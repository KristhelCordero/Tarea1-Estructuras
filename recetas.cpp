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
    for(int i=0; i<cantComponentes;i++){
        cout <<"    -"<< componentes[i].nombre<<endl;
    }
    cout<<endl;
}

void Combo::setNombre(string nuevoNombre){
    nombre=nuevoNombre;
    cout<<"no se cae"<<endl;
}

void Combo::calcularPorciones(int nuevaCantidad){
    cout << "----------- CALCULAR PORCIONES ------------" << endl;

    for (int i = 0; i < cantComponentes; i++) {
        double cantidadNecesaria = (nuevaCantidad * 100)/componentes[i].cantidad;
        cout << componentes[i].nombre << ": " << cantidadNecesaria << " " 
        << componentes[i].unidadMedida << "\n";
    }
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
    arrayCombos[cantCombos]=nuevoCombo;
    cantCombos=cantCombos+1;

}


void BaseDatos::imprimirBaseDatos(){
    cout << "Nombre: " << nombre << endl;
    for(int i=0; i<cantCombos; i++){
        cout <<"    -"<< arrayCombos[i].nombre << endl;
    }
}

void BaseDatos::encontrarCombo(){
    string nombreCombo;
    cout<<"Ingrese el nombre del combo: "<<endl;
    getline(cin,nombreCombo);
    
    for(int i=0;i<cantCombos;i++){
        if (arrayCombos[i].nombre==nombreCombo){
            arrayCombos[i].cantPorciones();
        }
    }
}