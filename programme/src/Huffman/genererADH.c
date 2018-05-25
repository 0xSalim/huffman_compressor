
#include "GenererADH.h"


ADH_arbreDeHuffman genererArbreDeHuffman(FDP_FileDePriorite *file,CLC_FonctionCopier copierArbre){
	ADH_arbreDeHuffman res,*aTemp;
    genererArbreRecursivement(file,copierArbre);
   
    res=(ADH_arbreDeHuffman)FDP_obtenirTete(*file);
    aTemp=(ADH_arbreDeHuffman*)ADHAD_copierArbre(&res);
    
    return *aTemp;
}

void genererArbreRecursivement(FDP_FileDePriorite *file,CLC_FonctionCopier copierArbre){
	ADH_arbreDeHuffman *a1,*a2,a,atemp;
	
    if(!(FDP_estVide(*file)))
    {
		atemp=(ADH_arbreDeHuffman)FDP_obtenirTete(*file);
		a1=(ADH_arbreDeHuffman*)ADHAD_copierArbre(&atemp);
		FDP_defiler(file,ADHAD_desallouerArbre);
		if (!(FDP_estVide(*file)))
		{
			atemp=(ADH_arbreDeHuffman)FDP_obtenirTete(*file);
			a2=(ADH_arbreDeHuffman*)ADHAD_copierArbre(&atemp);
			FDP_defiler(file,ADHAD_desallouerArbre);
			a=ADH_fusionnerArbreDeHuffman(*a1,*a2);
			FDP_insererItem(a, file,copierArbre,1);
			genererArbreRecursivement(file,copierArbre);
		}
		else 
		{
			FDP_insererItem(*a1, file,copierArbre,1);
		}
        
    }

}
