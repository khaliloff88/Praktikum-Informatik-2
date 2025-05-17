/*
 * Weg.cpp
 *
 *  Created on: Nov 30, 2024
 *      Author: khxli
 */

#include "Weg.h"
#include "Fahrzeug.h"
#include "Losfahren.h"
#include "Streckenende.h"
#include "Kreuzung.h"

#include <list>





#include <limits>
#include <iostream>
#include <iomanip>



Weg::Weg() {
	// TODO Auto-generated constructor stub

}
Weg::Weg(std::string name, double lange, Tempolimit T,std::shared_ptr<Kreuzung> k):Simulationsobjekt(name),p_dLange(lange),p_eTempolimit(T),kreuz(k) {

}

Weg::~Weg() {
	// TODO Auto-generated destructor stub
}


double Weg::getTempolimit() const{
	switch (p_eTempolimit){
	case Tempolimit::Innerorts:
		return 50;
	case Tempolimit::Landstraße:
		return 100;
	case Tempolimit::Autobahn:
		return std::numeric_limits<int>::max();
	}
}

void Weg::vSimulieren(){
	l.vAktualisieren();
	for (const std::unique_ptr<Fahrzeug>& fahrzeug : l) {
		double m = fahrzeug->getMaxGeschwindigkeit();
		try{
		fahrzeug->vSimulieren();
		fahrzeug->vZeichnen(*this);
		 //std::cout<<*fahrzeug;
		}
		catch ( Fahrausnahme& e) { // i moved catch here to avoid calling a nullptr through vZeichen and cout because the ptr is moved in pAbgabe
			e.vBearbeiten();
		}
	}
	l.vAktualisieren();
}

void Weg::vKopf(){
	std::cout << std::setiosflags(std::ios::left);
		std::cout<<std::setw(10)<<"ID"
					 <<std::setw(10)<<"| Name"
					 <<std::setw(15)<<"| Laenge"
					 <<std::setw(17)<<"| Fahrzeuge";
		std::cout<<std::resetiosflags(std::ios::left);
	    std::cout <<"\n"<<std::setfill('-') << std::setw(52)<<"\n";
}

void Weg::vAusgeben(std::ostream& ausgabe) const{
	std::string fahr="  ( ";
	for (const std::unique_ptr<Fahrzeug>& fahrzeug : l) {	// understand this line more
		        fahr+=(fahrzeug->getName())+" " ;
		    }
	fahr+=")";
	Simulationsobjekt::vAusgeben(ausgabe);
	ausgabe<<":"<<std::resetiosflags(std::ios::left) << std::setiosflags(std::ios::right)
				 <<std::setw(13)<<p_dLange<<std::resetiosflags(std::ios::right) << std::setiosflags(std::ios::left)<<std::setw(17)<<fahr<<std::resetiosflags(std::ios::left);
}

double Weg::getLange() const{
	return p_dLange;
}



void Weg::vAnnahme(std::unique_ptr<Fahrzeug> fz){
	fz->vNeueStrecke(*this);
	l.push_back(std::move(fz));

}

void Weg::vAnnahme(std::unique_ptr<Fahrzeug> fz, double st){
	fz->vNeueStrecke(*this,st);
	l.push_front(std::move(fz));
}

std::unique_ptr<Fahrzeug> Weg::pAbgabe(const Fahrzeug& fhz){		//beachten sie nullptr??
	std::unique_ptr<Fahrzeug> ve= nullptr;

	for (auto it = l.begin(); it != l.end(); ) {
	    if (*it != nullptr && fhz == **it) {
	        //std::cout << "\"" << (*it)->getName() << "\" is deleted\n";
	        ve = std::move(*it);
	        l.erase(it);
			return ve;
	    }
	    else{
	        ++it;
	    }
	}
	return ve;
}


// getters
std::shared_ptr<Weg> Weg::getrueckweg() const{
	return rueckweg.lock();
}

std::shared_ptr<Kreuzung> Weg::getkreuz() const{
	return kreuz.lock();
}


void Weg::setRueckweg(const std::shared_ptr<Weg>& rueckwegPtr) {
       rueckweg = rueckwegPtr;
   }
