#include <iostream>
using namespace std;

void pede_operando(float&, float&);

int main(int argc, char const *argv[])
{
    char sel;
    float x=0, y=0;
    system("clear");
    
    while (sel != 'e'){
        cout << "Calculadora C++" << endl;
        cout << endl;
        cout << "Operações do programa:" << endl;
        cout << "a - Adição" << endl;
        cout << "s - Subtração" << endl;
        cout << "m - Multiplicação" << endl;
        cout << "d - Divisão" << endl;
        cout << "e - Sair do programa" << endl;
        cout << "Selecione a operação: ";
        cin >> sel;
        if (sel == 'e') break;
        cout <<  endl;

        switch (sel)
        {
        case 'a':
            pede_operando(x, y);
            cout << endl;
            cout << "Resultado: " << (x+y) << endl;
            cout << "Pressione \"Enter\" Para continuar...";
            cin.ignore();
            cin.get();
            system("clear");
            break;
        
        case 's':
            pede_operando(x, y);
            cout << endl;
            cout << "Resultado: " << (x-y) << endl;
            cout << "Pressione \"Enter\" Para continuar...";
            cin.ignore();
            cin.get();
            system("clear");
            break;
        
        case 'm':
            pede_operando(x, y);
            cout << endl;
            cout << "Resultado: " << (x*y) << endl;
            cout << "Pressione \"Enter\" Para continuar...";
            cin.ignore();
            cin.get();
            system("clear");
            break;
        
        case 'd':
            pede_operando(x, y);
            cout << endl;
            cout << "Resultado: " << (x/y) << endl;
            cout << "Pressione \"Enter\" Para continuar...";
            cin.ignore();
            cin.get();
            system("clear");
            break;
        
        case 'e':
            break;
        
        default:
            cout << "Operação invalida" << endl;
            cout << "Pressione \"Enter\" Para continuar...";
            cin.ignore();
            cin.get();
            system("clear");
            break;
        }
    }
    return 0;
}

void pede_operando(float& a, float& b){
        cout << "Digite o operando 1: ";
        cin >> a;
        cout << "Digite o operando 2: ";
        cin >> b;
}