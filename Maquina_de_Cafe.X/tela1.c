#include "tela1.h"
#include "tela2.h"
#include "config.h"
#include "lcd.h"
#include "pic18f4520.h"
#include "ssd.h"
#include "io.h"
#include "keypad.h"
#include "bits.h"

void Tela1(void) {
    char i;
    char msg1[9] = "Cafe (1)";
    char msg2[14] = "Capuccino (2)";
    char time;
    unsigned char tecla;

    lcdCommand(0X80);
    for (i = 0; i < 8; i++) {
        lcdData(msg1[i]);
    }
    lcdCommand(0XC0);
    for (i = 0; i < 13; i++) {
        lcdData(msg2[i]);
    }

    for (;;) {
        ssdUpdate();
        kpDebounce();
        if (kpRead() != tecla) {
            tecla = kpRead();
            if (bitTst(kpRead(), 3)) {
                ssdDigit(1, 3);
                lcdCommand(0x01);
                Tela2();
            }
            if (bitTst(kpRead(), 7)) {
                ssdDigit(2, 3);
                lcdCommand(0x01);
                Tela2();
            }
        }

    }

}



