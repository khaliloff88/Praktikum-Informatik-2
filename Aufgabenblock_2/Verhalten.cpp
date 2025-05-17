/*
 * Verhalten.cpp
 *
 *  Created on: Dec 8, 2024
 *      Author: khxli
 */

#include "Verhalten.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include "Streckenende.h"
#include "Fahrausnahme.h"
#include <algorithm>


#include <cmath>
#include <iostream>






Verhalten::Verhalten(  Weg& g): p_pWeg(g) {
}

Verhalten::~Verhalten() {
	// TODO Auto-generated destructor stub
}


// here we need a lot of changes.


double Verhalten::dStrecke(Fahrzeug& aFzg, double dZeitIntervall){	// have to check the during simulation maybe i should control the unicity of calling the func

	double extern dEpsilon;
	double len= p_pWeg.getLange();
	double speed= aFzg.dGeschwindigkeit();
	double total= aFzg.getAbschnittStrecke();
	double Teilstrecke=std::min(len-total,(dZeitIntervall* speed));
	//std::cout<<Teilstrecke;
	if ( -dEpsilon<=Teilstrecke && Teilstrecke<=dEpsilon){
		//std::cout<<" das Fahrzeug steht am Ende des Weges "<<'\n';

		throw Streckenende(aFzg,p_pWeg);
	}
	return Teilstrecke;

}


const Weg& Verhalten::getWeg() const {
        return p_pWeg;
    }
