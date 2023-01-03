#include<graphics.h>
#include<conio.h>
#include<dos.h>
void set();
void tec(char);
void tac(char);
int gameOver();
int move=1;
int box1=0,box2=0,box3=0,box4=0,box5=0,box6=0,box7=0,box8=0,box9=0;
int g1,g2,g3,g4,g5,g6,g7,g8,g9,b1,b2,b3,b4,b5,b6,b7,b8,b9;

int main()
{
   int gd=0,gm,draw,i=1,u=150;
   char ch,choice;
   initgraph(&gd,&gm,"C:\\TC\\BGI");
   top:
   cleardevice();
   box1=0;box2=0;box3=0;box4=0;box5=0;box6=0;box7=0;box8=0;box9=0;
   g1=0;g2=0;g3=0;g4=0;g5=0;g6=0;g7=0;g8=0;g9=0;b1=0;b2=0;b3=0;b4=0;b5=0;b6=0;b7=0;b8=0;b9=0;
  // setbkcolor(8);

   while(1)
   {
   settextstyle(1,0,4);
   setcolor(LIGHTRED);
   outtextxy(80,50,"WELCOME TO TIC TAC TOE GAME");
   setfillstyle(1,YELLOW);
   bar(180,100,440,350);
   setfillstyle(1,RED);
   bar(220,u,400,u+50);
   settextstyle(0,0,3);
   setcolor(GREEN);
   outtextxy(250,165,"START");
   outtextxy(227,223,"SETTING");
   outtextxy(265,285,"HELP");
	switch(getch())
	{
	  case 'U':u-=60;break;
	  case 'D':u+=60;break;
	  case 'O': if(u==150)goto start;
		    if(u==210)goto setting;
		    if(u==270)goto help;
	  case 'E':goto end;
	  default:break;
	}
      cleardevice();
      if(u<150)u=270;
      if(u>270)u=150;
   }
   start:
   cleardevice();
   while(1)
   {
     draw=gameOver();
     if(gameOver()==1||gameOver()==2)
     goto win;
     if(gameOver()==0&&box1==1&&box2==2&&box3==3&&box4==4&&box5==5&&box6==6&&box7==7&&box8==8&&box9==9)
     goto over;
     set();
     if(kbhit())
     {
      ch=getch();
      if(ch=='E')goto again;
      else
      tac(ch);
     }
   }
   win:
   if(gameOver()==1)
   {
      delay(2000);
      setcolor(RED);
      cleardevice();
      settextstyle(4,0,7);
      outtextxy(40,200,"RED CIRCLE WIN");
   }
   else if(gameOver()==2)
   {
      delay(2000);
      setcolor(GREEN);
      cleardevice();
      settextstyle(4,0,6);
      outtextxy(50,200,"GREEN CIRCLE WIN");
   }
   over:
   if(draw==0&&box1==1&&box2==2&&box3==3&&box4==4&&box5==5&&box6==6&&box7==7&&box8==8&&box9==9)
   {
      delay(2000);
      setcolor(YELLOW);
      cleardevice();
      settextstyle(4,0,7);
      outtextxy(70,200,"MATCH DRAW");
   }
   settextstyle(0,0,2);
   outtextxy(200,300,"PRESS ANY KEY");
   getch();
   again:
   while(i)
   {
     cleardevice();
     setcolor(YELLOW);
     settextstyle(0,0,2);
     if(i%5==0)
     {
     outtextxy(60,250,"IF YOU WANT TO PLAY AGAIN ENTER 1");
     outtextxy(190,280,"IF NOT PRESS E");
     }
     if(kbhit())
     {
	choice=getch();
	switch(choice)
	{
	   case '1':goto top;
	   case 'E':goto end;
	   default:break;
	}
     }
     delay(130);i++;
   }
   setting:
  if(u==210)
   {
     cleardevice();
     while(1)
     {
       settextstyle(0,0,3);
       setcolor(RED);
       outtextxy(130,200,"FOR RED PRESS R");
       setcolor(GREEN);
       outtextxy(110,300,"FOR GREEN PRESS G");
       if(kbhit())
       {
	  switch(getch())
	  {
	     case 'R':move=1;goto top;
	     case 'G':move=2;goto top;
	     case 'M':goto top;
	     default: break;
	  }
       }
       delay(100);
     }
   }

   help:
   if(u==270)
   {
      cleardevice();
      while(1)
      {
	settextstyle(0,0,2);
	setcolor(RED);
	outtextxy(100,100,"M = MAIN MENU       E = EXIT");
	outtextxy(100,130,"U = UP              D = DOWN");
	outtextxy(100,160,"R = RED             G = GREEN");
	outtextxy(100,190,"O = OK  ");
	outtextxy(100,230,"READ THE INSTRACTION CAREFULLY");
	if(kbhit())
	{
	   if(getch()=='M')goto top;
	}
	delay(100);
      }
   }
   end:
   getch();
   closegraph();
   return 0;
}
void set()
{
   setlinestyle(0,0,3);
   setcolor(YELLOW);
   line(250,100,250,400);
   line(375,100,375,400);
   line(130,200,480,200);
   line(130,300,480,300);
   settextstyle(0,0,0);
   outtextxy(190,160,"1");
   outtextxy(310,160,"2");
   outtextxy(430,160,"3");
   outtextxy(190,250,"4");
   outtextxy(310,250,"5");
   outtextxy(430,250,"6");
   outtextxy(190,350,"7");
   outtextxy(310,350,"8");
   outtextxy(430,350,"9");

   //circle(190,160,30);
 //  rectangle(100,100,190,350);
}
void tac(char ch)
{
  setlinestyle(1,0,3);
    if(move==1)
    {
       setcolor(RED);
       switch(ch)
       {
	  case '1':if(box1)break;move=2;circle(190,160,30);box1=1;g1=1;break;
	  case '2':if(box2)break;move=2;circle(310,160,30);box2=2;g2=2;break;
	  case '3':if(box3)break;move=2;circle(430,160,30);box3=3;g3=3;break;
	  case '4':if(box4)break;move=2;circle(190,250,30);box4=4;g4=4;break;
	  case '5':if(box5)break;move=2;circle(310,250,30);box5=5;g5=5;break;
	  case '6':if(box6)break;move=2;circle(430,250,30);box6=6;g6=6;break;
	  case '7':if(box7)break;move=2;circle(190,350,30);box7=7;g7=7;break;
	  case '8':if(box8)break;move=2;circle(310,350,30);box8=8;g8=8;break;
	  case '9':if(box9)break;move=2;circle(430,350,30);box9=9;g9=9;break;
	  default:break;
       }
	 ch='0';
    }
    if(move==2)
    {
       setcolor(GREEN);
       switch(ch)
       {
	  case '1':if(box1)break;move=1;circle(190,160,30);box1=1;b1=1;break;
	  case '2':if(box2)break;move=1;circle(310,160,30);box2=2;b2=2;break;
	  case '3':if(box3)break;move=1;circle(430,160,30);box3=3;b3=3;break;
	  case '4':if(box4)break;move=1;circle(190,250,30);box4=4;b4=4;break;
	  case '5':if(box5)break;move=1;circle(310,250,30);box5=5;b5=5;break;
	  case '6':if(box6)break;move=1;circle(430,250,30);box6=6;b6=6;break;
	  case '7':if(box7)break;move=1;circle(190,350,30);box7=7;b7=7;break;
	  case '8':if(box8)break;move=1;circle(310,350,30);box8=8;b8=8;break;
	  case '9':if(box9)break;move=1;circle(430,350,30);box9=9;b9=9;break;
	  default:break;
       }
       ch='0';
    }
}
int gameOver()
{
   setlinestyle(0,0,3);
   setcolor(MAGENTA);
   if(g1==1&&g2==2&&g3==3)
   {
      moveto(190,160);
      lineto(310,160);
      lineto(430,160);
      return 1;
   }
   else if(g1==1&&g5==5&&g9==9)
   {
      moveto(190,160);
      lineto(310,250);
      lineto(430,350);
      return 1;
   }
   else if(g1==1&&g4==4&&g7==7)
   {
      moveto(190,160);
      lineto(190,250);
      lineto(190,350);
      return 1;
   }
   else if(g4==4&&g5==5&&g6==6)
   {
      moveto(190,250);
      lineto(310,250);
      lineto(430,250);
      return 1;
   }
   else if(g7==7&&g8==8&&g9==9)
   {
      moveto(190,350);
      lineto(310,350);
      lineto(430,350);
      return 1;
   }
   else if(g2==2&&g5==5&&g8==8)
   {
      moveto(310,160);
      lineto(310,250);
      lineto(310,350);
      return 1;
   }
   else if(g3==3&&g6==6&&g9==9)
   {
      moveto(430,160);
      lineto(430,250);
      lineto(430,350);
      return 1;
   }
   else if(g3==3&&g5==5&&g7==7)
   {
      moveto(430,160);
      lineto(310,250);
      lineto(190,350);
      return 1;
   }
   else if(b1==1&&b2==2&&b3==3)
   {
      moveto(190,160);
      lineto(310,160);
      lineto(430,160);
      return 2;
   }
   else if(b1==1&&b5==5&&b9==9)
   {
      moveto(190,160);
      lineto(310,250);
      lineto(430,350);
      return 2;
   }
   else if(b1==1&&b4==4&&b7==7)
   {
      moveto(190,160);
      lineto(190,250);
      lineto(190,350);
      return 2;
   }
   else if(b4==4&&b5==5&&b6==6)
   {
      moveto(190,250);
      lineto(310,250);
      lineto(430,250);
      return 2;
   }
   else if(b7==7&&b8==8&&b9==9)
   {
      moveto(190,350);
      lineto(310,350);
      lineto(430,350);
      return 2;
   }
   else if(b2==2&&b5==5&&b8==8)
   {
      moveto(310,160);
      lineto(310,250);
      lineto(310,350);
      return 2;
   }
   else if(b3==3&&b6==6&&b9==9)
   {
      moveto(430,160);
      lineto(430,250);
      lineto(430,350);
      return 2;
   }
   else if(b3==3&&b5==5&&b7==7)
   {
      moveto(430,160);
      lineto(310,250);
      lineto(190,350);
      return 2;
   }
   else return 0;
}
