/**
 * \file entier_allocation_dynamique.h
 * \brief Definition des types des operations de copie, d'allocation et de comparaison d'entiers
 *
 */

#ifndef __ENTIER_ALLOCATION_DYNAMIQUE__
#define __ENTIER_ALLOCATION_DYNAMIQUE__

/*Partie Public*/
/**
  *\fn EAD_copierEntier(void*)
  * \brief Fonction qui permet de copier dynamiquement un entier
  * \return void*
  */
void* EAD_copierEntier(void*);
/**
  *\fn EAD_desallouerEntier(void*)
  * \brief Fonction qui permet de desallouer dynamiquement un entier
  * \return void
  */
void EAD_desallouerEntier(void*);
/**
  *\fn EAD_comparerEntier(void*,void*)
  * \brief Fonction qui permet de comparer deux entier
  * \return int
  */
int EAD_comparerEntier(void*,void*);

#endif
