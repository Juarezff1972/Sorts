#include "pch.h"
#include "Algoritmos.h"
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>


void Algoritmos::setSort(String^ s)
{
	sortType = s;
}

void Algoritmos::ProcessaBMP(Bitmap^ bmp)
{
	// TODO: Adicione seu código de implementação aqui.

	Color c;
	unsigned int h1;
	unsigned int w1;
	unsigned int i, j;

	int t;
	int idx = 0;
	h1 = bmp->Height;
	w1 = bmp->Width;

	t = h1 * w1;

	//std::vector <ArrayItem> itm(t);

	//item = itm;
	item.resize(t);
	bmp2 = gcnew Bitmap(w1, h1);

	pg1->Maximum = t;
	pg1->Value = 0;
	for (j = 0; j < h1; j++)
	{
		for (i = 0; i < w1; i++)
		{
			item[idx] = gcnew ArrayItem();


			item[idx]->setIDX(idx);
			c = bmp->GetPixel(i, j);
			item[idx]->setCor(c);
			item[idx]->setX(i);
			item[idx]->setY(j);

			//bmp2->SetPixel(i, j, c.FromArgb(item[idx]->cinza2, item[idx]->cinza2, item[idx]->cinza2));

			idx++;
			pg1->Value = idx;
		}
	}

	//


	getMax();
	getMin();

	//Item = item;

	txtbx->Text = maxValue.ToString();
}

void Algoritmos::gerarCinza()
{
	Color c;
	unsigned int i;
	unsigned int x, y;
	unsigned int t;
	//c = gcnew Color();

	t = item.size();

	pg1->Value = 0;
	pg1->Maximum = t;

	destpic->Image = bmp2;

	for (i = 0; i < t; i++)
	{
		x = item[i]->x;
		y = item[i]->y;

		bmp2->SetPixel(x, y, c.FromArgb(item[i]->cinza2, item[i]->cinza2, item[i]->cinza2));
		pg1->Value = i;
		if (i % 2048 == 0) destpic->Refresh();
	}
	//destpic->Image = bmp2;
	destpic->Refresh();
}

template <class Container>
void split(const std::string& str, Container& cont, char delim = ' ')
{
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, delim))
	{
		cont.push_back(token);
	}
}

void Algoritmos::BucketSort()
{
	//MessageBox::Show("Clicou", "Ordenar", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);

	Color c;
	unsigned int h1;
	unsigned int w1;
	unsigned int i;
	unsigned int x1, y1;
	unsigned int x, y;
	unsigned int t, clr;
	std::string j, k;
	//c = gcnew Color();

	h1 = bmp2->Height;
	w1 = bmp2->Width;

	clr = 0;

	t = item.size();

	//std::string *collection = new std::string[wordsCollection];

	std::string* vlr = new std::string[maxValue + 1];
	std::string* idx1 = new std::string[t];

	//int* vec = new int[maxValue + 1][t];
	//std::array<std::vector<int>, (maxValue + 1)> vec;

	//std::vector<std::string> vlr;


	pg1->Value = 0;
	pg1->Maximum = maxValue;

	destpic->Image = bmp2;

	for (i = 0; i <= maxValue; i++)
	{
		vlr[i] = std::string("*");
		//vlr.push_back(std::string("*"));
		pg1->Value = i;
	}

	pg1->Value = 0;
	pg1->Maximum = t;
	for (i = 0; i < t; i++)
	{
		pg1->Value = i;
		idx1[i] = "," + std::to_string(item[i]->indiceOriginal);
	}

	pg1->Value = 0;
	//pg1->Maximum = t;

	for (i = 0; i < t; i++)
	{
		x = item[i]->x;
		y = item[i]->y;

		bmp2->SetPixel(x, y, c.FromArgb(255 - item[i]->getR(), 255 - item[i]->getG(), 255 - item[i]->getB()));
		pg1->Value = i;
		if (i % w1 == 0) destpic->Refresh();
		clr = item[i]->cinza;
		vlr[clr] = vlr[clr].append(idx1[i]);
	}

	std::vector<std::string> idx;
	i = 0;


	x1 = 0;
	y1 = 0;

	pg1->Value = 0;
	pg1->Maximum = maxValue;

	for (clr = 0; clr <= maxValue; clr++)
	{
		idx.clear();
		split(vlr[clr], idx, ',');
		for (t = 1; t < idx.size(); t++)
		{
			j = idx[t];
			i = stoi(j);
			bmp2->SetPixel(x1, y1, c.FromArgb(item[i]->getR(), item[i]->getG(), item[i]->getB()));

			x1++;
			if (x1 > w1 - 1)
			{
				x1 = 0;
				y1++;
			}
		}
		pg1->Value = clr;
		if (clr % 2048 == 0) destpic->Refresh();

	}
}

void Algoritmos::BubbleSort()
{
	Color c;
	unsigned int h1;
	unsigned int w1;
	unsigned int i, j;

	unsigned int x, y;
	unsigned int t;

	h1 = bmp2->Height;
	w1 = bmp2->Width;

	cliext::vector <int> x1;
	cliext::vector <int> y1;

	t = item.size();
	pg1->Maximum = t;
	pg2->Maximum = t;

	x1.resize(t);
	y1.resize(t);

	destpic->Image = bmp2;

	for (i = 0; i < t; i++)
	{
		x = item[i]->x;
		y = item[i]->y;

		x1[i] = x;
		y1[i] = y;

		bmp2->SetPixel(x, y, c.FromArgb(item[i]->getR(), item[i]->getG(), item[i]->getB()));
		pg1->Value = i;
		if (i % w1 == 0) destpic->Refresh();
	}

	for (i = 0; i < t - 1; i++)
	{
		for (j = 0; j < t - 1 - i; j++)
		{
			if (item[j]->cinza > item[j + 1]->cinza)
			{
				//swap(&item[j], &item[j + 1]);
				ArrayItem^ tmp;
				tmp = gcnew ArrayItem(item[j]);
				item[j] = gcnew ArrayItem(item[j + 1]);
				item[j + 1] = gcnew ArrayItem(tmp);

				bmp2->SetPixel(x1[j], y1[j], c.FromArgb(item[j]->getR(), item[j]->getG(), item[j]->getB()));
				bmp2->SetPixel(x1[j + 1], y1[j + 1], c.FromArgb(item[j + 1]->getR(), item[j + 1]->getG(), item[j + 1]->getB()));
			}
			pg2->Value = j;
			//if (j % w1 == 0) destpic->Refresh();
		}
		destpic->Refresh();
		pg1->Value = i;
	}
}
void Algoritmos::OptimizedBubble()
{
	unsigned int max, min;
	unsigned int max_idx, min_idx;
	unsigned int lo = 0;
	unsigned int hi = item.size() - 1;
	unsigned int i;
	unsigned int x, y;
	unsigned int t;
	cliext::vector <int> x1;
	cliext::vector <int> y1;
	Color c;
	unsigned int h1;
	unsigned int w1;
	ArrayItem^ tmp;

	h1 = bmp2->Height;
	w1 = bmp2->Width;
	t = item.size();
	x1.resize(t);
	y1.resize(t);
	destpic->Image = bmp2;

	for (i = lo; i < hi + 1; i++)
	{
		x = item[i]->x;
		y = item[i]->y;

		x1[i] = x;
		y1[i] = y;

		bmp2->SetPixel(x, y, c.FromArgb(item[i]->cinza2, item[i]->cinza2, item[i]->cinza2));
		pg1->Value = i;
		if (i % w1 == 0) destpic->Refresh();
	}
	pg2->Maximum = hi;
	while (lo < hi)
	{
		min = 255 * 255 * 255;
		max = 0;
		pg2->Value = hi;

		for (i = lo; i < hi + 1; i++)
		{
			if (max <= item[i]->cinza)
			{
				max = item[i]->cinza;
				max_idx = i;
			}
			if (min >= item[i]->cinza)
			{
				min = item[i]->cinza;
				min_idx = i;
			}
			pg1->Value = i;


		}
		tmp = gcnew ArrayItem(item[min_idx]);
		item[min_idx] = gcnew ArrayItem(item[lo]);
		item[lo] = gcnew ArrayItem(tmp);

		tmp = gcnew ArrayItem(item[max_idx]);
		item[max_idx] = gcnew ArrayItem(item[hi]);
		item[hi] = gcnew ArrayItem(tmp);

		bmp2->SetPixel(x1[min_idx], y1[min_idx], c.FromArgb(item[min_idx]->getR(), item[min_idx]->getG(), item[min_idx]->getB()));
		bmp2->SetPixel(x1[max_idx], y1[max_idx], c.FromArgb(item[max_idx]->getR(), item[max_idx]->getG(), item[max_idx]->getB()));
		bmp2->SetPixel(x1[lo], y1[lo], c.FromArgb(item[lo]->getR(), item[lo]->getG(), item[lo]->getB()));
		bmp2->SetPixel(x1[hi], y1[hi], c.FromArgb(item[hi]->getR(), item[hi]->getG(), item[hi]->getB()));
		destpic->Refresh();
		lo++;
		hi--;

		txtbx->Text = lo.ToString() + "-" + hi.ToString() + "|" + min.ToString() + "-" + max.ToString() + "|" + min_idx.ToString() + "-" + max_idx.ToString();
		txtbx->Refresh();
		min_idx = lo;
		max_idx = hi;
	}
	destpic->Refresh();
}

void Algoritmos::CocktailSort()
{
	unsigned int lo = 0;
	unsigned int hi = item.size() - 1;
	int mov = lo;
	ArrayItem^ tmp;

	Color c;
	unsigned int h1;
	unsigned int w1;
	unsigned int i;

	unsigned int x, y;
	unsigned int t;

	h1 = bmp2->Height;
	w1 = bmp2->Width;

	cliext::vector <int> x1;
	cliext::vector <int> y1;

	t = item.size();
	pg1->Maximum = t;
	pg2->Maximum = t;

	x1.resize(t);
	y1.resize(t);

	destpic->Image = bmp2;

	for (i = 0; i < t; i++)
	{
		x = item[i]->x;
		y = item[i]->y;

		x1[i] = x;
		y1[i] = y;

		//bmp2->SetPixel(x, y, c.FromArgb(item[i]->getR(), item[i]->getG(), item[i]->getB()));
		bmp2->SetPixel(x, y, c.FromArgb(item[i]->cinza2, item[i]->cinza2, item[i]->cinza2));
		pg1->Value = i;
		if (i % w1 == 0) destpic->Refresh();
	}

	while (lo < hi)
	{
		for (i = hi; i > lo; --i)
		{
			if (item[i - 1]->cinza > item[i]->cinza)
			{
				tmp = gcnew ArrayItem(item[i]);
				item[i] = gcnew ArrayItem(item[i - 1]);
				item[i - 1] = gcnew ArrayItem(tmp);
				mov = i;
				bmp2->SetPixel(x1[i], y1[i], c.FromArgb(item[i]->getR(), item[i]->getG(), item[i]->getB()));
				bmp2->SetPixel(x1[i - 1], y1[i - 1], c.FromArgb(item[i - 1]->getR(), item[i - 1]->getG(), item[i - 1]->getB()));
				pg2->Value = mov;
			}

			pg1->Value = i;
		}
		lo = mov;
		for (i = lo; i < hi; ++i)
		{
			if (item[i]->cinza > item[i + 1]->cinza)
			{
				tmp = gcnew ArrayItem(item[i]);
				item[i] = gcnew ArrayItem(item[i + 1]);
				item[i + 1] = gcnew ArrayItem(tmp);
				mov = i;
				bmp2->SetPixel(x1[i], y1[i], c.FromArgb(item[i]->getR(), item[i]->getG(), item[i]->getB()));
				bmp2->SetPixel(x1[i + 1], y1[i + 1], c.FromArgb(item[i + 1]->getR(), item[i + 1]->getG(), item[i + 1]->getB()));
				pg2->Value = mov;
			}
			pg1->Value = i;
		}
		destpic->Refresh();

		hi = mov;

	}
	destpic->Refresh();
}


void Algoritmos::Ordenar()
{
	/*
	Bucket Sort
Bubble Sort
Cocktail Sort
Optimized Bubble Sort
*/
	if (sortType == "Bucket Sort")
	{
		BucketSort();
	}
	if (sortType == "Bubble Sort")
	{
		BubbleSort();
	}
	if (sortType == "Cocktail Sort")
	{
		CocktailSort();
	}
	if (sortType == "Optimized Bubble Sort")
	{
		OptimizedBubble();
	}

	destpic->Refresh();
	MessageBox::Show("Feito", "Ordenar", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
}

void Algoritmos::getMin()
{
	long k;
	minIdx = -1;
	minValue = 16777215;


	for (k = 0; k < item.size(); k++)
	{
		if (item[k]->cinza < minValue)
		{
			minIdx = k;
			minValue = item[k]->cinza;
		}
	}
}

void Algoritmos::getMax()
{
	long k;
	maxIdx = 0;
	maxValue = 0;

	for (k = 0; k < item.size(); k++)
	{
		if (item[k]->cinza > maxValue)
		{
			maxIdx = k;
			maxValue = item[k]->cinza;
		}
	}
}

void Algoritmos::swap(ArrayItem^* a1, ArrayItem^* a2)
{
	ArrayItem^* tmp;
	//tmp = gcnew ArrayItem(a1);
	//a1 = gcnew ArrayItem(a2);
	//a2 = gcnew ArrayItem(tmp);
	tmp = a1;
	a1 = a2;
	a2 = tmp;

}

void Algoritmos::filtro()
{
	SByte filtro1[3][3];
	SByte filtro2[3][3];

	unsigned int h1;
	unsigned int w1;
	unsigned int i;

	unsigned int x, y;
	unsigned int t;
	Color c;
	Bitmap^ bmp1;
	h1 = bmp2->Height;
	w1 = bmp2->Width;

	t = item.size();
	pg1->Maximum = t;
	pg2->Maximum = t;

	filtro1[0][0] = 1;
	filtro1[0][1] = 0;
	filtro1[0][2] = -1;
	filtro1[1][0] = 2;
	filtro1[1][1] = 0;
	filtro1[1][2] = -2;
	filtro1[2][0] = 1;
	filtro1[2][1] = 0;
	filtro1[2][2] = -1;
	filtro2[0][0] = -1;
	filtro2[0][1] = -2;
	filtro2[0][2] = -1;
	filtro2[1][0] = 0;
	filtro2[1][1] = 0;
	filtro2[1][2] = 0;
	filtro2[2][0] = 1;
	filtro2[2][1] = 2;
	filtro2[2][2] = 1;

	bmp1 = gcnew Bitmap(bmp2->Width, bmp2->Height);

	destpic->Image = bmp2;

	for (i = 0; i < t; i++)
	{
		x = item[i]->x;
		y = item[i]->y;

		//x1[i] = x;
		//y1[i] = y;

		bmp1->SetPixel(x, y, c.FromArgb(item[i]->getR(), item[i]->getG(), item[i]->getB()));
		bmp2->SetPixel(x, y, c.FromArgb(item[i]->getR(), item[i]->getG(), item[i]->getB()));
		//bmp2->SetPixel(x, y, c.FromArgb(item[i]->cinza2, item[i]->cinza2, item[i]->cinza2));
		pg1->Value = i;
		if (i % w1 == 0) destpic->Refresh();


	}
	pg1->Maximum = w1;
	for (x = 0; x < w1; x++)
	{
		for (y = 0; y < h1; y++)
		{
			//c = bmp.GetPixel( x, y );
			c = aplicaFiltro(x, y, filtro1, filtro2, bmp1);
			bmp2->SetPixel(x, y, c);

		}
		//pictureBox1.Image = bmp;
		pg1->Value = x;
		destpic->Refresh();
		//pictureBox1.Refresh();
	}
	destpic->Refresh();


}

Color Algoritmos::aplicaFiltro(unsigned int x, unsigned int y, SByte filtro1[3][3], SByte filtro2[3][3], Bitmap^ bmp1)
{
	int i, j;
	int k, l;
	int r1, g1, b1;
	int r2, g2, b2;
	double r, g, b;

	SByte f1;
	SByte f2;

	Color c1;
	r1 = 0;
	g1 = 0;
	b1 = 0;
	r2 = 0;
	g2 = 0;
	b2 = 0;

	for (i = -1; i < 2; i++)
	{
		for (j = -1; j < 2; j++)
		{
			k = x + i;
			l = y + j;
			if ((k < 0) || (l < 0) || (k >= bmp1->Width) || (l >= bmp1->Height))
			{
				c1 = Color::FromArgb(0, 0, 0);
			}
			else
			{
				c1 = bmp1->GetPixel(k, l);
			}
			f1 = filtro1[i + 1][j + 1];
			f2 = filtro2[i + 1][j + 1];

			r1 += (c1.R * f1);// / 4;
			g1 += (c1.G * f1);// / 4;
			b1 += (c1.B * f1);// / 4;
			r2 += (c1.R * f2);// / 4;
			g2 += (c1.G * f2);// / 4;
			b2 += (c1.B * f2);// / 4;

		}
	}
	r = System::Math::Sqrt(r1 * r1 + r2 * r2);
	g = System::Math::Sqrt(g1 * g1 + g2 * g2);
	b = System::Math::Sqrt(b1 * b1 + b2 * b2);


	if (r > 255)
		r = 255;
	if (r < 0)
		r = 0;
	if (g > 255)
		g = 255;
	if (g < 0)
		g = 0;
	if (b > 255)
		b = 255;
	if (b < 0)
		b = 0;

	c1 = Color::FromArgb((int)r, (int)g, (int)b);

	return c1;
}
