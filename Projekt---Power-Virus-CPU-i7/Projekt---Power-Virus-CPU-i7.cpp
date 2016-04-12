// Projekt---Power-Virus-CPU-i7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <thread>
#include <iostream>
#include <windows.h>
#include <random>

#define NUM_OF_CORES 8

void test()
{
	long double c = 0.0, a = 3.5434, b = 43.2322, d = 0.4, e = 0.0;
	int f = 0, g = 2, h = 5;
	for (int i = 0; i < 1000000000000; i++)
	{
		//fdiv
		c = a / b;
		//fadd
		e = a + b;
		//ALU div
		f = h / g;
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
