#include <iostream>
#include "Actor.h"
using namespace std;

class Pelicula
{
    public:
        Pelicula();
        void setNumPeli(int np) {numPeli= np;};
        int getNumPeli() {return numPeli;};
        void setTitulo(string tit) { titulo = tit;};
        string getTitulo() {return titulo;};
        void setAnio(int an) {anio = an;};
        int getAnio() {return anio;};
        void setDuracion(int dr) {duracion = dr;};
        int getDuracion() {return duracion;};
        void setGenero(string gen) {genero = gen;};
        string getGenero() {return genero;};
        int getCantActores() {return cantActores;};
        Actor getListaActores(int i) {return listaActores[i];};
        bool agregarActor(Actor);
        
    private:
        int numPeli;
        string titulo;
        int anio;
        int duracion;
        string genero;
        int cantActores;
        Actor listaActores[10];
};

Pelicula::Pelicula()
{
    numPeli = 0;
    titulo = "S/D";
    anio = 0;
    duracion = 0;
    genero = "S/D";
    cantActores = 0;
    Actor actDef;
    for (int j=0; j<10;j++)
    {
        listaActores[j] = actDef;
    }
}

bool Pelicula::agregarActor(Actor a1)
{   int z=0;
    int x = cantActores;
    if(x<10)
    {
        for(int y=0; y<x; y++)
        {   
            int comp = listaActores[y].getId();
            if(a1.getId()==comp) //Verificar que el id no se repita
            {   
                cout<<"ERROR. El actor con id "<<comp<<" está duplicado ";
                return false;
            }
            else if (a1.getId()!=comp) {z++;} //Aumentar contador por cada vez que no se repite
        }
        if (z==x) //Cuando no se repitió en toda la lista, se agrega en el ultimo espacio
        {   
            listaActores[x].setNombre(a1.getNombre());
            listaActores[x].setId(a1.getId());
            cantActores++;
            return true;
        }
    }
    else if(cantActores>=10) {cout<<"No se puede agregar actor, la pelicula ya contiene 10 actores\n"; return false;}
}
