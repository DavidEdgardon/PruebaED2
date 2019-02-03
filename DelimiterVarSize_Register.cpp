//
// Created by ASUS on 2/1/2019.
//

#include <iostream>
#include <fstream>
#include <cstring>

#include "DelimiterVarSize_Register.h"
using namespace std;

void DelimiterVarSize_Register:: print_register(){
    file->archivo->seekg(0, ios::beg);

    DelimiterVarSize_Register actual;

    file->archivo->read(reinterpret_cast<char *>(&actual) ,get_size());
    while (!file->archivo->eof()){
        cout << "Name: " << actual.name << "\nCode: " << actual.code << "\nJob: " << actual.job
             << "\nSalary: " << actual.salary<<endl;
    }
    file->archivo->read(reinterpret_cast<char *>(&actual) ,get_size());
    file->cerrar();
}

char *DelimiterVarSize_Register:: toChar( ){
    char caracter_separacion = ' ';
    char caracter_de_fin = '\n';
    int tamano_registro = this->get_size();
    char *nuevo = new char[tamano_registro];
    int pos = 0;

    memcpy(&nuevo[pos], this->name, 30);
    pos += 30;
    memcpy(&nuevo[pos], &caracter_separacion, 1);
    pos++;

    memcpy(&nuevo[pos], (char*)&this->code, sizeof(int));
    pos += 4;
    memcpy(&nuevo[pos], &caracter_separacion, 1);
    pos++;

    memcpy(&nuevo[pos], this->job, 20);
    pos += 20;
    memcpy(&nuevo[pos], &caracter_separacion, 1);
    pos++;

    memcpy(&nuevo[pos], (char*)&this->salary, sizeof(double));
    pos += sizeof(double);
    memcpy(&nuevo[pos], &caracter_de_fin, 1);
    return nuevo;
}


void DelimiterVarSize_Register::fromChar(char * bufer) {
    string temporal = "";
    int i = 0, tamanoActual = 0, posicionActual = 0;
    bool final = false;
    while (!final) {
        if (bufer[i] == '|') {
            if (posicionActual == 0) {
                strcpy(this->name, (char *) &temporal);
                posicionActual++;
            } else if (posicionActual == 1) {
                this->code = stoi(temporal);
                posicionActual++;
            } else if (posicionActual == 2) {
                strcpy(this->job, (char *) &temporal);
                final = true;
            } else if (posicionActual == 3) {
                this->salary = stoi(temporal);
                posicionActual++;
            }

            temporal = "";
            tamanoActual = 0;
        }
        temporal += bufer[i];
        tamanoActual++;
    }
}

void DelimiterVarSize_Register::open_file ( char * fil){
    file = new DataFile(fil);
    file->abrir();
}

void DelimiterVarSize_Register::write_into_file(){
    char *nuevo ;
 //  file->escribir(nuevo,get_size(),74);
}

void DelimiterVarSize_Register::read_from_file(int pos) {
    file->leer(pos, 62);
}

void DelimiterVarSize_Register::close_file(){
    file->cerrar();
}

int DelimiterVarSize_Register::get_size(){
    int size= sizeof(code)+ sizeof(job)+ sizeof(name)+ sizeof(salary);
    return size;
}