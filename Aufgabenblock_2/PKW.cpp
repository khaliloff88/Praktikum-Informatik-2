/*
 * PKW.cpp
 *
 *  Created on: Oct 27, 2024
 *      Author: khxli
 */

#include "PKW.h"
#include "Verhalten.h"
#include "Parken.h"
#include "Fahren.h"
#include "Weg.h"
#include "SimuClient.h"



#include<algorithm>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>





PKW::PKW() {
	// TODO Auto-generated constructor stub

}

PKW::PKW(std::string s,double g,double v, double tv):Fahrzeug(s,g), p_dVerbrauch(v), p_dTankvolumen(tv), p_dTankinhalt(tv/2) {
	std::cout<<"Verbrauch: "<<p_dVerbrauch<<"\n";

}


PKW::~PKW() {
	// TODO Auto-generated destructor stub
}

double PKW::dTanken(double dMenge) {
	if (dMenge>(p_dTankvolumen-p_dTankinhalt)){
		dMenge=(p_dTankvolumen-p_dTankinhalt);
	}
	p_dTankinhalt+=dMenge;
	return dMenge;
}

double PKW::dGeschwindigkeit()const {
	return std::min(p_dMaxGeschwindigkeit,p_pVerhalten->getWeg().getTempolimit());
}

void PKW::vSimulieren(){
	double extern dGlobaleZeit;
	double extern dEpsilon;
		if (p_dTankinhalt==0.00){	//if p_dTankinhalt!=0 wird mit der Reserve garantiert dass die Fahrzeug den nachsten Schritt mmachen kann.
			p_dZeit=dGlobaleZeit;
			return;
			}
		else{
			double initial =p_dAbschnittStrecke;
			Fahrzeug::vSimulieren();
			p_dTankinhalt-=( (p_dAbschnittStrecke -initial) * p_dVerbrauch)/100; //wird der Verbrauch des nachsten Schritt berechnet und subtrahiert
			if(p_dTankinhalt<=dEpsilon)
				p_dTankinhalt=0.00;
		}
}



void PKW::vAusgeben(std::ostream& ausgabe) const{
	Fahrzeug::vAusgeben(ausgabe);
	ausgabe<< std::fixed << std::setprecision(2);
	ausgabe <<  std::setiosflags(std::ios::right);
	ausgabe<<std::setw(15)<<(p_dGesamtStrecke*p_dVerbrauch)/100
			<<std::setw(15)<<p_dTankinhalt;
	 ausgabe<< std::resetiosflags(std::ios::right);

}


void PKW::vZeichnen(const Weg& weg) const{
	bZeichnePKW(p_sName, weg.getName() , (p_dAbschnittStrecke/weg.getLange()) , this->dGeschwindigkeit(), p_dTankinhalt);
}


