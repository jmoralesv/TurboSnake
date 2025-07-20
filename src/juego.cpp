#include "juego.h"
#include "serpiente.h"
#include "pantalla.h"

void inicializarMatriz(void)
{
    for (i = 0; i < 50; i++)
    {
        for (j = 0; j < 80; j++)
        {
            m[i][j] = 0;
        }
    }
}

void reiniciarVariables(void)
{
    cantidad = 0; opt = 0; i = 0; j = 0; a = 0; col = 0; ren = 0; 
    velocidad = 0; truco = 0; gameover = 0; nivel = 1; 
    ci = 10; ri = 10; rf = 40; cf = 70; sy = 18; sx = 40; 
    op = 0; op2 = 0; y1 = 0; x1 = 0; band = 0; limite = 100;
}

void actualizarNivel(void)
{
    if (band == 10)
    {
        band = band + 50; 
        gotoxy(23, 7); textcolor(WHITE + BLINK); 
        cprintf("Bienvenido al segundo nivel!"); 
        gotoxy(32, 6); clreol();
        crearAsteriscos(cantidad + 16); 
        velocidad = 10;
        nivel = 2;
    }
    if (band == 75)
    {
        band = band + 50; 
        gotoxy(23, 7); textcolor(WHITE + BLINK); 
        cprintf("Bienvenido al tercel nivel!"); 
        gotoxy(32, 6); clreol();
        crearAsteriscos(cantidad + 20); 
        velocidad = 40;
        nivel = 3;
    }
    if (band == 145)
    {
        band = band + 50; 
        gotoxy(23, 7); textcolor(WHITE + BLINK); 
        cprintf("Tu puedes! ultimo nivel :D"); 
        gotoxy(32, 6); clreol();
        crearAsteriscos(cantidad + 100); 
        velocidad = 70;
        nivel = 4;
    }
    if (band == 220)
    {
        op = 27;
    }
}

void procesarColisiones(void)
{
    if (m[sy - 1][sx - 1] != 0)
    {
        textcolor(m[sy - 1][sx - 1]);
        m[sy - 1][sx - 1] = 0; 
        limite = limite + 85;
        band++;
    }
    else
    {
        if (a != 0)
        {
            cola = temp->sig;
            cola->ant = temp->ant;
            free(temp);
            temp = cola;
        }
    }
}

void manejarMovimiento(void)
{
    if (kbhit())
        op = getch();

    switch (op)
    {
        case up:
            if (sy > ri) { sy--; cabeza->y = sy; }
            else { gameover = 1; op = 27; }
            break;
        case down:
            if (sy < rf) { sy++; cabeza->y = sy; }
            else { gameover = 1; op = 27; }
            break;
        case left:
            if (sx > ci) { sx--; cabeza->x = sx; }
            else { gameover = 1; op = 27; }
            break;
        case right:
            if (sx < cf) { sx++; cabeza->x = sx; }
            else { gameover = 1; op = 27; }
            break;
        case '1':
            if (truco == 0) { truco = 120; }
            op = 0;
            break;
        case '2':
            velocidad = velocidad + 20;
            op = 0;
            break;
    }
}