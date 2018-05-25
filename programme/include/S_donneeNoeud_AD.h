/**
 * \file S_donneeNoeud_AD.h
 * \brief Definition des types des operations de copie, d'allocation et de comparaison de Statistiques
 *
 */

#ifndef __S_donneeNoeud_AD__
#define __S_donneeNoeud_AD__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Octet.h"
#include "Statistiques.h"

/**
* \fn SDNAD_copierDonneeNoeud(void*)
* \brief fonction de copie de donnee d'un noeud de statistiques dynamiquement
* \return void*
*/
void* SDNAD_copierDonneeNoeud(void*);
/**
* \fn SDNAD_desallouerDonneeNoeud(void*)
* \brief fonction qui desalloue des donnees d'un noeud de statistiques dynamiquement
* \return void
*/
void SDNAD_desallouerDonneeNoeud(void*);
/**
* \fn SDNAD_comparerDonneeNoeud(void*,void*)
* \brief fonction qui compare des donnees d'un noeud de statistiques
* \return int
*/
int SDNAD_comparerDonneeNoeud(void*,void*);

#endif
