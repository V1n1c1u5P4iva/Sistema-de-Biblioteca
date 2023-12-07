#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "sistemabiblioteca.h"

int main(){
	int op,d_ent,m_ent,a_ent;
	char v[100],livro[100];
	Lista* l;
	Lista* b;
	l = lst_cria();
	setlocale(LC_ALL, "Portuguese");
	do{
		system("CLS");
		menu();
		scanf("%d", &op);
		switch (op){
			case 1:
				printf("Digite o nome do leitor: ");
				scanf(" %99[^\n]", v);
				printf("Digite o nome do livro a ser emprestado: ");
				scanf(" %99[^\n]", livro);
				printf("Digite a data de devolução do livro (dia, mês e ano): ");
				scanf("%d%d%d",&d_ent,&m_ent,&a_ent);
				l = lst_insere(l, v,livro,d_ent,m_ent,a_ent);
				break;
			case 2:
				printf("Digite o nome do leitor para buscar: ");
				scanf(" %99[^\n]", v);
				b = lst_busca(l, v);
				if (b == NULL)
					printf("Leitor não encontrado!\n");
				else
					printf("Leitor encontrado!\n");
					printf("Nome do leitor: %s\n",v);
					printf("Livro emprestado: %s\n",livro);
				system("PAUSE");
				break;
			case 3:
				printf("Digite o nome do leitor para registrar a devolução do livro: ");
				scanf(" %99[^\n]", v);
				b = lst_busca(l, v);
				l = lst_retira(l, v);
				if (b == NULL)
					printf("Leitor não encontrado!\n");
				else
					printf("O livro foi devolvido pelo leitor.\n");
				system("PAUSE");
				break;
			case 4:
				lst_imprime(l);
				system("PAUSE");
				break;
			default:
				break;
		}
	} while (op != 5);
	return 0;
}
