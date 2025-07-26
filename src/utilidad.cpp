#include "utilidad.h"

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