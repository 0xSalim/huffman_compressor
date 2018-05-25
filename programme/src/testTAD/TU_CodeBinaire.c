#include <stdlib.h>
#include <CUnit/Basic.h>
#include "bit.h"
#include "CodeBinaire.h"
#include "bit_allocation_dynamique.h"

int init_suite_success(void) {
  return 0;
}

int clean_suite_success(void) {
  return 0;
}

void test_CB_convertirCodeBinaireEnBaseDix()
{
	bit bitAjouter;
	CodeBinaire code;
	bitAjouter = b1;
	code = CB_creerCodeBinaireVide();
	CB_ajouterEnTete(&code,bitAjouter,BAD_copierBit);
	CB_ajouterEnTete(&code,bitAjouter,BAD_copierBit);
	CU_ASSERT_TRUE(CB_convertirCodeBinaireEnBaseDix(code)==3);
	CB_supprimer(&code,BAD_desallouerBit);
}

void test_CB_concatener()
{
  bit bitAjouter;
  bit bitAjouter0;
	CodeBinaire code;
  CodeBinaire code2;
	bitAjouter = b1;
  bitAjouter0=b0;
	code = CB_creerCodeBinaireVide();
  code2 = CB_creerCodeBinaireVide();
	CB_ajouterEnTete(&code,bitAjouter,BAD_copierBit);
  CB_ajouterEnTete(&code,bitAjouter0,BAD_copierBit);
  CB_ajouterEnTete(&code,bitAjouter,BAD_copierBit);
  CB_ajouterEnTete(&code,bitAjouter0,BAD_copierBit);
  CB_ajouterEnTete(&code2,bitAjouter0,BAD_copierBit);
  CB_ajouterEnTete(&code2,bitAjouter,BAD_copierBit);
  CB_ajouterEnTete(&code2,bitAjouter0,BAD_copierBit);
  CB_ajouterEnTete(&code2,bitAjouter,BAD_copierBit);
  CB_concatener(&code2,code);
	CU_ASSERT_TRUE(CB_obtenirIemeBitCodeBinaire(code2,1)==b1 && CB_obtenirIemeBitCodeBinaire(code2,2)==b0 && CB_obtenirIemeBitCodeBinaire(code2,5)==b0 && CB_obtenirIemeBitCodeBinaire(code2,8)==b1 );
	CB_supprimer(&code2,BAD_desallouerBit);
}

void test_CB_obtenirIemeBitCodeBinaire()
{
	bit bitAjouter;
  bit bitAjouter0;
	CodeBinaire code;
	bitAjouter = b1;
  bitAjouter0=b0;
	code = CB_creerCodeBinaireVide();
	CB_ajouterEnTete(&code,bitAjouter,BAD_copierBit);
  CB_ajouterEnTete(&code,bitAjouter0,BAD_copierBit);
  CB_ajouterEnTete(&code,bitAjouter,BAD_copierBit);
  CB_ajouterEnTete(&code,bitAjouter0,BAD_copierBit);
	CU_ASSERT_TRUE(CB_obtenirIemeBitCodeBinaire(code,1)==b0 && CB_obtenirIemeBitCodeBinaire(code,2)==b1 && CB_obtenirIemeBitCodeBinaire(code,3)==b0 && CB_obtenirIemeBitCodeBinaire(code,4)==b1 );
	CB_supprimer(&code,BAD_desallouerBit);
}

void test_CB_supprimerBit()
{
	bit bitAjouter;
  bit bitAjouter0;
	CodeBinaire code;
	bitAjouter = b1;
  bitAjouter0=b0;
	code = CB_creerCodeBinaireVide();
	CB_ajouterEnTete(&code,bitAjouter,BAD_copierBit);
  CB_ajouterEnTete(&code,bitAjouter0,BAD_copierBit);
  CB_ajouterEnTete(&code,bitAjouter,BAD_copierBit);
  CB_ajouterEnTete(&code,bitAjouter0,BAD_copierBit);
  CB_supprimerBit(&code,1,BAD_desallouerBit);
  CB_supprimerBit(&code,2,BAD_desallouerBit);
	CU_ASSERT_TRUE( (CB_obtenirIemeBitCodeBinaire(code,1)==b1) && (CB_obtenirIemeBitCodeBinaire(code,2)==b1));
	CB_supprimer(&code,BAD_desallouerBit);
}




void test_ajouterEnTete()
{
	bit bitAjouter;
  bit bitAjouter0;
	CodeBinaire code;
	bitAjouter = b1;
  bitAjouter0=b0;
	code = CB_creerCodeBinaireVide();
  CB_ajouterEnTete(&code,bitAjouter0,BAD_copierBit);
	CB_ajouterEnTete(&code,bitAjouter,BAD_copierBit);
	CU_ASSERT_TRUE(CB_obtenirIemeBitCodeBinaire(code,1)==bitAjouter);
	CB_supprimer(&code,BAD_desallouerBit);
}

void test_estVide_casVide(){
	CodeBinaire code;
	code = CB_creerCodeBinaireVide();
	CU_ASSERT_TRUE(CB_estVide(code)==1);
}

void test_estVide_casNonVide(){
	CodeBinaire code;
	bit bitAjoute = b1;
	code = CB_creerCodeBinaireVide();
	CB_ajouterEnTete(&code, bitAjoute,BAD_copierBit);
	CU_ASSERT_TRUE(CB_estVide(code)==0);
	CB_supprimer(&code,BAD_desallouerBit);
}

void test_obtenirLongueur_casVide()
{
	CodeBinaire code= CB_creerCodeBinaireVide();
	CU_ASSERT_TRUE(CB_obtenirLongueur(code)==0);
}

void test_obtenirLongueur()
{
	CodeBinaire code;
	unsigned int i;
	bit bitAjoute = b1;
	code = CB_creerCodeBinaireVide();
	for(i=0;i<=3;i++)
		CB_ajouterEnTete(&code,bitAjoute,BAD_copierBit);
	CU_ASSERT_TRUE(CB_obtenirLongueur(code)==4);
	CB_supprimer(&code,BAD_desallouerBit);
}

void test_supprimer(){
	CodeBinaire code;
	int i;
	bit bitAjoute=b1;
	code = CB_creerCodeBinaireVide();
	for(i=0;i<=5;i++)
		CB_ajouterEnTete(&code,bitAjoute,BAD_copierBit);
	CB_supprimer(&code,BAD_desallouerBit);
	CU_ASSERT_TRUE(CB_estVide(code));
	CB_supprimer(&code,BAD_desallouerBit);
}

void test_fixerCodeBinaireSuivant(){
	CodeBinaire code1;
	CodeBinaire code2;
	int i;
	bit bitAjoute2=b0;
	code1 = CB_creerCodeBinaireVide();
  CB_ajouterEnTete(&code1,bitAjoute2,BAD_copierBit);
	code2 = CB_creerCodeBinaireVide();
	for(i=0;i<=5;i++)
	{
		CB_ajouterEnTete(&code2,bitAjoute2,BAD_copierBit);
	}
	CB_fixerCodeBinaireSuivant(&code1, code2);
	CU_ASSERT_TRUE(CB_obtenirCodeBinaireSuivant(code1) == code2);
	CB_supprimer(&code1,BAD_desallouerBit);
}

void test_ajouterAlaFin(){
	CodeBinaire code;
	unsigned int i;
	//bit bitAjoute = b1;
	bit bitd = b0;
  bit bitFin = b1;
	code = CB_creerCodeBinaireVide();
	for(i=0;i<=4;i++)
	CB_ajouterAlaFin(&code,bitd,BAD_copierBit);
  CB_ajouterAlaFin(&code,bitFin,BAD_copierBit);
	CU_ASSERT_TRUE(CB_obtenirIemeBitCodeBinaire(code,6)==b1);

	CB_supprimer(&code,BAD_desallouerBit);

}

int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "test convertir code en decimal",test_CB_convertirCodeBinaireEnBaseDix))
    || (NULL == CU_add_test(pSuite, "test concatener",test_CB_concatener))
    || (NULL == CU_add_test(pSuite, "test obtenir IemeBit",test_CB_obtenirIemeBitCodeBinaire))
    || (NULL == CU_add_test(pSuite, "test supprimer IemeBit",test_CB_supprimerBit))
    ||  (NULL == CU_add_test(pSuite, "test ajouter en tete", test_ajouterEnTete))
      || (NULL == CU_add_test(pSuite, "test obtenir longueur", test_obtenirLongueur))
      || (NULL == CU_add_test(pSuite, "test obtenir longueur", test_obtenirLongueur_casVide))
      || (NULL == CU_add_test(pSuite, "test est vide cas vide", test_estVide_casVide))
	  || (NULL == CU_add_test(pSuite, "test est vide cas non vide", test_estVide_casNonVide))
      || (NULL == CU_add_test(pSuite, "test supprimer bit", test_supprimer))
      || (NULL == CU_add_test(pSuite, "test fixer code binaire suivant", test_fixerCodeBinaireSuivant))
      || (NULL == CU_add_test(pSuite, "test ajouter A la fin", test_ajouterAlaFin))
  	  )
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

  /* Lancement des tests */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");

  /* Nettoyage du registre */
  CU_cleanup_registry();
  return CU_get_error();
}
