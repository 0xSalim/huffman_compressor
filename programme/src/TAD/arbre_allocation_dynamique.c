#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre_allocation_dynamique.h"
#include "arbreDeHuffman.h"

void* ADHAD_copierArbre(void* a) {
  ADH_arbreDeHuffman* resultat = (ADH_arbreDeHuffman*)malloc(sizeof(ADH_arbreDeHuffman));
  memcpy((void*)resultat, a, sizeof(ADH_arbreDeHuffman));
  return (void*) resultat;
}


void ADHAD_desallouerArbre(void* a) {
  free(a);
}


int ADHAD_comparerArbre(void* a1,void* a2) {
	return ADH_comparerArbreDeHuffman(*(ADH_arbreDeHuffman*)a1,*(ADH_arbreDeHuffman*)a2);
}
