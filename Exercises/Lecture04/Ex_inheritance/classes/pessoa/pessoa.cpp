/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: pessoa.cpp
 * Description: Inheritance exercise - Student/Professor Registry
 */
#include <iostream>
using namespace std;

#include "pessoa.h"


//Members of class Pessoa
Pessoa::Pessoa(){   //Necessita construtor da classe calendar???
    set_nome();
    set_birth();
}

void Pessoa::set_nome(string novo_nome){
    nome = novo_nome;
}

void Pessoa::set_birth(int m, int d, int y){
    birth.setCalendar(m, d, y);
}

string Pessoa::get_nome(){
    return nome;
}

void Pessoa::get_birth(int& m, int& d, int& y){
    birth.readCalendar(m, d, y);
}

/* class functions testing
int main()
{
    int op, d, day, m, mo, y, yr;
    string nome;
    Pessoa pessoa;
    bool sair=false;

    while (!sair) {
    cout << endl << "Operação: ";
    cin >> op;

    switch (op)
    {
    case 1:
        cout << "Nome: ";
        cin >> nome;
        pessoa.set_nome(nome);
        break;
    
    case 2:
        cout << endl << "Dia: ";
        cin >> d;
        cout << endl << "Mes: ";
        cin >> m;
        cout << endl << "Ano: ";
        cin >> y;
        pessoa.set_birth(m, d, y);
        break;
    
    case 3:
        cout << "Nome: " << pessoa.get_nome() << endl;
        break;
    
    case 4:
        pessoa.get_birth(mo, day, yr);
        cout << "Dia: " << d << endl << "Mes: " << m << endl << "Ano: " << y << endl;
        break;

    case 0:
        sair = true;
        break;

    default:
        break;
    }
    }
    return 0;
}
*/