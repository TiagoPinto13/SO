#include "vector.h"
vector* vector_add(vector* v1, vector* v2) {
    vector* result = vector_new(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z);
    return result;
}