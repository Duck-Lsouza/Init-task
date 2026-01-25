#include <stdio.h>
#include <stdlib.h>
#include "portabilidade.h"

void menu_edit();
void edit(int numero);
void erro_opcao();


int main (){

    limpar_tela();
    menu_edit();


}


void menu_edit(){ //menu para selecionar o que deseja editar
    int opcao = 1;

    while (opcao != 5){
        printf("==============================================\n");
        printf("\n\tSELECIONE O QUE DESEJA FAZER:\n\n");
        printf("==============================================\n");
        printf("(1) Para mudar a prioridade.\n");
        printf("(2) Para marcar como concluido.\n");
        printf("(3) Para mudar o prazo.\n");
        printf("(4) Para excluir tarefas.\n");
        printf("(5) Para voltar.\n");
            scanf("%d", &opcao);
            if(opcao < 1 || opcao > 5) {
                erro_opcao();
        
            }else{
                edit(opcao);
            }
            
    }
}

void edit(int numero){

    int x;
    printf("=============================================================");
    switch(numero){
        case 1:
            printf("Escolha a nova prioridade para o item:\n");
            printf("(1) Urgente.\n");
            printf("(2) Importante.\n");
            printf("(3) Intermediário.\n");
            printf("(4) Não importante.\n");
                scanf("%d", &x);
                if(x < 1 || x > 4){
                    erro_opcao();
                }else {
                    //variavel da prioridade = x;
                    printf("Prioridade alterada com sucesso.");
                }
            break;
        case 2: 
            //if(variavel do item concluido == 0){variavel do item = 1;}else if(variavel do item concluido == 1) {variavel do item = 0;}
            printf("O item foi concluido com sucesso!");
            break;
        case 3:
            printf("Escolha um novo dia e horario:\n");
            printf("Escolha o dia e o mes:\n");
            //scanf("%d", variavel do dia);
            //scanf("%d", variavel do mes);
            break;
        case 4: 
            printf("Item removido com sucesso");
            //variavel do nó = NULL;
            break;

    }
}
void erro_opcao(){ //Função para usar para indicar que nenhuma opção foi selecionada.

    limpar_tela();

    printf("ERRO! Nenhuma opção foi selecionada.\n");
        esperar(1000);

    printf("Reiniciando...\n");
        esperar(1000);

    limpar_tela();
    }
