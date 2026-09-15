#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio2.h>
#include <windows.h>

#include "tad_pilha.h"


void Menu() {
	TpPilha P1, P2, P3;
	char op;
	int elemento, elementoex;
	clrscr();
	op = toupper(getche());
	do {
		clrscr();
		printf("# # # SIMULADOR DE PILHAS # # #\n");
		printf("[A] Inicializar P1\n");
		printf("[B] Adicionar elemento P1\n");
		printf("[C] Desempilhar P1\n");
		printf("[D] Exibir P1\n");
		printf("[E] Excluir Elemento\n");
		printf("[ESC] Sair\n");
		printf("Resposta: ");
		switch(op) {
			case 'A': Inicializar(P1); break;
			case 'B': 
				if(Cheia(P1))
					printf("Pilha cheia!\n");
				else {
					printf("Digite o elemento: ");
					scanf("%d", &elemento);
					Empilhar(P1, elemento);
				}	break;
			case 'C': Desempilhar(P1); break;
			case 'D': Exibir(P1); break;
			case 'E':
				printf("Digite o elemento que deseja excluir: ");
				scanf("%d", &elementoex);
				Inicializar(P2);
				Excluir(P1, P2, elementoex);
		}
	} while(op != 27)
}

int main(void) {
	Menu();
	
	
	return 0;
}
