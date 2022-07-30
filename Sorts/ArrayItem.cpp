#include "pch.h"
#include "ArrayItem.h"
#include <cmath>
#include <vector>
#include <algorithm>
//#include <math.h>


using namespace std;


void ArrayItem::rgb2hsv()
{
	hsv out;
	rgb in;
	unsigned char      min, max, delta;

	in.R = RGB.R;
	in.G = RGB.G;
	in.B = RGB.B;

	min = in.R < in.G ? in.R : in.G;
	min = min < in.B ? min : in.B;

	max = in.R > in.G ? in.R : in.G;
	max = max > in.B ? max : in.B;

	out.v = max;                                // v
	delta = max - min;
	if (delta < 0.00001)
	{
		out.s = 0;
		out.h = 0; // undefined, maybe nan?
		HSV.h = out.h;
		HSV.s = out.s;
		HSV.v = out.v;
		return;
	}
	if (max > 0.0)
	{ // NOTE: if Max is == 0, this divide would cause a crash
		out.s = (delta / max);                  // s
	}
	else
	{
		// if max is 0, then r = g = b = 0              
		// s = 0, h is undefined
		out.s = 0.0;
		out.h = NAN;                            // its now undefined
		HSV.h = out.h;
		HSV.s = out.s;
		HSV.v = out.v;
		return;
	}
	if (in.R >= max)                           // > is bogus, just keeps compilor happy
		out.h = (in.G - in.B) / delta;        // between yellow & magenta
	else
		if (in.G >= max)
			out.h = 2.0 + (in.B - in.R) / delta;  // between cyan & yellow
		else
			out.h = 4.0 + (in.R - in.G) / delta;  // between magenta & cyan

	out.h *= 60.0;                              // degrees

	if (out.h < 0.0)
		out.h += 360.0;

	HSV.h = out.h;
	HSV.s = out.s;
	HSV.v = out.v;
}


void ArrayItem::hsv2rgb()
{
	double      hh, p, q, t, ff;
	long        i;

	rgb out;
	hsv in;

	in.h = HSV.h;
	in.s = HSV.s;
	in.v = HSV.v;

	if (in.s <= 0.0)
	{       // < is bogus, just shuts up warnings
		out.R = in.v;
		out.G = in.v;
		out.B = in.v;
		RGB.R = out.R;
		RGB.G = out.G;
		RGB.B = out.B;
		return;
	}
	hh = in.h;
	if (hh >= 360.0) hh = 0.0;
	hh /= 60.0;
	i = (long)hh;
	ff = hh - i;
	p = in.v * (1.0 - in.s);
	q = in.v * (1.0 - (in.s * ff));
	t = in.v * (1.0 - (in.s * (1.0 - ff)));

	switch (i)
	{
		case 0:
			out.R = in.v;
			out.G = t;
			out.B = p;
			break;
		case 1:
			out.R = q;
			out.G = in.v;
			out.B = p;
			break;
		case 2:
			out.R = p;
			out.G = in.v;
			out.B = t;
			break;
		case 3:
			out.R = p;
			out.G = q;
			out.B = in.v;
			break;
		case 4:
			out.R = t;
			out.G = p;
			out.B = in.v;
			break;
		case 5:
		default:
			out.R = in.v;
			out.G = p;
			out.B = q;
			break;
	}
	RGB.R = out.R;
	RGB.G = out.G;
	RGB.B = out.B;
}


void ArrayItem::setCor(Color cor)
{
	float nRPct;
	float nGPct;
	float nBPct;
	float linR;
	float linG;
	float linB;
	float lY;
	float l;
	float gama;
	rgb color;
	//hsv colorhsv;
	int r;
	int g;
	int b;

	corLong = cor.B + cor.G * 256 + cor.R * 256 * 256;

	//color = 
	RGB.R = cor.R;// cor % 256;
	RGB.G = cor.G;// (cor / 256) % 256;
	RGB.B = cor.B;// cor / 256 / 256;


	r = RGB.R;
	g = RGB.G;
	b = RGB.B;

	//=0,299*I1+0,587*J1+0,114*K1
	nRPct = r;// (0.299 * r);
	nGPct = g;// (0.587 * g);
	nBPct = b;// (0.114 * b);
	cinza2 = (int)roundf((nRPct + nGPct + nBPct) / 3);

	nRPct = r / 255.0;
	nGPct = g / 255.0;
	nBPct = b / 255.0;


	rgb2hsv();


	if (nRPct <= 0.04045)
	{
		linR = nRPct / 12.92;
	}
	else
	{
		linR = pow(((nRPct + 0.055) / 1.055), 2.4);
	}
	if (nGPct <= 0.04045)
	{
		linG = nGPct / 12.92;
	}
	else
	{
		linG = pow(((nGPct + 0.055) / 1.055), 2.4);
	}
	if (nBPct <= 0.04045)
	{
		linB = nBPct / 12.92;
	}
	else
	{
		linB = pow(((nBPct + 0.055) / 1.055), 2.4);
	}

	gama = 1.0; // '2.2

	lY = 0.2126 * linR + 0.7152 * linG + 0.0722 * linB;
	l = lY * 65535 * pow(lY, (1 / gama));  //'116 * lY ^ (1 / 3) //' - 16

	cinza = l;
}

void ArrayItem::setIDX(int i)
{
	indiceOriginal = i;
}

void ArrayItem::setX(unsigned int x1)
{
	x = x1;
}

void ArrayItem::setY(unsigned int y1)
{
	y = y1;
}


unsigned int ArrayItem::getCor()
{
	return corLong;
}


unsigned char ArrayItem::getR()
{
	return RGB.R;
}


unsigned char ArrayItem::getG()
{
	return RGB.G;
}


unsigned char ArrayItem::getB()
{
	return RGB.B;
}

char ArrayItem::compareTo(ArrayItem arr)
{
	char ret;

	ret = 0;
	if (arr.corLong < corLong) ret = 1;
	if (arr.corLong > corLong) ret = -1;

	return ret;
}

