/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   AnalisisSentimiento.cpp
 * Author: 999
 * 
 * Created on June 26, 2025, 10:38 PM
 */

#include "AnalisisSentimiento.hpp"

AnalisisSentimiento::AnalisisSentimiento() {
}

AnalisisSentimiento::AnalisisSentimiento(const AnalisisSentimiento& orig) {
}

AnalisisSentimiento::~AnalisisSentimiento() {
}

void AnalisisSentimiento::cargar_lexicon() {
    ifstream input("lexicon.csv", ios::in);
    char buffer[20];
    while (true) {
        string key;
        input.getline(buffer, 20, ',');
        if (input.eof()) break;
        key = buffer;
        input >> lexicon[key];
        input.get();
    }

}

void AnalisisSentimiento::cargar_comentarios_restaurantes() {
    ifstream input("comentarios.csv", ios::in);
    
    char nombre[100];
    int con=0;
    while (true) {
        input.getline(nombre, 100, ',');
        if (input.eof()) break;
        string key = nombre;
        Oracion orac;
        leer_oracion(input,orac);
        comentarios[key].push_back(orac);
//        orac.imprimir(output);
    }
}
void AnalisisSentimiento::procesar_oracion(string oracion, Oracion &orac) {
    int cont = 0;
    char word[30]{};
    for (char letra : oracion) {
        if (letra == ' ') {
            word[cont]=0;
            string key = word;
            if(cont > 0 )  orac.anadir_palabra(word,lexicon[key]);
            cont = 0;
        } else {
            word[cont] = letra;
            cont++;
        }
    }
}
void AnalisisSentimiento::pre_procesar_oracion(string &oracion) {

    for (char& c : oracion) {
        if (!isalpha(c)) {
            c = ' ';
        } else {
            c = tolower(c);
        }
    }
}
void AnalisisSentimiento::leer_oracion(ifstream &input, Oracion &orac) {
    string completo;
    getline(input, completo, '\n');
    pre_procesar_oracion(completo);
    procesar_oracion(completo,orac);
}
void AnalisisSentimiento::ordenar_comentarios(){
    for (auto &par : comentarios) {
        sort(par.second.begin(),par.second.end());
    }

}
void AnalisisSentimiento::mostrar(){
    ofstream output("prueba.txt",ios::out);
    
    for (auto par : comentarios) {
        output << "============================================"<<endl;
        output << par.first<<endl;
        output<<"=============================================="<<endl;
        for (Oracion orac : par.second) {
            orac.imprimir(output);
        }
    }
}