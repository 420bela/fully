
#include <time.h>

clock_t kezdetiIdo;

void idoMeresInditas() {
    kezdetiIdo = clock();
}

int lejartIdoMeres() {
    clock_t jelenlegiIdo = clock();
    double lejartIdo = (double)(jelenlegiIdo - kezdetiIdo) / CLOCKS_PER_SEC;
    return (int)lejartIdo;
}

void idoMeresLeallitas() {
    kezdetiIdo = 0;
}
