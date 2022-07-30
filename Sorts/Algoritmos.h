#pragma once

#include <cliext/vector>
#include "ArrayItem.h"
//#include <string>


using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
//using namespace std;



ref class Algoritmos
{
public:

	int cnt;
	TextBox ^txtbx;
	PictureBox^ destpic;
	ProgressBar^ pg1;
	ProgressBar^ pg2;
	

	void ProcessaBMP(Bitmap^ bmp);
	void gerarCinza();
	void Ordenar();
	void BucketSort();
	void BubbleSort();
	void CocktailSort();
	void OptimizedBubble();
	void setSort(String^ s);
	void filtro();

private:

	cliext::vector <ArrayItem^> item;
	
	int minIdx;
	int maxIdx;
	unsigned int minValue;
	unsigned int maxValue;
	Bitmap^ bmp2;
	String^ sortType;

	void getMin();
	void getMax();
	void swap(ArrayItem^* a1, ArrayItem^* a2);
	Color aplicaFiltro(unsigned int x, unsigned int y, SByte filtro1[3][3], SByte filtro2[3][3], Bitmap^ bmp1);
	
};

