#include <graphics.h>
#include <time.h>
#include <stdio.h>

int main(){

    int colore=1,x=128,y=128,i,raggio=0,maxx,maxy,coloreselezionato,pennello;
    initwindow(1920,1060);
    srand(time(NULL));
    maxx = getmaxx( );
    maxy = getmaxy( );
    setcolor(15);
    rectangle(1,1,1919,128);
    rectangle(1,1,256,1079);
    for(i=0;i<15;i++){
        line(x,0,x,y);
        x+=128;
    }
    x=128;
    for(i=0;i<16;i++){
        setfillstyle(1,colore);
        floodfill(x-2,y-3,15);
        colore++;
        x+=128;
    }
    setcolor(15);
    y=384;
    for(i=0;i<5;i++){
        line(0,y,256,y);
        y+=256;
    }
    x=128;
    y=256;
    for(i=0;i<3;i++){
        circle(x,y,raggio+=20);
        setfillstyle(1,15);
        floodfill(x,y,15);
        y+=256;
    }
    setfillstyle(1,15);
    bar(20,924,236,1020);

    //mouse
    while(true){
        while(ismouseclick(WM_LBUTTONDOWN)==false){
            delay(50);
        }
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if(y<128){
            coloreselezionato=(x/128)+1;
        }
        else if(x<256){
            i=(y-128)/256;
            pennello=(i+1)*20;
            if(i==3){
                pennello=20;
                coloreselezionato=0;
            }
        }
        else{
            clearmouseclick(WM_LBUTTONUP);
            do{
                if(x>256+pennello && y>128+pennello){
                    setcolor(coloreselezionato);
                    circle(x,y,pennello);
                    setfillstyle(1,coloreselezionato);
                    floodfill(x,y,coloreselezionato);
                }
                if(ismouseclick(WM_MOUSEMOVE)==true){
                    getmouseclick(WM_MOUSEMOVE,x,y);
                }
            }while(ismouseclick(WM_LBUTTONUP)==false);
        }
    }
}

