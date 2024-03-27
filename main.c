#include "operations.c"

int main(){
    struct vectors vector;
    if (vect_first_init(&vector))
    {
        stdiput_OP(&vector);
    }
    else
    {
        printf("Ну допустим что-то пошло не так, хз даже.");
    }   
}