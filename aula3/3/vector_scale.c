#include "vector.h"
vector* vector_scale(double scalar, vector* v) {
    vector* result = vector_new(scalar * v->x, scalar * v->y, scalar * v->z);
    return result;
}