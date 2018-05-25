#include <stdio.h>
#include <CUnit/Basic.h>
#include "ListeChainee.h"
#include "Octet.h"
#include "Statistiques.h"
#include "bit_allocation_dynamique.h"
#include "S_donneeNoeud_AD.h"

#define TRUE 1
#define FALSE 0

int init_suite_success (void)
	{
	return 0;
	}

int clean_suite_success (void)
	{
	return 0;
	}



void test_S_Statisiques_estVide(void)
{
  S_Statistiques s= S_creerVide();
	CU_ASSERT_TRUE(S_estVide(s));
	S_supprimer(&s,SDNAD_desallouerDonneeNoeud);
}

void test_S_Statisiques_estVide_casNonVide(void)
{
 S_Statistiques s= S_creerVide();
	octet o = OCT_creerOctet();
	S_ajouterItem(&s,o,4,SDNAD_copierDonneeNoeud,SDNAD_comparerDonneeNoeud);
	CU_ASSERT_TRUE(!S_estVide(s));
	S_supprimer(&s,SDNAD_desallouerDonneeNoeud);
}

void test_S_Statistiques_taille(void)
{
	S_Statistiques s= S_creerVide();
	octet o = OCT_creerOctet();
	S_ajouterItem(&s,o,4,SDNAD_copierDonneeNoeud,SDNAD_comparerDonneeNoeud);
	CU_ASSERT_TRUE(S_obtenirTaille(s) ==1);
	S_supprimer(&s,SDNAD_desallouerDonneeNoeud);
}

void test_S_Statistiques_supprimerTete(void)
{
	S_Statistiques s= S_creerVide();
	octet o = OCT_creerOctet();
	S_ajouterItem(&s,o,4,SDNAD_copierDonneeNoeud,SDNAD_comparerDonneeNoeud);
	S_supprimerTete(&s,SDNAD_desallouerDonneeNoeud);
	CU_ASSERT_TRUE((S_estVide(s))&&(S_obtenirTaille(s) ==0));
	S_supprimer(&s,SDNAD_desallouerDonneeNoeud);
}

void test_S_Statistiques_nboccurencesItem(void)
{
	S_Statistiques s= S_creerVide();
	octet o = OCT_creerOctet();
	S_ajouterItem(&s,o,4,SDNAD_copierDonneeNoeud,SDNAD_comparerDonneeNoeud);
	S_fixerOccurencesItem(s,o,6,SDNAD_copierDonneeNoeud,SDNAD_desallouerDonneeNoeud,SDNAD_comparerDonneeNoeud);
	CU_ASSERT_TRUE(S_nombreOccurencesItem(s,o,SDNAD_comparerDonneeNoeud)==6);
	S_supprimer(&s,SDNAD_desallouerDonneeNoeud);
}

void test_S_obtenirOctet(){
	S_Statistiques s= S_creerVide();
	bit monBit;
	octet o= OCT_creerOctet();
	octet o1 = OCT_creerOctet();
	monBit = b1;
	OCT_fixeriemeBit(&o,2,monBit);
	S_ajouterItem(&s,o,4,SDNAD_copierDonneeNoeud,SDNAD_comparerDonneeNoeud);
	o1=S_obtenirOctet(s);
	CU_ASSERT_TRUE(OCT_octetEgaux(o1,o));
	S_supprimer(&s,SDNAD_desallouerDonneeNoeud);
}

void test_S_ajouterItem(){
	S_Statistiques s= S_creerVide();
	octet o = OCT_creerOctet();
	S_ajouterItem(&s,o,4,SDNAD_copierDonneeNoeud,SDNAD_comparerDonneeNoeud);
	CU_ASSERT_TRUE(S_obtenirTaille(s) ==1);
	S_supprimer(&s,SDNAD_desallouerDonneeNoeud);
}

void test_S_ajouterItem_ALaFin(){
	S_Statistiques s= S_creerVide();
	octet o = OCT_creerOctet();
	S_ajouterItem(&s,o,4,SDNAD_copierDonneeNoeud,SDNAD_comparerDonneeNoeud);
	S_ajouterItemALafin(&s,o,6,SDNAD_copierDonneeNoeud,SDNAD_comparerDonneeNoeud);
	CU_ASSERT_TRUE((S_obtenirTaille(s) ==2) && (S_obtenirPonderation(S_obtenirDonneeNoeud(s))==4));
	S_supprimer(&s,SDNAD_desallouerDonneeNoeud);
}

void test_S_estPresent(){
	S_Statistiques s= S_creerVide();
	octet o = OCT_creerOctet();
	S_ajouterItem(&s,o,4,SDNAD_copierDonneeNoeud,SDNAD_comparerDonneeNoeud);
	CU_ASSERT_TRUE(S_estPresent(s,o,SDNAD_comparerDonneeNoeud));
	S_supprimer(&s,SDNAD_desallouerDonneeNoeud);
}

void test_S_ObtenirStatSuivante(){
	S_Statistiques s= S_creerVide();
	octet o1,o2 = OCT_creerOctet();
	int ponderation;
	bit monBit;
	monBit = b1;
	OCT_fixeriemeBit(&o2,2,monBit);
	OCT_fixeriemeBit(&o2,1,monBit);
	S_ajouterItem(&s,o2,6,SDNAD_copierDonneeNoeud,SDNAD_comparerDonneeNoeud);
  o1=S_obtenirOctet(s);

	ponderation = S_nombreOccurencesItem(s,o1,SDNAD_comparerDonneeNoeud);
	CU_ASSERT_TRUE((ponderation ==6) && OCT_octetEgaux(o1,o2));
	S_supprimer(&s,SDNAD_desallouerDonneeNoeud);
}



int main(int argc, char** argv)
{
	CU_pSuite pSuite=NULL;

/* initialisation du registre de tests*/

	if(CUE_SUCCESS != CU_initialize_registry())
	return CU_get_error();

/* ajout d'une suite de tests */

	pSuite=CU_add_suite("Tests boite noire", init_suite_success, clean_suite_success);
	if (NULL==pSuite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

/* ajout des tests a la suite de tests boite noire */

	if ((NULL==CU_add_test(pSuite,"estVide ?", test_S_Statisiques_estVide))
	    || (NULL==CU_add_test(pSuite,"verifie si des stats non vide n est pas vide", test_S_Statisiques_estVide_casNonVide))
	    || (NULL==CU_add_test(pSuite,"verifie que la taille de stats avec un element est correcte", test_S_Statistiques_taille))

			|| (NULL==CU_add_test(pSuite,"Vérifie qu'un element a bien été supprimé", test_S_Statistiques_supprimerTete))
			|| (NULL==CU_add_test(pSuite,"Vérifie que l'octet est bon", test_S_obtenirOctet))
			|| (NULL==CU_add_test(pSuite,"Vérifie que qu'Item est present", test_S_estPresent))

			|| (NULL==CU_add_test(pSuite,"Vérifie que l'on passe bien a la stats suivante", test_S_ObtenirStatSuivante))
			|| (NULL==CU_add_test(pSuite,"Vérifie que l'on ajoute bien un Item", test_S_ajouterItem))
			|| (NULL==CU_add_test(pSuite,"Vérifie que l'on ajoute bien un Item a la fin", test_S_ajouterItem_ALaFin))
			|| (NULL==CU_add_test(pSuite,"Vérifie que le nombre d'occurences d'un octet est le bon ", test_S_Statistiques_nboccurencesItem
		)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

/* lancement des tests */

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	printf("\n");
	CU_basic_show_failures(CU_get_failure_list());
	printf("\n\n");

/* nettoyage du registre */

	CU_cleanup_registry();
	return CU_get_error();
}
