#include <iostream>
#include <math.h>

#define G 9.81
#define pi 3.241617

using namespace std;

struct Do{ //Disparo Ofensivo
    float d=800;
    float Ho=100;
    float Xo=0;
    float Yo=Ho;
    float d0=0.05*d;
};

struct DD{ //Disparo defensivo
    float d=800;
    float Hd=200;
    float Xd=d;
    float Yd=Hd;
    float d0=0.025*d; //distancia de disparo

};

int main()
{

    Do disparoO;
    DD disparoD;

    int Vi;
    cout<<"Ingrese la velocidad desde la cual quiere probar: ";
    cin>>Vi; //Velocidad inicial



    return 0;
}
