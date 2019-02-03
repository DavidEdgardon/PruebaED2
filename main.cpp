#include <iostream>
#include "FixedSize_Register.h"
#include "DataFile.h"
#include "KnownVarSize_Register.h"
#include "DelimiterVarSize_Register.h"

using namespace std;
int opc,opc1,opc2,opc3;
char a1[30] ="FixedArchivo.dat";
char a2[30] ="KnownArchivo.dat";
char a3[30] ="DelimiterArchivo.dat";


int main() {
    do {
        cout << "*** P R U E B A  P A R C I A L ***"<< endl;
        cout << "1. FixedSize_Register" << endl;
        cout << "2. KnownVarSize_Register" << endl;
        cout << "3. DelimiterVarSize_Register" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese una opcion:" << endl;
        cin >> opc;

        switch (opc) {
            case 1:
                FixedSize_Register a;
                cout << "** F I X E D  S I Z E **"<< endl;
                cout << "1. toChar" << endl;
                cout << "2. fromChar" << endl;
                cout << "3. openFile" << endl;
                cout << "4. Write" << endl;
                cout << "5. Read" << endl;
                cout << "6. Close" << endl;
                cout << "7. Print" << endl;
                cout << "8. Size" << endl;
                cout << "0. Regresar" << endl;
                cout << "Ingrese una opcion:" << endl;
                cin>>opc1;

                switch (opc1){
                    case 1:
                        a.toChar();
                        break;
                    case 2:
                        a.fromChar(a1);
                        break;
                    case 3:
                        a.open_file(a1);
                        break;
                    case 4:
                        a.write_into_file();
                        break;
                    case 5:
                        int pos;
                        cout<<"Posicion del archivo a leer: ";
                        cin>>pos;
                        a.read_from_file(pos);
                        break;
                    case 6:
                        a.close_file();
                        break;
                    case 7:
                        a.print_register();
                        break;
                    case 8:
                        a.get_size();
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                KnownVarSize_Register b;
                cout << "** K N O W N  V A R  S I Z E **" << endl;
                cout << "1. toChar" << endl;
                cout << "2. fromChar" << endl;
                cout << "3. openFile" << endl;
                cout << "4. Write" << endl;
                cout << "5. Read" << endl;
                cout << "6. Close" << endl;
                cout << "7. Print" << endl;
                cout << "8. Size" << endl;
                cout << "0. Regresar" << endl;
                cout << "Ingrese una opcion:" << endl;
                cin>>opc2;

                switch (opc2){
                    case 1:
                        b.toChar();
                        break;
                    case 2:
                        b.fromChar(a2);
                        break;
                    case 3:
                        b.open_file(a2);
                        break;
                    case 4:
                        b.write_into_file();
                        break;
                    case 5:
                        int pos;
                        cout<<"Posicion del archivo a leer: ";
                        cin>>pos;
                        b.read_from_file(pos);
                        break;
                    case 6:
                        b.close_file();
                        break;
                    case 7:
                        b.print_register();
                        break;
                    case 8:
                        b.get_size();
                        break;
                    default:
                        break;
                }
                break;
            case 3:
                DelimiterVarSize_Register c;
                cout << "** D E L I M I T E R  V A R  S I Z E **" << endl;
                cout << "1. toChar" << endl;
                cout << "2. fromChar" << endl;
                cout << "3. openFile" << endl;
                cout << "4. Write" << endl;
                cout << "5. Read" << endl;
                cout << "6. Close" << endl;
                cout << "7. Print" << endl;
                cout << "8. Size" << endl;
                cout << "0. Regresar" << endl;
                cout << "Ingrese una opcion:" << endl;
                cin>>opc3;

                switch (opc3){
                    case 1:
                        c.toChar();
                        break;
                    case 2:
                        c.fromChar(a3);
                        break;
                    case 3:
                        c.open_file(a3);
                        break;
                    case 4:
                        c.write_into_file();
                        break;
                    case 5:
                        int pos;
                        cout<<"Posicion del archivo a leer: ";
                        cin>>pos;
                        c.read_from_file(pos);
                        break;
                    case 6:
                        c.close_file();
                        break;
                    case 7:
                        c.print_register();
                        break;
                    case 8:
                        c.get_size();
                        break;
                    default:
                        break;
                }
                break;
            default:
                exit(0);
        }
    }while(opc!=0);

    return  0;
}