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

//----------------------------------COMBOS-----------------------------------

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
    cout<<" "<<endl;
}

void Combo::setCantComponentes(int nuevaCantComponentes){
    cantComponentes=nuevaCantComponentes;
}

void Combo::calcularPorciones(int nuevaCantidad){
    cout << "----------- CALCULAR PORCIONES ------------" << endl;

    for (int i = 0; i < cantComponentes; i++) {
        double cantidadNecesaria = (nuevaCantidad * 100)/arrayComponentes[i].cantidad;
        cout << arrayComponentes[i].nombre << ": " << cantidadNecesaria << " " 
        << arrayComponentes[i].unidadMedida << "\n";
    }
}

void Combo::agregarComponente(){
    cout<< "Ingrese el nombre del nuevo componente: "<<endl;
    string nombreNC;
    getline(cin, nombreNC);
    cout<< "Ingrese la unidad de medida del componente: "<<endl;
    string unidadNC;
    getline(cin, unidadNC);
    cout<< "Ingrese la cantidad del componente: "<<endl;
    string cantidadNC;
    getline(cin, cantidadNC);

    int intCantidad=stoi(cantidadNC);
    Componente nuevoComponente=Componente(nombreNC, intCantidad, unidadNC);
    arrayComponentes[cantComponentes]=nuevoComponente;
    setCantComponentes(++cantComponentes);
}

int Combo::buscarNumeroComponente(string nombre){
    for (int i=0;i<cantComponentes;i++){
        if (arrayComponentes[i].nombre==nombre)
            return i;
            }
    return -1;
}

//----------------------------------BASE DE DATOS------------------------------
int BaseDatos::buscarNumeroCombo(string nombre){
    for (int i=0;i<cantCombos;i++)
        if (arrayCombos[i].nombre==nombre)
            return i;
    return -1;
}

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

void BaseDatos::setCantCombos(int nuevaCantidadCombos){
    cantCombos=nuevaCantidadCombos;
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

void BaseDatos::buscarCombo(){
    string nombreCombo;
    cout << "\nIngrese el nombre del combo: " << endl;
    getline(cin,nombreCombo);
    for (int i=0;i<cantCombos;i++)
        if (arrayCombos[i].nombre==nombreCombo)
            arrayCombos[i].imprimirCombo();
}

void BaseDatos::modificarCombo(){
    string nuevoNombre;
    string nombreActual;
    cout << "\nIngrese el nombre actual del combo: " << endl;
    getline(cin,nombreActual);
    cout << "\nIngrese el nuevo nombre del combo: " << endl;
    getline(cin,nuevoNombre);
    for (int i=0;i<cantCombos;i++)
        if (arrayCombos[i].nombre==nombreActual)
            arrayCombos[i].setNombre(nuevoNombre);
    cout << "Se modificó el nombre correctamente" << endl;
}


void BaseDatos::borrarCombo(string nombre){
    int numCombo=buscarNumeroCombo(nombre);
    for (int i=0; i< cantCombos-numCombo; i++){
        arrayCombos[i+numCombo]=arrayCombos[i+numCombo+1];
        cout << arrayCombos[i+numCombo].nombre <<endl;
    }
    cantCombos--;
}




void Combo::modificarCantidadComponenete(){
    string nombreComponente;
    string nuevaCantidad;

    cout<< "Ingrese el componente:"<<endl;    
    getline(cin,nombreComponente);

    cout <<endl<< "Ingrese la nueva cantidad:"<<endl;
    getline(cin,nombreComponente);
    int intNuevaCantidad = stoi(nuevaCantidad);

    int nuemroComponente=buscarNumeroComponente(nombreComponente);

    arrayComponentes[nuemroComponente].cantidad=intNuevaCantidad;

}