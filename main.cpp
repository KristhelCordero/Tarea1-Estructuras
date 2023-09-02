#include "funciones.cpp"
// BaseDatos agregarComboMenu(BaseDatos BD){
// }
int main(int argc, char const *argv[])
{
    int opcion;
    string opcionS;
    int cantCombos;
    string nombre;
    BaseDatos BD;
    Componente componente;
    string nombreComponente;
    string unidadMedida;
    string cantComp;
    int cantidad;
    string cantComponentesString;
    int cantComponentes;
    string cantPorc;
    int cantPorciones;
    int opcion2;
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
        Componente componentes[30];
        switch (opcion){
        case 1: /// NO SE SI NADA DE ESTO FUNCIONA AHHHHHHHHHHHHHHHHHHHHHH
            cout << "-------------- AGREGAR COMBO --------------" << endl;
            
            cout << "\nIngrese 0 para terminar: " << endl;
            getline(cin,cantComponentesString);
            cantComponentes=stoi(cantComponentesString);
            for (int i=0;i<cantComponentes;i++){
                cout<<"\nIngrese el nombre del componente #" << (i+1) <<"del combo: "<<endl;
                getline(cin,nombreComponente);
                if (nombreComponente=="0")
                    break;
                cout << "\nIngrese la cantidad de ese componente: " << endl;
                getline(cin,cantComp);
                cantidad= stoi(cantComp);
                cout << "\nIngrese la unidad de medida: " << endl;
                getline(cin,unidadMedida);
                componentes[i]=Componente(nombreComponente,cantidad,unidadMedida);
            }
            BD.agregarCombo();
            break;
        case 2:
            cout << "-------------- BUSCAR COMBO --------------" << endl;
            cout << "\nIngrese el nombre del combo: " << endl;
            getline(cin,nombre);
            buscarCombo(BD.cantCombos,BD.arrayCombos);
            break;
        case 3:
            cout << "-------------- BORRAR COMBO --------------" << endl;
            cout << "\nIngrese el nombre del combo: " << endl;
            getline(cin,nombre);
            BD=borrarCombo(BD,nombre);
            break;
        case 4:
            cout << "------------- IMPRIMIR COMBOS -------------" << endl;
            BD.imprimirBaseDatos();
            cout << "-------------------------------------------" << endl;
            break;
        case 5:
            BD=modificarCombo(BD);       //   NO ES OFICIAL, ES PARA PRUEBAS 
            break;
        case 6:
            cout << "------ MODIFICAR CANTIDAD COMPONENTE ------" << endl;
            break;
        case 7:
            cout << "----------- AGREGAR COMPONENTE ------------" << endl;
            break;
        case 8:
            cout << "----------- CALCULAR PORCIONES ------------" << endl;
            //BD
            break;
        default:
            break;
        }
    } while (opcion!=9);

    return 0;
}


