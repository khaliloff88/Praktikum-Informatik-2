/*
 * Fahrausnahme.h
 *
 *  Created on: Dec 24, 2024
 *      Author: khxli
 */

#ifndef FAHRAUSNAHME_H_
#define FAHRAUSNAHME_H_
#include <exception>
#include <stdexcept>

class Fahrzeug;
class Weg;

class Fahrausnahme : public std::exception {
public:
	Fahrausnahme( Fahrzeug&, Weg&);
	virtual ~Fahrausnahme();
	virtual void vBearbeiten() =0;

protected:
	 Fahrzeug& p_pFahrzeug;
	 Weg& p_pWeg;
};

#endif /* FAHRAUSNAHME_H_ */
