#include "operations.c"
#include "visual.h"

int main(){
    struct vectors vector;
    printf("step1\n");
    if (vect_first_init(&vector))
    {
        printf("step2\n");
        _Bool alive =true;
        while (alive)
        {
            alive=visual_disp(&vector);
        }
    }
    else
    {
        printf("Ну допустим что-то пошло не так, хз даже.\n");
    }   
}