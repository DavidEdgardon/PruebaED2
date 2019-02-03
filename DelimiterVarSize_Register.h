//
// Created by ASUS on 2/1/2019.
//

#ifndef PRUEBAED2_DELIMITERVARSIZE_REGISTER_H
#define PRUEBAED2_DELIMITERVARSIZE_REGISTER_H


#include "DataFile.h"



class DelimiterVarSize_Register {
public:
     DataFile *file;
    char * name; //30
    int code; //4
    char *job; //20
    double salary; //8
//72

    void print_register( );
    char * toChar( );
    void fromChar( char * );
    void open_file ( char * );
    void write_into_file();
    void read_from_file(int pos);
    void close_file();
    int get_size();
};


#endif //PRUEBAED2_DELIMITERVARSIZE_REGISTER_H
