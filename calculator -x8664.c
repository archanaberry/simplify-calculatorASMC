#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fungsi untuk menampilkan cara penggunaan kalkulator
void show_help() {
    printf("Penggunaan: ./calculator <input> <operator> <input> ...\n");
    printf("Operator yang tersedia:\n");
    printf("  +  : Penjumlahan\n");
    printf("  -  : Pengurangan\n");
    printf("  x  : Perkalian\n");
    printf("  /  : Pembagian\n");
    printf("Contoh:\n");
    printf("  ./calculator 1 + 1\n");
    printf("  ./calculator 2 + 2 + 2\n");
    printf("  ./calculator 10 x 2\n");
    printf("  ./calculator 1 - 1 + 20 x 2\n");
}

// Fungsi untuk menghitung operasi aritmatika
long calculate(long num1, char op, long num2) {
    long result;

    // Pastikan kode hanya dijalankan pada arsitektur x86_64
    #if defined(__x86_64__)
        switch(op) {
            case '+':
                __asm__ (
                    "addq %1, %0;"        // result = num1 + num2
                    : "=r" (result)
                    : "r" (num2), "0" (num1)
                );
                break;
            case '-':
                __asm__ (
                    "subq %1, %0;"        // result = num1 - num2
                    : "=r" (result)
                    : "r" (num2), "0" (num1)
                );
                break;
            case 'x': // Perkalian
                __asm__ (
                    "imulq %1, %0;"       // result = num1 * num2
                    : "=r" (result)
                    : "r" (num2), "0" (num1)
                );
                break;
            case '/': // Pembagian
                if (num2 == 0) {
                    printf("Error: Pembagian dengan nol tidak diperbolehkan!\n");
                    exit(1);
                }
                __asm__ (
                    "cqto;"               // Convert to quadword for division
                    "idivq %2;"           // result = num1 / num2
                    : "=a" (result)
                    : "d" (num1), "r" (num2)
                );
                break;
            default:
                printf("Operator tidak dikenal!\n");
                exit(1);
        }
    #else
        printf("Arsitektur ini tidak didukung. Pastikan Anda menggunakan x86_64.\n");
        exit(1);
    #endif

    return result;
}

int main(int argc, char *argv[]) {
    // Mengecek apakah --help diminta
    if (argc == 2 && strcmp(argv[1], "--help") == 0) {
        show_help();
        return 0;
    }

    if (argc < 4) {
        printf("Error: Format salah. Gunakan ./calculator --help untuk bantuan.\n");
        return 1;
    }

    long result = atol(argv[1]);  // Mengonversi input pertama menjadi long
    for (int i = 2; i < argc; i += 2) {
        char operator = argv[i][0]; // Mengambil operator (+, -, x, /)
        long next_num = atol(argv[i + 1]); // Mengonversi angka berikutnya menjadi long
        result = calculate(result, operator, next_num); // Menjalankan kalkulasi
    }

    printf("Hasil: %ld\n", result);
    return 0;
}
