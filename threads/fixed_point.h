#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

#include <stdint.h>

#define F (1 << 14) // Fator de escala para ponto fixo (2^14)

typedef int fixed_t; // Tipo do dado de ponto fixo

#define INT_TO_FIXED(n) ((fixed_t)(n) * F)
#define FIXED_TO_INT_ZERO(x) ((x) / F)
#define FIXED_TO_INT_NEAREST(x) ((x) >= 0 ? ((x) + F / 2) / F : ((x) - F / 2) / F)

// Definindo as operações aritméticas para ponto fixo
#define ADD_FIXED(x, y) ((x) + (y))
#define SUB_FIXED(x, y) ((x) - (y))
#define ADD_FIXED_INT(x, n) ((x) + (n) * F)
#define SUB_FIXED_INT(x, n) ((x) - (n) * F)
#define MULT_FIXED(x, y) ((fixed_t)(((int64_t)(x)) * (y) / F))
#define MULT_FIXED_INT(x, n) ((x) * (n))
#define DIV_FIXED(x, y) ((fixed_t)((((int64_t)(x)) * F) / (y)))
#define DIV_FIXED_INT(x, n) ((x) / (n))

#endif