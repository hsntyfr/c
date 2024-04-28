#ifndef CANLI_H
#define CANLI_H

typedef enum {
    false, true
} bool;

struct CANLI {
    int x;
    int y;
    int deger;
    bool canliMi;

    void (*yokEt)(struct CANLI*);
    char* (*gorunum)(struct CANLI*, void*);
    char (*getSimge)();

};
typedef struct CANLI* Canli;

Canli canliOlustur(int, int, int);
void yokEt(Canli);

char* gorunum(Canli, void*);


#endif //CANLI_H
