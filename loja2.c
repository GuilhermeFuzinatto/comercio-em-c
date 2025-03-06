#include <stdio.h>

int main();

void submenus(char dec) {
    printf("O que deseja?\n");
	printf("Abrir Controle de Estoque (digite E)\n");
	printf("Abrir Controle de Venda (digite V)\n");
	printf("Abrir Controle Financeiro (digite F)\n");
	printf("Sair (digite S)\n");
	scanf(" %c", &dec);
	while(dec!='e' && dec!='v' && dec!='f' && dec!='s') {
		printf("Comando invC!lido, digite novamente: ");
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
		printf("Encerrado");
		return 0;
	}
}

void estoque(char dec) {
	printf("Estoque\n");
	printf("Itens Disponíveis:\n 1. Item\n 2. Item\n 3. Item\n");
	printf("Voltar (digite V)\n");
	scanf(" %c", &dec);
	while(dec!='v') {
		printf("Comando inválido, digite novamente: ");
		scanf(" %c", &dec);
	}
	if(dec=='v') {
		main();
	}
}

void vendas(char dec) {
	printf("Vendas\n");
	printf("Itens Disponíveis:\n 1. Item\n 2. Item\n 3. Item\n");
	printf("Voltar (digite V)\n");
	scanf(" %c", &dec);
	while(dec!='v') {
		printf("Comando inválido, digite novamente: ");
		scanf(" %c", &dec);
	}
	if(dec=='v') {
		main();
	}
}

void financeiro(char dec) {
	printf("Financeiro\n");
	printf("Registrar Despesas (digite D)\n");
	printf("Registrar Reveitas (digite R)\n");
	printf("Consultar Saldo (digite S)\n");
	printf("Voltar (digite V)\n");
	scanf(" %c", &dec);
	while(dec=='d' || dec=='r' || dec=='s') {
		printf("essa parte ainda não foi programada, então volta aí na moral\n");
		scanf(" %c", &dec);
	}
	while(dec!='d' && dec!='r' && dec!='s' && dec!='v') {
		printf("Comando inválido, digite novamente: ");
		scanf(" %c", &dec);
	}
	if(dec=='v') {
		main();
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
