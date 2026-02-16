# Init-task: CLI To-Do List em C 📝

> *Projeto desenvolvido para a disciplina de Programação de Computadores da UFPel.*

O **Init-task** é um gerenciador de tarefas via linha de comando (CLI) desenvolvido em C. O projeto aplica conceitos fundamentais de estrutura de dados e engenharia de software para criar uma aplicação leve, persistente e multiplataforma.

## 🚀 Funcionalidades

* **CRUD de Tarefas:** Criação, leitura, edição (prioridade/status) e remoção de tarefas.
* **Persistência de Dados:** Utiliza manipulação de arquivos binários (`save.bin`) para carregar e salvar as tarefas automaticamente.
* **Priorização:** Sistema de classificação (Urgente, Importante, Intermediário, Não importante).
* **Multiplataforma:** Código modular com diretivas de pré-compilação para rodar nativamente em **Windows** e **Linux**.
* **UX Aprimorada:** Interface colorida no terminal e tratamento de acentuação (UTF-8).

## 🛠️ Tecnologias e Conceitos

* **Linguagem C**: Padrão ANSI/ISO.
* **Estruturas de Dados**: Lista Simplesmente Encadeada para gerenciamento dinâmico de memória (`malloc`/`free`).
* **Modularização**: Separação lógica em headers:
    * `main.c`: Lógica principal e menus.
    * `tarefas.h`: Definições de `structs` e constantes.
    * `portabilidade.h`: Abstração de funções de sistema (`system`, `sleep`) para compatibilidade entre OS.

## 📦 Como Compilar e Rodar

### Windows
Para incluir o ícone personalizado, você deve linkar o objeto de recursos:
```bash
gcc main.c recursos.o -o ToDoList.exe
./ToDoList.exe
