#include <stdlib.h>
#include <string.h>

#include "estudante.h"
#include "iterador.h"

#define MAX1 50 // nomes de estudantes, gerentes, residˆencias, universidades e localidades
#define MAX2 20 // restante

/* Estrutura de dados do TAD estudante */
struct _estudante{
    char login[MAX2];
    char nomeEstudante[MAX1];
    int idade;
    char localidade[MAX1];
    char universidade[MAX1];
    int numCandidaturas;
};

estudante criaEstudante(char login, char nomeEstudante, int idade, char localidade, char universidade){
    estudante e;

    e = (estudante) malloc(sizeof(struct _estudante));
    if (e==NULL) return NULL;
    
    strcpy(e->login, login);
    strcpy(e->nomeEstudante, nomeEstudante);
    e->idade = idade;
    strcpy(e->localidade, localidade);
    strcpy(e->universidade, universidade);
    e->numCandidaturas = 0;
    
    return e;
}

void destroiEstudante(estudante e){
    free(e);
}

void destroiEstudanteGen (void* e){
	destroiEstudante ((estudante) e);
} 