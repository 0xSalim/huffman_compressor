/**
 * \file genererStats.h
 * \brief signature des fonction pour generer des statistiques a partir du fichier binaire
 *
 */

#ifndef __GENERER_STATS__
#define __GENERER_STATS__


#include "Statistiques.h"
#include "Octet.h"
#include "fichierBinaire.h"
#include "copieLiberationComparaison.h"
#include "S_donneeNoeud_AD.h"
/**
* \fn genererStats(FichierBinaire )
* \brief fonction qui genere des statistiques
* \return S_Statistiques
*/
S_Statistiques genererStats(FichierBinaire ); /// Necessite un fichier binaire ouvert en mode lecture. Mise à 0 du curseur dans la fonction.


#endif
