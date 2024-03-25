#include <stdio.h>
#include <stdbool.h>

#define STEP 4

//fuck i cant coding im too fuck

// нам надо инциализировать тип данных и заполнить его нулями
_Bool vect_first_init(struct vectors*);

_Bool int_vect_size_up(struct vectors*);
_Bool int_vect_back(struct vectors*, int);
_Bool vect_set_item_int(struct vectors*, int, int);
_Bool vect_del_back_int(struct vectors*);
_Bool vect_del_item_int(struct vectors*, int);
_Bool vect_shrink_int(struct vectors*);

_Bool char_vect_size_up(struct vectors*);

//массив интов
struct int_vector{
    int size;
    int count;
    int* ptr;
};

//массив сиволов
struct char_vector{
    int size;
    int count;
    char* ptr;
};

//fuck this shit
struct vectors{
    struct int_vector int_arr;
    struct char_vector char_arr;
};
