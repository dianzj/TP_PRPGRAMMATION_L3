#ifndef FCT_H
#define FCT_H
#include <stdint.h>
#include<stdlib.h>
void print_state(size_t an, int a[an]);

void rule30(size_t an, int a[an], int nsteps);
void one_d_ca(uint8_t rule, size_t an, int a[an], int nsteps);
#endif