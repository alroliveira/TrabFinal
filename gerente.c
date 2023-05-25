#include <stdlib.h>
#include <string.h>

#include "gerente.h"
#include "iterador.h"


/* Estrutura de dados do TAD gerente */
struct _gerente{
    char login[MAX2G];
    char nomeGerente[MAX1G];
    char universidade[MAX1G];
};

gerente criaGerente(char* login, char* nomeGerente, char* universidade){
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
	destroiGerente ((gerente) g);
} 

char* daNomeGerente (gerente g){
    return g->nomeGerente;
}

char* daUniversidadeGerente (gerente g){
    return g->universidade;
}

