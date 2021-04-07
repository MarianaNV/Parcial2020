#include <iostream>
#include <math.h>

#define G 9.81
#define pi 3.241617

using namespace std;

struct Do{ //Disparo Ofensivo
    float d = 800;
    float Ho = 100;
    float Xo = 0;
    float Yo = Ho;
    float d0 = 0.05*d;
};

struct DD{ //Disparo defensivo
    float d = 800;
    float Hd = 200;
    float Xd = d;
    float Yd = Hd;
    float d0 = 0.025*d; //distancia de disparo

};


void DisparoOfensivo(Do, DD, int);

void ImprimirResultados(int angle, int Vin, float x, float y);


int main()
{

    Do disparoO;
    DD disparoD;

    int Vi;
    cout<<"Ingrese la velocidad desde la cual quiere probar: ";
    cin>>Vi; //Velocidad inicial del proyectil

    DisparoOfensivo(disparoO,disparoD,Vi);



    return 0;
}


void DisparoOfensivo(Do disparoO, DD disparoD, int Vii){

    int flag = 0;
    float x,y;
    float Vxo, Vyo;
    float Vini = 0; //Velocidad inicial del proyectil
    int t = 0;
    int angle = 0;

    for(Vini=Vii;;Vini+=5){ //Va aumentando en 5 la velocidad
        for(angle = 0;angle < 90;angle++){
            Vxo = Vini*cos(angle*pi/180);
            Vyo = Vini*sin(angle*pi/180);
            x = 0.0; //Son redundantes
            y = 0.0;
            for(t = 0;;t++){ //Cuanto tiempo se demora en hacer dichos impactos
                x = Vxo*t;
                y = disparoO.Yo+Vyo*t-(0.5*G*t*t);
                if(sqrt(pow(disparoD.Xd-x,2)+pow(disparoD.Yd-y,2)) < disparoO.d0){
                    if(y < 0) y=0;
                    ImprimirResultados(angle,Vini,x,y);
                    flag++;
                    Vini+=50; //Se puede omitir si se desea
                    break;
                }
                if(y < 0) break;
            }
            if(flag == 3) break;
        }
        if(flag == 3) break;
    }
    if(flag != 3) cout << "No impacto ningun disparo." << endl;

}

void ImprimirResultados(int angle, int Vin, float x, float y){

    cout << "Impacto con un angulo: " << angle << " grados"<<endl;
    cout << "Impacto con una velocidad inicial: " << Vin << " m/s"<<endl;
    cout << "Impacto con una posicion x: " << x << " m"<<endl;
    cout << "Impacto con una posicion y: " << y << " m"<<endl;
}
