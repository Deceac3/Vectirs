#include <stdio.h>
#include <stdbool.h>

#define STEP 4

//fuck i cant coding im too fuck

// нам надо инциализировать тип данных и заполнить его нулями
_Bool vect_first_init(struct vectors*);

_Bool int_vect_size_up(struct vectors*);
_Bool int_vect_back(struct vectors*, int);
_Bool int_vect_set_item_int(struct vectors*, int, int);

_Bool char_vect_size_up(struct vectors*);

_Bool vect_first_init(struct vectors* buff){
    return true;
}

//Чёрт, нам же надо хранить каждый объект........... фак
_Bool int_vect_size_up(struct vectors* buff){
    buff->int_arr.ptr=realloc(buff->int_arr.ptr, (buff->int_arr.size+STEP)*sizeof(int));
    if(buff->int_arr.ptr!=NULL){
        buff->int_arr.size+=STEP;
        return true;
    }
    else{
        return false;
    }
}

_Bool int_vect_back(struct vectors* buff, int buf){
    if (buff->int_arr.size>= buff->int_arr.count+1)
    {
        buff->int_arr.ptr[buff->int_arr.count+1]=buf;
        buff->int_arr.count++;
        return true;
    }
    else
    {
        if(int_vect_size_up(buff)){
            buff->int_arr.ptr[buff->int_arr.count+1]=buf;
            buff->int_arr.count++;
            return true;
        }
        else{
            return false;
        }
    }
}

_Bool int_vect_set_item_int(struct vectors* buff, int indx, int buf){
    if(buff->int_arr.count>=(indx-1)){
        buff->int_arr.ptr[indx]==buf;
        return true;
    }
    else
    {
        printf("Замена несуществующих эллементов невозможна!");
        return false;
    }
    
}

_Bool char_vect_back(struct vectors* buff, int buf){
    
}

_Bool char_vect_size_up(struct vectors* buff){
    buff->char_arr.size+=STEP;
    buff->char_arr.ptr=realloc(buff->char_arr.ptr, buff->char_arr.size+STEP);
}

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
