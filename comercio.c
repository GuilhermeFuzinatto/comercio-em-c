//bibliotecas
#include <stdio.h>

//funções utilizadas
int main();
void submenus(char dec);
void estoque(char dec);
void vendas(char dec);
void financeiro(char dec);

//abrir submenus
void submenus(char dec) {
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
		financeiro(d3);
		break;

	//encerrar programa
	case 's':
		printf("\nEncerrado");
	}
}

//submenu estoque
void estoque(char dec) {
	printf("\nEstoque\n");
	printf("Itens Disponíveis:\n 1. Item\n 2. Item\n 3. Item\n");
	printf("Voltar (digite V)\n\n");
	printf("Escolha: ");
	scanf(" %c", &dec);
	while(dec!='v') {
		printf("Comando inválido, digite novamente: ");
		scanf(" %c", &dec);
	}
	if(dec=='v') {
		main();
	}
}

//submenu vendas
void vendas(char dec) {
	printf("\nVendas\n");
	printf("Itens Disponíveis:\n 1. Item\n 2. Item\n 3. Item\n");
	printf("Voltar (digite V)\n\n");
	printf("Escolha: ");
	scanf(" %c", &dec);
	while(dec!='v') {
		printf("Comando inválido, digite novamente: ");
		scanf(" %c", &dec);
	}
	if(dec=='v') {
		main();
	}
}

//submenu financeiro
void financeiro(char dec) {
	printf("\nFinanceiro\n");
	printf("Registrar Despesas (digite D)\n");
	printf("Registrar Reveitas (digite R)\n");
	printf("Consultar Saldo (digite S)\n");
	printf("Voltar (digite V)\n\n");
	printf("Escolha: ");
	scanf(" %c", &dec);
	while(dec!='d' && dec!='r' && dec!='s' && dec!='v') {
		printf("Comando inválido, digite novamente: ");
		scanf(" %c", &dec);
	}
	
	switch(dec) {
        case 'd':
            printf("vaisefode");
	        break;
	    
	    case 'r':
	        printf("vaisefode");
	        break;
	        
	    case 's':
	        printf("vaisefode");
	        break;
	        
	    case 'v':
	        main();
	        break;
	    
	}
}

int main() {
	//variáveis de decisão
	char d2; //decisão: opções do menu principal
	char d3; //decisão: opções dos submenus

	//abrir submenus
	submenus(d2);
	
    return 0;
}