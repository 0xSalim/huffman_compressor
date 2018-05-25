#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#define NB_PARAMS 3
#define TAILLE_EXT 5
#include "fichierBinaire.h"
#include "S_donneeNoeud_AD.h"
#include "estCompresible.h"
#include "estCompresse.h"

#include "compresser.h"
#include "decompresser.h"

int comparerDeuxChaines(char* chaine1,char* chaine2)
{
	int res=1;
	unsigned int i=0;
    if( strlen(chaine1) != strlen(chaine2) )
    {
        res=0;
	}
	else
	{
		for(i=0;i<strlen(chaine1);i++)
		{
			if( chaine1[i] != chaine2[i])
			{
				res=0;
			}
		}
	}
	return res;
}

int main (int argc, char *argv[])
{
	char* nom_res;
	FichierBinaire fichierSource, fichierDest;

	if (argc!=NB_PARAMS)
	{
		if (argc>NB_PARAMS)
		{
			printf ("\nVous avez entré trop de paramètres.");
			printf("\nVeuillez indiquer en premier l'action que vous souhaitez effectuer puis le fichier a traiter.");
			printf("\nUtilisez c pour compresser et d pour décompresser.");
			return EXIT_FAILURE;
		}
		else
		{
			printf("\n Vous n'avez pas entré assez de paramètres.");
			printf("\n Veuillez indiquer en premier l'action que vous souhaitez effectuer puis le fichier a traiter.");
			printf("\n Utilisez c pour compresser et d pour décompresser.");
			return EXIT_FAILURE;
		}
	}
	/// La vérification d'existence du fichier se fera lors de la compression/décompression (vérifier que FOPEN!=NULL)

	if (comparerDeuxChaines(argv[1],"c"))
	{
		printf("\n Vous avez choisit de compresser le fichier %s. " ,argv[NB_PARAMS-1]);

		nom_res=(char*)malloc(sizeof(char*)*(strlen(argv[NB_PARAMS-1])+TAILLE_EXT));
		memcpy(nom_res,argv[NB_PARAMS-1],strlen(argv[NB_PARAMS-1]));  /// On copie le nom du fichier source dans le fichier destination
		strcat(nom_res,".huff"); 												/// ajout de l'extension .huff dans le nom du fichier destination
		fichierSource=FB_ouvrir(argv[NB_PARAMS-1],lecture); 					/// Ouverture du fihcier source en mode lecture
		if (fichierSource==NULL)
		{
			printf("Le fichier %s n'existe pas!", argv[NB_PARAMS-1]); /// Vérification de l'existence du fichier source
		}
		else if (!(estCompressible(&fichierSource,SDNAD_copierDonneeNoeud,SDNAD_comparerDonneeNoeud)))
		{
			printf("Le fichier %s n'est pas compressible car déjà compressé!", argv[NB_PARAMS-1]); /// Le fichier source est-il compressible?
			FB_fermer(&fichierSource);
		}
		else
		{
			fichierDest=FB_fichierBinaire(nom_res);									/// Creation du fichier de destination (vérifier si il n'existait pas avant?
			fichierDest=FB_ouvrir(nom_res,ecriture);								/// ouverture du fichier de destination en mode écriture
			compresser(fichierSource,&fichierDest);									/// Compression
			FB_fermer(&fichierDest); 												/// Fermeture du fichier de destination
		}
		//FB_fermer(&fichierSource);	/// Fermeture du fichier Source
	}
	else if (comparerDeuxChaines(argv[1],"d"))
	{
		printf("\n Vous avez choisit de décompresser le fichier %s. ",argv[NB_PARAMS-1]);
		nom_res=(char*)malloc(sizeof(char*)*(strlen(argv[NB_PARAMS-1])+11-TAILLE_EXT));

		fichierSource=FB_ouvrir(argv[NB_PARAMS-1],lecture);	/// Ouverture du fichier source en mode lecture
		if (fichierSource==NULL)
		{
			printf("\n Le fichier %s n'existe pas!", argv[NB_PARAMS-1]); /// Vérification de l'existence du fichier source
		}
		else if (!(estCompres(&fichierSource,SDNAD_copierDonneeNoeud,SDNAD_comparerDonneeNoeud)))
		{
			printf("\n Le fichier %s n'est pas compressé!", argv[NB_PARAMS-1]); /// Le fichier source est-il compressible?
			FB_fermer(&fichierSource);
		}
		else
		{
			memcpy(nom_res,argv[NB_PARAMS-1],strlen(argv[NB_PARAMS-1])-TAILLE_EXT);  /// On copie le nom du fichier source en enlevant l'extension
			strcat(nom_res,"_decompresse");
			fichierDest=FB_fichierBinaire(nom_res);									/// Creation du fichier de destination (vérifier si il n'existait pas avant?
			fichierDest=FB_ouvrir(nom_res,ecriture);								/// ouverture du fichier de destination en mode écriture
			decompresser(fichierSource,&fichierDest);								/// Décompression
			FB_fermer(&fichierDest);
			FB_fermer(&fichierSource); 												/// Fermeture du fichier de destination
		}
		//FB_fermer(&fichierSource);	/// Fermeture du fichier Source
	}
	else
	{
		printf("\n L'action que vous souhaitez effectuer sur ce fichier n'existe pas.");
		printf("\n Utilisez c pour compresser et d pour décompresser.");
		return EXIT_FAILURE;
	}
	free(nom_res);
	return EXIT_SUCCESS;
}
