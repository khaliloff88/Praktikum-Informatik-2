/*
 * Simulationsobjekt.cpp
 *
 *  Created on: Nov 27, 2024
 *      Author: khxli
 */

#include "Simulationsobjekt.h"
#include <iostream>
#include <iomanip>


Simulationsobjekt::Simulationsobjekt():p_iID(p_iMaxID++){
	std::cout<<"object created"<<"\tID: "<<p_iID<<"\n";
}

Simulationsobjekt::Simulationsobjekt(std::string name):p_sName(name),p_iID(p_iMaxID++){
	std::cout<<"object created"<<"\tID: "<<p_iID<<"\tName: "<<p_sName<<"\n";
}

Simulationsobjekt::~Simulationsobjekt() {
	std::cout<<"object with ID: "<<p_iID<<" and name: "<<p_sName<< " was deleted "<<"\n";
}

void Simulationsobjekt::vAusgeben(std::ostream& ausgabe) const{
		ausgabe << std::setiosflags(std::ios::left)<<std::setfill(' ');
		ausgabe<<std::setw(10)<<p_iID<<std::setw(10)<<p_sName;
}

std::ostream & operator<<(std::ostream& ausgabe, const Simulationsobjekt& simulationsobjekt) //Überladung von <<
{
	simulationsobjekt.vAusgeben(ausgabe);	// implementierung von ausgabe
    return ausgabe;
}

Simulationsobjekt& Simulationsobjekt::operator =(const Simulationsobjekt& F){ //Überladung von =
	if (this != &F){
		p_sName=F.p_sName;
	}
	return *this;	//return von der selben variablen nach die Modifikationen
}

bool Simulationsobjekt::operator==(const Simulationsobjekt& S) const{
	return p_iID==S.p_iID;
}

//getters
std::string Simulationsobjekt::getName() const {
	return p_sName;
}

double Simulationsobjekt::getZeit() const{
	return p_dZeit;
}

//setters
void Simulationsobjekt::setZeit(double t){
	p_dZeit=t;
}



