#include <iostream>
using namespace std;


class Habitacion {
    private:
        int id;
        string elemento;  
        bool tomado;

    public:
        Habitacion();
        Habitacion(int, string);
        void setid(int);
        int getid();
        void setelemento(string);
        string getelemento();
        void tomarelemento();
        bool estatomado();
        void mostrarhabitacion();
};


class Jugador {
    private:
        int posicion; 
        int puntos;

    public:
        Jugador();
        Jugador(int);
        void setposicion(int);
        int getposicion();
        void sumarPuntos();
        int getpuntos();
        void mostrarjugador();
};



Habitacion::Habitacion() {
    id = 0;
    elemento = "Ninguno";
    tomado = false;
}
Habitacion::Habitacion(int _id, string _elemento) {
    id = _id;
    elemento = _elemento;
    tomado = false;
}
void Habitacion::setid(int _id) { id = _id; }
int Habitacion::getid() { return id; }
void Habitacion::setelemento(string e) { elemento = e; }
string Habitacion::getelemento() { return elemento; }
void Habitacion::tomarelemento() { tomado = true; }
bool Habitacion::estatomado() { return tomado; }
void Habitacion::mostrarhabitacion() {
    cout << "Habitacion " << id << " | Elemento: " << elemento;
    if(tomado) cout << " (tomado)";
    cout << endl;
}


Jugador::Jugador() {
    posicion = 1; // empieza en Hab 1
    puntos = 0;
}
Jugador::Jugador(int _pos) {
    posicion = _pos;
    puntos = 0;
}
void Jugador::setposicion(int p) { posicion = p; }
int Jugador::getposicion() { return posicion; }
void Jugador::sumarPuntos() { puntos += 10; }
int Jugador::getpuntos() { return puntos; }
void Jugador::mostrarjugador() {
    cout << "Jugador en Habitacion " << posicion << " | Puntos: " << puntos << endl;
}


int main() {
    // Creamos habitaciones manualmente
    Habitacion habs[8]; // usamos índices 1 a 7
    habs[1] = Habitacion(1, "Alimento");
    habs[2] = Habitacion(2, "Arma");
    habs[3] = Habitacion(3, "Alimento");
    habs[4] = Habitacion(4, "Ninguno");
    habs[5] = Habitacion(5, "Arma");
    habs[6] = Habitacion(6, "Alimento");
    habs[7] = Habitacion(7, "Arma");

   
    Jugador j(1);

    int pasos = 8; // cantidad máxima de movimientos
    char comando;

    cout << "=== Juego de Busqueda ===" << endl;
    cout << "Comandos: N (norte), S (sur), E (este), O (oeste), T (tomar elemento)" << endl;

    while(pasos > 0) {
        cout << "\nPasos restantes: " << pasos << endl;
        j.mostrarjugador();
        habs[j.getposicion()].mostrarhabitacion();

        cout << "Ingrese comando: ";
        cin >> comando;

        int pos = j.getposicion();

        if(comando == 'N' || comando == 'n') {
            if(pos == 3) j.setposicion(1);
            else if(pos == 4) j.setposicion(2);
            else if(pos == 6) j.setposicion(4);
            else cout << "No se puede ir al norte.\n";
        }
        else if(comando == 'S' || comando == 's') {
            if(pos == 1) j.setposicion(3);
            else if(pos == 2) j.setposicion(4);
            else if(pos == 4) j.setposicion(6);
            else cout << "No se puede ir al sur.\n";
        }
        else if(comando == 'E' || comando == 'e') {
            if(pos == 1) j.setposicion(2);
            else if(pos == 3) j.setposicion(4);
            else if(pos == 4) j.setposicion(5);
            else if(pos == 6) j.setposicion(7);
            else cout << "No se puede ir al este.\n";
        }
        else if(comando == 'O' || comando == 'o') {
            if(pos == 2) j.setposicion(1);
            else if(pos == 4) j.setposicion(3);
            else if(pos == 5) j.setposicion(4);
            else if(pos == 7) j.setposicion(6);
            else cout << "No se puede ir al oeste.\n";
        }
        else if(comando == 'T' || comando == 't') {
            Habitacion &h = habs[pos];
            if(h.getelemento() != "Ninguno" && !h.estatomado()) {
                cout << "Tomaste un " << h.getelemento() << "!" << endl;
                j.sumarPuntos();
                h.tomarelemento();
            } else {
                cout << "No hay elemento disponible aqui.\n";
            }
        }
        else {
            cout << "Comando no valido.\n";
        }

        pasos--;
    }

    cout << "\n=== Juego terminado ===" << endl;
    j.mostrarjugador();
    cout << "Puntaje final: " << j.getpuntos() << endl;

    return 0;
}
