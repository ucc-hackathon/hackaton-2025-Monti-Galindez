#include <iostream>
using namespace std;

class Equipo {
    private:
        string nombre;

    public:
        Equipo();
        Equipo(string);
        void setnombre(string);
        string getnombre();
};

class Partido {
    private:
        Equipo equipo1;
        Equipo equipo2;
        int golesEquipo1;
        int golesEquipo2;

    public:
        Partido();
        Partido(Equipo, Equipo, int, int);
        Equipo getequipo1();
        Equipo getequipo2();
        int getgolesEquipo1();
        int getgolesEquipo2();
        int gettotalgoles();
        void mostrarpartido();
};


class Tabla {
    private:
        string nombre;
        int puntos;

    public:
        Tabla();
        Tabla(string, int);
        void setnombre(string);
        string getnombre();
        void setpuntos(int);
        int getpuntos();
        void sumarpuntos(int);
};


Equipo::Equipo() { nombre = ""; }
Equipo::Equipo(string n) { nombre = n; }
void Equipo::setnombre(string n) { nombre = n; }
string Equipo::getnombre() { return nombre; }


Partido::Partido() {
    golesEquipo1 = 0;
    golesEquipo2 = 0;
}
Partido::Partido(Equipo e1, Equipo e2, int g1, int g2) {
    equipo1 = e1;
    equipo2 = e2;
    golesEquipo1 = g1;
    golesEquipo2 = g2;
}
Equipo Partido::getequipo1() { return equipo1; }
Equipo Partido::getequipo2() { return equipo2; }
int Partido::getgolesEquipo1() { return golesEquipo1; }
int Partido::getgolesEquipo2() { return golesEquipo2; }
int Partido::gettotalgoles() { return golesEquipo1 + golesEquipo2; }
void Partido::mostrarpartido() {
    cout << equipo1.getnombre() << " " << golesEquipo1
         << " vs " << equipo2.getnombre() << " " << golesEquipo2
         << " | Total goles: " << gettotalgoles() << endl;
}


Tabla::Tabla() { nombre = ""; puntos = 0; }
Tabla::Tabla(string n, int p) { nombre = n; puntos = p; }
void Tabla::setnombre(string n) { nombre = n; }
string Tabla::getnombre() { return nombre; }
void Tabla::setpuntos(int p) { puntos = p; }
int Tabla::getpuntos() { return puntos; }
void Tabla::sumarpuntos(int p) { puntos += p; }


void ordenarPartidos(Partido partidos[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(partidos[j].gettotalgoles() < partidos[j+1].gettotalgoles()) {
                Partido aux = partidos[j];
                partidos[j] = partidos[j+1];
                partidos[j+1] = aux;
            }
        }
    }
}


int main() {

    Equipo UCC("UCC"), UNC("UNC"), UTN("UTN"), UNRC("UNRC"), UBP("UBP"), UES21("UES21");


    Partido partidos[15] = {
        Partido(UNRC, UBP, 0, 0),
        Partido(UCC, UNRC, 3, 0),
        Partido(UTN, UBP, 2, 2),
        Partido(UNC, UES21, 3, 1),
        Partido(UBP, UES21, 2, 1),
        Partido(UCC, UTN, 4, 1),
        Partido(UNC, UNRC, 2, 2),
        Partido(UCC, UBP, 0, 2),
        Partido(UTN, UNC, 1, 0),
        Partido(UTN, UNRC, 0, 1),
        Partido(UCC, UNC, 2, 1),
        Partido(UCC, UES21, 2, 2),
        Partido(UNC, UBP, 1, 3),
        Partido(UTN, UES21, 1, 0),
        Partido(UNRC, UES21, 2, 3)
    };


    ordenarPartidos(partidos, 15);
    cout << "=== Partidos ordenados por total de goles ===" << endl;
    for(int i=0; i<15; i++) {
        partidos[i].mostrarpartido();
    }


    Tabla tabla[6] = {
        Tabla("UCC", 0), Tabla("UNC", 0), Tabla("UTN", 0),
        Tabla("UNRC", 0), Tabla("UBP", 0), Tabla("UES21", 0)
    };


    for(int i=0; i<15; i++) {
        int g1 = partidos[i].getgolesEquipo1();
        int g2 = partidos[i].getgolesEquipo2();
        string eq1 = partidos[i].getequipo1().getnombre();
        string eq2 = partidos[i].getequipo2().getnombre();

        int idx1=-1, idx2=-1;
        for(int k=0; k<6; k++) {
            if(tabla[k].getnombre() == eq1) idx1 = k;
            if(tabla[k].getnombre() == eq2) idx2 = k;
        }

        if(g1 > g2) tabla[idx1].sumarpuntos(3);
        else if(g2 > g1) tabla[idx2].sumarpuntos(3);
        else { // empate
            tabla[idx1].sumarpuntos(1);
            tabla[idx2].sumarpuntos(1);
        }
    }

    // burbuja
    for(int i=0; i<5; i++) {
        for(int j=0; j<5-i; j++) {
            if(tabla[j].getpuntos() < tabla[j+1].getpuntos()) {
                Tabla aux = tabla[j];
                tabla[j] = tabla[j+1];
                tabla[j+1] = aux;
            }
        }
    }


    cout << "\n=== Tabla de posiciones ===" << endl;
    for(int i=0; i<6; i++) {
        cout << (i+1) << ". " << tabla[i].getnombre()
             << " - " << tabla[i].getpuntos() << " puntos" << endl;
    }

    return 0;
}
