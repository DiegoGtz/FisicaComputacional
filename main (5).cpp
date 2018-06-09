#include<graphics.h>
#include<dos.h>
#include<iostream>
#include<sstream>
#include <stdio.h>
#include <cmath>
#include <queue>
using namespace std;

queue <double> X1;
queue <double> Y1;
queue <double> Z1;

queue <double> X;
queue <double> Y;
queue <double> Z;

char str[3];


void numerar3()
{
    int j=0;
    for(int i=-20; i<=40; i=i+5)
    {
        //char str[3];
        sprintf(str,"%d",i);

        outtextxy(45+j,415,str);
        j+=80;
    }
    j=0;

    for(int k=-25; k<=25; k=k+5)
    {
        sprintf(str,"%d",k);
        outtextxy(370,820-j,str);
        j+=80;
    }
    setcolor(7);
    line(370,0,370,910);
    line(0,430,1400,430);
}

void numerar4()
{
    int j=0;
    for(int i=-10; i<=40; i=i+5)
    {
        //char str[3];
        sprintf(str,"%d",i);

        outtextxy(45+j,415,str);
        j+=160;
    }
    j=0;

    for(int k=-25; k<=25; k=k+5)
    {
        sprintf(str,"%d",k);
        outtextxy(370,820-j,str);
        j+=80;
    }
    setcolor(7);
    line(370,0,370,810);
    line(0,430,1400,430);
}

void numerar5()
{
    int j=0;
    for(int i=-40; i<=40; i=i+5)
    {
        //char str[3];
        sprintf(str,"%d",i);

        outtextxy(45+j,415,str);
        j+=40;
    }
    j=0;

    for(int k=-50; k<=50; k=k+5)
    {
        sprintf(str,"%d",k);
        outtextxy(370,820-j,str);
        j+=40;
    }
    setcolor(7);
    line(370,0,370,810);
    line(0,430,1400,430);

}

void lorentz()// con euler
{
    double o=10.0;
    double b=2.666667;
    double r=28.0;
    double x=5.0;
    double y=5.0;
    double z=5.0;
    int t=0;
    int tf=100;
    double n=5000.0;

    double h=(tf-t)/n;

    while( t<=3000)
    {
        X1.push(x);
        Y1.push(y);
        Z1.push(z);

        x=x+o*(y-x)*h;
        y=y+(r*x-y-x*z)*h;
        z=z+(x*y-b*z)*h;
        t++;
    }
}


void lkutta()// con rk4
{
    double o=10.0;
    double b=2.666667;
    double r=28.0;
    double x=5.0;
    double y=5.0;
    double z=5.0;
    int t=0;
    int tf=100;
    double n=5000.0;

    double h=(tf-t)/n;
    int i=0;
    double k1x,k1y,k1z,k2x,k2y,k2z,k3x,k3y,k3z,k4x,k4y,k4z;
    while(i<=3000)
    {
        X.push(x);
        Y.push(y);
        Z.push(z);

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

void tablalorentz()
{
    double i=0.0;
    int x=370;
    int y=410;
    int y0=810;
    cout<<"Tiempo        ";
    cout<<"Conejos"<<"             ";
    cout<<"Zorros"<<"             "<<endl;
    cout<<"-------------------------------------------------"<<endl;

    cout<<endl;

    while(i<=3000)
    {
        cout<<i<<"              ";
        cout<<X.front()<<"          ";
        if(i==0) cout<<"       ";
        cout<<Y.front()<<"   "<<Z.front()<<endl;

        setcolor(5);

        if(i>0) line(x,y,370+Y.front()*8,430-Z.front()*8);
        x=370+Y.front()*8;
        y=430-Z.front()*8;
/*
setcolor(9);
        line(x,y,370+i*0.65,430-Z.front()*8);
        x=370+i*0.65;
        y=430-Z.front()*8;
*/
        X.pop();
        Y.pop();
        Z.pop();
        i++;
    }
}


int main()
{


    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");


    setcolor(4);
    numerar5();
    //sina();
    //tablacon();
    //kutta();
    //lorentz();
    lkutta();
    tablalorentz();
    //tablalorentz1();
    setcolor(7);
    //line(50,0,50,810);
    //line(50,810,1400,810);
    getch();
    closegraph();

    return 0;
}
