#include "tela2.h"
#include "tela3.h"
#include "config.h"
#include "lcd.h"
#include "pic18f4520.h"
#include "ssd.h"
#include "io.h"
#include "keypad.h"
#include "bits.h"
void Tela2(void) {
    char i;
    char msg1[10] = "Forte (4)";
    char msg2[10] = "Medio (5)";
    char msg3[10] = "Fraco (6)";
    char time;
    unsigned char tecla;
    lcdCommand(0X80);
    for (i = 0; i < 9; i++) {
        lcdData(msg1[i]);
    }
    lcdCommand(0XC0);
    for (i = 0; i < 9; i++) {
        lcdData(msg2[i]);
    }
    lcdCommand(0X90);
    for (i = 0; i < 9; i++) {
        lcdData(msg3[i]);
    }
    
    for (;;) {
        ssdUpdate();
        kpDebounce();
        if (kpRead() != tecla) {
            tecla = kpRead();
            if (bitTst(kpRead(), 2)) {
                ssdDigit(4, 3);
                lcdCommand(0x01);
                Tela3();
            }
            if (bitTst(kpRead(), 6)) {
                ssdDigit(5, 3);
                lcdCommand(0x01);
                Tela3();
            }
            if (bitTst(kpRead(), 10)) {
                ssdDigit(6, 3);
                lcdCommand(0x01);
                Tela3();
            }
        }
        for (time = 0; time < 100; time++);
    }
}

