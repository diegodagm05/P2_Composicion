#include <iostream>
#include <string>
#include <fstream>
#include "Pelicula.h"
#include "Funcion.h"
using namespace std;

int main()
{       //Arreglos de objetos a usar, de las 3 clases
    Actor actores[20];
    Funcion funciones[20];
    Pelicula peliculas[20];
    
        //Asignacion de actores, del archivo
    ifstream archE;
    archE.open("actores.txt");
    int idA, listAct=0;
    string nombreA;
    while(archE>>idA)
    {   
        getline(archE, nombreA);
        actores[listAct].setId(idA);
        actores [listAct].setNombre(nombreA);
        listAct++;
    }
    archE.close();
        //Asignacion de peliculas, del archivo
    archE.open("peliculas.txt");
    int nump, an, dur, cantA,idAP, listPel=0;
    string gen, titl;
    bool ag;
    while(archE>>nump>>an>>dur>>gen>>cantA)
    {   
        peliculas[listPel].setNumPeli(nump);
        peliculas[listPel].setAnio(an);
        peliculas[listPel].setDuracion(dur);
        peliculas[listPel].setGenero(gen);
        for (int i=0; i<cantA; i++)
        {   int noen=0;
            archE>>idAP;
            for(listAct=0; listAct<20; listAct++) //Este ciclo verifica que el id del archivo exista
            {
                int x = actores[listAct].getId(); //Almacenar id de lista actores en variable x
                if(idAP == x)//comparar x con id de actor lista peliculas
                {   
                    ag = peliculas[listPel].agregarActor(actores[listAct]);//<<endl; //Agregar el objeto actor a la pelicula solo cuando se encuentre
                }
                else if (idAP!=x)//Contador de veces que no coincide id
                {   noen++;
                    if(noen==20) //Mensaje de error cuando no coincide en toda la lista
                    {
                        cout<<"El actor con id "<<idAP<<" no existe en la lista actores. Correjir en archivo\n";
                    }
                }
            }
        }
        getline(archE, titl);
        peliculas[listPel].setTitulo(titl);
        if(!ag){ cout<< "en la pelicula: "<<titl<<endl;}
        listPel++;
    }
    archE.close();
        //Asignacion de funciones por el usuario
    string cve;
    int NoPeli, h,m, sala, listFun=0, opf;
    cout<<"Ingrese los datos de las funciones del día"<<endl;
    do
    {   int opf=0;
        cout<<"Clave: "; cin>>cve;
        cout<<"No. de Pelicula: ";cin>>NoPeli;
        cout<<"~Horario(formato 24hrs)~"<<endl;
        hr:
        cout<<"Hora: ";cin>>h; if (h<0 || h>23){cout<<"Hora invalida, ingrese de nuevo\n"; goto hr;}
        min:
        cout<<"Minutos: ";cin>>m; if (m<0 || m>59){cout<<"Minuto invalido, ingrese de nuevo\n"; goto min;}
        cout<<"Sala: ";cin>>sala;
        Hora hf(h, m);
        funciones[listFun].setCveFuncion(cve);
        funciones[listFun].setNumPeli(NoPeli);
        funciones[listFun].setHora(hf);
        funciones[listFun].setSala(sala);
        listFun++;
        cout<<"¿Desea agregar otra función?"<<endl<<"(1)SI (2)NO "; cin>>opf;
    } while(opf=1);
                    //validación extra    //if(opf>2){cout<<"Opción Invalida. Ingrese nuevamente"; goto a;}
    
    






    /*char op=0;
    //MENU AQUI

    if(op=='A'||op=='a')
    {

    }
    else if(op=='B'||op=='b')
    {
        
    }
    else if(op=='C'||op=='c')
    {
        
    }
    else if(op=='D'||op=='d')
    {
        
    }
    else if(op=='E'||op=='e')
    {
        
    }
    else if(op=='F'||op=='f')
    {
        
    }
    else if(op=='G'||op=='g') {return 0;}
    else { cout<< "Opción invalida\n";}*/
    return 0;

}
