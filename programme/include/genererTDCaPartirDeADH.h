/**
 * \file genererTDCaPartirDeADH.h
 * \brief signature des fonction pour generer une table de codage a partir d'un arbre de huffman
 *
 */

#ifndef  __genererTDCAPartirDeADH__
#define __genererTDCAPartirDeADH__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "copieLiberationComparaison.h"
#include "bit.h"
#include "Octet.h"
#include "CodeBinaire.h"
#include "TableDeCodage.h"
#include "ListeChainee.h"
#include "FileDePriorite.h"
#include "arbreDeHuffman.h"
#include "arbre_allocation_dynamique.h"
/**
* \fn genererTDCaPartirDeADH(ADH_arbreDeHuffman)
* \brief fonction qui genere une table de codage a partir d'un arbre
* \return TableDeCodage
*/
TableDeCodage genererTDCaPartirDeADH(ADH_arbreDeHuffman);
/**
* \fn chercherFeuilleRecursivement(ADH_arbreDeHuffman , TableDeCodage*, CodeBinaire*,CLC_FonctionCopier)
* \brief fonction qui les feuille d'un arbre recursivement
* \return void
*/
void chercherFeuilleRecursivement(ADH_arbreDeHuffman , TableDeCodage*, CodeBinaire*,CLC_FonctionCopier);

#endif
