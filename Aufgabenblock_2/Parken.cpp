/*
 * Parken.cpp
 *
 *  Created on: Dec 23, 2024
 *      Author: khxli
 */

#include "Parken.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Losfahren.h"


#include <iostream>


Parken::Parken( Weg& c, double f): Verhalten(c), p_dStart(f) {

}

Parken::~Parken() {
	// TODO Auto-generated destructor stub
}


double Parken::dStrecke(Fahrzeug& aFzg, double dZeitIntervall){

	extern double dGlobaleZeit;
			extern double dEpsilon;
			if((-dEpsilon+p_dStart)<=dGlobaleZeit){
				aFzg.setZeit(p_dStart);
				double t =dGlobaleZeit;
				throw Losfahren(aFzg,p_pWeg);
			}
			return 0.0;
}

