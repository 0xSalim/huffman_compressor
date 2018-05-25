#include "CodeBinaire.h"
#include "bit.h"
CodeBinaire CB_creerCodeBinaireVide() {
	return (CodeBinaire)LC_ListeChaineeVide();
}


int CB_estVide(CodeBinaire c) {
	return LC_estVide(c);
}

bit CB_obtenirBit(CodeBinaire c) {
	assert(!CB_estVide(c));
	bit* e;

	e = (bit*)LC_obtenirElement(c);

	return *e;
}

bit CB_obtenirIemeBitCodeBinaire(CodeBinaire c, unsigned int i) {
	assert((1 <= i) && (i <= (CB_obtenirLongueur(c))));
	int j=0;
	CodeBinaire temp = c;
		for (j=1; j <i; j++) {
			temp = CB_obtenirCodeBinaireSuivant(temp);
		}
	return CB_obtenirBit(temp);
}

int CB_obtenirLongueur(CodeBinaire c) {
	int res = 0;
	CodeBinaire temp = c;

	while (!CB_estVide(temp)) {
		temp = CB_obtenirCodeBinaireSuivant(temp);
		res++;
	}
	return res;
}

CodeBinaire CB_obtenirCodeBinaireSuivant(CodeBinaire c){

	return LC_obtenirListeSuivante(c);
}


void CB_fixerCodeBinaireSuivant(CodeBinaire* c1 , CodeBinaire c2){
  assert(!CB_estVide(*c1));
	LC_fixerListeSuivante(c1, c2);
}

void CB_supprimerTete(CodeBinaire* c,CLC_FonctionLiberer libererBit ){
    assert (!CB_estVide(*c));
		LC_supprimerTete(c,libererBit);
}

void CB_supprimer(CodeBinaire* c,CLC_FonctionLiberer libererBit){
  LC_supprimer(c,libererBit);
}

void CB_supprimerBit(CodeBinaire* c, unsigned int i,CLC_FonctionLiberer libererBit) {
	assert((1 <= i) && (i <= (CB_obtenirLongueur(*c))) );
	CodeBinaire temp;

	if (i == 1) {
		CB_supprimerTete(c,libererBit);
	}
	else {
		temp = CB_obtenirCodeBinaireSuivant(*c);
		CB_supprimerBit(&temp, i-1,libererBit);
		CB_fixerCodeBinaireSuivant(c, temp);
	}
}


void CB_ajouterEnTete(CodeBinaire* c, bit b,CLC_FonctionCopier copierBit) {
	LC_ajouter(c, &b,copierBit);

}

void CB_ajouterAlaFin(CodeBinaire* c, bit b,CLC_FonctionCopier copierBit) {
	CodeBinaire temp;

	if (CB_estVide(*c)) {
		CB_ajouterEnTete(c, b,copierBit);
	}
	else {
		temp = CB_obtenirCodeBinaireSuivant(*c);
		CB_ajouterAlaFin(&temp, b,copierBit);
		CB_fixerCodeBinaireSuivant(c, temp);
	}
}
void CB_ajouterBit(CodeBinaire* c, unsigned int i, bit b,CLC_FonctionCopier copierBit) {
  assert(1 <= i && i <= (CB_obtenirLongueur(*c)));
  CodeBinaire temp;
  if (i == 1) {
    CB_ajouterEnTete(c, b,copierBit);
  }
  else {
    temp = CB_obtenirCodeBinaireSuivant(*c);
    CB_ajouterBit(&temp, i-1, b,copierBit);
    CB_fixerCodeBinaireSuivant(c, temp);
  }
}


int CB_sontEgaux(CodeBinaire c1, CodeBinaire c2,CLC_FonctionComparer comparerBit)
{
  return LC_egales(c1, c2, comparerBit);
}

void CB_concatener(CodeBinaire* c1,CodeBinaire c2)
{
	CodeBinaire temp=*c1;
	if (CB_estVide(*c1))
	{
		*c1=c2;
	}
	else
	{
		while (!CB_estVide(CB_obtenirCodeBinaireSuivant(temp)))
		{
			temp=CB_obtenirCodeBinaireSuivant(temp);
		}
		CB_fixerCodeBinaireSuivant(&temp,c2);
	}
}

int CB_convertirCodeBinaireEnBaseDix(CodeBinaire mon_code_binaire){
	assert(!CB_estVide(mon_code_binaire));
	int bit;
	int adresse=0;
	int longueur;
	int i=0;
	longueur=CB_obtenirLongueur(mon_code_binaire);
	for(i=1; i<=longueur; i++){
		bit=CB_obtenirIemeBitCodeBinaire(mon_code_binaire, i);
		adresse=adresse+bit_en_int(bit)*pow(2,longueur-i);
	}
	return(adresse);
}

CodeBinaire CB_copierCodeBinaire(CodeBinaire code,CLC_FonctionCopier copierBit){
	CodeBinaire res=CB_creerCodeBinaireVide();
	res=LC_copier(code,copierBit);
	return res;
}


