#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include "game.h"

void configurarCaracteresEspanol()
{
    union REGS regs;
    regs.h.ah = 0x10;
    regs.h.al = 0;
    regs.h.bh = 0;
    regs.h.bl = 2;  // Load ROM 8x16 font
    int86(0x10, &regs, &regs);

    // Set code page to 850
    system("chcp 850");
}

int main(void)
{
    configurarCaracteresEspanol();
    startGame();

    cprintf("Hola a%co 2025!", 164);  // prints "Hola año 2025!"
    cprintf("\nMurci%clago", 130); // prints "Murciélago"
    return 0;
}