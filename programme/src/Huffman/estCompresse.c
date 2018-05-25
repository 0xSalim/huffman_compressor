
#include "estCompresse.h"


int estCompres(FichierBinaire* fic,CLC_FonctionCopier copierDonneNoeud,CLC_FonctionComparer comparerDonneNoeud){
	octet bonCode=genererBonCode();
	octet codeFic=recupererCodeIdentification(*fic);
	return OCT_octetEgaux(codeFic,bonCode);
}


