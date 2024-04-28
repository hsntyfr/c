#include "Habitat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*enum Tur {
    TUR_BITKI = 0,
    TUR_BOCEK = 1,
    TUR_PIRE = 2,
    TUR_SINEK = 3
};*/

union{
    Bitki bitki;
    Bocek bocek;
    Pire pire;
    Sinek sinek;
}canliDizi;


void habitatBoyutBelirle(const char* dosya, int* satirSon, int* sutunSon) {
    FILE *file = fopen(dosya, "r");
    char veri[256];
    int satir = 0;
    int sutun = 0;
    while (fgets(veri, sizeof(veri), file)) {
        satir++;
        if (satir == 1) {
            char *ayrac = strtok(veri, " ");
            while (ayrac) {
                sutun++;
                ayrac = strtok(NULL, " ");
            }
        }
    }
    fclose(file);
    *satirSon = satir;
    *sutunSon = sutun;
}

Habitat habitatOlustur(char* dosya) {
    Habitat this;
    this = (Habitat)malloc(sizeof(struct HABİTAT));
    this->habitatYokEt = &habitatYokEt;
    habitatBoyutBelirle(dosya, &this->satir, &this->sutun);
    this->canliDizisi = diziOlustur(this->satir, this->sutun);
    habitatDoldur(this, dosya);
    return this;
}
Canli** diziOlustur(int satir, int sutun) {
    Canli** canliDizi = (Canli**)malloc(satir * sizeof(Canli*));
    for (int i = 0; i < satir; i++) {
        canliDizi[i] = (Canli*)malloc(sutun * sizeof(Canli));
    }
    return canliDizi;
}

void habitatDoldur(Habitat this, char* dosya) {
    FILE *file = fopen(dosya, "r");
    char veri[256];
    int satir = -1;
    int sutun = 0;
    int index = 0;
    while (fgets(veri, sizeof(veri), file)) {
        char* ayrac = strtok(veri, " ");
        while (ayrac) {
            int sayi = atoi(ayrac);
            if (sayi >= 1 && sayi <= 9) {
                if (satir == this->satir) {
                    satir = -1;
                    sutun++;
                    printf("\n");
                }
                satir++;
                Bitki bitki = bitkiOlustur(satir, sutun, sayi);
                this->canliDizisi[sutun][satir] = (Canli)bitki;
                printf("%c ", 'B');
                //printf("%d", satir);
                //printf("%d", sutun);
                index++;
            } else if (sayi >= 10 && sayi <= 20) {
                if (satir == this->satir) {
                    satir = -1;
                    sutun++;
                    printf("\n");
                }
                satir++;
                Bocek bocek = bocekOlustur(satir, sutun, sayi);
                this->canliDizisi[sutun][satir] = (Canli)bocek;
                printf("%c ", 'C');
                //printf("%d", satir);
                //printf("%d", sutun);
                index++;
            } else if (sayi >= 21 && sayi <= 50) {
                if (satir == this->satir) {
                    satir = -1;
                    sutun++;
                    printf("\n");

                }
                satir++;
                Sinek sinek = sinekOlustur(satir, sutun, sayi);
                this->canliDizisi[sutun][satir] = (Canli)sinek;
                printf("%c ", 'S');
                //printf("%d", satir);
                //printf("%d", sutun);
                index++;
            } else if (sayi >= 50 && sayi <= 99) {
                if (satir == this->satir) {
                    satir = -1;
                    sutun++;
                    printf("\n");

                }
                satir++;
                Pire pire = pireOlustur(satir, sutun, sayi);
                this->canliDizisi[sutun][satir] = (Canli)pire;
                printf("%c ", 'P');
                //printf("%d", satir);
                //printf("%d", sutun);
                index++;
            }
            ayrac = strtok(NULL, " ");
        }
    }
    printf("\n\n\n");
}
void habitatYazdir(Habitat this) {
    Bitki bitki;
    Bocek bocek;
    Pire pire;
    Sinek sinek;

    for (int i = 0; i < this->satir; i++) {
        for (int j = 0; j < this->sutun; j++) {
            bitki = (Bitki)this->canliDizisi[i][j];
            bocek = (Bocek)this->canliDizisi[i][j];
            pire = (Pire)this->canliDizisi[i][j];
            sinek = (Sinek)this->canliDizisi[i][j];
            if (bitki->simge == 'B') {
                printf("%c ", 'B');
            }
            if (bocek->simge == 'C') {
                printf("%c ", 'C');
            }
            if (pire->simge == 'P') {
                printf("%c ", 'P');
            }
            if (sinek->simge == 'S') {
                printf("%c ", 'S');
            }
        }
        printf("\n");
    }
}

/*void habitatCanliEkle(Habitat this, void* canli, int row, int col) {
    if (row >= 0 && row < this->satir && col >= 0 && col < this->sutun) {
        this->canlilar[row][col] = canli;
    } else {
        printf("Invalid row or column\n");
    }
}*/

void habitatYokEt(Habitat this) {

}