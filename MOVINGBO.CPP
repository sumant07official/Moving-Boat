//___________________ C++ PROGRAM TO MOVING BOAT _________________________//

#include <conio.h>

#include <stdio.h>

#include <graphics.h>

#include <math.h>

#include <stdlib.h>

#include <dos.h>

int gd = DETECT, gm, xmax, ymax, x, y, tx, ty;

void drawBoat()

{

    static int t = 0;

    line(x, y, x + 200, y);

    line(x, y, x + 20, y + 60);

    line(x + 20, y + 60, x + 180, y + 60);

    line(x + 180, y + 60, x + 200, y);

    line(x + 150, y, x + 150, y - 35);

    setfillstyle(SOLID_FILL, WHITE);

    fillellipse(x + 150, y - 50, 15, 15);

    setfillstyle(SOLID_FILL, YELLOW);

    fillellipse(x + 150, y - 60, 35, 3);

    fillellipse(x + 150, y - 65, 10, 10);

    setfillstyle(SOLID_FILL, RED);

    floodfill(x + 40, y + 20, WHITE);

    if (t < 1)

    {

        line(x + 150, y - 25, x + 130, y - 15);

        line(x + 130, y - 15, x + 110, y - 19);

        line(x + 150, y - 25, x + 107, y - 25);

        line(x + 107, y - 25, x + 110, y - 10);

        line(x + 115, y - 10, x + 108, y - 10);

        line(x + 115, y - 10, x + 135, y + 60);

        line(x + 108, y - 10, x + 128, y + 60);

        line(x + 135, y + 60, x + 128, y + 60);
    }

    else

    {

        line(x + 150, y - 25, x + 135, y - 20);

        line(x + 140, y - 20, x + 120, y - 10);

        line(x + 150, y - 25, x + 120, y - 20);

        line(x + 120, y - 20, x + 130, y - 5);

        line(x + 123, y - 5, x + 118, y - 5);

        line(x + 118, y - 5, x + 150, y + 60);

        line(x + 123, y - 5, x + 158, y + 60);

        line(x + 123, y + 60, x + 158, y + 60);
    }

    t = (t + 1) % 4;
}

void drawWave()

{

    static int waveh = 10, hdiff = 0, phasediff = 10;

    tx = 0;

    ty = y + 40;

    for (; tx < xmax * 3; tx += 3)

    {

        putpixel(tx / 3, (ty + hdiff) + waveh * sin((tx + phasediff) * 3.14f / 180), 3);
    }

    hdiff = (hdiff + 2) % 4;

    phasediff = (phasediff + 20) % 70;

    setfillstyle(SOLID_FILL, 3);

    floodfill(xmax - 1, ymax - 2, 3);
}

void rain()

{

    int i, rx, ry;

    setcolor(WHITE);

    for (i = 0; i < 1000; i++)

    {

        rx = random(xmax);

        ry = random(ymax);

        if (ry < y + 40)

        {

            if ((ry > y + 10 || ry < y - 77))

                line(rx, ry, rx + 2, ry + 2);

            else if ((rx < x + 90 || rx > x + 180))

            {

                line(rx, ry, rx + 2, ry + 2);
            }
        }
    }
}

void main()

{

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    cleardevice();

    xmax = getmaxx();

    ymax = getmaxy();

    x = 250;

    y = ymax - 150;

    while (!kbhit())

    {

        x -= 8;

        drawBoat();

        drawWave();

        rain();

        delay(300);

        cleardevice();
    }

    getch();
}
