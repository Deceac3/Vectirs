#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define STEP 4
#define MAX 20

union vectors_data
{
    char text[MAX];      //1
    double vd;           //2
    unsigned long vunsiglong;//3
    unsigned int vunsigint;//4
    long vlong;         //5
    int vint;           //6
    short vshort;       //7
    char vchar;         //8
};

struct vectors{
    union vectors_data** ptr;
    char** data_ment; 
    int size;
    int count;
};

//fuck i cant coding im too fuck

// нам надо инциализировать тип данных и заполнить его нулями
_Bool vect_first_init(struct vectors*);
_Bool vect_size_up(struct vectors*);
_Bool vect_back(struct vectors*, union vectors_data);
_Bool vect_set_item(struct vectors*, int, union vectors_data);
_Bool vect_del_back(struct vectors*);
_Bool vect_del_item(struct vectors*, int);
_Bool vect_shrink(struct vectors*);
_Bool stdiput_OP(struct vectors*,int);
_Bool moove_vector_left(struct vectors*,int);

int type_check(char buf[MAX]);