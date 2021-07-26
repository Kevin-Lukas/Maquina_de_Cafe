#include "tela3.h"
#include "config.h"
#include "lcd.h"
#include "pic18f4520.h"
#include "ssd.h"
#include "io.h"
#include "keypad.h"
#include "bits.h"
#include "pwm.h"
void tempo(unsigned char v) {
    //este código gera um delay
    volatile unsigned char j, k, i, l;

    for (l = 0; l < v; l++) {
        for (i = 0; i < 40; i++) {
            for (j = 0; j < 41; j++) {
                for (k = 0; k < 3; k++);
            }
            ssdUpdate();
        }
        ssdUpdate();
    }
}

void Tela3(void) {
    TRISD = 0x00;
    unsigned char i, j;
    char tecla;
    char msg1[11] = "Fazendo...";
    char msg2[14] = "Pedido Pronto";

    lcdCommand(0x01);
    lcdCommand(0X80);
    for (i = 0; i < 10; i++) {
        lcdData(msg1[i]);
    }
    pwmInit();
    pwmSet1(99);
    tempo(20000 / 100);
    tempo(20000 / 100);
    pwmSet1(0);
    for (;;) {
        ssdUpdate();
        lcdCommand(0XC0);
        for (i = 0; i < 13; i++) {
            lcdData(msg2[i]);
        }
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
