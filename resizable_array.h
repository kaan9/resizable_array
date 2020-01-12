/* Resizable array header --- kbe --- public domain */

/*
 * An array of void* elts that automatically resizes,
 * similar to the vector type in C++
 * Increases capacity by INC_MULTIPLE when filled to capacity
 * Decreases capacity by DEC_MULTIPLE when size decreases to
 * less than DEC_FRACT
 * fractional capacities are rounded up
 * capacity is always at least INIT_CAPACITY
 */

#define INIT_CAPACITY 8
#define INC_MULTIPLE 2.0
#define DEC_MULTIPLE 2.0
#define DEC_FRACT 0.25

struct r_array {
        void * start;    /* first elt */
        void * end;      /* end of capacity + 1 */
        size_t capacity; 
        size_t size;
};

typedef R_ARRAY struct r_array;

R_ARRAY
vector_init();

