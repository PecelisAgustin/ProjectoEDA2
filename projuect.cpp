#include <iostream>
#include <tchar.h>

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
public:
    int matriz[NODOS_CANTIDAD][NODOS_CANTIDAD];
    Nodo nodos[NODOS_CANTIDAD];

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

    void setearValoresNodo(int a, int x, int y){
        nodos[a].x = x;
        nodos[a].y = y;

    }
};

int main()
{
    Grafo g;
    
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