#include <stdlib.h>
#include <string.h>

#include "quarto.h"
#include "iterador.h"
#include "sequencia.h"
#include "estudante.h"
#include "gerente.h"
#include "gestor.h"



/* Estrutura de dados do TAD quarto */
struct _quarto{
    char codigo[MAX2Q];
    gerente g;
    char nomeResidencia[MAX1Q];
    char universidade[MAX1Q];
    char localidade[MAX1Q];
    int andar;
    char descricao[MAX3Q];
    char estado[MAX1Q];
    sequencia estudantes;
};
/*
quarto criarQuarto(char* codigo, gerente *g, char* nomeResidencia, char* universidade, char* localidade, int andar, char* descricao){
    quarto q;
    q = (quarto) malloc(sizeof(struct _quarto));
    if (q==NULL) return NULL;
//    q->g = (gerente)malloc(sizeof(gerente));
//    if (q->g == NULL){
//        free (q);
//        return NULL;
//    }

    strcpy(q->codigo, codigo);
    q->g = g;
    strcpy(q->nomeResidencia, nomeResidencia);
    strcpy(q->universidade, universidade);
    strcpy(q->localidade, localidade);
    q->andar = andar;
    strcpy(q->descricao, descricao);
    strcpy(q->estado, LIVRE);
    q->estudantes = criaSequencia(MAX_CANDIDATURAS);

    return q;
}*/

void destroiQuarto(quarto q){
    //free(q->g);
    free(q);
}

void destroiQuartoGen(void* q){
    destroiQuarto((quarto) q);
}