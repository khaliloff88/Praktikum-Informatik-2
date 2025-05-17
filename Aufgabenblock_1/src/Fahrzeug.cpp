/*
 * Fahrzeug.cpp
 *
 *  Created on: Oct 25, 2024
 *      Author: khxli
 */

#include "Fahrzeug.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

Fahrzeug::Fahrzeug():p_iID(++p_iMaxID) {
	std::cout<<"object created"<<"\tID: "<<p_iID<<"\n";
}

Fahrzeug::Fahrzeug(std::string name):p_sName(name),p_iID(++p_iMaxID) {
	std::cout<<"object created"<<"\tID: "<<p_iID<<"\tName: "<<p_sName<<"\n";
}


Fahrzeug::Fahrzeug(std::string name,double geschwindigkeit):p_sName(name),p_iID(++p_iMaxID),p_dMaxGeschwindigkeit((geschwindigkeit >= 0) ? geschwindigkeit : 0.00) {
	std::cout<<"object created"<<"\tID: "<<p_iID<<"\tName: "<<p_sName<<"\tMaxGeschwindigkeit: "<<p_dMaxGeschwindigkeit<<"\n";
}

Fahrzeug::~Fahrzeug() {
	//std::cout<<"object deleted "<<p_iID<<"\n";
}

void Fahrzeug::vAusgeben(std::ostream& ausgabe) const {

	ausgabe << std::fixed << std::setprecision(2);
	ausgabe << std::setiosflags(std::ios::left)<<std::setfill(' ');
	ausgabe<<std::setw(10)<<p_iID
			 <<std::setw(15)<<p_sName
			 <<std::setw(25)<<p_dMaxGeschwindigkeit
			 <<std::setw(16)<<p_dGesamtStrecke
	 	 	 <<std::setw(25)<<dGeschwindigkeit();		// dGeschwindigkeit gibt die AktuelleGeschwindigkeit zurück
    ausgabe << std::resetiosflags(std::ios::left);

}

void Fahrzeug::vKopf(){     // zweifel an setiosflags hier
	std::cout << std::setiosflags(std::ios::left);
	std::cout<<std::setw(10)<<"ID"
				 <<std::setw(15)<<"Name"
				 <<std::setw(25)<<"MaxGeschwindigkeit"
				 <<std::setw(16)<<"GesamtStrecke"
				<<std::setw(25)<<"AktuelleGeschwindigkeit";
	std::cout<<std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right);
	std::cout<<std::setw(15)<<"GesamtVerbrauch"
				<<std::setw(15)<<"Tankinhalt";
    std::cout << std::resetiosflags(std::ios::right);
    std::cout <<"\n"<<std::setfill('-') << std::setw(122);

}

void Fahrzeug::vSimulieren(){
	double extern dGlobaleZeit;
	double extern dEpsilon;
	if(fabs(dGlobaleZeit-p_dZeit)>dEpsilon){
		p_dGesamtStrecke+=(dGlobaleZeit-p_dZeit)*dGeschwindigkeit();
		p_dGesamtZeit+=(dGlobaleZeit-p_dZeit);
		p_dZeit=dGlobaleZeit;
	}
}

double Fahrzeug::dTanken(double d)	{ //dTanken return immer 0.0 für fahrrad
	return 0.0;
}

double Fahrzeug::dGeschwindigkeit() const{	//dGeschwindigkeit return immer p_dMaxGeschwindigkeit für PKWs
	return p_dMaxGeschwindigkeit;
}



bool Fahrzeug::operator <(const Fahrzeug& F2) const{ //Überladung von <
	extern double dEpsilon;
	bool b=((this->p_dGesamtStrecke)<F2.p_dGesamtStrecke) && std::fabs(p_dGesamtStrecke-F2.p_dGesamtStrecke)>dEpsilon;	//tolerenz
	return b;
}


Fahrzeug& Fahrzeug::operator =(const Fahrzeug& F){ //Überladung von =
	if (this != &F){
		p_sName=F.p_sName;
		p_dMaxGeschwindigkeit=F.p_dMaxGeschwindigkeit;
	}
	return *this;	//return von der selben variablen nach die Modifikationen
}



std::ostream & operator<<(std::ostream& ausgabe, const Fahrzeug& fahrzeug) //Überladung von <<
{
    fahrzeug.vAusgeben(ausgabe);	// implementierung von ausgabe
    return ausgabe;
}
