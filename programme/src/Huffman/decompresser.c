
#include "decompresser.h"


void decompresser(FichierBinaire fichierCompresse, FichierBinaire* fichierDecompresse){
	enTete monEnTete;
	FDP_FileDePriorite maFile;
	ADH_arbreDeHuffman monArbre;
	unsigned long long taille=0;
	FB_deplacerCurseur(&fichierCompresse,0);
	FB_deplacerCurseur(fichierDecompresse,0);
	
	
	FB_deplacerCurseurPourTrouverTaille(&fichierCompresse); /// On va chercher les 8 derniers octets qui correspondent à la longueur du fichier
	FB_lireGrosNaturel(fichierCompresse,&taille);
	FB_deplacerCurseur(&fichierCompresse,0);  /// Remise à 0 pour lecture de l'en tête
	monEnTete = recupererEnTete(fichierCompresse,SDNAD_copierDonneeNoeud,SDNAD_comparerDonneeNoeud);
	
	
	maFile = genererFileDePriorite(monEnTete.lesStats,0);
	monArbre = genererArbreDeHuffman(&maFile, ADHAD_copierArbre);
	
	
	decoder(monArbre,fichierCompresse,fichierDecompresse,taille,BAD_copierBit,BAD_desallouerBit);
}

