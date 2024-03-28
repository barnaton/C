#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int a, b, c, y, x;
    printf("Inserisci valore a: ");
    scanf("%d", &a);
    printf("Inserisci valore b: ");
    scanf("%d", &b);
    printf("Inserisci valore c: ");
    scanf("%d", &c);

    initwindow(640, 480);
    setcolor(15);
    line(320, 0, 320, 480);
    line(0, 240, 640, 240);

    int centralex = 320;
    int centraley = 240;

    for (x = -20; x < 20; x++) {
        y = a * pow(x, 2) + b * x + c;
        line(x + centralex, -y + centraley, x + centralex + 1, -y + centraley + 1);
    }

    delay(100000);
}
