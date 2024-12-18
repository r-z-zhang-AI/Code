#ifndef _ARRAY_H_
#define _ARRAT_H_

const int BLOCK_SIZE = 20;

typedef struct {
    int* array;
    int size;
} Array;

Array array_creat(int init_size);
void arrar_free(Array *a);
int array_size(const Array *a);
int* array_at(Array *a, int index);
void array_inflate(Array *a, int more_size);

#endif