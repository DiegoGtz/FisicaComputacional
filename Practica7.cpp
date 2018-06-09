//Practica de Numero 7 Fisica Computacional Teoria del Caos
//Gtz


#include <iostream>
#include <fstream>
using namespace std;



void lorentz();

void kutta();




//Variables Globales
const double o = 10.0;//numero de Prandtl(viscosidad/conductividad termica)
const double b = 2.666667;// razon entre la longitud  y altura del sistema 
const double r = 28.0;//numero de Rayleigh(Diferencia de Temperatura entre la base y el tope)
const double n = 5000;

int main()
{


	//lorentz();
	kutta();

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
		archivo<<x<<"\t"<<y<<"\t"<<z<<endl;
		x = x +o*(y-x)*h;
		y = y +(r*x-y-x*z)*h;
		z = z +(x*y-b*z)*h;

		To++;

	}

}

void kutta(){

	ofstream archivo1;
	archivo1.open("kutta.csv",ios::out);


	int To = 0;
	int Tf = 100;
	double h = (Tf-To)/n;
	double x = 5.0;
	double y = 5.0;	
	double z = 5.0;

	int i=0;
    double k1x,k1y,k1z,k2x,k2y,k2z,k3x,k3y,k3z,k4x,k4y,k4z;
    while(i<=3000)
    {
		cout<<x<<"   "<<y<<"    "<<z<<"    "<<endl;
		archivo1<<x<<"\t"<<y<<"\t"<<z<<endl;

        k1x=-o*x+o*y;
        k1y=r*x-y-x*z;
        k1z=-b*z+x*y;

        k2x=-o*(x+(0.5)*h*k1x)+o*(y+(0.5)*h*k1y);
        k2y=r*(x+(0.5)*h*k1x)-(y+(0.5)*h*k1y)-(x+(0.5)*h*k1x)*(z+(0.5)*h*k1z);
        k2z=-b*(z+(0.5)*h*k1z)+(x+(0.5)*h*k1x)*(y+(0.5)*h*k1y);

        k3x=-o*(x+(0.5)*h*k2x)+o*(y+(0.5)*h*k2y);
        k3y=r*(x+(0.5)*h*k2x)-(y+(0.5)*h*k2y)-(x+(0.5)*h*k2x)*(z+(0.5)*h*k2z);
        k3z=-b*(z+(0.5)*h*k2z)+(x+(0.5)*h*k2x)*(y+(0.5)*h*k2y);

        k4x=-o*(x+h*k3x)+o*(y+h*k3y);
        k4y=r*(x+h*k3x)-(y+h*k3y)-(x+h*k3x)*(z+h*k3z);
        k4z=-b*(z+h*k3z)+(x+h*k3x)*(y+h*k3y);

        x=x+(h/6.0)*(k1x+2*k2x+2*k3x+k4x);
        y=y+(h/6.0)*(k1y+2*k2y+2*k3y+k4y);
        z=z+(h/6.0)*(k1z+2*k2z+2*k3z+k4z);

        i++;
    }
}








