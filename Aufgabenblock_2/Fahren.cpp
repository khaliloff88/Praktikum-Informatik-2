/*
 * Fahren.cpp
 *
 *  Created on: Dec 23, 2024
 *      Author: khxli
 */

#include "Fahren.h"
#include "Weg.h"// try after without auch in Parken
#include "Fahrzeug.h"

Fahren::Fahren( Weg& c): Verhalten(c){	// reuse code of Verhalten

}

Fahren::~Fahren() {
	// TODO Auto-generated destructor stub
}

double Fahren::dStrecke(Fahrzeug& aFzg, double dZeitIntervall) {
	return Verhalten::dStrecke(aFzg,dZeitIntervall);// reuse code
}

