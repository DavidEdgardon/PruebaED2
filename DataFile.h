//
// Created by ASUS on 2/1/2019.
//

#ifndef PRUEBAED2_DATAFILE_H
#define PRUEBAED2_DATAFILE_H
#include <fstream>

class DataFile {
    public:
        DataFile();
        DataFile(char *);

        void abrir();
        void cerrar();
        void escribir(char*, int, int);
        char* leer(int, int);

        void setArchivo(char*);

        char *direccion;
        std::fstream *archivo;
    };



#endif //PRUEBAED2_DATAFILE_H
