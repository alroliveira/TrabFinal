#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// TADs usadas
#include "iterador.h"
#include "dicionario.h"
#include "sequencia.h"

#include "estudante.h"
#include "gerente.h"
#include "gestor.h"
#include "quarto.h"

// constantes
#define MAXL 200 // A CONFIRMAR <------------------------------------------------------------------------------------------

// protótipos funções
void interpretador(gestor g);
void cmdInserirEstudante(gestor g, char linha);
void cmdDadosEstudante(gestor g, char linha);
void cmdInserirGerente(gestor g, char linha);
void cmdDadosGerente (gestor g, char linha);
void cmdInserirQuarto(gestor g, char linha);
void cmdDadodsQuarto(gestor g, char linha);
void cmdModificarQuarto(gestor g, char linha);
void cmdRemoverQuarto(gestor g, char linha);
void cmdIncerirCandidatura(gestor g, char linha);
void cmdAceitarCandidatura(gestor g, char linha);
void cmdListaCandidaturas(gestor g, char linha);

int main (){
    gestor g = criaGestor();
    interpretador(g);
    destroiGestorTD(g);
    return 0;
}

void interpretador(gestor g){
    char linha[MAXL], cmd;

    fgets(linha,MAXL,stdin);
    sscanf(linha, "%s %[^\n]", cmd, linha);
	
    do{
        if (strcmp(cmd, "IE")==0) cmdInserirEstudante(g,linha);
        else if (strcmp(cmd, "DE")==0) cmdDadosEstudante(g,linha);
        else if (strcmp(cmd, "IG")==0) cmdDadosEstudante(g,linha);
        else if (strcmp(cmd, "DG")==0) cmdDadosEstudante(g,linha);
        else if (strcmp(cmd, "IQ")==0) cmdDadosEstudante(g,linha);
        else if (strcmp(cmd, "DQ")==0) cmdDadosEstudante(g,linha);
        else if (strcmp(cmd, "MQ")==0) cmdDadosEstudante(g,linha);
        else if (strcmp(cmd, "RQ")==0) cmdDadosEstudante(g,linha);
        else if (strcmp(cmd, "IC")==0) cmdDadosEstudante(g,linha);
        else if (strcmp(cmd, "AC")==0) cmdDadosEstudante(g,linha);
        else if (strcmp(cmd, "LC")==0) cmdDadosEstudante(g,linha);

        else if (strcmp(cmd, "XS")==0) printf("Obrigado. Ate a proxima.\n");

        
        else printf("Comando invalido\n");
    } while(strcmp(cmd, "XS")!=0);

}

void cmdInserirEstudante(gestor g, char linha){

}
void cmdDadosEstudante(gestor g, char linha){

}
void cmdInserirGerente(gestor g, char linha){

}
void cmdDadosGerente (gestor g, char linha){

}
void cmdInserirQuarto(gestor g, char linha){

}
void cmdDadodsQuarto(gestor g, char linha){

}
void cmdModificarQuarto(gestor g, char linha){

}
void cmdRemoverQuarto(gestor g, char linha){

}
void cmdIncerirCandidatura(gestor g, char linha){

}
void cmdAceitarCandidatura(gestor g, char linha){

}
void cmdListaCandidaturas(gestor g, char linha){

}