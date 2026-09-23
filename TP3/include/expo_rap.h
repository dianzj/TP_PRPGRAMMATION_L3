#ifndef EXPO_RAP_H
#define EXPO_RAP_H
#include <stdint.h>
#include<stdlib.h>

uint64_t add293(uint64_t a, uint64_t b);
uint64_t mul293(uint64_t a, uint64_t b);
uint64_t slow_exp(uint64_t a, uint64_t n);
uint64_t fast_exp_rec(uint64_t a,uint64_t n);
uint64_t fast_exp_iter(uint64_t a, uint64_t n);
#endif