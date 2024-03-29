//
// Created by ASUS on 2/1/2019.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include "KnownVarSize_Register.h"

using namespace std;


KnownVarSize_Register::KnownVarSize_Register() {

   }

KnownVarSize_Register::~KnownVarSize_Register() {
    delete[] this->name;
    delete[] this->job;
    delete this->file;
}


void KnownVarSize_Register::print_register(){
    file->archivo->seekg(0, ios::beg);

    KnownVarSize_Register actual;

    file->archivo->read(reinterpret_cast<char *>(&actual) ,get_size());
    while (!file->archivo->eof()){
        cout << "Name: " << actual.name << "\nCode: " << actual.code << "\nJob: " << actual.job
             << "\nSalary: " << actual.salary<<endl;

    }
    file->archivo->read(reinterpret_cast<char *>(&actual) ,get_size());
    file->cerrar();
}

char *KnownVarSize_Register:: toChar(){
    char final = '|';
    char separacion = ';';
    int tamRegistro = this->get_size();
    char *nuevo = new char[tamRegistro];
    int pos = 0;

    memcpy(&nuevo[pos], (char*)this->sizeName, sizeof(int));
    pos += 4;
    memcpy(&nuevo[pos], this->name, this->sizeName);
    pos += this->sizeName;
    memcpy(&nuevo[pos], &final, 1);
    pos++;
    memcpy(&nuevo[pos], (char*)this->sizeJob, sizeof(int));
    pos += 4;
    memcpy(&nuevo[pos], this->job, this->sizeJob);
    pos += this->sizeJob;
    memcpy(&nuevo[pos], &final, 1);
    pos++;
    memcpy(&nuevo[pos], (char*)&this->code, sizeof(int));
    pos += sizeof(int);
    memcpy(&nuevo[pos], &final, 1);
    pos++;
    memcpy(&nuevo[pos], (char*)&this->salary, sizeof(int));
    pos += sizeof(int);
    memcpy(&nuevo[pos], &final, 1);
    pos++;
    memcpy(&nuevo[pos], &separacion, 1);
    return nuevo;
}

void KnownVarSize_Register::fromChar( char * bufer) {
    string tmp = "";
    int tamActual = 0;
    int posActual = 0, i = 0;
    bool final = false;

    while (!final) {
        if (bufer[i] == '|') {
            if (posActual == 0) {
                strcpy(this->name, (char *) &tmp);
                posActual++;
            } else if (posActual == 1) {
                strcpy(this->job, (char *) &tmp);
                posActual++;
            } else if (posActual == 2) {
                this->code = stoi(tmp);
                posActual++;
            } else if (posActual == 3) {
                this->salary = stoi(tmp);
                final = true;
            }
            tmp = "";
            tamActual = 0;
        }
        tmp += bufer[i];
        tamActual++;
    }
}

void KnownVarSize_Register::open_file ( char *fil ){
    file = new DataFile(fil);
    file->abrir();
}

void KnownVarSize_Register::write_into_file(){
    this->file->abrir();
   // this->file->escribir(, this->get_size());
    this->file->cerrar();
}

void KnownVarSize_Register::read_from_file(int pos){
    file->leer(pos, 62);
}

void KnownVarSize_Register::close_file( ){
    file->cerrar();
}

int KnownVarSize_Register::get_size(  ){
    int size= sizeof(code)+sizeJob+sizeName+ sizeof(salary);
    return size;
}