📝 Init-task | CLI Task Manager

<p align="center">
<img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" />
<img src="https://img.shields.io/badge/Platform-Linux%20%7C%20Windows-000000?style=for-the-badge&logo=linux&logoColor=white" />
<img src="https://img.shields.io/badge/UFPel-Computer%20Engineering-FFD700?style=for-the-badge" />
</p>

    Projeto desenvolvido para a disciplina de Programação de Computadores da Universidade Federal de Pelotas (UFPel).

O Init-task é um gerenciador de tarefas leve e eficiente que roda diretamente no seu terminal. Construído em C, o projeto foca no uso prático de alocação dinâmica de memória e manipulação de arquivos binários, oferecendo uma experiência robusta e multiplataforma.
🚀 Funcionalidades

    Gerenciamento CRUD: Controle total sobre suas tarefas (Criar, Ler, Atualizar e Deletar).

    Persistência Automática: Seus dados são salvos em save.bin e recarregados sempre que você inicia o programa.

    Níveis de Prioridade: Classificação visual para focar no que importa:

        🔴 Urgente | 🟠 Importante | 🟡 Intermediário | 🟢 Não importante.

    Core Multiplataforma: Suporte total para Windows e Linux, com tratamento nativo de cores ANSI, limpeza de tela e encoding de caracteres.

    Interface Intuitiva: Menus coloridos para facilitar a navegação via CLI.

🛠️ Tecnologias e Conceitos Aplicados

O projeto utiliza conceitos fundamentais de Ciência da Computação:

    Estruturas de Dados: Implementação de Lista Simplesmente Encadeada para gerenciamento dinâmico em tempo de execução.

    Gestão de Memória: Uso rigoroso de malloc e free para evitar memory leaks.

    Persistência: Manipulação de arquivos em modo binário (fread/fwrite) para maior performance e integridade.

    Modularização: Divisão lógica do código em módulos (.h e .c) para facilitar a manutenção.

📂 Estrutura do Projeto
Plaintext

├── src/
│   ├── main.c          # Ponto de entrada e loop principal
│   ├── tarefas.c       # Lógica das funcionalidades (CRUD)
│   ├── tarefas.h       # Protótipos e structs
│   └── util.c          # Funções auxiliares (UI/Sistema)
├── resources/
│   └── recursos.o      # Ícone e recursos (Windows)
└── save.bin            # Arquivo de persistência (gerado após uso)

📦 Como Compilar e Rodar

Certifique-se de ter o GCC (ou outro compilador C) instalado.
🐧 Linux

No terminal, utilize o comando:
Bash

gcc src/*.c -o init-task
./init-task

🪟 Windows

Para incluir o ícone personalizado, compile linkando o arquivo de recursos:
Bash

gcc src/*.c resources/recursos.o -o InitTask.exe
./InitTask.exe
