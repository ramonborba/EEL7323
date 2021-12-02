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
    set_prof_id();
    set_password();
}

void Professor::set_prof_id(int new_id){
    prof_id = new_id;
}

void Professor::set_password(string new_password){
    password = new_password;
}

int Professor::get_prof_id(){
    return prof_id;
}


string Professor::get_password(){
    return password;
}