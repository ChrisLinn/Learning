#include "windows.h"
#include "stdio.h"
LRESULT CALLBACK WndProc(HWND hwnd,UINT message,
						 WPARAM wParam,LPARAM lParam);
int WhatCusor(int x,int y);
int WINAPI WinMain (HINSTANCE hThisInst, HINSTANCE hPrevInst,
					LPSTR lpszCmdLine,  int nCmdShow)
{
	WNDCLASS ws;
	HWND hWnd;
	MSG msg;
	ws.style = 0;
	ws.lpfnWndProc = WndProc;
	ws.cbClsExtra = 0;
	ws.cbWndExtra = 0;
	ws.hInstance = hThisInst;
	ws.hIcon = LoadIcon(NULL, IDI_HAND);
	ws.hCursor = LoadCursor(NULL,IDC_CROSS);
	ws.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
	ws.lpszMenuName = NULL;
	ws.lpszClassName = "DemoClass";
	if(!RegisterClass(&ws))
	{
		return -1;
	}
	hWnd = CreateWindow("DemoClass","My First Windows Program",
		WS_OVERLAPPEDWINDOW,100,200,640,480,
		NULL,NULL,hThisInst,NULL);
	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hwnd,UINT message,
		                 WPARAM wParam,LPARAM lParam)
{
	HDC   hdc ;       
	PAINTSTRUCT  ps ;
	HPEN  hPen;
	static int flag = 0;
	char str[20];
	POINT cur;
	POINT pt[20] = {	50 ,50,
						580,50,
						580,400,
						50 ,400,
						50 ,50,
				 (50+580)/2,50,
				 (50+580)/2,400,
						50 ,400,
						50 ,(50+400)/2,
						580 ,(50+400)/2};



	switch(message)
	{
	case   WM_PAINT:        
		hdc = BeginPaint (hwnd, &ps) ;
		hPen=GetStockObject(BLACK_PEN);		
		SelectObject(hdc,hPen);			
		Polyline(hdc,pt,10);		
		DeleteObject(hPen);
		EndPaint (hwnd, &ps) ;       
		return 0 ;			
	
	case WM_KEYDOWN:
		flag = 1;
		return 0 ;	

	case WM_MOUSEMOVE:
		hdc = GetDC(hwnd);
		cur.y = HIWORD(lParam);
		cur.x = LOWORD(lParam);
		switch(WhatCusor(cur.x,cur.y))
		{
		case 1:
			SetCursor (LoadCursor (NULL, IDC_WAIT)) ;
			break;
		case 2:
			SetCursor (LoadCursor (NULL, IDC_CROSS)) ;
			break;
		case 3:
			SetCursor (LoadCursor (NULL, IDC_SIZEALL)) ;
			break;
		case 4:
			SetCursor (LoadCursor (NULL, IDC_IBEAM)) ;
			break;
		}
		sprintf(str,"(%03d,%03d)",cur.x,cur.y);
		TextOut(hdc,0,0,str,strlen(str));
		if(flag){
			if((wParam&MK_CONTROL)&&(wParam&MK_SHIFT)){
				flag = 0;
				MessageBox (NULL, TEXT ("您刚才在移动鼠标的过程中按住了Ctrl和Shift键!"), TEXT ("提示"), 0);
			}
		}
		return 0;

	case WM_KEYUP:
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);		
		return 0 ;
				
	default:		
		return DefWindowProc(hwnd,message,wParam,lParam);
		
	}
	return 0;
}
int WhatCusor(int x,int y)
{
	x-=(50+580)/2;
	y-=(50+400)/2;
	if(x>0&&y>0)
		return 4;
	else if(x<0&&y>0)
		return 3;
	else if(x<0&&y<0)
		return 2;
	else if(x>0&&y<0)
		return 1;
	else return 0;
}
