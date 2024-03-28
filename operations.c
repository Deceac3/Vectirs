#include "updata_load.h"

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
        if(vect_size_up(buff)){
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
        return true;
    }
}

/*###### Z ZZ Z ZZ Z ZABIL ##### # #*/

_Bool stdiput_OP(struct vectors* vector){
    char buf[MAX];
    if(fgets(buf, MAX, stdin)!=NULL){
        char** bufer;
        switch (type_check(buf))
        {
        case 1:
            *vector->ptr->text=*buf;
            return true;
            break;
        case 2:
            vector->ptr->vd=strtod(buf,bufer);
            return true;
            break;
        case 3:
            unsigned long buff;
            buff =strtol(buf,bufer,0);
            vector->ptr->vunsiglong=buff;
            return true;
            break;
        case 4:
            unsigned long buff1;
            buff1 =(unsigned int)strtol(buf,bufer,0);
            vector->ptr->vunsigint=buff1;
            return true;
            break;
        case 5:
            long int buff2;
            buff2 = atol(buf);
            vector->ptr->vlong=buff2;
            return true;
            break;
        case 6:
            int buff3;
            buff3 = atoi(buf);
            vector->ptr->vint=buff3;
            return true;
            break;
        case 7:
            int buff4;
            buff4 = (short)atoi(buf);
            vector->ptr->vshort=buff4;
            return true;
            break;
        case 8:
            vector->ptr->vchar=buf[0];
            return true;
            break;
        default:
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