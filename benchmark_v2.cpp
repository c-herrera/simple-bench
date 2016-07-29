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

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#ifdef __MS_DOS__
#include <conio.h>
#endif

using namespace std;

#define _BENCH_DEBUG_ 	0
#define _STANDARD_RUN_	1024 * 1024
#define _LONG_RUN_  	1024 * 1024 * 1024


#define _ERROR_ 	2
#define _SUCCESS_	3

static int id;

enum display_scores
{ all = 1, integer_only, float_only, string_only, function_call_only };


// commit : 009edbad394b34bf48e8bfcdb2d382d2fb6aba64
//  25 additions and 4 deletions.
enum the_messages
{
	result_msg = 0, starting_test_msg, save_msg, saved_msg,
	int_add_msg, int_sub_msg, int_div_msg, int_mul_msg,
	dec_add_msg, dec_sub_msg, dec_div_msg, dec_mul_msg,
	str_msg, func_msg, prime_msg
};

class BenchMark
{
private:
	// vars to hold results

	double final_score;

	// these hold the result of integer tests
	double sum_int_result;
	double sub_int_result;
	double div_int_result;
	double mul_int_result;

	//these hold the result of floating point tests
	double sum_decimal_result;
	double sub_decimal_result;
	double div_decimal_result;
	double mul_decimal_result;

	// these hold other tipe of results
	double str_result;
	double func_result;
	double prime_result;

	// these hold all of the results of test, individually
	// then at the end, they are used to get an average
	double sum_int_sum[12];
	double sum_int_sub[12];
	double sum_int_div[12];
	double sum_int_mul[12];

	double sum_decimal_sum[12];
	double sum_decimal_sub[12];
	double sum_decimal_div[12];
	double sum_decimal_mul[12];


	double sum_string[12];
	double sum_func[12];
	double sum_prime[12];

	// the hold all the average computed from the vars above
	double average_int_sum;
	double average_int_sub;
	double average_int_div;
	double average_int_mul;


	double average_decimal_sum;
	double average_decimal_sub;
	double average_decimal_div;
	double average_decimal_mul;

	double average_string;
	double average_func;
	double average_prime;

	// internal keeping
	clock_t start_time;	// keeps the start time in each test
	clock_t end_time;	// keeps the end time for each test

	int object_id;  	// we may want more of one
	string message[24];	// message var array with standar info
	long limits;    	// limit var for several tests
	unsigned test_loop; // internal loop var, limited.
	ofstream reportfile;
	int test_id;

public:


	BenchMark();

	int standard_run(); // standard run

	// To run a test individually, o can use the
	// standard_run
	// Integer test are different from floating point
	double sum_int_test();	// add integer test
	double sub_int_test();	// Substraction integer test
	double div_int_test();	// Division integer test
	double mul_int_test();	// multiplication integer test

	double sum_decimal_test();
	double sub_decimal_test();
	double div_decimal_test();
	double mul_decimal_test();

	// Misc test that will be added or removed as it fits
	double string_test();
	double function_call_test();
	double prime_number_test();

	// Methods to save and display the results
	void save_results();
	void display_report(int );

	void set_limits(int );
	int get_id();


};
// --------------------------------------------------------------------

void foo(void);


// --------------------------------------------------------------------
int main(void)
{
	BenchMark bench;
	int option = 0;

	cout << endl;
	cout << " This a simple benchmark routine for processors based on x86 instructions\n"
		<< " Choose an option :\n"
		<< " 1 - Standard run \n"
		<< " 2 - User limited run\n";
	cout << " > ";
	cin >> option;

	switch(option)
	{
		case 1:
			bench.standard_run();
			bench.save_results();

		break;
		case 2:
			cout << " Enter a number to run the tests. the greater the number\n"
				<< " The longer it will take to finish the test\n";
			int runs;
			cin >> runs;
			bench.set_limits(runs);
			//bench.start_test();
		break;

		default:
			bench.standard_run();
		break;
	}
	cout << endl;
	return 0;
}
// --------------------------------------------------------------------
BenchMark::BenchMark()
{
	final_score = 0.0;

	sum_int_result = 0.0;
	sub_int_result = 0.0;
	div_int_result = 0.0;
	mul_int_result = 0.0;

	sum_decimal_result = 0.0;
	sub_decimal_result = 0.0;
	div_decimal_result = 0.0;
	mul_decimal_result = 0.0;

	str_result = 0.0;
	func_result = 0.0;
	prime_result = 0.0;

	test_loop = 0;
	limits = 1000;
	object_id= ++id;

	message[0] = " The result of loop :\t";
	message[1] = " Starting tests ... \n";
	message[2] = " Save the results to a file?\n";
	message[3] = " Results saved !\n";
	message[4] = " Integer addition ";
	message[5] = " Integer substraction ";
	message[6] = " Integer division ";
	message[7] = " Integer multiplication ";

	message[8] = " Float addition ";
	message[9] = " Float substraction ";
	message[10] = " Float division ";
	message[11] = " Float multiplication ";

	message[12] = " String " ;
	message[13] = " Function call ";
	message[14] = " Prime numbers ";
}

// --------------------------------------------------------------------
int BenchMark::standard_run()// All tests
{
	cout << message[starting_test_msg] << endl;
	cout << endl;
	test_loop = 4;
	limits = _STANDARD_RUN_;
	cout << message [int_add_msg] << " \n";
	for (int i = 0; i < test_loop; i++)
	{
		sum_int_sum[i] = sum_int_test();
		average_int_sum += sum_int_sum[i];
	}
	average_int_sum = average_int_sum / test_loop;

	cout << message[int_sub_msg] << " \n";
	for (int i = 0; i < test_loop; i++)
	{
		sum_int_sub[i] = sub_int_test();
		average_int_sub += sum_int_sub[i];
	}
	average_int_sub = average_int_sub / test_loop;

	cout << message[int_div_msg] << " \n";
	for (int i = 0; i < test_loop; i++)
	{
		sum_int_div[i] = div_int_test();
		average_int_div += sum_int_div[i];
	}
	average_int_div = average_int_div / test_loop;

	cout << message[int_mul_msg] << " \n";
	for (int i = 0; i < test_loop; i++)
	{
		sum_int_mul[i] = mul_int_test();
		average_int_mul += sum_int_mul[i];
	}
	average_int_sub = average_int_sub / test_loop;

	// Start of floating point tests
	cout << message[dec_add_msg] << " \n";
	for (int i = 0; i < test_loop; i++)
	{
		sum_decimal_sum[i] = sum_decimal_test();
		average_decimal_sum += sum_decimal_sum[i];
	}
	average_decimal_sum = average_decimal_sum / test_loop;

	cout << message[dec_sub_msg] << " \n";
	for (int i = 0; i < test_loop; i++)
	{
		sum_decimal_sub[i] = sub_decimal_test();
		average_decimal_sub += sum_decimal_sub[i];
	}
	average_decimal_sub = average_decimal_sub / test_loop;

	cout << message[dec_div_msg] << " \n";
	for (int i = 0; i < test_loop; i++)
	{
		sum_decimal_div[i] = div_decimal_test();
		average_decimal_div += sum_decimal_div[i];
	}
	average_decimal_div = average_decimal_div / test_loop;

	cout << message[dec_mul_msg] << " \n";
	for (int i = 0; i < test_loop; i++)
	{
		sum_decimal_mul[i] = mul_decimal_test();
		average_decimal_mul += sum_decimal_mul[i];
	}
	average_decimal_mul = average_decimal_mul / test_loop;

	// Start of misc tests
	cout << message[str_msg] << " \n";
	for (int i = 0; i < test_loop; i++)
	{
		sum_string[i] = string_test();
		average_string += sum_string[i];
	}
	average_string = average_string / test_loop;

	cout << message[func_msg] << " \n";
	for (int i = 0; i < test_loop; i++)
	{
		sum_func[i] = function_call_test();
		average_func += sum_func[i];
	}
	average_func = average_func / test_loop;

	cout << message[prime_msg] << " \n";
	for (int i = 0; i < test_loop; i++)
	{
		sum_prime[i] = prime_number_test();
		average_prime += sum_prime[i];
	}
	average_prime = average_prime / test_loop;

	display_report(all);

	return 0;
}
// --------------------------------------------------------------------
/*int BenchMark::standard_run()
{
	
}*/

// --------------------------------------------------------------------
double BenchMark::sum_int_test()	// add integer test
{
	long temp= 0;
	start_time = clock();
	for (long i = 0; i < limits; ++i)
		temp += 1;
	end_time = clock();
	sum_int_result = ( (double)end_time - (double)start_time)/CLOCKS_PER_SEC;
	return sum_int_result;
}
// --------------------------------------------------------------------
double BenchMark::sub_int_test()	// Substraction integer test
{
	long temp = 0;
	start_time = clock();
	for (long i = limits; i > 0; --i)
		temp -= 1;
	end_time = clock();
	sub_int_result = ( (double)end_time - (double)start_time)/CLOCKS_PER_SEC;
	return sub_int_result;	
}
// --------------------------------------------------------------------
double BenchMark::div_int_test() 	// Division integer test
{
	long temp = 1;
	start_time = clock();
	for (long i = 0; i < limits; ++i)
		temp /= 1;
	end_time = clock();
	div_int_result = ( (double)end_time - (double)start_time)/CLOCKS_PER_SEC;
	return div_int_result;		
}
// --------------------------------------------------------------------
double BenchMark::mul_int_test()
{
	long temp = 1;
	start_time = clock();
	for (long i = 0; i < limits; ++i)
		temp *= i;
	end_time = clock();
	mul_int_result = ( (double)end_time - (double)start_time)/CLOCKS_PER_SEC;
	return mul_int_result;		
}
// --------------------------------------------------------------------
double BenchMark::sum_decimal_test()
{
	long temp = 0;
	start_time = clock();
	for (long i = 0; i < limits; ++i)
		temp += 1.1;
	end_time = clock();
	sum_decimal_result = ( (double)end_time - (double)start_time)/CLOCKS_PER_SEC;
	return sum_decimal_result;		
}
// --------------------------------------------------------------------
double BenchMark::sub_decimal_test()
{
	long temp = 1;
	start_time = clock();
	for (long i = limits; i > 0; --i)
		temp -= 1.1;
	end_time = clock();
	sub_decimal_result = ( (double)end_time - (double)start_time)/CLOCKS_PER_SEC;
	return sub_decimal_result;			
}
// --------------------------------------------------------------------
double BenchMark::div_decimal_test()
{
	long temp = 1;
	start_time = clock();
	for (long i = 0; i < limits; ++i)
		temp /= 1.1;
	end_time = clock();
	div_decimal_result = ( (double)end_time - (double)start_time)/CLOCKS_PER_SEC;
	return div_decimal_result;			
}

// --------------------------------------------------------------------
double BenchMark::mul_decimal_test()
{
	double temp = 1.0;
	start_time = clock();
	for (long i = 0; i < limits; ++i)
		temp *= i;
	end_time = clock();
	mul_decimal_result = ( (double)end_time - (double)start_time)/CLOCKS_PER_SEC;
	return mul_decimal_result;			
}
// --------------------------------------------------------------------
double BenchMark::string_test()
{
	char string1[10] = {'a','a','a','a','a','a','a','a','\0'};
	char string2[10] = {'a','b','c','d','e','f','g','h','\0'};
	start_time = clock();
	for (long i = 0; i < limits; i++)
	{
		for (unsigned char temp = 0; temp< 8; temp++)
			string1[temp] = string2[temp];
	}
	end_time = clock();
	str_result = ( (double)end_time - (double)start_time)/CLOCKS_PER_SEC;

	return str_result;  
}
// --------------------------------------------------------------------
double BenchMark::function_call_test()
{
	start_time = clock();
	for (long i=0; i < limits; i++)
		foo();
	end_time = clock();
	func_result = ( (double)end_time - (double)start_time)/CLOCKS_PER_SEC;
	
	return func_result;  
}
// --------------------------------------------------------------------
double BenchMark::prime_number_test()
{
	long n = 1000;
	long prime = 0;
	start_time = clock();
	for (long  i = 2;n > 0; ++i)
	{
		bool  isPrime  =  true;
		for (long  j =  2;  j < i;  ++j)
		{
			if (i  % j ==  0)
			{
				isPrime  =  false ;
				break ;
			}
		}
		if (isPrime)
		{
			--n;
			prime =  i;
		}
	}
	end_time = clock();
	prime_result = ( (double)end_time - (double)start_time)/CLOCKS_PER_SEC;
	return prime_result;
}
// --------------------------------------------------------------------
void BenchMark::save_results()
{
	// TODO : save to file
}
// --------------------------------------------------------------------
void BenchMark::display_report(int w)
{
	switch(w)
	{
		case all:
			cout << endl;
			cout << message[result_msg] << endl;

			cout << message[int_add_msg] << setprecision(20) << average_int_sum << "\n";
			for (int i = 0; i < 4; i++)
				cout << message[result_msg] << i <<"\t" << sum_int_sum[i]<< "\n";

			cout << message[int_sub_msg] << setprecision(20) << average_int_sub << "\n";
			for (int i = 0; i < 4; i++)
				cout << message[result_msg] << i <<"\t" << sum_int_sub[i]<< "\n";

			cout << message[int_div_msg] << setprecision(20) << average_int_div << "\n";
			for (int i = 0; i < 4; i++)
				cout << message[result_msg] << i <<"\t" << sum_int_div[i]<< "\n";

			cout << message[int_mul_msg] << setprecision(20) << average_int_mul << "\n";
			for (int i = 0; i < 4; i++)
				cout << message[result_msg] << i <<"\t" << sum_int_mul[i] << "\n";

			cout << endl;
			cout << message[dec_add_msg] << setprecision(20) << average_decimal_sum << "\n";
			for (int i = 0; i < 4; i++)
				cout << message[result_msg] << i <<"\t" << sum_decimal_sum[i] << "\n";

			cout << message[dec_sub_msg] << setprecision(20) << average_decimal_sub << "\n";
			for (int i = 0; i < 4; i++)
				cout << message[result_msg] << i <<"\t" << sum_decimal_sub[i] << "\n";

			cout << message[dec_div_msg] << setprecision(20) << average_decimal_div << "\n";
			for (int i = 0; i < 4; i++)
				cout << message[result_msg] << i <<"\t" << sum_decimal_div[i] << "\n";

			cout << message[dec_mul_msg] << setprecision(20) << average_decimal_mul << "\n";
			for (int i = 0; i < 4; i++)
				cout << message[result_msg] << i <<"\t" << sum_decimal_mul[i] << "\n";

			cout << endl;
			cout << message[str_msg] << setprecision(20) << average_string << "\n";
			for (int i = 0; i < 4; i++)
				cout << message[result_msg] << i <<"\t" << sum_string[i] << "\n";

			cout << message[func_msg] << setprecision(20) << average_func << "\n";
			for (int i = 0; i < 4; i++)
				cout << message[result_msg] << i <<"\t" << sum_func[i] << "\n";

			cout << message[prime_msg] << setprecision(20) << prime_result << "\n";
			for (int i = 0; i < 4; i++)
				cout << message[result_msg] << i <<"\t" << sum_prime[i] << "\n";

		break;

		case integer_only:
			cout << endl;
			cout << message[int_add_msg] << setprecision(20) << average_int_sum << "\n";
			for (int i = 0; i < 4; i++)
				cout << message[result_msg] << i <<"\t" << sum_int_sum[i]<< "\n";

			cout << message[int_sub_msg] << setprecision(20) << average_int_sub << "\n";
			for (int i = 0; i < 4; i++)
				cout << message[result_msg] << i <<"\t" << sum_int_sub[i]<< "\n";

			cout << message[int_div_msg] << setprecision(20) << average_int_div << "\n";
			for (int i = 0; i < 4; i++)
				cout << message[result_msg] << i <<"\t" << sum_int_div[i]<< "\n";

			cout << message[int_mul_msg] << setprecision(20) << average_int_mul << "\n";
			for (int i = 0; i < 4; i++)
				cout << message[result_msg] << i <<"\t" << sum_int_mul[i] << "\n";
			cout << endl;
		break;

		float_only:
			cout << endl;
			cout << message[dec_add_msg] << setprecision(20) << average_decimal_sum << "\n";
			for (int i = 0; i < 4; i++)
				cout << message[result_msg] << i <<"\t" << sum_decimal_sum[i] << "\n";

			cout << message[dec_sub_msg] << setprecision(20) << average_decimal_sub << "\n";
			for (int i = 0; i < 4; i++)
				cout << message[result_msg] << i <<"\t" << sum_decimal_sub[i] << "\n";

			cout << message[dec_div_msg] << setprecision(20) << average_decimal_div << "\n";
			for (int i = 0; i < 4; i++)
				cout << message[result_msg] << i <<"\t" << sum_decimal_div[i] << "\n";

			cout << message[dec_mul_msg] << setprecision(20) << average_decimal_mul << "\n";
			for (int i = 0; i < 4; i++)
				cout << message[result_msg] << i <<"\t" << sum_decimal_mul[i] << "\n";
			cout << endl;
		break;

		string_only:
			cout << message[str_msg] << setprecision(20) << average_string << "\n";
			for (int i = 0; i < 4; i++)
				cout << message[result_msg] << i <<"\t" << sum_string[i] << "\n";
		break;

		function_call_only:
			cout << message[func_msg] << setprecision(20) << average_func << "\n";
			for (int i = 0; i < 4; i++)
				cout << message[result_msg] << i <<"\t" << sum_func[i] << "\n";
		break;

		default:
		break;

	}
}
// --------------------------------------------------------------------
void BenchMark::set_limits(int t)
{
	limits = t;
}
// --------------------------------------------------------------------

void foo (void)
{
	// do something    
}

// --------------------------------------------------------------------

