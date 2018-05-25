

#include "genererTDCaPartirDeStats.h"

TableDeCodage genererTableDeCodageAPartirDeStats(S_Statistiques stats){

	FDP_FileDePriorite file;
	ADH_arbreDeHuffman arbre;
	TableDeCodage table=TDC_tableDeCodageVide();

	file=genererFileDePriorite(stats,1);

	arbre=genererArbreDeHuffman(&file,ADHAD_copierArbre);
	
	FDP_supprimer(&file,ADHAD_desallouerArbre);
	
	table=genererTDCaPartirDeADH(arbre);
	ADH_supprimerArbre(&arbre);
	return(table);
}
