#include "recetas.h"
//---------------------------------Funciones aparte--------------------------

Componente* crearArrayComponentes(int intCantComponentes){
    string nombreComponente;
    string sumaComponente;
    int intSumaComponente;
    string unidadMedida;

    Componente arrayCompCombo[intCantComponentes];
    for (int i=0;i<intCantComponentes;i++){
        cout<<"\nIngrese el nombre del componente #" << (i+1) <<"del combo: "<<endl;
        getline(cin,nombreComponente);
        if (nombreComponente=="0")
            break;
        cout << "\nIngrese la cantidad de ese componente: " << endl;
        getline(cin,sumaComponente);
        intSumaComponente= stoi(sumaComponente);
        cout << "\nIngrese la unidad de medida: " << endl;
        getline(cin,unidadMedida);
        arrayCompCombo[i]=Componente(nombreComponente,intSumaComponente,unidadMedida);
    }
    return arrayCompCombo;

}

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
        cout <<"    -"<< arrayComponentes[i].nombre<<endl;
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
        double cantidadNecesaria = (nuevaCantidad * 100)/arrayComponentes[i].cantidad;
        cout << arrayComponentes[i].nombre << ": " << cantidadNecesaria << " " 
        << arrayComponentes[i].unidadMedida << "\n";
    }
}

//----------------------------------BASE DE DATOS------------------------------




void BaseDatos::agregarCombo(){
    string pNombreCombo;
    string cantPorc;
    int intCantPorc;
    string cantComponentes;
    int intCantComponentes;
    
    //solicitud de datos
    cout << "\nIngrese el nombre del combo a agregar: " << endl;
    getline(cin,pNombreCombo);

    cout << "\nIngrese la cantidad de porciones del combo a agregar: " << endl;
    getline(cin,cantPorc);
    intCantPorc=stoi(cantPorc);

    cout << "\nIngrese el número de componentes del combo a agregar: " << endl;
    getline(cin,cantComponentes);
    intCantComponentes=stoi(cantComponentes);

    //creacion de nuevo combo
    Combo nuevoCombo=Combo(pNombreCombo, intCantPorc, crearArrayComponentes(intCantComponentes), intCantComponentes);
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
    string nuevaCantidad;
    int intNuevaCantidad;
    cout<<"Ingrese el nombre del combo: "<<endl;
    getline(cin,nombreCombo);
    cout<<"Ingrese la cantidad de porciones a calcular: "<<endl;
    getline(cin,nuevaCantidad);
    intNuevaCantidad=stoi(nuevaCantidad);
    for(int i=0;i<cantCombos;i++){
        if (arrayCombos[i].nombre==nombreCombo){
            arrayCombos[i].calcularPorciones(intNuevaCantidad);
        }
    }
}