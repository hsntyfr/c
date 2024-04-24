#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bitki.h"
#include "Habitat.h"
#include "Canli.h"
#include "Bocek.h"

int main(void) {
    //printf("%s", "dede");
    //Habitat habitat = habitatOlustur();
    //printf("%d", habitat->boyut);

    /*FILE *dosya;
    dosya = fopen("Veri.txt", "r");
    if (dosya == NULL) {
        perror("Dosya açma hatası");
    }
    int boyut = 0;
    char satir[3];
    while (fgets(satir, 3, dosya) != NULL) {
        char *token = strtok(satir, " ");
        while (token != NULL) {
            printf("%d ", atoi(token));
            token = strtok(NULL, " ");
        }
        printf("\n");
        boyut++;
    }
    printf("%d\n", boyut);
    fclose(dosya);*/

    //habitatYokEt(habitat);
    //printf("%s", "dede");

    Bocek bocek = bocekOlustur(1, 2, 3);
    char* str = bocek->super->gorunum(bocek->super, bocek);
    printf("%s", str);
    free(str);
    bocekYokEt(bocek);

    Bitki bitki = bitkiOlustur(4, 5, 6);
    char* str1 = bitki->super->gorunum(bitki->super, bitki);
    printf("%s", str1);
    free(str1);
    bitkiYokEt(bitki);

    return 0;
}
