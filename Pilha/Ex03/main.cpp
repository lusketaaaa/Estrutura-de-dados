#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio2.h>
#include <windows.h>

#include "tad_pilha.h"


void Menu() {
	TpPilha P1, P2, P3;
	char expressao[20];
	char op;
	clrscr();
	op = toupper(getche());
	do {
		clrscr();
		printf("# # # SIMULADOR DE PILHAS # # #\n");
		printf("[A] Inicializar P1\n");
		printf("[B] Ler Expressao\n");
		printf("[ESC] Sair\n");
		printf("Resposta: ");
		switch(op) {
			case 'A': Inicializar(P1); break;
			case 'B': 
				printf("Digite a expressao: ");
				gets(expressao);
				Polonesa(P1, expressao);
		}
	} while(op != 27)
}

int main(void) {
	Menu();
	
	
	return 0;
}
