#include "config.h"
#include "lcd.h"
#include "pic18f4520.h"
#include "ssd.h"
#include "io.h"
#include "keypad.h"
#include "bits.h"
#include "tela1.h"

//inicio do programa
void main(void) {

    char i, j;
    char msg1[16] = "Maquina de Cafe";
    char msg2[3] = "(0)";
    char time;
    unsigned char tecla;
    lcdInit();
    lcdCommand(0X80);
    for (i = 0; i < 15; i++) {
        lcdData(msg1[i]);
    }
    lcdCommand(0XC0);
    for (i = 0; i < 4; i++) {
        lcdData(msg2[i]);
    }
    kpInit();
    ssdInit();
    for (;;) {
        kpDebounce();
        if (kpRead() != tecla) {
            tecla = kpRead();
            if (bitTst(kpRead(), 4)) {
                ssdDigit(0, 3);
                lcdCommand(0x01);
                Tela1();
            }
        }
        for (time = 0; time < 100; time++);
        lcdCommand(0x40);
        char logo1[32] = {
            0x01, 0x03, 0x03, 0x07, 0x07, 0x0F, 0x0F, 0x1F,
            0x10, 0x18, 0x18, 0x1C, 0x1C, 0x1E, 0x1E, 0x1F,
            0x0F, 0x0F, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00,
            0x1E, 0x1E, 0x1C, 0x18, 0x00, 0x00, 0x00, 0x00
        };

        for (i = 0; i < 32; i++)
            lcdData(logo1[i]);
        lcdCommand(0x90);
        lcdData(0);
        lcdData(1);
        lcdCommand(0xD0);
        lcdData(2);
        lcdData(3);
    }

}

