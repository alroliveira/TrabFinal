/*
    gestor.c
*/
#include <stdlib.h>
#include <string.h>

#include "iterador.h"
#include "dicionario.h"
#include "tuplo.h"

#include "gestor.h"

#include "gerente.h"
#include "estudante.h"
#include "quarto.h"


#include <stdlib.h>


struct _gestor{
	dicionario gerentes;
    dicionario estudantes;
    dicionario quartos;
};


gestor criaGestor(){
	gestor g = (gestor) malloc (sizeof(struct _gestor));
	if (g == NULL) return NULL;
	g->gerentes = criaDicionario(CAP_GERENTES,1);
	if (g->gerentes == NULL){
		free(g);
		return NULL;
	}
    g->estudantes = criaDicionario(CAP_ESTUDANTES,1);
    if (g->estudantes == NULL){
		destroiDicionario(g->gerentes);
		free(g);
		return NULL;
	}
    g->quartos = criaDicionario(CAP_QUARTOS,1);
    if (g->quartos == NULL){
		destroiDicionario(g->gerentes);
		destroiDicionario(g->estudantes);
		free(g);
		return NULL;
	}
	return g;
}

void destroiGestor(gestor g){
	destroiDicionario(g->gerentes);
	destroiDicionario(g->estudantes);
    destroiDicionario(g->quartos);
    free(g);
}

void destroiGestorEElems(gestor g){
	destroiDicEElems (g->gerentes, destroiGerenteGen);
	destroiDicEElems (g->estudantes, destroiEstudanteGen);
	destroiDicEElems (g->quartos, destroiQuartoGen);
	free(g);
}

int existeEstudanteGestor(gestor g,char* login){
    return existeElemDicionario(g->estudantes, (void *)&login);
}

int existeGerenteGestor(gestor g,char* login){
    return existeElemDicionario(g->gerentes, (void *)&login);
}

int novoEstudanteGestor (gestor g,char* login, char* nomeEstudante, int idade, char* localidade, char* universidade){
	estudante e = criaEstudante(login, nomeEstudante, idade, localidade, universidade);
	int aux = adicionaElemDicionario(g->estudantes, (void *)&login, e);
	if (aux != 1)
		destroiEstudante(e);
	return aux;
}

int novoGerenteGestor (gestor g, char* login, char* nomeGerente, char* universidade){
	gerente g2 = criaGerente(login, nomeGerente, universidade);
	int aux = adicionaElemDicionario(g->gerentes, (void *)&login, g2);
	if (aux != 1)
		destroiGerente(g2);
	return aux;
}

void *GerenteGestor(gestor g, char* ch){
    return (void*)elementoDicionario(g->gerentes, (void *)&ch);
}

int existeQuartoGestor(gestor g, char* codigo){
    return existeElemDicionario(g->quartos, (void *)&codigo);
}