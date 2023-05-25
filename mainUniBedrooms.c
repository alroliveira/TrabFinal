#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>


// TADs usadas
#include "iterador.h"
#include "dicionario.h"
#include "sequencia.h"

#include "estudante.h"
#include "gerente.h"
#include "quarto.h"
#include "gestor.h"


// constantes
#define MAXL 200 // A CONFIRMAR <------------------------------------------------------------------------------------------
#define MAX1 50 // nomes de estudantes, gerentes, residˆencias, universidades e localidades
#define MAX2 20 // restante
#define MAX3 200// descriçao

// protótipos funções
void interpretador(gestor g);
void cmdInserirEstudante(gestor g, char* linha);
void cmdDadosEstudante(gestor g, char* linha);
void cmdInserirGerente(gestor g, char* linha);
void cmdDadosGerente (gestor g, char* linha);
void cmdInserirQuarto(gestor g, char* linha);
void cmdDadosQuarto(gestor g, char* linha);
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


void interpretador(gestor g){
    char linha[MAXL], cmd[MAXL];

    do{
        printf("> ");
        fgets(linha,MAXL,stdin);
        sscanf(linha, "%s %[^\n]s", cmd, linha);

        if (strcmp(cmd, "IE")==0) cmdInserirEstudante(g,linha);
        else if (strcmp(cmd, "DE")==0) cmdDadosEstudante(g,linha);
        else if (strcmp(cmd, "IG")==0) cmdInserirGerente(g,linha);
        else if (strcmp(cmd, "DG")==0) cmdDadosGerente(g,linha);
        else if (strcmp(cmd, "IQ")==0) cmdInserirQuarto(g,linha);
        else if (strcmp(cmd, "DQ")==0) cmdDadosQuarto(g,linha);
        else if (strcmp(cmd, "MQ")==0) cmdModificarQuarto(g,linha);
        else if (strcmp(cmd, "RQ")==0) cmdRemoverQuarto(g,linha);
        else if (strcmp(cmd, "IC")==0) cmdIncerirCandidatura(g,linha);
        else if (strcmp(cmd, "AC")==0) cmdAceitarCandidatura(g,linha);
        else if (strcmp(cmd, "LC")==0) cmdListaCandidaturas(g,linha);

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
    sscanf(linha, "%d %[^\n]s", &idade, localidade);
    scanf("%s", universidade);
    
    if(existeEstudanteGestor(g, login)|| existeGerenteGestor(g, login)){
        printf("Utilizador ja existente.\n\n");
    }
    else{
        printf("Registo de estudante executado.\n\n");
        novoEstudanteGestor (g, login, nomeEstudante, idade, localidade, universidade);
    }
}

void cmdDadosEstudante(gestor g, char* login){
    estudante e;

    if(existeEstudanteGestor(g, login)){
        e = EstudanteGestor(g, login);
        printf("%s, %s, %d anos,%s \n", login, daNomeEstudante(e), daIdadeEstudante(e), daLocalidadeEstudante(e));           
        printf("%s\n\n",daUniversidadeEstudante(e));
    }
    else{
        printf("Inexistencia do estudante referido.\n\n");
    }

}

void cmdInserirGerente(gestor g, char* linha){
    char login[MAX2], nomeGerente[MAX1], universidade[MAX1];

    sscanf(linha, "%s %[^\n]s", login, nomeGerente);   
    scanf("%s", universidade);

    if(existeEstudanteGestor(g, login)|| existeGerenteGestor(g, login)){
        printf("Utilizador ja existente.\n\n");
    }
    else{
        printf("Registo de gerente executado.\n\n");
        novoGerenteGestor (g, login, nomeGerente, universidade);
    }

}
void cmdDadosGerente (gestor g, char* login){
    gerente g2;

    if(existeGerenteGestor(g, login)){
        g2 = GerenteGestor(g, login);
        printf("%s, %s\n%s\n\n", login, daNomeGerente(g2), daUniversidadeGerente(g2));
    }
    else{
        printf("Inexistencia do gerente referido.\n\n");
    }  
}
void cmdInserirQuarto(gestor g, char* linha){
    char codigo[MAX2], loginGerente[MAX2], nomeResidencia[MAX1], universidade[MAX1], localidade[MAX1], descricao[MAX3];
    int andar;

    sscanf(linha, "%s %[^\n]s", codigo, loginGerente);  
    scanf("%s", nomeResidencia);
    scanf("%s", universidade);
    scanf("%s", localidade);
    scanf("%d", &andar);
    scanf("%s", descricao);

    if(existeQuartoGestor(g, codigo)){
        printf("Quarto existente.\n\n");
    }
    else if(existeGerenteGestor(g, loginGerente)){
        printf("Inexistencia do gerente referido.\n\n");
    }
    //else if(strcmp(universidade,daUniversidadeGerente(GerenteGestor(g, loginGerente)))){      //daUniversidadeGerente esta a rebentar <------------------------------------------------------------------------------------------
    //    printf("Operacao nao autorizada.\n\n");
    //}
    else{
        printf("Registo de quarto executado.\n\n");   
        novoQuartoGestor (g, codigo, loginGerente, nomeResidencia, universidade, localidade, descricao, andar);
     
    }
}
void cmdDadosQuarto(gestor g, char* codigo){
    quarto q;
    if(existeQuartoGestor(g, codigo)){
        q = QuartoGestor(g, codigo);
        printf("%s, %s\n%s\n%s\n%d\n",codigo, daNomeQuarto(q),daUniversidadeQuarto(q),daLocalidadeQuarto(q),daAndarQuarto(q));
        printf("%s\n",daDescricaoQuarto(q)/*,daDescricaoQuarto(), daEstadoQuarto(q)*/);
    }
}
void cmdModificarQuarto(gestor g, char* linha){
    /*quarto q;
    char codigo[MAX2], loginGerente[MAX2], estado[MAX2];
    

    sscanf(linha, "%s %s %[^\n]s", codigo, loginGerente, estado);
    
*/
}
void cmdRemoverQuarto(gestor g, char* linha){

}
void cmdIncerirCandidatura(gestor g, char* linha){

}
void cmdAceitarCandidatura(gestor g, char* linha){

}
void cmdListaCandidaturas(gestor g, char* linha){

}