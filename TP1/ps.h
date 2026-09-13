#ifndef SCALAIRE_H
#define SCALAIRE_H

double psd (size_t dim, double x[dim], double y[dim]);
float psf (size_t dim, float x[dim], float y[dim]);
uint64_t  psu64 (size_t dim, uint64_t x[dim], uint64_t y[dim]);

uint32_t  psu32 (size_t dim, uint32_t x[dim], uint32_t y[dim]);
#endif