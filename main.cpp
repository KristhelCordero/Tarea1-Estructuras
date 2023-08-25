#include "recetas.cpp";

int main(int argc, char const *argv[])
{
    string opcion;
    do
    {
        cout << "------------------ MENU --------------------" << endl;
        cout << "1. Agregar combo " << endl << "2. Buscar combo " << endl;
        cout << "3. Borrar combo " << endl << "4. Imprimir todos los combos" << endl;
        cout << "5. Modificar nombre de un combo " << endl << "6. Modificar cantidad de	un componente de un combo" << endl;
        cout << "7. Agregar	componente a un combo " << endl << "8. Calcular	para porciones " << endl;
        cout << "9. Salir " << endl;
        cout << "\nIngrese la opción que desea: " << endl;
        getline(cin,opcion);
    } while (opcion!="9");
    
    return 0;
}
