#include "recetas.h"
//---------------------------------Funciones aparte--------------------------
void center(string str, const int padding){
    for(int i=0; i<padding;++i)cout<<"-";
    cout<<str;
    for(int i=0; i<padding;++i)cout<<"-";
    cout<<""<<endl;   
}


Componente* crearArrayComponentes(int intCantComponentes) {
    string nombreComponente;
    string sumaComponente;
    int intSumaComponente;
    string unidadMedida;

    Componente* arrayCompCombo = new Componente[intCantComponentes];

    for (int i = 0; i < intCantComponentes; i++) {
        cout << "\nIngrese el nombre del componente #" << (i + 1) << " del combo: " << endl;
        getline(cin, nombreComponente);
        
        if (nombreComponente == "0")
            break;

        cout << "\nIngrese la cantidad de ese componente: " << endl;
        getline(cin, sumaComponente);
        intSumaComponente = stoi(sumaComponente);

        cout << "\nIngrese la unidad de medida: " << endl;
        getline(cin, unidadMedida);

        arrayCompCombo[i] = Componente(nombreComponente, intSumaComponente, unidadMedida);
    }

    return arrayCompCombo;
}

//----------------------------------COMPONENTES------------------------------
void Componente::imprimirComponente(){
    cout << "   -> " << nombre
    << " X " << cantidad
    << " " << unidadMedida << endl;
}

//----------------------------------COMBOS-----------------------------------

void Combo::imprimirCombo(){
    cout << " "<<endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Porciones: "<<cantPorciones<<endl;
    cout << "Componentes: " << endl;
    for(int i=0; i<cantComponentes;i++){
        arrayComponentes[i].imprimirComponente();
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
    for (int i = 0; i < cantComponentes; i++) {
        double cantidadNecesaria = ((nuevaCantidad * arrayComponentes[i].cantidad)/cantPorciones);
        cout << arrayComponentes[i].nombre << ": " << cantidadNecesaria << " " 
        << arrayComponentes[i].unidadMedida << "\n";
    }
}


void Combo::agregarComponente(){
    cout<< "Ingrese el nombre del nuevo componente: "<<endl;
    string nombreNC;
    getline(cin, nombreNC);
    cout<< "Ingrese la cantidad del componente: "<<endl;
    string cantidadNC;
    getline(cin, cantidadNC);
    cout<< "Ingrese la unidad de medida del componente: "<<endl;
    string unidadNC;
    getline(cin, unidadNC);

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
    cout<<"No se encontro el componente"<<endl;
    return -1;
}

void Combo::modificarCantidadComponenete(){
    string nombreComponente;
    string nuevaCantidad;

    cout<< "Ingrese el componente:"<<endl;    
    getline(cin,nombreComponente);

    cout <<endl<< "Ingrese la nueva cantidad:"<<endl;
    getline(cin,nuevaCantidad);
    int intNuevaCantidad = stoi(nuevaCantidad);

    int numeroComponente=buscarNumeroComponente(nombreComponente);

    arrayComponentes[numeroComponente].cantidad=intNuevaCantidad;
}

//----------------------------------BASE DE DATOS------------------------------
int BaseDatos::buscarNumeroCombo(){
    string nombre;
    cout << "\nIngrese el nombre del combo: " << endl;
    getline(cin,nombre);
    for (int i=0;i<cantCombos;i++)
        if (arrayCombos[i].nombre==nombre)
            return i;

    cout<<"No se encontró el combo buscado"<<endl;
    return -1;
}

void BaseDatos::agregarCombo(){
    string pNombreCombo;
    string cantPorc;
    int intCantPorc;
    string cantComponentes;
    int intCantComponentes=0;
    
    //solicitud de datos
    cout << "\nIngrese el nombre del combo a agregar: " << endl;
    getline(cin,pNombreCombo);

    cout << "\nIngrese la cantidad de porciones del combo a agregar: " << endl;
    getline(cin,cantPorc);
    intCantPorc=stoi(cantPorc);

    do{
        if (intCantComponentes>30){
            cout<<"no se pueden agregar mas de 30 componentes"<<endl;
        }
        cout << "\nIngrese el número de componentes del combo a agregar: " << endl;
        getline(cin,cantComponentes);
        intCantComponentes=stoi(cantComponentes);
    }while(intCantComponentes>30);
    

    //creacion de nuevo combo

    Componente *ptArrayComponentes=crearArrayComponentes(intCantComponentes);
    Combo nuevoCombo(pNombreCombo, intCantPorc, ptArrayComponentes , intCantComponentes);
    arrayCombos[cantCombos]=nuevoCombo;
    setCantCombos(++cantCombos);
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

void BaseDatos::encontrarComboPorciones(){
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

void BaseDatos::encontrarComboComponente(){
    string nombreCombo;
    cout<<"Ingrese el nombre del combo: "<<endl;
    getline(cin,nombreCombo);
    for(int i=0;i<cantCombos;i++){
        if (arrayCombos[i].nombre==nombreCombo){
            if(arrayCombos[i].cantComponentes<30){
                arrayCombos[i].agregarComponente();
            }else {cout << "No se puede agregar mas de 30 componentes"<<endl;}
        }
    }
}

void BaseDatos::buscarCombo(){
    int numeroCombo=buscarNumeroCombo();
    if(numeroCombo!= -1){
        arrayCombos[numeroCombo].imprimirCombo();
    }
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


void BaseDatos::borrarCombo(){
    int numCombo=buscarNumeroCombo();
    if (numCombo!=-1){
        for (int i=0; i< cantCombos-numCombo; i++){
            arrayCombos[i+numCombo]=arrayCombos[i+numCombo+1];

        }
        cantCombos--;
        cout << "Se borro el combo correctamente" << endl;
    }
}

void BaseDatos::imprimirTodoslosCombos(){
    center("Combos",15);
    for(int i=0; i<cantCombos;i++){
        string mensaje="Combo "+to_string(i+1);
        center(mensaje,10);
        arrayCombos[i].imprimirCombo();
    }   
}




