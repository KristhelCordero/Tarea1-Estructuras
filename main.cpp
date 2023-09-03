#include "recetas.cpp"
// BaseDatos agregarComboMenu(BaseDatos BD){
// }
int main(int argc, char const *argv[])
{
    int opcion;
    string opcionS;
    string nombre;
    BaseDatos BD;
//---------------------------
    do
    {
        cout << "------------------ MENU --------------------" << endl;
        cout << "1. Agregar combo " << endl << "2. Buscar combo " << endl;
        cout << "3. Borrar combo " << endl << "4. Imprimir todos los combos" << endl;
        cout << "5. Modificar nombre de un combo " << endl;
        cout << "6. Modificar cantidad de	un componente de un combo" << endl;
        cout << "7. Agregar	componente a un combo " << endl;
        cout << "8. Calcular porciones " << endl;
        cout << "9. Salir " << endl;
        cout << "\nIngrese la opción que desea: " << endl;
        getline(cin,opcionS);
        opcion= stoi(opcionS);
        Componente componentes[30];

        string continuar="1";
        switch (opcion){
        case 1: /// NO SE SI NADA DE ESTO FUNCIONA AHHHHHHHHHHHHHHHHHHHHHH
            cout << "-------------- AGREGAR COMBO --------------" << endl;
            do{
                if(BD.cantCombos<100){
                    BD.agregarCombo();
                }else {cout<<"No se pueden agregar mas de 100 combos"<<endl;}

                cout<<"¿Desea continuar agregando combos?\n1 = Si\n0 = No"<<endl;
                getline(cin,continuar);
            }while(continuar!="0");
                        
            break;
        case 2:
            cout << "-------------- BUSCAR COMBO --------------" << endl;
            do{
                BD.buscarCombo();
                cout<<"¿Desea continuar buscando combos?\n1 = Si\n0 = No"<<endl;
                getline(cin,continuar);

            }while(continuar!="0");
            break;

        case 3:
            cout << "-------------- BORRAR COMBO --------------" << endl;
            do{
                BD.borrarCombo();
                cout<<"¿Desea continuar borrando combos?\n1 = Si\n0 = No"<<endl;
                getline(cin,continuar);

            }while(continuar!="0");
            
            break;
        case 4:
            cout << "------------- IMPRIMIR COMBOS -------------" << endl;
            BD.imprimirTodoslosCombos();
            
            cout << "-------------------------------------------" << endl;
            break;
        case 5:
            cout << "------------- MODIFICAR COMBO --------------" << endl;
            do{
                BD.modificarCombo();

                cout<<"¿Desea continuar modificando combos?\n1 = Si\n0 = No"<<endl;
                getline(cin,continuar);

            }while(continuar!="0");

            break;
        case 6:
            cout << "------ MODIFICAR CANTIDAD COMPONENTE ------" << endl;
            do{
                BD.arrayCombos[BD.buscarNumeroCombo()].modificarCantidadComponenete();

                cout<<"¿Desea modificar otro componente?\n1 = Si\n0 = No"<<endl;
                getline(cin,continuar);

            }while(continuar!="0");
            
            break;
        case 7:
            cout << "----------- AGREGAR COMPONENTE ------------" << endl;
            do{
                BD.encontrarComboComponente();
                cout<<"¿Desea continuar agregando componentes?\n1 = Si\n0 = No"<<endl;
                getline(cin,continuar);

            }while(continuar!="0");

            break;
        case 8:
            cout << "----------- CALCULAR PORCIONES ------------" << endl;
            do{
                BD.encontrarComboPorciones();
                cout<<"¿Desea continuar calculando porciones?\n1 = Si\n0 = No"<<endl;
                getline(cin,continuar);

            }while(continuar!="0");
            break;
        default:
            break;
        }
    } while (opcion!=9);

    return 0;
}


