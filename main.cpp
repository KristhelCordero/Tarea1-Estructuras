#include "recetas.cpp"

int main(int argc, char const *argv[])
{
    int opcion;
    string opcionS;
    int cantCombos;
    Combo * ptArray; /////// NO ES OFICIAL, ES PARA PRUEBAS 
    string nombre;
    do
    {
        cout << "------------------ MENU --------------------" << endl;
        cout << "1. Agregar combo " << endl << "2. Buscar combo " << endl;
        cout << "3. Borrar combo " << endl << "4. Imprimir todos los combos" << endl;
        cout << "5. Modificar nombre de un combo " << endl << "6. Modificar cantidad de	un componente de un combo" << endl;
        cout << "7. Agregar	componente a un combo " << endl << "8. Calcular	para porciones " << endl;
        cout << "9. Salir " << endl;
        cout << "\nIngrese la opción que desea: " << endl;
        getline(cin,opcionS);
        opcion= stoi(opcionS);
        switch (opcion){
        case 1:
            cout << "-------------- AGREGAR COMBO --------------" << endl;
            break;
        case 2:
            cout << "-------------- BUSCAR COMBO --------------" << endl;
            cout << "\nIngrese el nombre del combo: " << endl;
            getline(cin,nombre);
            break;
        case 3:
            cout << "-------------- BORRAR COMBO --------------" << endl;
            break;
        case 4:
            cout << "------------- IMPRIMIR COMBOS -------------" << endl;
            break;
        case 5:
            // modificarCombo(cantCombos,ptArray);    NO ES OFICIAL, ES PARA PRUEBAS 
            break;
        case 6:
            cout << "------ MODIFICAR CANTIDAD COMPONENTE ------" << endl;
            break;
        case 7:
            cout << "----------- AGREGAR COMPONENTE ------------" << endl;
            break;
        case 8:
            // calcularPorciones
            break;
        default:
            break;
        }
    } while (opcion!=9);

    return 0;
}


