/**
 * \file TableDeCodage.h
 * \brief signature des fonctions du TAD TableDeCodage
 *
 */
 
#ifndef __TableDeCodage__
#define __TableDeCodage__


#include <math.h>
#include <assert.h>
#include "copieLiberationComparaison.h"
#include "CodeBinaire.h"
#include "Octet.h"
#include "bit.h"
#include "bit_allocation_dynamique.h"
/**
 * \def NB_OCT_MAX
 * \brief valeur maximal d'un octet en decimal
 * \return int
 */
#define NB_OCT_MAX 255

//510=2^1+2^2+2^3+2^4+2^5+2^6+2^7+2^8 soit tous les codes bianaires possibles (sauf le nul)

/*Partie privee */
/**
 * \typedef Création de la structure TableDeCodage
 */

typedef struct /**< struct TableDeCodage*/ {
	CodeBinaire CB_EnFonctionDeOctets[NB_OCT_MAX+1]; /*!< Tableau representant les codes binaires  */
}TableDeCodage;

/*
int convertirCBenAdresseOctet(CodeBinaire mon_code_bianire);
*/

/**
 * \fn TDC_tableDeCodageVide()
 * \brief Fonction qui permet de creer une table de codage vide
 * \return TableDeCodage
 */
TableDeCodage TDC_tableDeCodageVide();
/*
void ajouterElement(octet element, TableDeCodage *table);
* */

/**
 * \fn TDC_fixerCodeElement(octet element, CodeBinaire mon_code_binaire, TableDeCodage *table,CLC_FonctionCopier)
 * \brief Fonction qui permet de fixer la valeur du code avec un octet
 * \return CodeBinaire
 */
void TDC_fixerCodeElement(octet element, CodeBinaire mon_code_binaire, TableDeCodage *table,CLC_FonctionCopier);
/*
void supprimerElement(octet element, TableDeCodage *table);
* */
/*
int estPresentElement(TableDeCodage table, octet element);
* */
/*
int estPresentCodeBinaire(TableDeCodage table, CodeBinaire mon_code_binaire);
* */


/**
 * \fn TDC_obtenirCode(TableDeCodage table, octet element,CLC_FonctionCopier)
 * \brief Fonction qui permet de récuperer le code binaire corrrespondant à un octet(présent dans la table de codage).
 * \return CodeBinaire
 */
CodeBinaire TDC_obtenirCode(TableDeCodage table, octet element,CLC_FonctionCopier);



/**
 * \fn TDC_supprimer(TableDeCodage*,CLC_FonctionLiberer)
 * \brief Fonction qui permet de désallouer une table de codage
 * \return void
 */
void TDC_supprimer(TableDeCodage*,CLC_FonctionLiberer);
#endif
