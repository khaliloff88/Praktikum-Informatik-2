/*
 * Fahrrad.cpp
 *
 *  Created on: Oct 27, 2024
 *      Author: khxli
 */

#include "Fahrrad.h"
#include "SimuClient.h"
#include "Weg.h"



Fahrrad::Fahrrad() {
	// TODO Auto-generated constructor stub

}

Fahrrad::Fahrrad(std::string name, double geschwindigkeit): Fahrzeug(name,geschwindigkeit){
	// TODO Auto-generated constructor stub
}

Fahrrad::~Fahrrad() {
	// TODO Auto-generated destructor stub
}
double Fahrrad::dGeschwindigkeit() const {
	extern double dEpsilon;
	if (p_dMaxGeschwindigkeit-12.0<dEpsilon){
		return p_dMaxGeschwindigkeit;
	}
	double s=p_dGesamtStrecke;
	double AktuelleGeschwindigkeit=p_dMaxGeschwindigkeit;// kann ich g in der Klasse definieren damit ich mein Program optimieren und nicht mehr rechnen wenn g=12
	while(s-20>-dEpsilon){
			AktuelleGeschwindigkeit=AktuelleGeschwindigkeit*0.9;
			s=s-20;
			if(AktuelleGeschwindigkeit-12.0<=dEpsilon){
				AktuelleGeschwindigkeit=12.0;
				return AktuelleGeschwindigkeit;
			}
	}
	double t=AktuelleGeschwindigkeit;
	return AktuelleGeschwindigkeit;
}

void Fahrrad::vZeichnen(const Weg& weg) const{
	bZeichneFahrrad(p_sName , weg.getName() , p_dAbschnittStrecke/weg.getLange() , this->dGeschwindigkeit() );
}






