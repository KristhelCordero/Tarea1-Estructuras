#include "recetas.cpp"
using namespace std;

BaseDatos agregarCombo(BaseDatos BD, string nombre, int cantPorciones, Componente* componentes, int numComponentes){
        Combo combo(nombre, cantPorciones,componentes,numComponentes); 
        BD.setCombo(combo);
    return BD;


}