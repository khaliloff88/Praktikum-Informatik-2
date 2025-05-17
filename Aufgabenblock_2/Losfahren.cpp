/*
 * Losfahren.cpp
 *
 *  Created on: Dec 24, 2024
 *      Author: khxli
 */

#include "Losfahren.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include <iostream>




Losfahren::Losfahren( Fahrzeug& fahrzeug,  Weg& weg):Fahrausnahme(fahrzeug,weg){

}

Losfahren::~Losfahren() {
	// TODO Auto-generated destructor stub
}


const char* Losfahren:: what() const noexcept  {
        return "Losfahren";
    }

void Losfahren::vBearbeiten() {
	extern double dGlobaleZeit;
	std::cout<<"Fahrzeug:"<<p_pFahrzeug.getName()<<"   Weg:"<<p_pWeg.getName()<<"   Art der Ausnahme:"<<this->what()<<"   ZEIT:"<<dGlobaleZeit<<'\n';
	std::unique_ptr<Fahrzeug> ve= (p_pWeg.pAbgabe(p_pFahrzeug));
	p_pWeg.vAnnahme(std::move(ve));  // Move the Fahrzeug to another function
}


