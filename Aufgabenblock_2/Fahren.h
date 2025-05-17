/*
 * Fahren.h
 *
 *  Created on: Dec 23, 2024
 *      Author: khxli
 */

#include "Verhalten.h"





#ifndef FAHREN_H_
#define FAHREN_H_


class Weg;
class Fahrzeug;


class Fahren : public Verhalten {
public:
	Fahren();
	Fahren(Weg&);
	virtual ~Fahren();
	double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) override;
};

#endif /* FAHREN_H_ */
