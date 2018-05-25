/**
 * \file ecrireEnTetePrivee.h
 * \brief signature des fonction privee utile pour ecrire l'entete d'un fichier compresse
 *
 */

#ifndef __ECRIRE_ENTETE_PRIVEE__
#define __ECRIRE_ENTETE_PRIVEE__
#include "ecrireEnTetePublic.h"
/*Partie Public*/
/**
  *\fn ecrireTaille(FichierBinaire*, int)
  * \brief Fonction qui permet d'erire la taille d'un fichier dans un autre fichier
  * \return void
  */
void ecrireTaille(FichierBinaire*, int);
/**
  *\fn ecrireStatistiques(FichierBinaire*,S_Statistiques*)
  * \brief Fonction qui permet d'erire des Statistiques dans un fichier
  * \return void
  */
void ecrireStatistiques(FichierBinaire*,S_Statistiques*);
/**
  *\fn ecrireCodeIdentification(FichierBinaire*)
  * \brief Fonction qui permet d'erire un octet dans un fichier
  * \return void
  */
void ecrireCodeIdentification(FichierBinaire*);

#endif
