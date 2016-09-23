/*
============================================================================
File          : benchmark_v1.cpp
Date          : Feb - 28 - 2016
Program name  : Benchmark in CLI
Version       : 0.0.3
Author        : ----
Enviroment    : CLI
Description   : A simple benchmarking program, only uses
basic operations, no reports to file, only console output
Notes         : revised in february 28
============================================================================
*/



#include "benchmarkv2.h"


//using namespace std;

#ifndef WINCONSOLE
#define WINCONSOLE 1
#endif

#ifndef NIXCONSOLE
#define NIXCONSOLE 0
#endif

// --------------------------------------------------------------------
int main(void)
{
	BenchMark bench;
	int option = 0;

#ifdef WINCONSOLE
	system("cls");
#endif

	cout << endl;
	cout << " This a simple benchmark routine for processors based on x86 instructions\n"
		<< " Choose an option :\n"
		<< " 1 - Standard run \n"
		<< " 2 - User limited run\n\n\n";
	cout << " > ";
	cin >> option;

	switch (option)
	{
	case 1:
		bench.standard_run();
		bench.save_results();

		break;
	case 2:
		cout << " Enter a number to run the tests. the greater the number\n"
			<< " The longer it will take to finish the test\n";
		unsigned long runs;
		cin >> runs;
		if (runs > 0)
		{
			bench.set_limits(runs);
			bench.start_custom_run();
			bench.save_results();
		}
		else
			cout << " Invalid input \n";
		break;

	default:
		bench.standard_run();
		break;
	}

	cout << endl;
	return 0;
}