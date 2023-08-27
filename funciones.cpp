#include "recetas.cpp"

void agregarCombo(BaseDatos BD, string nombre, int cantPorciones, Componente* componentes, int numComponentes){
        cout<<"hola estamos vivos";

    // if (!(numComponentes>=100)){
        Combo combo(nombre, cantPorciones,componentes,numComponentes); 
        BD.setCombo(combo);
    // }


}