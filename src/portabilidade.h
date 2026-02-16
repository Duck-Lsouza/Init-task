/*para fins de portabilidade criamos um cabeçalho 
para tornar o nosso codigo executavel tanto no linux
quanto no windows, a necessidade se deu por precisarmos usar a biblioteca 
windows e a unistd */


#include <stdlib.h> 

#ifdef _WIN32
    // para o windows

    #include <windows.h>
   static void inicializar_terminal() { //Função para arrumar a acentuação do terminal
        system("chcp 65001 > nul");
        SetConsoleOutputCP(CP_UTF8);
    }
    static void limpar_tela() { 
        system("cls"); 
    }

    static void esperar(int ms) { 
        Sleep(ms); 
    
    }

#else
    //para o linux
    static void inicializar_terminal() { //Função para arrumar a acentuação do terminal
        
    }
    #include <unistd.h> 

    static void limpar_tela() { 
        system("clear"); 
    }

    // Converte e pausa (Linux usa microsegundos, então x1000)
    static void esperar(int ms) { 
        usleep(ms * 1000); 
    }

#endif
