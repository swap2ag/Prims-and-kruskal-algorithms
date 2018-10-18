#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void function()
{
    long long number = 0;
	
{
    for( long long i = 0; i != 200; ++i )
    {
       number += 5;
    }
}
}

int main()
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    function();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>( t2 - t1 ).count();

    cout << duration<<" microseconds";
    return 0;
}

#include<time.h>
int main()
{
	clock_t start_t, end_t,total_t;
	
	start_t = clock();
	g = prims(g);
	end_t = clock();
	
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC*1000;
	
	cout<<"duration: "<<total_t<<" ms";
	return 0;
}

#include<windows.h>
inline long long PerformanceCounter() noexcept
{
    LARGE_INTEGER li;
    ::QueryPerformanceCounter(&li);
    return li.QuadPart;
}
// -----------------------------------------
inline long long PerformanceFrequency() noexcept
{
    LARGE_INTEGER li;
    ::QueryPerformanceFrequency(&li);
    return li.QuadPart;
}


int main()
{
	// Record start time
        
	long long start = PerformanceCounter();
	function();
	long long finish = PerformanceCounter();
	
	long long frequency = PerformanceFrequency();
	
	double elapsedMilliseconds = ((finish - start) * 1000.0) / frequency;
	
	return 0;
}








