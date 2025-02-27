/*vamo faze o menu principal eba
usar do while pra ele ficar no programa ate pipipipopopo*/
#include <stdio.h>

int main(){
    char d1;
    char d2;
    char de;
    printf("Deseja abrir o menu? (S para Sim, N para Não): ");
    scanf(" %c", &d1);
    while(d1!='s' && d1!='n'){
        printf("Comando inválido, digite novamente: ");
        scanf(" %c", &d1);
    }
    do{
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
                    case 'e':
                        printf("Estoque\n");
                        printf("Cadastrar novo item (digite C)\n");
                        printf("Editar itens (digite E)\n");
                        printf("Abrir estoque (digite A)\n");
                        printf("Voltar (digite V)\n");
                        scanf(" %c", &de);
                        switch(de){
                            case 'v':
                            
                        }
                        break;
                    case 'v':
                        printf("Venda\n");
                        break;
                    case 'f':
                        printf("Financeiro\n");
                        break;
                    case 's':
                        printf("Encerrado");
                        break;
                }
                
                break;
                
            case 'n':
                printf("Encerrado");
                break;
        }
    }while(de=='v' && d2=='s');
    return 0;
}
