#include "global.h"
#include "pantalla.h"
#include "utilidad.h"
#include "bucle.h"

void main(void)
{
    configurarCaracteresEspanol();

    char cont[3];
    int continu = 0;

    do
    {
        opt = mostrarMenuInicio();

        switch (opt)
        {
            case 1:
                ejecutarBucleJuego();
                break;

            case 2:
                gotoxy(15, 28); cprintf("Salir?");
                gotoxy(15, 30); cprintf("SI:1NO:2 \n:");
                flushall(); gets(cont);
                continu = atoi(cont);
                clrscr();
                break;
        }
    }
    while (continu != 1);
}