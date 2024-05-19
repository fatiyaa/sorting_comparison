#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void merge(int array[], int const left, int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main()
{
    // --- START

    int seq_length[5] = {1000, 2000, 3000, 4000, 5000};

    string time_file_name = "mergeSort_time.txt";
    FILE *time_file = fopen(time_file_name.c_str(), "w");
    if (time_file == NULL)
    {
        perror("err");
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {
        clock_t start = clock();

        string file_name = "input_" + to_string(seq_length[i]) + ".txt";
        FILE *file = fopen(file_name.c_str(), "r");
        if (file == NULL)
        {
            perror("err");
            return 1;
        }

        // --- BACA INPUT DARI FILE
        vector<int> angka_list;
        int angka;

        while (fscanf(file, "%d", &angka) != EOF)
        {
            angka_list.push_back(angka);
        }

        fclose(file);

        // --- URUTKAN ANGKA MENGGUNAKAN INSERTION SORT
        int n = angka_list.size();
        mergeSort(angka_list.data(), 0, n - 1);

        // --- OUTPUT KE FILE
        file_name = "output/output_mergeSort_" + to_string(seq_length[i]) + ".txt";
        FILE *output_file = fopen(file_name.c_str(), "w");
        if (output_file == NULL)
        {
            perror("err");
            return 1;
        }

        for (int num : angka_list)
        {
            fprintf(output_file, "%d\n", num);
        }

        fclose(output_file);

        // --- FINISH
        clock_t end = clock();
        double duration = double(end - start) / CLOCKS_PER_SEC;

        std::cout << "mergeSort is done" << std::endl;
        std::cout << "time " << seq_length[i] << " sequence: " << duration << " seconds" << std::endl;

        fprintf(time_file, "%lf\n", duration);
    }

    fclose(time_file);

    return 0;
}
