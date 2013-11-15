/*
 *
 * 
 *
 * Name: Driver.cpp
 * Author: Thiago Pereira
 *
 */

#include "StandardIncludes.h"
#include <math.h>
#define MAX_PRIME 10000000

typedef boost::mutex::scoped_lock scoped_lock;

void setPrimeArrayToZero(int* primeArray);
void sieveOfEratosthenes(int* array);
void printPrimes(int* array);
void startApplication();

mutex mutex;
thread_group threads;
int counter = 0;
int primeArray[MAX_PRIME];

int main()
{
	int* primeArray = new int[MAX_PRIME];
	timer time;
	time.restart();
	setPrimeArrayToZero(primeArray);
	sieveOfEratosthenes(primeArray);
	cout << "Time consumed: " << time.elapsed() << endl;
	//printPrimes(primeArray);

	return 0;
}

void startApplication()
{
	scoped_lock lock(mutex);
	threads.create_thread(bind(&sieveOfEratosthenes, primeArray));
	condition.notify_all();
	threads.join_all();

}

void setPrimeArrayToZero(int* primeArray)
{
	for (unsigned int indexArray = 1; indexArray < MAX_PRIME; ++indexArray)
	{
		primeArray[indexArray] = 0;
	}
}

void sieveOfEratosthenes(int* array)
{
	int n, m;

	for (n = 2; n < sqrt(MAX_PRIME); ++n)
	{
		for (m = 2; m < sqrt(MAX_PRIME); ++m)
		{
			array[n * m] = 1;
		}
	}
}

void printPrimes(int* array)
{
	int count = 0;

	cout << "Prime numbers" << endl;
	for (unsigned int indexArray = 1; indexArray < MAX_PRIME; ++indexArray)
	{
		if (array[indexArray] != 1)
		{
			cout << indexArray << endl;
			count++;
		}
	}
}

