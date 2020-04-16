#include <iostream>
#include "Hora.h"
using namespace std;

class Funcion
{
    public:
        Funcion();
        Funcion(string, int, Hora, int);
        void setCveFuncion(string claveF) {cveFuncion = claveF;};
        string getCveFuncion () {return cveFuncion;};
        void setNumPeli(int nump) {numPeli = nump;};
        int getNumPeli() {return numPeli;};
        void setHora (Hora hr) {hora.setHh(hr.getHh()); hora.setMm(hr.getMm());};
        Hora getHora(){return hora;}; 
        void setSala(int sla) { sala= sla;};
        int getSala () {return sala;}
        void muestra();

    private:
        string cveFuncion;
        int numPeli;
        Hora hora;
        int sala;
};
Funcion::Funcion()
{
    Hora h1;
    cveFuncion = "S/D";
    numPeli = 0;
    hora = h1;
    sala = 0;
}
Funcion::Funcion(string clav, int num, Hora h, int s)
{
    cveFuncion = clav;
    numPeli = num;
    hora = h;
    sala = s;
}
void Funcion::muestra()
{
  cout<<"  ~Datos de la Funcion~"<<endl;
  cout<<"Clave de Funcion: "<<cveFuncion<<endl;
  cout<<"No. de Pelicula: "<<numPeli<<endl;
  cout<<"Horario: "; hora.muestra();
  cout<<"Sala: "<<sala<<endl;
}
