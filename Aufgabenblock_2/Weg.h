/*
 * Weg.h
 *
 *  Created on: Nov 30, 2024
 *      Author: khxli
 */

#ifndef WEG_H_
#define WEG_H_

#include <list>
#include <memory>
#include "Tempolimit.h"
#include "Simulationsobjekt.h"
#include "vertagt_liste - Vorlage.h"



class Kreuzung;

class Fahrzeug;

class Weg : public Simulationsobjekt{
public:
	Weg();
	Weg(std::string name,double lange, Tempolimit T=Tempolimit::Autobahn,std::shared_ptr<Kreuzung> f= nullptr);		// i have to check how T should be initialised
	virtual ~Weg();
	static void vKopf();	// what happens if i have two vkopf static
	void vSimulieren() override;
	void vAusgeben(std::ostream& ausgabe) const override;


	void vAnnahme(std::unique_ptr<Fahrzeug>);
	void vAnnahme(std::unique_ptr<Fahrzeug>,double);
	double getTempolimit() const;

	std::unique_ptr<Fahrzeug> pAbgabe(const Fahrzeug&);

	//Getters
	double getLange() const;
	std::shared_ptr<Weg> getrueckweg() const;
	std::shared_ptr<Kreuzung> getkreuz() const;

	// Setters
	void setRueckweg(const std::shared_ptr<Weg>&);



private:
	std::weak_ptr<Weg> rueckweg;
	const std::weak_ptr<Kreuzung>  kreuz ;

	vertagt::VListe<std::unique_ptr<Fahrzeug>> l;
	double p_dLange;
	Tempolimit p_eTempolimit;	// how to use this tempolimit type


};

#endif /* WEG_H_ */
