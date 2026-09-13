#include "fct.h"
#include<stdlib.h>
#include<stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include "test_fct.h"
#include<string.h>
void test_print_state(void) {
    printf("Test print_state\n");

    int tout_zero[5] = {0, 0, 0, 0, 0};
    printf("TOUT_ZERO\n");
    print_state(5, tout_zero);
     
    int tout_un[5] = {1, 1, 1, 1, 1};
    printf("TOUT_UN\n");
    print_state(5, tout_un);

    int melange[5] = {0, 1, 0, 1, 1};
    printf("MELANGE\n");
    print_state(5, melange);
}

void test_rule30(void) {
    printf("Test rule30\n");

    size_t an = 79;
    int a[an];
    for (size_t i = 0; i < an; i++) {
        a[i] = 0;
    }
    a[an / 2] = 1;

    rule30(an, a, 100);
}
void test_one_d_ca(size_t an, int a[an]){
    printf("Test one-dimensional cellular automaton\n");
    uint8_t rule;
    int tmp[an];
    while(1){
        printf("VEUILLEZ ENTREZ LA REGLE\n");
        
        if (scanf("%" SCNu8, &rule) != 1) {
            break;
        }
        memcpy(tmp,a, an * sizeof(int));
        one_d_ca(rule,an,a,100);
        printf("FIN DU TEST_ONE_D_CA POUR LA REGLE%d\n",rule);
        printf("CTRL+C POUR FINIR LE PROGRAMME\n");
        memcpy(a,tmp, an * sizeof(int));
    }
}
void test_etat_un_milieu(void) {
    size_t an = 79;
    int a[an];
    for (size_t i = 0; i < an; i++) {
        a[i] = 0;
    }
    a[an / 2] = 1;
    test_one_d_ca(an, a);
}

void test_etat_dizaine(void) {
    size_t an = 79;
    int a[an];
    for (size_t i = 0; i < an; i++) {
        a[i] = 0;
    }
    for (size_t i = an / 2 - 5; i < an / 2 + 5; i++) {
        a[i] = 1;
    }
    test_one_d_ca(an, a);
}

void test_etat_moitie(void) {
    size_t an = 79;
    int a[an];
    for (size_t i = 0; i < an; i++) {
        a[i] = (i % 2 == 0) ? 1 : 0;
    }
    test_one_d_ca(an, a);
}

void test_etat_nul(void) {
    size_t an = 79;
    int a[an];
    for (size_t i = 0; i < an; i++) {
        a[i] = 0;
    }
    test_one_d_ca(an, a);
}

