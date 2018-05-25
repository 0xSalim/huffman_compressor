#include "genererStats.h"

S_Statistiques genererStats(FichierBinaire source){
  octet octetTemp;
  S_Statistiques stats=S_creerVide();
  FB_deplacerCurseur(&source,0);
  int a=0;
  int i=0;
  while(!FB_finFichier(source) && FB_lireOctet(source, &octetTemp)) 
  {
	  if (!(S_estPresent(stats,octetTemp,SDNAD_comparerDonneeNoeud)))
		{
			S_ajouterItem(&stats, octetTemp,1,SDNAD_copierDonneeNoeud,SDNAD_comparerDonneeNoeud);
			a++;
			
			
		}
	else
	{
		S_fixerOccurencesItem(stats,octetTemp,S_nombreOccurencesItem(stats,octetTemp,SDNAD_comparerDonneeNoeud)+1,SDNAD_copierDonneeNoeud,SDNAD_desallouerDonneeNoeud,SDNAD_comparerDonneeNoeud);
		i++;

	}
	
  }
  printf("\n%s %d %s %d %s\n","total de ",i+a,"octets, avec ",a,"octets différents");
  return stats;
}

