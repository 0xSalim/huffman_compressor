/**
 * \file ecrireCodeBinaire.h
 * \brief signature de la fonction ecrireCodeBinaire
 *
 */


#ifndef __ECRIRE_CODE_BINAIRE__
#define __ECRIRE_CODE_BINAIRE__


#include "TableDeCodage.h"
#include "fichierBinaire.h"
#include "CodeBinaire.h"
#include "Octet.h"
#include "bit_allocation_dynamique.h"

/*Partie Public*/
/**
  *\fn ecrireCodeBinaire(FichierBinaire* , FichierBinaire , TableDeCodage, unsigned long long*)
  * \brief Fonction qui permet d'erire un code binaire dans un fichier binaire
  * \return void
  */
void ecrireCodeBinaire(FichierBinaire* , FichierBinaire , TableDeCodage, unsigned long long*);


#endif
