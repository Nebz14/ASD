#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Batas aman untuk mencegah stack overflow

/* ============================================================
   FUNGSI UTILITAS (Mencegah terminal berantakan)
   ============================================================ */

void clear_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pause_kembali() {
    printf("\n[Tekan Enter untuk kembali ke Menu Utama...]");
    clear_input(); // Menangkap enter
}

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/* ============================================================
   FITUR 1: MEMBUAT SEGITIGA BINTANG
   (Menggunakan pola Infinity/Butterfly >< sesuai riwayat preferensi)
   ============================================================ */

void segitiga_bintang() {
    int n;

    clear_screen();
    printf("========================================\n");
    printf("      POLA SEGITIGA BINTANG (><)        \n");
    printf("========================================\n");
    printf("Masukkan tinggi ukuran (bilangan ganjil): ");
    scanf("%d", &n);
    clear_input();

    if (n <= 0 || n % 2 == 0) {
        printf("\n[ERROR] Input harus bilangan ganjil positif!\n");
        pause_kembali();
        return;
    }

    printf("\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // Logika matriks untuk segitiga menyempit ke tengah
            if ((j <= i && j <= n - i + 1) || (j >= i && j >= n - i + 1)) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    pause_kembali();
}

/* ============================================================
   FITUR 2: INPUT DAN TAMPILKAN ARRAY 3 DIMENSI
   (SANGAT KETAT SESUAI TEKS PROYEKTOR)
   ============================================================ */

void array3D() {
    int lapis, baris, kolom;

    clear_screen();
    printf("========================================\n");
    printf("       EKSEKUSI ARRAY 3 DIMENSI         \n");
    printf("========================================\n");
    
    printf("Masukkan jumlah LAPISAN (Maks %d): ", MAX_SIZE);
    scanf("%d", &lapis);
    printf("Masukkan jumlah BARIS   (Maks %d): ", MAX_SIZE);
    scanf("%d", &baris);
    printf("Masukkan jumlah KOLOM   (Maks %d): ", MAX_SIZE);
    scanf("%d", &kolom);
    clear_input();

    // Validasi dimensi
    if (lapis <= 0 || baris <= 0 || kolom <= 0) {
        printf("\n[ERROR] Ukuran dimensi tidak boleh 0 atau negatif!\n");
        pause_kembali();
        return;
    }
    if (lapis > MAX_SIZE || baris > MAX_SIZE || kolom > MAX_SIZE) {
        printf("\n[ERROR] Ukuran melebihi batas maksimal memori (%d)!\n", MAX_SIZE);
        pause_kembali();
        return;
    }

    int arr[MAX_SIZE][MAX_SIZE][MAX_SIZE];
    int total_elemen = lapis * baris * kolom;
    int nilai_terbesar;

    printf("\n--- PROSES INPUT DATA ---\n");
    for(int i = 0; i < lapis; i++) {
        for(int j = 0; j < baris; j++) {
            for(int k = 0; k < kolom; k++) {
                printf("Input isi index [%d][%d][%d]: ", i, j, k);
                scanf("%d", &arr[i][j][k]);
                
                // Menentukan nilai terbesar secara langsung
                if (i == 0 && j == 0 && k == 0) {
                    nilai_terbesar = arr[i][j][k];
                } else if (arr[i][j][k] > nilai_terbesar) {
                    nilai_terbesar = arr[i][j][k];
                }
            }
        }
    }
    clear_input();

    // Menjawab Syarat Proyektor: "Wajib memunculkan isi array per lapisan dan isi lengkap dengan index"
    printf("\n========================================\n");
    printf("      ISI ARRAY 3D PER LAPISAN          \n");
    printf("========================================\n");
    
    for(int i = 0; i < lapis; i++) {
        printf("\n>>> DATA LAPISAN KE-%d <<<\n", i);
        for(int j = 0; j < baris; j++) {
            for(int k = 0; k < kolom; k++) {
                printf("  Index [%d][%d][%d] = %d\n", i, j, k, arr[i][j][k]);
            }
        }
    }

    // Menjawab Syarat Proyektor: "total elemen dan nilai terbesar"
    printf("\n========================================\n");
    printf("TOTAL ELEMEN   : %d buah\n", total_elemen);
    printf("NILAI TERBESAR : %d\n", nilai_terbesar);
    printf("========================================\n");

    pause_kembali();
}

/* ============================================================
   MAIN — SISTEM MENU PROGRAM
   ============================================================ */

int main() {
    int pilihan;

    do {
        clear_screen();
        printf("=======================================\n");
        printf("===          MENU PROGRAM           ===\n");
        printf("=======================================\n");
        printf("1. Membuat Segitiga Bintang\n");
        printf("2. Input dan Tampilkan Array 3 Dimensi\n");
        printf("3. Keluar\n");
        printf("=======================================\n");
        printf("Pilih menu: ");
        
        // Membaca input
        if (scanf("%d", &pilihan) != 1) {
            // Menangani jika user iseng memasukkan huruf di menu
            pilihan = 0; 
        }
        clear_input();

        switch (pilihan) {
            case 1: 
                segitiga_bintang(); 
                break;
            case 2: 
                array3D();          
                break;
            case 3:
                printf("\nKeluar dari program. Selesai.\n\n");
                break;
            default:
                printf("\n[ERROR] Pilihan menu tidak valid! Masukkan angka 1, 2, atau 3.\n");
                pause_kembali();
        }

    } while (pilihan != 3);

    return 0;
}