#include "pantalla.h"

void dibujarFondo(void)
{
    textbackground(BLACK); clrscr();

    for (col = ci; col < cf; col++)
    {
        gotoxy(col, ri); cprintf("Í");
        gotoxy(col, rf); cprintf("Í");
    }
    for (ren = ri; ren < rf; ren++)
    {
        gotoxy(ci, ren); cprintf("º");
        gotoxy(cf, ren); cprintf("º");
    }

    gotoxy(10, 10); cprintf("É");
    gotoxy(10, 30); cprintf("È");
    gotoxy(80, 10); cprintf("»");
    gotoxy(80, 30); cprintf("¼");

    gotoxy(32, 1); cprintf("AYUDA");
    gotoxy(13, 3); cprintf("Pulsar 1=Truco:Disminuir velocidad(puede utilizarlo una vez)");
    gotoxy(13, 4); cprintf("Pulsar 2=Truco:Aumentar velocidad (Bajo su propio riesgo!!!)");
    gotoxy(1, 10); cprintf("CONTROLES");
    gotoxy(1, 14); cprintf("=ARRIBA");
    gotoxy(1, 15); cprintf("=ABAJO");
    gotoxy(1, 16); cprintf(">=DELANTE");
    gotoxy(1, 17); cprintf("<=ATRAS");
    gotoxy(35, 9); cprintf("PIXSNAKE 2010");
    gotoxy(71, 22); cprintf("OBJETIVO:");
    gotoxy(71, 23); cprintf("TENER 220");
    gotoxy(72, 24); cprintf(" PUNTOS  ");
}

void crearAsteriscos(int n)
{
    int k, c = 0, r = 0, color = 0, pass = 1;
    randomize();
    for (k = 0; k < n; k++)
    {
        do
        {
            pass = 1;
            c = random(59) + 11;
            r = random(29) + 11;

            if ((r == 17 && (c >= 19 && c <= 60))
                || (r == 18 && (c >= 19 && c <= 60))
                || (r == 19 && (c >= 19 && c <= 60))
                || (r == 20 && (c >= 19 && c <= 60))
                || (r == 21 && (c >= 35 && c <= 44))
                || (r == 21 && (c >= 35 && c <= 44))
                || (r == 22 && (c >= 35 && c <= 44))
                || (r == 23 && (c >= 35 && c <= 44))
                || (r == 24 && (c >= 35 && c <= 44))
                || (r == 25 && (c >= 35 && c <= 44))
                || (r == 26 && (c >= 35 && c <= 44))
                || (r == 27 && (c >= 35 && c <= 44))
                || (r == 28 && (c >= 35 && c <= 44)))
            {
                pass = 0;
            }
        }
        while (pass == 0);

        color = random(13) + 2;
        gotoxy(c, r); textcolor(color);
        cprintf("*");
        m[r - 1][c - 1] = color;
    }
}

void mostrarInformacionDinamica(void)
{
    textcolor(WHITE); gotoxy(15, 48); cprintf("Nivel:%d", nivel);
    textcolor(WHITE); gotoxy(33, 48); cprintf("Puntuaci%cn:%d ", 162, band);
    textcolor(WHITE); gettime(&t); gotoxy(55, 48); cprintf("Tiempo:  %2d:%2d:%2d:%2d", t.ti_hour, t.ti_min, t.ti_sec, t.ti_hund);
}

void mostrarPantallaFinal(void)
{
    char dummy[5];

    if (limite < 10)
    {
        clrscr();
        _setcursortype(_NOCURSOR);
        gotoxy(10, 5); cprintf("SE TE ACABO LA VIDA!!!");
        gotoxy(10, 10); cprintf("MAXIMO PUNTAJE:%d", band); delay(1500);
        gotoxy(15, 30); cprintf("Pulse ENTER para continuar!"); flushall(); gets(dummy);
    }
    else
    {
        if (band == 220)
        {
            clrscr();
            _setcursortype(_NOCURSOR);
            gotoxy(10, 5); cprintf("FELICITACIONES GANASTE!!!");
            gotoxy(10, 10); cprintf("MAXIMO PUNTAJE:%d", band); delay(1500);
            gotoxy(15, 30); cprintf("Pulse ENTER para continuar!"); flushall(); gets(dummy);
        }
        else
        {
            if (op == 27 && gameover == 0 && canibal == 0)
            {
                clrscr();
                _setcursortype(_NOCURSOR);
                gotoxy(10, 5); cprintf("USTED SALIO DEL JUEGO :(");
                gotoxy(10, 10); cprintf("MAXIMO PUNTAJE:%d", band); delay(1500);
                gotoxy(15, 30); cprintf("Pulse ENTER para continuar!"); flushall(); gets(dummy);
            }
            else
            {
                clrscr();
                _setcursortype(_NOCURSOR);
                gotoxy(10, 5); cprintf("GAME OVER TOCASTE PARTES INDEVIDAS XD!!!");
                gotoxy(10, 10); cprintf("MAXIMO PUNTAJE:%d", band); delay(1500);
                gotoxy(15, 30); cprintf("Pulse ENTER para continuar!"); flushall(); gets(dummy);
                canibal = 0;
            }
        }
    }
}

int mostrarMenuInicio(void)
{
    char opi[2];
    int xx = 1, opti = 0;
    do
    {
        clrscr();
        cprintf("Selecciona opci%cn\n1.-Juego Nuevo\n2.-Salir\n", 162);

        do
        {
            gotoxy(xx, 5); printf("---****---*****--*----*-..######..##....##....###....##....##.########"); delay(4);
            gotoxy(xx, 6); printf("---*---*----*-----*--*--.##....##.###...##...##.##...##...##..##......"); delay(4);
            gotoxy(xx, 7); printf("---*---*----*------**---.##.......####..##..##...##..##..##...##......"); delay(4);
            gotoxy(xx, 8); printf("---****-----*------**---..######..##.##.##.##.....##.#####....######.."); delay(4);
            gotoxy(xx, 9); printf("---*--------*-----*--*--.......##.##..####.#########.##..##...##......"); delay(4);
            gotoxy(xx, 10); printf("---*--------*----*----*-.##....##.##...###.##.....##.##...##..##......"); delay(4);
            gotoxy(xx, 11); printf("---*------*****-*------*..######..##....##.##.....##.##....##.########"); delay(4);

            xx++;
        }
        while (xx < 81);

        gotoxy(1, 55); cprintf("RIVERJUEGOS-->:");
        xx = 1;
        flushall(); gets(opi);
        opti = atoi(opi);
    }
    while (opti == 0);

    return opti;
}

void mostrarPuertaCerrada(void)
{
    gotoxy(18, 7); printf(" ========================================== ");
    gotoxy(18, 8); printf("|x x x x x x     Bienvenido!   x x x x x x |");
    gotoxy(18, 9); printf("| '   ï   .                     u   +   3  |");
    gotoxy(18, 10); printf(" ================          ================ ");
    gotoxy(35, 11); printf("|        |");
    gotoxy(35, 12); printf("|        |");
    gotoxy(35, 13); printf("|        |");
    gotoxy(35, 14); printf("|        |");
    gotoxy(35, 15); printf("| Puerta |");
    gotoxy(35, 16); printf("|   ||   |");
    gotoxy(35, 17); printf("|   VV   |");
    gotoxy(35, 18); printf(" -------- ");
}

void mostrarPuertaAbierta(void)
{
    gotoxy(18, 7); printf(" ========================================== ");
    gotoxy(18, 8); printf("|x x x x x x     Bienvenido!   x x x x x x |");
    gotoxy(18, 9); printf("| '   ï   .                     u   +   3  |");
    gotoxy(18, 10); printf(" ================          ================ ");
    gotoxy(35, 11); printf("|        |");
    gotoxy(35, 12); printf("|        |");
    gotoxy(35, 13); printf("|        |");
    gotoxy(35, 14); printf("|        |");
    gotoxy(35, 15); printf("|Abierto!|");
    gotoxy(35, 16); printf("|        |");
    gotoxy(35, 17); printf("|        |");
    gotoxy(35, 18); printf("1        1");
    gotoxy(35, 19); printf("1        1");
    gotoxy(35, 20); printf("1        1");
    gotoxy(35, 21); printf("1        1");
    gotoxy(35, 22); printf("1        1");
    gotoxy(35, 23); printf("1        1");
    gotoxy(35, 24); printf("1        1");
}

void mostrarPuertaLateral(void)
{
    gotoxy(18, 7); printf(" ========================================== ");
    gotoxy(18, 8); printf("|x x x x x xCuidado con la puerta! x x x x |");
    gotoxy(18, 9); printf("| '   ï   .                         +   3  |");
    gotoxy(18, 10); printf(" ================          ================ ");
    gotoxy(35, 11); printf("|        |");
    gotoxy(35, 12); printf("|        |");
    gotoxy(35, 13); printf("|        |");
    gotoxy(35, 14); printf("|        |");
    gotoxy(35, 15); printf("|        |");
    gotoxy(35, 16); printf("|        |");
    gotoxy(35, 17); printf("|CERRADO!|");
    gotoxy(35, 18); printf(" -------- ");
    gotoxy(35, 19); printf("(        )");
    gotoxy(35, 20); printf("( TUNEL  )");
    gotoxy(35, 21); printf("(        )");
    gotoxy(35, 22); printf("(        )");
    gotoxy(35, 23); printf("(        )");
    gotoxy(35, 24); printf("(        )");
    gotoxy(35, 25); printf("(        )");
}