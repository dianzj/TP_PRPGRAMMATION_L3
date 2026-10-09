#include <stdio.h>
#include <stdint.h>
#include "include/isqrt.h"

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

    return 0;
}
