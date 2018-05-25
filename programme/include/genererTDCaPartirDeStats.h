/**
 * \file genererTDCaPartirDeStats.h
 * \brief signature des fonction pour generer une table de codage a partir de Statistiques
 *
 */

#ifndef __genererTDCaPartirDeStats__
#define __genererTDCaPartirDeStats__
#include <stdlib.h>
#include <assert.h>


#include "Statistiques.h"
#include "FileDePriorite.h"
#include "arbreDeHuffman.h"
#include "TableDeCodage.h"

#include "GenererADH.h"
#include "genererFDP.h"
#include "genererTDCaPartirDeADH.h"



#include "arbre_allocation_dynamique.h"

/**
* \fn genererTableDeCodageAPartirDeStats(S_Statistiques)
* \brief fonction qui genere une table de codage a partir de Statistiques
* \return TableDeCodage
*/
TableDeCodage genererTableDeCodageAPartirDeStats(S_Statistiques);


#endif
