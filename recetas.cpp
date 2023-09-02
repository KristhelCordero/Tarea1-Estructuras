#include "recetas.h"


//----------------------------------COMPONENTES------------------------------
void Componente::imprimirComponente(){
    cout << "Nombre: " << nombre << endl;
    cout << "Cantidad: " << cantidad << endl;
    cout << "Unidad de medida: " << unidadMedida << endl;
}


//----------------------------------COMBOS------------------------------

void Combo::imprimirCombo(){
    cout << " "<<endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Porciones: "<<cantPorciones<<endl;
    cout << "Componentes: " << endl;
    for(int i=0; i<numComponentes;i++){
        cout <<"    -"<< componentes[i].nombre<<endl;
    }
    cout<<endl;
}



void Combo::setNombre(string nuevoNombre){
    nombre=nuevoNombre;
    cout<<"no se cae"<<endl;
}


//----------------------------------BASE DE DATOS------------------------------


void BaseDatos::agregarCombo(){
    string pNombreCombo;
    string cantPorc;
    int intCantPorc;
    
    //solicitud de datos
    cout << "\nIngrese el nombre del combo a agregar: " << endl;
    getline(cin,pNombreCombo);
    cout << "\nIngrese la cantidad de porciones del combo a agregar: " << endl;
    getline(cin,cantPorc);
    intCantPorc=stoi(cantPorc);
    cout << "\nIngrese el número de componentes del combo a agregar: " << endl;

    //creacion de Combo

    Combo nuevoCombo=Combo();
    ptArray[cantCombos]=nuevoCombo;
    cantCombos=cantCombos+1;

}


void BaseDatos::imprimirBaseDatos(){
    cout << "Nombre: " << nombre << endl;
    for(int i=0; i<cantCombos; i++){
        cout <<"    -"<< ptArray[i].nombre << endl;
    }
}