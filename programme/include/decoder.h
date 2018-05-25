/**
 * \file decoder.h
 * \brief signature des fonction pour decoder un code binaire afin de le decompresser
 *
 */

#ifndef __decoder__
#define __decoder__

#include <stdlib.h>
#include <assert.h>
#include "CodeBinaire.h"
#include "Octet.h"
#include "bit.h"
#include "arbreDeHuffman.h"
#include "copieLiberationComparaison.h"
#include "fichierBinaire.h"
/*Partie Public*/
/**
  *\fn decoder(ADH_arbreDeHuffman ,FichierBinaire source,FichierBinaire* dest,int , CLC_FonctionCopier ,CLC_FonctionLiberer)
  * \brief Fonction qui permet de decoder un fichier compresser
  * \return void
  */
void decoder(ADH_arbreDeHuffman ,FichierBinaire source,FichierBinaire* dest,int , CLC_FonctionCopier ,CLC_FonctionLiberer);
/// Necessite un fichier Binaire compressé "source" ouvert en mode lecture, après l'en tête, et un fichier Binaire "dest" ouvert en mode écriture.
/**
  *\fn traiterCodeBinaire(CodeBinaire* ,octet* ,int* ,ADH_arbreDeHuffman ,CLC_FonctionLiberer )
  * \brief Fonction qui permet de decoder le code binaire à l'interieur du fichier
  * \return void
  */
void traiterCodeBinaire(CodeBinaire* ,octet* ,unsigned long long* ,ADH_arbreDeHuffman ,CLC_FonctionLiberer );
/**
  *\fn octet_en_CB(octet ,CLC_FonctionCopier )
  * \brief Fonction qui permet de transformer un octet en code binaire
  * \return CodeBinaire
  */
CodeBinaire octet_en_CB(octet ,CLC_FonctionCopier );

#endif // decoder
