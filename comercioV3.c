//bibliotecas
#include <stdio.h>
#include <stdlib.h>

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

//variáveis globais
float sald = 0; //saldo total
float vend[] = {0, 0, 0}; //valor vendido por cada item
int qtdvend[] = {0, 0, 0}; //quantidade vendida de cada item
int uni[] = {10, 10, 10}; //quantidade dos itens em estoque
float preco[] = {15, 20, 45}; //preço dos itens em estoque
char*id[] = {"001", "002", "003"}; //id dos itens em estoque
char*nome[] = {"Bosta", "Coco", "Merda"}; //nome dos itens em estoque
char d[1]; //decisões no programa

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
	fgets(d,sizeof(d),stdin);
	
	//tratamento de erro
	while(d!="1" && d!="2" && d!="3" && d!="0") {
		printf("Comando inválido, digite novamente: ");
		fgets(d,sizeof(d),stdin);
	}

	if(d=="1"){
	//submenu estoque
		estoque();

	}else if(d=="2"){
	//submenu vendas
		vendas();

	}else if(d=="3"){
	//submenu financeiro
		financeiro();
		
	}else if(d=="0"){
	//encerrar programa
	    printf("\nVendas Item %s: R$%.2f ; Quantidade: %d", id[0], vend[0], qtdvend[0]);
	    printf("\nVendas Item %s: R$%.2f ; Quantidade: %d", id[1], vend[1], qtdvend[1]);
	    printf("\nVendas Item %s: R$%.2f ; Quantidade: %d", id[2], vend[2], qtdvend[2]);
	    printf("\nSaldo final: R$%.2f", sald);
		printf("\n\nEncerrado");
		exit(0);
	}
}

//submenu estoque
void estoque() {
	printf("\nEstoque\n");
	printf("Itens Disponíveis:\n %s. %s - %d Unidades\n %s. %s - %d Unidades \n %s. %s - %d Unidades\n", id[0], nome[0], uni[0], id[1], nome[1], uni[1], id[2], nome[2], uni[2]);
	printf("Adicionar Item (digite 1)\n");
	printf("Voltar (digite 0)\n\n");
	printf("Escolha: ");
	fgets(d,sizeof(d),stdin);
	
	//tratamento de erro
	while(d!="0" && d!="1") {
		printf("Comando inválido, digite novamente: ");
		fgets(d,sizeof(d),stdin);
	}
	
	if(d=="1"){
	    //adicionar item
	    additem();
	    
	}else if(d=="0"){
	    //voltar ao menu principal
	    main();

	}
}

//adicionar item TERMINAR
void additem(){
    printf("\nAdicionar Item\n");
    printf("nao terminei ainda\n");
    estoque();

}

//submenu vendas
void vendas() {
    int item; //para selecionar o item vendido
    int qtd; //para selecionar quantidade vendida
    float total; //total do valor vendido
    
	printf("\nVendas\n");
	printf("Itens Disponíveis:\n %s. %s - R$%.2f\n %s. %s - R$%.2f\n %s. %s - R$%.2f\n", id[0], nome[0], preco[0], id[1], nome[1], preco[1], id[2], nome[2], preco[2]);
	printf("Registrar Venda (digite 1)\n");
	printf("Total Vendido Por Item (digite 2)\n");
	printf("Voltar (digite 0)\n\n");
	printf("Escolha: ");
	fgets(d,sizeof(d),stdin);
	
	//tratamento de erro
	while(d!="1" && d!="2" && d!="0") {
		printf("Comando inválido, digite novamente: ");
		fgets(d,sizeof(d),stdin);
	}
	
	if(d=="1"){
	    //registrar venda
	        printf("\nItem Vendido (digite o número do item): ");
	        scanf("%d", &item);
	        while(item!=001 && item!=002 && item!=003){
	            printf("Comando inválido, digite novamente: ");
		        scanf(" %d", &item);
	        }
	        printf("Quantidade Vendida: ");
	        scanf("%d", &qtd);
	        while((item==001 && qtd>uni[0]) || (item==002 && qtd>uni[1]) || (item==003 && qtd>uni[2])){
	            printf("Quantidade maior do que itens em estoque, digite novamente: ");
	            scanf("%d", &qtd);
	        }
	        printf("\nConfirmar? (1 para sim, 2 para não)\n");
	        printf("Escolha: ");
	        fgets(d,sizeof(d),stdin);
	        while(d!="1" && d!="2") {
		        printf("Comando inválido, digite novamente: ");
		        fgets(d,sizeof(d),stdin);
	        }
	        if(d=="2"){
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
	                uni[0] = uni[0] - qtd;
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
	                uni[1] = uni[1] - qtd;
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
	                uni[2] = uni[2] - qtd;
	                vendas();
	                break;
	        }
	        
	}else if(d=="2"){
	    //total vendido por categoria
	    totalpitem(total, item);
	    
	}else if(d=="0"){
	    //voltar ao menu principal
	    submenus();

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
        	    fgets(d,sizeof(d),stdin);
        	    while(d!="1" && d!="2") {
        		    printf("Comando inválido, digite novamente: ");
        	        fgets(d,sizeof(d),stdin);
        	    }
        	    break;
        }
	}while(d=="2");
	
	return total;
}

void totalpitem(float total, int item){
    printf("Valor e Quantidade Vendida por Item");
	printf("\nItem %s - Valor Vendido: R$%.2f ; Quantidade: %d", id[0], vend[0], qtdvend[0]);
	printf("\nItem %s - Valor Vendido: R$%.2f ; Quantidade: %d", id[1], vend[1], qtdvend[1]);
	printf("\nItem %s - Valor Vendido: R$%.2f ; Quantidade: %d", id[2], vend[2], qtdvend[2]);
	printf("\nVoltar (digite 0)\n");
	printf("Escolha: ");
	fgets(d,sizeof(d),stdin);
	while(d!="0"){
	    printf("Comando inválido, digite novamente: ");
		fgets(d,sizeof(d),stdin);
	}
	if(d=="0"){
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
	fgets(d,sizeof(d),stdin);
	
	while(d!="1" && d!="2" && d!="3" && d!="0") {
		printf("Comando inválido, digite novamente: ");
		fgets(d,sizeof(d),stdin);
	}
	
	if(d=="1"){
	    //registrar despesas
        despesas();
	    
	}else if(d=="2"){
	    //registrar receitas
	    receitas();
	       
	}else if(d=="3"){
	    //consultar saldo
	    saldo();
	}else if(d=="0"){
        //voltar ao menu principal
	    submenus();
	    
	}
}

//submenu financeiro: opção despesas
void despesas() {
    float des; //valor da despesa
    
    printf("\nValor da Despesa: R$");
	scanf(" %f", &des);
	printf("\nConfirmar? (1 para sim, 2 para não)\n");
	printf("Escolha: ");
	fgets(d,sizeof(d),stdin);
	while(d!="1" && d!="2") {
		printf("Comando inválido, digite novamente: ");
	    fgets(d,sizeof(d),stdin);
	}
	if(d=="2"){
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
	fgets(d,sizeof(d),stdin);
	while(d!="1" && d!="2") {
		printf("Comando inválido, digite novamente: ");
	    fgets(d,sizeof(d),stdin);
	}
	if(d=="2"){
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
    fgets(d,sizeof(d),stdin);

    while(d!="0") {
		printf("Comando inválido, digite novamente: ");
		fgets(d,sizeof(d),stdin);
	}
    if(d=="0"){
        financeiro();
    }
}