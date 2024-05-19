import random

length = [1000, 2000, 3000, 4000, 5000]
# Generate angka acak dari 1 hingga 1000 tanpa ada yang sama

for i in length:
    numbers = random.sample(range(1, 10000), i)

    # Simpan hasil ke file teks
    with open(f'input_{i}.txt', 'w') as f:
        for number in numbers:
            f.write(f"{number}\n")

