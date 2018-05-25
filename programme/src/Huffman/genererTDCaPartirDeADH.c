
#include "genererTDCaPartirDeADH.h"

TableDeCodage genererTDCaPartirDeADH(ADH_arbreDeHuffman arbre){
    TableDeCodage table=TDC_tableDeCodageVide();
    CodeBinaire code;
    code=CB_creerCodeBinaireVide();
    chercherFeuilleRecursivement(arbre,&table,&code,BAD_copierBit);
    return table;
}

void chercherFeuilleRecursivement(ADH_arbreDeHuffman arbre, TableDeCodage *table, CodeBinaire *code,CLC_FonctionCopier copierBit){
    ADH_arbreDeHuffman filsGauche, filsDroit;

    CodeBinaire codeTemp=CB_copierCodeBinaire(*code,copierBit);

    if (!(ADH_estVide(arbre))){
    if (ADH_estUneFeuille(arbre))
    {
        TDC_fixerCodeElement(ADH_obtenirPere(arbre).valeurOctet,*code,table,copierBit);

    }
    else
    {
      filsGauche=ADH_obtenirFilsGauche(arbre);
      filsDroit=ADH_obtenirFilsDroit(arbre);
      CB_ajouterAlaFin(code,b0,copierBit);
      chercherFeuilleRecursivement(filsGauche, table, code,copierBit);
  
      CB_ajouterAlaFin(&codeTemp,b1,copierBit);
      chercherFeuilleRecursivement(filsDroit, table, &codeTemp,copierBit);
    
    }
	}
	CB_supprimer(&codeTemp,BAD_desallouerBit);
}
