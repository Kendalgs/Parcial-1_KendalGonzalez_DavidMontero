
#ifndef SSTRING_H
#define	SSTRING_H

#include "std.h"

class sstring {
public:
	static string deserialize(ifstream&);
	static bool serialize(ofstream&, const string&);
	static int deserializeInt(ifstream&); // Nueva función para deserializar un entero
	static bool serializeInt(ofstream&, int); // Nueva función para serializar un entero

};

#endif	/* SSTRING_H */

