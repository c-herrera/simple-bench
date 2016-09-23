#pragma once

#define _BENCH_DEBUG_ 	0
#define _STANDARD_RUN_	1024 * 1024
#define _LONG_RUN_  	1024 * 1024 * 1024


#define _ERROR_ 	2
#define _SUCCESS_	3

static int id;

enum display_scores
{
	all = 1, integer_only, float_only, string_only, function_call_only
};


// commit : 009edbad394b34bf48e8bfcdb2d382d2fb6aba64
//  25 additions and 4 deletions.
enum the_messages
{
	result_msg = 0, starting_test_msg, save_msg, saved_msg,
	int_add_msg, int_sub_msg, int_div_msg, int_mul_msg,
	dec_add_msg, dec_sub_msg, dec_div_msg, dec_mul_msg,
	str_msg, func_msg, prime_msg
};

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <fstream>
#ifdef __MS_DOS__
#include <conio.h>
#endif


#ifndef __BENCHMARK_H__
#define __BENCHMARK_H__

#define BENCH_SAVE_SLOTS 32

using namespace std;

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
	double sum_int_sum[BENCH_SAVE_SLOTS];
	double sum_int_sub[BENCH_SAVE_SLOTS];
	double sum_int_div[BENCH_SAVE_SLOTS];
	double sum_int_mul[BENCH_SAVE_SLOTS];

	double sum_decimal_sum[BENCH_SAVE_SLOTS];
	double sum_decimal_sub[BENCH_SAVE_SLOTS];
	double sum_decimal_div[BENCH_SAVE_SLOTS];
	double sum_decimal_mul[BENCH_SAVE_SLOTS];


	double sum_string[BENCH_SAVE_SLOTS];
	double sum_func[BENCH_SAVE_SLOTS];
	double sum_prime[BENCH_SAVE_SLOTS];

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
	long limits;    	// limit var for several tests
	unsigned test_loop; // internal loop var, limited.
	unsigned block_loop;	// limits the loop per test block
	unsigned report_loop;	// used to save all the result from the loop
	bool is_bench_done;		// is the benchmark done?
	bool is_report_done;	// is the report done ?
	bool is_report_saved;	// is the report saved?
	bool is_test_done;		// is the test done?
	unsigned long the_int_score;
	double the_float_score;
	int test_id;
	ofstream reportfile;
	string message[24];	// message var array with standar info

public:


	BenchMark();

	int standard_run(); // standard run
	int start_custom_run();

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
	void display_report(int);

	void set_limits(int);
	int get_id();


};
// --------------------------------------------------------------------

#endif __BENCHMARK_H__

void foo(void);
