/**
 * \file Octet.h
 * \brief signature des fonctions du TAD Octet
 *
 */

#ifndef __octet__
#define __octet__

#include <math.h>
#include "bit.h"
#include <stdbool.h>
#include <assert.h>

#include <stdio.h>
#include <malloc.h>

/**
 * \def NB_MAX_BITS
 * \brief valeur maximal de bits dans un octet
 * \return int
 */
#define NB_MAX_BITS 8
/**
 * \typedef Création du TAD octet
 */
typedef struct octet /**< struct octet*/
{
	int lesBits[NB_MAX_BITS];/**< struct tableau de bits*/
}octet;

/* Partie publique */
/**
 * \fn OCT_creerOctet()
 * \brief Fonction qui permet de creer un octet avec tous les bits à 0
 * \return octet
 */
octet OCT_creerOctet();

/**
 * \fn OCT_obteniriemeBit(octet,int)
 * \brief Fonction qui retourne un bit compris entre la position 1 et 8
 * \return bit
 */
bit  OCT_obteniriemeBit(octet,int);

/**
 * \fn OCT_fixeriemeBit(octet*,int,bit)
 * \brief Fonction qui fixe un bit compris entre la position 1 et 8
 * \return octet
 */
void OCT_fixeriemeBit(octet*,int,bit);

/**
 * \fn OCT_octetEgaux(octet,octet)
 * \brief Fonction qui teste si deux octets sont égaux
 * \return Booleen
 */
int OCT_octetEgaux(octet,octet);

/**
 * \fn OCT_decimalEnOctet(int)
 * \brief Fonction d'adressage inverse pour la table de hashage
 * \return Octet
 */
octet OCT_decimalEnOctet(int);


/**
 * \fn OCT_octetEnDecimal(octet)
 * \brief Fonction d'adressage pour la table de hashage
 * \return int
 */
int OCT_octetEnDecimal (octet);

/**
 * \fn OCT_copierOctet(octet,octet*)
 * \brief Fonction qui copie un octet et le retourne
 * \return octet
 */
void OCT_copierOctet(octet,octet*);

/**
 * \fn OCT_desallouerOctet(octet*)
 * \brief Fonction qui desalloue un octet
 * \return octet
 */
void OCT_desallouerOctet(octet*);

#endif
