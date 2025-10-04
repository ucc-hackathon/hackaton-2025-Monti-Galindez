#include <iostream>
using namespace std;

class Usuario
{
private:
    string nombre;
    int legajo;

public:
    Usuario();
    Usuario(string, int);
    void setnombre(string);
    string getnombre();
    void setlegajo(int);
    int getlegajo();
    void mostrarusuario();
};

class Alumno : public Usuario
{
private:
    int anioCursado;

public:
    Alumno();
    Alumno(string, int, int);
    void setaniocursado(int);
    int getaniocursado();
    void mostraralumno();
};

class Profesor : public Usuario
{
private:
    string area;

public:
    Profesor();
    Profesor(string, int, string);
    void setarea(string);
    string getarea();
    void mostrarprofesor();
};

class Libro
{
private:
    string codigo;
    string titulo;
    string autor;
    int anio;
    string categoria;
    bool prestado;

public:
    Libro();
    Libro(string, string, string, int, string);
    void setcodigo(string);
    string getcodigo();
    void settitulo(string);
    string gettitulo();
    void setautor(string);
    string getautor();
    void setanio(int);
    int getanio();
    void setcategoria(string);
    string getcategoria();
    void prestar();
    void devolver();
    void mostrarlibro();
};

Usuario::Usuario() {}
Usuario::Usuario(string _nombre, int _legajo)
{
    nombre = _nombre;
    legajo = _legajo;
}
void Usuario::setnombre(string _nombre) { nombre = _nombre; }
string Usuario::getnombre() { return nombre; }
void Usuario::setlegajo(int _legajo) { legajo = _legajo; }
int Usuario::getlegajo() { return legajo; }
void Usuario::mostrarusuario()
{
    cout << "Usuario: " << nombre << " | Legajo: " << legajo << endl;
}

Alumno::Alumno() : Usuario() {}
Alumno::Alumno(string _nombre, int _legajo, int _anioCursado) : Usuario(_nombre, _legajo)
{
    anioCursado = _anioCursado;
}
void Alumno::setaniocursado(int a) { anioCursado = a; }
int Alumno::getaniocursado() { return anioCursado; }
void Alumno::mostraralumno()
{
    cout << "Alumno: " << getnombre() << " | Legajo: " << getlegajo() << " | Año cursado: " << anioCursado << endl;
}

Profesor::Profesor() : Usuario() {}
Profesor::Profesor(string _nombre, int _legajo, string _area) : Usuario(_nombre, _legajo)
{
    area = _area;
}
void Profesor::setarea(string a) { area = a; }
string Profesor::getarea() { return area; }
void Profesor::mostrarprofesor()
{
    cout << "Profesor: " << getnombre() << " | Legajo: " << getlegajo() << " | Area: " << area << endl;
}

Libro::Libro()
{
    codigo = "";
    titulo = "";
    autor = "";
    anio = 0;
    categoria = "";
    prestado = false;
}
Libro::Libro(string _codigo, string _titulo, string _autor, int _anio, string _categoria)
{
    codigo = _codigo;
    titulo = _titulo;
    autor = _autor;
    anio = _anio;
    categoria = _categoria;
    prestado = false;
}
void Libro::setcodigo(string c) { codigo = c; }
string Libro::getcodigo() { return codigo; }

void Libro::settitulo(string t) { titulo = t; }
string Libro::gettitulo() { return titulo; }

void Libro::setautor(string a) { autor = a; }
string Libro::getautor() { return autor; }

void Libro::setanio(int an) { anio = an; }
int Libro::getanio() { return anio; }

void Libro::setcategoria(string cat) { categoria = cat; }
string Libro::getcategoria() { return categoria; }

void Libro::prestar() { prestado = true; }

void Libro::devolver() { prestado = false; }

void Libro::mostrarlibro()
{
    cout << "Libro:"
         << "Codigo:" << codigo
         << ", Titulo:" << titulo
         << ", Autor:" << autor
         << ", Anio:" << anio
         << ", Categoria:" << categoria
         << ", Prestado:" << (prestado ? "SI" : "NO")
         << " " << endl;
}


int main()
{

    Libro l1("00001", "Harry Potter", "J.K Rowling", 2012, "Fantasia");
    Libro l2("00002", "Fisica I", "Jorge Castillo", 1990, "Fisica");

    l1.mostrarlibro();
    l2.mostrarlibro();


    l1.prestar();
    cout << "Despues de prestar L1:" << endl;
    l1.mostrarlibro();

    
    l1.devolver();
    cout << "Despues de devolver L1:" << endl;
    l1.mostrarlibro();


    Alumno a1("Santiago Monti", 100, 1);
    Profesor p1("Victoria Marchesini", 200, "Matematicas");

    a1.mostraralumno();
    p1.mostrarprofesor();

    return 0;
}
