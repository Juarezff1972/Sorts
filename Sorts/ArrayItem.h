#pragma once

//#include "rgb.h"

using namespace System::Drawing;





ref class ArrayItem
{
	unsigned long corLong;
	//RGB rgb;

	void rgb2hsv();
	void hsv2rgb();
	ref struct hsv
	{
		double h=0.0;       // angle in degrees
		double s=0.0;       // a fraction between 0 and 1
		double v=0.0;       // a fraction between 0 and 1
	} HSV;

	ref struct rgb
	{
		unsigned char R;
		unsigned char G;
		unsigned char B;
	} RGB;

public:
	int indiceOriginal = -1;
	unsigned long cinza=0;
	unsigned char cinza2=0;
	unsigned int x=0;
	unsigned int y=0;
	//hsv HSV;
	//rgb RGB;


	void setCor(Color cor);
	void setIDX(int i);
	void setX(unsigned int x1);
	void setY(unsigned int y1);
	unsigned int getCor();
	unsigned char getR();
	unsigned char getG();
	unsigned char getB();
	char compareTo(ArrayItem arr);
	
	ArrayItem()
	{
		indiceOriginal = -1;
	}
	/*ArrayItem(const ArrayItem^ copied) : x(copied->x)
	{
	};*/

	ArrayItem(const ArrayItem^ outro)
	{ //Construtor de cópia - copia recurso
		indiceOriginal=outro->indiceOriginal;
		cinza = outro->cinza;
		cinza2 = outro->cinza2;
		corLong = outro->corLong;
		RGB.R = outro->RGB.R;
		RGB.G = outro->RGB.G;
		RGB.B = outro->RGB.B;
		HSV.h = outro->HSV.h;
		HSV.s = outro->HSV.s;
		HSV.v = outro->HSV.v;
		x = outro->x;
		y = outro->y;
	}

};

