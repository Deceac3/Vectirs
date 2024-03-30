#include "updata_load.h"
//We need first start for vectors
_Bool vect_first_init(struct vectors* buff){
    buff->ptr=malloc(sizeof(union vectors_data)*STEP);
    buff->data_ment=malloc(sizeof(char)*STEP);
    if ((buff->ptr != NULL) && (buff->data_ment!= NULL))
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
//this function resized function to more space on STEP
_Bool vect_size_up(struct vectors* buff){
    buff->ptr=realloc(buff->ptr, (buff->size+STEP)*sizeof(union vectors_data));
    buff->data_ment=realloc(buff->data_ment, (buff->size+STEP)*sizeof(char));
    if((buff->ptr!=NULL)&&(buff->data_ment!=NULL)){
        buff->size+=STEP;
        return true;
    }
    else{
        return false;
    }
}
//this function place item back to arr
_Bool vect_back(struct vectors* buff){
    if (buff->size>= buff->count+1)
    {
        if(stdiput_OP(buff,buff->count)){
            buff->count++;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(vect_size_up(buff)){
            if(stdiput_OP(buff,buff->count)){
                buff->count++;
                return true;
            }
            else
            {
                return false;
            }
        }
        else{
            return false;
        }
    }
}
//this function replace item with index
_Bool vect_set_item(struct vectors* buff, int indx){
    if(buff->count>=(indx-1)){ 
        if(stdiput_OP(buff,indx)){
            return true;
        }
        else
        {
            return false;
        }
        
    }
    else
    {
        printf("Замена несуществующих эллементов невозможно!");
        return false;
    }
}
//fuction to del the item with indx
_Bool vect_del_item(struct vectors* buff, int indx){
    if (indx>=0)
    {
        if (buff->count>=(indx-1))
        {
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
//its op function for del function to moove all items left
_Bool moove_vector_left(struct vectors* vector,int indx){
    for(int i = vector->count; i<vector->size;i++){
        switch (*vector->data_ment[i])
        {
        case 1:
            *vector->ptr[i]->text=*vector->ptr[i+1]->text;
            vector->data_ment[i]=vector->data_ment[i+1];
            return true;
            break;
        case 2:
            vector->ptr[i]->vd=vector->ptr[i+1]->vd;
            vector->data_ment[i]=vector->data_ment[i+1];
            return true;
            break;
        case 3:
            vector->ptr[i]->vunsiglong=vector->ptr[i+1]->vunsiglong;
            vector->data_ment[i]=vector->data_ment[i+1];
            return true;
            break;
        case 4:
            vector->ptr[i]->vunsigint=vector->ptr[i+1]->vunsigint;
            vector->data_ment[i]=vector->data_ment[i+1];
            return true;
            break;
        case 5:
            vector->ptr[i]->vlong=vector->ptr[i+1]->vlong;
            vector->data_ment[i]=vector->data_ment[i+1];
            return true;
            break;
        case 6:
            vector->ptr[i]->vint=vector->ptr[i+1]->vint;
            vector->data_ment[i]=vector->data_ment[i+1];
            return true;
            break;
        case 7:
            vector->ptr[i]->vshort=vector->ptr[i+1]->vshort;
            vector->data_ment[i]=vector->data_ment[i+1];
            return true;
            break;
        case 8:
            vector->ptr[i]->vchar=vector->ptr[i+1]->vchar;
            vector->data_ment[i]=vector->data_ment[i+1];
            return true;
            break;
        default:
            return false;
            break;
        }
    }
    return true;
}

_Bool vect_del_back(struct vectors* buff){
    if(buff->count!=0){
        buff->count--;
        if(vect_shrink(buff)){
            return true;
        }
        else{
            return false;
        }
    }
    else
    {
        return false;
    }
    
}

_Bool vect_shrink(struct vectors* buff){
    if (buff->count!=0)
    {
        buff->ptr=realloc(buff->ptr,buff->count*sizeof(int));
        buff->data_ment=realloc(buff->ptr,buff->count*sizeof(char));
        if ((buff->ptr!=NULL)&&(buff->data_ment!=NULL))
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
        return true;
    }
}

/*###### Z ZZ Z ZZ Z ZABIL ##### # #*/

_Bool stdiput_OP(struct vectors* vector,int pos){
    char buf[MAX];
    int x;
    scanf("%d", &x);
    if(fgets(buf, MAX, stdin)!=NULL){
        char** bufer;
        switch (type_check(buf))
        {
        case 1:
            *vector->ptr[pos]->text=*buf;
            *vector->data_ment[pos]=(char)1;
            return true;
            break;
        case 2:
            vector->ptr[pos]->vd=strtod(buf,bufer);
            *vector->data_ment[pos]=(char)2;
            return true;
            break;
        case 3:
            unsigned long buff;
            buff =strtol(buf,bufer,0);
            *vector->data_ment[pos]=(char)3;
            vector->ptr[pos]->vunsiglong=buff;
            return true;    
            break;
        case 4:
            unsigned long buff1;
            buff1 =(unsigned int)strtol(buf,bufer,0);
            vector->ptr[pos]->vunsigint=buff1;
            *vector->data_ment[pos]=(char)4;
            return true;
            break;
        case 5:
            long int buff2;
            buff2 = atol(buf);
            vector->ptr[pos]->vlong=buff2;
            *vector->data_ment[pos]=(char)5;
            return true;
            break;
        case 6:
            int buff3;
            buff3 = atoi(buf);
            vector->ptr[pos]->vint=buff3;
            *vector->data_ment[pos]=(char)6;
            return true;
            break;
        case 7:
            int buff4;
            buff4 = (short)atoi(buf);
            vector->ptr[pos]->vshort=buff4;
            *vector->data_ment[pos]=(char)7;
            return true;
            break;
        case 8:
            vector->ptr[pos]->vchar=buf[0];
            *vector->data_ment[pos]=(char)8;
            return true;
            break;
        default:
            return false;
            break;
        }
        return false;
    }
    else
    {
        printf("Считывание ввода не произошло!");
        return false;
    }    
}

int type_check(char buf[MAX]){
    char sep[2] = {" "};
    char *istr;
    strchr(buf, '\n')[0]='\0';
    buf=strtok(buf,sep);
    if (strlen(buf)==1){
        istr=strtok(NULL,sep);
        if(istr==NULL){
            return 8;
        }
        else{
            return 1;
        }
    }
    istr = strchr(buf, '.');
    if(istr!= NULL){
        istr=strtok(buf,sep);
        istr=strtok(NULL,sep);
        if(istr==NULL){
            char sepd[2] = {'.'};
            istr=strtok(buf,sepd);
            istr=strtok(NULL,sepd);
            istr=strtok(NULL,sepd);
            if (istr==NULL)
            {
                printf("2");
                return 2;
            }
            else{
                printf("1");
                return 1;
            }
        }
        else{
            return 1;
        }
    }
    //That mean we need to convert it to signed type
    istr = strchr(buf, '-');
    if(istr!=NULL){
        istr=strtok(buf,sep);
        istr=strtok(NULL,sep);
        if(istr==NULL){
            if (strlen(buf)<6)
            {
                int buff;
                buff = atoi(buf);
                if ((buff>=-32768) &&(buff<=32767))
                {
                    return 7;
                }
                else
                {
                    return 6;
                }
                
            }
            else if (strlen(buf)<11)
            {
                long int buff;
                buff = atol(buf);
                if ((buff>=-2147483648) &&(buff<=2147483647))
                {
                    return 6;
                }
                else
                {
                    return 5;
                }
            }
            else{
                return 5;
            }
        }
        else{
            return 1;
        }
    }
    //Else we need convert it to unsigned type 
    else{
        istr=strtok(buf,sep);
        istr=strtok(NULL,sep);
        if(istr==NULL){
            if (strlen(buf)<11)
            {
                unsigned long buff;
                char** bufer;
                buff =strtol(buf,bufer,0);
                if (buff <=4294967295)
                {
                    return 4;
                }
                else{
                    return 3;
                }
            }
            else{
                return 3;
            }
        }
        else{
            return 1;
        }
    }
}