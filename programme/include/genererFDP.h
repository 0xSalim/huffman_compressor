/**
 * \file genererFDP.h
 * \brief signature des fonction pour generer une file de priorite a partir de Statistiques
 *
 */

#ifndef  __genererFDP__
#define __genererFDP__

#include "arbreDeHuffman.h"
#include "FileDePriorite.h"
#include "Statistiques.h"
#include "Octet.h"
#include "arbre_allocation_dynamique.h"
#include "bit_allocation_dynamique.h"
/**
* \fn genererFileDePriorite(S_Statistiques )
* \brief fonction qui genere une file de priorite
* \return FDP_FileDePriorite
*/
FDP_FileDePriorite genererFileDePriorite(S_Statistiques,int );

#endif
