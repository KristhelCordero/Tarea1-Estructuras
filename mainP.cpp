// #include "main.cpp"
#include "funciones.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
    Componente componente("Arstotzka",2,"Jarras");
    componente.imprimirComponente();
    Componente com;
    com.nombre="lalala";

    cout<<"1"<<endl;

    Componente componentes[]={componente,com};
    Combo combo("NombreC",3,componentes,2);
    combo.imprimirCombo();
    Combo comb("OtroNombre",3,componentes,2);

    cout<<"2"<<endl;

    Combo combos[]={combo,comb};
    BaseDatos BD("Hipopotamo",2, combos);
    BD.imprimirBaseDatos(); 
    BD = agregarCombo(BD,"Combo Wombo", 3, componentes,2);
    cout<<""<<endl;
    BD.imprimirBaseDatos();

    cout<<""<<endl;
    cout<<"3"<<endl;
    cout<<"Funcion Borrar"<<endl;
    cout<<""<<endl;

    BD = borrarCombo(BD,"Combo Wombo");
    BD.imprimirBaseDatos();


    cout<<"4"<<endl;

    imprimirTodoslosCombos(BD);

    // BD= modificarCantidadComponenete(BD);

    // imprimirTodoslosCombos(BD);

    // string variableloca;
    // getline(cin,variableloca);

    return 0;
}
