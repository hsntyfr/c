#include "Habitat.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int habitatBoyutBelirle(FILE* dosya) {
    int boyut = 0;
    char satir[3];
    while (fgets(satir, 3, dosya) != NULL) {
        char *token = strtok(satir, " ");
        while (token != NULL) {
            //printf("%d ", atoi(token));
            token = strtok(NULL, " ");
        }
        //printf("\n");
        boyut++;
    }
    fseek(dosya, 0, SEEK_SET);
    //printf("%d", boyut);
    return boyut;
}

Habitat habitatOlustur() {
    Habitat this;
    FILE *dosya;
    dosya = fopen("Veri.txt", "r");
    this->boyut = habitatBoyutBelirle(dosya);
    this->canlilar = (Canli)malloc(this->boyut * sizeof(Canli)); //galiba burası yanlış bunun yerine sankii görünümle bir şeyler yapmak gerekcek gibi
    fclose(dosya);
    return this;
}

void habitatYokEt(Habitat this)
{
    if(this == NULL) {
        return;
    }
    if (this->canlilar != NULL) {
        free(this->canlilar);
    }
    //free(this);
}


