#include <stdlib.h>
#include "iterador.h"
#include "sequencia.h"


/* Estrutura de dados: sequencia implementada em vector */
struct _sequencia{
	void * * elems; // apontador para vector de enderecos de elementos
	int numElems;
	int capacidade; // capacidade corrente do vector
};


sequencia criaSequencia(int cap){
    sequencia s = (sequencia) malloc(sizeof(struct _sequencia));
	if (s == NULL) return NULL;

	s->elems = (void*) malloc(sizeof(void*)*cap);
	if (s->elems==NULL){
		free(s);
		return NULL;
	}
	s->numElems=0;
    s->capacidade=cap;

	return s;
}


void destroiSequencia (sequencia s ){
	free (s->elems);
    free (s);
}


void destroiSeqElems(sequencia s, void (*destroi)(void *) ){
	for (int i=1; i<=s->numElems; i++)
	{
        destroi(s->elems[i-1]);
	}
	destroiSequencia(s);	
}


int vaziaSequencia(sequencia s){
	return s->numElems==0;
}


int tamanhoSequencia(sequencia s){
	return (s->numElems);
}


void * elementoPosSequencia(sequencia s, int i){
	return (s->elems[i-1]);
}


void adicionaPosSequencia(sequencia s, void * elem, int i){
	int j = s->numElems;
    while (j>=(i-1))
    {
        s->elems[j+1]= s->elems[j];
        j--;
    }
    s->elems[i-1]=elem;
    s->numElems ++;
}


void * removePosSequencia(sequencia s, int i){
    void * save = s->elems[i-1];
    while ((i-1)<=s->numElems)
    {
        s->elems[i-1]= s->elems[i];
        i++;
    }

    s->numElems --;
    return save;
}


iterador iteradorSequencia(sequencia s){
	//CUIDADO: DEVE DAR AO ITERADOR UMA COPIA DO VECTOR A PERCORRER
    int i;
    void * * copia = malloc(sizeof(void *) * s->numElems);

    for (i=1; i<=s->numElems; i++)
        copia[i-1] = s->elems[i-1];

    return criaIterador(copia, s->numElems);
}