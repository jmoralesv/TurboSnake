#ifndef GLOBAL_H
#define GLOBAL_H

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>

#define up 72
#define down 80
#define left 75
#define right 77
#define esc 27

// Variables globales del juego
extern int m[50][80];
extern int cantidad;
extern int opt;
extern int i, j, col, ren;
extern int sx, sy;
extern int a, ax;
extern int velocidad;
extern int truco;
extern int gameover;
extern int nivel;
extern int ci, ri, rf, cf;
extern int op, op2;
extern int y1, x1;
extern int band;
extern int limite;
extern int canibal;

extern struct time t;

// Estructura de la serpiente
typedef struct cuerpo
{
    int x;
    int y;
    struct cuerpo* sig;
    struct cuerpo* ant;
} body;

typedef body* snake;

// Punteros globales de la serpiente
extern snake cabeza;
extern snake princi;
extern snake cola;
extern snake temp;
extern snake aux;

#endif