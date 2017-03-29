class col_chaine
{
	char *D;
	char **I;
	int nbc;
	int nbi;
	int max_nbc;
	int max_nbi;

	public:
		col_chaine(int mnbc, int mnbi);
		~col_chaine();
		bool ajout(char *s);
		void afficher();
		bool present(char *s);
		void etendre(int f);
		void trier();
		int leplusgrand(int n);
		bool present_trie(char *s);
		bool operator==(col_chaine & C);
		col_chaine & operator <<(char*s);
		//friend col_chaine & operator >>(char*s,col_chaine & o);

};

