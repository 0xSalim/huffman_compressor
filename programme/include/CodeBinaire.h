/**
 * \file CodeBinaire.h
 * \brief signature des fonctions du TAD codeBinaire
 *
 */
 
#ifndef __CODE_BINAIRE__
#define __CODE_BINAIRE__
#include <errno.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "bit.h"
#include "bit_allocation_dynamique.h"
#include "ListeChainee.h"
/**
 * \typedef    Création de la structure CodeBinaire
 * \details   fait à partir de ListeChainée 
 */
/* Partie privée */
typedef LC_ListeChainee CodeBinaire;

/**
 * \def CB_ERREUR_MEMOIRE
 * \brief valeur que prend errno lorsqu'il n'y a plus de mémoire système
 * 
 * \return listeChainee
 */
#define CB_ERREUR_MEMOIRE 1


/* Partie publique */

/**
 * \fn CB_creerCodeBinaireVide()
 * \brief Créé un CodeBinaire vide
 * \return CodeBinaire
 */

CodeBinaire CB_creerCodeBinaireVide() ;



/**
 * \fn CB_estVide(CodeBinaire)
 * \brief Permet de savoir si un CodeBinaire est vide ou pas
 * \return int
 */
int CB_estVide(CodeBinaire );

/**
 * \fn CB_obtenirBit(CodeBinaire c)
 * \brief obtient le bit d un code binaire
 * \return bit
 */
bit CB_obtenirBit(CodeBinaire c);

/**
 * \fn CB_obtenirIemeBitCodeBinaire(CodeBinaire, unsigned int)
 * \brief obtient le bit d un code binaire a une certaine position
 * \return bit
 */
bit CB_obtenirIemeBitCodeBinaire(CodeBinaire, unsigned int);

/**
 * \fn CB_obtenirLongueur(CodeBinaire)
 * \brief Retourne le nombre de Bit du CodeBinaire
 * \return int
 */
int CB_obtenirLongueur(CodeBinaire);

/**
 * \fn CB_obtenirCodeBinaireSuivant(CodeBinaire)
 * \brief Retourne le CodeBinaire suivant (non estVide)
 * \return CodeBinaire
 */
CodeBinaire CB_obtenirCodeBinaireSuivant(CodeBinaire) ;

/**
 * \fn CB_fixerCodeBinaireSuivant(CodeBinaire*,CodeBinaire)
 * \brief Fixe le CodeBinaire suivant (non estVide)
 * \return CodeBinaire
 */
void CB_fixerCodeBinaireSuivant(CodeBinaire*,CodeBinaire);

/**
 * \fn CB_supprimerTete(CodeBinaire*,CLC_FonctionLiberer)
 * \brief Supprime le Bit de tête (non estVide)
 */
void CB_supprimerTete(CodeBinaire*,CLC_FonctionLiberer);

/**
 * \fn CB_supprimerBit(CodeBinaire*, unsigned int,CLC_FonctionLiberer)
 * \brief Supprime le ieme Bit du CodeBinaire
 */
void CB_supprimerBit(CodeBinaire*, unsigned int,CLC_FonctionLiberer);

/**
 * \fn CB_supprimer(CodeBinaire*,CLC_FonctionLiberer)
 * \brief Supprime le CodeBinaire
 */
void CB_supprimer(CodeBinaire*,CLC_FonctionLiberer);

/**
 * \fn CB_ajouterEnTete(CodeBinaire*, bit,CLC_FonctionCopier)
 * \brief Ajoute un Bit en tête du CodeBinaire
 */
void CB_ajouterEnTete(CodeBinaire*, bit,CLC_FonctionCopier);

/**
 * \fn CB_ajouterBit(CodeBinaire*,unsigned int, bit,CLC_FonctionCopier)
 * \brief Ajoute un Bit au CodeBinaire
 */
void CB_ajouterBit(CodeBinaire*,unsigned int, bit,CLC_FonctionCopier);

/**
 * \fn CB_ajouterAlaFin(CodeBinaire*, bit,CLC_FonctionCopier)
 * \brief Ajoute un Bit à la fin du CodeBinaire
 */
void CB_ajouterAlaFin(CodeBinaire*, bit,CLC_FonctionCopier);

/**
 * \fn CB_sontEgaux(CodeBinaire, CodeBinaire,CLC_FonctionComparer)
 * \brief Vérifie l'égalité entre deux CodeBinaire
 * \return int
 */
int CB_sontEgaux(CodeBinaire, CodeBinaire,CLC_FonctionComparer);

/**
 * \fn CB_concatener(CodeBinaire*,CodeBinaire)
 * \brief Concatene deux codes binaires
 * \return CodeBinaire
 */
void CB_concatener(CodeBinaire*,CodeBinaire);

/**
 * \fn  CB_copierCodeBinaire(CodeBinaire,CLC_FonctionCopier)
 * \brief Permet de copier un codeBinaire
 * \return CodeBinaire
 */
CodeBinaire CB_copierCodeBinaire(CodeBinaire,CLC_FonctionCopier);

/**
 * \fn  CB_convertirCodeBinaireEnBaseDix(CodeBinaire mon_code_bianire)
 * \brief convertçr le code binaire en base 10
 * \return int
 */
int CB_convertirCodeBinaireEnBaseDix(CodeBinaire mon_code_bianire);

#endif // CODEBINAIRE_H_INCLUDED
