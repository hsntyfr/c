#ifndef HABITAT_H
#define HABITAT_H

#include "Bitki.h"
#include "Canli.h"
#include "Bocek.h"
#include <stdio.h>
#include <stdlib.h>
#include "Pire.h"
#include "Sinek.h"

struct HABİTAT {
    char tur;

    //struct canliDizi ***canlilar;
    int satir;
    int sutun;
    Canli *kazanan;
    Canli ***canliDizisi;
    void (*habitatYokEt) (struct HABİTAT*);
    Canli (*kazananBul) (Canli, Canli);
    //void (*habitatYazdir) (struct CANLI**);

};
typedef struct HABİTAT *Habitat;

void habitatBoyutBelirle(const char*, int*, int*);
void habitatYokEt(Habitat);
Habitat habitatOlustur(char*);
Canli*** diziOlustur(int, int);
void habitatYazdir(Habitat);
void habitatYokEt(Habitat);
void habitatDoldur(Habitat, char*);
//Canli kazananBul(Canli, Canli);
void kazananYazdir(Habitat);
void savasciGonder(Habitat this);
char turBelirle(Canli* this);
char kazananBul(char tur1, char tur2);
void kaybedenOldur(Canli* this);
int ikiBitki(Canli* canli1, Canli* canli2);
int ikiBocek(Canli* canli1, Canli* canli2);
int ikiSinek(Canli* canli1, Canli* canli2);
#endif


/*void* canli[MAX_TUR][MAX_CANLI];
int canliTurleri[MAX_TUR][MAX_CANLI];

Bitki bitki1 = bitkiOlustur(4, 5, 6);
Bocek bocek1 = bocekOlustur(1, 2, 3);

canli[0][0] = (void*)bitki1;
canliTurleri[0][0] = 1; // 1 bitki türünü temsil eder

canli[0][1] = (void*)bocek1;
canliTurleri[0][1] = 2; // 2 bocek türünü temsil eder

Bitki bitki2 = bitkiOlustur(7, 8, 9);
Bocek bocek2 = bocekOlustur(10, 11, 12);

canli[1][0] = (void*)bitki2;
canliTurleri[1][0] = 1; // 1 bitki türünü temsil eder

canli[1][1] = (void*)bocek2;
canliTurleri[1][1] = 2; // 2 bocek türünü temsil eder

// Dizideki nesneleri işlemek için
for(int i = 0; i < MAX_TUR; i++) {
    for(int j = 0; j < MAX_CANLI; j++) {
        if(canliTurleri[i][j] == 1) {
            Bitki ba = (Bitki)canli[i][j];
            char* str = ba->super->gorunum(ba->super, ba);
            printf("%s", str);
            free(str);
        } else if(canliTurleri[i][j] == 2) {
            Bocek bs = (Bocek)canli[i][j];
            char* str = bs->super->gorunum(bs->super, bs);
            printf("%s", str);
            free(str);
        }
    }
}

bitki1->yokEt(bitki1);
bocek1->yokEt(bocek1);
bitki2->yokEt(bitki2);
bocek2->yokEt(bocek2);*/