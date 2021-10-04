// Compilation of all the ways to solve fibonacci numbers to be used as a future reference
// This document is primarily used to refresh memory and remember how dynamic programming works

#include "iostream"
#include "vector"
#include "unordered_map"

// forward declaration for all the functions

unsigned long fibonacci(unsigned int num);
unsigned long fib_bottom_up(unsigned int num);
unsigned long fib_bottom_up_arr(unsigned int num);
unsigned long fib_dynamic(unsigned int num, std::unordered_map<int, unsigned long> &map);


// ---------------------------------------------------
// The main function (customize as needed) -----------
// ---------------------------------------------------

int main()
{
	std::unordered_map<int, unsigned long> map;

	std::cout << fib_bottom_up_arr(20);
}

/// <summary>Unoptimized topdown approach where we calculate the fib number by calculating sum of fib of previous two numbers.
///	<para>This is a very slow approach and can take extremely long time, thus for bigger numbers this should not be used.
///	</summary>
unsigned  long fibonacci(unsigned int num)
{
	// base cases of 1 and 2 which we both know are equal to 1
	if (num == 1 || num == 2)
		return 1;

	// base case of 0 we return 0 as fibb of 0 is 0
	if (num == 0)
		return 0;
	else
	{
		return fibonacci(num - 1) + fibonacci(num - 2);
	}
}

/// <summary>fib_dynamic is the top down approach to solving the fibonacci number using unordered map.
/// <para>Solution is found through recursion and calculated values are stored in an unordered map where
///	the key is the fibonacci number and value is what that fibonacci number is equal to. As the map is
///	passed into the function the results are stored and can be used in the future as well. 
///	</summary>
unsigned long fib_dynamic(unsigned int num, std::unordered_map<int, unsigned long> &map)
{
	// map.find() returns map.end() if the key is not found
	// if the key is found that means we know the solution and can return the value at the key
	if (map.find(num) != map.end())
	{
		return map[num];
	}

	// base case 1: fibonacci of 0 is 0
	if (num == 0)
		return 0;
	// base case 2: fibonacci of 1 and 2 are both equal to 1 
	if (num < 3)
		return 1;
	else // if it is not base case calculate fib of the previous two numbers
	{
		return map[num] = fib_dynamic(num - 1, map) + fib_dynamic(num - 2, map);
	}
}


/// <summary>fib_bottom_up is the bottom up approach to solving the fibonacci numbers using vector.
///	<para>This solution relies on std vector and has the flexibility of taking any input within reason.
///	<para>The vector is filled by summing the last two numbers of the array.
///	</summary>
unsigned long fib_bottom_up(unsigned int num)
{
	std::vector<long> fib_array {0, 1};

	for (unsigned int i = 0; i <= num; i++)
	{
		fib_array.push_back(fib_array[i - 1] + fib_array[i - 2]);
	}

	return fib_array[num];
}

/// <summary>fib_bottom_up_arr is the bottom up approach to solving the fibonacci numbers using an array.
///	<para>This solution relies on a normal array and has capacity of 1,000, even though 1,000th fibb number
///	cannot be printed due to it being too large.
///	<para>The array is filled by initializing all the numbers to zero. Second member of the array is set to 1
///	and the first member is added to the next two all the way until the end of the array.
///	</summary>
unsigned long fib_bottom_up_arr(unsigned int num)
{
#define SIZE 1000

	if (num > SIZE)
	{
		printf("The input is too large, please input a number under: %d.", SIZE);
		return 0;
	}

	unsigned long arr[SIZE] = { 0, 1 };

	for (unsigned int i = 0; i <= num; i++)
	{
		arr[i+1] += arr[i];
		arr[i+2] += arr[i];
	}

	return arr[num];
}