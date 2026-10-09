
#include <stdio.h>
#include <stdint.h>
#include<stdlib.h>
uint64_t mul339(uint64_t a, uint64_t b){
     __uint128_t x=(__uint128_t)a*(__uint128_t)b;

    uint64_t x0 = x & ((1ULL<<33)-1);

    uint64_t x1=x>>33;
    uint64_t res=x0+9*x1;
    while (res>= 8589934583ULL){
        res-=9;
    }
    return res;

}
uint64_t hash339(uint64_t k, size_t buflen, uint8_t buf[buflen]){
    
}

int  main(){
    printf("2^33 *2^33= ");
    uint64_t a=1ULL<<33;
    uint64_t b=1ULL<<33;
    printf("%lu",mul339(a,b));
    return 0;
}
