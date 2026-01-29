//aqui a gente so esta dando a definição de o que é uma tarefa
typedef struct{
    int dia, mes, ano;

}Data;

typedef struct{
    int id;
    char titulo [50];
    int prioridade;
    int concluido;
    Data prazo;

}Tarefa;

typedef struct No{
    Tarefa info;
    struct No* prox;
    
}No;

