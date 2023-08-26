#include <iostream>
using namespace std;

struct Componente{
    string nombre;
    int cantidad;
    string unidadMedida;

    Componente() : cantidad(1) {} //!!!!!

    Componente(string _nombre, int _cantidad, string _unidadMedida ):
    nombre(_nombre), cantidad(_cantidad), unidadMedida(_unidadMedida){} 


    void imprimirComponente(){
        cout << "Componente: " << nombre << endl << "Cantidad: " << cantidad << endl
        << "Unidad de medida: " << unidadMedida<<endl;
    }
};





// struct Combo{
//     string nombre;
//     int cantPorciones;
//     Componente componentes[30];

//     Combo() : cantPorciones(1){}//

//     Combo(string xNombre,int xPorciones,int cantComponentes){
//         nombre=xNombre;
//         cantPorciones=xPorciones;
//         Componente componentes[cantComponentes];
//     }
//     //Combo(string _nombre, int _cantPorciones, int cantidadComponentes):
//     //nombre(_nombre), cantPorciones(_cantPorciones), componentes[_cantComponentes]){}
    
    
//     void Combo::imprimirCombo();
// };






// struct BaseDatos{
//     string nombre;
//     Combo arregloCombos[];

//     BaseDatos(){

//     }
// };
