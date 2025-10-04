#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Tablero {
private:
    int n;
    char celdas[20][20];

public:
    Tablero(int _n) {
        n = _n;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                celdas[i][j] = '.'; // vacío
    }

    void mostrar() {
        cout << "   ";
        for(int j=0; j<n; j++) cout << j+1 << " ";
        cout << endl;
        for(int i=0; i<n; i++) {
            if(i+1 < 10) cout << " " << i+1 << " ";
            else cout << i+1 << " ";
            for(int j=0; j<n; j++) {
                cout << celdas[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool colocar(int f, int c, char pieza) {
        if(f<0 || f>=n || c<0 || c>=n) return false;
        if(celdas[f][c] != '.') return false;
        celdas[f][c] = pieza;
        return true;
    }

    int getN() { return n; }
};

int main() {
    srand(time(0));

    int tam;
    cout << "Ingrese tamaño del tablero (8-20): ";
    cin >> tam;
    if(tam < 8) tam = 8;
    if(tam > 20) tam = 20;

    Tablero t(tam);

    // lista de piezas básicas
    char piezas[6] = {'|','-','+','L','T','='};

    int jugadas = 0, total = tam * tam;

    while(jugadas < total) {
        t.mostrar();

        // turno del jugador
        int f, c, op;
        cout << "\nTurno del jugador (fila col pieza 0-5): ";
        cin >> f >> c >> op;
        if(!t.colocar(f-1, c-1, piezas[op % 6])) {
            cout << "Movimiento invalido. Intente de nuevo.\n";
            continue;
        }
        jugadas++;
        if(jugadas >= total) break;

        // turno de la computadora
        int rf, rc;
        do {
            rf = rand()%tam;
            rc = rand()%tam;
        } while(!t.colocar(rf, rc, piezas[rand()%6]));
        cout << "Computadora coloca en (" << rf+1 << "," << rc+1 << ")\n";
        jugadas++;
    }

    cout << "\n=== Juego terminado ===\n";
    t.mostrar();
    cout << "Puntaje no calculado (se puede agregar despues).\n";

    return 0;
}

