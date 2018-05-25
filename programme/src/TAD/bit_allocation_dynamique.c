#include "bit_allocation_dynamique.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bit.h"



void* BAD_copierBit(void* b) {
  bit* resultat = (bit*)malloc(sizeof(bit));
  memcpy((void*)resultat, b, sizeof(bit));
  return (void*) resultat;
}


void BAD_desallouerBit(void* b) {
  free(b);
}


int BAD_comparerBit(void* b1,void* b2) {
  return (*(bit*)b1 == *(bit*)b2);
}
