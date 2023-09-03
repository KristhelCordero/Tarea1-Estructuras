#include "recetas.cpp"
// BaseDatos agregarComboMenu(BaseDatos BD){
// }
int main(int argc, char const *argv[])
{
    int opcion;
    string opcionS;
    string nombre;
//-----------------------
    Componente componente("Arstotzka",2,"Jarras");
    Componente com;
    com.nombre="lalala";

    Componente componentes[]={componente,com};


    Combo combo("combo", 7, componentes, 2);
    Combo wombo("wombo", 5, componentes, 2);
    Combo array[]={combo,wombo};

    BaseDatos BD("Nombre",2,array);
//---------------------------
    do
    {
        cout << "------------------ MENU --------------------" << endl;
        cout << "1. Agregar combo " << endl << "2. Buscar combo " << endl;
        cout << "3. Borrar combo " << endl << "4. Imprimir todos los combos" << endl;
        cout << "5. Modificar nombre de un combo " << endl;
        cout << "6. Modificar cantidad de	un componente de un combo" << endl;
        cout << "7. Agregar	componente a un combo " << endl << "8. Calcular	para porciones " << endl;
        cout << "9. Salir " << endl;
        cout << "\nIngrese la opción que desea: " << endl;
        getline(cin,opcionS);
        opcion= stoi(opcionS);
        Componente componentes[30];
        switch (opcion){
        case 1: /// NO SE SI NADA DE ESTO FUNCIONA AHHHHHHHHHHHHHHHHHHHHHH
            cout << "-------------- AGREGAR COMBO --------------" << endl;
            cout << "\nIngrese 0 para terminar: " << endl;
            
            // BD.agregarCombo();

            
            break;
        case 2:
            cout << "-------------- BUSCAR COMBO --------------" << endl;
            BD.buscarCombo();
            break;
        case 3:
            cout << "-------------- BORRAR COMBO --------------" << endl;

            BD.borrarCombo();
            break;
        case 4:
            cout << "------------- IMPRIMIR COMBOS -------------" << endl;
            BD.imprimirBaseDatos();
            cout << "-------------------------------------------" << endl;
            break;
        case 5:
            cout << "------------- MODIFICAR COMBO --------------" << endl;
            BD.modificarCombo();       //   NO ES OFICIAL, ES PARA PRUEBAS 
            break;
        case 6:
            cout << "------ MODIFICAR CANTIDAD COMPONENTE ------" << endl;
            break;
        case 7:
            cout << "----------- AGREGAR COMPONENTE ------------" << endl;
            BD.encontrarComboComponente();
            break;
        case 8:
            cout << "----------- CALCULAR PORCIONES ------------" << endl;
            BD.encontrarComboPorciones();
            break;
        default:
            break;
        }
    } while (opcion!=9);

    return 0;
}


