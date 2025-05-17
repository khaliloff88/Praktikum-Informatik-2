/*
 * Fahrzeug.cpp
 *
 *  Created on: Oct 25, 2024
 *      Author: khxli
 */

#include "Fahrzeug.h"
#include "Verhalten.h"
#include "Parken.h"
#include "Fahren.h"
#include "Losfahren.h"
#include "Streckenende.h"

#include "Weg.h"


#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

Fahrzeug::Fahrzeug():Simulationsobjekt() {
}

Fahrzeug::Fahrzeug(std::string name):Simulationsobjekt(name) {

}


Fahrzeug::Fahrzeug(std::string name,double geschwindigkeit):Simulationsobjekt(name),p_dMaxGeschwindigkeit((geschwindigkeit >= 0) ? geschwindigkeit : 0.00) {
	std::cout<<"\tMaxGeschwindigkeit: "<<p_dMaxGeschwindigkeit<<"\n";
}

Fahrzeug::~Fahrzeug() {
	//std::cout<<"object deleted "<<p_iID<<"\n";
}

void Fahrzeug::vAusgeben(std::ostream& ausgabe) const {
	Simulationsobjekt::vAusgeben(ausgabe);
	ausgabe<< std::fixed << std::setprecision(2);
	ausgabe<<std::setw(25)<<p_dMaxGeschwindigkeit
			 <<std::setw(16)<<p_dGesamtStrecke
	 	 	 <<std::setw(25)<<dGeschwindigkeit()	//this here is used as instanz	// dGeschwindigkeit gibt die AktuelleGeschwindigkeit zurück
			 <<std::setw(20)<<p_dAbschnittStrecke;
    ausgabe << std::resetiosflags(std::ios::left);
}

void Fahrzeug::vKopf(){     // zweifel an setiosflags hier
	std::cout << std::setiosflags(std::ios::left);
	std::cout<<std::setw(10)<<"ID"
				 <<std::setw(10)<<"Name"
				 <<std::setw(25)<<"MaxGeschwindigkeit"
				 <<std::setw(16)<<"GesamtStrecke"
				<<std::setw(25)<<"AktuelleGeschwindigkeit"
				<<std::setw(20)<<"AbschnittStrecke";
	std::cout<<std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right);
	std::cout<<std::setw(15)<<"GesamtVerbrauch"
				<<std::setw(15)<<"Tankinhalt";
    std::cout << std::resetiosflags(std::ios::right);
    std::cout <<"\n"<<std::setfill('-') << std::setw(142)<<"\n";

}

void Fahrzeug::vSimulieren(){
	double extern dGlobaleZeit;
	double extern dEpsilon;
		if(fabs(dGlobaleZeit-p_dZeit)>dEpsilon){
		double deltatime=dGlobaleZeit-p_dZeit;
		p_dZeit=dGlobaleZeit;
		double AktuelleStrecke=p_pVerhalten->dStrecke(*this,deltatime);
		p_dGesamtStrecke+=AktuelleStrecke;
		p_dAbschnittStrecke+=AktuelleStrecke;// still must be checked
		p_dGesamtZeit+=(dGlobaleZeit-p_dZeit);
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
		Simulationsobjekt::operator=(F);
		p_dMaxGeschwindigkeit=F.p_dMaxGeschwindigkeit;
	}
	return *this;	//return von der selben variablen nach die Modifikationen
}

void Fahrzeug::vNeueStrecke(Weg& W){
	p_dAbschnittStrecke=0.0;
	p_pVerhalten=std::make_unique<Fahren>(W);
}

void Fahrzeug::vNeueStrecke(Weg& W, double st){
	p_dAbschnittStrecke=0.0;
	p_pVerhalten=std::make_unique<Parken>(W,st);
}

void Fahrzeug::vZeichnen(const Weg& weg) const{
}



//getters
double Fahrzeug::getMaxGeschwindigkeit() const{
	return p_dMaxGeschwindigkeit;
}



double Fahrzeug::getGesamtStrecke() const{
	return p_dGesamtStrecke;
}
double Fahrzeug::getGesamtZeit() const{
	return p_dGesamtZeit;
}

double Fahrzeug::getAbschnittStrecke() const{
	return p_dAbschnittStrecke;
}

 Verhalten& Fahrzeug::getVerhalten()  {
		return *p_pVerhalten;
	}






