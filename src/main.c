#include <stdio.h>
#include <stdlib.h>
#include "portabilidade.h"



void menu_ini();

void menu_edit();
void edit(int numero);
void erro_opcao();



int main (){
    menu_ini();
    limpar_tela();
    
    


}

void menu_ini(){
    
    
    int opcao = 0;
    
    while(opcao != 4){
        limpar_tela();
        printf("==============================================\n");
        printf("\n\tMENU PRINCIPAL (INIT-TASK)\n\n");
        printf("==============================================\n");
        printf("(1) Criar uma tarefa.\n");
        printf("(2) Editar tarefas existentes\n");
        printf("(3) Listar todas as tarefas\n");
        printf("(4) Exit\n");
            scanf("%d", &opcao);  
        
            if(opcao < 1 || opcao > 4) {
            erro_opcao();
        }

    switch(opcao){
        
        case 1:
            //tamo criando tamo criando
             break;

        case 2:
            //editar
            menu_edit();
            break;
        
        case 3:
            //saboor listar tarefas
            break;
        
        case 4:
            //muy triste com sua saida
            break;
    }

}
}


void menu_edit(){ //menu para selecionar o que deseja editar
    int opcao = 1;

    while (opcao != 5){
        limpar_tela();
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
        
            }else if(opcao != 5){
                edit(opcao);
            }
               
    }
}

void edit(int numero){
    limpar_tela();
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
                        esperar(1500);
                }   
            break;
        case 2: 
            //if(variavel do item concluido == 0){variavel do item = 1;}else if(variavel do item concluido == 1) {variavel do item = 0;}
            printf("O item foi concluido com sucesso!");
                esperar(1500);
            break;
        case 3:
            printf("Escolha um novo dia e horario:\n");
            printf("Escolha o dia e o mes:\n");
            //scanf("%d", variavel do dia);
            //scanf("%d", variavel do mes);
            break;
        case 4: 
            printf("Item removido com sucesso");
                esperar(1500);
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
