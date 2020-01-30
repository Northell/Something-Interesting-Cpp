
/*Задание: Сфотографировать рабочий стол, подождать немнмого, сфотографировать еще раз, изменения закрасить зеленым цветом.
Картинки сохранить в проекте*/


#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <gdiplus.h>

using namespace std;

#define LoadBmp(fbmp)\
(HBITMAP)LoadImage((HINSTANCE)GetModuleHandle(NULL),\
                              fbmp, IMAGE_BITMAP, 0, 0,\
                              LR_LOADFROMFILE | LR_CREATEDIBSECTION)



// 16-цветный и монохромный растр не поддерживается




#pragma comment(lib, "GdiPlus.lib") /* наш многострадальный lib-файл */
using namespace Gdiplus; /* как хочешь, но мне не в кайф постоянно писать Gdiplus:: */

static const GUID bmp =
{ 0x557cf406, 0x1a04, 0x11d3, { 0x9a, 0x73, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e } };


void Sleep(BYTE time)
{
	Sleep((DWORD)time * 1000);
	return;
}


using namespace std;
HDC memdc, memdc1, scrdc;


BOOL  IsBitmapEqual(HBITMAP bmp1, HBITMAP bmp2) {
	BITMAP bi1, bi2;
	ZeroMemory(&bi1, sizeof(BITMAP));
	ZeroMemory(&bi2, sizeof(BITMAP));

	if (!GetObject(bmp1, sizeof(BITMAP), (LPVOID)&bi1))
		return FALSE;
	if (!GetObject(bmp2, sizeof(BITMAP), (LPVOID)&bi2))
		return FALSE;



	bi1.bmBitsPixel >>= 3;



	DWORD size = (DWORD)(bi1.bmWidth * bi1.bmHeight * bi1.bmBitsPixel);
	BYTE* ptr1 = (BYTE*)HeapAlloc(GetProcessHeap(), 0uL, size);
	BYTE* ptr2 = (BYTE*)HeapAlloc(GetProcessHeap(), 0uL, size);

	GetBitmapBits(bmp1, (LONG)size, (LPVOID)ptr1);
	GetBitmapBits(bmp2, (LONG)size, (LPVOID)ptr2);



	for (int i = 0; i < bi1.bmHeight; ++i) {
		for (int j = 0; j < bi1.bmWidth; ++j) {


			if (GetPixel(memdc, j, i) != GetPixel(memdc1, j, i)) {
				bi2.bmBitsPixel = SetPixel(memdc1, j, i, RGB(0, 255, 0));


			}
			if ((ptr2[i + j] == ptr1[i + j]))
				ptr2[i + j] = ptr1[i + j];


		}
	}
	HeapFree(GetProcessHeap(), 0uL, (LPVOID)ptr1);
	HeapFree(GetProcessHeap(), 0uL, (LPVOID)ptr2);

}


int main()
{
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);


	HBITMAP membit;
	// Получаем HDC рабочего стола
	// Параметр HWND для рабочего стола всегда равен нулю.
	scrdc = GetDC(0);
	// Определяем разрешение экрана
	int Height, Width;
	Height = GetSystemMetrics(SM_CYSCREEN);
	Width = GetSystemMetrics(SM_CXSCREEN);
	// Создаем новый DC, идентичный десктоповскому и битмап размером с экран.
	memdc = CreateCompatibleDC(scrdc); //dc
	membit = CreateCompatibleBitmap(scrdc, Width, Height); //bitmap
	SelectObject(memdc, membit);
	// Улыбаемся... Снято!
	BitBlt(memdc, 0, 0, Width, Height, scrdc, 0, 0, SRCCOPY);


	HBITMAP hBitmap, hBitmap1;
	hBitmap = (HBITMAP)SelectObject(memdc, membit);
	Gdiplus::Bitmap bitmap(hBitmap, NULL);
	bitmap.Save(L"D:\screen1.bmp", &bmp);

	Sleep((BYTE)5);
	scrdc = GetDC(0);
	memdc1 = CreateCompatibleDC(scrdc);
	membit = CreateCompatibleBitmap(scrdc, Width, Height);
	SelectObject(memdc1, membit);

	BitBlt(memdc1, 0, 0, Width, Height, scrdc, 0, 0, SRCCOPY);
	hBitmap1 = (HBITMAP)SelectObject(memdc1, membit);










	if (IsBitmapEqual(hBitmap, hBitmap1))
		puts("Yes equal.");
	else
		puts("Not equal !");
	Gdiplus::Bitmap bitmap1(hBitmap1, NULL);
	bitmap1.Save(L"D:\screen2.bmp", &bmp);
	DeleteObject(hBitmap1);
	DeleteObject(hBitmap);
	return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
