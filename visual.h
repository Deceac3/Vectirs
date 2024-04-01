_Bool visual_disp(struct vectors*);
int IntPlayerChoose();
_Bool visual_disp(struct vectors*);
void menu_display();
void special_arrs_display(struct vectors*);
void item_display(struct vectors*,int);

int IntPlayerChoose(){
    char buf[80];
    int x;
    scanf("%d", &x);
    if (fgets(buf, sizeof buf, stdin)){return x;}
    else{
        return 0;
    }
};

_Bool visual_disp(struct vectors* vector){
    menu_display();
    int buff= IntPlayerChoose();
    switch (buff)
    {
    case 0:
        return false;
        break;
    case 1:                 //arr display
        special_arrs_display(vector);
        return true;
        break;
    case 2 :                //add the item back
        vect_back(vector);
        return true;
        break;
    case 3:                 //change the item
        int indx =IntPlayerChoose();
        if(stdiput_OP(vector,indx)){
            return true;
        }
        else{
            return false;
        }
        break;
    case 4:                 //Delete the past item
        if(vect_del_back(vector)){
            return true;
        }
        else{
            return false;
        }
        break;
    case 5:                 //delete the item with index
        int indxx = IntPlayerChoose();
        if(vect_del_item(vector,indxx)){
            return true;
        }
        else{
            return false;
        }
        break;
    case 6:                 //show item with index
        int ind= IntPlayerChoose();
        item_display(vector,ind);
        return true;
        break;
    default:
        printf("Вы не можете запрашивать функцию с данным номером %d\nПопробуйте снова",buff);
        return true;
        break;
    }
}

void menu_display(){
    system("clear");
    printf("Привет пользователь! Что мы будем делать сейчас?\n0)Выйти((((\n1)Вывести массив\n2)Добавить объект в конец массива\n3)Изменить эллемент по индексу \n4)Удалить последний эллемент\n5)Удалить эллемент по индексу\n6)Вывести эллемент по индексу: ");
}

void special_arrs_display(struct vectors* vector){
    for(int i = 0; i<vector->count;i++){
        item_display(vector,i);
    }
    sleep(4);
}

void item_display(struct vectors* vector,int i){
    switch (*vector->data_ment[i])
    {
    case 1:
        printf("%s\n",vector->ptr[i]->text);
        break;
    case 2:
        printf("%f",vector->ptr[i]->vd);
        break;
    case 3:
        printf("%lu", vector->ptr[i]->vunsiglong);
        break;
    case 4:
        printf("%u", vector->ptr[i]->vunsigint);
        break;
    case 5:
        printf("%ld", vector->ptr[i]->vlong);
        break;
    case 6:
        printf("%d", vector->ptr[i]->vint);
        break;
    case 7:
        printf("%hd", vector->ptr[i]->vshort);
        break;
    case 8:
        printf("%c", vector->ptr[i]->vchar);
        break;
    default:
        //такого не бывает, хотя............
        break;
    }
}