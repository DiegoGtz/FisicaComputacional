//Practica de Numero 7 Fisica Computacional Teoria del Caos
//Gtz


#include <iostream>
#include <fstream>
using namespace std;



void lorentz();




//Variables Globales
const double o = 10.0;//numero de Prandtl(viscosidad/conductividad termica)
const double b = 2.666667;// razon entre la longitud  y altura del sistema 
const double r = 28.0;//numero de Rayleigh(Diferencia de Temperatura entre la base y el tope)
const double n = 5000;

int main()
{


	lorentz();

	return 0;
}


void lorentz(){

	ofstream archivo;
	archivo.open("lore.csv",ios::out);


	int To = 0;
	int Tf = 100;
	double h = (Tf-To)/n;
	double x = 5.0;
	double y = 5.0;	
	double z = 5.0;

	while (To <= 3000){	
		cout<<x<<"   "<<y<<"    "<<z<<"    "<<endl;
		archivo<<x<<"\t"<<y<<endl;
		x = x +o*(y-x)*h;
		y = y +(r*x-y-x*z)*h;
		z = z +(x*y-b*z)*h;

		To++;

	}



}