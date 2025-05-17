/*
 * Kreuzung.h
 *
 *  Created on: Dec 30, 2024
 *      Author: khxli
 */

#ifndef KREUZUNG_H_
#define KREUZUNG_H_
#include "Simulationsobjekt.h"
#include <memory>
#include <list>
#include "Tempolimit.h"



class Weg;
class Fahrzeug;

class Kreuzung : public Simulationsobjekt{
public:
	Kreuzung(std::string, double t=0);
	virtual ~Kreuzung();
	static void vVerbinde(std::string,std::string,double,std::shared_ptr<Kreuzung>,std::shared_ptr<Kreuzung>, Tempolimit);
	void vTanken(Fahrzeug&);
	void vAnnahme(std::unique_ptr<Fahrzeug>,double t=0);
	void vSimulieren() override;
	std::shared_ptr<Weg> pZufaelligerWeg(Weg&);




	//getters
	double getTankstelle ();

private:
	double p_dTankstelle;
	std::list<std::shared_ptr<Weg>> roads;

};

#endif /* KREUZUNG_H_ */
