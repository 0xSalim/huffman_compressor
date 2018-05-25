#include <stdlib.h>
#include <CUnit/Basic.h>
#include "Octet.h"
#include "bit.h"

#define TRUE 1
#define FALSE 0

int init_suite_success(void) {
  return 0;
}

int clean_suite_success(void) {
  return 0;
}

void test_OCT_creerOctet(){
}

void test_obteniriemeBit(){
	octet octetATester;
	octetATester = OCT_creerOctet();
	OCT_fixeriemeBit(&octetATester,1,b1);
	CU_ASSERT_TRUE(bit_egaux(OCT_obteniriemeBit(octetATester,1),b1));
}

void test_octetEgaux_casSontEgaux(){
	octet octetATester1,octetATester2;
	octetATester1 = OCT_creerOctet();
	octetATester2 = OCT_creerOctet();
	CU_ASSERT_TRUE(OCT_octetEgaux(octetATester1,octetATester2)==TRUE);
}

void test_octetEgaux_casPasEgaux(){
	octet octetATester1,octetATester2;
	octetATester1 = OCT_creerOctet();
	OCT_copierOctet(octetATester1, &octetATester2);
	OCT_fixeriemeBit(&octetATester2,2,b1);
	CU_ASSERT_TRUE(OCT_octetEgaux(octetATester1,octetATester2)==FALSE);
}
void test_octetEnDeximal(){
  octet monOctet;
  int resDecimal;
  monOctet = OCT_creerOctet();
  OCT_fixeriemeBit(&monOctet,1,b1);
  resDecimal = OCT_octetEnDecimal(monOctet);
  CU_ASSERT_TRUE(resDecimal==64);
}

void test_decimalEnOctet(){
  int mondecimal;
  octet monOctet;
  monOctet = OCT_creerOctet();
  mondecimal = 4;
  monOctet = OCT_decimalEnOctet(mondecimal);
  CU_ASSERT_TRUE(bit_egaux(OCT_obteniriemeBit(monOctet,5),b1));
}

void test_OCT_copierOctet(){
  octet monOctet1, monOctet2;
  monOctet1 = OCT_creerOctet();
  monOctet2 = OCT_creerOctet();
  OCT_fixeriemeBit(&monOctet2,2,b1);
  OCT_copierOctet(monOctet1, &monOctet2);
  CU_ASSERT_TRUE(OCT_octetEgaux(monOctet1,monOctet2));
}

void test_OCT_fixeriemeBit(){
	octet octetATester;
	bit bitAjoute;
	octetATester = OCT_creerOctet();
	bitAjoute = b1;
	OCT_fixeriemeBit(&octetATester,3,bitAjoute);
	CU_ASSERT_TRUE(bit_egaux(OCT_obteniriemeBit(octetATester,3),bitAjoute));

}

int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : octet", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "test creer Octet", test_OCT_creerOctet))
      || (NULL == CU_add_test(pSuite, "test obtenir ieme bit", test_obteniriemeBit))
      || (NULL == CU_add_test(pSuite, "test Egaux", test_octetEgaux_casSontEgaux))
      || (NULL == CU_add_test(pSuite, "test pas Egaux", test_octetEgaux_casPasEgaux))
      || (NULL == CU_add_test(pSuite, "test fixer bit", test_OCT_fixeriemeBit))
      || (NULL == CU_add_test(pSuite, "test octet en decimal", test_octetEnDeximal))
      || (NULL == CU_add_test(pSuite, "test decimal en octet", test_decimalEnOctet))
      || (NULL == CU_add_test(pSuite, "test copier octet", test_OCT_copierOctet))
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
