#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#include "portabilidade.h"
#include "tarefas.h"


void menu_ini(No** lista, int* prox_id);
void nova_tarefa(No** lista, int* contador_id);
void menu_edit(No** lista);
void listar(No* lista);
void edit(int numero, No **lista);
void erro_opcao();
No* find(No* lista, int idzada);
void remover(No** lista, int idzada);
int quantidade_tarefas = 0;


int main (){
    
    int prox_id = 1;

    No* lista = NULL;

    menu_ini(&lista, &prox_id);
    limpar_tela();
    
    return 0;
   
}

void menu_ini(No** lista, int* prox_id){
    
    
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
            nova_tarefa(lista, prox_id); 
            break;

        case 2:
            //editar
            menu_edit(lista);
            break;
        
        case 3:
            
        //saboor listar tarefas
            listar(*lista);
            break;
        
        case 4:
            //muy triste com sua saida
            break;
    }

}
}


void listar(No* lista){
    limpar_tela();
    
    /*a função não altera onde a lista começa, so percorre por isso 
    passamos uma copia do ponteiro(passagem por valor)
*/ 
    printf("=== LISTA DE TAREFAS ===\n\n");

    if(lista == NULL){
        printf("Nenhuma tarefa encontrada\n");
    } else {
        
        // ponteiro auxiliar apontado para o inicio da lista 
        No* aux = lista; 

        
        while(aux != NULL){
            printf("----------------------------------------\n");
            printf("ID: %d  |  Titulo: %s\n", aux->info.id, aux->info.titulo);
            
        
    
            printf("Prioridade: %d\n", aux->info.prioridade);
            printf("Status: %s\n", (aux->info.concluido) ? "[X] Concluido" : "[ ] Pendente");
            
            
            aux = aux->prox; 
        }
        printf("----------------------------------------\n");
    }

    printf("\n[Pressione Enter para voltar...]");
    limpar_buffer();
    getchar();
    
}
    




void menu_edit(No** lista){ //menu para selecionar o que deseja editar
    int opcao = 1;
    limpar_tela();
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
                edit(opcao, lista);
            }
               
    }
}
// Recebe No** (ponteiro duplo) porque precisamos alterar o ENDEREÇO para onde 
// o ponteiro 'lista' da main aponta (atualizar a cabeça da lista).
void nova_tarefa(No** lista, int* contador_id){
    limpar_tela();

    printf("=== Criando nova tarefa ===\n");

    No* novo_no = (No*) malloc(sizeof(No));
    
    novo_no->info.id = (*contador_id);
    (*contador_id)++; 
    
    getchar();
    printf("Digite o Titulo: ");
        fgets(novo_no->info.titulo, sizeof(novo_no->info.titulo), stdin);
    
    
    
    printf("Digite a prioridade: \n(1) Urgente.\n(2) Importante.\n(3) Intermediário.\n(4) Não importante.\n");
        scanf("%d", &novo_no->info.prioridade);


    //valores padroes, apenas testes felas
    novo_no->info.concluido = 0;
    novo_no->info.prazo.dia = 1; 
    novo_no->info.prazo.mes = 1; 
    novo_no->info.prazo.ano = 2024;

    //o "prox" aponta para onde a lista original apontava
    novo_no->prox = *lista;
    //a lista aponta para o novo no que criamos.
    *lista = novo_no;

    printf("\n>> Tarefa criada com sucesso! (ID: %d)\n", novo_no->info.id);
    quantidade_tarefas++;
    esperar(2000);
}





void edit(int numero, No** lista){
    limpar_tela();
    int x, id_aux;
    No *atual = *lista;
    
    printf("Digite o ID do item que deseja alterar: ");
      scanf("%d", &id_aux);

    printf("=============================================================\n");

    switch(numero){
        case 1:

        printf("Escolha a nova prioridade para o item:\n");
            printf("(1) Urgente.\n");
            printf("(2) Importante.\n");
            printf("(3) Intermediário.\n");
            printf("(4) Não importante.\n");
                scanf("%d", &x);
               if(x < 1 || x> 4){
                erro_opcao();
                break;
                
               }
                //procura se o id existe
                atual = find(*lista, id_aux);
                
                    
                    atual->info.prioridade = x;
                    printf("Prioridade alterada com sucesso.\n");
                        esperar(1500);
                        limpar_tela();
                  
            break;
        case 2: 
            atual = find(atual, id_aux);
            atual->info.concluido = 1;
            printf("O item foi concluido com sucesso!\n");
              
            esperar(1500);
            break;
        case 3:
            atual = find(atual, id_aux);
            printf("Escolha o dia e o mes:\n");
            scanf("%d", &atual->info.prazo.dia);
            scanf("%d", &atual->info.prazo.mes);
            printf("Escolha o novo ano: ");
            scanf("%d", &atual->info.prazo.ano);
            break;
        case 4: 
            remover(lista, id_aux);
            printf("Item removido com sucesso.");
                esperar(1500);
            return;

    }
}
void erro_opcao(){ //Função para usar para indicar que nenhuma opção foi selecionada.

    limpar_tela();

    printf("ERRO! Nenhuma opção foi selecionada.\n");
        esperar(1000);

    printf("Reiniciando...\n");
        esperar(1000);
        getchar();
    limpar_tela();
    }

No* find(No* lista, int idzada){
    No* atual = lista;
    int id_aux = idzada;

     while (atual != NULL && atual->info.id != id_aux){
            atual = atual->prox;
    }

    return atual;
}   

void remover(No **lista, int idzada){
    No *anterior, *proximo;
    anterior = NULL;
    proximo = *lista;

    if(proximo == NULL){
        printf("ERRO! LISTA VAZIA.");
        return;
    }
    if(proximo->info.id == idzada){
        *lista = proximo->prox;
        free(proximo);
        return;
    }

    while((proximo != NULL) && (proximo->info.id != idzada)){
        anterior = proximo;
        proximo = proximo->prox;
    }
    
    if(proximo != NULL){
        anterior->prox = proximo->prox;
        free(proximo);
    }else{
        erro_opcao();
    }
}
