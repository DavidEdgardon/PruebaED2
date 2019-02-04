//
// Created by ASUS on 2/1/2019.
//

#ifndef PRUEBAED2_FIXEDSIZE_REGISTER_H
#define PRUEBAED2_FIXEDSIZE_REGISTER_H


#include "DataFile.h"

class FixedSize_Register {
private:
    DataFile * file;
    char * name;//30
    char * job;//20
    int code;//4
    double salary;//8

public:
    FixedSize_Register();
    ~FixedSize_Register();
    void print_register();
    char * toChar();
    void fromChar(char *);
    void open_file(char *);
    void write_into_file();
    void read_from_file(int pos);
    void close_file();
    int get_size();
};


#endif //PRUEBAED2_FIXEDSIZE_REGISTER_H
