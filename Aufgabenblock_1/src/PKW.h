/*
 * PKW.h
 *
 *  Created on: Oct 27, 2024
 *      Author: khxli
 */
#include "Fahrzeug.h"
#ifndef PKW_H_
#define PKW_H_
#include <limits>


class PKW:public Fahrzeug {
public:
	PKW();
	PKW(std::string s,double g,double v, double tv=55);
	virtual ~PKW();
	double dTanken(double dMenge=std::numeric_limits<double>::infinity()) override;
	void vSimulieren() override;
	void vAusgeben(std::ostream& ausgabe) const override;


private:
	double p_dVerbrauch,p_dTankvolumen,p_dTankinhalt;
};

#endif /* PKW_H_ */
