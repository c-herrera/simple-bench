/*
 ============================================================================
 	File          : benchmark_v1.cpp
	Date          : Feb - 28 - 2016
	Program name  : Benchmark in CLI
	Version       : 0.0.1
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

enum display_scores { all = 1, integer_only, float_only, string_only, function_call_only };

class BenchMark
{
private:
	double final_score;
	double sum_int_result;
	double sub_int_result;
	double div_int_result;
	double mul_int_result;
	
	double sum_decimal_result;
	double sub_decimal_result;
	double div_decimal_result;
	double mul_decimal_result;
	
	double str_result;
	double func_result;
	int object_id;
	string message[20];
	long limits;
	
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
	
	clock_t start_time;	// keeps the start time in each test
	clock_t end_time;	// keeps the end time for each test
	
public:
	
	
	BenchMark();
	
	int standard_run(); // standard run
	
	double sum_int_test();	// add integer test
	double sub_int_test();	// Substraction integer test
	double div_int_test(); // Division integer test
	double mul_int_test();
	
	double sum_decimal_test();
	double sub_decimal_test();
	double div_decimal_test();
	double mul_decimal_test();
	
	double string_test();
	double function_call_test();
	
	void save_results();
	void display_data(int );
	
	void set_limits(int );
	
};


void foo(void);  	



int main(void)
{
	BenchMark bench;
	int option = 0;
	
	cout << endl;
	cout << " This a simple benchmark routine for processors based on x86 instructions\n"
		<< " Choose an option :\n"
		<< " 1 - Standard run \n"
		<< " 2 - User limited run\n";
	cin >> option;
	
	switch(option)
	{
		case 1:
			bench.standard_run();
			bench.display_data(all);
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
	

	bench.display_data(all);
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
	limits = 1000;
	object_id = ++id;	
	message[0] = " The result for this run :\t";
	message[1] = " Starting all standard test \n";
	message[2] = " Save the results to a file?\n";
	message[3] = " Results saved !\n";
}

// --------------------------------------------------------------------
int BenchMark::standard_run()// All tests
{
	cout << message[1] << endl;
	cout << endl;
	limits = _STANDARD_RUN_;
	cout << " 1 - Integer Addition Test \n";
	for (int i = 0; i < 4; i++)
		sum_int_sum[i] = sum_int_test();
	for (int i = 0; i < 4; i++)
		cout << " Result of run " << i <<"\t" << sum_int_sum[i]<< "\n";
	
	cout << " 2 - Integer Substraction Test \n";
	for (int i = 0; i < 4; i++)
		sum_int_sub[i] = sub_int_test();
	for (int i = 0; i < 4; i++)
		cout << " Result of run " << i <<"\t" << sum_int_sub[i]<< "\n";
	
	cout << " 3 - Integer Division Test \n";
	for (int i = 0; i < 4; i++)
		sum_int_div[i] = div_int_test();
	for (int i = 0; i < 4; i++)
		cout << " Result of run " << i <<"\t" << sum_int_div[i]<< "\n";	
	
	cout << " 4 - Integer Multiplication Test \n";
	for (int i = 0; i < 4; i++)
		sum_int_mul[i] = mul_int_test();
	for (int i = 0; i < 4; i++)
		cout << " Result of run " << i <<"\t" << sum_int_mul[i] << "\n";			
	
	cout << " 5 - Float Addition Test \n";
	for (int i = 0; i < 4; i++)
		sum_decimal_sum[i] = sum_decimal_test();
	for (int i = 0; i < 4; i++)
		cout << " Result of run " << i <<"\t" << sum_decimal_sum[i] << "\n";
	
	cout << " 6 - Float Substraction Test \n";
	for (int i = 0; i < 4; i++)
		sum_decimal_sub[i] = sub_decimal_test();
	for (int i = 0; i < 4; i++)
		cout << " Result of run " << i <<"\t" << sum_decimal_sub[i] << "\n";
	
	cout << " 7 - Float Division Test \n";
	for (int i = 0; i < 4; i++)
		sum_decimal_div[i] = div_decimal_test();
	for (int i = 0; i < 4; i++)
		cout << " Result of run " << i <<"\t" << sum_decimal_div[i] << "\n";	
	
	cout << " 8 - Float Multiplication Test \n";
	for (int i = 0; i < 4; i++)
		sum_decimal_mul[i] = mul_decimal_test();
	for (int i = 0; i < 4; i++)
		cout << " Result of run " << i <<"\t" << sum_decimal_mul[i] << "\n";
	
	cout << " 9 - String Test \n";
	for (int i = 0; i < 4; i++)
		sum_string[i] = string_test();
	for (int i = 0; i < 4; i++)
		cout << " Result of run " << i <<"\t" << sum_string[i] << "\n";
	
	cout << " 10 Function Call Test \n";
	for (int i = 0; i < 4; i++)
		sum_func[i] = function_call_test();
	for (int i = 0; i < 4; i++)
		cout << " Result of run " << i <<"\t" << sum_func[i] << "\n";
	
	return 0;
}

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
	int temp = 8;
	start_time = clock();
	for (long i = 0; i < limits; i++)
	{
		while ( temp >= 0)
		{
			string1[temp] = string2[temp];
			temp--;
		}
		
		if (temp == 0)
			temp = 8;
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
void BenchMark::save_results()
{
	// TODO : save to file
}
// --------------------------------------------------------------------
void BenchMark::display_data(int w)
{
	switch(w)
	{
		case all:
			cout << endl;
			cout << message[result_msg] << endl;
			cout << message[int_add_msg] << setprecision(20) << sum_int_result << "\n";
			cout << message[int_sub_msg] << setprecision(20) << sub_int_result << "\n";
			cout << message[int_div_msg] << setprecision(20) << div_int_result << "\n";
			cout << message[int_mul_msg] << setprecision(20) << mul_int_result << "\n";
			cout << endl;
			cout << message[dec_add_msg] << setprecision(20) << sum_decimal_result << "\n";
			cout << message[dec_sub_msg] << setprecision(20) << sum_decimal_result << "\n";
			cout << message[dec_div_msg] << setprecision(20) << sum_decimal_result << "\n";
			cout << message[dec_mul_msg] << setprecision(20) << sum_decimal_result << "\n";
			cout << endl;
			cout << message[str_msg] << setprecision(20) << str_result << "\n";
			cout << message[func_msg] << setprecision(20) << func_result << "\n";
		break;
		
		case integer_only:
			cout << endl;
			cout << message[result_msg] << endl;
			cout << message[int_add_msg] << setprecision(20) << sum_int_result << "\n";
			cout << message[int_sub_msg] << setprecision(20) << sub_int_result << "\n";
			cout << message[int_div_msg] << setprecision(20) << div_int_result << "\n";
			cout << message[int_mul_msg] << setprecision(20) << mul_int_result << "\n";
			cout << endl;			
		break;
		
		float_only:
			cout << endl;
			cout << message[dec_add_msg] << setprecision(20) << sum_decimal_result << "\n";
			cout << message[dec_sub_msg] << setprecision(20) << sum_decimal_result << "\n";
			cout << message[dec_div_msg] << setprecision(20) << sum_decimal_result << "\n";
			cout << message[dec_mul_msg] << setprecision(20) << sum_decimal_result << "\n";
			cout << endl;
		break;
		
		string_only:
			cout << message[str_msg] << setprecision(20) << str_result << "\n";
		break;
		
		function_call_only:
			cout << message[func_msg] << setprecision(20) << func_result << "\n";
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
