/**
 * \file bit_allocation_dynamique.h
 * \brief definition des types des operations de copie, d'allocation et de comparaison de bit
 *
 */

#ifndef __BIT_ALLOCATION_DYNAMIQUE__
#define __BIT_ALLOCATION_DYNAMIQUE__


/* Partie Public*/
/**
 * \fn BAD_copierBit(void*)
 * \brief fonction qui copie un bit
 * \return void*
*/
void* BAD_copierBit(void*);
/**
  * \fn BAD_desallouerBit(void*)
  * \brief fonction qui desalloue un bit
  * \return void *
*/
void BAD_desallouerBit(void*);
/**
  * \fn BAD_comparerBit(void*, void*)
  * \brief fonction qui compare deux bit
  * \return int
*/
int BAD_comparerBit(void*, void*);

#endif
