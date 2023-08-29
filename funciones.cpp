#include "recetas.cpp"
using namespace std;

void center(string str, const int padding){
    for(int i=0; i<padding;++i)cout<<"-";
    cout<<str;
    for(int i=0; i<padding;++i)cout<<"-";
    cout<<""<<endl;   
}

int buscarNumeroCombo(int cantCombos, Combo * array, string nombre){
    for (int i=0;i<cantCombos;i++)
        if (array[i].nombre==nombre)
            return i;
    return -1;
}

BaseDatos borrarCombo(BaseDatos BD, string nombre){
    int numCombo=buscarNumeroCombo(BD.cantCombos, BD.ptArray, nombre);
    for (int i=0; i< BD.cantCombos-numCombo; i++){
        BD.ptArray[i+numCombo]=BD.ptArray[i+numCombo+1];
        cout << BD.ptArray[i+numCombo].nombre <<endl;
    }
    BD.cantCombos--;
    return BD;
}

BaseDatos agregarCombo(BaseDatos BD, string nombre, int cantPorciones, Componente* componentes, int numComponentes){
    Combo combo(nombre, cantPorciones,componentes,numComponentes); 
    BD.setCombo(combo);
    return BD;
}

void imprimirTodoslosCombos(BaseDatos BD){
    center("Combos",15);
    for(int i=0; i<BD.cantCombos;i++){
        string mensaje="Combo "+to_string(i+1);
        center(mensaje,10);
        BD.ptArray[i].imprimirCombo();
    }   
}

// Combo modificarCantidadComponenetes(){
// }

// Combo agregarComponente(){
// }

BaseDatos modificarCombo(BaseDatos BD){
    string nuevoNombre;
    string nombreActual;
    cout << "------------- MODIFICAR COMBO --------------" << endl;
    cout << "\nIngrese el nombre actual del combo: " << endl;
    getline(cin,nombreActual);
    cout << "\nIngrese el nuevo nombre del combo: " << endl;
    getline(cin,nuevoNombre);
    for (int i=0;i<BD.cantCombos;i++)
        if (BD.ptArray[i].nombre==nombreActual)
            BD.ptArray[i].setNombre(nuevoNombre);
    cout << "Se modificó el nombre correctamente" << endl;
    return BD;
}

void buscarCombo(int cantCombos, Combo * array){
    string nombre;
    cout << "-------------- BUSCAR COMBO --------------" << endl;
    cout << "\nIngrese el nombre del combo: " << endl;
    getline(cin,nombre);
    for (int i=0;i<cantCombos;i++)
        if (array[i].nombre==nombre)
            array[i].imprimirCombo();
}

void calcularPorciones(Combo comboSeleccionado,int cantComponentes, int nuevaCantidad){
    cout << "----------- CALCULAR PORCIONES ------------" << endl;
    for (int i = 0; i < cantComponentes; i++) {
        double cantidadNecesaria = (nuevaCantidad * 100)/comboSeleccionado.componentes[i].cantidad;
        cout << comboSeleccionado.componentes[i].nombre << ": " << cantidadNecesaria << " " 
        << comboSeleccionado.componentes[i].unidadMedida << "\n";
    }
}



