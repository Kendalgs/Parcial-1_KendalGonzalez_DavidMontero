#include "interfaz.h"
#include <limits>

 

// Ruta de los archivos de datos
const string interfaz::archivo = "..\\Playlist.txt";

// Constructor de la clase interfaz
interfaz::interfaz()
{
    ifstream entrada(archivo.c_str());
    try {
        _listaPlaylist = new listaPlaylist(entrada);
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
}



// Destructor de la clase interfaz
    interfaz::~interfaz()
    {
        delete _listaPlaylist;

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
    cout << "1. Agregar Cancion a la playlist" << endl;
    cout << "\t\t";
    cout << "2. Eliminar Cancion de la playlist" << endl;
    cout << "\t\t";
    cout << "3. Mostrar Duracion Total de la playlist " << endl;
    cout << "\t\t";
    cout << "4. Mostrar Canciones de la playlist" << endl;
    cout << "\t\t";
    cout << "5. Cambiar Suscripcion " << endl;
    cout << "\t\t";
    cout << "6. Salir " << endl;
}

// Función para mostrar el menú de consultar del usuario normal
void interfaz::mostrarMenu()
{
    int op = 0;
    int opcion = 0;
    string nombre;
    string artista;
    string duracion_str;
    int duracion = 0;
    int duracionTotal = 0;
    string tipoSuscripcion = "Gratuita";
    int ts = 0;
    int cant = 0;

    Cancion* c;
    ofstream salida(archivo.c_str());
    bool final = false;

    while (!final) {
        system("cls");
        cout << "\n\n\t\t";
        cout << "***** MENU PRINCIPAL *****" << endl;
        mostrarOpciones();
        op = seleccionarOpcion();

        while (op > 6) {
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
            if (tipoSuscripcion == "Gratuita" && _listaPlaylist->totalCanciones() >= 10) {
                cout << "No puede agregar mas canciones, alcanzo el limite de la suscripcion gratuita." << endl;
                system("pause");
                break;
            }
            else {
                cout << "Digite el nombre: ";
                cout << "\n\n\t\t";
                getline(cin, nombre);
                cout << "\n\n\t\t";
                cout << "Digite el artista: ";
                cout << "\n\n\t\t";
                getline(cin, artista);
                cout << "\n\n\t\t";
                cout << "Digite la duracion en segundos: ";
                while (true) {
                    cout << "\n\n\t\t";
                    getline(cin, duracion_str);
                    cout << "\n\n\t\t";
                    try {
                        duracion = stoi(duracion_str);
                        if (duracion > 0) {
                            c = new Cancion(nombre, artista, duracion);
                            _listaPlaylist->agregarFinal(c);
                            cout << "Se ha agregado una cancion" << endl;
                            system("pause");
                            break; // Salir del bucle si el número es válido
                        }
                        else {
                            cout << "Entrada invalida. Por favor, ingrese un numero mayor que 0: ";
                        }
                    }
                    catch (invalid_argument&) {
                        cout << "Entrada invalida. Por favor, ingrese un numero mayor que 0: ";
                    }
                    catch (out_of_range&) {
                        cout << "El numero ingresado es demasiado grande. Por favor, ingrese un numero menor: ";
                    }
                }
                break;

            }
            
           

        case 2:
            try {
                system("cls");
                cout << "\n\n\t\t";
                cout << "***** Eliminar Cancion - Playlist ******";
                cout << "\n\n\t\t";
                cout << MAGENTA << "PLAYLIST:" << endl;
                cout << "****************************************" << RESET << endl;
                cout << _listaPlaylist->toString() << endl;
                cout << MAGENTA << "****************************************" << RESET << endl;
                cout << "\n\n\t\t";
                cout << "Digite el nombre de la cancion que quiere eliminar: ";
                cout << "\n\n\t\t";
                getline(cin, nombre);
                _listaPlaylist->eliminarNombre(nombre);
                //cout << _listaPlaylist->toString() << endl;
                system("pause");
            }
            catch(const exception& e){
                cout << e.what() << endl;
            }
            break;

        case 3:
            system("cls");
            cout << "\n\n\t\t";
            cout << "***** Mostrar Duracion Total - Playlist ******";
            cout << "\n\n\t\t";
            duracionTotal = _listaPlaylist->duracionTotal();
            cout << "Duracion Total de la playlist: " << duracionTotal << endl;
            system("pause");
            break;

        case 4:
            system("cls");
            cout << "\n\n\t\t";
            cout << "***** Mostrar Canciones - Playlist ******";
            if (_listaPlaylist->vacio()) {
                cout << "\n\n\t\t";
                cout << "La playlist esta vacia" << endl;
                system("pause");
            }
            else {
                cout << "\n\n\t\t";
                cout << MAGENTA << "PLAYLIST:" << endl;
                cout << "****************************************" << RESET << endl;
                cout << _listaPlaylist->toString() << endl;
                cout << MAGENTA << "****************************************" << RESET << endl;
                system("pause");
            }
            break;

        case 5:
            system("cls");
            cout << "\n\n\t\t";
            cout << "***** Cambiar Suscripcion - Playlist ******";
            cout << "\n\n\t\t";
            cout << "Seleccione el tipo de suscripcion: " << endl;
            cout << "\t\t1. Gratuita" << endl;
            cout << "\t\t2. Premium" << endl;
            cout << "\t\t3. Familiar" << endl;
            cout << "\n\t\t";

            ts = seleccionarOpcion();
            while (ts < 1 || ts > 3) {
                cout << "\n\t\t";
                cout << "Opcion invalida. Seleccione nuevamente: ";
                ts = seleccionarOpcion();
            }
            switch (ts) {
            case 1:
                if (tipoSuscripcion == "Gratuita") {
                    cout << "Ya tienes este tipo de suscrpcion" << endl;
                }
                else {
                    if (tipoSuscripcion == "Premium" || tipoSuscripcion == "Familiar") {
                        cant = _listaPlaylist->totalCanciones();
                        if (cant > 10) {
                            _listaPlaylist->eliminarExceso();
                            tipoSuscripcion = "Gratuita";
                            cout << "Se ha cambiado el tipo de suscripcion" << endl;
                        }
                    }
                    else {
                        tipoSuscripcion = "Gratuita";
                        cout << "Se ha cambiado el tipo de suscripcion" << endl;
                    }
                }
                
                break;
            case 2:
                if (tipoSuscripcion == "Premium") {
                    cout << "Ya tienes este tipo de suscrpcion" << endl;
                }
                else {
                    tipoSuscripcion = "Premium";
                    cout << "Se ha cambiado el tipo de suscripcion" << endl;
                }
                break;
            case 3:
                if (tipoSuscripcion == "Familiar") {
                    cout << "Ya tienes este tipo de suscrpcion" << endl;
                }
                else {
                    tipoSuscripcion = "Familiar";
                    cout << "Se ha cambiado el tipo de suscripcion" << endl;
                }
                break;
            }
            system("pause");
            break;

        case 6:
            _listaPlaylist->guardar(salida);
            salida.close();
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
