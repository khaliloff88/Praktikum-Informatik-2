/*
 * Fahrrad.h
 *
 *  Created on: Oct 27, 2024
 *      Author: khxli
 */

#include "Fahrzeug.h"
#include <string>

#ifndef FAHRRAD_H_
#define FAHRRAD_H_

class Fahrrad: public Fahrzeug {
public:
	Fahrrad();
	Fahrrad(std::string name, double geschwindigkeit); // ein Konstruktor, der einen Namen und die maximale Geschwindigkeit als Parameter bekommt.
	virtual ~Fahrrad();	//Destruktor
	double dGeschwindigkeit() const override;

};

#endif /* FAHRRAD_H_ */
