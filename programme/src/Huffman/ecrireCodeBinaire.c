
#include "ecrireCodeBinaire.h"

void ecrireCodeBinaire(FichierBinaire* fichierFinal, FichierBinaire source, TableDeCodage table,unsigned long long *nb){
  CodeBinaire code=CB_creerCodeBinaireVide();
  CodeBinaire codeTemp=CB_creerCodeBinaireVide();

  octet octetTemp = OCT_creerOctet();
  int i;
  while ( !(FB_finFichier(source)) && FB_lireOctet(source,&octetTemp) )
  {
		codeTemp=CB_copierCodeBinaire(TDC_obtenirCode(table,octetTemp,BAD_copierBit),BAD_copierBit);
		///printf("\n%s %d\n","longueur du code binaire temp: ",CB_obtenirLongueur(codeTemp));
		CB_concatener(&code,codeTemp);
		octetTemp = OCT_creerOctet();
		///printf("\n%s %d\n","longueur du code binaire : ",CB_obtenirLongueur(code));
		if ((CB_obtenirLongueur(code)>=NB_MAX_BITS))
		{
			for (i=0;i<NB_MAX_BITS;i++)
			{
				OCT_fixeriemeBit(&octetTemp,i,copierBit(CB_obtenirBit(code)));
				CB_supprimerTete(&code,BAD_desallouerBit);
			}
			FB_ecrireOctet(fichierFinal,octetTemp);
			*nb=*nb+NB_MAX_BITS;

		}

	}
	
	int l=0;
	l=CB_obtenirLongueur(code);
	if (!CB_estVide(code))
	{
			octetTemp = OCT_creerOctet();
			for (i=0;i<l;i++)
			{
				OCT_fixeriemeBit(&octetTemp,i,copierBit(CB_obtenirBit(code)));
				CB_supprimerTete(&code,BAD_desallouerBit);
				*nb=*nb+1;
			}
		
			FB_ecrireOctet(fichierFinal,octetTemp);
			
	}
	///CB_supprimer(&codeTemp,BAD_desallouerBit);
  }
