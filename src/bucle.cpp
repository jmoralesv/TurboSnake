#include "bucle.h"
#include "serpiente.h"
#include "pantalla.h"
#include "juego.h"

void ejecutarBucleJuego(void)
{
    int pa = 0, pc = 0;

    gettime(&t);
    t.ti_sec = 0; t.ti_hour = 0; t.ti_min = 0; t.ti_hund = 0;
    settime(&t);
    _setcursortype(_NOCURSOR);

    inicializarMatriz();
    dibujarFondo();
    crearAsteriscos(18);

    do
    {
        limite--;
        actualizarNivel();
        crearSerpiente();

        if (sy < 18 && pc == 0)
        {
            mostrarPuertaCerrada();
        }

        if (sy == 19 && pa == 0)
        {
            mostrarPuertaAbierta();
        }

        if (sy == 25 || pa == 1)
        {
            mostrarPuertaLateral();
            pa = 1; pc = 1;
        }

        procesarColisiones();

        gotoxy(princi->x, princi->y); cprintf("@");
        delay((200 - velocidad) + truco);
        gotoxy(cola->x, cola->y); cprintf(" ");
        a = a + 1;

        if (verificarAutocanibalismo())
        {
            op = 27;
            canibal = 1;
        }

        mostrarInformacionDinamica();
        manejarMovimiento();

        gotoxy(0, 0); cprintf("VIDA RESTANTE:%d ", limite);
        if (limite < 1)
        {
            op = 27;
        }
    }
    while (op != esc);

    if (op == esc)
    {
        mostrarPantallaFinal();
    }

    reiniciarVariables();
    limpiarSerpiente();
    clrscr();
}