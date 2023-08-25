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
    while (numComponentes!=0){

    }
}

