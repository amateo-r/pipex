#include "../include/libpipex.h"

int main(void)
{
    int i;

    i = 0;
    printf("Hola buenos días\n");
    fork();
    printf("La cosa es que esto debería de salir dos veces, %d\n", i);
    i++;
    return (0);
}