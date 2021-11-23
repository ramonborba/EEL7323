/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: pessoa.h
 * Description: Inheritance exercise - Student/Professor Registry
 */
#include <string>
using namespace std;

#include "../clk_cal/calendar.cpp"

//Class Pessoa definition
class Pessoa {
        string nome;
        Calendar birth;       
    public:
        Pessoa();
        void set_nome(string);
        void set_birth(int, int, int);
        string get_nome();
        void get_birth(int&, int&, int&);        
};