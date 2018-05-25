#include "FileDePriorite.h"
#include "arbreDeHuffman.h"
#include "ListeChainee.h"
#include "copieLiberationComparaison.h"
#include "arbre_allocation_dynamique.h"

FDP_FileDePriorite FDP_creerVide(){
    return (FDP_FileDePriorite) LC_ListeChaineeVide();
}

int FDP_estVide(FDP_FileDePriorite file){
    return LC_estVide(file);
}


void FDP_defiler(FDP_FileDePriorite* file,CLC_FonctionLiberer desallouerArbre){
    assert(!FDP_estVide(*file));
    LC_supprimerTete(file,  desallouerArbre);
}


void FDP_supprimer(FDP_FileDePriorite* file,CLC_FonctionLiberer desallouerArbre){
	while (!FDP_estVide(*file)){
		FDP_defiler(file,desallouerArbre);
	}
}

void FDP_insererItem(ADH_arbreDeHuffman item, FDP_FileDePriorite* file,CLC_FonctionCopier copierArbre,int param){
    FDP_FileDePriorite tmp;
    if (param)
    {
		if (FDP_estVide(*file) || FDP_obtenirTete(*file)->Racine.ponderation>item->Racine.ponderation)
		{
			LC_ajouter(file, &item, copierArbre);
		}
		else
		{
			tmp=(FDP_FileDePriorite)LC_obtenirListeSuivante(*file);
			FDP_insererItem(item,&tmp,ADHAD_copierArbre,param);
			LC_fixerListeSuivante(file, tmp);
		}
    }
    else
    {
		if (FDP_estVide(*file) || FDP_obtenirTete(*file)->Racine.ponderation>=item->Racine.ponderation)
		{
			LC_ajouter(file, &item, copierArbre);
		}
		else
		{
			tmp=(FDP_FileDePriorite)LC_obtenirListeSuivante(*file);
			FDP_insererItem(item,&tmp,ADHAD_copierArbre,param);
			LC_fixerListeSuivante(file, tmp);
		}
    }
}

ADH_arbreDeHuffman FDP_obtenirTete(FDP_FileDePriorite file){
    assert(!FDP_estVide(file));
    ADH_arbreDeHuffman* resultat;
    resultat=(ADH_arbreDeHuffman*) LC_obtenirElement(file);
    return *resultat;
}

int FDP_longueur(FDP_FileDePriorite file){
    int resultat=0;
    FDP_FileDePriorite tmp=file;
    while (!FDP_estVide(tmp)){
        tmp=LC_obtenirListeSuivante(tmp);
        resultat++;
    }
    return resultat;
}
