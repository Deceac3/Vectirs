#include "updata_load.h"

int IntPlayerChoose(){
    char buf[80];
    int x;
    scanf("%d", &x);
    if (fgets(buf, sizeof buf, stdin)){return x;}
    else{
        return 0;
    }
};

_Bool vector_type_Indef(){

}

_Bool vect_first_init(struct vectors* buff){
    buff->ptr=malloc(sizeof(union vectors_data)*STEP);
    if (buff->ptr != NULL)
    {
        buff->size = STEP;
        buff->count = 0;
        return true;
    }
    else
    {
        printf("Выделение памяти не произошло(");
        return false;
    }
    
}

//Чёрт, нам же надо хранить каждый объект........... фак
_Bool vect_size_up(struct vectors* buff){
    buff->ptr=realloc(buff->ptr, (buff->size+STEP)*sizeof(union vectors_data));
    if(buff->ptr!=NULL){
        buff->size+=STEP;
        return true;
    }
    else{
        return false;
    }
}

_Bool vect_back(struct vectors* buff, union vectors_data buf){
    if (buff->size>= buff->count+1)
    {
        buff->ptr[buff->count+1]=buf;
        buff->count++;
        return true;
    }
    else
    {
        if(int_vect_size_up(buff)){
            buff->ptr[buff->count+1]=buf;
            buff->count++;
            return true;
        }
        else{
            return false;
        }
    }
}

_Bool vect_set_item(struct vectors* buff, int indx, union vectors_data buf){
    if(buff->count>=(indx-1)){ 
        buff->ptr[indx]==buf;
        return true;
    }
    else
    {
        printf("Замена несуществующих эллементов невозможно!");
        return false;
    }
}

_Bool vect_del_item(struct vectors* buff, int indx){
    if (indx>=0)
    {
        if (buff->count>=(indx-1))
        {
            for(int i=indx;i<buff->count;i--){
                buff->ptr[i]=buff->ptr[i+1];
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
        printf("Индекс должен быть больше 0 и меньше %d", buff->count);
        return false;
    }
    
}

_Bool vect_del_back_int(struct vectors* buff){
    if(buff->count!=0){
        buff->ptr[buff->count]=0;
        buff->count--;
        return true;
    }
    else
    {
        return false;
    }
    
}

_Bool vect_shrink_int(struct vectors* buff){
    if (buff->count!=0)
    {
        buff->ptr=realloc(buff->ptr,buff->count*sizeof(int));
        if (buff->ptr!=NULL)
        {
            buff->size=buff->count;
            return true;
        }
        else
        {
            printf("Ошибка выделения памяти");
            return false;
        }
    }
    else{
        buff->ptr=realloc(buff->ptr,sizeof(union vectors_data)*STEP);
    }
}

/*###### Z ZZ Z ZZ Z ZABIL ##### # #*/
