#include "arbreDeHuffman.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#define TRUE 1
#define FALSE 0
#define estSup 1
#define estInf 0

ADH_arbreDeHuffman ADH_creerArbreDeHuffmanVide(){
	return NULL;
}



ADH_arbreDeHuffman ADH_creerArbreDeHuffman(octet octetAAjoute, int ponderation){
	ADH_arbreDeHuffman arbreRes=(ADH_arbreDeHuffman)malloc(sizeof(ADH_Racine));
	arbreRes->Racine.ponderation=ponderation;
	OCT_copierOctet(octetAAjoute,&(arbreRes->Racine.valeurOctet));
	arbreRes->filsDroit=ADH_creerArbreDeHuffmanVide();
	arbreRes->filsGauche=ADH_creerArbreDeHuffmanVide();
	return arbreRes;
}

int ADH_estVide(ADH_arbreDeHuffman a){	
		return a==NULL;
}

int ADH_estUneFeuille(ADH_arbreDeHuffman a){
	assert(ADH_estVide(a)!=TRUE);
	if ( ADH_estVide(ADH_obtenirFilsDroit(a)) && ADH_estVide(ADH_obtenirFilsGauche(a)) )
	{

		return TRUE;
	}
	else
		return FALSE;
}

ADH_valeurRacine ADH_obtenirPere(ADH_arbreDeHuffman a){
	assert(ADH_estVide(a)!=TRUE);
	return a->Racine;
}

ADH_arbreDeHuffman ADH_obtenirFilsDroit(ADH_arbreDeHuffman a){
	assert(!ADH_estVide(a));
	return a->filsDroit;
}

ADH_arbreDeHuffman ADH_obtenirFilsGauche(ADH_arbreDeHuffman a){
	assert(!ADH_estVide(a));
	return a->filsGauche;
}

ADH_arbreDeHuffman ADH_fusionnerArbreDeHuffman(ADH_arbreDeHuffman arbre1,ADH_arbreDeHuffman arbre2){
	assert(!ADH_estVide(arbre1) && !ADH_estVide(arbre2));
	ADH_arbreDeHuffman arbreRes=ADH_creerArbreDeHuffman(OCT_creerOctet(),arbre1->Racine.ponderation+arbre2->Racine.ponderation);
	arbreRes->filsDroit = arbre1;
	arbreRes->filsGauche = arbre2;	
	return arbreRes;
}

int ADH_comparerArbreDeHuffman(ADH_arbreDeHuffman arbre1, ADH_arbreDeHuffman arbre2){
	assert (!ADH_estVide(arbre1) && !ADH_estVide(arbre2));
	if(arbre1->Racine.ponderation >= arbre2->Racine.ponderation)
		return estSup;
	else
		return estInf;		
}

void ADH_supprimerPere(ADH_arbreDeHuffman* arbre, ADH_arbreDeHuffman* filsDroit, ADH_arbreDeHuffman *filsGauche){
	assert(!ADH_estVide(*arbre));
	if (!ADH_estUneFeuille(*arbre)){
			*filsDroit=ADH_obtenirFilsDroit(*arbre);
			*filsGauche=ADH_obtenirFilsGauche(*arbre);				
		}
	else 
	{
		*filsDroit=ADH_creerArbreDeHuffmanVide();
		*filsGauche=ADH_creerArbreDeHuffmanVide();	
	}
		ADHAD_desallouerArbre(*arbre);		
	}
	
void ADH_supprimerArbre(ADH_arbreDeHuffman* arbre){
	ADH_arbreDeHuffman filsDroit,filsGauche;
	if (!ADH_estVide(*arbre)){
		if (!ADH_estUneFeuille(*arbre))
		{
			ADH_supprimerPere(arbre,&filsDroit,&filsGauche);
			if (!ADH_estVide(filsDroit)){
				ADH_supprimerArbre(&filsDroit);
			}
			if (!ADH_estVide(filsGauche)){
				ADH_supprimerArbre(&filsGauche);
			}
				
		}
		else ADH_supprimerPere(arbre,&filsDroit,&filsGauche);
	}
}

int ADH_longueur(ADH_arbreDeHuffman arbre){
	if (ADH_estVide(arbre)) 
	{
		return 0;
	}
	else return max(ADH_longueur(ADH_obtenirFilsDroit(arbre)), ADH_longueur(ADH_obtenirFilsGauche(arbre)) )+1;
	
}

int max(int a, int b)
{
	if (a>b) 
		{
			return a;
		}
	else return b;
}
