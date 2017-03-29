#include "col_chaine.h"
#include "col_chaine.cpp"
#include <iostream>

using namespace std;

int main()
{

	col_chaine C(100,6);

	char s[10]="toto";
	char s1[10]="tata";
	char s2[10]="titi";
	char s3[10]="tutu";
	char s4[10]="tete";
	char s5[10]="titi";

	C.ajout(s);
	C.ajout(s1);
	C.ajout(s2);
	//C.ajout(s3);
	C.ajout(s4);
	C.ajout(s5);

	C.afficher();
	C.trier();

	if(C.present_trie(s3)) cout<<"oui"<<endl;
	else cout<<"non"<<endl;

	//C.etendre(2);

	//C.afficher();
	
	col_chaine(300,20);
	//C1.ajout(ss2);
	//C1.ajout(ss4);
	//C1.ajout(ss5);
	
	//if(C1==C) cout<<"egal"<<endl;
	//else cout<<"non egal"<<endl;
	char t[10]="matrouf";
	C<<s5<<A;
	C.afficher();
	//C.afficher();
}

