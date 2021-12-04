/**
 * Author: Ramon de Araujo Borba < ramonborba97@gmail.com >
 * Institution: UFSC
 * Date: 10/11/2021
 * File: prof.cpp
 * Description: Inheritance exercise - Student/Professor Registry
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "prof.h"


//Membros da classe professor
Professor::Professor() : Pessoa() {
    pswd_is_set = false;
    set_prof_id();
    set_password();
}

void Professor::set_prof_id(int new_id){
    prof_id = new_id;
}

void Professor::set_password(string new_password){
    password = new_password;
    pswd_is_set = true;
}

int Professor::get_prof_id(){
    return prof_id;
}


string Professor::get_password(){
    return password;
}

void Professor::mod_password(){
    string new_pswd, cur_pswd;

    if (!pswd_is_set)
    {
        cout << "Digite nova senha: " << endl;
        cin >> new_pswd;
        set_password(new_pswd);
    }
    else 
    {
        cout << "Digite senha atual: " << endl;
        cin >> cur_pswd;
        if (check_password(cur_pswd))
        {
            cout << "Digite nova senha: " << endl;
            cin >> new_pswd;
            set_password(new_pswd);
        }
        else
        {
            cout << "Senha incorreta" << endl;
        }
    }
}

void Professor::delete_password(){
    string cur_pswd;
    
    cout << "Digite senha atual: " << endl;
    cin >> cur_pswd;
    if (check_password(cur_pswd))
    {
        set_password();
    }
    else
    {
        cout << "Senha incorreta" << endl;
    }
}


bool Professor::check_password(std::string pswd){
    if (pswd == password)
    {
        return true;
    }
    else
    {
        return false;
    }           
}