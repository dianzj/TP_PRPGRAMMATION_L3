#include<string.h>
#include <stdio.h>
#include "sqrt.h"
uint64_t lzc(uint64_t x){
    uint64_t j=64;
    for(int64_t i=63;i>=0;i--){
        if((x>>i)&1){
            return 64-j;
        }
        j=j-1;
    }
    return 64-j;
}

uint64_t isqrta(uint64_t x)
{
    if (x == 0) {
        return 0;
    }

    uint64_t i = 32 - lzc(x - 1) / 2;

    return 1ULL << i;
}
uint64_t  Babylo(uint64_t x){
    if(x==0){
        return 0;
    }
    uint64_t k=63-lzc(x);

    uint64_t un=1ULL<<((k+2)/2);

    uint64_t un1=(un+(x/un))/2;
    
    while(un>un1){
        un=un1;
        un1=(un+(x/un))/2;
        
    }
    return un;
}



