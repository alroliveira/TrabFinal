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
#define MAX1 50 // nomes de estudantes, gerentes, residˆencias, universidades e localidades
#define MAX2 20 // restante

// protótipos funções
void interpretador(gestor g);
void cmdInserirEstudante(gestor g, char* linha);
void cmdDadosEstudante(gestor g, char* linha);
void cmdInserirGerente(gestor g, char* linha);
void cmdDadosGerente (gestor g, char* linha);
void cmdInserirQuarto(gestor g, char* linha);
void cmdDadodsQuarto(gestor g, char* linha);
void cmdModificarQuarto(gestor g, char* linha);
void cmdRemoverQuarto(gestor g, char* linha);
void cmdIncerirCandidatura(gestor g, char* linha);
void cmdAceitarCandidatura(gestor g, char* linha);
void cmdListaCandidaturas(gestor g, char* linha);

int main (){
    gestor g = criaGestor();
    interpretador(g);
    destroiGestorEElems(g);
    return 0;
}
/*
// Remover o primeiro caractere o " "
char* removePimeiroCaracterString(char* string){    
    memmove(string, string + 1, strlen(string));
    string[strlen(string) - 1] = '\0';
    return string;
}*/


void interpretador(gestor g){
    char linha[MAXL], cmd[MAXL];

    

    do{
        printf("> ");
        fgets(linha,MAXL,stdin);
        sscanf(linha, "%s %[^\n]s", cmd, linha);
        //removePimeiroCaracterString(linha);

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

void cmdInserirEstudante(gestor g, char* resto){
    char login[MAX2], nomeEstudante[MAX1], localidade[MAX1], universidade[MAX1];
    int idade;
    char linha[MAXL];

    sscanf(resto, "%s %[^\n]s", login, nomeEstudante);      //%[^\n]s -> ler ate ao \n
    fgets(linha,MAXL,stdin);
    sscanf(resto, "%d %[^\n]s", &idade, localidade);
    fgets(universidade,MAX1,stdin);

    if(existeEstudanteGestor(g, login)|| existeGerenteGestor(g, login)){
        printf("Utilizador ja existente.\n\n");
    }
    else{
        printf("Registo de estudante executado.\n\n");
        novoEstudanteGestor (g, login, nomeEstudante, idade, localidade, universidade);
    }

}
void cmdDadosEstudante(gestor g, char* linha){

}
void cmdInserirGerente(gestor g, char* linha){

}
void cmdDadosGerente (gestor g, char* linha){

}
void cmdInserirQuarto(gestor g, char* linha){

}
void cmdDadodsQuarto(gestor g, char* linha){

}
void cmdModificarQuarto(gestor g, char* linha){

}
void cmdRemoverQuarto(gestor g, char* linha){

}
void cmdIncerirCandidatura(gestor g, char* linha){

}
void cmdAceitarCandidatura(gestor g, char* linha){

}
void cmdListaCandidaturas(gestor g, char* linha){

}