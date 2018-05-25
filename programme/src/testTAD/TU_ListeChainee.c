#include <stdio.h>
#include <CUnit/Basic.h>
#include "ListeChainee.h"
#include "bit_allocation_dynamique.h"


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




void test_LC_estVide(void)
{
  LC_ListeChainee l= LC_ListeChaineeVide();
	CU_ASSERT_TRUE(LC_estVide(l));

	LC_supprimer(&l,BAD_desallouerBit);
}

/*void test_LC_ajouter_obtenirElement(void)
{
	void* e1;
  LC_ListeChainee l= LC_ListeChaineeVide();
	LC_ajouter(&l,e1,BAD_copierBit);
	CU_ASSERT_TRUE(LC_obtenirElement(l) == e1);

	LC_supprimer(&l,BAD_desallouerBit);
}*/
/*
void test_LC_obtenirListeSuivante(void)
{
	void* e1;
	void* e2;
  LC_ListeChainee l1= LC_ListeChaineeVide();
	LC_ListeChainee l2= LC_ListeChaineeVide();
	LC_ajouter(&l1,e1,BAD_copierBit);
	LC_ajouter(&l2,e2,BAD_copierBit);

	CU_ASSERT_TRUE(	LC_obtenirListeSuivante(LC_fixerListeSuivante(l1,l2)) == l2);

	LC_supprimer(&l,BAD_desallouerBit);
}*/
/*
void test_LC_supprimerTete(void)
{
	void* e1;
  LC_ListeChainee l= LC_ListeChaineeVide();
	LC_ajouter(&l,e1,BAD_copierBit);
  LC_supprimerTete(&l, BAD_desallouerBit);
	CU_ASSERT_TRUE(LC_obtenirElement(l) == NULL);

	LC_supprimer(&l,BAD_desallouerBit);
}*/


/*
void test_LC_egales(void)
{
  LC_ListeChainee l1= LC_ListeChaineeVide();
  LC_ListeChainee l2= LC_ListeChaineeVide();
  LC_ListeChainee l3= LC_ListeChaineeVide();
	void* e1;
	void* e2;
	LC_ajouter(&l1,e1,BAD_copierBit);
	LC_ajouter(&l2,e2,BAD_copierBit);
	LC_ajouter(&l3,e1,BAD_copierBit);


	CU_ASSERT_TRUE(LC_egales(l1, l3,CLC_FonctionComparer) && !LC_egales(l1, l2,CLC_FonctionComparer));

	LC_supprimer(&l1,BAD_desallouerBit);
	LC_supprimer(&l2,BAD_desallouerBit);
	LC_supprimer(&l3,BAD_desallouerBit);
}
*/
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

	if ((NULL==CU_add_test(pSuite,"estVide ?", test_LC_estVide))
	    /*|| (NULL==CU_add_test(pSuite,"Ajoute un element en tête et regarde si c'est le bon", test_LC_ajouter_obtenirElement))
	    || (NULL==CU_add_test(pSuite,"verifie si la liste suivante est bien la bonne", test_LC_obtenirListeSuivante))
	    || (NULL==CU_add_test(pSuite,"Vérifie si le l'element ajouté en tete a bien été supprimé", test_LC_supprimerTete))
	    || (NULL==CU_add_test(pSuite,"Vérifie si deux Liste chainées sont égaux", test_LC_egales))*/)
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
