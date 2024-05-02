#include "Habitat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    //printf("%d", satir);
    //printf("%d\n", sutun);
    *satirSon = satir;
    *sutunSon = sutun;
}


Habitat habitatOlustur(char* dosya) {
    Habitat this;
    this = (Habitat)malloc(sizeof(struct HABİTAT));
    this->habitatYokEt = &habitatYokEt;
    habitatBoyutBelirle(dosya, &this->satir, &this->sutun);
    this->canliDizisi = diziOlustur(this->satir, this->sutun);
    /*Bitki bitki = bitkiOlustur(0, 0, 0);
    this->kazanan = (Canli*)bitki;*/
    habitatDoldur(this, dosya);
    return this;
}
/*Canli** diziOlustur(int satir, int sutun) {
    Canli** canliDizi = (Canli**)malloc(satir * sizeof(Canli*));
    for (int i = 0; i < satir; i++) {
        canliDizi[i] = (Canli*)malloc(sutun * sizeof(Canli));
    }
    return canliDizi;
}*/

Canli*** diziOlustur(int satir, int sutun) {
    Canli*** canliDizi = (Canli***)malloc((sutun + 1) * sizeof(Canli**));
    for (int i = 0; i < sutun + 1; i++) {
        canliDizi[i] = (Canli**)malloc((satir + 1) * sizeof(Canli*));
        for (int j = 0; j < satir + 1; j++) {
            canliDizi[i][j] = (Canli*)malloc(sizeof(Canli));
        }
    }
    return canliDizi;
}

void habitatDoldur(Habitat this, char* dosya) {
    FILE *file = fopen(dosya, "r");
    char veri[256];
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
                x++;
            } else if (sayi >= 10 && sayi <= 20) {
                Bocek bocek = bocekOlustur(x, y, sayi);
                this->canliDizisi[y][x] = (Canli)bocek;
                x++;
            } else if (sayi >= 21 && sayi <= 50) {
                Sinek sinek = sinekOlustur(x, y, sayi);
                this->canliDizisi[y][x] = (Canli)sinek;
                x++;
            } else if (sayi >= 50 && sayi <= 99) {
                Pire pire = pireOlustur(x, y, sayi);
                this->canliDizisi[y][x] = (Canli)pire;
                x++;
            }
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
    printf("\n");

    for (int i = 0; i < this->satir; i++) {
        for (int j = 0; j < this->sutun; j++) {
            //printf("%d", i);
            //printf("%d", j);
            bitki = (Bitki)this->canliDizisi[i][j];
            bocek = (Bocek)this->canliDizisi[i][j];
            pire = (Pire)this->canliDizisi[i][j];
            sinek = (Sinek)this->canliDizisi[i][j];
            if (bitki->simge == 'B' && bitki->super->canliMi == true) {
                printf("%c ", 'B');
                //printf("%c, %d, %d\n", bitki->simge, bitki->super->x, bitki->super->y);
            }
            if (bocek->simge == 'C' && bocek->super->canliMi == true) {
                printf("%c ", 'C');
                //printf("%c, %d, %d\n", bocek->simge, bocek->super->x, bocek->super->y);
            }
            if (pire->simge == 'P' && pire->super->super->canliMi == true) {
                printf("%c ", 'P');
                //printf("%c, %d, %d\n", pire->simge, pire->super->super->x, pire->super->super->y);
            }
            if (sinek->simge == 'S' && sinek->super->super->canliMi == true) {
                printf("%c ", 'S');
                //printf("%c, %d, %d\n", sinek->simge, sinek->super->super->x, sinek->super->super->y);
            }
            if (bitki->simge == 'B' && bitki->super->canliMi == false) {
                printf("%c ", 'X');
                //printf("%c, %d, %d\n", bitki->simge, bitki->super->x, bitki->super->y);
            }
            if (bocek->simge == 'C' && bocek->super->canliMi == false) {
                printf("%c ", 'X');
                //printf("%c, %d, %d\n", bocek->simge, bocek->super->x, bocek->super->y);
            }
            if (pire->simge == 'P' && pire->super->super->canliMi == false) {
                printf("%c ", 'X');
                //printf("%c, %d, %d\n", pire->simge, pire->super->super->x, pire->super->super->y);
            }
            if (sinek->simge == 'S' && sinek->super->super->canliMi == false) {
                printf("%c ", 'X');
                //printf("%c, %d, %d\n", sinek->simge, sinek->super->super->x, sinek->super->super->y);
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

void kazananYazdir(Habitat this) {
    Bitki bitki = (Bitki)this->kazanan;
    Bocek bocek = (Bocek)this->kazanan;
    Pire pire = (Pire)this->kazanan;
    Sinek sinek = (Sinek)this->kazanan;
    if (bitki->simge == 'B' && bitki->super->canliMi == true) {
        printf("%c\n", 'B');
        printf("%p\n", bitki);
    }
    if (bocek->simge == 'C' && bocek->super->canliMi == true) {
        printf("%c\n", 'C');
        printf("%p\n", bocek);
    }
    if (pire->simge == 'P' && pire->super->super->canliMi == true) {
        printf("%c\n", 'P');
        printf("%p\n", pire);
    }
    if (sinek->simge == 'S' && sinek->super->super->canliMi == true) {
        printf("%c\n", 'S');
        printf("%p\n", sinek);
    }
}

/*void habitatYokEt(Habitat this) {
    for (int i = 0; i < this->satir; i++) {
        for (int j = 0; j < this->sutun; j++) {
            free(this->canliDizisi[i][j]);
        }
        free(this->canliDizisi[i]);
    }
    free(this->canliDizisi);
    free(this);
}*/

char turBelirle(Canli* this) {
    Bitki bitki = (Bitki)this;
    Bocek bocek = (Bocek)this;
    Pire pire = (Pire)this;
    Sinek sinek = (Sinek)this;
    if (bitki->simge == 'B') {
        return 'B';
    }
    if (bocek->simge == 'C') {
        return 'C';
    }
    if (pire->simge == 'P') {
        return 'P';
    }
    if (sinek->simge == 'S') {
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
        return 0;
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
        return 0;
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
        return 0;
    }
}

void savasciGonder(Habitat this) {
    Bitki bitki;
    Bocek bocek;
    Pire pire;
    Sinek sinek;
    printf("\n");



    for (int i = 0; i < this->satir; i++) {
        for (int j = 0; j < this->sutun; j++) {
            printf("%p\n", this->kazanan);
            printf("%p\n", this->canliDizisi[0][0]);
            Canli *canli1 = this->kazanan;
            kazananYazdir(this);
            if (this->kazanan == this->canliDizisi[i][j]) {
                continue;
            }
            Canli *canli2 = this->canliDizisi[i][j];
            Canli* temp;
            char tur1 = turBelirle(canli1);
            char tur2 = turBelirle(canli2);
            printf("%c", tur1);
            printf("%c\n", tur2);
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
            }



            habitatYazdir(this);
            //printf("%d", i);
            //printf("%d", j);
            /*bitki = (Bitki)this->kazanan;
            bocek = (Bocek)this->kazanan;
            pire = (Pire)this->kazanan;
            sinek = (Sinek)this->kazanan;*/
            /*if (bitki->simge == 'B' && bitki->super->canliMi == true) {
                printf("%c, %d, %d\n", bitki->simge, bitki->super->x, bitki->super->y);
            }
            if (bocek->simge == 'C' && bocek->super->canliMi == true) {
                printf("%c, %d, %d\n", bocek->simge, bocek->super->x, bocek->super->y);
            }
            if (pire->simge == 'P' && pire->super->super->canliMi == true) {
                printf("%c, %d, %d\n", pire->simge, pire->super->super->x, pire->super->super->y);
            }
            if (sinek->simge == 'S' && sinek->super->super->canliMi == true) {
                printf("%c, %d, %d\n", sinek->simge, sinek->super->super->x, sinek->super->super->y);
            }*/


        }
        printf("\n");
    }

    /*
    Canli *canli1;
    Canli *canli2;
    canli1 = this->kazanan;
    char tur1 = turBelirle(canli1);
    for (int i = 1; i < this->satir; i++) {
        for (int j = 0; j < this->sutun; j++) {
            canli2 = this->canliDizisi[i][j];
            char tur2 = turBelirle(canli2);
            if (tur1 == tur2) {
                continue;
            } else {
                char kazanan = kazananBul(tur1, tur2);
                if (kazanan == tur1) {
                    this->kazanan = canli1;
                    kaybedenOldur(canli1);

                } else {
                    this->kazanan = canli2;
                    kaybedenOldur(canli2);
                }
            }
        }
    }*/
}

void kaybedenOldur(Canli* this) {
    Bitki bitki = (Bitki)this;
    Bocek bocek = (Bocek)this;
    Pire pire = (Pire)this;
    Sinek sinek = (Sinek)this;
    if (bitki->simge == 'B' && bitki->super->canliMi == true) {
        bitki->super->canliMi = false;
    }
    if (bocek->simge == 'C' && bocek->super->canliMi == true) {
        bocek->super->canliMi = false;
    }
    if (pire->simge == 'P' && pire->super->super->canliMi == true) {
        pire->super->super->canliMi = false;
    }
    if (sinek->simge == 'S' && sinek->super->super->canliMi == true) {
        sinek->super->super->canliMi = false;
    }


}
/*
char kazananBul(char tur1, char tur2) {
    if (tur1 == 'B') {
        if (tur2 == 'P') {
            return 'B';
        }
        if (tur2 == 'S') {
            return 'B';
        }
    }
    if (tur1 == 'C') {
        if (tur2 == 'B') {
            return 'C';
        }
        if (tur2 == 'P') {
            return 'P';
        }
    }
    if (tur1 == 'S') {
        if (tur2 == 'P') {
            return 'S';
        }
    }
    return false;
}
*/

void habitatYokEt(Habitat this) {

}