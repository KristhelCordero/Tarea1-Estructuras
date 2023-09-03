#include <iostream>
using namespace std;

struct Componente{
    string nombre;
    int cantidad;
    string unidadMedida;

    Componente() : cantidad(1) {} //!!!!!

    Componente(string _nombre, int _cantidad, string _unidadMedida):
    nombre(_nombre), cantidad(_cantidad), unidadMedida(_unidadMedida){} 

    void imprimirComponente();
};

struct Combo{
    string nombre;
    int cantPorciones;
    Componente arrayComponentes[30];
    int cantComponentes;

    Combo():cantPorciones(1){}

    Combo(string _nombre, int _cantPorciones, Componente* _componentes, int _cantComponentes)
        : nombre(_nombre), cantPorciones(_cantPorciones), cantComponentes(_cantComponentes) {
        // if (numComponentes > 30) {
        //     cout << "El número de componentes excede el tamaño máximo." << endl;
        //     return;
        // }                    Hay que hacer validaciones
        for (int i = 0; i < cantComponentes; ++i) {
            arrayComponentes[i]=_componentes[i];
        }
    }

    int buscarNumeroComponente(string nombre);
    void setCantComponentes(int nuevaCantComponentes);
    void agregarComponente();
    void calcularPorciones(int nuevaCantidad);
    void setNombre(string nuevoNombre);
    void imprimirCombo();
    void modificarCantidadComponenete();
};


struct BaseDatos{
    string nombre;
    Combo arrayCombos[100];
    int cantCombos;

    BaseDatos():nombre("BD"),cantCombos(0){} 

    BaseDatos(string _Nombre, int _cantidadCombos, Combo* _ptCombos){
        nombre=_Nombre;
        cantCombos=_cantidadCombos;
        // ptArray= new Combo[_cantidadCombos];
        for (int i = 0; i < _cantidadCombos; ++i) {
            arrayCombos[i]=_ptCombos[i];
        }
    }
    int buscarNumeroCombo();
    void setCantCombos(int nuevaCantidadCombos);
    void modificarCombo();
    void buscarCombo();
    void encontrarComboPorciones();
    void encontrarComboComponente();
    void agregarCombo();
    void imprimirBaseDatos();
    void borrarCombo();
    void imprimirTodoslosCombos();
};