#include<stdlib.h>
#include<stdint.h>
#include <stdio.h>
#include "ps.h"

void test_double(size_t dim, int repet){
    double x[dim];
    double y[dim];
    for(size_t i=0;i<dim;i++){
        x[i]=1;
        y[i]=1;
    }
    double somme=0;
    for(int i=0;i<repet;i++){
        somme+=psd(dim,x,y);
    }
    printf("somme du produit scalaire de x et y avec %d repet = %f\n",repet,somme);

}
void test_float(size_t dim, int repet){
    float x[dim];
    float y[dim];
    for(size_t i=0;i<dim;i++){
        x[i]=1;
        y[i]=1;
    }
    float somme=0;
    for(int i=0;i<repet;i++){
        somme+=psf(dim,x,y);
    }
    printf("somme du produit scalaire de x et y avec %d repet = %f\n",repet,somme);

}
void test_u64(size_t dim, int repet){
    uint64_t x[dim];
    uint64_t y[dim];
    for(size_t i=0;i<dim;i++){
        x[i]=1;
        y[i]=1;
    }
    uint64_t somme=0;
    for(int i=0;i<repet;i++){
        somme+=psu64(dim,x,y);
    }
    printf("somme du produit scalaire de x et y avec %d repet = %lu\n",repet,somme);
  
}

void test_32(size_t dim, int repet){
    uint32_t x[dim];
    uint32_t y[dim];
    for(size_t i=0;i<dim;i++){
        x[i]=1;
        y[i]=1;
    }
    uint32_t somme=0;
    for(int i=0;i<repet;i++){
        somme=somme+psu32(dim,x,y);
    }
    printf("somme du produit scalaire de x et y avec %d repet = %d\n",repet,somme);

}

int main(int argc, char **argv){
    size_t dim   = (argc > 1) ? (size_t)atol(argv[1]) : 1000;
    int    repet = (argc > 2) ? atoi(argv[2])         : 1000;

    printf("dim = %zu, repet = %d\n", dim, repet);

    test_double(dim, repet);
    test_float(dim, repet);
    test_u64(dim, repet);
    test_32(dim, repet);

    return 0;
}