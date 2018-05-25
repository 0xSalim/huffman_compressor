#include "Octet.h"


#define TRUE 1
#define FALSE 0

int OCT_octetEnDecimal (octet oct)
{
	int i;
	int res=0;
	for (i=NB_MAX_BITS-1;i>=0;i--)
	{
	res=res+bit_en_int(oct.lesBits[NB_MAX_BITS-i-1])*(int)pow((double)2,(double)i);
	}
	return res;
}


octet OCT_creerOctet(){
    octet resultat;
    int i;

		for(i=0;i<NB_MAX_BITS;i++){
        resultat.lesBits[i]=b0;
 }
    return resultat;


}

bit OCT_obteniriemeBit(octet UnOctet, int i){
    assert(i<=NB_MAX_BITS);
    return UnOctet.lesBits[i];
}

int OCT_octetEgaux(octet Octet1,octet Octet2){
    int i,resultat=TRUE;
    for(i=0;i<NB_MAX_BITS;i++){
        if (Octet1.lesBits[i]!=Octet2.lesBits[i]){
            resultat=FALSE;
        }
    }
    return resultat;
}

void OCT_fixeriemeBit(octet* UnOctet, int i,bit UnBit){
    UnOctet->lesBits[i]=UnBit;
}



octet OCT_decimalEnOctet(int dec){
	assert(dec>=0 && dec<=255);
	int i;
	octet res;
	int temp=dec;
	int coeff;
	for (i=NB_MAX_BITS-1;i>=0;i--)
	{
		coeff=(int)pow((double)2,(double)i);
		OCT_fixeriemeBit(&res,NB_MAX_BITS-i-1,int_en_bit(temp/coeff));
		temp=temp-coeff*(temp/coeff);
	}
	return res;
}

void OCT_copierOctet(octet source,octet* dest)
{

	int i;
	for (i=0;i<NB_MAX_BITS;i++)
	{
		OCT_fixeriemeBit(dest,i,OCT_obteniriemeBit(source,i));
	}
}
