/*
 * Streckenende.h
 *
 *  Created on: Dec 24, 2024
 *      Author: khxli
 */

#ifndef STRECKENENDE_H_
#define STRECKENENDE_H_
#include "Fahrausnahme.h"

class Streckenende : public Fahrausnahme {
public:
	Streckenende( Fahrzeug&, Weg&);
	virtual ~Streckenende();
	void vBearbeiten() override;
	const char* what() const noexcept override;

};

#endif /* STRECKENENDE_H_ */
