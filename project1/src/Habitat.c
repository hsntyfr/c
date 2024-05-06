#include "Habitat.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void habitatBoyutBelirle(const char* dosya, int* satirSon, int* sutunSon) {
    FILE *file = fopen(dosya, "r");
    char veri[512];
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
    this = (Habitat)malloc(sizeof(struct HABITAT));
    this->habitatYokEt = &habitatYokEt;
    habitatBoyutBelirle(dosya, &this->satir, &this->sutun);
    this->canliDizisi = diziOlustur(this->satir, this->sutun);
    habitatDoldur(this, dosya);
    this->habitatYazdir = &habitatYazdir;
    this->kazananYazdir = &kazananYazdir;
    this->habitatYokEt = &habitatYokEt;
    this->savasBaslat = &savasciGonder;
    return this;
}

Canli*** diziOlustur(int satir, int sutun) {
    int matrisBoyut = 0;
    if (satir > sutun) {
        matrisBoyut = satir;
    }
    else {
        matrisBoyut = sutun;
    }
    Canli*** canliDizi = (Canli***)malloc((matrisBoyut+ 1) * sizeof(Canli**));
    for (int i = 0; i < matrisBoyut + 1; i++) {
        canliDizi[i] = (Canli**)malloc((matrisBoyut + 1) * sizeof(Canli*));
        for (int j = 0; j < matrisBoyut + 1; j++) {
            canliDizi[i][j] = (Canli*)malloc(sizeof(Canli));
        }
    }
    return canliDizi;
}

void habitatDoldur(Habitat this, char* dosya) {
    FILE *file = fopen(dosya, "r");
    char veri[512];
    int x = 0;
    int y = 0;
    while (fgets(veri, sizeof(veri), file)) {
        char* ayrac = strtok(veri, " ");
        while (ayrac) {
            int sayi = atoi(ayrac);
            if (x >= this->sutun) {
                x = 0;
                y++;
            }
            if (sayi >= 1 && sayi <= 9) {
                Bitki bitki = bitkiOlustur(x, y, sayi);
                this->canliDizisi[y][x] = (Canli)bitki;
            } else if (sayi >= 10 && sayi <= 20) {
                Bocek bocek = bocekOlustur(x, y, sayi);
                this->canliDizisi[y][x] = (Canli)bocek;
            } else if (sayi >= 21 && sayi <= 50) {
                Sinek sinek = sinekOlustur(x, y, sayi);
                this->canliDizisi[y][x] = (Canli)sinek;
            } else if (sayi >= 51 && sayi <= 99) {
                Pire pire = pireOlustur(x, y, sayi);
                this->canliDizisi[y][x] = (Canli)pire;
            }
            x++;
            ayrac = strtok(NULL, " ");
        }
    }
    fclose(file);
    this->kazanan = this->canliDizisi[0][0];
}

void habitatYazdir(Habitat this) {
    //system("clear");
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
            if (bitki->simge == "B") {
                char* str;
                str = bitki->super->gorunum(bitki->super, bitki);
                printf("%s ", str);
                free(str);
            }
            if (bocek->simge == "C") {
                char* str;
                str = bocek->super->gorunum(bocek->super, bocek);
                printf("%s ", str);
                free(str);
            }
            if (pire->simge == "P") {
                char* str;
                str = pire->super->super->gorunum(pire->super->super, pire);
                printf("%s ", str);
                free(str);
            }
            if (sinek->simge == "S") {
                char* str;
                str = sinek->super->super->gorunum(sinek->super->super, sinek);
                printf("%s ", str);
                free(str);
            }
        }
        printf("\n");
    }
}

void kazananYazdir(Habitat this) {
    Bitki bitki;
    Bocek bocek;
    Pire pire;
    Sinek sinek;
    bitki = (Bitki)this->kazanan;
    bocek = (Bocek)this->kazanan;
    pire = (Pire)this->kazanan;
    sinek = (Sinek)this->kazanan;
    if (bitki->simge == "B") {
        char* str;
        str = bitki->super->gorunum(bitki->super, bitki);
        printf("Kazanan: %s : (%d,%d)", str, bitki->super->y, bitki->super->x);
        free(str);
    }
    if (bocek->simge == "C") {
        char* str;
        str = bocek->super->gorunum(bocek->super, bocek);
        printf("Kazanan: %s : (%d,%d)", str, bocek->super->y, bocek->super->x);
        free(str);
    }
    if (pire->simge == "P") {
        char* str;
        str = pire->super->super->gorunum(pire->super->super, pire);
        printf("Kazanan: %s : (%d,%d)", str, pire->super->super->y, pire->super->super->x);
        free(str);
    }
    if (sinek->simge == "S") {
        char* str;
        str = sinek->super->super->gorunum(sinek->super->super, sinek);
        printf("Kazanan: %s : (%d,%d)", str, sinek->super->super->y, sinek->super->super->x);
        free(str);
    }
}

char turBelirle(Canli* this) {
    Bitki bitki = (Bitki)this;
    Bocek bocek = (Bocek)this;
    Pire pire = (Pire)this;
    Sinek sinek = (Sinek)this;
    if (bitki->simge == "B") {
        return 'B';
    }
    if (bocek->simge == "C") {
        return 'C';
    }
    if (pire->simge == "P") {
        return 'P';
    }
    if (sinek->simge == "S") {
        return 'S';
    }
    return false;
}

int ikiBitki(Canli* canli1, Canli* canli2) {
    Bitki bitki1 = (Bitki)canli1;
    Bitki bitki2 = (Bitki)canli2;
    if (bitki1->super->deger > bitki2->super->deger) {
        return 0;
    }
    else if (bitki1->super->deger < bitki2->super->deger) {
        return 1;
    }
    else {
        if (bitki1->super->y == bitki2->super->y) {
            if (bitki1->super->x > bitki2->super->x) {
                return 1;
            }
            else {
                return 0;
            }
        }
        if (bitki1->super->x == bitki2->super->x) {
            if (bitki1->super->y > bitki2->super->y) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}

int ikiBocek(Canli* canli1, Canli* canli2) {
    Bocek bocek1 = (Bocek)canli1;
    Bocek bocek2 = (Bocek)canli2;
    if (bocek1->super->deger > bocek2->super->deger) {
        return 0;
    }
    else if (bocek1->super->deger < bocek2->super->deger) {
        return 1;
    }
    else {
        if (bocek1->super->y == bocek2->super->y) {
            if (bocek1->super->x > bocek2->super->x) {
                return 1;
            }
            else {
                return 0;
            }
        }
        if (bocek1->super->x == bocek2->super->x) {
            if (bocek1->super->y > bocek2->super->y) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}


int ikiSinek(Canli* canli1, Canli* canli2) {
    Sinek sinek1 = (Sinek)canli1;
    Sinek sinek2 = (Sinek)canli2;
    if (sinek1->super->super->deger > sinek2->super->super->deger) {
        return 0;
    }
    else if (sinek1->super->super->deger < sinek2->super->super->deger) {
        return 1;
    }
    else {
        if (sinek1->super->super->y == sinek2->super->super->y) {
            if (sinek1->super->super->x > sinek2->super->super->x) {
                return 1;
            }
            else {
                return 0;
            }
        }
        if (sinek1->super->super->x == sinek2->super->super->x) {
            if (sinek1->super->super->y > sinek2->super->super->y) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}

int ikiPire(Canli* canli1, Canli* canli2) {
    Pire pire1 = (Pire)canli1;
    Pire pire2 = (Pire)canli2;
    if (pire1->super->super->deger > pire2->super->super->deger) {
        return 0;
    }
    else if (pire1->super->super->deger < pire2->super->super->deger) {
        return 1;
    }
    else {
        if (pire1->super->super->y == pire2->super->super->y) {
            if (pire1->super->super->x > pire2->super->super->x) {
                return 1;
            }
            else {
                return 0;
            }
        }
        if (pire1->super->super->x == pire2->super->super->x) {
            if (pire1->super->super->y > pire2->super->super->y) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}

void savasciGonder(Habitat this) {
    Bitki bitki;
    Bocek bocek;
    Pire pire;
    Sinek sinek;
    for (int i = 0; i < this->satir; i++) {
        for (int j = 0; j < this->sutun; j++) {
            Canli *canli1 = this->kazanan;
            if (this->kazanan == this->canliDizisi[i][j]) {
                continue;
            }
            Canli *canli2 = this->canliDizisi[i][j];
            Canli* temp;
            char tur1 = turBelirle(canli1);
            char tur2 = turBelirle(canli2);
            if (tur1 == 'C') {
                if (tur2 == 'B') {
                    kaybedenOldur(this->canliDizisi[i][j]);
                }
                else if (tur2 == 'P') {
                    kaybedenOldur(this->canliDizisi[i][j]);
                }
                else if (tur2 == 'S') {
                    temp = this->kazanan;
                    this->kazanan = canli2;
                    kaybedenOldur(temp);
                }
                else if (tur2 == 'C') {
                    if (!ikiBocek(canli1, canli2)) {
                        this->kazanan = canli1;
                        kaybedenOldur(canli2);
                    }
                    else {
                        this->kazanan = canli2;
                        kaybedenOldur(canli1);
                    }
                }
            } else if (tur1 == 'B') {
                if (tur2 == 'C') {
                    temp = this->kazanan;
                    this->kazanan = canli2;
                    kaybedenOldur(temp);
                }
                else if (tur2 == 'P') {
                    kaybedenOldur(this->canliDizisi[i][j]);
                }
                else if (tur2 == 'S') {
                    kaybedenOldur(this->canliDizisi[i][j]);
                }
                else if (tur2 == 'B') {
                    if (!ikiBitki(canli1, canli2)) {
                        this->kazanan = canli1;
                        kaybedenOldur(canli2);
                    }
                    else {
                        this->kazanan = canli2;
                        kaybedenOldur(canli1);
                    }
                }
            } else if (tur1 == 'S') {
                if (tur2 == 'B') {
                    temp = this->kazanan;
                    this->kazanan = canli2;
                    kaybedenOldur(temp);
                }
                else if (tur2 == 'C') {
                    kaybedenOldur(this->canliDizisi[i][j]);
                }
                else if (tur2 == 'P') {
                    kaybedenOldur(this->canliDizisi[i][j]);
                }
                else if (tur2 == 'S') {
                    if (!ikiSinek(canli1, canli2)) {
                        this->kazanan = canli1;
                        kaybedenOldur(canli2);
                    }
                    else {
                        this->kazanan = canli2;
                        kaybedenOldur(canli1);
                    }
                }
            } else if (tur1 == 'P') {
                if (tur2 == 'P') {
                    if (!ikiPire(canli1, canli2)) {
                        this->kazanan = canli1;
                        kaybedenOldur(canli2);
                    }
                    else {
                        this->kazanan = canli2;
                        kaybedenOldur(canli1);
                    }
                }
                else if (tur2 == 'B') {
                    temp = this->kazanan;
                    this->kazanan = canli2;
                    kaybedenOldur(temp);
                }
                else if (tur2 == 'C') {
                    temp = this->kazanan;
                    this->kazanan = canli2;
                    kaybedenOldur(temp);
                }
                else if (tur2 == 'S') {
                    temp = this->kazanan;
                    this->kazanan = canli2;
                    kaybedenOldur(temp);
                }
            }
            habitatYazdir(this);
        }
    }
}

void kaybedenOldur(Canli* this) {
    Bitki bitki = (Bitki)this;
    Bocek bocek = (Bocek)this;
    Pire pire = (Pire)this;
    Sinek sinek = (Sinek)this;
    if (bitki->simge == "B" && bitki->super->canliMi == true) {
        bitki->super->canliMi = false;
    }
    if (bocek->simge == "C" && bocek->super->canliMi == true) {
        bocek->super->canliMi = false;
    }
    if (pire->simge == "P" && pire->super->super->canliMi == true) {
        pire->super->super->canliMi = false;
    }
    if (sinek->simge == "S" && sinek->super->super->canliMi == true) {
        sinek->super->super->canliMi = false;
    }
}

void habitatYokEt(Habitat this) {
    int matrisBoyut = 0;
    if (this->satir > this->sutun) {
        matrisBoyut = this->satir;
    }
    else {
        matrisBoyut = this->sutun;
    }
    for (int i = 0; i < matrisBoyut + 1; i++) {
        for (int j = 0; j < matrisBoyut + 1; j++) {
            Bitki bitki;
            Bocek bocek;
            Pire pire;
            Sinek sinek;
            bitki = (Bitki)this->kazanan;
            bocek = (Bocek)this->kazanan;
            pire = (Pire)this->kazanan;
            sinek = (Sinek)this->kazanan;
            if (bitki->simge == "B") {
                bitki->yokEt(bitki);
            }
            if (bocek->simge == "C") {
                bocek->yokEt(bocek);
            }
            if (pire->simge == "P") {
                pire->yokEt(pire);
            }
            if (sinek->simge == "S") {
                sinek->yokEt(sinek);
            }
        }
        free(this->canliDizisi[i]);
    }
    free(this->canliDizisi);
    free(this);
}