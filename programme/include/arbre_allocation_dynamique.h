/**
 * \file arbre_allocation_dynamique.h
 * \brief definition des types des operations de copie, d'allocation et de comparaison d'arbre de hufmann
 *
 */

#ifndef __ARBRE_ALLOCATION_DYNAMIQUE__
#define __ARBRE_ALLOCATION_DYNAMIQUE__

/* Partie Public*/
/**
 * \fn ADHAD_copierArbre(void*)
 * \brief fonction qui copie un arbre
 * \return void*
*/
void* ADHAD_copierArbre(void*);
/**
  * \fn ADHAD_desallouerArbre(void*)
  * \brief fonction qui desalloue un arbre
  * \return void *
*/
void ADHAD_desallouerArbre(void*);
/**
  * \fn ADHAD_comparerArbre(void*,void*)
  * \brief fonction qui compare deux arbre
  * \return int
*/
int ADHAD_comparerArbre(void*,void*);

#endif
