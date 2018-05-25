#include "entier_allocation_dynamique.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* EAD_copierEntier(void* e)
{
    int* res=(int*)malloc(sizeof(int));
    memcpy((void*)res,e,sizeof(int));
    return (void*)res;
}
void EAD_desallouerEntier(void* e)
{
    free(e);
}
int EAD_comparerEntier(void* e1,void* e2)
{
    return (*(int*)e1)==(*(int*)e2);
}
