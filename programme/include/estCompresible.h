/**
 * \file estCompresible.h
 * \brief Definition de la fonction de test pour savoir si un fichier est compressible ou non
 *
 */

#ifndef __ESTCOMPRESSIBLE__
#define __ESTCOMPRESSIBLE__


#include "estCompresse.h"

/*Partie Public*/
/**
* \fn estCompressible(FichierBinaire* ,CLC_FonctionCopier ,CLC_FonctionComparer)
* \brief fonction qui test si le fichier binaire donnee est compressible
* \return int
*/
int estCompressible(FichierBinaire* ,CLC_FonctionCopier ,CLC_FonctionComparer);

#endif
