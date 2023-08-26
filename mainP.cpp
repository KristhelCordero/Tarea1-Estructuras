#include "recetas.h"

int main(int argc, char const *argv[])
{
    Componente componente("arstotzka",2,"Jarras");
    componente.imprimirComponente();
    Componente com;
    com.nombre="lalala";

    Componente componentes[]={componente,com};
    Combo combo("nombreC",3,componentes,2);
    combo.imprimirCombo();


    
    
    




    return 0;
}
