#include "test_fct.h"
#include "fct.h"
#include <stdio.h>

int main(void) {
    int choix;

    printf("Quel test lancer ?\n");
    printf("1 - test_print_state\n");
    printf("2 - test_rule30\n");
    printf("3 - test_etat_un_milieu\n");
    printf("4 - test_etat_dizaine\n");
    printf("5 - test_etat_moitie\n");
    printf("6 - test_etat_nul\n");
    printf("Choix : ");

    if (scanf("%d", &choix) != 1) {
        return 1;
    }

    switch (choix) {
        case 1:
            test_print_state();
            break;
        case 2:
            test_rule30();
            break;
        case 3:
            test_etat_un_milieu();
            break;
        case 4:
            test_etat_dizaine();
            break;
        case 5:
            test_etat_moitie();
            break;
        case 6:
            test_etat_nul();
            break;
        default:
            printf("Choix invalide\n");
            return 1;
    }

    return 0;
}