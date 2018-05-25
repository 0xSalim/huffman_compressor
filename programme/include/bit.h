/**
 * \file bit.h
 * \brief definition de bit et signature des fonctions pour bit
 *
 */
#ifndef __BIT__
#define __BIT__

#include <stdio.h>
#include <assert.h>
#include "bit_allocation_dynamique.h"
/**
 * \typedef enum Création de la structure bit
 */
/* Partie privée */
typedef enum {b1 , b0} bit;
/*Partie Public*/
/**
  * \fn bit_egaux(bit b,bit c)
  * \brief Fonction qui compare si deux bit sont égaux
  * \return int
  */
int bit_egaux(bit b,bit c);
/**
  * \fn bit_en_int(bit)
  * \brief Fonction qui permet de transformer un bit en un entier
  * \return int
  */
int bit_en_int(bit);
/**
  * \fn int_en_bit(int)
  * \brief Fonction qui permet de transformer un entier en un bit
  * \return bit
  */
bit int_en_bit(int);

bit copierBit(bit);

#endif
