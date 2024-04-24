#ifndef CANLI_H
#define CANLI_H

typedef enum {
    false, true
} bool;

struct CANLI {
    int x;
    int y;
    int deger;
    char tur; //??????????
    bool canliMi;
    float sonaUzaklık;

    char* (*gorunum)(struct CANLI*, void*);
    void (*yokEt)(struct CANLI*);

};
typedef struct CANLI* Canli;

Canli canliOlustur(int, int, int);
char* gorunum(Canli, void*);
void yokEt(Canli);


#endif //CANLI_H
