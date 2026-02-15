#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

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
void salvar(No *lista);
No *pull(int *prox_id);
int find_id(No **lista, int idzin);


int main (){
    int prox_id = 1;
    No* lista = NULL;
    lista = pull(&prox_id);
    setlocale(LC_ALL, "Portuguese");

    menu_ini(&lista, &prox_id);
    limpar_tela();
    
    return 0;
   
}

void menu_ini(No** lista, int* prox_id){
    
    
    int opcao = 0;
    
    while(opcao != 4){
        limpar_tela();
        printf(MAGENTA "================================================================\n");
        printf( "\n\t\tMENU PRINCIPAL (INIT-TASK)\n\n");
        printf("================================================================" RESET "\n\n");
        printf("(1) Criar uma tarefa.\n");
        printf("(2) Editar tarefas existentes.\n");
        printf("(3) Listar todas as tarefas.\n");
        printf("(4) Sair e salvar.\n");
        printf("\nDigite a opção: ");
            if(scanf("%d", &opcao) == 0){
                erro_opcao();
            }else if(opcao < 1 || opcao > 4) {
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
            salvar(*lista);
            break;
    }

}
}
// Recebe No** (ponteiro duplo) porque precisamos alterar o ENDEREÇO para onde 
// o ponteiro 'lista' da main aponta (atualizar a cabeça da lista).
void nova_tarefa(No** lista, int* contador_id){
    //usando a biblioteca time.h para atribuir a data da criação das tarefas
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    limpar_tela();

    printf(CYAN "======== Criando nova tarefa ========" RESET "\n");

    No* novo_no = (No*) malloc(sizeof(No));
    if(novo_no == NULL){
        printf("Erro ao alocar a memória.\n");
        return;
    }
    novo_no->info.id = (*contador_id);
    (*contador_id)++; 
    
    getchar();
    printf("Digite o Titulo: ");
        fgets(novo_no->info.titulo, sizeof(novo_no->info.titulo), stdin);
    
    
    
    printf("Digite a prioridade: \n(1) Urgente.\n(2) Importante.\n(3) Intermediário.\n(4) Não importante.\n");
        if(scanf("%d", &novo_no->info.prioridade) == 0){
            erro_opcao();
            free(novo_no);
            return;
        }else {

        
            while (novo_no->info.prioridade < 1 || novo_no->info.prioridade > 4){
            erro_opcao();
            printf(RED "Essa prioridade não existe."RESET "\nPor favor digite uma das 4 prioridades.\n");
            getchar();
            return;
        }
        }

    //valores padroes
    novo_no->info.concluido = 0;
    novo_no->info.prazo.dia = tm->tm_mday;
    novo_no->info.prazo.mes = tm->tm_mon + 1;
    novo_no->info.prazo.ano = tm->tm_year + 1900;

    //o "prox" aponta para onde a lista original apontava
    novo_no->prox = *lista;
    //a lista aponta para o novo no que criamos.
    *lista = novo_no;

    printf(GREEN "\n>> Tarefa criada com sucesso! (ID: %d)" RESET "\n", novo_no->info.id);
    esperar(2000);
}


void menu_edit(No** lista){ //menu para selecionar o que deseja editar
    int opcao = 1;
    limpar_tela();
    while (opcao != 4){
        limpar_tela();
        printf("==============================================\n\n");
        printf(CYAN"(1) Para mudar a prioridade.\n");
        printf("(2) Para marcar como concluido.\n");
        printf("(3) Para excluir tarefas.\n");
        printf("(4) Para voltar." RESET "\n\n");
        printf("==============================================\n\n");
        printf("Selecione o que deseja alterar: ");
            if(scanf("%d", &opcao) == 0){
                erro_opcao();
            }else if(opcao < 1 || opcao > 4) {
                erro_opcao();
        
            }else if(opcao != 4){
                edit(opcao, lista);
            }
               
    }
}
void edit(int numero, No** lista){
    limpar_tela();
    int x, id_aux;
    No *atual = *lista;
    
    printf("Digite o ID do item que deseja alterar: ");
    while(scanf("%d", &id_aux) == 0){

        erro_opcao();
        return;
      }
    if(find_id(lista, id_aux) == 1){
        printf(RED "ID não encontrado." RESET "\nPor favor digite um ID válido.\n");
        esperar(1000);
        return;
    }
    printf("\n---------------------------------------------------------------\n");

    switch(numero){
        case 1:

        printf("Escolha a nova prioridade para o item:\n");
            printf("(1) Urgente.\n");
            printf("(2) Importante.\n");
            printf("(3) Intermediário.\n");
            printf("(4) Não importante.\n");
                if(scanf("%d", &x) == 0){
                    erro_opcao();
                    break;
                }else if(x < 1 || x> 4){
                    erro_opcao();
                    printf(RED"Essa prioridade não existe."RESET  "\nPor favor digite uma das 4 prioridades.\n");
                    getchar();
                break;
                
               }
                //procura se o id existe
                atual = find(*lista, id_aux);
                
                    
                    atual->info.prioridade = x;
                    printf(GREEN ">> Prioridade alterada com sucesso." RESET "\n");
                        esperar(1500);
                        limpar_tela();
                  
            break;
        case 2: 
            atual = find(atual, id_aux);
            if(atual->info.concluido == 1){
                printf("Esse item já foi concluido.\n");
                esperar(1500);
                return;
            }
            atual->info.concluido = 1;
            printf(GREEN ">> O item foi concluido com sucesso!"RESET"\n");
              
            esperar(1500);
            break;
        case 3: 
            remover(lista, id_aux);
            break;;

    }
}



void listar(No* lista){
    limpar_tela();
    
    /*a função não altera onde a lista começa, so percorre por isso 
    passamos uma copia do ponteiro(passagem por valor)
*/ 
    printf("\t\t\t\t" MAGENTA "=== LISTA DE TAREFAS ===" RESET "\n\n");

    if(lista == NULL){
        printf(RED "Nenhuma tarefa encontrada."RESET "\n");
    } else {
        
        // ponteiro auxiliar apontado para o inicio da lista 
        No* aux = lista; 

        
        while(aux != NULL){
            int p = aux->info.prioridade;
            printf("-----------------------------------------------------------------------\n");
            aux->info.titulo[strcspn(aux->info.titulo, "\n")] = '\0';
            printf("ID: " YELLOW " %d" RESET "\t|  Titulo:" YELLOW " %s" RESET "\t|  Data da tarefa:" YELLOW " %d/%d/%d" RESET "\n\n\n", aux->info.id, aux->info.titulo, aux->info.prazo.dia, aux->info.prazo.mes, aux->info.prazo.ano);
            
        
    
            printf("Prioridade:" YELLOW " %s" RESET "\n", nome_prioridade[p]);
            printf("Status: %s\n", (aux->info.concluido) ? GREEN "[X] Concluido" RESET : RED "[ ] Pendente" RESET);
            
            aux = aux->prox; 
        }
        printf("-----------------------------------------------------------------------\n");
    }

    printf("\n[Pressione Enter para voltar...]");
    limpar_buffer();
    getchar();
    
}
    




void erro_opcao(){ //Função para usar para indicar que nenhuma opção foi selecionada.

    limpar_tela();

    printf(RED "ERRO! Entrada inválida.\n" RESET);
        esperar(1000);

    printf("Reiniciando...\n");
        esperar(1000);
        limpar_buffer();
    limpar_tela();
    
}

No* find(No* lista, int idzada){
    No* atual = lista;
    int id_aux = idzada;

    while (atual != NULL && atual->info.id != id_aux){
            atual = atual->prox;
    }
    if(atual == NULL){
        printf(RED "ID não encontrado." RESET "\n");
        getchar();
        return NULL;
    }

    return atual;
}   

void remover(No **lista, int idzada){
    No *anterior, *proximo;
    anterior = NULL;
    proximo = *lista;

    if(proximo == NULL){
        printf(RED "ERRO! LISTA VAZIA." RESET);
        esperar(1000);
        return;
    }
    if(proximo->info.id == idzada){
        *lista = proximo->prox;
        free(proximo);
    }else{

    

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
    printf(GREEN"\n>> Item removido com sucesso." RESET);
        esperar(1500);
}

void salvar(No *lista){
    FILE *fp = fopen("save.bin", "wb");
    No *salvar = lista;


    if(fp == NULL){
        printf(RED "ERRO! IMPOSSÍVEL SALVAR." RESET "\n");
        esperar(1000);
        return;
     }

    while (salvar != NULL){
        fwrite(&salvar->info, sizeof(salvar->info), 1, fp);
        salvar = salvar->prox;
    }

    fclose(fp);
    while(lista != NULL){
        salvar = lista;
        lista = lista->prox;
        free(salvar);
    }
}

No *pull(int *prox_id){
    FILE *fp = fopen("save.bin", "rb");
    No *puxar_ini = NULL;
    No *puxar_at = NULL;
    Tarefa temp;

   
    if(fp == NULL){
        return NULL;

    }else{
        while (fread(&temp, sizeof(temp), 1, fp) == 1){

            No *new= (No*)malloc(sizeof(No));
            new->info = temp;
            new->prox = NULL;

            if(puxar_ini == NULL){

                puxar_ini = new;
                puxar_at = puxar_ini;

            }else{

                puxar_at->prox = new;
                puxar_at = puxar_at->prox; 

            }
            if(puxar_at->info.id >= *prox_id){
                *prox_id = puxar_at->info.id + 1;
            }
        }
    }
    fclose(fp);

    return puxar_ini;
}
int find_id(No **lista, int idzin){
    No* atual = *lista;
    int id_aux = idzin;

    while (atual != NULL && atual->info.id != id_aux){
            atual = atual->prox;
    }
    if(atual == NULL){
        printf(RED "ID não encontrado." RESET "\n");
        esperar(1000);
        return 1;
    }

    return 0;
}