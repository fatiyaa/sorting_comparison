import random

length = [10000, 20000, 30000, 40000, 50000]
# Generate angka acak dari 1 hingga 1000 tanpa ada yang sama

for i in length:
    numbers = random.sample(range(1, 100000), i)

    # Simpan hasil ke file teks
    with open(f'input/input_{i}.txt', 'w') as f:
        for number in numbers:
            f.write(f"{number}\n")

