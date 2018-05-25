/**
 * \file arbreDeHuffman.h
 * \brief definition du type arbreDeHuffman et signature du TAD arbreDeHuffman
 *
 */

#ifndef __ARBRE_DE_HUFFMAN__
#define __ARBRE_DE_HUFFMAN__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Octet.h"
#include "copieLiberationComparaison.h"
#include "arbre_allocation_dynamique.h"
/*Partie Privee*/
/**
	* \typedef Creation de la structure pour la valeur de la racine
	*/
typedef struct ADH_valeurRacine /**< struct ADH_valeurRacine*/{
	int ponderation;/**< ponderation de l'octet*/
	octet valeurOctet;/**< valeur de l'octet de la racine*/
} ADH_valeurRacine;
/**
	* \typedef Creation du type abre de huffman
	*/
typedef struct/**< struct ADH_arbreDeHuffman*/ ADH_Racine* ADH_arbreDeHuffman;
/**
* \typedef Creation du type Racine
*/
typedef struct ADH_Racine /**< struct ADH_Racine*/{
    ADH_valeurRacine Racine;/**< valeur de la racine */
    ADH_arbreDeHuffman filsDroit;/**< fils droit*/
	ADH_arbreDeHuffman filsGauche;/**< fils gauche*/
} ADH_Racine;

/**
	* \fn ADH_creerArbreDeHuffmanVide()
	* \brief fonction qui permet de creer un arbre vide
	* \return ADH_arbreDeHuffman
	*/
ADH_arbreDeHuffman ADH_creerArbreDeHuffmanVide();

/**
* \fn ADH_creerArbreDeHuffman(octet octetAAjoute, int ponderation)
* \brief fonction qui creer un arbre de huffman
* \return ADH_Racine
*/
ADH_arbreDeHuffman ADH_creerArbreDeHuffman(octet octetAAjoute, int ponderation); 

/**
* \fn ADH_estUneFeuille(ADH_arbreDeHuffman)
* \brief fonction qui test si un arbre est feuille
* \return int
*/
int ADH_estUneFeuille(ADH_arbreDeHuffman);

/**
* \fn ADH_obtenirPere(ADH_arbreDeHuffman)
* \brief fonction qui permet d'avoir la valeur de la racine d'un arbre
* \return ADH_valeurRacine
*/
ADH_valeurRacine ADH_obtenirPere(ADH_arbreDeHuffman);/* assertion : l'arbre n'est pas vide */

/**
* \fn ADH_obtenirFilsDroit(ADH_arbreDeHuffman)
* \brief fonction qui permet d'avoir le fils droit d'un arbre
* \return ADH_arbreDeHuffman
*/
ADH_arbreDeHuffman ADH_obtenirFilsDroit(ADH_arbreDeHuffman);/*assertion : l'arbre n'est pas une feuille*/

/**
* \fn ADH_obtenirFilsGauche(ADH_arbreDeHuffman)
* \brief fonction qui permet d'avoir le fils gauche d'un arbre
* \return ADH_arbreDeHuffman
*/
ADH_arbreDeHuffman ADH_obtenirFilsGauche(ADH_arbreDeHuffman);/*assertion : l'arbre n'est pas une feuille*/

/**
* \fn ADH_fusionnerArbreDeHuffman(ADH_arbreDeHuffman,ADH_arbreDeHuffman)
* \brief fonction qui permet de fusionner deux arbre
* \return ADH_Racine
*/
ADH_arbreDeHuffman ADH_fusionnerArbreDeHuffman(ADH_arbreDeHuffman,ADH_arbreDeHuffman);

/**
* \fn ADH_comparerArbreDeHuffman(ADH_arbreDeHuffman,ADH_arbreDeHuffman)
* \brief fonction qui compare deux arbre
* \return int
*/
int ADH_comparerArbreDeHuffman(ADH_arbreDeHuffman,ADH_arbreDeHuffman);

/**
* \fn ADH_estVide(ADH_arbreDeHuffman)
* \brief fonction qui test si un arbre est vide
* \return int
*/
int ADH_estVide(ADH_arbreDeHuffman);

/**
* \fn ADH_supprimerPere(ADH_arbreDeHuffman*, ADH_arbreDeHuffman*, ADH_arbreDeHuffman*)
* \brief supprime le pere d un arbre de huffman
* \return int
*/
void ADH_supprimerPere(ADH_arbreDeHuffman*, ADH_arbreDeHuffman*, ADH_arbreDeHuffman*);

/**
* \fn ADH_supprimerArbre(ADH_arbreDeHuffman*)
* \brief supprime un arbre de huffman
* \return int
*/
void ADH_supprimerArbre(ADH_arbreDeHuffman*);

int ADH_longueur(ADH_arbreDeHuffman);
int max(int a, int b);
#endif
