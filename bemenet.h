#ifndef BEMENET_H_INCLUDED
#define BEMENET_H_INCLUDED

struct Jatekos {
    char nev[50];
    int nehezsegi_szint;
    int pontszam;
    int jatek_ido;
} Jatekos;

void fbemenet(struct Jatekos *jatekos);

#endif /
