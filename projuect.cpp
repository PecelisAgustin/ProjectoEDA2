#include <iostream>
#include <tchar.h>
#include <cstring>

using namespace std;

#define NODOS_CANTIDAD 8

struct Nodo
{
    int id;
    char nombre[50];
    int x;
    int y;
};

class Grafo
{
    int matriz[NODOS_CANTIDAD][NODOS_CANTIDAD];
    Nodo nodos[NODOS_CANTIDAD];
    public:

    Grafo()
    {
        for (int i = 0; i < NODOS_CANTIDAD; i++)
        {
            for (int j = 0; j < NODOS_CANTIDAD; j++)
            {
                if (i == j)
                {
                    matriz[i][j] = 0;
                }
                else
                {
                    matriz[i][j] = -1;
                }
            }
        }
    }

    void conectar(int a, int b, int distancia)
    {

        matriz[a][b] = distancia;
        matriz[b][a] = distancia;
    }

    void setearNodo(int id, const char nombre[], int x, int y)
    {
        nodos[id].id = id;

        strcpy(nodos[id].nombre, nombre);

        nodos[id].x = x;
        nodos[id].y = y;
    }

    void cortarORestaurarConexion(int a, int b)
    {
        matriz[a][b] = matriz[a][b] * -1;
        matriz[b][a] = matriz[b][a] * -1;
    }

    int verSiConexionActiva(int a, int b){
        if (matriz[a][b] == -1)
        {
            //No existe la conexion
            return -1;
        }
        else if(matriz[a][b] < -1)
        {
            //Conexion cortada temporalmente
            return 0;
        }
        else
        {
            //Conexion activa
            return 1;
        }
        
    }
};

int main()
{
    Grafo g;

    g.setearNodo(0, "Cordoba", 350, 120);
    g.setearNodo(1, "Villa Maria", 500, 280);
    g.setearNodo(2, "Rio Cuarto", 420, 500);
    g.setearNodo(3, "Carlos Paz", 250, 140);
    g.setearNodo(4, "San Francisco", 700, 80);
    g.setearNodo(5, "Bell Ville", 620, 260);
    g.setearNodo(6, "Alta Gracia", 300, 220);
    g.setearNodo(7, "Rio Tercero", 420, 320);

    // Córdoba ↔ Villa María
    g.conectar(0, 1, 140);

    // Córdoba ↔ Carlos Paz
    g.conectar(0, 3, 35);

    // Córdoba ↔ San Francisco
    g.conectar(0, 4, 210);

    // Córdoba ↔ Alta Gracia
    g.conectar(0, 6, 40);

    // Córdoba ↔ Río Tercero
    g.conectar(0, 7, 110);

    // Villa María ↔ Río Cuarto
    g.conectar(1, 2, 220);

    // Villa María ↔ San Francisco
    g.conectar(1, 4, 150);

    // Villa María ↔ Bell Ville
    g.conectar(1, 5, 65);

    // Villa María ↔ Río Tercero
    g.conectar(1, 7, 100);

    // Río Cuarto ↔ Carlos Paz
    g.conectar(2, 3, 190);

    // Río Cuarto ↔ Bell Ville
    g.conectar(2, 5, 180);

    // Río Cuarto ↔ Río Tercero
    g.conectar(2, 7, 140);

    // Carlos Paz ↔ Alta Gracia
    g.conectar(3, 6, 40);

    // San Francisco ↔ Bell Ville
    g.conectar(4, 5, 170);

    // Bell Ville ↔ Río Tercero
    g.conectar(5, 7, 120);

    // Alta Gracia ↔ Río Tercero
    g.conectar(6, 7, 90);

    return 0;
}
