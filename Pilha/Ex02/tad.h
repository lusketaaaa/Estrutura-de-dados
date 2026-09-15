#define MAX 20

struct TpPilha {
	int Topo;
	int Pilha[MAX];
};

// tad basico da pilha
void Inicializar(TpPilha &p) {
	p.Topo = -1;
}

void Empilhar(TpPilha &p, int e) {
	p.Pilha[++p.Topo] = e;
}

int Desempilhar(TpPilha &p) {
	return p.Pilha[p.Topo--];
}

char Cheia(int topo) {
	return topo == MAX-1;
}

char Vazia(int topo) {
	return topo == -1;
}

void Exibir(TpPilha p) {
	while(!Vazia(p.Topo)) 
		printf("%d\n",Desempilhar(p));
}

void Concatenar(TpPilha &P1, TpPilha P2, TpPilha &P3) {
	int num;
	while(!Vazia(P2.Topo) && !Cheia(P3.Topo)) {
		num = Desempilhar(P2);
		Empilhar(P3, num);
	}
	while(!Vazia(P3.Topo) && !Cheia(P1.Topo)) {
		num = Desempilhar(P3);
		Empilhar(P1, num);
	}
}

void Excluir(TpPilha &P1, TpPilha &P2, int elementoex) {
	int elemento;
	while(!Vazia(P1.Topo)) {
		elemento = Desempilhar(P1);
		if(elemento != elementoex)
			Empilhar(P2, elemento);
	}
	while(!Vazia(P2.Topo))
		Empilhar(P1,Desempilhar(P2));
}
