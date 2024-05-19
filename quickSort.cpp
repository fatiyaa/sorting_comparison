#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main()
{
  // --- START
  int seq_length[20] = {1000, 2000, 3000, 4000, 5000, 10000, 20000, 30000, 40000, 50000, 1000, 2000, 3000, 4000, 5000, 1000, 2000, 3000, 4000, 5000};

  string time_file_name = "time/quickSort_time.txt";
  FILE *time_file = fopen(time_file_name.c_str(), "w");
  if (time_file == NULL)
  {
    perror("err");
    return 1;
  }

  for (int i = 0; i < 20; i++)
  {
    string file_name;
    FILE *file;
    if (i < 10)
    {
      file_name = "input/input_" + to_string(seq_length[i]) + ".txt";
      file = fopen(file_name.c_str(), "r");
      if (file == NULL)
      {
        perror("err");
        return 1;
      }
    }
    else if (i < 15)
    {
      file_name = "input/sorted_input_" + to_string(seq_length[i]) + ".txt";
      file = fopen(file_name.c_str(), "r");
      if (file == NULL)
      {
        perror("err");
        return 1;
      }
    }
    else
    {
      file_name = "input/back_input_" + to_string(seq_length[i]) + ".txt";
      file = fopen(file_name.c_str(), "r");
      if (file == NULL)
      {
        perror("err");
        return 1;
      }
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
    clock_t start = clock();
    quickSort(angka_list.data(), 0, n - 1);
    clock_t end = clock();

    // --- OUTPUT KE FILE
    file_name = "output/output_quickSort_" + to_string(seq_length[i]) + ".txt";
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

    if (i < 10)
      cout << "quickSort Random input ";
    else if (i < 15)
      cout << "quickSort Ascending input ";
    else
      cout << "quickSort Descending input ";
    std::cout << "time " << seq_length[i] << " sequence: " << duration << " seconds" << std::endl;

    fprintf(time_file, "%lf\n", duration);
  }
  fclose(time_file);

  return 0;
}
