#include <stdio.h>
#include <stdlib.h>
#include "Bitki.h"
#include "Bocek.h"
#include "Habitat.h"
#include "Canli.h"
#include "Pire.h"
#include "Sinek.h"


int main(void){

    /*Bitki bitki = bitkiOlustur(11, 22, 33);
    Bocek bocek = bocekOlustur(44, 55, 66);
    Bitki bitki1 = bitkiOlustur(7, 8, 9);
    Bocek bocek1 = bocekOlustur(10, 11, 12);

    Canli **canliDizisi  = (Canli **)malloc(2 * sizeof(Canli *));
    for (int i = 0; i < 2; i++) {
        canliDizisi[i] = (Canli *)malloc(2 * sizeof(Canli));
    }

    canliDizisi[0][0] = (Canli)bitki;
    canliDizisi[0][1] = (Canli)bocek;
    canliDizisi[1][0] = (Canli)bocek1;
    canliDizisi[1][1] = (Canli)bitki1;

    Bitki bitki2 = (Bitki)canliDizisi[0][0];
    Bocek bocek2 = (Bocek)canliDizisi[0][1];
    Bocek bocek3 = (Bocek)canliDizisi[1][0];
    Bitki bitki3 = (Bitki)canliDizisi[1][1];*/

    /*
    char* str = bitki3->super->gorunum(bitki3->super, bitki);
    printf("%s", str);
    free(str);

    char* str1 = bocek3->super->gorunum(bocek3->super, bocek);
    printf("%s", str1);
    free(str1);

    char* str2 = bitki2->super->gorunum(bitki2->super, bitki);
    printf("%s", str2);
    free(str2);

    char* str3 = bocek2->super->gorunum(bocek2->super, bocek);
    printf("%s", str3);
    free(str3);*/

    /*int satir = 0;
    int sutun = 0;

    habitatBoyutBelirle("Veri.txt", &satir, &sutun);

    printf("%d\n", satir);
    printf("%d", sutun);
    */

    /*habitat->canliDizisi[0][0] = (Canli)bitki;
    habitat->canliDizisi[0][1] = (Canli)bocek;

    Bitki bitki4 = (Bitki)habitat->canliDizisi[0][0];
    Bocek bocek4 = (Bocek)habitat->canliDizisi[0][1];

    char* str = bitki4->super->gorunum(bitki4->super, bitki);
    printf("%s", str);
    free(str);
    printf("%d", bitki4->super->x);

    char* str1 = bocek4->super->gorunum(bocek4->super, bocek);
    printf("%s", str1);
    free(str1);
    printf("%d", bocek4->super->x);*/

    Habitat habitat = habitatOlustur("Veri.txt");
    /*printf("%d", habitat->satir);
    printf("%d", habitat->sutun);

    Bocek bocek = (Bocek)habitat->canliDizisi[0][0];
    char* str = bocek->super->gorunum(bocek->super, bocek);
    printf("%s", str);
    free(str);*/

    habitatYazdir(habitat);
    //getchar();
    //kazananYazdir(habitat);
    savasciGonder(habitat);
    //printf("\n");
    //kazananYazdir(habitat);
    //printf("\n");
    //habitatYazdir(habitat);
    kazananYazdir(habitat);

    //habitatYazdir(habitat);







    return 0;
}
