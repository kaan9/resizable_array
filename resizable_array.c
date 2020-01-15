#include "resizable_array.h"

#include <stdlib.h>

struct r_array {
        void * data;
        size_t capacity;
        size_t size;
        size_t unit; /* size of each elt in bytes */ 
};

VECTOR * vector_init(size_t unit)
{
        VECTOR * v = malloc(sizeof(VECTOR));
        if (!v) return NULL; /* relay errno from malloc */

        v->capacity = INIT_CAPACITY;
        v->size = 0;
        v->unit = unit;
        
        v->data = malloc(sizeof(char) * unit * INIT_CAPACITY);
        if (!v->data) {
                free();
                return NULL; /* relay errno from malloc */
        }

        return v;
}

size_t vector_size(VECTOR * v)
{
        return v->size;
}

static int vector_recapacity(VECTOR * v, size_t new_cap)
{
        
}

int vector_clear(VECTOR * v)
{
        
}

void vector_delete(VECTOR * v);

/* 
 * creates a new vector with data form indices start 
 * to end (inclusive) copied from v
 */
VECTOR * duplicate(VECTOR * v, size_t start, size_t end);

/*
 * returns a pointer to the start of stored data
 * should be cast to a pointer of the stored type
 * (e.g. int*) for meaningful access
 */
void * vector_data(VECTOR * v);

/* 
 * returns a pointer of the location of the data
 * at index, should be cast and then dereferenced
 * to access data
 */
void * vector_at(VECTOR * v, size_t index);

void * vector_push_back(VECTOR * v, void * elt);

void * vector_push_front(VECTOR * v, void * elt);

void * vector_pop_back(VECTOR * v);

void * vector_pop_front(VECTOR * v);

