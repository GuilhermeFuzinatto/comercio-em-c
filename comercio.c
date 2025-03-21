//TOTAL VENDIDO POR ITEM NAO TA FUNCIONANDO

//bibliotecas
#include <stdio.h>
#include <stdlib.h>

//funções utilizadas
int main();
int submenus(int dec, float sald);

void estoque(int dec);

void vendas(int dec, float sald);
float pagamento(float total);
//void totalpitem(char dec, float sald, float total, int item, float vend001, float vend002, float vend003);

void financeiro(int dec, float sald);
void despesas(int dec, float sald);
void receitas(int dec, float sald);
void saldo(int dec, float sald);

int main() {
	//variáveis de decisão
	int d2; //decisão: opções do menu principal
	
	//variáaveis numéricas
	float sald = 0; // saldo atual

	//abrir submenus
	submenus(d2, sald);
	
    return 0;
}

//abrir submenus
int submenus(int dec, float sald) {
    //variáveis de decisão
	int d3; //decisão: opções dos submenus
    
    //abrir os submenus
    printf("\nO que deseja?\n");
	printf("Abrir Controle de Estoque (digite 1)\n");
	printf("Abrir Controle de Venda (digite 2)\n");
	printf("Abrir Controle Financeiro (digite 3)\n");
	printf("Sair (digite 0)\n\n");
	printf("Escolha: ");
	scanf(" %d", &dec);
	
	//tratamento de erro
	while(dec!=1 && dec!=2 && dec!=3 && dec!=0) {
		printf("Comando inválido, digite novamente: ");
		
		scanf(" %d", &dec);
	}

	switch(dec) {
	//submenu estoque
	case 1:
		estoque(d3);
		break;

	//submenu vendas
	case 2:
		vendas(d3, sald);
		break;

	//submenu financeiro
	case 3:
		financeiro(d3, sald);
		break;

	//encerrar programa
	case 0:
		printf("\nEncerrado");
		exit(0);
	}
}

//submenu estoque
void estoque(int dec) {
	printf("\nEstoque\n");
	printf("Itens Disponíveis:\n 1. Bosta - 10 Unidades\n 2. Coco - 10 Unidades \n 3. Merda - 10 Unidades\n");
	printf("Voltar (digite 0)\n\n");
	printf("Escolha: ");
	scanf(" %d", &dec);
	
	//tratamento de erro
	while(dec!=0) {
		printf("Comando inválido, digite novamente: ");
		scanf(" %d", &dec);
	}
	
	switch(dec){
	    
	    //voltar ao menu principal
	    case 0:
	        main();
	        break;
	}
}

//submenu vendas
void vendas(int dec, float sald) {
    int d2; //decisão: opções do menu principal
    int d3; //decisão: opções dos submenus
    int d4; //decisão nas opções do submenu
    int conf; //decisão de confirmação
    int item; //para selecionar o item vendido
    int qtd; //para selecionar quantidade vendida
    float total; //total do valor vendido
    
    //total vendido por cada item
    float vend001 = 0;
    float vend002 = 0;
    float vend003 = 0;
    
	printf("\nVendas\n");
	printf("Itens Disponíveis:\n 001. Bosta - R$15,00\n 002. Coco - R$20,00\n 003. Merda - R$45,00\n");
	printf("Registrar Venda (digite 1)\n");
	printf("Total Vendido Por Item (digite 2)\n");
	printf("Voltar (digite 0)\n\n");
	printf("Escolha: ");
	scanf(" %d", &dec);
	
	//tratamento de erro
	while(dec!=1 && dec!=2 && dec!=0) {
		printf("Comando inválido, digite novamente: ");
		scanf(" %d", &dec);
	}
	
	switch(dec){
	    
	    //registrar venda
	    case 1:
	        printf("\nItem Vendido (digite o número do item): ");
	        scanf("%d", &item);
	        while(item!=001 && item!=002 && item!=003){
	            printf("Comando inválido, digite novamente: ");
		        scanf(" %d", &item);
	        }
	        printf("Quantidade Vendida: ");
	        scanf("%d", &qtd);
	        printf("\nConfirmar? (1 para sim, 2 para não)\n");
	        printf("Escolha: ");
	        scanf(" %d", &conf);
	        while(conf!=1 && conf!=2) {
		        printf("Comando inválido, digite novamente: ");
		        scanf(" %d", &conf);
	        }
	        switch(conf){
	            case 2:
	                vendas(d3, sald);
	        }
	        switch(item){
	            case 001:
	                total = qtd * 15.00;
	                total = pagamento(total);
	                printf("\nTotal vendido: R$%.2f \n", total);
	                printf("Receita Registrada! \n");
	                sald = sald + total;
	                vend001 = vend001 + total;
	                vendas(d3, sald);
	                break;
	               
	            case 002:
	                total = qtd * 20.00;
	                total = pagamento(total);
	                printf("\nTotal vendido: R$%.2f \n", total);
	                printf("Receita Registrada! \n");
	                sald = sald + total;
	                vend002 = vend002 + total;
	                vendas(d3, sald);
	                break;
	                
	            case 003:
	                total = qtd * 45.00;
	                total = pagamento(total);
	                printf("\nTotal vendido: R$%.2f \n", total);
	                printf("Receita Registrada! \n");
	                sald = sald + total;
	                vend003 = vend003 + total;
	                vendas(d3, sald);
	                break;
	        }
	        
	    //total vendido por categoria
	    case 2:
	        //totalpitem(d4, sald, total, item, vend001, vend002, vend003);
	        printf("ninguem fez isso ainda, eu nao consigo faze, eu nao vo faze agora, vai se fuder");
	        exit(0);
	    
	    //voltar ao menu principal
	    case 0:
	        submenus(d2, sald);
	        break;
	}
}

//forma de pagamento
float pagamento(float total){
    float vpag; //valor pago pelo cliente
    float troco; //valor do troco
    int fpag; //forma de pagamento
    int conf; //decisão de confirmação
    
    do{
	    printf("\nForma de Pagamento (1 para dinheiro, 2 para cartão): ");
	    scanf(" %d", &fpag);
	    while(fpag!=1 && fpag!=2) {
		    printf("Comando inválido, digite novamente: ");
		    scanf(" %d", &fpag);
	    }
	    switch(fpag){
	        //cálculo do devend001, float vend002, float vend003sconto do pagamento em dinheiro
	        case 1:
                if(total<=50){
                    total = total - (total*0.05);
                }else if(total<100){
                    total = total - (total*0.10);
                }else{
                    total = total - (total*0.18);
                }
                printf("Qual o valor dado pelo cliente? R$");
                scanf("%f", &vpag);
                troco = vpag - total;
                printf("Troco a ser retornado: R$%.2f", troco);
                break;
	                
	        case 2:
        	    printf("Pagamento OK? (1 para sim, 2 para não)\n");
        	    printf("Escolha: ");
        	    scanf(" %d", &conf);
        	    while(conf!=1 && conf!=2) {
        		    printf("Comando inválido, digite novamente: ");
        	        scanf(" %d", &conf);
        	    }
        	    break;
        }
	}while(conf==2);
	
	return total;
}

/*
void totalpitem(char dec, float sald, float total, int item, float vend001, float vend002, float vend003){
    char d3; //decisão: opções dos submenus
    
    if(item==001){
        tvend001 = vend001 + total;
        printf("%d, %f", item, vend001);
    }else if(item==002){
        tvend002 = vend002 + total;
    }else if(item==003){
        tvend003 = vend003 + total;
    }
    
    printf("Valor Vendido por Item");
	printf("\nItem 001: %.2f", tvend001);
	printf("\nItem 002: %.2f", tvend002);
	printf("\nItem 003: %.2f", tvend003);
	printf("\nVoltar (digite V)\n");
	printf("Escolha: ");
	scanf(" %c", &dec);
	while(dec!='v'){
	    printf("Comando inválido, digite novamente: ");
		scanf(" %c", &dec);
	}
	switch(dec){
	    case 'v':
	        vendas(d3, sald);
	}
}
*/

//submenu financeiro
void financeiro(int dec, float sald) {
    int d2; //decisão: opções do menu principal
    int d4; //decisão nas opções do submenu
	printf("\nFinanceiro\n");
	printf("Registrar Despesas (digite 1)\n");
	printf("Registrar Receitas (digite 2)\n");
	printf("Consultar Saldo (digite 3)\n");
	printf("Voltar (digite 0)\n\n");
	printf("Escolha: ");
	scanf(" %d", &dec);
	while(dec!=1 && dec!=2 && dec!=3 && dec!=0) {
		printf("Comando inválido, digite novamente: ");
		scanf(" %d", &dec);
	}
	switch(dec) {
	    //registrar despesas
        case 1:
            despesas(d4, sald);
	        break;
	    
	    //registrar receitas
	    case 2:
	        receitas(d4, sald);
	        break;
	       
	    //consultar saldo
	    case 3:
	        saldo(d4, sald);
	        break;
	        
	    case 0:
	        submenus(d2, sald);
	        break;
	    
	}
}


//submenu financeiro: opção despesas
void despesas(int dec, float sald) {
    int d3; //decisão: opções dos submenus
    float des; //valor da despesa
    int conf; //decisão de confirmação
    printf("\nValor da Despesa: R$");
	scanf(" %f", &des);
	printf("\nConfirmar? (1 para sim, 2 para não)\n");
	printf("Escolha: ");
	scanf(" %d", &conf);
	while(conf!=1 && conf!=2) {
		printf("Comando inválido, digite novamente: ");
	    scanf(" %d", &conf);
	}
	switch(conf){
	    case 2:
	    financeiro(d3, sald);
	}
	sald = sald - des;
	printf("Despesa Registrada!\n");
	financeiro(d3, sald);
}

//submenu financeiro: opção receitas
void receitas(int dec, float sald) {
    int d3; //decisão: opções dos submenus
    float rec; //valor da receita
    int conf; //decisão de confirmação
    printf("\nValor da Receita: R$");
	scanf(" %f", &rec);
	printf("\nConfirmar? (1 para sim, 2 para não)\n");
	printf("Escolha: ");
	scanf(" %d", &conf);
	while(conf!=1 && conf!=2) {
		printf("Comando inválido, digite novamente: ");
	    scanf(" %d", &conf);
	}
	switch(conf){
	    case 2:
	    financeiro(d3, sald);
	}
	sald = sald + rec;
	printf("Receita Registrada!\n");
	financeiro(d3, sald);
}

//submenu financeiro: opção saldo
void saldo(int dec, float sald) {
    int d3; //decisão: opções dos submenus
    printf("\nSeu Saldo Atual\n");
    printf("R$%.2f \n", sald);
    printf("Voltar (digite 0)\n\n");
    printf("Escolha: ");
    scanf(" %d", &dec);

    while(dec!=0) {
		printf("Comando inválido, digite novamente: ");
		scanf(" %d", &dec);
	}
    switch(dec) {
        case 0:
            financeiro(d3, sald);
            break;
    }
}