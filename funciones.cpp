#include "recetas.cpp"
using namespace std;

void center(string str, const int padding){
    for(int i=0; i<padding;++i)cout<<"-";
    cout<<str;
    for(int i=0; i<padding;++i)cout<<"-";
    cout<<""<<endl;   
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


// Combo agregarComponente(){
// }





void Combo::calcularPorciones(int nuevaCantidad){
    for (int i = 0; i < cantComponentes; i++) {
        double cantidadNecesaria = (nuevaCantidad * 100)/arrayComponentes[i].cantidad;
        cout << arrayComponentes[i].nombre << ": " << cantidadNecesaria << " " 
        << arrayComponentes[i].unidadMedida << "\n";
    }
}



