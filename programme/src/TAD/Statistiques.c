#include <assert.h>
#include <stdio.h>
#include "copieLiberationComparaison.h"
#include "ListeChainee.h"
#include "Octet.h"
#include "Statistiques.h"
#include "S_donneeNoeud_AD.h"




/// Partie Privee
S_donneeNoeud S_creerDonneeNoeud(octet oct,int ponderation)
{
	S_donneeNoeud res;
	res.loctet=oct;
	res.ponderation=ponderation;
	return res;
}

int S_obtenirTaille(S_Statistiques s)
{
	return s.taille;
}

LC_ListeChainee S_obtenirLesStats(S_Statistiques s)
{
	return s.lesStats;
}
void S_fixerLesStats(S_Statistiques* stats,LC_ListeChainee lesS)
{
	stats->lesStats=lesS;
}

void S_ajouterDonneeNoeud(S_Statistiques* s,S_donneeNoeud donnee, CLC_FonctionCopier copierElement)
{
	LC_ListeChainee l=S_obtenirLesStats(*s);
	LC_ajouter(&l,&donnee,copierElement);
	S_fixerLesStats(s,l);
	s->taille=s->taille+1;
}

S_donneeNoeud S_obtenirDonneeNoeud(S_Statistiques s)
{
	assert(!S_estVide(s));
  S_donneeNoeud *donnee;
  donnee=(S_donneeNoeud*)LC_obtenirElement(S_obtenirLesStats(s));
  return *donnee;
}
octet SDN_obtenirOctet(S_donneeNoeud donnee)
{
  return donnee.loctet;
}

int S_obtenirPonderation(S_donneeNoeud donnee)
{
  return donnee.ponderation;
}


/// Partie Publique
S_Statistiques S_creerVide()
{
  S_Statistiques s;
  s.taille=0;
  s.lesStats=LC_ListeChaineeVide();
	return s;
}

int S_estVide(S_Statistiques s)
{
  return((s.lesStats==NULL) && (s.taille==0));
}

octet S_obtenirOctet(S_Statistiques s)
{
  return SDN_obtenirOctet(S_obtenirDonneeNoeud(s));
}

int S_nombreOccurencesItem(S_Statistiques s,octet oct,CLC_FonctionComparer comparerDonneNoeud)
{
  S_donneeNoeud donnee=S_creerDonneeNoeud(oct,1);
  assert(!LC_estVide(S_obtenirLesStats(s)));
  assert(LC_estPresent(S_obtenirLesStats(s),&donnee,comparerDonneNoeud));
  LC_ListeChainee l=S_obtenirLesStats(s);
  while (!OCT_octetEgaux(SDN_obtenirOctet(*(S_donneeNoeud*)LC_obtenirElement(l)),oct))
    {
      l=LC_obtenirListeSuivante(l);
    }
  return S_obtenirPonderation(*(S_donneeNoeud*)LC_obtenirElement(l));
}

void S_fixerOccurencesItem(S_Statistiques s,octet o,int occurences,CLC_FonctionCopier copierDonnee, CLC_FonctionLiberer libererDonnee,CLC_FonctionComparer comparerDonneNoeud)
{
  S_donneeNoeud donnee=S_creerDonneeNoeud(o,1);
  LC_ListeChainee l=S_obtenirLesStats(s);
  assert(!LC_estVide(S_obtenirLesStats(s)));
  assert(LC_estPresent(l,&donnee,comparerDonneNoeud));
  while (!OCT_octetEgaux(SDN_obtenirOctet(*(S_donneeNoeud*)LC_obtenirElement(l)),o))
    {
      l=LC_obtenirListeSuivante(l);
    }
  donnee=S_creerDonneeNoeud(o,occurences);
  LC_fixerElement(l,&donnee,copierDonnee,libererDonnee);
}

void S_supprimerTete(S_Statistiques* s,CLC_FonctionLiberer libererDonnee)
{
	assert(!S_estVide(*s));
  LC_ListeChainee l=S_obtenirLesStats(*s);
  LC_supprimerTete(&l,libererDonnee);
  S_fixerLesStats(s,l);
  s->taille=s->taille-1;
}

void S_ajouterItem(S_Statistiques* s,octet o,int ponderation,CLC_FonctionCopier copierDonneeNoeud,CLC_FonctionComparer comparerDonneNoeud)
{
  LC_ListeChainee l=S_obtenirLesStats(*s);
  S_donneeNoeud donnee=S_creerDonneeNoeud(o,ponderation);
  assert(!LC_estPresent(l,&donnee,comparerDonneNoeud));
  S_ajouterDonneeNoeud(s,donnee,copierDonneeNoeud);
}

void S_ajouterItemALafin(S_Statistiques *lesStats,octet monOctet,int ponderation,CLC_FonctionCopier copierDonneeNoeud,CLC_FonctionComparer comparerDonneeNoeud)
{
	LC_ListeChainee l,lcTemp=S_obtenirLesStats(*lesStats);
	int i,taille=S_obtenirTaille(*lesStats);
	if (S_estVide(*lesStats))
	{
		S_ajouterItem(lesStats,monOctet,ponderation,copierDonneeNoeud,comparerDonneeNoeud);
		printf("%s","bite");
	}
	else
	{
		l=lcTemp;
		for (i=0;i<taille;i++)
		{
			if (!(LC_estVide(lcTemp)))
			{
			lcTemp=LC_obtenirListeSuivante(lcTemp);
			}
		}
		S_fixerLesStats(lesStats,lcTemp);
		S_ajouterItem(lesStats,monOctet,ponderation,copierDonneeNoeud,comparerDonneeNoeud);
		S_fixerLesStats(lesStats,l);
	}

}

int S_estPresent(S_Statistiques s,octet o,CLC_FonctionComparer comparerDonneeNoeud){
	S_donneeNoeud donnee=S_creerDonneeNoeud(o,1);
	return LC_estPresent(S_obtenirLesStats(s),&donnee,comparerDonneeNoeud);
}

void S_obtenirStatSuivante(S_Statistiques *s)
{
	LC_ListeChainee listeTemp=S_obtenirLesStats(*s);
	listeTemp=LC_obtenirListeSuivante(listeTemp);
	S_fixerLesStats(s,listeTemp);
	s->taille=s->taille-1;

}

void S_supprimer(S_Statistiques* s,CLC_FonctionLiberer libererDonneeNoeud){
	while (!S_estVide(*s) && !LC_estVide(S_obtenirLesStats(*s)))
	{
		S_supprimerTete(s,libererDonneeNoeud);
	}
}
