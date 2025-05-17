/*
 * Losfahren.h
 *
 *  Created on: Dec 24, 2024
 *      Author: khxli
 */

#ifndef LOSFAHREN_H_
#define LOSFAHREN_H_

#include "Fahrausnahme.h"

class Losfahren : public Fahrausnahme{
public:
	Losfahren( Fahrzeug&, Weg&);
	virtual ~Losfahren();

	const char* what() const noexcept override;
	void vBearbeiten()  override;


};

#endif /* LOSFAHREN_H_ */
