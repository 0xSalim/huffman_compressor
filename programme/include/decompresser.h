/**
 * \file decompresser.h
 * \brief signature de la fonction pour decompresser un fichier compresse
 *
 */

#ifndef __DECOMPRESSER__
#define __DECOMPRESSER__

#include <stdlib.h>
#include "arbre_allocation_dynamique.h"
#include "arbreDeHuffman.h"
#include "bit.h"
#include "bit_allocation_dynamique.h"
#include "recupererEnTete.h"
#include "genererFDP.h"
#include "GenererADH.h"
#include "FileDePriorite.h"
#include "fichierBinaire.h"
#include "Statistiques.h"
#include "decoder.h"
#include "copieLiberationComparaison.h"

/*Partie Public*/
/**
* \fn decompresser(FichierBinaire fichierCompresse, FichierBinaire* fichierDecompresse)
* \brief Fonction qui decompresse un fichier compresser
* \return void
*/
void decompresser(FichierBinaire fichierCompresse, FichierBinaire* fichierDecompresse);
/// Necessite un "fichierComrpesse" ouvert en mode lecture et un "fichierDecompresse" ouvert en mode ecriture
/// Mise a 0 des curseurs dans la fonction

#endif
