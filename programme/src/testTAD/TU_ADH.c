#include <stdlib.h>
#include <assert.h>
#include "FileDePriorite.h"
#include "arbreDeHuffman.h"
#include "CodeBinaire.h"
#include "Octet.h"
#include "bit.h"

#include<stdlib.h>
#include<CUnit/Basic.h>

#define TRUE 1
#define FALSE 0

//on ne teste pas fusionner et comparer etant donne qu'on ne s'en sert pas

int init_suite_success(void) {
  return 0;
}

int clean_suite_success(void) {
  return 0;
}

void TU_creerADH_arbreDeHuffman(){
    octet o=OCT_creerOctet();
    ADH_arbreDeHuffman arbre=ADH_creerArbreDeHuffman(o, 5);
    CU_ASSERT_TRUE(!ADH_estVide(arbre) && (ADH_obtenirPere(arbre).ponderation==5) && OCT_octetEgaux(OCT_creerOctet(),ADH_obtenirPere(arbre).valeurOctet));
	ADH_supprimerArbre(&arbre);
}
void TU_estVide_casVide(){
    ADH_arbreDeHuffman arbre=ADH_creerArbreDeHuffmanVide();
    CU_ASSERT_TRUE(ADH_estVide(arbre));
     ADH_supprimerArbre(&arbre);
}
void TU_estVide_casNonVide(){
    octet o=OCT_creerOctet();
    ADH_arbreDeHuffman arbre=ADH_creerArbreDeHuffman(o,5);
    CU_ASSERT_TRUE(!(ADH_estVide(arbre)));
     ADH_supprimerArbre(&arbre);
}
void TU_estUneFeuille_casFeuille(){
    octet o=OCT_creerOctet();
    ADH_arbreDeHuffman arbre=ADH_creerArbreDeHuffman(o,5);
    CU_ASSERT_TRUE(ADH_estUneFeuille(arbre));
     ADH_supprimerArbre(&arbre);
}
void TU_estUneFeuille_casNonFeuille(){
    ADH_arbreDeHuffman arbre1=ADH_creerArbreDeHuffman(OCT_creerOctet(),5);
    ADH_arbreDeHuffman arbre2=ADH_creerArbreDeHuffman(OCT_creerOctet(),6);
    ADH_arbreDeHuffman arbre_resultat=ADH_fusionnerArbreDeHuffman(arbre1,arbre2);
    CU_ASSERT_TRUE(!(ADH_estUneFeuille(arbre_resultat)));
	ADH_supprimerArbre(&arbre_resultat);
}
void TU_obtenirPere(){
    octet o=OCT_creerOctet();
    ADH_arbreDeHuffman arbre=ADH_creerArbreDeHuffman(o, 5);
    ADH_valeurRacine pere=ADH_obtenirPere(arbre);
    CU_ASSERT_TRUE((pere.ponderation==5) && OCT_octetEgaux(pere.valeurOctet,OCT_creerOctet()));
    ADH_supprimerArbre(&arbre);
}
void TU_obtenirFilsDroit(){
    octet o=OCT_creerOctet();
    ADH_arbreDeHuffman arbre1=ADH_creerArbreDeHuffman(o,5);
    ADH_arbreDeHuffman arbre2=ADH_creerArbreDeHuffman(o,3);
    ADH_arbreDeHuffman arbre_resultat=ADH_fusionnerArbreDeHuffman(arbre1,arbre2);
    CU_ASSERT_TRUE(ADH_obtenirFilsDroit(arbre_resultat)==arbre1);
	ADH_supprimerArbre(&arbre_resultat);
}
void TU_obtenirFilsGauche(){
    octet o=OCT_creerOctet();
    ADH_arbreDeHuffman arbre1=ADH_creerArbreDeHuffman(o,5);
    ADH_arbreDeHuffman arbre2=ADH_creerArbreDeHuffman(o,3);
    ADH_arbreDeHuffman arbre_resultat=ADH_fusionnerArbreDeHuffman(arbre1,arbre2);
    CU_ASSERT_TRUE(ADH_obtenirFilsGauche(arbre_resultat)==arbre2);
	ADH_supprimerArbre(&arbre_resultat);
}
void TU_fusionner(){
    octet o=OCT_creerOctet();
    ADH_arbreDeHuffman arbre1=ADH_creerArbreDeHuffman(o,5);
    ADH_arbreDeHuffman arbre2=ADH_creerArbreDeHuffman(o,3);
    ADH_arbreDeHuffman arbre_resultat=ADH_fusionnerArbreDeHuffman(arbre1,arbre2);
    CU_ASSERT_TRUE((ADH_obtenirFilsGauche(arbre_resultat)==arbre2)&&(ADH_obtenirFilsDroit(arbre_resultat)==arbre1));
	ADH_supprimerArbre(&arbre_resultat);
}
void TU_comparer_casEgaux(){
    octet o=OCT_creerOctet();
    ADH_arbreDeHuffman arbre1=ADH_creerArbreDeHuffman(o,5);
    ADH_arbreDeHuffman arbre2=ADH_creerArbreDeHuffman(o,3);
    ADH_arbreDeHuffman arbre5=ADH_creerArbreDeHuffman(o,3);
    ADH_arbreDeHuffman arbre6=ADH_creerArbreDeHuffman(o,5);
    ADH_arbreDeHuffman arbre3=ADH_fusionnerArbreDeHuffman(arbre1,arbre2);
    ADH_arbreDeHuffman arbre4=ADH_fusionnerArbreDeHuffman(arbre6,arbre5);
    int i=ADH_comparerArbreDeHuffman(arbre3,arbre4);
    CU_ASSERT_TRUE(i!=0);
	ADH_supprimerArbre(&arbre3);
	ADH_supprimerArbre(&arbre4);
}
void TU_comparer_casNonEgaux(){
    octet o=OCT_creerOctet();
    ADH_arbreDeHuffman arbre1=ADH_creerArbreDeHuffman(o,5);
    ADH_arbreDeHuffman arbre2=ADH_creerArbreDeHuffman(o,3);
    ADH_arbreDeHuffman arbre6=ADH_creerArbreDeHuffman(o,3);
    ADH_arbreDeHuffman arbre3=ADH_creerArbreDeHuffman(o,1);
    ADH_arbreDeHuffman arbre4=ADH_fusionnerArbreDeHuffman(arbre1,arbre2);
    ADH_arbreDeHuffman arbre5=ADH_fusionnerArbreDeHuffman(arbre6,arbre3);
    int i=ADH_comparerArbreDeHuffman(arbre5,arbre4);
    CU_ASSERT_TRUE(i==0);
	ADH_supprimerArbre(&arbre4);
	ADH_supprimerArbre(&arbre5);

}

void TU_supprimerPere_casFeuille(){
		octet o=OCT_creerOctet();
		ADH_arbreDeHuffman arbre2,arbre3,arbre1=ADH_creerArbreDeHuffman(o,5);
		ADH_supprimerPere(&arbre1,&arbre2,&arbre3);
		CU_ASSERT_TRUE(ADH_estVide(arbre2) && ADH_estVide(arbre3));
	}

void TU_supprimerPere_casGeneral(){
		octet o=OCT_creerOctet();

		ADH_arbreDeHuffman arbre2=ADH_creerArbreDeHuffman(o,5);
		ADH_arbreDeHuffman arbre3=ADH_creerArbreDeHuffman(o,5);
		ADH_arbreDeHuffman arbre1=ADH_fusionnerArbreDeHuffman(arbre2,arbre3);
		ADH_arbreDeHuffman arbre4=ADH_creerArbreDeHuffmanVide();
		ADH_arbreDeHuffman arbre5=ADH_creerArbreDeHuffmanVide();
		ADH_supprimerPere(&arbre1,&arbre4,&arbre5);
		CU_ASSERT_TRUE(ADH_comparerArbreDeHuffman(arbre2,arbre4) && ADH_comparerArbreDeHuffman(arbre3,arbre5));
		ADH_supprimerArbre(&arbre2);
		ADH_supprimerArbre(&arbre3);
	}

void TU_supprimer_casFeuille(){  /// A regarder avec valgrind
		octet o=OCT_creerOctet();

		ADH_arbreDeHuffman arbre2=ADH_creerArbreDeHuffman(o,5);
		ADH_supprimerArbre(&arbre2);
		CU_ASSERT_TRUE(1);
	}

void TU_supprimer_casGeneral(){  /// A regarder avec valgrind
		octet o=OCT_creerOctet();

		ADH_arbreDeHuffman arbre2=ADH_creerArbreDeHuffman(o,5);
		ADH_arbreDeHuffman arbre3=ADH_creerArbreDeHuffman(o,5);
		ADH_arbreDeHuffman arbre1=ADH_fusionnerArbreDeHuffman(arbre2,arbre3);
		ADH_supprimerArbre(&arbre1);
		CU_ASSERT_TRUE(1);
	}


int main(int argc, char** argv){
  CU_pSuite TU_ADH_creerADH_arbreDeHuffman = NULL;
  CU_pSuite TU_ADH_estVide = NULL;
  CU_pSuite TU_ADH_estUneFeuille = NULL;
  CU_pSuite TU_ADH_obtenirPere = NULL;
  CU_pSuite TU_ADH_obtenirFilsDroit = NULL;
  CU_pSuite TU_ADH_obtenirFilsGauche = NULL;
  CU_pSuite TU_ADH_fusionnerArbreDeHuffman = NULL;
  CU_pSuite TU_ADH_comparerArbreDeHuffman = NULL;
  CU_pSuite TU_ADH_supprimerFeuille= NULL;
  CU_pSuite TU_ADH_supprimer= NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  TU_ADH_creerADH_arbreDeHuffman = CU_add_suite("Tests boite noire : creerADH_arbreDeHuffman", init_suite_success, clean_suite_success);
  TU_ADH_estVide = CU_add_suite("Tests boite noire : estVide", init_suite_success, clean_suite_success);
  TU_ADH_estUneFeuille = CU_add_suite("Tests boite noire : estUneFeuille", init_suite_success, clean_suite_success);
  TU_ADH_obtenirPere = CU_add_suite("Tests boite noire : obtenirPere", init_suite_success, clean_suite_success);
  TU_ADH_obtenirFilsDroit = CU_add_suite("Tests boite noire : obtenirFilsDroit", init_suite_success, clean_suite_success);
  TU_ADH_obtenirFilsGauche = CU_add_suite("Tests boite noire : obtenirFilsGauche", init_suite_success, clean_suite_success);
  TU_ADH_fusionnerArbreDeHuffman = CU_add_suite("Tests boite noire : fusionnerArbreDeHuffman", init_suite_success, clean_suite_success);
  TU_ADH_comparerArbreDeHuffman = CU_add_suite("Tests boite noire : comparerArbreDeHuffman", init_suite_success, clean_suite_success);
  TU_ADH_supprimerFeuille=CU_add_suite("Tests boite noire : supprimerFeuille", init_suite_success, clean_suite_success);
  TU_ADH_supprimer=CU_add_suite("Tests boite noire : supprimer", init_suite_success, clean_suite_success);

  if ((NULL == TU_ADH_creerADH_arbreDeHuffman) || (NULL == TU_ADH_estVide) || (NULL == TU_ADH_estUneFeuille) || (NULL == TU_ADH_obtenirPere) || (NULL == TU_ADH_obtenirFilsDroit) || (NULL == TU_ADH_obtenirFilsGauche) || (NULL == TU_ADH_fusionnerArbreDeHuffman) || (NULL == TU_ADH_comparerArbreDeHuffman) || (NULL==TU_ADH_supprimerFeuille) || (NULL==TU_ADH_supprimer) )
    {
    CU_cleanup_registry();
    return CU_get_error();
    }

  /* Ajout des tests � la suite de tests boite noire */
  if (NULL == CU_add_test(TU_ADH_creerADH_arbreDeHuffman, "l'arbre cree est bien vide", TU_creerADH_arbreDeHuffman))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if ((NULL == CU_add_test(TU_ADH_estVide, "un arbre vide est bien vide", TU_estVide_casVide)) || (NULL == CU_add_test(TU_ADH_estVide, "un arbre non vide n'est pas vide", TU_estVide_casNonVide)))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

     if ((NULL == CU_add_test(TU_ADH_estUneFeuille, "une feuille est bien une feuille", TU_estUneFeuille_casFeuille)) || (NULL == CU_add_test(TU_ADH_estUneFeuille, "un arbre qui n'est pas une feuille n'est pas une feuille", TU_estUneFeuille_casNonFeuille)))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

      if (NULL == CU_add_test(TU_ADH_obtenirPere, "obtenirPere donne le bon element", TU_obtenirPere))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

        if (NULL == CU_add_test(TU_ADH_obtenirFilsDroit, "obtenirFilsDroit donne le bon element", TU_obtenirFilsDroit))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

        if (NULL == CU_add_test(TU_ADH_obtenirFilsGauche, "obtenirFilsGauche donne le bon element", TU_obtenirFilsGauche))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }
        if (NULL == CU_add_test(TU_ADH_fusionnerArbreDeHuffman, "fusionner fonctionne", TU_fusionner))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }
    if ((NULL == CU_add_test(TU_ADH_comparerArbreDeHuffman, "deux arbres identiques sont �gaux", TU_comparer_casEgaux)) || (NULL == CU_add_test(TU_ADH_comparerArbreDeHuffman, "deux arbres diff�rents ne sont pas �gaux", TU_comparer_casNonEgaux)))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if ((NULL == CU_add_test(TU_ADH_supprimerFeuille, "suppression d'une feuille", TU_supprimerPere_casFeuille)) || (NULL == CU_add_test(TU_ADH_supprimerFeuille, "suppression d'une feuille", TU_supprimerPere_casGeneral)))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if ((NULL == CU_add_test(TU_ADH_supprimer, "suppression d'un arbre-feuille", TU_supprimer_casFeuille)) || (NULL == CU_add_test(TU_ADH_supprimer, "suppression d'un arbre", TU_supprimer_casGeneral)))
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
