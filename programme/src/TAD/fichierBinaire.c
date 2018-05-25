#define _POSIX_SOURCE

#include "fichierBinaire.h"


FichierBinaire FB_fichierBinaire(char nom[])
{
		FILE *fh = fopen(nom, "w");
		fclose(fh);
 
		return fh;
}


FichierBinaire FB_ouvrir(char nom[], FBmode mode) {
  FichierBinaire res = NULL;

  errno = 0;

  switch (mode) {
  case ecriture :
    res = fopen(nom, "wb");
    break;

  case lecture :
    res = fopen(nom, "rb");
    break;
  default :
    errno = FB_ERREUR_OUVERTURE;
    break;
  }

  if (res == NULL) errno = FB_ERREUR_OUVERTURE;

  return res;
}

void FB_fermer(FichierBinaire* f) {
  fclose(*f);
}

int FB_finFichier(FichierBinaire f) {
  return feof(f);
}

void FB_ecrireOctet(FichierBinaire* f, octet o) {
	int valeur=OCT_octetEnDecimal(o);
  fwrite(&valeur, sizeof(unsigned char), 1, *f);
}

int FB_lireOctet(FichierBinaire f, octet* o) {
	int valeur=0;
  int res = fread(&valeur, sizeof(unsigned char), 1, f);
  *o=OCT_decimalEnOctet(valeur);
  return res;
}

void FB_ecrireNaturel(FichierBinaire* f, int n) {
  fwrite(&n, sizeof(int), 1, *f);
}

int FB_lireNaturel(FichierBinaire f, int* naturel) {
  return fread(naturel, sizeof(int), 1, f);
}

void FB_ecrireGrosNaturel(FichierBinaire* f,unsigned long long n){
  fwrite(&n, sizeof(unsigned long long), 1, *f);
}

int FB_lireGrosNaturel(FichierBinaire f, unsigned long long* n) {
  return fread(n, sizeof(unsigned long long), 1, f);
}



void FB_ecrireCaractere(FichierBinaire* f, char c) {
  fwrite(&c, sizeof(char), 1, *f);
}

int FB_lireCaractere(FichierBinaire f, char* caractere) {
  return fread(caractere, sizeof(char), 1, f);
}


int FB_longueurFichier(FichierBinaire f) {
  struct stat fileStat;

  fstat(fileno(f), &fileStat);
  return fileStat.st_size;
}


void FB_ecrireChaine(FichierBinaire* f, char* chaine) {
  int i;
  for (i=0; i <= strlen(chaine)-1; i++) {
    FB_ecrireCaractere(f, chaine[i]);
  }
}

char* FB_lireChaine(FichierBinaire f, int n) {
  char* res = (char*) malloc((n+1) * sizeof(char));
  int i = 0;

  while (i <= (n-1) && !FB_finFichier(f) && FB_lireCaractere(f, &res[i])) {
    i++;
  }

  res[i+1] = '\0';
  return res;
}


void FB_deplacerCurseur(FichierBinaire* f, long position) {
  fseek(*f, position, SEEK_SET);
}

void FB_deplacerCurseurPourTrouverTaille(FichierBinaire* f) {
  fseek(*f, -sizeof(unsigned long long), SEEK_END);
}
/*
int main(){
	unsigned long long a=2800000000;
	unsigned long long b=0;
	FichierBinaire fic;
	fic=FB_ouvrir("test",ecriture);
	FB_ecrireGrosNaturel(&fic,a);
	FB_fermer(&fic);
	fic=FB_ouvrir("test",lecture);
	if (FB_lireGrosNaturel(fic,&b)){
		printf("%llu",b);
	}
	FB_fermer(&fic);
}
* */
	
