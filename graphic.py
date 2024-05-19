import matplotlib.pyplot as plt
import pandas as pd

# Nama-nama file yang berisi data waktu
file_names = ["time/heapSort_time.txt", "time/insertionSort_time.txt", "time/mergeSort_time.txt", "time/quickSort_time.txt"]

# List untuk menyimpan data dari setiap file
all_data = []

for file_name in file_names:
    with open(file_name, 'r') as file:
        data = [float(line.strip()) for line in file]
        all_data.append(data)

letters = ['1000', '2000', '3000', '4000', '50000']

# Membuat plot
plt.figure(figsize=(10, 6))

# Memplot setiap dataset
for i, data in enumerate(all_data):
    plt.plot(letters[:len(data)], data, label=file_names[i].split('/')[1].split('_')[0])

# Menambahkan label dan judul
plt.xlabel('Jumlah Angka')
plt.ylabel('Waktu')
plt.title('Grafik Waktu')
plt.legend()

# Menampilkan plot
plt.show()