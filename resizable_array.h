/* Resizable array header --- kbe --- public domain */

/*
 * An array of generic elts that automatically resizes,
 * similar to the vector type in C++
 * Increases capacity by INC_MULTIPLE when filled to capacity
 * Decreases capacity by DEC_MULTIPLE when size decreases to
 * less than DEC_FRACT
 * fractional capacities are rounded up
 * capacity is always at least INIT_CAPACITY
 * 
 * USAGE:
 * elts are copied into the array: for the relevant functions
 * pass a pointer to the value from which location 'unit' bytes
 * will be copied. For functions returning values from the array,
 * cast the void* pointer returned to the relevant type
 * and dereference
 *
 * Upon error, relevant functions will return NULL if returning
 * a pointer type and a nonzero value if returning an int and
 * also set the errno if applicable
 */

#define INIT_CAPACITY 8
#define INC_MULTIPLE 2.0
#define DEC_MULTIPLE 0.5
#define DEC_FRACT 0.25

struct r_array;

typedef struct r_array VECTOR;


/**** Creation and Destruction ****/

/* returns an empty vector with elts of size unit */
VECTOR *
vector_init(size_t unit);

/* copy with start and end inclusive */ 
VECTOR *
duplicate(VECTOR * v, size_t start, size_t end);

void
vector_delete(VECTOR * v);

/**** Properties ****/

size_t
vector_size(VECTOR * v);


/**** Access ****/

/* 
 * returns a pointer of the location of the data
 * at index, should be cast and then dereferenced
 * to access data
 */
void *
vector_at(VECTOR * v, size_t index);

/*
 * returns a pointer to the start of stored data
 * should be cast to a pointer of the stored type
 * (e.g. int*) for meaningful access
 */
void *
vector_data(VECTOR * v);


/**** Modification ****/

void
vector_set(VECTOR * v, void * elt);

void
vector_clear(VECTOR * v);

void
vector_push(VECTOR * v, void * elt);

void *
vector_pop(VECTOR * v);
