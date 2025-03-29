#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <WinUser.h>
#define jmp goto
unsigned char b;
char*c;
int main() {
long e=3;
FILE* d = fopen("cfg.ini", "r");
c=(char*)malloc(64);
int interval;
POINT f={645,930};
POINT g;
update:
#pragma warning(suppress : 4996)
while(fscanf(d,"%s",c)){
#pragma warning(suppress : 4996)
if((--e)==0)sscanf(c,"%d",&(interval));
if(*c=='0')break;
}
l1:
if(GetAsyncKeyState(0x73)&&0x8000){b=1;printf("script toggled\n");Sleep(100);GetCursorPos(&g);jmp update;}
else if(GetAsyncKeyState(0x11)&&0x8000){b=0;printf("script stopped\n");Sleep(100);}
else if(GetAsyncKeyState(0x78)&&0x8000){if(GetCursorPos(&f))printf("(%d,%d)",f.x,f.y);}
else if(GetAsyncKeyState(0x79)&&0x8000){mouse_event(0x8001,22032,56500,0,0);}
if(b){
mouse_event(0x8001,22032,56500,0,0);
Sleep(10);
mouse_event(0x2,0,0,0,0);
Sleep(10);
mouse_event(0x4,0,0,0,0);
Sleep(100);
mouse_event(0x8001,(int)(35.15883*g.x),(int)(60.75334*g.y), 0, 0);
Sleep(10);
mouse_event(0x2,0,0,0,0);
Sleep(10);
mouse_event(0x4,0,0,0,0);
Sleep(interval);
}
if(GetKeyState(0x75)&&0x8000){printf("script quitted");return 0;}
Sleep(10);
jmp l1;
}