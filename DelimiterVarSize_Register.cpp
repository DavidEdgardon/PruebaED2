//
// Created by ASUS on 2/1/2019.
//

#include <iostream>
#include <fstream>
#include <cstring>

#include "DelimiterVarSize_Register.h"
using namespace std;

DelimiterVarSize_Register::DelimiterVarSize_Register() {

}

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

    int tamRegistro = this->get_size();
    char *nuevo = new char[tamRegistro];
    int pos = 0;
    char final = '|';
    char separacion = ';';

    int tamNombre = strlen(this->name);
    memcpy(&nuevo[pos], this->name, tamNombre);
    pos += tamNombre;
    memcpy(&nuevo[pos], &final, 1);
    pos++;
    int tamTrabajo = strlen(this->job);
    memcpy(&nuevo[pos], this->job, tamTrabajo);
    pos += tamTrabajo;
    memcpy(&nuevo[pos], &final, 1);
    pos++;
    memcpy(&nuevo[pos], (char*)&this->code, sizeof(int));
    pos += 4;
    memcpy(&nuevo[pos], &final, 1);
    pos++;
    memcpy(&nuevo[pos], (char*)&this->salary, sizeof(int));
    pos += 8;
    memcpy(&nuevo[pos], &final, 1);
    pos++;
    memcpy(&nuevo[pos], &separacion, 1);
    return nuevo;
}


void DelimiterVarSize_Register::fromChar(char * bufer) {
    string tmp = "";
    int i = 0, tamActual = 0, posActual = 0;
    bool final = false;
    while (!final) {
        if (bufer[i] == '|') {
            if (posActual == 0) {
                strcpy(this->name, (char *) &tmp);
                posActual++;
            } else if (posActual == 1) {
                this->code = stoi(tmp);
                posActual++;
            } else if (posActual == 2) {
                strcpy(this->job, (char *) &tmp);
                final = true;
            } else if (posActual == 3) {
                this->salary = stoi(tmp);
                posActual++;
            }

            tmp = "";
            tamActual = 0;
        }
        tmp += bufer[i];
        tamActual++;
    }
}

void DelimiterVarSize_Register::open_file ( char * fil){
    file = new DataFile(fil);
    file->abrir();
}

void DelimiterVarSize_Register::write_into_file(){
    this->file->abrir();
  //  this->file->escribir(, this->get_size());
    this->file->cerrar();
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