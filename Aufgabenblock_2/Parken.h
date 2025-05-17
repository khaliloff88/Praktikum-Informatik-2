/*
 * Parken.h
 *
 *  Created on: Dec 23, 2024
 *      Author: khxli
 */

#include "Verhalten.h"
class Weg;

#ifndef PARKEN_H_
#define PARKEN_H_
class Parken : public Verhalten {
public:
	Parken();
	Parken(  Weg&, double);
	virtual ~Parken();
	double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) override;

private:
	const double p_dStart;

};

#endif /* PARKEN_H_ */
