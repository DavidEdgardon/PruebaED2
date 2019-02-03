//
// Created by ASUS on 2/1/2019.
//

#ifndef PRUEBAED2_KNOWNVARSIZE_REGISTER_H
#define PRUEBAED2_KNOWNVARSIZE_REGISTER_H


#include "DataFile.h"

class KnownVarSize_Register {
public:
     DataFile *file;
     int sizeName;
    char * name;
     int sizeJob;
    char *job;
    int code;
    double salary;


    void setSizeName(int size);
    int getSizeName();
    void setSizeJob(int size);
    int getSizeJob();
    void print_register( );
    char * toChar( );
    void fromChar(char *);
    void open_file (char *);
    void write_into_file();
    void read_from_file(int pos);
    void close_file( );
    int get_size(  );
};


#endif //PRUEBAED2_KNOWNVARSIZE_REGISTER_H
