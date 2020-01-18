#define SC_INCLUDE_FX
#include <iostream>
#include <systemc>
#include <vector>

sc_dt::sc_int<50> fib(std::vector<sc_dt::sc_int<50>> &a, const int &b)
{
	int i;
	for(i = 2; i < b; ++i)
		a.push_back(a[i-1] + a[i-2]);
	return a[i-1];
}
int no_bits(const sc_dt::sc_int<50> &d)
{
	int bit = 1;

	while(1)
	{
		sc_dt::sc_ufix_fast fix_point(bit, bit);
		
		fix_point = d;

		if(!fix_point.overflow_flag())
			break;

		++bit;
	}
	return bit;
}
int sc_main(int argc, char* argv[])
{
	int b, num_bits;
	std::vector<sc_dt::sc_int<50>> a = {1, 1};
	std::cout << "Please enter a fibonacci number:";
	std::cin >> b;
	
	sc_dt::sc_int<50> c = fib(a, b);
	
	std::cout << c << std::endl;

	num_bits = no_bits(c);

	std::cout << "No bits:" << num_bits << std::endl;

	return 0;
}
