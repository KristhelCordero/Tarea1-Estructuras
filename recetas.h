#include <iostream>
using namespace std;

struct Componente{
    string nombre;
    int cantidad;
    string unidadMedida;

    Componente() : cantidad(1) {} //!!!!!

    Componente(string _nombre, int _cantidad, string _unidadMedida ):
    nombre(_nombre), cantidad(_cantidad), unidadMedida(_unidadMedida){} 

    void imprimirComponente();
};

struct Combo{
    string nombre;
    int cantPorciones;
    Componente componentes[30];
    int numComponentes;

    Combo():cantPorciones(1){}

    Combo(string _nombre, int _cantPorciones, Componente* _componentes, int numComponentes)
        : nombre(_nombre), cantPorciones(_cantPorciones), numComponentes(numComponentes) {
        // if (numComponentes > 30) {
        //     cout << "El número de componentes excede el tamaño máximo." << endl;
        //     return;
        // }                    Hay que hacer validaciones
        for (int i = 0; i < numComponentes; ++i) {
            componentes[i]=_componentes[i];
        }
    }
    void imprimirCombo();
    };

struct BaseDatos{
    string nombre;
    BaseDatos(string xNombre, int cantidadCombos){
        nombre=xNombre;
        Combo arregloCombos[cantidadCombos];
    }
    void imprimirBaseDatos();
};
