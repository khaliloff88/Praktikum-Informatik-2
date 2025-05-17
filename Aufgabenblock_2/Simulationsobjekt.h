/*
 * Simulationsobjekt.h
 *
 *  Created on: Nov 27, 2024
 *      Author: khxli
 */

#ifndef SIMULATIONSOBJEKT_H_
#define SIMULATIONSOBJEKT_H_
#include <string>


class Simulationsobjekt {
public:
	Simulationsobjekt();
	Simulationsobjekt(std::string name);
	Simulationsobjekt(const Simulationsobjekt&) = delete; //delete of copy constructor
	virtual ~Simulationsobjekt();
	virtual void vSimulieren()=0;
	virtual void vAusgeben(std::ostream&) const;
	Simulationsobjekt& operator =(const Simulationsobjekt& F);
	bool operator==(const Simulationsobjekt& ) const;
	//getters
	std::string getName() const;
	double getZeit() const;

	// setters
	void setZeit(double);


protected:
	double p_dZeit=0;
	std::string p_sName="";


private:
	static int p_iMaxID;
	const int p_iID;
};

std::ostream& operator<<(std::ostream& ausgabe,const Simulationsobjekt& simulationsobjekt);


#endif /* SIMULATIONSOBJEKT_H_ */
