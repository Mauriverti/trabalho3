#include <gerenciador.h>

int main() {

    Gerenciador g;
    
    int opcao = -1;
    string nome;
    
    while (opcao != 0) {
        system("cls");
        cout << "Escolha uma opcao" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Ler disco" << endl;
        cout << "2 - Formatar disco" << endl;
        cout << "3 - Acessar disco" << endl;
//        cout << "4 - criar disco" << endl;
        cin >> opcao;

        switch(opcao) {
            case 1: {
                cout << "\tInforme o nome do disco a ser lido: ";
                cin >> nome;
                g.abrirDisco(QString::fromStdString(nome));
                break;
            }
            case 2: {
                if (nome.empty()) {
                    cout << endl << "Nenhum disco aberto!";
                } else {
                    g.formatarDisco(QString::fromStdString(nome));
                }

                break;
            }
            case 3: {
                if (nome.empty()) {
                    cout << endl << "Nenhum disco aberto!";
                } else {
                    g.exibirDiretorio(0);
                }


                break;
            }
            case 4: {
                string discoNome;
                string tipoTamanho;
                int tamanho;
                cout << "\tInforme o nome do disco: ";
                cin >> discoNome;
                cout << "\n\tInforme o tamanho do disco do disco: ";
                cin >> tamanho;
                cout << "\n\tInforme o tipo do tamanho (KB, MB ou GB): ";
                cin >> tipoTamanho;

                QString _discoNome = QString::fromStdString(discoNome);

                g.criaDisco(_discoNome, tamanho, tipoTamanho);
                break;
            }
        }
        if (opcao != 0) {
            cout << endl;
            system("pause");
        }
    }


//            copiar arquivo pra dentro

//            copiar arquivo pra fora

//            navegar?

    return 0;
}
