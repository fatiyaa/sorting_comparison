
# Membuat plot
plt.figure(figsize=(10, 6))

# Memplot setiap dataset
for i, data in enumerate(all_data):
    plt.plot(letters[:len(data)], data, label=f'File {i+1}')

# Menambahkan label dan judul
plt.xlabel('Nomor Baris (a, b, c, d, ...)')
plt.ylabel('Waktu')
plt.title('Grafik Waktu dari Beberapa File')
plt.legend()

# Menampilkan plot
plt.show()