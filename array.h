// Автор: Деревцов Павел

///Заполнение массива а размером n случ числами от min до max
void random_array(float* a, unsigned n,float min,float max);

///вывод массива а размером n на экран по e элементов в строке
void print_array(const float* a, unsigned n, unsigned e);

///вычисление по формуле 2(а1+...+аn)^2 а-массив n-его размер
float sum_ar(float* a, unsigned n);

///запись размера и массива в файл name
void array_infile(float* a, unsigned n,std::string& name);
// todo: filename arg

///вывод массива из файла name. Размер массива-n, тоже записан в файл в первой строке
float* array_outfile(unsigned& n,std::string& name);

///запись массива a и размера n в бинарный файл с именем name
void array_inbinary(float* a, unsigned n,std::string& name);

///создание массива из бинарного файла name, размером n, который первый в файле
float* array_outbinary(unsigned& n,std::string& name);

