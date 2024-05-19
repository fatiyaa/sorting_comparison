#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <ctime>
using namespace std;

vector<int> countSort(vector<int>& inputArray){
    int N = inputArray.size();
    int M = 0;
 
    for (int i = 0; i < N; i++)
        M = max(M, inputArray[i]);
 
    vector<int> countArray(M + 1, 0);
 
    for (int i = 0; i < N; i++)
        countArray[inputArray[i]]++;
 
    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];
 
    vector<int> outputArray(N);
    for (int i = N - 1; i >= 0; i--){
        outputArray[countArray[inputArray[i]] - 1] = inputArray[i];
        countArray[inputArray[i]]--;
    }
    return outputArray;
}

int main()
{
    // --- START
    int seq_length[5] = {10000, 20000, 30000, 40000, 50000};

    string time_file_name = "time/countingSort_time.txt";
    FILE *time_file = fopen(time_file_name.c_str(), "w");
    if (time_file == NULL)
    {
        perror("err");
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {
        string file_name = "input/input_" + to_string(seq_length[i]) + ".txt";
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

        // --- URUTKAN ANGKA MENGGUNAKAN COUNTING SORT
        int n = angka_list.size();
        clock_t start = clock();
        // heapSort(angka_list.data(), n);
        angka_list = countSort(angka_list);
        clock_t end = clock();

        // --- OUTPUT KE FILE
        file_name = "output/output_countingSort_" + to_string(seq_length[i]) + ".txt";
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
        double duration = double(end - start) / CLOCKS_PER_SEC;

        std::cout << "countingSort is done" << std::endl;
        std::cout << "time " << seq_length[i] << " sequence: " << duration << " seconds" << std::endl;

        fprintf(time_file, "%lf\n", duration);
    }
    fclose(time_file);

    return 0;
}
