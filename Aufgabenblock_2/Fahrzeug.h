/*
 * Fahrzeug.h
 *
 *  Created on: Oct 25, 2024
 *      Author: khxli
 */

#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_
#include <string>
#include <limits>
#include <memory>
#include "Simulationsobjekt.h"




class Weg;
class Verhalten;

class Fahrzeug : public Simulationsobjekt{
public:
	Fahrzeug(); // Default konstruktor
	Fahrzeug(std::string); // ein Konstruktor, der einen string als Parameter hat
	Fahrzeug(std::string, double); // ein Konstruktor, der einen Namen und die maximale Geschwindigkeit als Parameter bekommt.
	Fahrzeug(const Fahrzeug&) = delete; //delete of copy constructor
	virtual ~Fahrzeug();	// Destruktor
	static void vKopf();
	void vSimulieren() override;
	virtual double dTanken(double dMenge=std::numeric_limits<double>::infinity());
	virtual double dGeschwindigkeit() const;
	void vAusgeben(std::ostream& ausgabe) const override;
	bool operator <(const Fahrzeug& F2) const;
	Fahrzeug& operator =(const Fahrzeug& F);
	void vNeueStrecke(Weg&);
	void vNeueStrecke(Weg&,double);

	virtual void vZeichnen(const Weg&) const;

	// getters
	double getMaxGeschwindigkeit() const;
	double getGesamtStrecke() const;
	double getGesamtZeit() const;
	double getAbschnittStrecke() const;
	Verhalten& getVerhalten() ;

// maybe should be private





protected:
		double p_dMaxGeschwindigkeit;
		double p_dGesamtStrecke=0.0;
		double p_dGesamtZeit=0.0;
		double p_dAbschnittStrecke=0;
		std::unique_ptr<Verhalten> p_pVerhalten;

};


#endif /* FAHRZEUG_H_ */
