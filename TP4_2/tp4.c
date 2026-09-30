#include <stdio.h>
#include <stdint.h>
#include "isqrt.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "isqrt.h"

void test_isqrt(void)
{
    unsigned long i;
    unsigned long erreurs = 0;
    unsigned int x, attendu, obtenu;

    for (i = 0; i < (1UL << 23); i++) {
        /* nombre aléatoire entre 0 et 2^32 - 1 */
        x = ((unsigned int)(rand() & 0xFFFF) << 16) | (rand() & 0xFFFF);

        attendu = (unsigned int)floor(sqrt((double)x));
        obtenu  = isqrt(x);

        if (obtenu != attendu) {
            printf("Erreur : isqrt(%u) = %u, attendu %u\n", x, obtenu, attendu);
            erreurs++;
        }
    }

    printf("%lu erreurs sur %lu tests\n", erreurs, 1UL << 23);
}



int main(void)
{
    printf("isqrt(0) = %llu\n",
           (unsigned long long)isqrt(0));

    printf("isqrt(4) = %llu\n",
           (unsigned long long)isqrt(4));

    printf("isqrt(10) = %llu\n",
           (unsigned long long)isqrt(10));

    printf("isqrt(25) = %llu\n",
           (unsigned long long)isqrt(25));

    printf("isqrt(100) = %llu\n",
           (unsigned long long)isqrt(100));
    printf("isqrt(10) = %llu\n",
           (unsigned long long)isqrt(10));


    srand(time(NULL));
    test_isqrt();
    return 0;       
    return 0;
}
