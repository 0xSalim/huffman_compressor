/**
 * \file estCompresse.h
 * \brief Definition de la fonction de test pour savoir si un fichier est compresse ou non
 *
 */

#ifndef __ESTCOMPRESSER__
#define __ESTCOMPRESSER__


#include "S_donneeNoeud_AD.h"
#include "recupererEnTete.h"
#include "ecrireEnTetePublic.h"
#include "fichierBinaire.h"
#include "copieLiberationComparaison.h"

/*Partie Public*/
/**
* \fn estCompres(FichierBinaire* ,CLC_FonctionCopier ,CLC_FonctionComparer)
* \brief fonction qui test si un fichier est compresse
* \return int
*/
int estCompres(FichierBinaire* ,CLC_FonctionCopier ,CLC_FonctionComparer);

#endif
