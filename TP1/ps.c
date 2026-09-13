#include<stdlib.h>
#include<stdint.h>
#include "ps.h"
double psd (size_t dim, double x[dim], double y[dim]){
    double prod=0;
    for(size_t i=0;i<dim;i++){
        prod+=x[i]*y[i];
    }
    return prod;
}

float psf (size_t dim, float x[dim], float y[dim]){
    float prod=0.0;
    for(size_t i=0;i<dim;i++){
        prod+=x[i]*y[i];
    }
    return prod;
}
uint64_t psu64 (size_t dim, uint64_t x[dim], uint64_t y[dim]){
    uint64_t prod=0;
    for(size_t i=0;i<dim;i++){
        prod+=x[i]*y[i];
    }
    return prod;
}

uint32_t psu32 (size_t dim, uint32_t x[dim], uint32_t y[dim]){
    uint32_t prod=0;
    for(size_t i=0;i<dim;i++){
        prod+=x[i]*y[i];
    }
    return prod;
}