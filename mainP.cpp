#include "funciones.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
    Componente componente("Arstotzka",2,"Jarras");
    componente.imprimirComponente();
    Componente com;
    com.nombre="lalala";

    Componente componentes[]={componente,com};
    Combo combo("NombreC",3,componentes,2);
    combo.imprimirCombo();
    Combo comb("OtroNombre",3,componentes,2);

    Combo combos[]={combo,comb};

    BaseDatos BD("Hipopotamo",3, combos);
    BD.imprimirBaseDatos();
    // cout<<endl;
    cout<<"sisecae";

    agregarCombo(BD,"Combo Wombo", 3, componentes,2);
    cout<<"nosecae";
    BD.imprimirBaseDatos();





    return 0;
}
