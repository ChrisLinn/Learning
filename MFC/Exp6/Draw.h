#include <afxwin.h>
class CDrawWnd: public CFrameWnd
{
protected:
LRESULT OnLButtonDown(WPARAM wParam, LPARAM lParam);
LRESULT OnMouseMove(WPARAM wParam, LPARAM lParam);
LRESULT OnPaint(WPARAM wParam,LPARAM lParam);
DECLARE_MESSAGE_MAP()
public:
int x1,y1,x2,y2,flag;
CDrawWnd();
};
class CDrawApp: public CWinApp
{
public:
BOOL InitInstance();

};
CDrawApp ThisApp; // 全局应用程序对象

