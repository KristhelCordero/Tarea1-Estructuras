#include "recetas.h"

void Componente::imprimirComponente(){
    cout << "Nombre: " << nombre << endl;
    cout << "Cantidad: " << cantidad << endl;
    cout << "Unidad de medida: " << unidadMedida << endl;
}

void Combo::imprimirCombo(){
    cout<<"Nombre: "<< nombre << endl;
    cout<<"Porciones: "<< cantPorciones << endl;
    cout<<"Componentes: "<< endl;
    int numComponentes=sizeof(componentes)/sizeof(componentes[0]);
    for(int i=0; i<numComponentes;i++) {
        cout << componentes[i].nombre<<" ";
    }
}

void BaseDatos::imprimirBaseDatos(){
    int numComponentes=sizeof(arregloCombos)/sizeof(arregloCombos[0]);
    for(int i=0; i<numComponentes;i++) {
        cout << arregloCombos[i].nombre<<" ";
    }
}