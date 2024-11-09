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

## Cara Kompilasi

### Untuk x86_64
1. Kompilasi dengan GCC:
2. contoh kompilasi agar efisien dan lebih cepat pakai opsi flag -O3 (optimalisasi level 3)
3. ```
   gcc <file program kalkulator.c nya> -o <penamaan program contoh "kalkulator"> <opsi optimalisasi>
   ```
   seperti ini kalau untuk prosesor x86_64 (32bit dan 64bit) misal Intel dan AMD
   ```
   gcc calculator-x8664.c -o calculator -O3
   ```
   atau kalau untuk prosesor ARM dari 32bit dan 64bit misal Snapdragon, Mediatek, dan Unisoc, dll
	 ```
   gcc calculator-arm3264.c -o calculator -03
   ```
   Setelah berhasil dikompilasi, Anda dapat menjalankan program dengan:
   ```
   ./calculator <input> <operator> <input> ...
   ```
4. Jika salah pemilihan versi arsitektur tidak dapat membuat aplikasi nya karena tidak cocok dengan set instruksi di prosesor anda!!!

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

Proyek ini dilisensikan di bawah **Creative Common License** - lihat [LICENSE](LICENSE) untuk detail lebih lanjut.
