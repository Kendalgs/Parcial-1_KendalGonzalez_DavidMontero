#include "sstring.h"

// Deserializa una cadena desde un flujo de entrada.
string sstring::deserialize(ifstream& in) {
    string r;

    // Lee la longitud de la cadena desde el archivo.
    size_t n = 0;
    in.read((char*)&n, sizeof(size_t));

    // Lee los caracteres de la cadena desde el archivo.
    char* c = new char[n];
    in.read(c, static_cast<std::streamsize>(n));
    r = string(c);
    delete[] c;

    // Verifica si la operación de lectura fue exitosa.
    if (!in.good())
        throw - 1;

    return r;
}

// Serializa una cadena en un flujo de salida.
bool sstring::serialize(ofstream& out, const string& s) {
    bool r = true;

    // Primero, guarda la longitud de la cadena, 
    // teniendo en cuenta el carácter nulo de terminación.
    size_t n = s.length() + 1;
    out.write((char*)&n, sizeof(size_t));

    // Luego, graba los caracteres que componen la cadena.
    out.write(s.c_str(), static_cast<std::streamsize>(n));

    // Devuelve true si la operación de escritura fue exitosa.
    return out.good();
}
