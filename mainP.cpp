#include "main.cpp"
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
    BaseDatos BD("Hipopotamo",2, combos);
    
    BD.imprimirBaseDatos(); 
    BD = agregarCombo(BD,"Combo Wombo", 3, componentes,2);
    cout<<BD.cantCombos<<endl;
    BD.imprimirBaseDatos();

    cout<<"Funcion Borrar"<<endl;

    BD= borrarCombo(BD,"Combo Wombo");
    BD.imprimirBaseDatos();


    

    imprimirTodoslosCombos(BD);


    BD= modificarCantidadComponenete(BD);

    imprimirTodoslosCombos(BD);

    string variableloca;
    getline(cin,variableloca);



    return 0;
}
