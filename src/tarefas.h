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

//funções utei


// Limpa o buffer de entrada (stdin).
// Usa 'int' para tratar corretamente o EOF que getchar() pode retornar.
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//vetor para prioridades
const char *nome_prioridade[] = {
    "Indefinido",
    "Urgente",
    "Importante",
    "Intermediário",
    "Não importante"
};
//cores para o terminal
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define BOLD "\033[1m"