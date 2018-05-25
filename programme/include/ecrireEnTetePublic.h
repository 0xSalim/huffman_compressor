/**
 * \file ecrireEnTetePublic.h
 * \brief signature des fonction public pour ecrire l'entete d'un fichier compresser
 *
 */

#ifndef __ECRIRE_ENTETE_PUBLIC__
#define __ECRIRE_ENTETE_PUBLIC__
#include "fichierBinaire.h"
#include "Statistiques.h"
#include "ecrireEnTetePrivee.h"
#include "Octet.h"
#include "S_donneeNoeud_AD.h"

/*Partie Public*/
/**
  *\fn ecrireEnTete(FichierBinaire*, S_Statistiques*)
  * \brief Fonction qui permet d'erire l'entete afin d'obtenir les information necessaire lors de la decompression
  * \return void
  */
void ecrireEnTete(FichierBinaire*, S_Statistiques*); /// Nécessite un fichier binaire ouvert en mode lecture. Ne pas oublier de le refermer!
/**
  *\fn genererBonCode()
  * \brief Fonction qui permet de generer le code d'identification pour reconnaitre un fichoer compresse
  * \return octet
  */
octet genererBonCode();
#endif
