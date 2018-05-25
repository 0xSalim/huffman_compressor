
#include "estCompresse.h"

int estCompressible(FichierBinaire* fic,CLC_FonctionCopier copierDonneNoeud,CLC_FonctionComparer comparerDonneNoeud){
	return !(estCompres(fic,copierDonneNoeud,comparerDonneNoeud));
}

