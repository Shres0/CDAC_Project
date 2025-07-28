#include <stdint.h>
#include "lcd.h"
#include "Rain.h"

int main(void) {
    DelayMs(20);
    LcdInit();
    Rain_Digital_Init();  //PA1 as input

    char* status;

    while (1) {
        if (Is_Raining()) {
            status = "Raining...";
        } else {
            status = "No Rain";
        }

        LcdPuts(LCD_LINE1, "Rain Detection");
        LcdPuts(LCD_LINE2, status);

        DelayMs(1000);  // Update every 1 sec
    }
}
