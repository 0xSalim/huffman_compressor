#include<stdlib.h>
#include<CUnit/Basic.h>

#define TRUE 1
#define FALSE 0
#include "FileDePriorite.h"
#include "arbreDeHuffman.h"
#include "arbre_allocation_dynamique.h"


/// Utiliser valgrind pour vérifier la suppression

int init_suite_success(void) {
  return 0;
}

int clean_suite_success(void) {
  return 0;
}

void TU_fileVide (void)
{
  CU_ASSERT_TRUE(FDP_estVide(FDP_creerVide()));
}

void TU_estVide_casVide(void)
{
  CU_ASSERT_TRUE(FDP_estVide(FDP_creerVide()));
}

void TU_estVide_casNonVide(void)
{
  FDP_FileDePriorite f=FDP_creerVide();
  ADH_arbreDeHuffman arbre1=ADH_creerArbreDeHuffman(OCT_creerOctet(),8);

  FDP_insererItem(arbre1,&f,ADHAD_copierArbre,1);
  ADH_supprimerArbre(&arbre1);

  CU_ASSERT_TRUE(!FDP_estVide(f));
  FDP_supprimer(&f,ADHAD_desallouerArbre);
}

void TU_defiler_taille1(void)
{
  FDP_FileDePriorite f=FDP_creerVide();
  ADH_arbreDeHuffman arbre1=ADH_creerArbreDeHuffman(OCT_creerOctet(),8);
  FDP_insererItem(arbre1,&f,ADHAD_copierArbre,1);
  ADH_supprimerArbre(&arbre1);
  FDP_defiler(&f, ADHAD_desallouerArbre);
  CU_ASSERT_TRUE(FDP_estVide(f));

  FDP_supprimer(&f,ADHAD_desallouerArbre);

}

void TU_defiler_taille2(void)
{
  FDP_FileDePriorite f=FDP_creerVide();
  ADH_arbreDeHuffman arbre1=ADH_creerArbreDeHuffman(OCT_creerOctet(),8);
  ADH_arbreDeHuffman arbre2=ADH_creerArbreDeHuffman(OCT_creerOctet(),9);
  FDP_insererItem(arbre1,&f,ADHAD_copierArbre,1);
  FDP_insererItem(arbre2,&f,ADHAD_copierArbre,1);
  FDP_defiler(&f,ADHAD_desallouerArbre);
  CU_ASSERT_TRUE(ADH_comparerArbreDeHuffman(FDP_obtenirTete(f),arbre1));
  FDP_defiler(&f,ADHAD_desallouerArbre);
  ADH_supprimerArbre(&arbre1);
  ADH_supprimerArbre(&arbre2);
}

void TU_inserer_casVide(void)
{
	ADH_arbreDeHuffman arbre1=ADH_creerArbreDeHuffman(OCT_creerOctet(),8);
	FDP_FileDePriorite f=FDP_creerVide();
  	FDP_insererItem(arbre1,&f,ADHAD_copierArbre,1);
	int a=ADH_comparerArbreDeHuffman(FDP_obtenirTete(f),arbre1);
	CU_ASSERT_TRUE(a);
	FDP_defiler(&f,ADHAD_desallouerArbre);
	ADH_supprimerArbre(&arbre1);
}

void TU_inserer_casNonVide(void)
{
	ADH_arbreDeHuffman arbre1=ADH_creerArbreDeHuffman(OCT_creerOctet(),8);
	ADH_arbreDeHuffman arbre2=ADH_creerArbreDeHuffman(OCT_creerOctet(),5);
	FDP_FileDePriorite f=FDP_creerVide();
  	FDP_insererItem(arbre1,&f,ADHAD_copierArbre,1);
  	FDP_insererItem(arbre2,&f,ADHAD_copierArbre,1);
	int a=ADH_comparerArbreDeHuffman(FDP_obtenirTete(f),arbre2);
	CU_ASSERT_TRUE(a);
	FDP_supprimer(&f,ADHAD_desallouerArbre);
	ADH_supprimerArbre(&arbre1);
	ADH_supprimerArbre(&arbre2);
}

void TU_obtenirTete(void)
{
	ADH_arbreDeHuffman arbre1=ADH_creerArbreDeHuffman(OCT_creerOctet(),8);
	FDP_FileDePriorite f=FDP_creerVide();
  	FDP_insererItem(arbre1,&f,ADHAD_copierArbre,1);
	int a=ADH_comparerArbreDeHuffman(FDP_obtenirTete(f),arbre1);
	CU_ASSERT_TRUE(a);
	FDP_defiler(&f,ADHAD_desallouerArbre);
	ADH_supprimerArbre(&arbre1);
}

void TU_longueur_casVide(void)
{
	FDP_FileDePriorite f=FDP_creerVide();
	CU_ASSERT_TRUE(FDP_longueur(f)==0);
}

void TU_longueur_casGeneral(void)
{
	FDP_FileDePriorite f=FDP_creerVide();
	FDP_insererItem(ADH_creerArbreDeHuffmanVide(),&f,ADHAD_copierArbre,1);
	CU_ASSERT_TRUE(FDP_longueur(f)==1);
	FDP_supprimer(&f,ADHAD_desallouerArbre);
}

int main(int argc, char** argv){
  CU_pSuite TU_FDP_creerVide = NULL;
  CU_pSuite TU_FDP_estVide = NULL;
  CU_pSuite TU_FDP_defiler = NULL;
  CU_pSuite TU_FDP_inserer = NULL;
  CU_pSuite TU_FDP_obtenirTete = NULL;
  CU_pSuite TU_FDP_longueur = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  TU_FDP_creerVide = CU_add_suite("Tests boite noire : creerVide", init_suite_success, clean_suite_success);
  TU_FDP_estVide = CU_add_suite("Tests boite noire : estVide", init_suite_success, clean_suite_success);
  TU_FDP_defiler = CU_add_suite("Tests boite noire : defiler", init_suite_success, clean_suite_success);
  TU_FDP_inserer = CU_add_suite("Tests boite noire : inserer", init_suite_success, clean_suite_success);
  TU_FDP_obtenirTete = CU_add_suite("Tests boite noire : obtenirTete", init_suite_success, clean_suite_success);
  TU_FDP_longueur = CU_add_suite("Tests boite noire : longueur", init_suite_success, clean_suite_success);

  if ((NULL == TU_FDP_creerVide) || (NULL == TU_FDP_estVide) || (NULL == TU_FDP_defiler) || (NULL == TU_FDP_inserer) || (NULL == TU_FDP_obtenirTete) || (NULL == TU_FDP_longueur))
    {
    CU_cleanup_registry();
    return CU_get_error();
    }

  /* Ajout des tests � la suite de tests boite noire */
  if ((NULL == CU_add_test(TU_FDP_creerVide, "la liste creee est bien vide", TU_fileVide)))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

   if ((NULL == CU_add_test(TU_FDP_estVide, "une liste vide est bien vide", TU_estVide_casVide)) || (NULL == CU_add_test(TU_FDP_estVide, "une liste non vide n'est pas vide", TU_estVide_casNonVide)))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if ((NULL == CU_add_test(TU_FDP_defiler, "defiler une file avec deux elems", TU_defiler_taille1)))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if ((NULL == CU_add_test(TU_FDP_inserer, "inserer dans une liste vide", TU_inserer_casVide))  || (NULL == CU_add_test(TU_FDP_inserer, "inserer dans une liste non vide", TU_inserer_casNonVide)))    {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if ((NULL == CU_add_test(TU_FDP_obtenirTete, "obtenir tete", TU_obtenirTete)))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }
    if ((NULL == CU_add_test(TU_FDP_longueur, "longueur d'une liste vide", TU_longueur_casVide)) || (NULL == CU_add_test(TU_FDP_longueur, "longueur d'une liste", TU_longueur_casGeneral)))
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
