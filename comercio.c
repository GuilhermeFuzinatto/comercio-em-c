//bibliotecas
#include <stdio.h>
#include <stdlib.h>

//funções utilizadas
int main();
int submenus(char dec, float sald);
void estoque(char dec);
void vendas(char dec);
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
    
    printf("\nO que deseja?\n");
	printf("Abrir Controle de Estoque (digite E)\n");
	printf("Abrir Controle de Venda (digite V)\n");
	printf("Abrir Controle Financeiro (digite F)\n");
	printf("Sair (digite S)\n\n");
	printf("Escolha: ");
	scanf(" %c", &dec);
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
		vendas(d3);
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
	while(dec!='a' && dec!='v') {
		printf("Comando inválido, digite novamente: ");
		scanf(" %c", &dec);
	}
	switch(dec){
	    case 'v':
	        main();
	        break;
	}
}

//submenu vendas
void vendas(char dec) {
    int item; //para selecionar o item vendido
    int qtd; //para selecionar quantidade vendida
	printf("\nVendas\n");
	printf("Itens Disponíveis:\n 001. Bosta - R$15,00\n 002. Coco - R$20,00\n 003. Merda - R$45,00\n");
	printf("Registrar Venda (digite R)\n");
	printf("Voltar (digite V)\n\n");
	printf("Escolha: ");
	scanf(" %c", &dec);
	while(dec!='v' && dec!='r') {
		printf("Comando inválido, digite novamente: ");
		scanf(" %c", &dec);
	}
	switch(dec){
	    case 'r':
	        printf("Item Vendido (digite o número do item): ");
	        scanf("%d", &item);
	        switch(item){
	            case 001:
	                printf("Quantidade Vendida: ");
	                scanf("%d", &qtd);
	                printf("vaisefode nao terminei\n");
	                main();
	                //TERMINAR ESSA PARTE
	        }
	    
	    case 'v':
	        main();
	        break;
	}
}

//submenu financeiro
void financeiro(char dec, float sald) {
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
	        main();
	        break;
	    
	}
}

//submenu financeiro: opção despesas
void despesas(char dec, float sald) {
    char d3; //decisão: opções dos submenus
    float des; //valor da despesa
    printf("\nValor da Despesa: R$");
	scanf(" %f", &des);
	sald = sald - des;
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

//submenu financeiro: opção receitas
void receitas(char dec, float sald) {
    char d3; //decisão: opções dos submenus
    float rec; //valor da receita
    printf("\nValor da Receita: R$");
	scanf(" %f", &rec);
	sald = sald + rec;
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
