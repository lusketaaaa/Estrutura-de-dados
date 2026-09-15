#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio2.h>
#include <windows.h>

#include "tad_pilha.h"


void Menu() {
	TpPilha P1, P2, P3;
	char op;
	int elemento;
	clrscr();
	op = toupper(getche());
	do {
		clrscr();
		printf("# # # SIMULADOR DE PILHAS # # #\n");
		printf("[A] Inicializar P1\n");
		printf("[B] Inicializar P2\n");
		printf("[C] Adicionar elemento P1\n");
		printf("[D] Adicionar elemento P2\n");
		printf("[E] Concatenar P1 e P2\n");
		printf("[F] Desempilhar P1\n");
		printf("[G] Desempilhar P2\n");
		printf("[H] Exibir P1\n");
		printf("[I] Exibir P2\n");
		printf("[ESC] Sair\n");
		printf("Resposta: ");
		switch(op) {
			case 'A': Inicializar(P1); break;
			case 'B': Inicializar(P2); break;
			case 'C': 
				if(Cheia(P1))
					printf("Pilha cheia!\n");
				else {
					printf("Digite o elemento: ");
					scanf("%d", &elemento);
					Empilhar(P1, elemento);
				}	break;
			case 'D':
				if(Cheia(P2))
					printf("Pilha cheia!\n");
				else {
					printf("Digite o elemento: ");
					scanf("%d", &elemento);
					Empilhar(P2, elemento);
				}	break;
			case 'E': Concatenar(P1,P2,P3); break;
			case 'F': Desempilhar(P1); break;
			case 'G': Desempilhar(P2); break;
			case 'H': Exibir(P1); break;
			case 'I': Exibir(P2); break;
		}
	} while(op != 27)
}

int main(void) {
	Menu();
	
	
	return 0;
}
