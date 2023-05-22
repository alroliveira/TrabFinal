#include <stdlib.h>
#include <string.h>

#include "gerente.h"
#include "iterador.h"

#define MAX1 50 // nomes de estudantes, gerentes, residˆencias, universidades e localidades
#define MAX2 20 // restante

/* Estrutura de dados do TAD gerente */
struct _gerente{
    char login[MAX2];
    char nomeGerente[MAX1];
    char universidade[MAX1];
};

gerente criaGerente(char login, char nomeGerente, char universidade){
    gerente g;

    g = (gerente) malloc(sizeof(struct _gerente));
    if (g==NULL) return NULL;
    
    strcpy(g->login, login);
    strcpy(g->nomeGerente, nomeGerente);
    strcpy(g->universidade, universidade);
   
    return g;
}

void destroiGerente(gerente g){
    free(g);
}

void destroiGerenteGen (void* g){
	destroiEstudante ((gerente) g);
} 