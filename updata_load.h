#include <stdio.h>
#include <stdbool.h>

#define STEP 4

//fuck i cant coding im too fuck

// нам надо инциализировать тип данных и заполнить его нулями
_Bool vect_first_init(struct vectors*);
_Bool vect_size_up(struct vectors*);
_Bool vect_back(struct vectors*, union vectors_data);
_Bool vect_set_item(struct vectors*, int, union vectors_data);
_Bool vect_del_back(struct vectors*);
_Bool vect_del_item(struct vectors*, int);
_Bool vect_shrink(struct vectors*);

union vectors_data
{
    char vchar;
    int vint;
    short vshort;
    long vlong;
    unsigned int vunsigint;
    unsigned long vunsiglong;
    float vfloat;
    double vdouble;
    long double vlb;
};

struct vectors{
    union vectors_data* ptr; 
    int size;
    int count;
};
