#include "recetas.cpp"

void modificarCombo(int cantCombos, Combo * array){
    string nuevoNombre;
    string nombreActual;
    cout << "------------- MODIFICAR COMBO --------------" << endl;
    cout << "\nIngrese el nombre actual del combo: " << endl;
    getline(cin,nombreActual);
    cout << "\nIngrese el nuevo nombre del combo: " << endl;
    getline(cin,nuevoNombre);
    for (int i=0;i<cantCombos;i++)
        if (array[i].nombre==nombreActual)
            array[i].setNombre(nuevoNombre);
    cout << "Se modificó el nombre correctamente" << endl;
}

void buscarCombo(int cantCombos, Combo * array){
    string nombre;
    cout << "-------------- BUSCAR COMBO --------------" << endl;
    cout << "\nIngrese el nombre del combo: " << endl;
    getline(cin,nombre);
    for (int i=0;i<cantCombos;i++)
        if (array[i].nombre==nombre)
            array[i].imprimirCombo();
}

int calcularPorciones(Combo comboSeleccionado,int cantComponentes, int nuevaCantidad){
    cout << "----------- CALCULAR PORCIONES ------------" << endl;
    for (int i = 0; i < cantComponentes; i++) {
        double cantidadNecesaria = (nuevaCantidad * 100)/comboSeleccionado.componentes[i].cantidad;
        cout << comboSeleccionado.componentes[i].nombre << ": " << cantidadNecesaria << " " 
        << comboSeleccionado.componentes[i].unidadMedida << "\n";
    }
}

int main(int argc, char const *argv[])
{
    int opcion;
    string opcionS;
    int cantCombos;
    Combo * ptArray; /////// NO ES OFICIAL, ES PARA PRUEBAS 
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
            // buscarCombo();
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


