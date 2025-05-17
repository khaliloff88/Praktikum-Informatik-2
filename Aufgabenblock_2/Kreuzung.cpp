/*
 * Kreuzung.cpp
 *
 *  Created on: Dec 30, 2024
 *      Author: khxli
 */

#include "Kreuzung.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include <random>



Kreuzung::Kreuzung(std::string name , double t): Simulationsobjekt(name) , p_dTankstelle(t){
}

Kreuzung::~Kreuzung() {
	// TODO Auto-generated destructor stub
}

void Kreuzung::vTanken(Fahrzeug& fahrzeug){
	if (p_dTankstelle>0){
		 double volume=fahrzeug.dTanken();
		p_dTankstelle=p_dTankstelle-volume;
		if(p_dTankstelle<0)
			p_dTankstelle=0.0;
	}
}

void Kreuzung::vAnnahme(std::unique_ptr<Fahrzeug> fahrzeug, double t){
	extern double dEpsilon;
	this->vTanken(*fahrzeug); //Die Fahrzeuge sollen dabei ggf. aufgetankt werden.
	if(-dEpsilon<t && t<dEpsilon){
		roads.front()->vAnnahme(move(fahrzeug));
	}
	else{
		roads.front()->vAnnahme(move(fahrzeug),t);
	}
}

void Kreuzung::vSimulieren(){
	for (std::shared_ptr<Weg>& weg : roads) {
		weg->vSimulieren();
	}
}

/*std::shared_ptr<Weg> Kreuzung::pZufaelligerWeg(Weg& weg){

	int zuf;
	auto it = roads.begin();
	if(roads.size()>1){	// to make sure it is not ”Sackgasse”
		static std::mt19937 device(0);
		std::uniform_int_distribution<int> dist(0,roads.size()-1);
		zuf = dist(device);
		std::advance(it, zuf);

		while( **it== *(weg.getrueckweg())){		//check if this is the rückweg
			zuf = dist(device);
			std::advance(it, zuf);
		}
	}
	return *it ;
}*/

std::shared_ptr<Weg> Kreuzung::pZufaelligerWeg(Weg& ankunftsWeg){
	std::vector<std::shared_ptr<Weg>> moeglicheWege;

	    // to filter the possible routes
	    auto rueckweg = ankunftsWeg.getrueckweg();
	    for (const auto& weg : roads) {
	        if (weg != rueckweg) {
	            moeglicheWege.push_back(weg);
	        }
	    }

	    if (moeglicheWege.empty()) {
	        return ankunftsWeg.getrueckweg();  // Dead-end case
	    }

	    static std::mt19937 device(0);
	    std::uniform_int_distribution<> dist(0, moeglicheWege.size() - 1);
	    return moeglicheWege[dist(device)];
}


double Kreuzung::getTankstelle(){
	return p_dTankstelle;
}

void Kreuzung::vVerbinde(std::string name1 ,std::string name2 ,double laenge ,std::shared_ptr<Kreuzung> k1 ,std::shared_ptr<Kreuzung> k2,  Tempolimit T){
	std::shared_ptr<Weg> f1=std::make_shared<Weg>(name1,laenge,T,k2);
	std::shared_ptr<Weg> f2=std::make_shared<Weg>(name2,laenge,T,k1);
	f1->setRueckweg(f2);
	f2->setRueckweg(f1);
	k1->roads.push_back(f1);
	k2->roads.push_back(f2);
}




