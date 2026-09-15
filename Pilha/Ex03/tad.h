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

void Polonesa(TpPilha P1, char expressao[20]) {
	int n1, n2, resultado;
	for(int i = 0; expressao[i] != '\0'; i++) {
		if(expressao[i] == '+' ) {
			n2 = Desempilhar(P1); n1 = Desempilhar(P1);
			resultado = n1 + n2; Empilhar(P1, resultado);
		}
		else if(expressao[i] == '-' ) {
			n2 = Desempilhar(P1); n1 = Desempilhar(P1);
			resultado = n1 - n2; Empilhar(P1, resultado);
		}
		else if(expressao[i] == '*' ) {
			n1 = Desempilhar(P1); n2 = Desempilhar(P1);
			resultado = n1 * n2; Empilhar(P1, resultado);
		}
		else if(expressao[i] == '/' ) {
			n2 = Desempilhar(P1); n1 = Desempilhar(P1);
			resultado = n1 / n2; Empilhar(P1, resultado);
		}
		else {
			int num1 = expressao[i] - '0';
			Empilhar(P1,num1);
		}
	}
	resultado = Desempilhar(P1);
	printf("Resultado:  %d\n", resultado);
}
