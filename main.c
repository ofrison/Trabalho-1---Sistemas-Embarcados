/**
 *@author	Osmar Frison Junior
 *@version	1.0
 *@date		25/04/2013
 *@brief		Este c�digo faz parte dos trabalhos da disciplina
 *@brief		de Sistemas Embarcados.
 *@brief		O usu�rio deve entrar com uma sequencia num�rica,
 *@brief		a qual ser� ordenada e posteriormente calculado
 *@brief		a m�dia e o desvio padr�o.
*/

/**
 *brief Inclui as bibliotecas utilizadas
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 *brief Defini��o para o compilador GCC
*/
#define _GNU_SOURCE


#define  NUM_DADOS  20	///>N�mero de dados que ser�o solicitados ao usu�rio

/**
 *brief Prot�tipo das Fun��es utilizadas no programa
*/
int SolicitaDados(void);
void OrdenaDados(int dados_digitados[], int *dados_ordenados);
void Calcula_Media_e_DP(int dados_ordenados[]);
void ImprimeDados(int dados[]);

/**
 *brief Vari�veis Globais
*/
float media = 0, dp = 0;	///> armazenam a m�dia e o desvio padr�o

/**
 *brief Fun��o que solicita ao usu�rio que entre com os dados
 *param Nenhum
 *return Retorna o dado digitado, na vari�vel "dado"
*/
int SolicitaDados(void){
    
    int dado;   
    printf("Digite o numero e pressione Enter para continuar\n");
    scanf("%d", &dado);
    return (dado);   
}

/**
 *brief Fun��o recebe os dados digitados pelo usu�rio, e os coloca em ordem
 *brief decrescente
 *param dados_digitados[] > dados que o usu�rio digitou
 *param *dados_ordenados > endere�o da vari�vel a ser carregada com os valores ordenados
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
 *brief Fun��o recebe os dados digitados e ordenados, e calcula a m�dia e desvio padr�o
 *param dados_ordenados[] > dados digitado pelo usu�rio, j� ordenados
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
 *brief Fun��o utilizada para imprimir os dados ordenados na tela, em ordem crescente
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
 *brief Fun��o principal. Chama as demais fun��es
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
    
    /* Solicita dados ao usu�rio */
    for(x=0; x < NUM_DADOS; x++){
             dados[x] = SolicitaDados();     
    }
        
    /* Ordena valores em ordem crescente */
    OrdenaDados(dados, p1);
    
    /* Imprime os dados ordenados na tela */    
    ImprimeDados(dados_ordenados);
    
    /* Calcula M�dia e Desvio Padr�o */    
    Calcula_Media_e_DP(dados_ordenados);    

    
    printf("\nMedia %.2f e Desvio Padrao %.2f\n", media, dp);    
    getchar();  
  	
    return 0;
}
