#include "S_donneeNoeud_AD.h"


void* SDNAD_copierDonneeNoeud(void* e)
{
	S_donneeNoeud* res=(S_donneeNoeud*)malloc(sizeof(S_donneeNoeud));
	memcpy((void*)res,e,sizeof(S_donneeNoeud));
	return res;
}

void SDNAD_desallouerDonneeNoeud(void* e)
{
	free(e);
}

int SDNAD_comparerDonneeNoeud(void* e1,void* e2)
{
	return OCT_octetEgaux(((S_donneeNoeud*)(e1))->loctet,((S_donneeNoeud*)(e2))->loctet);
}
