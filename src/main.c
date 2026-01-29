#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#include "portabilidade.h"
#include "tarefas.h"


void menu_ini(No** lista);
void nova_tarefa(No** lista);
void menu_edit();
void edit(int numero);
void erro_opcao();



int main (){
    
    srand(time(NULL)); // variar o id das tarefas

    No* lista = NULL;

    menu_ini(&lista);
    limpar_tela();
    
    }

void menu_ini(No** lista){
    
    
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
            nova_tarefa(lista); 
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

void nova_tarefa(No** lista){
    limpar_tela();

    printf("=== Criando nova tarega ===\n");

    No* novo_no = (No*) malloc(sizeof(No));

    novo_no->info.id = rand() % 1000; 
    
    // Limpa o buffer do teclado (para o scanf não pular o titulo) 
    //esqueci se tem outro jeito, salva o codigo ai Henrique
    int c; while ((c = getchar()) != '\n' && c != EOF);

    printf("Digite o Titulo:");
        scanf("%49[^\n]", novo_no->info.titulo);
    
    
    //valores padroes, apenas testes felas
    novo_no->info.concluido = 0;
    novo_no->info.prazo.dia = 1; 
    novo_no->info.prazo.mes = 1; 
    novo_no->info.prazo.ano = 2024;

    novo_no->prox = *lista;

    *lista = novo_no;

    printf("\n>> Tarefa criada com sucesso! (ID: %d)\n", novo_no->info.id);
    esperar(2000);
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
