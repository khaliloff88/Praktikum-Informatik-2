/*
 * Verhalten.h
 *
 *  Created on: Dec 8, 2024
 *      Author: khxli
 */

#ifndef VERHALTEN_H_
#define VERHALTEN_H_

class Weg;
class Fahrzeug;

class Verhalten {
public:
	Verhalten();
	Verhalten( Weg&);
	virtual ~Verhalten();
	virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall)=0;

	// Getters
	const Weg& getWeg() const ;

protected:
	   Weg& p_pWeg;	// must check if this correct


};

#endif /* VERHALTEN_H_ */
