#include "recetas.cpp"
using namespace std;

void agregarCombo(BaseDatos BD, string nombre, int cantPorciones, Componente* componentes, int numComponentes){
        cout<<"hola estamos vivos"<<endl;

    // if (!(numComponentes>=100)){
        Combo combo(nombre, cantPorciones,componentes,numComponentes); 
        cout<<"nose"<<endl;
        BD.setCombo(combo);
        cout<<"nya"<<endl;
    // }


}