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
    Componente componentes[];

    Combo(){

    }

    void imprimirCombo();
};

struct BaseDatos{
    string nombre;
    Combo arregloCombos[];

    BaseDatos(){

    }
};
