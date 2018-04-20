struct mapa{
	char** matriz;
	int linhas;
	int colunas;
};

typedef struct mapa MAPA;

void lerMapa(MAPA* m);
void alocaMapa(MAPA* m);
void imprimeMapa(MAPA* m);