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
        nombreA.erase(0,1);
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
        titl.erase(0,1);
        peliculas[listPel].setTitulo(titl);
        if(!ag){ cout<< "en la pelicula: "<<titl<<endl;}
        listPel++;
    }
    archE.close();
    
        //Asignacion de funciones por el usuario
    string cve;
    int NoPeli, h,m, sala, listFun=0;
    cout<<"Ingrese los datos de las funciones del día"<<endl;
    a:
        int opf=0;
        cout<<"Clave: "; cin>>cve;
        funciones[listFun].setCveFuncion(cve);
        nopeli:
        cout<<"No. de Pelicula: ";cin>>NoPeli;
        int noen1=0;
        for (int numerop=0; numerop<listPel; numerop++)
        {   
            if(NoPeli==peliculas[numerop].getNumPeli()) {funciones[listFun].setNumPeli(NoPeli);}
            else if(NoPeli!=peliculas[numerop].getNumPeli()){noen1++;}
            if (noen1==listPel){cout<<"No. de Pelicula no existe, ingrese uno valido\n"; goto nopeli;}
        }
        cout<<"~Horario(formato 24hrs)~"<<endl;
        hr:
        cout<<"Hora: ";cin>>h; if (h<0 || h>23){cout<<"Hora invalida, ingrese de nuevo\n"; goto hr;}
        min:
        cout<<"Minutos: ";cin>>m; if (m<0 || m>59){cout<<"Minuto invalido, ingrese de nuevo\n"; goto min;}
        Hora hf(h, m);
        funciones[listFun].setHora(hf);
        cout<<"Sala: ";cin>>sala;
        funciones[listFun].setSala(sala);
        listFun++;
        otrf:
        cout<<"¿Desea agregar otra función?"<<endl<<"(1)SI (2)NO "; cin>>opf;
    if(opf==1) { goto a;}
    else if(opf>2){cout<<"Opción Invalida. Ingrese nuevamente\n"; goto otrf;}
    
    menu:
    char op=0;
    cout<<"     ~MENÚ DE OPCIONES~"<<endl;
    cout<<"A) Mostrar lista de Actores"<<endl;
    cout<<"B) Mostrar lista de Peliculas"<<endl;
    cout<<"C) Mostrar funciones del día"<<endl;
    cout<<"D) Consultar funcion por hora"<<endl;
    cout<<"E) Consultar funcion por clave"<<endl;
    cout<<"F) Consultar peliculas de un Actor"<<endl;
    cout<<"G) Terminar"<<endl;
    cout<<"Seleccione una opción: ";cin>>op;
    
    if(op=='A'||op=='a') //Mostrar actores
    {
        cout<<"~Id~"<<"\t"<<"~Nombre del Actor~"<<endl; //Encabezado
        for (int act=0; act<20; act++)
        {
            actores[act].muestra();
        }
        goto menu;
    }
    else if(op=='B'||op=='b')
    {
        cout<<"~Titulo~\t\t\t"<<"~Año~\t"<<"~Duracion~\t"<<"~Genero~\t"<<"~Actores~"<<endl; //Encabezado
        for (int pel=0; pel<11; pel++)
        {
            peliculas[pel].muestra();cout<<endl;
        }
        goto menu;
    }
    else if(op=='C'||op=='c')
    {
        for (int fun=0; fun<listFun; fun++)
        {
            funciones[fun].muestra();
        }
        goto menu;
    }
    else if(op=='D'||op=='d')
    {   horanueva:
        int hr, min, noen2=0;
        int encab=0;
        cout<<"~Ingrese la hora de la funcion a consultar(formato 24hrs)~"<<endl;
        hr2:
        cout<<"Hora: ";cin>>hr; if (hr<0 || hr>23){cout<<"Hora invalida, ingrese de nuevo\n"; goto hr2;}
        min2:
        cout<<"Minutos: ";cin>>min; if (min<0 || min>59){cout<<"Minuto invalido, ingrese de nuevo\n"; goto min2;}
        Hora hf(hr, min);
        for(int j=0; j<listFun; j++)
        {   int y;
            if(hf.getHh()==funciones[j].getHora().getHh() && hf.getMm()==funciones[j].getHora().getMm()) //Se encuentra el horario en funciones
            {
                if (encab==0) //Mostar encabezado en un inicio
                {
                    cout<<"~Funciones con horario "<<hr<<":"<<min<<"~\n";
                    encab = 1;
                }
                for(int k=0; k<listPel; k++) //Mostrar titulo de la funcion
                {
                    y = peliculas[k].getNumPeli();
                    if(funciones[j].getNumPeli()==y)
                    {
                        cout<<"La pelicula: "<<peliculas[k].getTitulo();
                        cout<<"\nSe presenta en la sala: "<<funciones[j].getSala()<<endl;
                    }
                }
            }
            else if(hf.getHh()!=funciones[j].getHora().getHh() || hf.getMm()!=funciones[j].getHora().getMm())
            {noen2++;}//Contador de veces que no encuentra
            if(noen2==listFun)//Si no encuentra el horario en todas la funciones arroja mensaje
            {
                cout<<"No hay funciones con horario "<<hr<<":"<<min<<endl; goto horanueva;
            }
        }
        goto menu;
    }
    else if(op=='E'||op=='e')
    {
        
    }
    else if(op=='F'||op=='f')
    {
        
    }
    else if(op=='G'||op=='g') {return 0;}
    else { cout<< "Opción invalida\n";}
    return 0;

}
