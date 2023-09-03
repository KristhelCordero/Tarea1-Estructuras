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

int buscarNumeroComponenete(int cantComponenetes, Componente * array, string nombre){
    for (int i=0;i<cantComponenetes;i++){
        if (array[i].nombre==nombre)
            return i;
            }
    return -1;
}

BaseDatos borrarCombo(BaseDatos BD, string nombre){
    int numCombo=buscarNumeroCombo(BD.cantCombos, BD.arrayCombos, nombre);
    for (int i=0; i< BD.cantCombos-numCombo; i++){
        BD.arrayCombos[i+numCombo]=BD.arrayCombos[i+numCombo+1];
        cout << BD.arrayCombos[i+numCombo].nombre <<endl;
    }
    BD.cantCombos--;
    return BD;
}

// void imprimirTodoslosCombos(BaseDatos BD){
//     center("Combos",15);
//     for(int i=0; i<BD.cantCombos;i++){
//         string mensaje="Combo "+to_string(i+1);
//         center(mensaje,10);
//         BD.arrayCombos[i].imprimirCombo();
//     }   
// }

// Combo modificarCantidadComponenetes(){
// }
        // BD.ptArray[i].imprimirCombo();

BaseDatos modificarCantidadComponenete(BaseDatos BD){
    string nombreComponente;
    string nombreCombo;
    string nuevaCantidad;

    cout<< "Ingrese nombre del combo"<<endl;
    getline(cin,nombreCombo);

    cout<< "Ingrese el componente:"<<endl;    
    getline(cin,nombreComponente);

    cout <<endl<< "Ingrese la nueva cantidad:"<<endl;
    getline(cin,nombreComponente);
    int intNuevaCantidad = stoi(nuevaCantidad);

    int numeroCombo=buscarNumeroCombo(BD.cantCombos, BD.arrayCombos,nombreCombo);
    int nuemroComponente=buscarNumeroComponenete(BD.arrayCombos[numeroCombo].cantComponentes,
    BD.arrayCombos[numeroCombo].arrayComponentes, nombreComponente);

    BD.arrayCombos[numeroCombo].arrayComponentes[nuemroComponente].cantidad=intNuevaCantidad;

    return BD;
}
// Combo agregarComponente(){
// }





void Combo::calcularPorciones(int nuevaCantidad){
    for (int i = 0; i < cantComponentes; i++) {
        double cantidadNecesaria = (nuevaCantidad * 100)/arrayComponentes[i].cantidad;
        cout << arrayComponentes[i].nombre << ": " << cantidadNecesaria << " " 
        << arrayComponentes[i].unidadMedida << "\n";
    }
}



