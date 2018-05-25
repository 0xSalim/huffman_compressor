/**
 * \file recupererEnTete.h
 * \brief signature des fonction pour recuperer l'entete d'un fichier compresse afin de le decompresser
 *
 */

#ifndef __RECUPERER_ENTETE__
#define __RECUPERER_ENTETE__
#include "fichierBinaire.h"
#include "Statistiques.h"
#include "Octet.h"
#include "S_donneeNoeud_AD.h"
/**
* \typedef creation du type enTete
*/
typedef struct enTete /**< struct enTete*/{
	S_Statistiques lesStats;/**< Statistique du fichier */
	octet codeId;/**< code d'identification d'un fichier compresser*/
} enTete;

/**
* \fn recupererEnTete(FichierBinaire,CLC_FonctionCopier copierDonneeNoeud,CLC_FonctionComparer comparerDonneeNoeud)
* \brief fonction qui recupere l'entete d'un fichier compresse
* \return enTete
*/
enTete recupererEnTete(FichierBinaire,CLC_FonctionCopier copierDonneeNoeud,CLC_FonctionComparer comparerDonneeNoeud); /// Nécessite un fichier binaire ouvert en mode écriture. Ne pas oublier de le refermer!

/**
* \fn recupererStatistiques(FichierBinaire,CLC_FonctionCopier copierDonneeNoeud,CLC_FonctionComparer comparerDonneeNoeud)
* \brief fonction qui recupere les statistiques d'un fichier compresse
* \return S_Statistiques
*/
S_Statistiques recupererStatistiques(FichierBinaire,CLC_FonctionCopier copierDonneeNoeud,CLC_FonctionComparer comparerDonneeNoeud);
/**
* \fn recupererLongueur(FichierBinaire)
* \brief fonction qui recupere la longueur dans un fichier compresse
* \return int
*/
int recupererLongueur(FichierBinaire);

/**
* \fn recupererCodeIdentification(FichierBinaire)
* \brief fonction qui recupere un octet d'un fichier compresse ici le code d'identification
* \return octet
*/
octet recupererCodeIdentification(FichierBinaire);
#endif
