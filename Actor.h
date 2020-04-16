#include <iostream>
using namespace std;

class Actor
{
    public:
        Actor();
        Actor(int, string);
        void setId(int Id) {id = Id;};
        int getId() {return id;};
        void setNombre(string nomb) {nombre= nomb;};
        string getNombre (){return nombre; };
        void muestra() {cout<<id<<"\t"<<nombre<<endl;}

    private:
        int id;
        string nombre;
};
Actor::Actor()
{
    id= 0;
    nombre= "S/D";
}
Actor::Actor(int i, string n)
{
    id = i;
    nombre = n;
}
