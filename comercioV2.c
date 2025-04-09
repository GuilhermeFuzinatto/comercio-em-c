//ARRUMAR: CONTROLE DE VENDA - VENDA DE NOVOS ITENS (OPCIONAL - ID AUTOMATICO)

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funções utilizadas
int main();
int submenus();

void estoque();
void additem();

void vendas();
float pagamento(float total);
void totalpitem(float total, int item);

void financeiro();
void despesas();
void receitas();
void saldo();

void testador();

//variáveis globais
int i = 3; //espaço atual a ser preenchido nos vetores
float sald = 0; //saldo total

//dados dos itens
struct Item{
    float vend;
    int qtdvend;
    int uni;
    char id[4];
    float preco;
    char nome[50];
};

//itens já em estoque
struct Item itens[50] = {
    {0, 0, 10, "001", 15, "Bosta"},
    {0, 0, 10, "002", 20, "Coco"},
    {0, 0, 10, "003", 45, "Merda"},
};

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
	printf("TESTADOR (digite 4)\n");
	printf("Sair (digite 0)\n\n");
	printf("Escolha: ");
	scanf(" %d", &d);
	
	//tratamento de erro
	while(d!=1 && d!=2 && d!=3 && d!=4 && d!=0) {
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
		
	//TESTADOR
	case 4:
	    testador();
	    break;

	//encerrar programa
	case 0:
	    for(int cont = 0; cont < i; cont++){
	        printf("\nVendas Item %s: R$%.2f ; Quantidade: %d", itens[cont].id, itens[cont].vend, itens[cont].qtdvend);
    	}
	    printf("\nSaldo final: R$%.2f", sald);
		printf("\n\nEncerrado");
		exit(0);
	}
}

//submenu estoque
void estoque() {
	printf("\nEstoque\n");
	
	//visualizaçãao dos itens
	printf("Itens Disponíveis:\n");
	for(int cont = 0; cont < i; cont++){
	    printf("%s. %s - %d Unidades\n", itens[cont].id, itens[cont].nome, itens[cont].uni);
	}
	
	printf("Adicionar Item (digite 1)\n");
	printf("Voltar (digite 0)\n\n");
	printf("Escolha: ");
	scanf(" %d", &d);
	
	//tratamento de erro
	while(d!=0 && d!=1) {
		printf("Comando inválido, digite novamente: ");
		scanf(" %d", &d);
	}
	
	switch(d){
	    //adicionar item
	    case 1:
	        additem();
	    
	    //voltar ao menu principal
	    case 0:
	        main();
	        break;
	}
}

//adicionar item TERMINAR
void additem(){
    printf("\nAdicionar Item\n");
    
    printf("ID do Item: ");
    fgets(itens[i].id, sizeof(itens[i].id), stdin);
    fgets(itens[i].id, sizeof(itens[i].id), stdin);
    strtok(itens[i].id, "\n");
    
    //atribuir nome ao item
    printf("Nome do Item: ");
    fgets(itens[i].nome, sizeof(itens[i].nome), stdin);
    fgets(itens[i].nome, sizeof(itens[i].nome), stdin);
    strtok(itens[i].nome, "\n");
    
    //ARRUMAR TRATAMENTO DE ERRO
    /*
    for(int cont = 0; cont < i; cont++){
        if(strcmp(nomeinput, nome[cont])==0){
            printf("Nome já está em uso, digite novamente: ");
            fgets(nomeinput, sizeof(nomeinput), stdin);
            strtok(nomeinput, "\n");
        }
    }
    */
    
    //atribuir unidades ao item
    printf("Unidades Disponíveis: ");
    scanf(" %d", &itens[i].uni);
    
    //atribuir preço ao item
    printf("Preço do Item: ");
    scanf(" %f", &itens[i].preco);
    
    i++;
    
    printf("\nItem Registrado!\n");
    
    estoque();
}

//submenu vendas
void vendas() {
    char item[4]; //para selecionar o item vendido
    int qtd; //para selecionar quantidade vendida
    float total; //total do valor vendido
    int achaitem = 0; //verifica se o ID digitado existe no estoque
    
	printf("\nVendas\n");
	//visualizaçãao dos itens
	printf("Itens Disponíveis:\n");
	for(int cont = 0; cont < i; cont++){
	    printf("%s. %s - R$%.2f\n", itens[cont].id, itens[cont].nome, itens[cont].preco);
	}
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
	        printf("\nItem Vendido (digite o ID do item): ");
	        scanf(" %s", item);
	        
	        for(int cont = 0; cont < i; cont++){
	            if(strcmp(item, itens[cont].id) == 0){
                    achaitem = cont;
                    break;
                }
	        }
	        
	        while(achaitem == 0){
                printf("ID inválido, digite novamente: ");
                scanf(" %s", item);
                for(int cont = 0; cont < i; cont++){
    	            if(strcmp(item, itens[cont].id) == 0){
                        achaitem = cont;
                        break;
                    }
    	        }
	        }
	        
	        printf("Quantidade Vendida: ");
	        scanf("%d", &qtd);
	        while((item==001 && qtd>itens[0].uni) || (item==002 && qtd>itens[1].uni) || (item==003 && qtd>itens[2].uni)){
	            printf("Quantidade maior do que itens em estoque, digite novamente: ");
	            scanf("%d", &qtd);
	        }
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
	                itens[0].vend = itens[0].vend + total;
	                itens[0].qtdvend = itens[0].qtdvend + qtd;
	                itens[0].uni = itens[0].uni - qtd;
	                vendas();
	                break;
	               
	            case 002:
	                total = qtd * 20.00;
	                total = pagamento(total);
	                printf("\n\nTotal vendido: R$%.2f \n", total);
	                printf("Receita Registrada! \n");
	                sald = sald + total;
	                itens[1].vend = itens[1].vend + total;
	                itens[1].qtdvend = itens[1].qtdvend + qtd;
	                itens[1].uni = itens[1].uni - qtd;
	                vendas();
	                break;
	                
	            case 003:
	                total = qtd * 45.00;
	                total = pagamento(total);
	                printf("\n\nTotal vendido: R$%.2f \n", total);
	                printf("Receita Registrada! \n");
	                sald = sald + total;
	                itens[2].vend = itens[2].vend + total;
	                itens[2].qtdvend = itens[2].qtdvend + qtd;
	                itens[2].uni = itens[2].uni - qtd;
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
	for(int cont = 0; cont < i; cont++){
	    printf("\nItem %s - Valor Vendido: R$%.2f ; Quantidade: %d", itens[cont].id, itens[cont].vend, itens[cont].qtdvend);
	}
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

void testador() {
    printf("\nBEM VINDO AO TESTADOR ONDE TUDO É TESTADO\n");
    printf("\nID's\n");
    for(int cont = 0; cont < i; cont++){
        printf("Item %d: %s \n", (cont + 1), itens[cont].id);
    }
    printf("\nNOMES\n");
    for(int cont = 0; cont < i; cont++){
        printf("Item %d: %s \n", (cont + 1), itens[cont].nome);
    }
    printf("\nUNIDADES\n");
    for(int cont = 0; cont < i; cont++){
        printf("Item %d: %d \n", (cont + 1), itens[cont].uni);
    }
    printf("\nPREÇOS\n");
    for(int cont = 0; cont < i; cont++){
        printf("Item %d: %.2f \n", (cont + 1), itens[cont].preco);
    }
    
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