#include <stdio.h>
#include "bemenet.h"

void fbemenet(struct Jatekos *jatekos) {
      printf("Udvozollek a Legyen On Is Milliomos jatekban!\n");
    printf("Kerlek, add meg a neved: ");
    scanf("%s", jatekos->nev);

    // Nehézségi szint választása
    printf("Valassz nehezsegi szintet:\n");
    printf("1 - Konnyu\n");
    printf("2 - Kozepes\n");
    printf("3 - Nehez\n");
    printf("4 - Nagyon nehez\n");

    while (1) {
        printf("Add meg a valasztott nehezsegi szintet (1-4): ");
        scanf("%d", &jatekos->nehezsegi_szint);

        if (jatekos->nehezsegi_szint >= 1 && jatekos->nehezsegi_szint <= 4) {
            break;
        } else {
            printf("Ervenytelen valasztas. Kerlek, valassz 1 es 4 kozott.\n");
        }
    }
    jatekos->pontszam=0;
    jatekos->jatek_ido=0;
}
