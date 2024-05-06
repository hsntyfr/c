#include <stdio.h>
#include "Habitat.h"

int main(void){
    Habitat habitat = habitatOlustur("Veri.txt");
    habitat->habitatYazdir(habitat);
    getchar();
    habitat->savasBaslat(habitat);
    habitat->kazananYazdir(habitat);
    habitat->habitatYokEt(habitat);
    return 0;
}