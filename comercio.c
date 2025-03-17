//bibliotecas
#include <stdio.h>
#include <stdlib.h>

//funções utilizadas
int main();
int submenus(char dec, float sald);
void estoque(char dec);
void vendas(char dec, float sald);
void financeiro(char dec, float sald);
void despesas(char dec, float sald);
void receitas(char dec, float sald);
void saldo(char dec, float sald);

int main() {
	//variáveis de decisão
	char d2; //decisão: opções do menu principal
	
	//variáaveis numéricas
	float sald = 0; // saldo atual

	//abrir submenus
	submenus(d2, sald);
	
    return 0;
}

//abrir submenus
int submenus(char dec, float sald) {
    //variáveis de decisão
	char d3; //decisão: opções dos submenus
    
    //abrir os submenus
    printf("\nO que deseja?\n");
	printf("Abrir Controle de Estoque (digite E)\n");
	printf("Abrir Controle de Venda (digite V)\n");
	printf("Abrir Controle Financeiro (digite F)\n");
	printf("Sair (digite S)\n\n");
	printf("Escolha: ");
	scanf(" %c", &dec);
	
	//tratamento de erro
	while(dec!='e' && dec!='v' && dec!='f' && dec!='s') {
		printf("Comando inválido, digite novamente: ");
		scanf(" %c", &dec);
	}

	switch(dec) {
	//submenu estoque
	case 'e':
		estoque(d3);
		break;

	//submenu vendas
	case 'v':
		vendas(d3, sald);
		break;

	//submenu financeiro
	case 'f':
		financeiro(d3, sald);
		break;

	//encerrar programa
	case 's':
		printf("\nEncerrado");
		exit(0);
	}
}

//submenu estoque
void estoque(char dec) {
	printf("\nEstoque\n");
	printf("Itens Disponíveis:\n 1. Bosta - 10 Unidades\n 2. Coco - 10 Unidades \n 3. Merda - 10 Unidades\n");
	printf("Adicionar Item (digite A)\n");
	printf("Voltar (digite V)\n\n");
	printf("Escolha: ");
	scanf(" %c", &dec);
	
	//tratamento de erro
	while(dec!='a' && dec!='v') {
		printf("Comando inválido, digite novamente: ");
		scanf(" %c", &dec);
	}
	
	switch(dec){
	    
	    //voltar ao menu principal
	    case 'v':
	        main();
	        break;
	}
}

//submenu vendas
void vendas(char dec, float sald) {
    char d2; //decisão: opções do menu principal
    char d3; //decisão: opções dos submenus
    int item; //para selecionar o item vendido
    int qtd; //para selecionar quantidade vendida
    float total; //total do valor vendido
    char conf; //decisão de confirmação
    
	printf("\nVendas\n");
	printf("Itens Disponíveis:\n 001. Bosta - R$15,00\n 002. Coco - R$20,00\n 003. Merda - R$45,00\n");
	printf("Registrar Venda (digite R)\n");
	printf("Voltar (digite V)\n\n");
	printf("Escolha: ");
	scanf(" %c", &dec);
	
	//tratamento de erro
	while(dec!='v' && dec!='r') {
		printf("Comando inválido, digite novamente: ");
		scanf(" %c", &dec);
	}
	
	switch(dec){
	    
	    //registrar venda
	    case 'r':
	        printf("\nItem Vendido (digite o número do item): ");
	        scanf("%d", &item);
	        while(item!=001 && item!=002 && item!=003){
	            printf("Comando inválido, digite novamente: ");
		        scanf(" %d", &item);
	        }
	        printf("Quantidade Vendida: ");
	        scanf("%d", &qtd);
	        printf("\nConfirmar? (S para sim, N para não)\n");
	        printf("Escolha: ");
	        scanf(" %c", &conf);
	        while(conf!='s' && conf!='n') {
		        printf("Comando inválido, digite novamente: ");
		        scanf(" %c", &conf);
	        }
	        switch(conf){
	            case 'n':
	            
	            
	                vendas(d3, sald);
	        }
	        switch(item){
	            case 001:
	                total = qtd * 15.00;
	                printf("\nTotal vendido: R$%.2f \n", total);
	                printf("Receita Registrada! \n");
	                sald = sald + total;
	                vendas(d3, sald);
	                break;
	               
	            case 002:
	                total = qtd * 20.00;
	                printf("\nTotal vendido: R$%.2f \n", total);
	                printf("Receita Registrada! \n");
	                sald = sald + total;
	                vendas(d3, sald);
	                break;
	                
	            case 003:
	                total = qtd * 45.00;
	                printf("\nTotal vendido: R$%.2f \n", total);
	                printf("Receita Registrada! \n");
	                sald = sald + total;
	                vendas(d3, sald);
	                break;
	        }
	    
	    //voltar ao menu principal
	    case 'v':
	        submenus(d2, sald);
	        break;
	}
}

//submenu financeiro
void financeiro(char dec, float sald) {
    char d2; //decisão: opções do menu principal
    char d4; //decisão nas opções do submenu
	printf("\nFinanceiro\n");
	printf("Registrar Despesas (digite D)\n");
	printf("Registrar Receitas (digite R)\n");
	printf("Consultar Saldo (digite S)\n");
	printf("Voltar (digite V)\n\n");
	printf("Escolha: ");
	scanf(" %c", &dec);
	while(dec!='d' && dec!='r' && dec!='s' && dec!='v') {
		printf("Comando inválido, digite novamente: ");
		scanf(" %c", &dec);
	}
	switch(dec) {
	    //registrar despesas
        case 'd':
            despesas(d4, sald);
	        break;
	    
	    //registrar receitas
	    case 'r':
	        receitas(d4, sald);
	        break;
	       
	    //consultar saldo
	    case 's':
	        saldo(d4, sald);
	        break;
	        
	    case 'v':
	        submenus(d2, sald);
	        break;
	    
	}
}

//submenu financeiro: opção despesas
void despesas(char dec, float sald) {
    char d3; //decisão: opções dos submenus
    float des; //valor da despesa
    char conf; //decisão de confirmação
    printf("\nValor da Despesa: R$");
	scanf(" %f", &des);
	printf("\nConfirmar? (S para sim, N para não)\n");
	printf("Escolha: ");
	scanf(" %c", &conf);
	while(conf!='s' && conf!='n') {
		printf("Comando inválido, digite novamente: ");
	    scanf(" %c", &conf);
	}
	switch(conf){
	    case 'n':
	    financeiro(d3, sald);
	}
	sald = sald - des;
	printf("Despesa Registrada!\n");
	financeiro(d3, sald);
    scanf(" %c", &dec);
    while(dec!='v') {
		printf("Comando inválido, digite novamente: ");
		scanf(" %c", &dec);
	}
	switch(dec) {
        case 'v':
            financeiro(d3, sald);
            break;
    }
}

//submenu financeiro: opção receitas
void receitas(char dec, float sald) {
    char d3; //decisão: opções dos submenus
    float rec; //valor da receita
    char conf; //decisão de confirmação
    printf("\nValor da Receita: R$");
	scanf(" %f", &rec);
	printf("\nConfirmar? (S para sim, N para não)\n");
	printf("Escolha: ");
	scanf(" %c", &conf);
	while(conf!='s' && conf!='n') {
		printf("Comando inválido, digite novamente: ");
	    scanf(" %c", &conf);
	}
	switch(conf){
	    case 'n':
	    financeiro(d3, sald);
	}
	sald = sald + rec;
	printf("Receita Registrada!\n");
	financeiro(d3, sald);
    scanf(" %c", &dec);
    while(dec!='v') {
		printf("Comando inválido, digite novamente: ");
		scanf(" %c", &dec);
	}
	switch(dec) {
        case 'v':
            financeiro(d3, sald);
            break;
    }
}

//submenu financeiro: opção saldo
void saldo(char dec, float sald) {
    char d3; //decisão: opções dos submenus
    printf("\nSeu Saldo Atual\n");
    printf("R$%.2f \n", sald);
    printf("Voltar (digite V)\n\n");
    printf("Escolha: ");
    scanf(" %c", &dec);
    while(dec!='v') {
		printf("Comando inválido, digite novamente: ");
		scanf(" %c", &dec);
	}
    switch(dec) {
        case 'v':
            financeiro(d3, sald);
            break;
    }
}