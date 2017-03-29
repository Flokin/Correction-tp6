#include "col_chaine.h"
#include <string.h>
#include <iostream>

using namespace std;

col_chaine::col_chaine(int mnbc, int mnbi)
{
	max_nbc=mnbc;
	max_nbi=mnbi;

	D=new char[mnbc];
	I=new char *[mnbi];

	nbc=0;
	nbi=0;
}


col_chaine::~col_chaine()
{
	delete [] D;
	delete [] I;
}

bool col_chaine::ajout(char *s)
{
	int nbcr=max_nbc-nbc;
	int l=strlen(s)+1;


	if(l>nbcr || nbi==max_nbi) return false;
	if(nbi==0) I[nbi]=D;
	else I[nbi]=I[nbi-1]+l;
	strcpy(I[nbi],s);
	nbi++;
	nbc+=l;
}

void col_chaine::afficher()
{
	for(int i=0;i<nbi;i++) cout<<I[i]<<" ";
	cout<<endl;
}

bool col_chaine::present(char *s)
{
	for(int i=0;i<nbi;i++)
	{
		if(strcmp(s,I[i])==0) return true;
	}
	return false;
}

void col_chaine::etendre(int f)
{
	// c'est pratique, mais je ne sais pas si c'est de bon usage
	col_chaine *C=new col_chaine(f*max_nbc,f*max_nbi);
	for(int i=0;i<nbi;i++) (*C).ajout(I[i]);
	delete [] D;
	delete [] I;
	D=(*C).D;
	I=(*C).I;
}

int col_chaine::leplusgrand(int n)
{
	int ip=0;
	for(int i=0;i<n;i++)
	{
		if(strcmp(I[i],I[ip])>0) ip=i;
	}
	return ip;
}

void col_chaine::trier()
{
	for(int n=nbi;n>1;n--)
	{
		int ip=leplusgrand(n);
		char *aux=I[ip];
		I[ip]=I[n-1];
		I[n-1]=aux;
	}
}

bool col_chaine::present_trie(char *s)
{
	if(strcmp(s,I[0])<0 || strcmp(s,I[nbi-1])>0 ) return false;
	int d=0,f=nbi;
	while((f-d)>1)
	{
		int m=(f+d)/2;
		if(strcmp(s,I[m])<0) f=m;
		else d=m;
	}
	if(strcmp(s,I[d])==0) return true;
	else return false;
}

bool col_chaine::operator==(col_chaine & C)
{
	for(int i=0;i<nbi;i++)
	{
		if(!C.present(I[i]))
		{
		return false;
		}
	}
	for(int i=0;i<C.nbi;i++)
	{
		if(!present(C.I[i]))
		{
			return false;
		}
	}
	return true;
}

col_chaine & col_chaine::operator<<(char*s)
{
	(*this).ajout(s);
	return(*this);
}

/*

col_chaine & operator >> (char*s,col_chaine & o)
{
	o.ajout(s);
	return o
}
*/








