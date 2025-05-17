/*
 * Fahrausnahme.cpp
 *
 *  Created on: Dec 24, 2024
 *      Author: khxli
 */

#include "Fahrausnahme.h"
#include "Weg.h"
#include "Fahrzeug.h"





Fahrausnahme::Fahrausnahme( Fahrzeug& fahrzeug,  Weg& weg):p_pFahrzeug(fahrzeug),p_pWeg(weg){

}


Fahrausnahme::~Fahrausnahme() {
	// TODO Auto-generated destructor stub
}

