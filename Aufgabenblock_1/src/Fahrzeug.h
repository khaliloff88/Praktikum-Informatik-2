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


class Fahrzeug {
public:
	Fahrzeug(); // Default konstruktor
	Fahrzeug(std::string); // ein Konstruktor, der einen string als Parameter hat
	Fahrzeug(std::string, double ); // ein Konstruktor, der einen Namen und die maximale Geschwindigkeit als Parameter bekommt.
	Fahrzeug(const Fahrzeug&) = delete; //delete of copy constructor
	virtual ~Fahrzeug();	// Destruktor
	static void vKopf();
	virtual void vSimulieren();
	virtual double dTanken(double dMenge=std::numeric_limits<double>::infinity());
	virtual double dGeschwindigkeit() const;
	virtual void vAusgeben(std::ostream& ausgabe) const;
	bool operator <(const Fahrzeug& F2) const;
	Fahrzeug& operator =(const Fahrzeug& F);

private:
	static int p_iMaxID;
	std::string p_sName="";
	const int p_iID;

protected:
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke=0.0;
	double p_dGesamtZeit=0.0;
	double p_dZeit=0;


};
std::ostream& operator<<(std::ostream& ausgabe, const Fahrzeug& fahrzeug);


#endif /* FAHRZEUG_H_ */
