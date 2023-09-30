//Автор: Деревцов Павел
//Вычислить 2(а1+...+аn)^2


#include <iostream>
#include <cassert>//тесты
#include <iomanip>//для setprecision
#include "array.h"
#include <string>
#include <stdexcept>

#define NDEBUG;//отключаем assert
using namespace std;



int main()
{	
	///массивы для тестов
	float *a1= new float [3] {2,3,4};
	float *a2=new float [3] {2.5,3.6,7.1};
	float *a3=new float [10] {0,1,2,3,4,5,6,7,8,9};

	assert(sum_ar(a1,3)==162);
	assert((sum_ar(a2,3)-348.48)<0.009);
	assert(sum_ar(a3,10)==4050);



	unsigned n;
	const float MIN=1.0;
	const float MAX=10.9;

	srand(time(0));
	cout<<"Input size of array: ";
	cin>>n;
	if (n==0)
	{	cout<<"Zero size"<<endl;
		return -1;
	}

	else
	{
		cout<<"\n";

		try 
		{
			

			float* ar=new float [n]{0};

			///для тестов
			float*b=nullptr;
			string s2;
		
		
		
			random_array(ar,n,MIN,MAX);

			cout<<fixed<<setprecision(1);//вывод с одним знаком после запятой

			cout<<"Input number of elements in string:";
			unsigned e=0;
			cin>>e;
			cout<<"\n";

			cout<<"Array:"<<endl;
			print_array(ar,n,e);

			cout<<fixed<<setprecision(2);
			cout<<"Answer: "<<sum_ar(ar,n)<<endl;

			
			string s;

			cout<<"Text file name: ";
			cin>>s;//спрашиваем имя файла

			array_infile(ar,n,s);
			delete[] ar;
			n=0;

			ar=array_outfile(n,s);

			cout<<fixed<<setprecision(1);
			cout<<"Array:"<<endl;
			print_array(ar,n,e);

			cout << "Binary file name: ";
			cin >> s;//спрашиваем имя файла
			array_inbinary(ar,n,s);

			delete[] ar;
			n=0;

			ar=array_outbinary(n,s);
			cout<<"Array:"<<endl;
			print_array(ar,n,e);
		}

		catch (const exception &error)
		{
			 cout<<error.what()<<endl;
		}
	}
}