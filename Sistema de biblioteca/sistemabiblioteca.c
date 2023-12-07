#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sistemabiblioteca.h"

struct lista{
	char nome[100];
	char nome_livro[100];
	int dia,mes,ano;
	struct lista* prox;
};

Lista* lst_cria(void){
	return NULL;
}

Lista* lst_insere(Lista* l, char* v,char *livro,int d_ent,int m_ent,int a_ent){
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	strcpy(novo->nome, v);
	strcpy(novo->nome_livro,livro);
	novo->dia=d_ent;
	novo->mes=m_ent;
	novo->ano=a_ent;
	novo->prox = NULL;
	
	if(l==NULL){
		return novo;
	}else
	{
		Lista* p = l;
		while(p->prox!=NULL)
		{
			p=p->prox;
		}
		p->prox=novo;
		return l;
	}
}

void lst_imprime(Lista* l){
    Lista* p;
    for (p = l; p != NULL; p = p->prox){
        printf("Nome do leitor: %s\n", p->nome);
        printf("Livro emprestado: %s\n",p->nome_livro);
        printf("Data de devolução: %d/%d/%d\n",p->dia,p->mes,p->ano);
        
    }
}


Lista* lst_busca(Lista* l, char* v){
	Lista* p;
	for (p = l; p != NULL; p = p->prox){
		if (strcmp(p->nome, v) == 0)
			return p;
	}
	return NULL;
}

Lista* lst_retira(Lista* l, char* v){
	Lista* ant = NULL;
	Lista* p = l;
	while (p != NULL && strcmp(p->nome, v) != 0){
		ant = p;
		p = p->prox;
	}
	
	if (p == NULL)
		return l;
	
	if (ant == NULL)
		l = p->prox;
	else
		ant->prox = p->prox;
	free(p);
	return l;
}


void menu(){
	printf("1 - Registrar empréstimo de livro\n");
	printf("2 - Buscar leitor na lista\n");
	printf("3 - Registrar devolução de livro\n");
	printf("4 - Imprimir lista de empréstimos\n");
	printf("5 - Sair\n");
	printf("Escolha uma opção: ");
}
