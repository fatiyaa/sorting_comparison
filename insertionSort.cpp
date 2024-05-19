#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    // --- START

    int seq_length[5] = {1000, 2000, 3000, 4000, 5000};

    string time_file_name = "insertionSort_time.txt";
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
        insertionSort(angka_list.data(), n);

        // --- OUTPUT KE FILE
        file_name = "output/output_insertionSort_" + to_string(seq_length[i]) + ".txt";
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

        std::cout << "insertionSort is done" << std::endl;
        std::cout << "time " << seq_length[i] << " sequence: " << duration << " seconds" << std::endl;

        fprintf(time_file, "%lf\n", duration);
    }

    fclose(time_file);

    return 0;
}
