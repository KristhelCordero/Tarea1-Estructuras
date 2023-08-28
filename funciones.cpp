#include "recetas.cpp"
using namespace std;


int buscarNumeroCombo(int cantCombos, Combo * array, string nombre){
    // string nombre;
    // cout << "-------------- BUSCAR COMBO --------------" << endl;
    // cout << "\nIngrese el nombre del combo: " << endl;
    // getline(cin,nombre);
    for (int i=0;i<cantCombos;i++){
        if (array[i].nombre==nombre)
            return i;
            }
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



