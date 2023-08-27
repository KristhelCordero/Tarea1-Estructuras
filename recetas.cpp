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
    for(int i=0; i<numComponentes;i++) {
        cout <<"    -"<< componentes[i].nombre<<endl;
    }
    cout<<endl;
}

void BaseDatos::imprimirBaseDatos(){
    cout << "Nombre: " << nombre << endl;
    for(int i=0; i<cantidadCombos;i++) {
        cout <<"    -"<< arregloCombos[i].nombre << endl;
    }
}