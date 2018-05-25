#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TableDeCodage.h"
#include "CodeBinaire.h"
#include "bit.h"
#include "Octet.h"
#include "bit_allocation_dynamique.h"
#include "ListeChainee.h"
#define TRUE 1
#define FALSE 0

int init_suite_success(void) {
  return 0;
}

int clean_suite_success(void) {
  return 0;
}


void test_tableDeCodageVide(){
  TableDeCodage tdc=TDC_tableDeCodageVide();
  octet monOctet = OCT_creerOctet();
  OCT_fixeriemeBit(&monOctet,5,b1);
  CU_ASSERT_TRUE(CB_estVide(TDC_obtenirCode(tdc,monOctet,BAD_copierBit)));
  TDC_supprimer(&tdc,BAD_desallouerBit);
  }



void test_TDC_fixerCodeElement(void){
    TableDeCodage tdc=TDC_tableDeCodageVide();
    CodeBinaire code=CB_creerCodeBinaireVide();
    octet oct=OCT_creerOctet();

    OCT_fixeriemeBit(&oct,1,b0);
    OCT_fixeriemeBit(&oct,2,b0);
    OCT_fixeriemeBit(&oct,3,b0);
    OCT_fixeriemeBit(&oct,5,b0);
    OCT_fixeriemeBit(&oct,4,b0);
    OCT_fixeriemeBit(&oct,6,b0);
    OCT_fixeriemeBit(&oct,7,b0);
    OCT_fixeriemeBit(&oct,8,b0);

    CB_ajouterEnTete(&code,b1,BAD_copierBit);
    TDC_fixerCodeElement(oct,code,&tdc,BAD_copierBit);
    CU_ASSERT_TRUE(CB_sontEgaux(TDC_obtenirCode(tdc,oct,BAD_copierBit),code,BAD_comparerBit));
    TDC_supprimer(&tdc,BAD_desallouerBit);
    CB_supprimer(&code,BAD_desallouerBit);
}



void test_TDC_obtenirCode(void){
    TableDeCodage tdc=TDC_tableDeCodageVide();
    CodeBinaire code=CB_creerCodeBinaireVide();
    octet oct=OCT_creerOctet();

    OCT_fixeriemeBit(&oct,1,b0);
    OCT_fixeriemeBit(&oct,2,b0);
    OCT_fixeriemeBit(&oct,3,b0);
    OCT_fixeriemeBit(&oct,5,b0);
    OCT_fixeriemeBit(&oct,4,b0);
    OCT_fixeriemeBit(&oct,6,b0);
    OCT_fixeriemeBit(&oct,7,b0);
    OCT_fixeriemeBit(&oct,8,b0);

    CB_ajouterEnTete(&code, b1,BAD_copierBit);
    TDC_fixerCodeElement(oct,code,&tdc,BAD_copierBit);
    CU_ASSERT_TRUE(CB_sontEgaux(TDC_obtenirCode(tdc,oct,BAD_copierBit),code,BAD_comparerBit));
    TDC_supprimer(&tdc,BAD_desallouerBit);
    CB_supprimer(&code,BAD_desallouerBit);
}

int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;


  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();


  pSuite = CU_add_suite("Tests boite noire", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }


  if (( (NULL == CU_add_test(pSuite, "fixerCodeElement", test_TDC_fixerCodeElement))
        || (NULL == CU_add_test(pSuite, "tableDeCodageVide", test_tableDeCodageVide))
        || (NULL == CU_add_test(pSuite, "obtenirCode", test_TDC_obtenirCode))
      ))
    {
      CU_cleanup_registry();
      return CU_get_error();
    }


  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");


  CU_cleanup_registry();
  return CU_get_error();
}
