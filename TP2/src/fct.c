
#include<string.h>
#include <stdio.h>
#include "fct.h"
void print_state(size_t an, int a[an]){
    
    for(size_t i=0;i<an;i++){
        if(a[i]==0){
            printf("%c",' ');
        }
        else if (a[i]==1)
        {
            printf("%c",'*');
        }
        
    }
    printf("\n");
}

void rule30(size_t an, int a[an], int nsteps) {
    int temp[an];
 
    for (int step = 0; step < nsteps; step++) {
        print_state(an, a); 
 
        if (step == nsteps - 1) {
            break;
        }
 
        for (size_t i = 0; i < an; i++) {
            int gch  = (i == 0)      ? 0 : a[i - 1]; 
            int cent = a[i];
            int drt  = (i == an - 1) ? 0 : a[i + 1];
            
            if ((gch == 1 && cent == 1 && drt == 1) ||
                (gch == 1 && cent == 1 && drt == 0) ||
                (gch == 1 && cent == 0 && drt == 1) ||
                (gch == 0 && cent == 0 && drt == 0)) {
                temp[i] = 0;
            } else if ((gch == 1 && cent == 0 && drt == 0) ||
                       (gch == 0 && cent == 1 && drt == 1) ||
                       (gch == 0 && cent == 1 && drt == 0) ||
                       (gch == 0 && cent == 0 && drt == 1)) {
                temp[i] = 1;
            }
        }
 
        memcpy(a, temp, an * sizeof(int));
    }
}

void one_d_ca(uint8_t rule, size_t an, int a[an], int nsteps){
    int temp[an];
    uint8_t p;
    for (int step = 0; step < nsteps; step++) {
        print_state(an, a); 
 
        if (step == nsteps - 1) {
            break;
        }
 
        for (size_t i = 0; i < an; i++) {
            int gch  = (i == 0)      ? 0 : a[i - 1]; 
            int cent = a[i];
            int drt  = (i == an - 1) ? 0 : a[i + 1];
            p=4*gch+2*cent+drt;
            temp[i]=(rule>>p) &1;
        }
 
        memcpy(a, temp, an * sizeof(int));
    }
}
