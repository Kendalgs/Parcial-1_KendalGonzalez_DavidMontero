#include "interfaz.h"

#define RESET   "\033[0m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define MAGENTA "\033[35m"  

// Ruta de los archivos de datos
const string interfaz::archivo = "..\\Asociados.txt";
const string interfaz::archivo1 = "..\\Personas.txt";
const string interfaz::archivo2 = "..\\Libros.txt";

// Constructor de la clase interfaz
interfaz::interfaz()
{
    ifstream entrada(archivo.c_str());
    try {
        _PersonaLibro = new PersonaLibro(entrada);
        if (entrada.good()) {
            cout << "Se cargaron los datos del archivo exitosamente" << endl;
            cin.get();
        }
    }
    catch (...) {

        cout << "Ocurrio un error, no se cargaron los datos del archivo" << endl;

        cin.get();
    }
    entrada.close();

    ifstream entrada1(archivo1.c_str());
    try {
        _persona = new persona(entrada1);
        if (entrada1.good()) {
            cout << "Se cargaron los datos del archivo exitosamente" << endl;
            cin.get();
        }
    }
    catch (...) {

        cout << "Ocurrio un error, no se cargaron los datos del archivo" << endl;

        cin.get();
    }
    entrada1.close();

    ifstream entrada2(archivo2.c_str());
    try {
        _libro = new libro(entrada2);
        if (entrada2.good()) {
            cout << "Se cargaron los datos del archivo exitosamente" << endl;
            cin.get();
        }
    }
    catch (...) {

        cout << "Ocurrio un error, no se cargaron los datos del archivo" << endl;

        cin.get();
    }
    entrada2.close();


}

// Destructor de la clase interfaz
interfaz::~interfaz()
{
    delete _PersonaLibro;
    delete _persona;
    delete _libro;
}

// Función para seleccionar una opción y retornar un entero
int interfaz::seleccionarOpcion()
{
    int opcion = 0;
    cout << "\n\t\t";
    cout << "Digite una opcion: ";
    opcion = utiles::validarEntero();
    return opcion;
}

// Función para mostrar las opciones del usuario normal
void interfaz::mostrarOpciones()
{
    cout << "\n\t\t";
    cout << "1. Agregar persona " << endl;
    cout << "\t\t";
    cout << "2. Agregar Libro " << endl;
    cout << "\t\t";
    cout << "3. Mostrar Persona/Libros " << endl;
    cout << "\t\t";
    cout << "4. Mostrar Libros asociados a Persona" << endl;
    cout << "\t\t";
    cout << "5. Salir " << endl;
}

// Función para mostrar el menú de consultar del usuario normal
void interfaz::mostrarMenu()
{
    int op = 0;
    int opcion = 0;
    string nombre;
    string apellido;
    string titulo;
    string id;
    libro* li = NULL;
    persona* pe = NULL;
    persona* ap = NULL;
    libro* al = NULL;
    listaLibros* listaLi = NULL;
    listaLi = new listaLibros();
    listaPersonas* listaPe = NULL;
    listaPe = new listaPersonas();
    lista <PersonaLibro> listaPL;
    ofstream salida(archivo.c_str());//PersonaLibro
    ofstream salida1(archivo1.c_str());//Persona
    ofstream salida2(archivo2.c_str());//Libro
    bool final = false;

    while (!final) {
        system("cls");
        cout << "\n\n\t\t";
        cout << "***** MENU PRINCIPAL *****" << endl;
        mostrarOpciones();
        op = seleccionarOpcion();

        while (op > 5) {
            cout << "\n\n\t\t";
            cout << "Opcion invalida !!!";
            op = seleccionarOpcion();
        }

        switch (op) {
        case 1:
            system("cls");
            cout << "\n\n\t\t";
            cout << "***** Agregar una Cancion - Playlist ******";
            cout << "\n\n\t\t";
            cout << "Digite el nombre: ";
            cout << "\n\n\t\t";
            getline(cin, nombre);
            cout << "\n\n\t\t";
            cout << "Digite el apellido: ";
            cout << "\n\n\t\t";
            getline(cin, apellido);
            pe = new persona(nombre, apellido);
            listaPe->agregarFinal(pe);
            cout << "Se ha agregado una persona" << endl;
            system("pause");
            break;

        case 2:
            system("cls");
            cout << "\n\n\t\t";
            cout << "***** Eliminar Cancion - Playlist ******";
            cout << "\n\n\t\t";
            cout << "Digite el titulo del libro: ";
            cout << "\n\n\t\t";
            getline(cin, titulo);
            cout << "\n\n\t\t";
            cout << "Digite el id del libro: ";
            cout << "\n\n\t\t";
            getline(cin, id);
            li = new libro(titulo, id);
            listaLi->agregarFinal(li);
            cout << "Se ha agregado un libro!" << endl;
            system("pause");
            break;

        case 3:
            system("cls");
            cout << "\n\n\t\t";
            cout << "***** Mostrar Duracion Total - Playlist ******";
            cout << "\n\n\t\t";
            cout << BLUE << "LISTA PERSONAS:" << endl;
            cout << "****************************************" << RESET << endl;
            cout << listaPe->toString() << endl;
            cout << BLUE << "****************************************" << RESET << endl;

            cout << GREEN << "LISTA LIBROS:" << endl;
            cout << "****************************************" << RESET << endl;
            cout << listaLi->toString() << endl;
            cout << GREEN << "****************************************" << RESET << endl;

            system("pause");
            break;

        case 4:
            system("cls");
            cout << "\n\n\t\t";
            cout << "***** Mostrar Canciones - Playlist ******";
            cout << "\n\n\t\t";
            cout << "Quiere asignar un libro a una persona o mostrar los libros asignados" << endl << "1. Asignar" << endl << "2. Mostrar Asignados" << endl;
            cin >> opcion;
            if (opcion == 1) {
                cout << "Lista Personas:" << endl << listaPe->toString() << endl;
                cout << "Lista Libros:" << endl << listaLi->toString() << endl;
                cout << "Ingrese el id del libro que quiere asignar:" << endl;
                cin >> id;
                cout << "Ingrese el nombre de la persona a la que quiere asignarle el libro" << endl;
                cin >> nombre;
                ap = listaPe->buscarPersona(nombre);
                al = listaLi->buscarLibro(id);
                _PersonaLibro = new PersonaLibro(ap->getNombre(), ap->getApellido(), al->getId(), al->getTitulo());
                listaPL.agregarFinal(_PersonaLibro);
                cout << "Se ha asignado correctamente!" << endl;
                system("pause");
            }
            else if (opcion == 2) {
                system("cls");
                cout << MAGENTA << "ASOCIADOS:" << endl;
                cout << "****************************************" << RESET << endl;
                cout << listaPL.toString() << endl;
                cout << MAGENTA << "****************************************" << RESET << endl;
                system("pause");
            }
            break;

        case 5:
            system("cls");
            cout << "\n\n\t\t";
            cout << "***** Cambiar Suscripcion - Playlist ******";
            cout << "\n\n\t\t";
            break;

        case 6:
            listaPL.guardar(salida);
            listaPe->guardar(salida1);
            listaLi->guardar(salida2);
            salida.close();
            salida1.close();
            salida2.close();
            cout << "\n\t\t";
            cout << "Los datos se guardaron exitosamente en el archivo" << endl;
            final = true;
            break;

        default:
            cout << "\n\t\t";
            cout << "La opcion es incorrecta" << endl;
        }
    }
}
