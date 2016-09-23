#include "benchmarkv2.h"




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
	object_id = ++id;

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

// --------------------------------------------------------------------
int BenchMark::standard_run()// All tests
{
	cout << message[starting_test_msg] << endl;
	cout << endl;
	test_loop = 16;
	report_loop = test_loop;
	block_loop = test_loop;
	unsigned i = 0;
	limits = _STANDARD_RUN_;
	cout << message[int_add_msg] << " \n";
	for ( i = 0; i < test_loop; i++)
	{
		sum_int_sum[i] = sum_int_test();
		average_int_sum += sum_int_sum[i];
	}
	average_int_sum = average_int_sum / test_loop;

	cout << message[int_sub_msg] << " \n";
	for ( i = 0; i < test_loop; i++)
	{
		sum_int_sub[i] = sub_int_test();
		average_int_sub += sum_int_sub[i];
	}
	average_int_sub = average_int_sub / test_loop;

	cout << message[int_div_msg] << " \n";
	for ( i = 0; i < test_loop; i++)
	{
		sum_int_div[i] = div_int_test();
		average_int_div += sum_int_div[i];
	}
	average_int_div = average_int_div / test_loop;

	cout << message[int_mul_msg] << " \n";
	for ( i = 0; i < test_loop; i++)
	{
		sum_int_mul[i] = mul_int_test();
		average_int_mul += sum_int_mul[i];
	}
	average_int_sub = average_int_sub / test_loop;

	// Start of floating point tests
	cout << message[dec_add_msg] << " \n";
	for ( i = 0; i < test_loop; i++)
	{
		sum_decimal_sum[i] = sum_decimal_test();
		average_decimal_sum += sum_decimal_sum[i];
	}
	average_decimal_sum = average_decimal_sum / test_loop;

	cout << message[dec_sub_msg] << " \n";
	for ( i = 0; i < test_loop; i++)
	{
		sum_decimal_sub[i] = sub_decimal_test();
		average_decimal_sub += sum_decimal_sub[i];
	}
	average_decimal_sub = average_decimal_sub / test_loop;

	cout << message[dec_div_msg] << " \n";
	for ( i = 0; i < test_loop; i++)
	{
		sum_decimal_div[i] = div_decimal_test();
		average_decimal_div += sum_decimal_div[i];
	}
	average_decimal_div = average_decimal_div / test_loop;

	cout << message[dec_mul_msg] << " \n";
	for ( i = 0; i < test_loop; i++)
	{
		sum_decimal_mul[i] = mul_decimal_test();
		average_decimal_mul += sum_decimal_mul[i];
	}
	average_decimal_mul = average_decimal_mul / test_loop;

	// Start of misc tests
	cout << message[str_msg] << " \n";
	for ( i = 0; i < test_loop; i++)
	{
		sum_string[i] = string_test();
		average_string += sum_string[i];
	}
	average_string = average_string / test_loop;

	cout << message[func_msg] << " \n";
	for ( i = 0; i < test_loop; i++)
	{
		sum_func[i] = function_call_test();
		average_func += sum_func[i];
	}
	average_func = average_func / test_loop;

	cout << message[prime_msg] << " \n";
	for ( i = 0; i < test_loop; i++)
	{
		sum_prime[i] = prime_number_test();
		average_prime += sum_prime[i];
	}
	average_prime = average_prime / test_loop;

	is_test_done = true;

	display_report(all);

	return 0;
}
// --------------------------------------------------------------------
int BenchMark:: start_custom_run()
{
	cout << message[starting_test_msg] << endl;
	cout << endl;
	test_loop = 16;
	report_loop = test_loop;
	block_loop = test_loop;
	unsigned i = 0;
	limits = limits;
	cout << message[int_add_msg] << " \n";
	for (i = 0; i < test_loop; i++)
	{
		sum_int_sum[i] = sum_int_test();
		average_int_sum += sum_int_sum[i];
	}
	average_int_sum = average_int_sum / test_loop;

	cout << message[int_sub_msg] << " \n";
	for (i = 0; i < test_loop; i++)
	{
		sum_int_sub[i] = sub_int_test();
		average_int_sub += sum_int_sub[i];
	}
	average_int_sub = average_int_sub / test_loop;

	cout << message[int_div_msg] << " \n";
	for (i = 0; i < test_loop; i++)
	{
		sum_int_div[i] = div_int_test();
		average_int_div += sum_int_div[i];
	}
	average_int_div = average_int_div / test_loop;

	cout << message[int_mul_msg] << " \n";
	for (i = 0; i < test_loop; i++)
	{
		sum_int_mul[i] = mul_int_test();
		average_int_mul += sum_int_mul[i];
	}
	average_int_sub = average_int_sub / test_loop;

	// Start of floating point tests
	cout << message[dec_add_msg] << " \n";
	for (i = 0; i < test_loop; i++)
	{
		sum_decimal_sum[i] = sum_decimal_test();
		average_decimal_sum += sum_decimal_sum[i];
	}
	average_decimal_sum = average_decimal_sum / test_loop;

	cout << message[dec_sub_msg] << " \n";
	for (i = 0; i < test_loop; i++)
	{
		sum_decimal_sub[i] = sub_decimal_test();
		average_decimal_sub += sum_decimal_sub[i];
	}
	average_decimal_sub = average_decimal_sub / test_loop;

	cout << message[dec_div_msg] << " \n";
	for (i = 0; i < test_loop; i++)
	{
		sum_decimal_div[i] = div_decimal_test();
		average_decimal_div += sum_decimal_div[i];
	}
	average_decimal_div = average_decimal_div / test_loop;

	cout << message[dec_mul_msg] << " \n";
	for (i = 0; i < test_loop; i++)
	{
		sum_decimal_mul[i] = mul_decimal_test();
		average_decimal_mul += sum_decimal_mul[i];
	}
	average_decimal_mul = average_decimal_mul / test_loop;

	// Start of misc tests
	cout << message[str_msg] << " \n";
	for (i = 0; i < test_loop; i++)
	{
		sum_string[i] = string_test();
		average_string += sum_string[i];
	}
	average_string = average_string / test_loop;

	cout << message[func_msg] << " \n";
	for (i = 0; i < test_loop; i++)
	{
		sum_func[i] = function_call_test();
		average_func += sum_func[i];
	}
	average_func = average_func / test_loop;

	cout << message[prime_msg] << " \n";
	for (i = 0; i < test_loop; i++)
	{
		sum_prime[i] = prime_number_test();
		average_prime += sum_prime[i];
	}
	average_prime = average_prime / test_loop;

	is_test_done = true;

	display_report(all);

	return 0;
}

// --------------------------------------------------------------------
double BenchMark::sum_int_test()	// add integer test
{
	long temp = 0;
	start_time = clock();
	for (long i = 0; i < limits; ++i)
		temp += 1;
	end_time = clock();
	sum_int_result = ((double)end_time - (double)start_time) / CLOCKS_PER_SEC;
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
	sub_int_result = ((double)end_time - (double)start_time) / CLOCKS_PER_SEC;
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
	div_int_result = ((double)end_time - (double)start_time) / CLOCKS_PER_SEC;
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
	mul_int_result = ((double)end_time - (double)start_time) / CLOCKS_PER_SEC;
	return mul_int_result;
}
// --------------------------------------------------------------------
double BenchMark::sum_decimal_test()
{
	double temp = 0;
	start_time = clock();
	for (long i = 0; i < limits; ++i)
		temp += 1.1;
	end_time = clock();
	sum_decimal_result = ((double)end_time - (double)start_time) / CLOCKS_PER_SEC;
	return sum_decimal_result;
}
// --------------------------------------------------------------------
double BenchMark::sub_decimal_test()
{
	double temp = 1;
	start_time = clock();
	for (long i = limits; i > 0; --i)
		temp -= 1.1;
	end_time = clock();
	sub_decimal_result = ((double)end_time - (double)start_time) / CLOCKS_PER_SEC;
	return sub_decimal_result;
}
// --------------------------------------------------------------------
double BenchMark::div_decimal_test()
{
	double temp = 1;
	start_time = clock();
	for (long i = 0; i < limits; ++i)
		temp /= 1.1;
	end_time = clock();
	div_decimal_result = ((double)end_time - (double)start_time) / CLOCKS_PER_SEC;
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
	mul_decimal_result = ((double)end_time - (double)start_time) / CLOCKS_PER_SEC;
	return mul_decimal_result;
}
// --------------------------------------------------------------------
double BenchMark::string_test()
{
	char string1[10] = { 'a','a','a','a','a','a','a','a','\0' };
	char string2[10] = { 'a','b','c','d','e','f','g','h','\0' };
	start_time = clock();
	for (long i = 0; i < limits; i++)
	{
		for (unsigned char temp = 0; temp< 8; temp++)
			string1[temp] = string2[temp];
	}
	end_time = clock();
	str_result = ((double)end_time - (double)start_time) / CLOCKS_PER_SEC;

	return str_result;
}
// --------------------------------------------------------------------
double BenchMark::function_call_test()
{
	start_time = clock();
	for (long i = 0; i < limits; i++)
		foo();
	end_time = clock();
	func_result = ((double)end_time - (double)start_time) / CLOCKS_PER_SEC;

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
	prime_result = ((double)end_time - (double)start_time) / CLOCKS_PER_SEC;
	return prime_result;
}
// --------------------------------------------------------------------
void BenchMark::save_results()
{
	// TODO : save to file
	reportfile.open("bench_results.txt", ios::out | ios::app);
	if (reportfile.is_open())
	{
		switch (test_id)
		{
		case all:
			reportfile << endl;

			reportfile << message[int_add_msg] << setprecision(20) << average_int_sum << "\n";
			for (int i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sum_int_sum[i] << "\n";

			reportfile << message[int_sub_msg] << setprecision(20) << average_int_sub << "\n";
			for (int i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sum_int_sub[i] << "\n";

			reportfile << message[int_div_msg] << setprecision(20) << average_int_div << "\n";
			for (int i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sum_int_div[i] << "\n";

			reportfile << message[int_mul_msg] << setprecision(20) << average_int_mul << "\n";
			for (int i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sum_int_mul[i] << "\n";

			reportfile << endl;
			reportfile << message[dec_add_msg] << setprecision(20) << average_decimal_sum << "\n";
			for (int i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sum_decimal_sum[i] << "\n";

			reportfile << message[dec_sub_msg] << setprecision(20) << average_decimal_sub << "\n";
			for (int i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sum_decimal_sub[i] << "\n";

			reportfile << message[dec_div_msg] << setprecision(20) << average_decimal_div << "\n";
			for (int i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sum_decimal_div[i] << "\n";

			reportfile << message[dec_mul_msg] << setprecision(20) << average_decimal_mul << "\n";
			for (int i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sum_decimal_mul[i] << "\n";

			reportfile << endl;
			reportfile << message[str_msg] << setprecision(20) << average_string << "\n";
			for (int i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sum_string[i] << "\n";

			reportfile << message[func_msg] << setprecision(20) << average_func << "\n";
			for (int i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sum_func[i] << "\n";

			reportfile << message[prime_msg] << setprecision(20) << prime_result << "\n";
			for (int i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sum_prime[i] << "\n";

			break;

		case integer_only:
			reportfile << endl;
			reportfile << message[int_add_msg] << setprecision(20) << average_int_sum << "\n";
			for (int i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sum_int_sum[i] << "\n";

			reportfile << message[int_sub_msg] << setprecision(20) << average_int_sub << "\n";
			for (int i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sum_int_sub[i] << "\n";

			reportfile << message[int_div_msg] << setprecision(20) << average_int_div << "\n";
			for (int i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sum_int_div[i] << "\n";

			reportfile << message[int_mul_msg] << setprecision(20) << average_int_mul << "\n";
			for (int i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sum_int_mul[i] << "\n";
			reportfile << endl;
			break;

		case float_only:
			reportfile << endl;
			reportfile << message[dec_add_msg] << setprecision(20) << average_decimal_sum << "\n";
			for (int i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sum_decimal_sum[i] << "\n";

			reportfile << message[dec_sub_msg] << setprecision(20) << average_decimal_sub << "\n";
			for (int i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sum_decimal_sub[i] << "\n";

			reportfile << message[dec_div_msg] << setprecision(20) << average_decimal_div << "\n";
			for (int i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sum_decimal_div[i] << "\n";

			reportfile << message[dec_mul_msg] << setprecision(20) << average_decimal_mul << "\n";
			for (int i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sum_decimal_mul[i] << "\n";
			reportfile << endl;
			break;

		case string_only:
			reportfile << message[str_msg] << setprecision(20) << average_string << "\n";
			for (int i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sum_string[i] << "\n";
			break;

		case function_call_only:
			reportfile << message[func_msg] << setprecision(20) << average_func << "\n";
			for (int i = 0; i < report_loop; i++)
				reportfile << message[result_msg] << i << "\t" << sum_func[i] << "\n";
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
	if (is_report_done)
	{
		test_id = whose_test;
		switch (test_id)
		{
			case all:
				cout << endl;
				cout << message[result_msg] << endl;

				cout << message[int_add_msg] << setprecision(20) << average_int_sum << "\n";
				for (int i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sum_int_sum[i] << "\n";

				cout << message[int_sub_msg] << setprecision(20) << average_int_sub << "\n";
				for (int i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sum_int_sub[i] << "\n";

				cout << message[int_div_msg] << setprecision(20) << average_int_div << "\n";
				for (int i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sum_int_div[i] << "\n";

				cout << message[int_mul_msg] << setprecision(20) << average_int_mul << "\n";
				for (int i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sum_int_mul[i] << "\n";

				cout << endl;
				cout << message[dec_add_msg] << setprecision(20) << average_decimal_sum << "\n";
				for (int i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sum_decimal_sum[i] << "\n";

				cout << message[dec_sub_msg] << setprecision(20) << average_decimal_sub << "\n";
				for (int i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sum_decimal_sub[i] << "\n";

				cout << message[dec_div_msg] << setprecision(20) << average_decimal_div << "\n";
				for (int i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sum_decimal_div[i] << "\n";

				cout << message[dec_mul_msg] << setprecision(20) << average_decimal_mul << "\n";
				for (int i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sum_decimal_mul[i] << "\n";

				cout << endl;
				cout << message[str_msg] << setprecision(20) << average_string << "\n";
				for (int i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sum_string[i] << "\n";

				cout << message[func_msg] << setprecision(20) << average_func << "\n";
				for (int i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sum_func[i] << "\n";

				cout << message[prime_msg] << setprecision(20) << prime_result << "\n";
				for (int i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sum_prime[i] << "\n";

				break;

			case integer_only:
				cout << endl;
				cout << message[int_add_msg] << setprecision(20) << average_int_sum << "\n";
				for (int i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sum_int_sum[i] << "\n";

				cout << message[int_sub_msg] << setprecision(20) << average_int_sub << "\n";
				for (int i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sum_int_sub[i] << "\n";

				cout << message[int_div_msg] << setprecision(20) << average_int_div << "\n";
				for (int i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sum_int_div[i] << "\n";

				cout << message[int_mul_msg] << setprecision(20) << average_int_mul << "\n";
				for (int i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sum_int_mul[i] << "\n";
				cout << endl;
				break;

			case float_only:
				cout << endl;
				cout << message[dec_add_msg] << setprecision(20) << average_decimal_sum << "\n";
				for (int i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sum_decimal_sum[i] << "\n";

				cout << message[dec_sub_msg] << setprecision(20) << average_decimal_sub << "\n";
				for (int i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sum_decimal_sub[i] << "\n";

				cout << message[dec_div_msg] << setprecision(20) << average_decimal_div << "\n";
				for (int i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sum_decimal_div[i] << "\n";

				cout << message[dec_mul_msg] << setprecision(20) << average_decimal_mul << "\n";
				for (int i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sum_decimal_mul[i] << "\n";
				cout << endl;
				break;

			case string_only:
				cout << message[str_msg] << setprecision(20) << average_string << "\n";
				for (int i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sum_string[i] << "\n";
				break;

			case function_call_only:
				cout << message[func_msg] << setprecision(20) << average_func << "\n";
				for (int i = 0; i < report_loop; i++)
					cout << message[result_msg] << i << "\t" << sum_func[i] << "\n";
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
void BenchMark::set_limits(int t)
{
	limits = t;
}
// --------------------------------------------------------------------
int BenchMark::get_id()
{
	return object_id;
}
// --------------------------------------------------------------------
void foo(void)
{
	// do something    
}

// --------------------------------------------------------------------

