//Juan Pablo Pazmiño Caicedo 2325093-3743
//Programa que modela figuras geometricas, permite elegir sus dimensiones, calcular el area y perimetro,
//y cambiarlas de color

#include <iostream>
#include <windows.h>
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

using namespace Gdiplus;

Color currentColor(Color(255, 0, 0, 0));
int x = 0;
int y = 0;
float area = 0;
float per = 0;
int width = 100;
int height = 100;


LRESULT CALLBACK WindowProcessMessages(HWND hwnd, UINT msg, WPARAM param, LPARAM lparam);
void draw(HDC hdc);


int WINAPI WinMain(HINSTANCE currentInstance, HINSTANCE previousInstance, PSTR cmdLine, INT cmdCount) {
	//Para abrir la consola
	AllocConsole();

	//Para que la consola muestre y reciba datos
	FILE* stream;
	freopen_s(&stream, "CONOUT$", "w", stdout);
	freopen_s(&stream, "CONIN$", "r", stdin);

	std::cout << "Nota: Para el tamanio del circulo solo se toma el ancho, el cual se toma como el diametro"<<"\n"<< std::endl;
	//Nota: Un ancho mayor a 700 o alto mayor a 450 se va a ver mal
	std::cout << "Ingresa el ancho: ";
	std::cin >> width;
	std::cout << "Ingresa el alto: ";
	std::cin >> height;
	//MessageBox(NULL, "Hello, Win32!", "Win32 API", MB_OK);

	//Inicializar gdi+ (libreria grafica)
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);

	//Registrar la clase "window"
	const char* CLASS_NAME = "myWin32WindowClass";
	WNDCLASS wc{};
	wc.hInstance = currentInstance;
	wc.lpszClassName = CLASS_NAME;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = WindowProcessMessages;
	RegisterClass(&wc);

	//Crear la ventana principal
	CreateWindow(CLASS_NAME, "Figuras geometricas", //Nombre de la ventana
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,			// Tipo de ventana (visible)
		CW_USEDEFAULT, CW_USEDEFAULT,				// Posicion inicial de la ventana (por defecto)
		800, 600,						//Tamaño de la ventana
		nullptr, nullptr, nullptr, nullptr);

	//Este ciclo se recorre hasta que se cierre la ventana
	MSG msg{};
	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	//Cierra el Gdi luego de cerrar la ventana
	Gdiplus::GdiplusShutdown(gdiplusToken);
	return 0;
}

LRESULT CALLBACK WindowProcessMessages(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	HDC hdc;
	PAINTSTRUCT ps;
	
	switch (msg) {
	
	case WM_CREATE:
		//Crear el boton del rectangulo
		CreateWindow(
			"BUTTON",  // Clase predefinida; Unicode 
			"Rectangulo",      // Nombre del boton
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
			10,         // x coordenada 
			500,         // y coordenada
			100,        // Ancho
			50,        // Alto
			hwnd,       // Ventana padre(la principal pues)
			(HMENU)1,   // Identificador
			(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
			NULL);
		//Boton del triangulo
		CreateWindow(
			"BUTTON",  // Clase predefinida; Unicode
			"Triangulo",      // Nombre 
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
			120,         // x coordenada
			500,         // y coordenada 
			100,        // Ancho
			50,        // Alto
			hwnd,       // ventana padre
			(HMENU)2,   // Identificador
			(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
			NULL);

		//Boton del circulo:
		CreateWindow("BUTTON", "Circulo", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			240, 500, 100, 50, hwnd, (HMENU)3, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
		//Boton del color rojo:
		CreateWindow("BUTTON", "Rojo", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  
		360,500, 100, 50, hwnd, (HMENU)4, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
		//Boton del color verde:
		CreateWindow("BUTTON", "Verde", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			480, 500, 100, 50, hwnd, (HMENU)5, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
		//Boton del color azul:
		CreateWindow("BUTTON", "Azul", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			600, 500, 100, 50, hwnd, (HMENU)6, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
		//Boton restart:
		CreateWindow("BUTTON", "Restart", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			720, 20, 50, 50, hwnd, (HMENU)7, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

	//Eventos para crear figuras al presionar los botones
	case WM_COMMAND:

		if (LOWORD(wparam) == 1) {
			HDC hdc = GetDC(hwnd);
			Graphics graphics(hdc);
			//Pen pen(Color(255, 0, 0, 255));
			SolidBrush brush(currentColor); //Define el color de las figuras tomando la variable que cree, para poder cambiarlo
			graphics.FillRectangle(&brush, 50, 50, width, height);
			ReleaseDC(hwnd, hdc);
			area = width * height;
			per = (2 * width) + (2 * height);
			std::cout << "El area del cuadrilatero es de: "<<area<<" pixeles"<<std::endl;
			std::cout << "El perimetro del cuadrilatero es de: " << per<<" pixeles"<< "\n" << std::endl;
		}
		else if (LOWORD(wparam) == 2) {
			HDC hdc = GetDC(hwnd);
			Graphics graphics(hdc);
			//Para graficar un triangulo es necesario usar la funcion FillPolygon, ya que no hay una funcion dedicada,
			//Y se deben especificar las 3 coordenadas de dicho triangulo
			PointF points[] = {
				PointF(50, 50),
				PointF(50, 50+height),
				PointF(50+width, 50+height)
			};
			SolidBrush brush(currentColor);
			graphics.FillPolygon(&brush, points, 3);
			ReleaseDC(hwnd, hdc);
			area = (width * height) / 2;
			per = width + height + (sqrt((width*width)+(height*height)));
			std::cout << "El area del triangulo es de: " << area <<" pixeles"<< std::endl;
			std::cout << "El perimetro del triangulo es de: " << per << " pixeles" << "\n" << std::endl;
		}
		else if (LOWORD(wparam) == 3) {
			HDC hdc = GetDC(hwnd);
			Graphics graphics(hdc);
			SolidBrush brush(currentColor);
			graphics.FillEllipse(&brush, 50, 50, width, width);
			ReleaseDC(hwnd, hdc);
			area = 3.1416*(width/2)*(width/2);
			per = 2*3.1416*(width/2);
			std::cout << "El area del circulo es de: " << area << " pixeles" << std::endl;
			std::cout << "El perimetro del circulo es de: " << per <<" pixeles" << "\n" << std::endl;
		}
		else if (LOWORD(wparam) == 4) {
			currentColor = Color(255, 255, 0, 0);
			
		}
		else if (LOWORD(wparam) == 5) {
			currentColor = Color(255, 0, 255, 0);

		}
		else if (LOWORD(wparam) == 6) {
			currentColor = Color(255, 0, 0, 255);

		}
		//Reinicia la ventana principal
		else if (LOWORD(wparam) == 7) {
			InvalidateRect(hwnd, NULL, TRUE);
		}
		break;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		draw(hdc);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY: //Cerrar la ventana
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}
}

void draw(HDC hdc) {
	
}


