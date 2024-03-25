#include "updata_load.h"

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

_Bool vect_set_item_int(struct vectors* buff, int indx, int buf){
    if(buff->int_arr.count>=(indx-1)){
        buff->int_arr.ptr[indx]==buf;
        return true;
    }
    else
    {
        printf("Замена несуществующих эллементов невозможно!");
        return false;
    }
}

_Bool vect_del_item_int(struct vectors* buff, int indx){
    if (indx>=0)
    {
        if (buff->int_arr.count>=(indx-1))
        {
            for(int i=indx;i<buff->int_arr.count;i--){
                buff->int_arr.ptr[i]=buff->int_arr.ptr[i+1];
            }
            return true;
        }
        else
        {
            printf("Удаление несуществующих эллементов невозможно!");
            return false;
        }
    }
    else
    {
        printf("Индекс должен быть больше 0 и меньше %d", buff->int_arr.count);
        return false;
    }
    
}

_Bool vect_del_back_int(struct vectors* buff){
    if(buff->int_arr.count!=0){
        buff->int_arr.ptr[buff->int_arr.count]=0;
        buff->int_arr.count--;
        return true;
    }
    else
    {
        return false;
    }
    
}

_Bool vect_shrink_int(struct vectors* buff){
    if (buff->int_arr.count!=0)
    {
        buff->int_arr.ptr=realloc(buff->int_arr.ptr,buff->int_arr.count*sizeof(int));
        if (buff->int_arr.ptr!=NULL)
        {
            buff->int_arr.size=buff->int_arr.count;
            return true;
        }
        else
        {
            printf("Ошибка выделения памяти");
            return false;
        }
    }
    else{
        buff->int_arr.ptr=realloc(buff->int_arr.ptr,sizeof(int)*STEP);
    }
}

/*###### Z ZZ Z ZZ Z ZABIL ##### # #*/

_Bool char_vect_back(struct vectors* buff, int buf){
    
}

_Bool char_vect_size_up(struct vectors* buff){
    buff->char_arr.size+=STEP;
    buff->char_arr.ptr=realloc(buff->char_arr.ptr, buff->char_arr.size+STEP);
}