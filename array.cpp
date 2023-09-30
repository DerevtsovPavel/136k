// Автор: Деревцов Павел

#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#pragma once

using namespace std;


///Заполнение массива а размером n случ числами от min до max
void random_array(float* a, unsigned n,float min,float max)
{	
	if (a == nullptr) throw 1;
	// throw invalid_argument("");
	
	else if (n==0) {throw 2;}
	else
	{
		for (unsigned i=0; i<n; i++)
			a[i]=(double)(rand())/RAND_MAX * (max - min) + min;;//заполняем случ числами от min до max
	}
	 
}

///вывод массива а размером n на экран по е элементов в строке
void print_array(const float* a, unsigned n, unsigned e)
{	
	if (a == nullptr) throw 1;
	
	 else if (n==0) {throw 2;}
	else
	{
		unsigned k=0;
		for (unsigned i=0; i<n; i++)
		{	
			cout<<a[i]<<" ";
			k++;
			if (k%e == 0)
				cout<<"\n";//выводим по 10 элементов в строке

		}

		cout<<"\n";
	}
	 
}

///вычисление по формуле 2(а1+...+аn)^2 а-массив n-его размер
float sum_ar(float* a, unsigned n)
{	
	float s=0;
	if (a == nullptr) throw 1; 
	else if (n==0) {throw 2;}
	else 
	{
		

		for (unsigned i=0; i<n; i++)
			s=s+a[i];	
	}
	return s*s*2;
}

///запись размера и массива в файл name. Сначала пишем размер-n, затем массив а в столбик
void array_infile(float* a, unsigned n,std::string& name)
{	
	if (a == nullptr) throw 1;
	 
	 else if (n==0) {throw 2;}
	else if (name.length()==0) {throw 3;}

	else
	{
		ofstream f(name);//создаём файл на запись
	
		if (f.is_open())
		{

			f<<n;//пишем размер массива
			f<<endl;

			//выводим массив в столбик
			for (unsigned i=0; i<n; i++)
			{
				f<<a[i];
				f<<"\n";
			}

			f.close();
		}
		else{throw 4;}//если файл не открылся
	}
	 	
}



///создание массива из файла name. Размер массива тоже записан в файл
float* array_outfile( unsigned& n,std::string& name)
{
	float* a=nullptr;
	if (name.length()==0){throw 3;}
	else
	{
		ifstream f(name);
		if (f.is_open())
		{
			f >> n;
			if (n==0){throw 2;}
			a = new float[n]{0};

			for (unsigned i = 0; i < n; i++)
			{
				f >> a[i];
			}

			f.close();
		}
		else{throw 4;}
	}

	return a;

}

///запись массива a и размера n в бинарный файл с именем name
void array_inbinary(float* a, unsigned n,std::string& name)
{	
	if (a == nullptr) throw 1;
	
	else if (n==0) {throw 2;}
	else if (name.length()==0) {throw 3;}
	else
	{
		ofstream f(name,ios::binary);

		if (f.is_open())
		{

			f.write( (char*)&n, sizeof(n) );//записываем размер массива

			//записываем массив 
			for (unsigned i=0; i<n; i++)
				{
					f.write((char*)&a[i],sizeof(a[i]));
				}

			f.close();
		}
		else{throw 4;}
}	}
	

///создание массива из бинарного файла name, размером n, который первый в файле
float* array_outbinary(unsigned& n,std::string& name)
{	
	float* a=nullptr;//создаём ук на а
	if (name.length()==0){throw 3;}
	else
	{
		ifstream f(name,ios::binary);
		if (f.is_open())
		{
			f.read((char*)&n,sizeof(n));

			if (n==0) {throw 2;}

			a = new float[n]{0};//создаём массив а из n эл и заполняем нулями

			for (unsigned i = 0; i < n; i++)
			{
				f.read((char*)&a[i],sizeof(a[i]));//читаем массив
			}

			f.close();

		}
		else{throw 4;}
	}
	return a;
}