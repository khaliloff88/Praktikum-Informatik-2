#include <iostream>
#include <iomanip>
#include <memory>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include "Fahrzeug.h"
#include "PKW.h"
#include "Weg.h"
#include "Fahrrad.h"
#include "Simulationsobjekt.h"
#include "Tempolimit.h"
#include "Verhalten.h"
#include "Parken.h"
#include "Fahren.h"
#include "Losfahren.h"
#include "Streckenende.h"
#include "Fahrausnahme.h"
#include "SimuClient.h"
#include <random>
#include "vertagt_liste - Vorlage.h"
#include "Kreuzung.h"






using namespace std;
int Simulationsobjekt::p_iMaxID=0;
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

/*void vAufgabe_2(){
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
}*/


void vAufgabe_3(){

	double extern dGlobaleZeit;
	dGlobaleZeit+=0.01;
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
void vAufgabe_4(){
	unique_ptr<Weg> uh=std::make_unique<Weg>("Weg" ,100);
	Weg::vKopf();
	cout<<*uh<<'\n';
}


void vAufgabe_5(){
	extern double dGlobaleZeit;

	unique_ptr<Weg> uh=std::make_unique<Weg>("kayas" ,100,Tempolimit::Autobahn);

	unique_ptr<Fahrzeug> f1=std::make_unique<PKW>("BMW",120,7);
	unique_ptr<Fahrzeug> f2=std::make_unique<Fahrrad>("BMX",40);
	uh->vAnnahme(move(f1));
	uh->vAnnahme(move(f2),2);
	Weg::vKopf();
	cout<<*uh<<'\n';
	cout<<'\n';
	//Fahrzeug::vKopf();
	dGlobaleZeit=0;
	while (dGlobaleZeit<=10) {
		//Fahrzeug::vKopf();
		cout<<" \n dGlobaleZeit: "<<dGlobaleZeit<<'\n';
		uh->vSimulieren();
		//cout<<'\n';
		dGlobaleZeit+=0.5;

		}
	}


void vAufgabe_6(){
	extern double dGlobaleZeit;

			unique_ptr<Weg> yhez=std::make_unique<Weg>("yhez" ,400,Tempolimit::Landstraße);
			unique_ptr<Weg> yjib=std::make_unique<Weg>("yjib" ,400,Tempolimit::Landstraße);

			unique_ptr<Fahrzeug> f1=std::make_unique<PKW>("BMW",200,4,600);
			unique_ptr<Fahrzeug> f2=std::make_unique<Fahrrad>("BMX",40);

			unique_ptr<Fahrzeug> f3=std::make_unique<PKW>("POLO",120,7);
			unique_ptr<Fahrzeug> f4=std::make_unique<Fahrrad>("BIKE",30);

		yhez->vAnnahme(move(f1));

		yhez->vAnnahme(move(f2),3);
		yjib->vAnnahme(move(f3),1.5);
		//yjib->vAnnahme(move(f4));

		Weg::vKopf();
		cout<<*yhez<<'\n';
		cout<<*yjib<<'\n';

		cout<<'\n';
		dGlobaleZeit=0;


		bInitialisiereGrafik(800, 500);
		int Koordinaten[4]={700, 250, 100, 250};
		bZeichneStrasse("yhez","yjib", yhez->getLange(), 2, Koordinaten);

		while (dGlobaleZeit<=10) {

			vSetzeZeit(dGlobaleZeit);

			yjib->vSimulieren();
			yhez->vSimulieren();

			dGlobaleZeit+=0.3;
			vSleep(100);

		}

		std::cout << "Press Enter to exit..." << std::endl;
				        std::cin.get();


}

void vAufgabe_6a(){
	vertagt::VListe<int> vlist;

	static std::mt19937 device(0);
	std::uniform_int_distribution<int> dist(1, 10);

	for (int i=0;i<7;i++){
		int zuf = dist(device);
		vlist.push_back(zuf);
	}
	vlist.vAktualisieren();

	for (auto& i : vlist)
	{
		cout<<i<<"\t";
	}
	cout<<"\n";
	for (auto it = vlist.begin(); it != vlist.end(); ) {
		if ((*it)>5){
			vlist.erase(it);
		}
		++it;
	}

	for (auto& i : vlist)
		{
		cout<<i<<"\t";
		}
	cout<<"\n";

	vlist.vAktualisieren();

	for (auto& i : vlist)
		{
		cout<<i<<"\t";
		}
	cout<<"\n";

	vlist.push_front(3);
	vlist.push_back(11);
	vlist.vAktualisieren();
	for (auto& i : vlist)
			{
			cout<<i<<"\t";
			}
		cout<<"\n";

}

void vAufgabe_7 (){
	bInitialisiereGrafik(1920, 1080);

		bZeichneKreuzung(680, 40);
		bZeichneKreuzung(680, 300);
		bZeichneKreuzung(680, 570);
		bZeichneKreuzung(320, 300);


		std::string nameHin1 = "W12";
		std::string nameRueck1 = "W21";

		std::string nameHin2 = "W23a";
		std::string nameRueck2 = "W32a";

		std::string nameHin3 = "W23b";
		std::string nameRueck3 = "W32b";

		std::string nameHin4 = "W24";
		std::string nameRueck4 = "W42";

		std::string nameHin5 = "W34";
		std::string nameRueck5 = "W43";

		std::string nameHin6 = "W44a";
		std::string nameRueck6 = "W44b";

		std::shared_ptr<Kreuzung> Kr1 = std::make_shared<Kreuzung>("Kr1");
		std::shared_ptr<Kreuzung> Kr2 = std::make_shared<Kreuzung>("Kr2",1000);
		std::shared_ptr<Kreuzung> Kr3 = std::make_shared<Kreuzung>("Kr3");
		std::shared_ptr<Kreuzung> Kr4 = std::make_shared<Kreuzung>("Kr4");

	    Kreuzung::vVerbinde(nameHin1, nameRueck1, 40, Kr1, Kr2, Tempolimit::Innerorts);  // Strasse 1
	    Kreuzung::vVerbinde(nameHin2, nameRueck2, 115, Kr2, Kr3, Tempolimit::Autobahn); // Strasse 2
	    Kreuzung::vVerbinde(nameHin3, nameRueck3, 40, Kr2, Kr3, Tempolimit::Innerorts); // Strasse 3
	    Kreuzung::vVerbinde(nameHin4, nameRueck4, 55, Kr2, Kr4, Tempolimit::Innerorts); // Strasse 4
	    Kreuzung::vVerbinde(nameHin5, nameRueck5, 85, Kr3, Kr4, Tempolimit::Autobahn);  // Strasse 5
	    Kreuzung::vVerbinde(nameHin6,nameRueck6,130, Kr4, Kr4, Tempolimit::Landstraße); // Strasse 6


	    int koordStrasse1[] = {680, 40, 680, 300};
	    bZeichneStrasse("W12", "W21", 40, 2, koordStrasse1);

	    int koordStrasse2[] = {680, 300, 850, 300, 970, 390, 970, 500, 850, 570, 680, 570};
	    bZeichneStrasse("W23a", "W32a", 115, 6, koordStrasse2);

	    int koordStrasse3[] = {680, 300, 680, 570};
	    bZeichneStrasse("W23b", "W32b", 40, 2, koordStrasse3);

	    int koordStrasse4[] = {680, 300, 320, 300};
	    bZeichneStrasse("W24", "W42", 55, 2, koordStrasse4);

	    int koordStrasse5[] = {680, 570, 500, 570, 350, 510, 320, 420, 320, 300 };
	    bZeichneStrasse("W34", "W43", 85, 5, koordStrasse5);

	    int koordStrasse6[] = {320, 300, 320, 150, 200,  60,  80,  90,  70, 250, 170, 300, 320, 300};
	    bZeichneStrasse("W44a", "W44b", 130, 7, koordStrasse6);
	    auto car1 = std::make_unique<PKW>("Polo",60,8);
	    auto car2 = std::make_unique<PKW>("Audi",80,10);
	    auto bike1 = std::make_unique<Fahrrad>("bike1",40);
	    auto bike2 = std::make_unique<Fahrrad>("bike2",18);

	    Kr1->vAnnahme(std::move(car1),3);
	    Kr1->vAnnahme(std::move(car2),6);
	    Kr1->vAnnahme(std::move(bike1));
	    Kr1->vAnnahme(std::move(bike2),2);

		double dTimeStep = 0.1;
		double dSimulationDuration= 4;
	    while (  -0.001<= dSimulationDuration-dGlobaleZeit)  {
			vSleep(100);
	        vSetzeZeit(dGlobaleZeit);

	    	//cout<<" \n dGlobaleZeit: "<<dGlobaleZeit<<'\n';
	    	//Fahrzeug::vKopf();
	    	Kr1->vSimulieren();
	    	Kr2->vSimulieren();
	    	Kr3->vSimulieren();
	    	Kr4->vSimulieren();

	    	dGlobaleZeit += dTimeStep;

	    }
	    std::cout << "Press Enter to exit..." << std::endl;
	    std::cin.get();
}


int main(){
	vAufgabe_7();
	cout<<"tout va bien";

	return 0;
}


