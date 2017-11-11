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



// Normal Constructor
BenchMark::BenchMark()
{
	// Start up of all internal vars
	final_score = 0.0;

	sum_int_result = 0.1;
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

	block_loop = 0;
	internal_test_limits = 1000;
	object_id = ++id;

	for (unsigned i = 0; i < BENCH_SAVE_SLOTS; i++)
	{
		addtion_test_list[i] = 0;
		substrac_test_list[i] = 0;
		division_test_list[i] = 0;
		mult_test_list[i] = 0;
		add_float_list[i] = 0.0;
		sub_float_list[i] = 0.0;
		div_float_list[i] = 0.0;
		mul_float_list[i] = 0.0;
	}
	average_int_sum = 0;
	average_int_sub = 0;
	average_int_div = 0;
	average_int_mul = 0;


	average_decimal_sum =0.0;
	average_decimal_sub =0.0;
	average_decimal_div =0.0;
	average_decimal_mul =0.0;

	average_string =0.0;
	average_func  =0.0;
	average_prime = 0.0;
	index_control = 0;

	// Internal messges, must not change
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

	message[12] = " String ";
	message[13] = " Function call ";
	message[14] = " Prime numbers ";

}

enum the_tests
{
	add_int_test, sub_int_test, div_int_test, mult_int_test,
	add_dec_test, sub_dec_test, div_dec_test, mult_dec_test,
	str_test, func_test, prime_test, hanoi_test
};

int BenchMark::run_test(int testnameid, string msg)
{
	switch(testnameid)
	{
		case add_int_test:
			break;
		case sub_int_test:
			break;
		case div_int_test:
			break;
		case mult_int_test:
			break;
		case add_dec_test:
			break;
		case sub_dec_test:
			break;
		case div_dec_test:
			break;
		case mult_dec_test:
			break;
		case str_test:
			break;
		case func_test:
			break;
		case prime_test:
			break;
		case hanoi_test:
			break;
	}
}
// --------------------------------------------------------------------
int BenchMark::standard_run()// All tests
{
	cout << message[starting_test_msg] << endl;
	cout << endl;

	set_test_limits(_STANDARD_RUN_);
	set_block_limits(16);
	set_report_limits(16);

	unsigned i = 0;
	cout << message[int_add_msg] << " \n";
	for ( i = 0; i < block_loop; i++)
	{
		sum_int_test();
		average_int_sum += addtion_test_list[i];
	}
	average_int_sum = average_int_sum / block_loop;

	set_test_index(0);
	cout << message[int_sub_msg] << " \n";
	for ( i = 0; i < block_loop; i++)
	{
		substrac_test_list[i] = sub_int_test();
		average_int_sub += substrac_test_list[i];
	}
	average_int_sub = average_int_sub / block_loop;

	cout << message[int_div_msg] << " \n";
	for ( i = 0; i < block_loop; i++)
	{
		division_test_list[i] = div_int_test();
		average_int_div += division_test_list[i];
	}
	average_int_div = average_int_div / block_loop;

	cout << message[int_mul_msg] << " \n";
	for ( i = 0; i < block_loop; i++)
	{
		mult_test_list[i] = mul_int_test();
		average_int_mul += mult_test_list[i];
	}
	average_int_sub = average_int_sub / block_loop;

	// Start of floating point tests
	cout << message[dec_add_msg] << " \n";
	for ( i = 0; i < block_loop; i++)
	{
		add_float_list[i] = sum_decimal_test();
		average_decimal_sum += add_float_list[i];
	}
	average_decimal_sum = average_decimal_sum / block_loop;

	cout << message[dec_sub_msg] << " \n";
	for ( i = 0; i < block_loop; i++)
	{
		sub_float_list[i] = sub_decimal_test();
		average_decimal_sub += sub_float_list[i];
	}
	average_decimal_sub = average_decimal_sub / block_loop;

	cout << message[dec_div_msg] << " \n";
	for ( i = 0; i < block_loop; i++)
	{
		div_float_list[i] = div_decimal_test();
		average_decimal_div += div_float_list[i];
	}
	average_decimal_div = average_decimal_div / block_loop;

	cout << message[dec_mul_msg] << " \n";
	for ( i = 0; i < block_loop; i++)
	{
		mul_float_list[i] = mul_decimal_test();
		average_decimal_mul += mul_float_list[i];
	}
	average_decimal_mul = average_decimal_mul / block_loop;

	// Start of misc tests
	cout << message[str_msg] << " \n";
	for ( i = 0; i < block_loop; i++)
	{
		string_result_list[i] = string_test();
		average_string += string_result_list[i];
	}
	average_string = average_string / block_loop;

	cout << message[func_msg] << " \n";
	for ( i = 0; i < block_loop; i++)
	{
		function_result_list[i] = function_call_test();
		average_func += function_result_list[i];
	}
	average_func = average_func / block_loop;

	cout << message[prime_msg] << " \n";
	for ( i = 0; i < block_loop; i++)
	{
		prime_result_list[i] = prime_number_test();
		average_prime += prime_result_list[i];
	}
	average_prime = average_prime / block_loop;

	is_test_done = true;

	display_report(all);

	return 0;
}
// --------------------------------------------------------------------
int BenchMark:: start_custom_run()
{
	cout << message[starting_test_msg] << endl;
	cout << endl;

	set_block_limits(16);
	set_report_limits(16);

	unsigned i = 0;

	cout << message[int_add_msg] << " \n";
	for (i = 0; i < block_loop; i++)
	{
		addtion_test_list[i] = sum_int_test();
		average_int_sum += addtion_test_list[i];
	}
	average_int_sum = average_int_sum / block_loop;

	cout << message[int_sub_msg] << " \n";
	for (i = 0; i < block_loop; i++)
	{
		substrac_test_list[i] = sub_int_test();
		average_int_sub += substrac_test_list[i];
	}
	average_int_sub = average_int_sub / block_loop;

	cout << message[int_div_msg] << " \n";
	for (i = 0; i < block_loop; i++)
	{
		division_test_list[i] = div_int_test();
		average_int_div += division_test_list[i];
	}
	average_int_div = average_int_div / block_loop;

	cout << message[int_mul_msg] << " \n";
	for (i = 0; i < block_loop; i++)
	{
		mult_test_list[i] = mul_int_test();
		average_int_mul += mult_test_list[i];
	}
	average_int_sub = average_int_sub / block_loop;

	// Start of floating point tests
	cout << message[dec_add_msg] << " \n";
	for (i = 0; i < block_loop; i++)
	{
		add_float_list[i] = sum_decimal_test();
		average_decimal_sum += add_float_list[i];
	}
	average_decimal_sum = average_decimal_sum / block_loop;

	cout << message[dec_sub_msg] << " \n";
	for (i = 0; i < block_loop; i++)
	{
		sub_float_list[i] = sub_decimal_test();
		average_decimal_sub += sub_float_list[i];
	}
	average_decimal_sub = average_decimal_sub / block_loop;

	cout << message[dec_div_msg] << " \n";
	for (i = 0; i < block_loop; i++)
	{
		div_float_list[i] = div_decimal_test();
		average_decimal_div += div_float_list[i];
	}
	average_decimal_div = average_decimal_div / block_loop;

	cout << message[dec_mul_msg] << " \n";
	for (i = 0; i < block_loop; i++)
	{
		mul_float_list[i] = mul_decimal_test();
		average_decimal_mul += mul_float_list[i];
	}
	average_decimal_mul = average_decimal_mul / block_loop;

	// Start of misc tests
	cout << message[str_msg] << " \n";
	for (i = 0; i < block_loop; i++)
	{
		string_result_list[i] = string_test();
		average_string += string_result_list[i];
	}
	average_string = average_string / block_loop;

	cout << message[func_msg] << " \n";
	for (i = 0; i < block_loop; i++)
	{
		function_result_list[i] = function_call_test();
		average_func += function_result_list[i];
	}
	average_func = average_func / block_loop;

	cout << message[prime_msg] << " \n";
	for (i = 0; i < block_loop; i++)
	{
		prime_result_list[i] = prime_number_test();
		average_prime += prime_result_list[i];
	}
	average_prime = average_prime / block_loop;

	is_test_done = true;

	display_report(all);

	return 0;
}

// --------------------------------------------------------------------
double BenchMark::sum_int_test()	// add integer test
{
	long temp = 0;
	start_time = clock();
	for (long i = 0; i < internal_test_limits; ++i)
		temp += 1;
	end_time = clock();
	sum_int_result = (double) (end_time - start_time) / CLOCKS_PER_SEC;
	addtion_test_list[index_control++] = sum_int_result;
	return sum_int_result;
}
// --------------------------------------------------------------------
double BenchMark::sub_int_test()	// Substraction integer test
{
	long temp = 0;
	start_time = clock();
	for (long i = internal_test_limits; i > 0; --i)
		temp -= 1;
	end_time = clock();
	sub_int_result = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	return sub_int_result;
}
// --------------------------------------------------------------------
double BenchMark::div_int_test() 	// Division integer test
{
	long temp = 1;
	start_time = clock();
	for (long i = 0; i < internal_test_limits; ++i)
		temp /= 1;
	end_time = clock();
	div_int_result = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	return div_int_result;
}
// --------------------------------------------------------------------
double BenchMark::mul_int_test()
{
	long temp = 1;
	start_time = clock();
	for (long i = 0; i < internal_test_limits; ++i)
		temp *= i;
	end_time = clock();
	mul_int_result = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	return mul_int_result;
}
// --------------------------------------------------------------------
double BenchMark::sum_decimal_test()
{
	double temp = 0;
	start_time = clock();
	for (long i = 0; i < internal_test_limits; ++i)
		temp += 1.1;
	end_time = clock();
	sum_decimal_result = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	return sum_decimal_result;
}
// --------------------------------------------------------------------
double BenchMark::sub_decimal_test()
{
	double temp = 1;
	start_time = clock();
	for (long i = internal_test_limits; i > 0; --i)
		temp -= 1.1;
	end_time = clock();
	sub_decimal_result = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	return sub_decimal_result;
}
// --------------------------------------------------------------------
double BenchMark::div_decimal_test()
{
	double temp = 1;
	start_time = clock();
	for (long i = 0; i < internal_test_limits; ++i)
		temp /= 1.1;
	end_time = clock();
	div_decimal_result = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	return div_decimal_result;
}

// --------------------------------------------------------------------
double BenchMark::mul_decimal_test()
{
	double temp = 1.0;
	start_time = clock();
	for (long i = 0; i < internal_test_limits; ++i)
		temp *= i;
	end_time = clock();
	mul_decimal_result = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	return mul_decimal_result;
}
// --------------------------------------------------------------------
double BenchMark::string_test()
{
	char string1[10] = { 'a','a','a','a','a','a','a','a','\0' };
	char string2[10] = { 'a','b','c','d','e','f','g','h','\0' };
	start_time = clock();
	for (long i = 0; i < internal_test_limits; i++)
	{
		for (unsigned char temp = 0; temp< 8; temp++)
			string1[temp] = string2[temp];
	}
	end_time = clock();
	str_result = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	return str_result;
}
// --------------------------------------------------------------------
double BenchMark::function_call_test()
{
	start_time = clock();
	for (long i = 0; i < internal_test_limits; i++)
		foo();
	end_time = clock();
	func_result = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	return func_result;
}
// --------------------------------------------------------------------
double BenchMark::prime_number_test()
{
	long n = 1000;
	long prime = 0;
	start_time = clock();
	for (long i = 2; n > 0; ++i)
	{
		bool  isPrime = true;
		for (long j = 2; j < i; ++j)
		{
			if (i  % j == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
			--n;
			prime = i;
		}
	}
	end_time = clock();
	prime_result = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	return prime_result;
}
// --------------------------------------------------------------------
void BenchMark::save_results()
{
	int i = 0;
	// insert check if tests are done "íf"
	reportfile.open("bench_results.txt", ios::out | ios::app);
	if (reportfile.is_open())
	{
		switch (test_id)
		{
		case all:
			reportfile << endl;

			reportfile << message[int_add_msg] << setprecision(20) << average_int_sum << "\n";
			for (i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << addtion_test_list[i] << "\n";

			reportfile << message[int_sub_msg] << setprecision(20) << average_int_sub << "\n";
			for (i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << substrac_test_list[i] << "\n";

			reportfile << message[int_div_msg] << setprecision(20) << average_int_div << "\n";
			for (i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << division_test_list[i] << "\n";

			reportfile << message[int_mul_msg] << setprecision(20) << average_int_mul << "\n";
			for (i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << mult_test_list[i] << "\n";

			reportfile << endl;
			reportfile << message[dec_add_msg] << setprecision(20) << average_decimal_sum << "\n";
			for (i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << add_float_list[i] << "\n";

			reportfile << message[dec_sub_msg] << setprecision(20) << average_decimal_sub << "\n";
			for (i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sub_float_list[i] << "\n";

			reportfile << message[dec_div_msg] << setprecision(20) << average_decimal_div << "\n";
			for (i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << div_float_list[i] << "\n";

			reportfile << message[dec_mul_msg] << setprecision(20) << average_decimal_mul << "\n";
			for (i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << mul_float_list[i] << "\n";

			reportfile << endl;
			reportfile << message[str_msg] << setprecision(20) << average_string << "\n";
			for (i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << string_result_list[i] << "\n";

			reportfile << message[func_msg] << setprecision(20) << average_func << "\n";
			for (i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << function_result_list[i] << "\n";

			reportfile << message[prime_msg] << setprecision(20) << prime_result << "\n";
			for (i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << prime_result_list[i] << "\n";

			break;

		case integer_only:
			reportfile << endl;
			reportfile << message[int_add_msg] << setprecision(20) << average_int_sum << "\n";
			for (i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << addtion_test_list[i] << "\n";

			reportfile << message[int_sub_msg] << setprecision(20) << average_int_sub << "\n";
			for (i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << substrac_test_list[i] << "\n";

			reportfile << message[int_div_msg] << setprecision(20) << average_int_div << "\n";
			for (i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << division_test_list[i] << "\n";

			reportfile << message[int_mul_msg] << setprecision(20) << average_int_mul << "\n";
			for (i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << mult_test_list[i] << "\n";
			reportfile << endl;
			break;

		case float_only:
			reportfile << endl;
			reportfile << message[dec_add_msg] << setprecision(20) << average_decimal_sum << "\n";
			for (i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << add_float_list[i] << "\n";

			reportfile << message[dec_sub_msg] << setprecision(20) << average_decimal_sub << "\n";
			for (i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sub_float_list[i] << "\n";

			reportfile << message[dec_div_msg] << setprecision(20) << average_decimal_div << "\n";
			for (i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << div_float_list[i] << "\n";

			reportfile << message[dec_mul_msg] << setprecision(20) << average_decimal_mul << "\n";
			for (i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << mul_float_list[i] << "\n";
			reportfile << endl;
			break;

		case string_only:
			reportfile << message[str_msg] << setprecision(20) << average_string << "\n";
			for (i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << string_result_list[i] << "\n";
			break;

		case function_call_only:
			reportfile << message[func_msg] << setprecision(20) << average_func << "\n";
			for (i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << function_result_list[i] << "\n";
			break;

		default:
			break;
		}
		reportfile.close();
		is_report_done = true;
	}
	else
	{
		cout << endl << " Error on saving the results to a file" << endl;
	}
}
// --------------------------------------------------------------------
void BenchMark::display_report(int whose_test)
{
	int i = 0;

	if (is_report_done)
	{
		test_id = whose_test;
		switch (test_id)
		{
			case all:
				cout << endl;
				cout << message[result_msg] << endl;

				cout << message[int_add_msg] << setprecision(20) << average_int_sum << "\n";
				for (i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << addtion_test_list[i] << "\n";

				cout << message[int_sub_msg] << setprecision(20) << average_int_sub << "\n";
				for (i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << substrac_test_list[i] << "\n";

				cout << message[int_div_msg] << setprecision(20) << average_int_div << "\n";
				for (i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << division_test_list[i] << "\n";

				cout << message[int_mul_msg] << setprecision(20) << average_int_mul << "\n";
				for (i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << mult_test_list[i] << "\n";

				cout << endl;
				cout << message[dec_add_msg] << setprecision(20) << average_decimal_sum << "\n";
				for (i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << add_float_list[i] << "\n";

				cout << message[dec_sub_msg] << setprecision(20) << average_decimal_sub << "\n";
				for (i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sub_float_list[i] << "\n";

				cout << message[dec_div_msg] << setprecision(20) << average_decimal_div << "\n";
				for (i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << div_float_list[i] << "\n";

				cout << message[dec_mul_msg] << setprecision(20) << average_decimal_mul << "\n";
				for (i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << mul_float_list[i] << "\n";

				cout << endl;
				cout << message[str_msg] << setprecision(20) << average_string << "\n";
				for (i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << string_result_list[i] << "\n";

				cout << message[func_msg] << setprecision(20) << average_func << "\n";
				for (i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << function_result_list[i] << "\n";

				cout << message[prime_msg] << setprecision(20) << prime_result << "\n";
				for (i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << prime_result_list[i] << "\n";

				break;

			case integer_only:
				cout << endl;
				cout << message[int_add_msg] << setprecision(20) << average_int_sum << "\n";
				for (i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << addtion_test_list[i] << "\n";

				cout << message[int_sub_msg] << setprecision(20) << average_int_sub << "\n";
				for (i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << substrac_test_list[i] << "\n";

				cout << message[int_div_msg] << setprecision(20) << average_int_div << "\n";
				for (i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << division_test_list[i] << "\n";

				cout << message[int_mul_msg] << setprecision(20) << average_int_mul << "\n";
				for (i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << mult_test_list[i] << "\n";
				cout << endl;
				break;

			case float_only:
				cout << endl;
				cout << message[dec_add_msg] << setprecision(20) << average_decimal_sum << "\n";
				for (i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << add_float_list[i] << "\n";

				cout << message[dec_sub_msg] << setprecision(20) << average_decimal_sub << "\n";
				for (i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sub_float_list[i] << "\n";

				cout << message[dec_div_msg] << setprecision(20) << average_decimal_div << "\n";
				for (i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << div_float_list[i] << "\n";

				cout << message[dec_mul_msg] << setprecision(20) << average_decimal_mul << "\n";
				for (i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << mul_float_list[i] << "\n";
				cout << endl;
				break;

			case string_only:
				cout << message[str_msg] << setprecision(20) << average_string << "\n";
				for (i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << string_result_list[i] << "\n";
				break;

			case function_call_only:
				cout << message[func_msg] << setprecision(20) << average_func << "\n";
				for (i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << function_result_list[i] << "\n";
				break;

			default:
				break;
		 }


	}
	else
	{
		cout << " Report was not saved \n";
	}
}
// --------------------------------------------------------------------

// --------------------------------------------------------------------
void BenchMark::set_int_score(unsigned long score)
{
	the_int_score = score;
}
// --------------------------------------------------------------------
void BenchMark::set_float_score(double score)
{
	the_float_score = score;
}
void BenchMark::set_test_index(unsigned n)
{
	index_control = n;
}
void BenchMark::set_test_limits(unsigned n)
{
	internal_test_limits = n;
}
void BenchMark::set_block_limits(unsigned b)
{
	block_loop = b;
}
void BenchMark::set_report_limits(unsigned r)
{
	report_loop = r;
}
// --------------------------------------------------------------------
int BenchMark::get_id()
{
	return object_id;
}
// --------------------------------------------------------------------
unsigned long BenchMark::get_int_result()
{
	return the_int_score;
}
// --------------------------------------------------------------------
double BenchMark::get_float_result()
{
	return the_float_score;
}
// --------------------------------------------------------------------
void foo(void)
{
	// do something
}

// --------------------------------------------------------------------
void BenchMark::display_debug_messages(bool)
{
	//
}

