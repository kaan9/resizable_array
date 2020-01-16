#include "resizable_array.h"

#include <stdlib.h>

struct r_array {
        char * data;
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
        realloc(v->data, sizeof(char) * v->unit * INIT_CAPACITY);
        v->capacity = INIT_CAPACITY;
}

void vector_clear(VECTOR * v)
{
        realloc(v->data, sizeof(char) * v->unit * INIT_CAPACITY);
        v->capacity = INIT_CAPACITY;
        v->size = 0;
        return 0;
}

void vector_delete(VECTOR * v)
{
        free(v->data);
        free(v);
}

static size_t max(size_t a, size_t b)
{
        return a > b ? a : b;
}

VECTOR * duplicate(VECTOR * v, size_t start, size_t end)
{
        VECTOR * v2 = malloc(sizeof(VECTOR));
        if(!v2) return NULL;

        v2->capacity = max(INIT_CAPACITY, end - start + 1);
        v2->data = malloc(sizeof(char) * (v2->unit = v->unit) * v2->capacity);
        if (!v2->data) {
                free(v2);
                return NULL;
        }

        v2->size = end - start + 1;
        memcpy(v2->data, v->data + v->unit * start, v->unit * (end - start + 1));

        return v2;
}
void * vector_data(VECTOR * v)
{
        return v->data;
}

void * vector_at(VECTOR * v, size_t index)
{
        return v->data + v->unit * index;
}

void * vector_push_back(VECTOR * v, void * elt)
{
        if (v->size < v->capacity) {
                memcpy(v->data + v->unit * v->size++, elt, v->unit);
        } else {
                
        }
}

void * vector_push_front(VECTOR * v, void * elt);

void * vector_pop_back(VECTOR * v);

void * vector_pop_front(VECTOR * v);

