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

    switch(op) {
        case '+':
            #if defined(__arm__) || defined(__aarch32__) // ARM32
                __asm__ (
                    "add %0, %1, %2;"    // result = num1 + num2
                    : "=r" (result)
                    : "r" (num1), "r" (num2)
                );
            #elif defined(__aarch64__) // ARM64
                __asm__ (
                    "add %0, %1, %2;"    // result = num1 + num2
                    : "=r" (result)
                    : "r" (num1), "r" (num2)
                );
            #else
                printf("Arsitektur tidak didukung!\n");
                exit(1);
            #endif
            break;
        case '-':
            #if defined(__arm__) || defined(__aarch32__) // ARM32
                __asm__ (
                    "sub %0, %1, %2;"    // result = num1 - num2
                    : "=r" (result)
                    : "r" (num1), "r" (num2)
                );
            #elif defined(__aarch64__) // ARM64
                __asm__ (
                    "sub %0, %1, %2;"
                    : "=r" (result)
                    : "r" (num1), "r" (num2)
                );
            #else
                printf("Arsitektur tidak didukung!\n");
                exit(1);
            #endif
            break;
        case 'x': // Perkalian
            #if defined(__arm__) || defined(__aarch32__) // ARM32
                __asm__ (
                    "mul %0, %1, %2;"    // result = num1 * num2
                    : "=r" (result)
                    : "r" (num1), "r" (num2)
                );
            #elif defined(__aarch64__) // ARM64
                __asm__ (
                    "mul %0, %1, %2;"
                    : "=r" (result)
                    : "r" (num1), "r" (num2)
                );
            #else
                printf("Arsitektur tidak didukung!\n");
                exit(1);
            #endif
            break;
        case '/': // Pembagian
            if (num2 == 0) {
                printf("Error: Pembagian dengan nol tidak diperbolehkan!\n");
                exit(1);
            }
            #if defined(__arm__) || defined(__aarch32__) // ARM32
                __asm__ (
                    "sdiv %0, %1, %2;"   // result = num1 / num2
                    : "=r" (result)
                    : "r" (num1), "r" (num2)
                );
            #elif defined(__aarch64__) // ARM64
                __asm__ (
                    "sdiv %0, %1, %2;"
                    : "=r" (result)
                    : "r" (num1), "r" (num2)
                );
            #else
                printf("Arsitektur tidak didukung!\n");
                exit(1);
            #endif
            break;
        default:
            printf("Operator tidak dikenal!\n");
            exit(1);
    }
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
