#include <iostream>
#include <iomanip>
#include <memory>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"

using namespace std;
int Fahrzeug::p_iMaxID=0;
double dGlobaleZeit=0;
double dEpsilon = 0.001;

void vAufgabe_1() {
	Fahrzeug t;
	Fahrzeug t1("Mercedes");

	Fahrzeug* p= new Fahrzeug("Polo");
	delete p;

	unique_ptr<Fahrzeug> U = std::make_unique<Fahrzeug>("Opel");
	unique_ptr<Fahrzeug> U1 = std::make_unique<Fahrzeug>("Renault");
	//unique_ptr<Fahrzeug> U2 = U1; nicht möglich: unique_ptr kann nicht koppiert werden

	shared_ptr<Fahrzeug> S = std::make_shared<Fahrzeug>("Volkswagen");
	shared_ptr<Fahrzeug> S1 = std::make_shared<Fahrzeug>("Mazda");
	cout<<"Shared Pointer count: "<<S1.use_count()<<"\n";
	shared_ptr<Fahrzeug> S2 = S1;
	cout<<"Shared Pointer count: "<<S1.use_count()<<"\n";		// +1 for the shared_pointer S1



	vector<unique_ptr<Fahrzeug>> v;
	v.push_back(move(U));	// kann nicht U als Parameter geben, weil ptr unique ist.
	v.push_back(move(U1));
	v.clear();				// clear the vector
	cout<<v.empty()<<"\n"; // check if the vector is empty


}
void vAufgabe_1a(){

	vector<unique_ptr<Fahrzeug>> v1;

	string n;
	int s;
	for (int i=0;i<3;i++){
		cout<<"Enter the car name: "<<"\n";
		cin>>n;
		cout<<"Enter the car maximum speed: "<<"\n";
		cin>>s;
		v1.push_back(make_unique<Fahrzeug>(n,s));
	}
	Fahrzeug::vKopf();
	double extern dGlobaleZeit;
	for(int i=0;i<3;i++){
		dGlobaleZeit+=0.75;
		v1[0]->vSimulieren();
		cout<<endl;
		cout<<*v1[0];
	}
	cout<<"\n";
}

void vAufgabe_2(){
	int Zahl,Zahl1;
		double MaxG,Verbrauch,TankenV,g;
		char c;
		bool check=true;
		double extern dGlobaleZeit;
		double extern dEpsilon;
		string Name;
		cout<<"Die Anzahl der zu erzeugenden PKWs: "<<'\n';
		cin>>Zahl;
		cout<<"Die Anzahl der zu erzeugenden Fahrräder: "<<'\n';
		cin>>Zahl1;
		vector<unique_ptr<Fahrzeug>> v2;

		for (int i=0;i<Zahl;i++){
				cout<<"Name des PKWs: "<<'\n';
				cin>>Name;
				cout<<"MaxG des PKWs: "<<'\n';
				cin>>MaxG;
				cout<<"Verbrauch des PKWs: "<<'\n';
				cin>>Verbrauch;
				cout<<"Wissen Sie das TankVolum  Y/N?"<<'\n';
				cin>>c;
				if(c=='N'){
					cout<<"No Problem we know it :)"<<'\n';
					v2.push_back(make_unique<PKW>(Name,MaxG,Verbrauch));}
				else{
					cout<<"TankenV des PKWs: "<<'\n';
					cin>>TankenV;
					v2.push_back(make_unique<PKW>(Name,MaxG,Verbrauch,TankenV));}
			}
		for (int i=0;i<Zahl1;i++){
				cout<<"Name des Fahrrads: "<<'\n';
				cin>>Name;
				cout<<"MaxG des Fahrrads: "<<'\n';
				cin>>MaxG;
				v2.push_back(make_unique<Fahrrad>(Name,MaxG));
			}
		Fahrzeug::vKopf();
		const double startTime =dGlobaleZeit;// optional hier : muss aber wenn startTime !=0 ist
		while(dGlobaleZeit<=10){
				dGlobaleZeit +=0.4;
				cout<<"\n";
				double refueltime=3 + startTime;
				if (check && (dGlobaleZeit-refueltime)>=-dEpsilon){
					cout<<"tawa gaad nrefueli M3a "<<dGlobaleZeit<<"\n";
					for (int j=0;j<Zahl;j++){
						v2[j]->dTanken();
						}
					check=false;
				}
				for (size_t i=0;i<v2.size();i++){	//auto& i : v2
					v2[i]->vSimulieren();
					cout<<"dGlobaleZeit:"<<dGlobaleZeit<<"\n";
					cout<<*v2[i];
					cout<<"\n";
				}

			}
}


void vAufgabe_3(){

	double extern dGlobaleZeit;
	dGlobaleZeit+=0.01;
	Fahrzeug* b = new Fahrzeug("Q5", 150);
	PKW* p = new PKW("audi",170,7);
	PKW* o = new PKW("golf",200,7);
	p->vSimulieren();
	o->vSimulieren();

	if (*o<*p){ //TEST von Überladung von '<' vergleich nach Strecke
		cout<<"PKW audi ist mehr gefahren als Golf"<<"\n";
	}
	else if(*p<*o)
		cout<<"PKW golf ist mehr gefahren als Audi"<<"\n";
	else
		cout<<"Der PKW Golf ist genauso viel gefahren wie der Audi"<<"\n";

	PKW k; //Wegen Löschen von CpyK kann ich nicht hier ein Fahrzeug zu dem neuen Fahrzeug zuweisen
	Fahrzeug::vKopf();
	cout<<"\n";
	*p=*o;	// TEST von Überladung von '='
	cout<<*p<<"\n";  // TEST von Überladung von '<<'
}

void fun(shared_ptr<PKW> t){
	shared_ptr<PKW> t1=t;
	weak_ptr<PKW> t2=t;// zähler verändert nicht hier
	cout<<t.use_count()<<endl;
}

int main(){
	//vAufgabe_3();

	/*shared_ptr<PKW> t=make_shared<PKW>("golf",130,7);
	fun(t);
	cout<<t.use_count()<<"\n";*/

	vAufgabe_3();







	return 0;
}


