/**
 * \file compresser.h
 * \brief signature des fonction pour compresser
 *
 */

#ifndef  __compresser__
#define __compresser__

#include "arbreDeHuffman.h"
#include "Statistiques.h"
#include "TableDeCodage.h"
#include "genererTDCaPartirDeStats.h"
#include "GenererADH.h"
#include "fichierBinaire.h"
#include "genererStats.h"
#include "bit_allocation_dynamique.h"
#include "ecrireEnTetePublic.h"
#include "ecrireCodeBinaire.h"

/*Partie Public*/
/**
  *\fn compresser(FichierBinaire ficSource, FichierBinaire* dest)
  * \brief Fonction qui compresse le fichier source donne en entree
  * \return void
  */
void compresser(FichierBinaire ficSource, FichierBinaire* dest);
/// Necessite un fichier binaire "ficSource" ouvert en mode lecture et un fihcierBinaire "dest" ouvert en mode écriture. Mise à 0 des curseurs dans la focntion.
/**
* \fn ecrireFichierAvecEnTete(FichierBinaire , FichierBinaire* , TableDeCodage , S_Statistiques)
* \brief Fonction qui permet d'ecrire l'entete du fichier
* \return void
*/
void ecrireFichierAvecEnTete(FichierBinaire , FichierBinaire* , TableDeCodage , S_Statistiques*);

#endif
