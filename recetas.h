#include <iostream>
using namespace std;

struct Componente{
    string nombre;
    int cantidad;
    string unidadMedida;

    Componente(){

    }

    void imprimirComponente();
};

struct Combo{
    string nombre;
    int cantPorciones;
    Componente componentes[2];

    Combo(string xNombre,int xPorciones,int cantComponentes){
        nombre=xNombre;
        cantPorciones=xPorciones;
        Componente componentes[cantComponentes];
    }
    void Combo::imprimirCombo();
};

struct BaseDatos{
    string nombre;
    Combo arregloCombos[];

    BaseDatos(){

    }
};
