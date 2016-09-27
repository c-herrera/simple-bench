/*
============================================================================
	File          : benchmark_v1.cpp
	Date          : Feb - 28 - 2016
	Program name  : Benchmark in CLI
	Version       : 0.0.4
	Author        : ----
	Enviroment    : CLI
	Description   : A simple benchmarking program, only uses
	basic operations, no reports to file, only console output
	Notes         : revised in february 28
============================================================================
*/



#include "benchmark.h"


//using namespace std;

#ifndef _PROGRAM_VERSION_
#define _PROGRAM_VERSION_ "0.0.4"
#endif


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

#if WINCONSOLE
	system("cls");
#endif

#if NIXCONSOLE
	system("clear");
#endif


	cout << endl;
	for (int i=0; i < 72; i++)
		cout << "=";
	cout << endl;
	cout << " This a simple benchmark routine for processors based on x86 instructions\n"
		<< " Current version is " << _PROGRAM_VERSION_ << "\n"
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
			for (int i=0; i < 72; i++)
				cout << "=";
			cout << endl;
			cout << " Enter a number to run the tests. the greater the number\n"
				<< " The longer it will take to finish the test\n";
			unsigned long runs;
			cin >> runs;
			if (runs > 0 || runs > 1000)
			{
				bench.set_test_limits_to(runs);
				bench.start_custom_run();
				bench.save_results();
			}
			else
				cout << " Invalid input or too short to set a bench run \n";
			break;

		default:
			bench.standard_run();
			break;
	}

	cout << endl;
	return 0;
}
