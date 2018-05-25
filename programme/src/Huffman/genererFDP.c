#include "genererFDP.h"

FDP_FileDePriorite genererFileDePriorite(S_Statistiques stats, int param){
	LC_ListeChainee listeTemp=S_obtenirLesStats(stats); /// On garde en mémoire le premier élément dde la liste chainée de données noeud.
    FDP_FileDePriorite fdp=FDP_creerVide();
    ADH_arbreDeHuffman adh;
    int ponderation;
    octet oct;
    int nb=S_obtenirTaille(stats);
    int i=0;
	
	while (!S_estVide(stats))
	{
			oct=S_obtenirOctet(stats);
			ponderation=S_nombreOccurencesItem(stats,oct,BAD_comparerBit);
			S_obtenirStatSuivante(&stats);
			
            adh=ADH_creerArbreDeHuffman(oct,ponderation);
            FDP_insererItem(adh,&fdp,ADHAD_copierArbre,param);
            i++;
		

	}
	S_fixerLesStats(&stats,listeTemp);
	stats.taille=nb;


    return fdp;
}
