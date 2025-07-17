#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include "game.h"

void configurarCaracteresEspanol(void);

int main()
{
    configurarCaracteresEspanol();
    startGame();
    return 0;
}

void configurarCaracteresEspanol(void)
{
    union REGS regs;
    regs.h.ah = 0x10;
    regs.h.al = 0;
    regs.h.bh = 0;
    regs.h.bl = 2;  // Load ROM 8x16 font
    int86(0x10, &regs, &regs);

    // Set code page to 850 which DOS uses for Western European languages
    system("chcp 850");
}