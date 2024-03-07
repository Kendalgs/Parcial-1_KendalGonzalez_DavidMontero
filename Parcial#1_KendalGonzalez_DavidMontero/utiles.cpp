#include "utiles.h"

//Constructor de utiles
utiles::utiles() {
}

//Destructor de utiles
utiles::~utiles() {
}

//Este método valida si la opción es un entero
int utiles::validarEntero() {
	int opcion = 0;
	bool estado = false;
	while (estado == false) {
		cout << "\n\n\t\t";
		if (!(cin >> opcion)) {
			system("cls");
			cout << "\n\n\t\t";
			cout << "La opcion debe ser un valor entero.";
			cin.clear();
			cout << "\n\n\t\t";
			cout << "Digite de nuevo la informacion:" << endl;
		}
		else {
			estado = true;
		}
		cin.ignore(1000, '\n');

	}
	return opcion;
}

