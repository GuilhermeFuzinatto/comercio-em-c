//bibliotecas
#include <stdio.h>
#include <stdlib.h>

//funções utilizadas
int main();
int submenus();

void estoque();

void vendas();
float pagamento(float total);
void totalpitem(float total, int item);

void financeiro();
void despesas();
void receitas();
void saldo();

//variáveis globais
float sald = 0; //saldo total
float vend[] = {0, 0, 0}; //valor vendido por cada item
int qtdvend[] = {0, 0, 0}; //quantidade vendida de cada item
int d; //decisões no programa

int main() {
    
	//abrir submenus
	submenus(sald);
	
    return 0;
}

//abrir submenus
int submenus() {
    
    //abrir os submenus
    printf("\nO que deseja?\n");
	printf("Abrir Controle de Estoque (digite 1)\n");
	printf("Abrir Controle de Venda (digite 2)\n");
	printf("Abrir Controle Financeiro (digite 3)\n");
	printf("Sair (digite 0)\n\n");
	printf("Escolha: ");
	scanf(" %d", &d);
	
	//tratamento de erro
	while(d!=1 && d!=2 && d!=3 && d!=0) {
		printf("Comando inválido, digite novamente: ");
		scanf(" %d", &d);
	}

	switch(d) {
	//submenu estoque
	case 1:
		estoque();
		break;

	//submenu vendas
	case 2:
		vendas();
		break;

	//submenu financeiro
	case 3:
		financeiro();
		break;

	//encerrar programa, float vend001, float vend002, float vend003
	case 0:
	    printf("\nVendas Item 001: R$%.2f ; Quantidade: %d", vend[0], qtdvend[0]);
	    printf("\nVendas Item 002: R$%.2f ; Quantidade: %d", vend[1], qtdvend[1]);
	    printf("\nVendas Item 003: R$%.2f ; Quantidade: %d", vend[2], qtdvend[2]);
	    printf("\nSaldo final: R$%.2f", sald);
		printf("\n\nEncerrado");
		exit(0);
	}
}

//submenu estoque
void estoque() {
	printf("\nEstoque\n");
	printf("Itens Disponíveis:\n 1. Bosta - 10 Unidades\n 2. Coco - 10 Unidades \n 3. Merda - 10 Unidades\n");
	printf("Voltar (digite 0)\n\n");
	printf("Escolha: ");
	scanf(" %d", &d);
	
	//tratamento de erro
	while(d!=0) {
		printf("Comando inválido, digite novamente: ");
		scanf(" %d", &d);
	}
	
	switch(d){
	    
	    //voltar ao menu principal
	    case 0:
	        main();
	        break;
	}
}

//submenu vendas
void vendas() {
    int item; //para selecionar o item vendido
    int qtd; //para selecionar quantidade vendida
    float total; //total do valor vendido
    
	printf("\nVendas\n");
	printf("Itens Disponíveis:\n 001. Bosta - R$15,00\n 002. Coco - R$20,00\n 003. Merda - R$45,00\n");
	printf("Registrar Venda (digite 1)\n");
	printf("Total Vendido Por Item (digite 2)\n");
	printf("Voltar (digite 0)\n\n");
	printf("Escolha: ");
	scanf(" %d", &d);
	
	//tratamento de erro
	while(d!=1 && d!=2 && d!=0) {
		printf("Comando inválido, digite novamente: ");
		scanf(" %d", &d);
	}
	
	switch(d){
	    
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
	        scanf(" %d", &d);
	        while(d!=1 && d!=2) {
		        printf("Comando inválido, digite novamente: ");
		        scanf(" %d", &d);
	        }
	        switch(d){
	            case 2:
	                printf("\nVenda Cancelada!\n");
	                vendas(sald);
	        }
	        switch(item){
	            case 001:
	                total = qtd * 15.00;
	                total = pagamento(total);
	                printf("\n\nTotal vendido: R$%.2f \n", total);
	                printf("Receita Registrada! \n");
	                sald = sald + total;
	                vend[0] = vend[0] + total;
	                qtdvend[0] = qtdvend[0] + qtd;
	                vendas();
	                break;
	               
	            case 002:
	                total = qtd * 20.00;
	                total = pagamento(total);
	                printf("\n\nTotal vendido: R$%.2f \n", total);
	                printf("Receita Registrada! \n");
	                sald = sald + total;
	                vend[1] = vend[1] + total;
	                qtdvend[1] = qtdvend[1] + qtd;
	                vendas();
	                break;
	                
	            case 003:
	                total = qtd * 45.00;
	                total = pagamento(total);
	                printf("\n\nTotal vendido: R$%.2f \n", total);
	                printf("Receita Registrada! \n");
	                sald = sald + total;
	                vend[2] = vend[2] + total;
	                qtdvend[2] = qtdvend[2] + qtd;
	                vendas();
	                break;
	        }
	        
	    //total vendido por categoria
	    case 2:
	        totalpitem(total, item);
	    
	    //voltar ao menu principal
	    case 0:
	        submenus();
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
	        case 1:
                if(total<=50){
                    total = total - (total*0.05);
                }else if(total<100){
                    total = total - (total*0.10);
                }else{
                    total = total - (total*0.18);
                }
                printf("Valor da compra: R$%.2f \n", total);
                printf("Qual o valor dado pelo cliente? R$");
                scanf("%f", &vpag);
                while(vpag<total){
                    printf("Valor inválido, digite novamente: R$");
                    scanf("%f", &vpag);
                }
                troco = vpag - total;
                printf("Troco a ser retornado: R$%.2f", troco);
                break;
	                
	        case 2:
	            printf("Valor da compra: R$%.2f \n", total);
        	    printf("Pagamento OK? (1 para sim, 2 para não)\n");
        	    printf("Escolha: ");
        	    scanf(" %d", &d);
        	    while(d!=1 && d!=2) {
        		    printf("Comando inválido, digite novamente: ");
        	        scanf(" %d", &d);
        	    }
        	    break;
        }
	}while(d==2);
	
	return total;
}

void totalpitem(float total, int item){
    printf("Valor e Quantidade Vendida por Item");
	printf("\nItem 001 - Valor Vendido: R$%.2f ; Quantidade: %d", vend[0], qtdvend[0]);
	printf("\nItem 002 - Valor Vendido: R$%.2f ; Quantidade: %d", vend[1], qtdvend[1]);
	printf("\nItem 003 - Valor Vendido: R$%.2f ; Quantidade: %d", vend[2], qtdvend[2]);
	printf("\nVoltar (digite 0)\n");
	printf("Escolha: ");
	scanf(" %d", &d);
	while(d!=0){
	    printf("Comando inválido, digite novamente: ");
		scanf(" %d", &d);
	}
	switch(d){
	    case 0:
	        vendas();
	}
}

//submenu financeiro
void financeiro() {

	printf("\nFinanceiro\n");
	printf("Registrar Despesas (digite 1)\n");
	printf("Registrar Receitas (digite 2)\n");
	printf("Consultar Saldo (digite 3)\n");
	printf("Voltar (digite 0)\n\n");
	printf("Escolha: ");
	scanf(" %d", &d);
	while(d!=1 && d!=2 && d!=3 && d!=0) {
		printf("Comando inválido, digite novamente: ");
		scanf(" %d", &d);
	}
	switch(d){
	    //registrar despesas
        case 1:
            despesas();
	        break;
	    
	    //registrar receitas
	    case 2:
	        receitas();
	        break;
	       
	    //consultar saldo
	    case 3:
	        saldo();
	        break;
	        
	    case 0:
	        submenus();
	        break;
	    
	}
}


//submenu financeiro: opção despesas
void despesas() {
    float des; //valor da despesa
    
    printf("\nValor da Despesa: R$");
	scanf(" %f", &des);
	printf("\nConfirmar? (1 para sim, 2 para não)\n");
	printf("Escolha: ");
	scanf(" %d", &d);
	while(d!=1 && d!=2) {
		printf("Comando inválido, digite novamente: ");
	    scanf(" %d", &d);
	}
	switch(d){
	    case 2:
	    financeiro();
	}
	sald = sald - des;
	printf("Despesa Registrada!\n");
	financeiro();
}

//submenu financeiro: opção receitas
void receitas() {
    float rec; //valor da receita

    printf("\nValor da Receita: R$");
	scanf(" %f", &rec);
	printf("\nConfirmar? (1 para sim, 2 para não)\n");
	printf("Escolha: ");
	scanf(" %d", &d);
	while(d!=1 && d!=2) {
		printf("Comando inválido, digite novamente: ");
	    scanf(" %d", &d);
	}
	switch(d){
	    case 2:
	    financeiro();
	}
	sald = sald + rec;
	printf("Receita Registrada!\n");
	financeiro();
}

//submenu financeiro: opção saldo
void saldo() {

    printf("\nSeu Saldo Atual\n");
    printf("R$%.2f \n", sald);
    printf("Voltar (digite 0)\n\n");
    printf("Escolha: ");
    scanf(" %d", &d);

    while(d!=0) {
		printf("Comando inválido, digite novamente: ");
		scanf(" %d", &d);
	}
    switch(d) {
        case 0:
            financeiro();
            break;
    }
}