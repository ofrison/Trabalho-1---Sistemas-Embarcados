/**
 *@author	Osmar Frison Junior
 *@version	1.0
 *@date		25/04/2013
 *@brief		Este código faz parte dos trabalhos da disciplina
 *@brief		de Sistemas Embarcados.
 *@brief		O usuário deve entrar com uma sequencia numérica,
 *@brief		a qual será ordenada e posteriormente calculado
 *@brief		a média e o desvio padrão.
*/

/**
 *brief Inclui as bibliotecas utilizadas
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 *brief Definição para o compilador GCC
*/
#define _GNU_SOURCE


#define  NUM_DADOS  20	///>Número de dados que serão solicitados ao usuário

/**
 *brief Protótipo das Funções utilizadas no programa
*/
int SolicitaDados(void);
void OrdenaDados(int dados_digitados[], int *dados_ordenados);
void Calcula_Media_e_DP(int dados_ordenados[]);
void ImprimeDados(int dados[]);

/**
 *brief Variáveis Globais
*/
float media = 0, dp = 0;	///> armazenam a média e o desvio padrão

/**
 *brief Função que solicita ao usuário que entre com os dados
 *param Nenhum
 *return Retorna o dado digitado, na variável "dado"
*/
int SolicitaDados(void){
    
    int dado;   
    printf("Digite o numero e pressione Enter para continuar\n");
    scanf("%d", &dado);
    return (dado);   
}

/**
 *brief Função recebe os dados digitados pelo usuário, e os coloca em ordem
 *brief decrescente
 *param dados_digitados[] > dados que o usuário digitou
 *param *dados_ordenados > endereço da variável a ser carregada com os valores ordenados
 *return Nada
*/
void OrdenaDados(int dados_digitados[], int *dados_ordenados){
    
    int x, y, aux;
    for(x=0; x < NUM_DADOS; x++){
             *(dados_ordenados + x) = 0;                     
    }
    for(x=0; x < NUM_DADOS; x++){
             for(y=0; y < NUM_DADOS; y++){
                 if(dados_digitados[y] > *(dados_ordenados + x)){
                                 *(dados_ordenados + x) = dados_digitados[y];
                                 aux = y;                                                                 
                 }
             }
             dados_digitados[aux] = 0;                          
    }        
}

/**
 *brief Função recebe os dados digitados e ordenados, e calcula a média e desvio padrão
 *param dados_ordenados[] > dados digitado pelo usuário, já ordenados
 *return Nada
*/
void Calcula_Media_e_DP(int dados_ordenados[]){

     int x;
     float variancia, soma = 0, desvio;
     
     for(x=0; x < NUM_DADOS; x++){
             soma = soma + dados_ordenados[x];                     
     }
     media = soma/NUM_DADOS;
     
     soma = 0;
     for (x=0; x < NUM_DADOS; x++){
         desvio = dados_ordenados[x] - media;         
         soma = soma + desvio*desvio;         
     }
     variancia = soma/NUM_DADOS;     
     dp = sqrt(variancia);    
}

/**
 *brief Função utilizada para imprimir os dados ordenados na tela, em ordem crescente
 *param dados_imprimir[] > Recebe os dados a serem impressos
 *return Nada
*/
void ImprimeDados(int dados_imprimir[]){
     
     int x;
     printf("\nDados Ordenados\n");
     for(x = NUM_DADOS; x > 0; x--){
             printf("%d ", dados_imprimir[x-1]);
     }          
}

/**
 *brief Função principal. Chama as demais funções
 *see SolicitaDados()
 *see OrdenaDados()
 *see ImprimeDados()
 *see Calcula_Media_e_DP()
*/
int main(int argc, char *argv[])
{
    int x;
    int dados[NUM_DADOS], dados_ordenados[NUM_DADOS];
    int *p1;  
    
    p1 = &dados_ordenados[0]; 
    
    /* Solicita dados ao usuário */
    for(x=0; x < NUM_DADOS; x++){
             dados[x] = SolicitaDados();     
    }
        
    /* Ordena valores em ordem crescente */
    OrdenaDados(dados, p1);
    
    /* Imprime os dados ordenados na tela */    
    ImprimeDados(dados_ordenados);
    
    /* Calcula Média e Desvio Padrão */    
    Calcula_Media_e_DP(dados_ordenados);    

    
    printf("\nMedia %.2f e Desvio Padrao %.2f\n", media, dp);    
    getchar();  
  	
    return 0;
}
