#include "recetas.cpp"

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

    BaseDatos BD("Hipopotamo", 2, combos);
    BD.imprimirBaseDatos();



    return 0;
}
