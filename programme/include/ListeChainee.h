/**
 * \file ListeChainee.h
 * \brief Signatures des operations du TAD Liste Chainee générique
 * \author L. Tschora
 * \version 1.1
 * \date 1/12/2016
 *
 */

#ifndef LISTECHAINEE_H_INCLUDED
#define LISTECHAINEE_H_INCLUDED

#include "entier_allocation_dynamique.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "copieLiberationComparaison.h"
#include "entier_allocation_dynamique.h"
/*Partie privee */
/**
 * \typedef Création de la structure LC_Noeud
 */
/**
 * \typedef Création du TAD LC_ListeChainee
 */

typedef struct LC_Noeud* LC_ListeChainee; /**< struct LC_ListeChainee*/
typedef struct LC_Noeud/**< struct LC_Noeud*/{
    void* lElement; /*!< Element contenu dans la liste  */
    LC_ListeChainee listeSuivante; /*!< liste Suivante  */
} LC_Noeud;


/* Partie publique */

/**
 * \def LC_ERREUR_MEMOIRE
 * \brief valeur que prend errno lorsqu'il n'y a plus de mémoire système
 * 
 * \return listeChainee
 */

#define LC_ERREUR_MEMOIRE 1

/**
 * \fn LC_ListeChaineeVide();
 * \brief Fonction qui crée une liste chaînée vide
 * \return LC_ListeChainee
 */
LC_ListeChainee LC_ListeChaineeVide();


/**
 * \fn int LC_estVide(LC_ListeChainee l);
 * \brief Fonction qui permet de savoir si une liste est vide
 * \param l LC_listeChainee
 * \return int
 */
int LC_estVide(LC_ListeChainee);

/**
 * \fn LC_ajouter(LC_ListeChainee* ,void*, CLC_FonctionCopier)
 * \brief Fonction qui permet d'ajouter un element en tête de liste. S'il n'y a plus assez
 * de mémoire système, errno prend LC_ERREUR_MEMOIRE
 * \return LC_ListeChainee
 */
void LC_ajouter(LC_ListeChainee*,void*,CLC_FonctionCopier);



/**
 * \fn LC_ajouterALaFin(LC_ListeChainee* ,void*, CLC_FonctionCopier)
 * \brief Fonction qui permet d'ajouter un element a la fin d une liste
 * de mémoire système, errno prend LC_ERREUR_MEMOIRE
 * \return LC_ListeChainee
 */
void LC_ajouterALaFin(LC_ListeChainee*,void*,CLC_FonctionCopier);

/**
 * \fn LC_obtenirElement(LC_ListeChainee pl)
 * \brief Fonction qui permet d'obtenir l'element en tête de liste
 * \param pl LC_listeChainee
 * \return element
 */

void* LC_obtenirElement(LC_ListeChainee);

/**
 * \fn LC_obtenirListeSuivante(LC_ListeChainee)
 * \brief Fonction qui retourne la liste qui suit la liste courante
 * 
 * \return LC_ListeSuivante
 */
LC_ListeChainee LC_obtenirListeSuivante(LC_ListeChainee);

/**
 * \fn LC_fixerListeSuivante(LC_ListeChainee*,LC_ListeChainee)
 * \brief Fonction qui permet de modifier la liste Suivante d'une listeChainee
 * 
 * \return LC_ListeSuivante
 */
void LC_fixerListeSuivante(LC_ListeChainee*,LC_ListeChainee);

/**
 * \fn LC_fixerElement(LC_ListeChainee,void*,CLC_FonctionCopier,CLC_FonctionLiberer)
 * \brief Fonction qui permet de remplacer l'element en tête de lsite
 * 
 * \return LC_ListeSuivante
 */
void LC_fixerElement(LC_ListeChainee,void*,CLC_FonctionCopier,CLC_FonctionLiberer);

/**
 * \fn LC_supprimerTete(LC_ListeChainee*, CLC_FonctionLiberer)
 * \brief Fonction qui permet de supprimer la tête de liste
 * 
 * \return LC_ListeSuivante
 */
void LC_supprimerTete(LC_ListeChainee*, CLC_FonctionLiberer);


/**
 * \fn LC_supprimer(LC_ListeChainee*,CLC_FonctionLiberer)
 * \brief Fonction qui permet de supprimer tous les éléments d'une liste chaînée
 * 
 * \return void
 */
void LC_supprimer(LC_ListeChainee*,CLC_FonctionLiberer);


/**
 * \fn LC_estPresent(LC_ListeChainee,void* ,CLC_FonctionComparer)
 * \brief Fonction de verifier si un item est present dans la liste
 * 
 * \return int
 */

int LC_estPresent(LC_ListeChainee,void* ,CLC_FonctionComparer);

/**
 * \fn LC_copier(LC_ListeChainee,CLC_FonctionCopier)
 * \brief Fonction qui permet de copier une liste chaînée, c'est-à-dire dupliquer tous les éléments
 * 
 * \return LC_ListeChainee
 */

LC_ListeChainee LC_copier(LC_ListeChainee,CLC_FonctionCopier);

        
/**
 * \fn LC_egales(LC_ListeChainee,LC_ListeChainee,CLC_FonctionComparer)
 * \brief Fonction qui indique si deux listeChainee sont egales.
 * 
 * \return Booleen
 */
int LC_egales(LC_ListeChainee,LC_ListeChainee,CLC_FonctionComparer);



#endif // LISTECHAINEE_H_INCLUDED
