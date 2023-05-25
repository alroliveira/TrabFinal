#include <stdlib.h>
#include <string.h>

#include "estudante.h"
#include "iterador.h"


/* Estrutura de dados do TAD estudante */
struct _estudante{
    char login[MAX2E];
    char nomeEstudante[MAX1E];
    int idade;
    char localidade[MAX1E];
    char universidade[MAX1E];
    int numCandidaturas;
};

estudante criaEstudante(char* login, char* nomeEstudante, int idade, char* localidade, char* universidade){
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

void destroiEstudanteGen(void* e){
	destroiEstudante((estudante) e);
} 
char* daNomeEstudante(estudante e){
    return e->nomeEstudante;
}
int daIdadeEstudante(estudante e){
    return e->idade;
}
char* daLocalidadeEstudante(estudante e){
    return e->localidade;
}
char* daUniversidadeEstudante(estudante e){
    return e->universidade;
}