/**
 * \file GenererADH.h
 * \brief signature des fonction pour generer un arbre de huffman a partir d'un file de priorite
 *
 */

#ifndef  __genererADH__
#define __genererADH__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bit.h"
#include "Octet.h"
#include "CodeBinaire.h"
#include "TableDeCodage.h"
#include "ListeChainee.h"
#include "FileDePriorite.h"
#include "arbreDeHuffman.h"
#include "arbre_allocation_dynamique.h"

/**
* \fn genererArbreDeHuffman(FDP_FileDePriorite *file,CLC_FonctionCopier)
* \brief fonction qui appele genererArbreRecursivement
* \return ADH_arbreDeHuffman
*/
ADH_arbreDeHuffman genererArbreDeHuffman(FDP_FileDePriorite *file,CLC_FonctionCopier);

/**
* \fn genererArbreRecursivement(FDP_FileDePriorite *file,CLC_FonctionCopier)
* \brief fonction qui genere un arbre recursivement
* \return void
*/
void genererArbreRecursivement(FDP_FileDePriorite *file,CLC_FonctionCopier);

#endif
