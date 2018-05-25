/**
 * \file FileDePriorite.h
 * \brief signature des fonctions du TAD FileDePriorite
 *
 */

#ifndef __FILE_DE_PRIORITE__
#define __FILE_DE_PRIORITE__

/* ajouter les include */
#include "arbreDeHuffman.h"
#include "ListeChainee.h"
#include "arbre_allocation_dynamique.h"
#include "S_donneeNoeud_AD.h"
/**
 * \typedef    Création de la structure FDP_FileDePriorite
 * \details   fait à partir de ListeChainée 
 */
/* Partie privée */
typedef LC_ListeChainee FDP_FileDePriorite;
/**
* \fn FDP_creerVide()
* \brief fonction qui permet de cree une file de priorite vide
* \return FDP_FileDePriorite
*/
FDP_FileDePriorite FDP_creerVide();
/**
* \fn FDP_estVide(FDP_FileDePriorite)
* \brief fonction qui test si une file de priorite est vide ou non
* \return int
*/
int FDP_estVide(FDP_FileDePriorite);

/**
* \fn FDP_defiler(FDP_FileDePriorite*,CLC_FonctionLiberer)
* \brief fonction qui defile un element de la file de priorite
* \return void
*/
void FDP_defiler(FDP_FileDePriorite*,CLC_FonctionLiberer);
/**
* \fn FDP_supprimer(FDP_FileDePriorite*,CLC_FonctionLiberer)
* \brief fonction qui permet de supprimer un file de priorite
* \return ADH_arbreDeHuffman
*/
void FDP_supprimer(FDP_FileDePriorite*,CLC_FonctionLiberer);
/**
* \fn FDP_insererItem(ADH_arbreDeHuffman, FDP_FileDePriorite*,CLC_FonctionCopier)
* \brief fonction qui permet d'inserer un item dans la file de priorité
* \return ADH_arbreDeHuffman
*/
void FDP_insererItem(ADH_arbreDeHuffman, FDP_FileDePriorite*,CLC_FonctionCopier,int);
/**
* \fn FDP_obtenirTete(FDP_FileDePriorite)
* \brief fonction qui permet d'obtenir la tete de la file ici c'est un arbre
* \return ADH_arbreDeHuffman
*/
ADH_arbreDeHuffman FDP_obtenirTete(FDP_FileDePriorite);
/**
* \fn FDP_longueur(FDP_FileDePriorite)
* \brief fonction qui permet d'obtenir la longueur de la file
* \return int
*/
int FDP_longueur(FDP_FileDePriorite);

#endif
