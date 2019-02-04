//
// Created by ASUS on 2/1/2019.
//

#include "FixedSize_Register.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

FixedSize_Register::FixedSize_Register()
{
    this->name = new char[30];
    this->job = new char[20];
}

FixedSize_Register::~FixedSize_Register()
{
    delete[] this->name;
    delete[] this->job;
    delete this->file;
}


void FixedSize_Register::print_register() {
    file->archivo->seekg(0, ios::beg);
    FixedSize_Register tmp;

    file->archivo->read(reinterpret_cast<char *>(&tmp) ,get_size());
    while (!file->archivo->eof()){
        cout << "Name: " << tmp.name << "\nCode: " << tmp.code << "\nJob: "
             << tmp.job<< "\nSalary: " << tmp.salary<<endl;
        file->archivo->read(reinterpret_cast<char *>(&tmp) ,get_size());
    }

    file->cerrar();
}

char* FixedSize_Register::toChar() {
    char separacion = ' ';
    char final = '|';
    int tamRegistro = this->get_size();
    char *nuevo = new char[tamRegistro];
    int pos = 0;

    memcpy(&nuevo[pos], this->name, 30);
    pos += 30;
    memcpy(&nuevo[pos], &separacion, 1);
    pos++;

    memcpy(&nuevo[pos], (char*)&this->code, sizeof(int));
    pos += 4;
    memcpy(&nuevo[pos], &separacion, 1);
    pos++;

    memcpy(&nuevo[pos], this->job, 20);
    pos += 20;
    memcpy(&nuevo[pos], &separacion, 1);
    pos++;

    memcpy(&nuevo[pos], (char*)&this->salary, sizeof(double));
    pos += sizeof(double);
    memcpy(&nuevo[pos], &final, 1);
    return nuevo;
}

void FixedSize_Register::fromChar(char * buffer) {
    string tmp = "";
    int tamActual = 0;
    int posActual = 0, i = 0;
    bool final = false;

    while(!final) {
        if (buffer[i] == '|') {
            if (posActual == 0) {
                strcpy(this->name, (char*)&tmp);
                posActual++;
            }
            else if (posActual == 1) {
                strcpy(this->job, (char*)&tmp);
                posActual++;
            }
            else if (posActual == 2) {
                this->code = stoi(tmp);
                posActual++;
            }
            else if (posActual == 3) {
                this->salary = stoi(tmp);
                final = true;
            }
            tmp = "";
            tamActual = 0;
        }
        tmp += buffer[i];
        tamActual++;
    }
}

void FixedSize_Register::open_file(char * archivo) {

    file = new DataFile(archivo);
    file ->abrir();
}

void FixedSize_Register::close_file() {
    file->cerrar();
}

void FixedSize_Register::write_into_file() {
    this->file->abrir();
  //  this->file->escribir(, this->get_size());
    this->file->cerrar();
}
void FixedSize_Register::read_from_file(int pos) {
    this->file->abrir();
    char *data = this->file->leer(pos, this->get_size());
    this->fromChar(data);
    this->file->cerrar();
    delete data;
}

int FixedSize_Register::get_size() {
    int size= sizeof(code)+ sizeof(name)+sizeof(salary)+ sizeof(job);
    return size;
}