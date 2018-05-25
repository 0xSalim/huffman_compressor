/**
 * \file copieLiberationComparaison.h
 * \brief Definition des types des operations de copie, d'allocation et de comparaison d'entiers
 * \author L. Tschora
 * \version 1.0
 * \date 1/12/2016
 *
 */

#ifndef COPIELIBERATIONCOMPARAISON_H_INCLUDED
#define COPIELIBERATIONCOMPARAISON_H_INCLUDED

/**
* \typedef creation du type fonction copier dynamiquement
*/
typedef /**< struct (*CLC_FonctionCopier) (void*)*/ void* (*CLC_FonctionCopier) (void*);
/**
* \typedef creation du type fonction liberer dynamiquement
*/
typedef /**< struct (*CLC_FonctionLiberer) (void*)*/ void (*CLC_FonctionLiberer) (void*);
/**
* \typedef creation du type fonction comparer dynamiquement
*/
typedef /**< struct (*CLC_FonctionComparer) (void*)*/ int (*CLC_FonctionComparer) (void*,void*);


#endif // COPIELIBERATIONCOMPARAISON_H_INCLUDED
