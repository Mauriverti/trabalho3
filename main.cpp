#include <gerenciador.h>


int main() {

    Gerenciador g;
    
    int opcao = -1;
    
    while (opcao != 0) {
        system("cls");
        cout << "Escolha uma opcao" << endl;
        cout << "1 - Ler disco" << endl;
        cout << "2 - Formatar disco" << endl;
        cout << "3 - Acessar disco" << endl;
        cout << "4 - criar disco" << endl;
        cin >> opcao;

        switch(opcao) {
        case 1:
//            string nome;
//            cout << "\tInforme o nome do disco a ser lido: ";
//            cin >> nome;
//            g.setNomeDisco(nome);
            //cout << endl << "lala: " << g.getNomeDisco();

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
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
            cout << endl;
            system("pause");
            break;
        }
    }

//            abrir disco

//            formatar disco

//            copiar arquivo pra dentro

//            copiar arquivo pra fora

//            navegar?

    return 0;
}
