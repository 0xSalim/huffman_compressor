/**
 * \file Statistiques.h
 * \brief signature des fonctions du TAD Statistiques
 *
 */

#ifndef __Stats__
#define __Stats__
#include "ListeChainee.h"
#include "Octet.h"
#include "copieLiberationComparaison.h"
#include <assert.h>


/*Partie privee */
/**
 * \typedef Création de la structure S_donneeNoeud
 */
/**
 * \typedef Création du TAD S_Statistiques
 */
typedef struct /**< struct S_Statistiques*/
{
	int taille;  /*!< entier correspondant au nombre d'octets */
	LC_ListeChainee lesStats; /*!< Liste Chainee representant les stats */
}
S_Statistiques;


typedef struct{/**< struct S_donneeNoeud*/
		octet loctet;/*!< octet */
		int ponderation;/*!< entier correspondant au nombre d'occurences de l'octet concerné */
				}
S_donneeNoeud;

/// Partie Privée



/**
 * \fn S_creerDonneeNoeud(octet,int)
 * \brief Fonction qui permet de creer des donnees vides.
 * \return S_donneeNoeud
 */
S_donneeNoeud S_creerDonneeNoeud(octet,int);

/**
 * \fn S_obtenirTaille(S_Statistiques)
 * \brief Fonction qui obtient la taille d'une statistiques
 * \return int
 */
int S_obtenirTaille(S_Statistiques);

/**
 * \fn S_obtenirLesStats(S_Statistiques)
 * \brief Fonction qui obtient les statistiques
 * \return LC_ListeChainee
 */
LC_ListeChainee S_obtenirLesStats(S_Statistiques);

/**
 * \fn S_ajouterDonneeNoeud(S_Statistiques*,S_donneeNoeud,CLC_FonctionCopier)
 * \brief Fonction qui permet d'ajouter un octet au donnees
 * \return S_Statistiques
 */
void S_ajouterDonneeNoeud(S_Statistiques*,S_donneeNoeud,CLC_FonctionCopier);

/**
 * \fn S_obtenirDonneeNoeud(S_Statistiques)
 * \brief Fonction qui permet d'obtenir les donnee du noeud
 * \return S_donneeNoeud
 */
S_donneeNoeud S_obtenirDonneeNoeud(S_Statistiques);

/**
 * \fn S_fixerLesStats(S_Statistiques*,LC_ListeChainee)
 * \brief Fonction qui permet de modifier les statistiques
 * \return S_Statistiques
 */
void S_fixerLesStats(S_Statistiques*,LC_ListeChainee);

/**
 * \fn SDN_obtenirOctet(S_donneeNoeud)
 * \brief Fonction qui permet de modifier les statistiques
 * \return octet
 */
octet SDN_obtenirOctet(S_donneeNoeud);

/**
 * \fn S_obtenirPonderation(S_donneeNoeud)
 * \brief Fonction qui permet d'obtenir le nombre de ponderation d'un octet
 * \return int
 */
int S_obtenirPonderation(S_donneeNoeud);

/// Partie Publique


/**
 * \fn S_creerVide()
 * \brief Fonction qui permet des des statistiques vides
 * \return S_Statistiques
 */
S_Statistiques S_creerVide();

/**
 * \fn S_estVide(S_Statistiques)
 * \brief Fonction qui permet de vérifier si des statistiques sont vides
 * \return Booleen
 */
int S_estVide(S_Statistiques);


/**
 * \fn S_obtenirOctet(S_Statistiques);
 * \brief Fonction qui permet d'obtenir un certain octet
 * \return octet
 */
octet S_obtenirOctet(S_Statistiques);


/**
 * \fn S_nombreOccurencesItem(S_Statistiques,octet,CLC_FonctionComparer)
 * \brief Fonction qui retourne le nombre d'occurences de l'octet (à partir des statistiques).
 * \return int
 */
int S_nombreOccurencesItem(S_Statistiques,octet,CLC_FonctionComparer); // L'item doit être présent

/**
 * \fn S_fixerOccurencesItem(S_Statistiques,octet,int,CLC_FonctionCopier, CLC_FonctionLiberer,CLC_FonctionComparer)
 * \brief Fonction qui fixe le nombre d'Occurences d une statistiques
 * \return int
 */
void S_fixerOccurencesItem(S_Statistiques,octet,int,CLC_FonctionCopier, CLC_FonctionLiberer,CLC_FonctionComparer); // L'item doit être présent

/**
 * \fn S_supprimerTete(S_Statistiques*,CLC_FonctionLiberer)
 * \brief supprime l item etant en tête d une statistique
 * \return S_Statistiques
 */
void S_supprimerTete(S_Statistiques*,CLC_FonctionLiberer); // Précondition incluse dans LC_supprimerTete


/**
 * \fn S_ajouterItem(S_Statistiques*,octet,int,CLC_FonctionCopier,CLC_FonctionComparer)
 * \brief ajoute un item a une statistique
 * \return S_Statistiques
 */
void S_ajouterItem(S_Statistiques*,octet,int,CLC_FonctionCopier,CLC_FonctionComparer); // L'item ne doit pas être présent

void S_ajouterItemALafin(S_Statistiques*,octet,int,CLC_FonctionCopier,CLC_FonctionComparer);

/**
 * \fn S_estPresent(S_Statistiques,octet,CLC_FonctionComparer)
 * \brief Fonction qui permet de vérifier si unoctet  est présent dans les statistiques.
 * \return Booleen
 */
int S_estPresent(S_Statistiques,octet,CLC_FonctionComparer);
/**
 * \fn S_obtenirStatSuivante(S_Statistiques*)
 * \brief Fonction qui permet d'obtenir la statistiques suivantes
 * \return S_Statistiques
 */
void S_obtenirStatSuivante(S_Statistiques*);

/**
 * \fn S_supprimer(S_Statistiques*,CLC_FonctionLiberer libererDonneeNoeud)
 * \brief Fonction qui permet de supprimer une statistiques
 * \return S_Statistiques
 */
void S_supprimer(S_Statistiques*,CLC_FonctionLiberer libererDonneeNoeud);

#endif
