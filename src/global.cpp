#include "global.h"

// Definición de variables globales
int m[50][80];
int cantidad = 0;
int opt = 0;
int i, j, col, ren;
int sx = 40, sy = 9;
int a = 0, ax = 0;
int velocidad = 0;
int truco = 0;
int gameover = 0;
int nivel = 1;
int ci = 1, ri = 1, rf = 30, cf = 80;
int op = 0, op2 = 0;
int y1 = 0, x1 = 0;
int band = 0;
int limite = 100;
int canibal = 0;

struct time t;

// Punteros globales de la serpiente
snake cabeza;
snake princi = NULL;
snake cola = NULL;
snake temp = NULL;
snake aux = NULL;