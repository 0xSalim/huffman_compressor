#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TableDeCodage.h"



TableDeCodage TDC_tableDeCodageVide(){
	//a completer en mettant des valeurs NULL
	TableDeCodage table;
	int i=0;
		//octet tab_Octet[510];
		for(i=0;i<NB_OCT_MAX+1;i++){
			table.CB_EnFonctionDeOctets[i]=CB_creerCodeBinaireVide();

		}
	return table;
}


void TDC_fixerCodeElement(octet element, CodeBinaire mon_code_binaire, TableDeCodage *table,CLC_FonctionCopier copierBit){
	int adresse;

	adresse=OCT_octetEnDecimal(element);
	table->CB_EnFonctionDeOctets[adresse]=CB_copierCodeBinaire(mon_code_binaire,copierBit);
}


CodeBinaire TDC_obtenirCode(TableDeCodage table, octet element,CLC_FonctionCopier copierBit){

	int adresse;
	CodeBinaire *mon_code_binaire;

	adresse=OCT_octetEnDecimal(element);
	mon_code_binaire=&(table.CB_EnFonctionDeOctets[adresse]);
	return *mon_code_binaire;
}


void TDC_supprimer(TableDeCodage* table,CLC_FonctionLiberer libererBit){
	for(int i=1;i<=NB_OCT_MAX+1;i++){
		LC_supprimer(table->CB_EnFonctionDeOctets,libererBit);
	}
}
