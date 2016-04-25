// Projekt---Power-Virus-CPU-i7.cpp : Defines the entry point for the console application.
//
#define _USE_MATH_DEFINES

#include "stdafx.h"

using std::cout;
using std::endl;
using std::vector;

/* Naive reference computation functions */

static void naiveDft(const vector<double> &inreal, const vector<double> &inimag, vector<double> &outreal, vector<double> &outimag, bool inverse) {
	int n = inreal.size();
	double coef = (inverse ? 2 : -2) * M_PI;
	for (int k = 0; k < n; k++) {  // For each output element
		double sumreal = 0;
		double sumimag = 0;
		for (int t = 0; t < n; t++) {  // For each input element
			double angle = coef * ((long long)t * k % n) / n;
			sumreal += inreal[t] * cos(angle) - inimag[t] * sin(angle);
			sumimag += inreal[t] * sin(angle) + inimag[t] * cos(angle);
		}
		outreal[k] = sumreal;
		outimag[k] = sumimag;
	}
}
static void randomReals(vector<double> &vec) {
	for (vector<double>::iterator it = vec.begin(); it != vec.end(); ++it)
		*it = (rand() / (RAND_MAX + 1.0)) * 2 - 1;
}
static void testFft(int n) {
	vector<double> inputreal(n);
	vector<double> inputimag(n);
	randomReals(inputreal);
	randomReals(inputimag);

	vector<double> refoutreal(n);
	vector<double> refoutimag(n);
	naiveDft(inputreal, inputimag, refoutreal, refoutimag, false);

	vector<double> actualoutreal(inputreal);
	vector<double> actualoutimag(inputimag);
	Fft::transform(actualoutreal, actualoutimag);

}


void test()
{
	const long double a = 434343.435354;
	register long long int  c = 5434, b = 555;
	long long int  f = 0, g = 2, h = 5, p = 7, k = 4, l = 0, m = 3, n = 2, o = 6;

	long long int *tab = new long long int[2343243];
	for (int i = 0; i < 2343243; i++)
	{
		tab[i] = i;
	}
	while (1)
	{
		//ALU operations
		f = g + h;
		p = k + l;
		m = n + o;
		//store_data long double data value in memory
		tab[23] = a;
		//store_addr value from register in memory
		tab[56555] = b;
		tab[4] = c;
		// Test small size FFTs
		/*for (int i = 0; i < _MAX_INT_DIG; i++)
		{
		testFft(i);
		}*/
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::thread *thread_tab = new std::thread[8];
	for (int i = 0; i < NUM_OF_CORES; i++)
	{
		thread_tab[i] = std::thread(test);
		std::cout << "Startuje watek: " << i << std::endl;
	}
	for (int i = 0; i < NUM_OF_CORES; i++)
	{
		//czekamy, a¿ w¹tki przestan¹ pracowaæ - umr¹, nastêpuje ich synchronizacja
		thread_tab[i].join();
	}
	delete[] thread_tab;
	return 0;
}
