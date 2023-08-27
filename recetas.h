#include <iostream>
using namespace std;

struct Componente{
    string nombre;
    int cantidad;
    string unidadMedida;

    Componente() : cantidad(1) {} //!!!!!

    Componente(string _nombre, int _cantidad, string _unidadMedida ):
    nombre(_nombre), cantidad(_cantidad), unidadMedida(_unidadMedida){} 

    void imprimirComponente(){
        cout << "Componente: " << nombre << endl << "Cantidad: " << cantidad << endl
        << "Unidad de medida: " << unidadMedida<<endl;
    }
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


    void imprimirCombo(){
        cout<<"Combo:"<<nombre<<endl;
        cout<<"Porciones:"<<cantPorciones<<endl;
        cout<<"Componentes"<<endl;
        for(int i=0; i<numComponentes;i++) {
            cout << componentes[i].nombre<<" ";
            }
        }
    };







struct BaseDatos{
    string nombre;
    Combo arregloCombos[];

    BaseDatos(){
    }
};
