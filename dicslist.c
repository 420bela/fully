
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dicslist.h"

#define MAX_JATEKOSOK 5

typedef struct DicsossegListaElem {
    char nev[50];
    int pontszam;
    int jatekido;
} DicsossegListaElem;

DicsossegListaElem dicsosseglista[MAX_JATEKOSOK];

void frissitDicsosleglistat(struct Jatekos *jatekos, int jatekido) {
    FILE *fajl = fopen("dicsosleglista.txt", "a");

    if (!fajl) {
        printf("Hiba: Nem sikerult megnyitni a dicsosleglista fajlt.\n");
        return;
    }

    fprintf(fajl, "Nev: %s - Pontszam: %d - Jatekido: %d perc\n", jatekos->nev, jatekos->pontszam, jatekido);

    fclose(fajl);
}

void kiirDicsosleglistat() {
    FILE *fajl = fopen("dicsosleglista.txt", "r");

    if (!fajl) {
        printf("Hiba: Nem sikerult megnyitni a dicsosleglista fajlt.\n");
        return;
    }

    int i = 0;
    while (fscanf(fajl, "Nev: %s - Pontszam: %d - Jatekido: %d perc\n", dicsosseglista[i].nev, &dicsosseglista[i].pontszam, &dicsosseglista[i].jatekido) == 3 && i < MAX_JATEKOSOK) {
        i++;
    }

    fclose(fajl);

    // Rendezzük a dicsõséglistát pontszám alapján
    for (int j = 0; j < i - 1; j++) {
        for (int k = 0; k < i - j - 1; k++) {
            if (dicsosseglista[k].pontszam < dicsosseglista[k + 1].pontszam) {
                // Cseréljük meg a két elemet
                DicsossegListaElem temp = dicsosseglista[k];
                dicsosseglista[k] = dicsosseglista[k + 1];
                dicsosseglista[k + 1] = temp;
            }
        }
    }

    // Kiírjuk csak az elsõ 5 játékost
    printf("\nDicsosleglista:\n");
    for (int j = 0; j < i && j < MAX_JATEKOSOK; j++) {
        printf("Nev: %s - Pontszam: %d - Jatekido: %d perc\n", dicsosseglista[j].nev, dicsosseglista[j].pontszam, dicsosseglista[j].jatekido);
    }
}
