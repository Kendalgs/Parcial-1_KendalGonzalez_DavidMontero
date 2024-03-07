
#ifndef SSTRING_H
#define	SSTRING_H

#include "std.h"

class sstring {
public:
	static string deserialize(ifstream&);
	static bool serialize(ofstream&, const string&);
};

#endif	/* SSTRING_H */

