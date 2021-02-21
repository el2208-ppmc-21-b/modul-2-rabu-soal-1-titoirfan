/** EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
*   Modul               : 2
*   Soal                : 1
*   Hari dan Tanggal    : Minggu, 21 Februari 2021
*   Nama (NIM)          : Irfan Tito Kurniawan (18317019)
*   Nama File           : m02.c
*   Deskripsi           : Program pengolah perintah drone.
*/

// Kompilasi: gcc -o m02 m02.c
// Run: ./m02

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20

int main () {
    // Nama file
    char filename[MAX_LEN];

    // Masukkan nama file
    printf("Masukkan nama file perintah: ");
    scanf("%s", &filename);

    // Buka file untuk dibaca
    FILE* stream = fopen(filename, "r");
    
    // Variabel utility untuk pembacaan file
    // Variabel penyimpan baris dari file sementara    
    char line[MAX_LEN];
    // Token penyimpan string sementara untuk parsing
    char* token;

    // Koordinat drone
    float coord_x = 0.0;
    float coord_y = 0.0;

    // Utility
    float cmd_param = 0.0;

    // Validitas perintah
    int cmd_code = 0;
    int validity = 1;

    // Baca file baris demi baris hingga habis
    while(fgets(line, MAX_LEN, stream)) {
        // Asumsikan perintah valid
        validity = 1;
        cmd_code = 0;

        // Parse baris
        // Ambil string pada baris hingga tanda koma (koma tidak ikut dibaca)
        token = strtok(line, ",");

        // Cek keutuhan awalan perintah
        if (!strcmp(token, "abc")) {
            // Lanjutkan jika awalan abc
            token = strtok(NULL, ",");

            // Cek kode perintah
            if (!strcmp(token, "1")) {
                // Perintah maju
                cmd_code = 1;

                // Baca parameter
                token = strtok(NULL, ",");
                cmd_param = atof(token);
            }
            else if (!strcmp(token, "2")) {
                // Perintah ke kanan
                cmd_code = 2;

                // Baca parameter
                token = strtok(NULL, ",");
                cmd_param = atof(token);
            }
            else if (!strcmp(token, "3")) {
                // Perintah mengambil gambar
                cmd_code = 3;
            }
        }

        // Cek akhiran
        token = strtok(NULL, "\n");

        // Proses hanya bila akhiran utuh
        if (token != NULL)
            if (!strcmp(token, "xyz"))
                if (cmd_code == 1)
                    coord_x += cmd_param;
                else if (cmd_code == 2)
                    coord_y += cmd_param;
                else if (cmd_code == 3)
                    printf("Drone mengambil gambar pada titik (%.2f, %.2f)\n", coord_x, coord_y);
    }

    return 0;
}
