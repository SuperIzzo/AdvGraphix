#include <windows.h>

long __stdcall WndProc( HWND window, unsigned int msg, WPARAM wp, LPARAM lp )
{
    switch(msg)
    {
        case WM_DESTROY:
            PostQuitMessage(0) ;
            return 0L ;
        case WM_LBUTTONDOWN:
            //std::cout << "\nmouse left button down at (" << LOWORD(lp)
            //          << ',' << HIWORD(lp) << ")\n" ;
            // fall thru
        default:
            //std::cout << '.' ;
            return DefWindowProc( window, msg, wp, lp ) ;
    }
}

int RunWnd()
{
	const WCHAR * theWndClass = L"OGLClass";
    WNDCLASSEX wc;
	
	wc.cbSize			= sizeof(WNDCLASSEX);
	wc.style			= 0;
	wc.lpfnWndProc		= WndProc;
	wc.cbClsExtra		= 0;
    wc.cbWndExtra		= 0;
	wc.hInstance		= GetModuleHandle(0);
	wc.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor			= LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszMenuName		= NULL;
	wc.lpszClassName	= theWndClass;
	wc.hIconSm			= LoadIcon(0,IDI_APPLICATION);


    if( RegisterClassEx(&wc) )
    {
        HWND window = CreateWindowEx( 0, theWndClass, L"title",
                   WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                   CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, GetModuleHandle(0), 0 ) ;
        if(window)
        {
            ShowWindow( window, SW_SHOWDEFAULT ) ;
            MSG msg ;
            while( GetMessage( &msg, 0, 0, 0 ) ) DispatchMessage(&msg) ;
        }
    }

	return 0;
}