/*
 * Streckenende.cpp
 *
 *  Created on: Dec 24, 2024
 *      Author: khxli
 */

#include "Streckenende.h"
#include <iostream>
#include "Weg.h"
#include "Fahrzeug.h"
#include "Kreuzung.h"


Streckenende::Streckenende( Fahrzeug& fahrzeug, Weg& weg):Fahrausnahme(fahrzeug,weg){

}

Streckenende::~Streckenende() {
	// TODO Auto-generated destructor stub
}


const char* Streckenende:: what() const noexcept  {
        return "Streckenende";
    }


void Streckenende::vBearbeiten() {
	extern double dGlobaleZeit;
	std::cout<<"Fahrzeug:"<<p_pFahrzeug.getName()<<" Weg:"<<p_pWeg.getName()<<" Art der Ausnahme:"<<this->what()<<'\n';
	std::unique_ptr<Fahrzeug> ve=p_pWeg.pAbgabe(p_pFahrzeug);


    auto pKreuzung = p_pWeg.getkreuz();


    if (pKreuzung) {
    	std::shared_ptr<Weg> weg=p_pWeg.getkreuz()->pZufaelligerWeg(p_pWeg);
		p_pWeg.getkreuz()->vTanken(p_pFahrzeug);
		std::cout << "ZEIT: " <<dGlobaleZeit<<"\n";
	    std::cout << "Name der KREUZUNG: " << p_pWeg.getkreuz()->getName() << " \ " << "INHALT DER TANKSTELLE: " <<p_pWeg.getkreuz()->getTankstelle()<<'\n'  ;
	    std::cout << "WECHSEL: " << p_pWeg.getName() << " → " <<weg->getName() <<"\n";
	    std::cout <<"DATEN DES FAHRZEUGS: "<<"\n";
	    Fahrzeug::vKopf();
	    std::cout<<p_pFahrzeug<<"\n"<<"\n";
	    weg->vAnnahme(std::move(ve));
    }
	else{
		std::cout << "Streckenende ohne Zielkreuzung erreicht! Fahrzeug wird nicht umgesetzt." << std::endl;
	}
}

