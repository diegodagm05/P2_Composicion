#include <iostream>
using namespace std;

class Hora
{
    public:
        Hora();
        Hora (int, int);
        void setHh(int HH) { hh= HH;}
        int getHh() {return hh;};
        void setMm(int MM) {mm=MM;};
        int getMm() {return mm;};
        void muestra();
    private:
        int hh;
        int mm;
};

Hora::Hora()
{
    hh=-1;
    mm=-1;
}
Hora::Hora(int H, int M)
{
    hh = H;
    mm = M;
}
void Hora::muestra()
{
    if((hh>=0&&hh<10)&&(mm>=0&&mm<10)) {cout<<"0"<<hh<<":"<<"0"<<mm<<endl;} //hora y minutos entre 0 y 9
    else if(hh>=0&&hh<10) {cout<<"0"<<hh<<":"<<mm<<endl;} //Hora entre 0 y 9
    else if(mm>=0&&mm<10) {cout<<hh<<":"<<"0"<<mm<<endl;} //Minutos entre 0 y 9
    else {cout<<hh<<":"<<mm<<endl;} //Ninguno entre 0 y 9
}
