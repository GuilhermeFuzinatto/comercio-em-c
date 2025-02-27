#include <stdio.h>

int main(){
    //variáveis de decisão
    char d1; //decisão: abrir menu principal
    char d2; //decisão: opções do menu principal
    char d3; //decisão: opções dos submenus
    
    //abrir menu principal
    printf("Deseja abrir o menu? (S para Sim, N para Não): ");
    scanf(" %c", &d1);
    while(d1!='s' && d1!='n'){
        printf("Comando inválido, digite novamente: ");
        scanf(" %c", &d1);
    }
    
    do{
        //abrir submenus
        switch(d1){
            case 's':
                printf("O que deseja?\n");
                printf("Abrir Controle de Estoque (digite E)\n");
                printf("Abrir Controle de Venda (digite V)\n");
                printf("Abrir Controle Financeiro (digite F)\n");
                printf("Sair (digite S)\n");
                scanf(" %c", &d2);
                while(d2!='e' && d2!='v' && d2!='f' && d2!='s'){
                printf("Comando inválido, digite novamente: ");
                scanf(" %c", &d2);
                }
                
                switch(d2){
                    //submenu estoque
                    case 'e':
                        printf("Estoque\n");
                        printf("Itens Disponíveis:\n 1. Item\n 2. Item\n 3. Item\n");
                        printf("Voltar (digite V)\n");
                        scanf(" %c", &d3);
                        while(d3!='v'){
                            printf("Comando inválido, digite novamente:  ");
                            scanf(" %c", &d3);
                        }
                        break;
                        
                    //submenu vendas
                    case 'v':
                        printf("Vendas\n");
                        printf("Itens Disponíveis:\n 1. Item\n 2. Item\n 3. Item\n");
                        printf("Voltar (digite V)\n");
                        scanf(" %c", &d3);
                        while(d3!='v'){
                            printf("Comando inválido, digite novamente:  ");
                            scanf(" %c", &d3);
                        }
                        break;
                        
                    //submenu financeiro
                    case 'f':
                        printf("Financeiro\n");
                        printf("Registrar Despesas (digite D)\n");
                        printf("Registrar Reveitas (digite R)\n");
                        printf("Consultar Saldo (digite S)\n");
                        printf("Voltar (digite V)\n");
                        scanf(" %c", &d3);
                        while(d3=='d' || d3=='r' || d3=='s'){
                            printf("essa parte ainda não foi programada, então volta aí na moral\n");
                            scanf(" %c", &d3);
                        }
                        while(d3!='d' && d3!='r' && d3!='s' && d3!='v'){
                            printf("Comando inválido, digite novamente:  ");
                            scanf(" %c", &d3);
                        }
                        break;
                        
                    //encerrar programa
                    case 's':
                        printf("Encerrado");
                        return 0;
                }
                break;
            
            //encerrar programa
            case 'n':
                printf("Encerrado");
                break;
        }
    }while(d3=='v');
    return 0;
}