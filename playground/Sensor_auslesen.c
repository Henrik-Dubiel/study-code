#include <stdio.h>

int main() {
    unsigned char status = 0xCC;
    unsigned char messwert;
    if(status & (1<<7)) {
        printf("Es liegt ein Fehler vor!\n");
    }
    else {
        printf("Es liegt kein Fehler vor!\n");
    }
    if(status & (1<<6)) {
        printf("Es liegt eine Uebertemperatur vor!\n");
    }
    else {
        printf("Es liegt keine Uebertemperatur vor!\n");
    }
    if(status & (1<<5)) {
        printf("Es liegt eine Unterspannung vor!\n");
    }
    else {
        printf("Es liegt keine Unterspannung vor!\n");
    }
    messwert = status & 0x0F;
    printf("Der Messwert betraegt %u", messwert);
    return 0;
}