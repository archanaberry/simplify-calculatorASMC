# Kalkulator Sederhana Assembly - x86_64 & ARM32/ARM64

Kalkulator ini dibuat menggunakan bahasa C dan instruksi assembly untuk operasi aritmatika dasar. Program mendukung arsitektur **x86_64** dan **ARM32/ARM64** dengan menggunakan assembly untuk operasi yang lebih cepat dan ringan.

## Deskripsi

Program kalkulator ini mendukung empat operator dasar:
- **+** : Penjumlahan
- **-** : Pengurangan
- **x** : Perkalian
- **/** : Pembagian

Program menggunakan instruksi assembly untuk meningkatkan kinerja kalkulasi.

## Cara Menggunakan

### Menjalankan Kalkulator
Untuk menjalankan kalkulator, gunakan sintaks berikut di terminal:
```
./calculator <input> <operator> <input> ...
```

Contoh penggunaan:
```
./calculator 1 + 1
```
Hasil: `2`

```
./calculator 2 + 2 + 2
```
Hasil: `6`

```
./calculator 10 x 2
```
Hasil: `20`

```
./calculator 1 - 1 + 20 x 2
```
Hasil: `40`

### Bantuan
Untuk melihat bantuan dan informasi tentang cara penggunaan, jalankan perintah berikut:
```
./calculator --help
```

Output:
```
Penggunaan: ./calculator <input> <operator> <input> ...
Operator yang tersedia:
  +  : Penjumlahan
  -  : Pengurangan
  x  : Perkalian
  /  : Pembagian
Contoh:
  ./calculator 1 + 1
  ./calculator 2 + 2 + 2
  ./calculator 10 x 2
  ./calculator 1 - 1 + 20 x 2
```

## Cara Kompilasi

### Untuk x86_64
1. Kompilasi dengan GCC:
   ```
   gcc cal2.c -o calculator -O3
   ```

2. Setelah berhasil dikompilasi, Anda dapat menjalankan program dengan:
   ```
   ./calculator <input> <operator> <input> ...
   ```

### Untuk ARM32/ARM64
Jika Anda ingin menggunakan arsitektur ARM32 atau ARM64, Anda dapat memodifikasi file sumber untuk menyesuaikan instruksi assembly dengan masing-masing arsitektur, dan mengikuti langkah kompilasi yang sesuai dengan sistem Anda.

## Penjelasan File Assembly

### `calculator-x8664.asm`

File `calculator-x8664.asm` berisi kode assembly yang digunakan untuk operasi aritmatika pada arsitektur **x86_64**. Di dalamnya, Anda akan menemukan instruksi untuk:
- **Penjumlahan** (`addq`)
- **Pengurangan** (`subq`)
- **Perkalian** (`imulq`)
- **Pembagian** (`idivq`)

Instruksi ini disesuaikan untuk bekerja dengan register dan struktur data pada sistem **x86_64**, dan digunakan dalam program C untuk meningkatkan performa perhitungan.

### `calculator-arm3264.asm`

File `calculator-arm3264.asm` berisi kode assembly yang digunakan untuk operasi aritmatika pada arsitektur **ARM32** dan **ARM64**. Di dalamnya, instruksi-instruksi berikut digunakan:
- **Penjumlahan** (`ADD`)
- **Pengurangan** (`SUB`)
- **Perkalian** (`MUL`)
- **Pembagian** (`SDIV`)

File ini memungkinkan kalkulator untuk bekerja dengan arsitektur ARM, dengan instruksi assembly yang disesuaikan untuk ARM32 dan ARM64.

## Kontribusi

Jika Anda ingin berkontribusi dalam pengembangan kalkulator ini, silakan lakukan fork repository ini, buat cabang (branch), lakukan perubahan, dan ajukan pull request.

## Lisensi

Proyek ini dilisensikan di bawah **MIT License** - lihat [LICENSE](LICENSE) untuk detail lebih lanjut.
```

### Penjelasan Konten `README.md`:

1. **Deskripsi Proyek**: Menyediakan informasi umum tentang kalkulator yang menggunakan instruksi assembly untuk operasi aritmatika.
   
2. **Cara Penggunaan**: Memberikan penjelasan tentang bagaimana menjalankan kalkulator dan menggunakan operator yang tersedia. Contoh penggunaan ditampilkan agar pengguna dapat langsung mencoba program.

3. **Bantuan**: Menyediakan informasi untuk pengguna yang ingin mengetahui cara penggunaan kalkulator lebih lanjut dengan `--help`.

4. **Cara Kompilasi**: Memberikan instruksi tentang bagaimana mengompilasi program untuk **x86_64** menggunakan GCC. Untuk ARM32/ARM64, instruksi umum disediakan untuk referensi lebih lanjut.

5. **Penjelasan File Assembly**: Menjelaskan tujuan dan fungsi masing-masing file assembly (`calculator-x8664.asm` dan `calculator-arm3264.asm`) serta instruksi yang digunakan pada masing-masing arsitektur.

6. **Kontribusi**: Mendorong kontribusi dari pengguna untuk mengembangkan proyek ini lebih lanjut.

7. **Lisensi**: Memberikan informasi mengenai lisensi yang digunakan untuk proyek ini (MIT License).
