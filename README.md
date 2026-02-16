Aqui está a versão final do **README.md**, atualizada com o link do GitHub do seu colega.

É só copiar o bloco de código abaixo e colar no seu arquivo `README.md`:

```markdown
# Init-task: Sistema de Gerenciamento de Tarefas 📝

> *Projeto desenvolvido para a disciplina de Programação de Computadores da Universidade Federal de Pelotas (UFPel).*

O **Init-task** é uma aplicação de lista de tarefas (To-Do List) via linha de comando (CLI), desenvolvida inteiramente em linguagem C. O projeto foi construído com foco em **portabilidade**, **gestão eficiente de memória** e **persistência de dados**.

## 🚀 Funcionalidades

* **Gerenciamento Completo (CRUD):** Permite criar, listar, editar (status/prioridade) e remover tarefas.
* **Persistência de Dados:** Utiliza arquivos binários (`save.bin`) para salvar e carregar as tarefas automaticamente, garantindo que os dados não sejam perdidos ao fechar o programa.
* **Priorização:** Sistema de classificação de tarefas: *Urgente*, *Importante*, *Intermediário* e *Não importante*.
* **Multiplataforma:** Código preparado para rodar nativamente em **Windows** e **Linux**, com funções adaptadas para cada sistema operacional (limpeza de tela, `sleep`, acentuação).
* **Interface Visual:** Uso de cores ANSI no terminal para melhorar a legibilidade e ícone personalizado no executável (Windows).

## 🛠️ Tecnologias e Conceitos

* **Linguagem C**: Padrão ANSI/ISO.
* **Estruturas de Dados**: Lista Simplesmente Encadeada para armazenamento dinâmico (`malloc`/`free`).
* **File I/O**: Manipulação de arquivos binários (`fread`, `fwrite`).
* **Modularização**: Código organizado em arquivos de cabeçalho (`.h`) para melhor manutenção.

## 📦 Como Compilar e Rodar

Para rodar o projeto, você precisará de um compilador C (como o GCC).

### Windows
Para incluir o ícone personalizado e garantir a execução correta, compile linkando o arquivo de recursos:

```bash
gcc main.c recursos.o -o ToDoList.exe
./ToDoList.exe

```

### Linux

No Linux, a compilação é direta:

```bash
gcc main.c -o ToDoList
./ToDoList

```

## 👥 Autores

Este projeto foi desenvolvido por:

* **Lúcio Vagner Carvalho Souza**
* **[Carlos Henrique Leite Bianchin](https://github.com/henrique-bianchin)**

---

Desenvolvido com 💙 e C na UFPel.

```

```
