/**
 * \file fichierBinaire.h
 * \brief signature des fonctions du TAD FichierBinaire
 *
 */

#ifndef __FICHIER_BINAIRE__
#define __FICHIER_BINAIRE__

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "Octet.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

#include "bit.h"

/**
 * \def FB_ERREUR_OUVERTURE
 * \brief valeur que prend errno
 * 
 * \return FichierBinaire
 */
#define FB_ERREUR_OUVERTURE 1

/**
 * \typedef    Création de la structure FichierBinaire
 * \details   fait à partir de ListeChainée 
 */
/* Partie publique */
typedef FILE* FichierBinaire;

/**
 * \enum FBmode
 * \details   détermine la lecture ou l'écriture 
 */
typedef enum {ecriture, lecture} FBmode;

/**
 * \fn FB_fichierBinaire(char*)
 * \brief creer un fichierBinaire a partir d une chaine de caractere
 * \return FichierBinaire
 */
FichierBinaire FB_fichierBinaire(char*);


/**
 * \fn FB_ouvrir(char*, FBmode)
 * \brief Ouvre le fichier passé en paramètre et retourne le pointeur FichierBinaire associé
 * \return FichierBinaire
 */
FichierBinaire FB_ouvrir(char*, FBmode);

/**
 * \fn FB_fermer(FichierBinaire*)
 * \brief Ferme le FichierBinaire
 */
void FB_fermer(FichierBinaire*);

/**
 * \fn FB_finFichier(FichierBinaire)
 * \brief Retourne 1 si le pointeur FichierBinaire se situe à la fin du fichier
 * \return int
 */
int FB_finFichier(FichierBinaire);

/**
 * \fn FB_ecrireOctet(FichierBinaire*, octet )
 * \brief Ecrit un Octet dans le fichier
 */
void FB_ecrireOctet(FichierBinaire*, octet);

/**
 * \fn FB_lireOctet(FichierBinaire, octet*)
 * \brief Lit un Octet à partir du fichier et le retourne. (!) Vérifier la sortie de la fonction pour savoir si l'octet a réellement une valeur
 * \return int
 */
int FB_lireOctet(FichierBinaire, octet*);


/**
 * \fn FB_ecrireNaturel(FichierBinaire*, int)
 * \brief Ecrit un Naturel dans le fichier
 */
void FB_ecrireNaturel(FichierBinaire*, int);

/**
 * \fn FB_lireNaturel(FichierBinaire, int*)
 * \brief Lit un Naturel à partir du fichier et le retourne. (!) Vérifier la sortie de la fonction pour savoir si le naturel a réellement une valeur
 * \return int
 */
int FB_lireNaturel(FichierBinaire, int*);

/**
 * \fn FB_ecrireGrosNaturel(FichierBinaire*,unsigned long long)
 * \brief ecris un naturel
 * \return FichierBinaire
 */
void FB_ecrireGrosNaturel(FichierBinaire*,unsigned long long);

/**
 * \fn FB_lireGrosNaturel(FichierBinaire,unsigned long long*)
 * \brief lis un naturel
 * \return int
 */
int FB_lireGrosNaturel(FichierBinaire, unsigned long long*);

/**
 * \fn FB_ecrireCaractere(FichierBinaire*, char)
 * \brief Ecrit un Caractere dans le fichier
 */
void FB_ecrireCaractere(FichierBinaire*, char);


/**
 * \fn FB_lireCaractere(FichierBinaire, char*)
 * \brief Lit un Caractere à partir du fichier et le retourne. (!) Vérifier la sortie de la fonction pour savoir si le caractère a réellement une valeur
 * \return int
 */
int FB_lireCaractere(FichierBinaire, char*);

/**
 * \fn FB_longueurFichier(FichierBinaire)
 * \brief Retourne la longueur du fichier
 * \return int
 */
int FB_longueurFichier(FichierBinaire);

/**
 * \fn FB_ecrireChaine(FichierBinaire*, char*)
 * \brief Ecrit une ChaineDeCaractères dans le fichier
 * 
 */
void FB_ecrireChaine(FichierBinaire*, char*);

/**
 * \fn FB_lireChaine(FichierBinaire, int)
 * \brief Lit une ChaineDeCaractères de taille n dans le fichier.
 * (!) Retourne une chaine de taille n+1 (caractère \0 de fin). (!!) Penser à désallouer l'espace mémoire retourné !
 * \return char*
 */
char* FB_lireChaine(FichierBinaire, int);


/**
 * \fn FB_deplacerCurseur(FichierBinaire*, long)
 * \brief Déplace le curseur du FichierBinaire à la position donnée à partir du début (en nombre d'Octets)
 */
void FB_deplacerCurseur(FichierBinaire*, long);

/**
 * \fn FB_deplacerCurseurPourTrouverTaille(FichierBinaire* f)
 * \brief Déplace le curseur du FichierBinaire jusqu'a la fin du fichier pour obtenir sa taille
 */
void FB_deplacerCurseurPourTrouverTaille(FichierBinaire* f); /// Se déplace à la fin du fichier-8

#endif
