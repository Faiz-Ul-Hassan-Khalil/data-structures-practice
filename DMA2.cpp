#include<iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int n = 5;
	int* arr = new (nothrow) int[5]; //171779669184
	
	if (!arr) {
		cout<<"Memory Allocation failed";
	}
	
	
	for(int i= 0 ; i<n ; i++)
	{
		*(arr+i) = rand();
	}
	
	cout << "arr (heap address start): " << arr << endl;   // jahan array start hota hai
	cout << "&arr (pointer ka apna address on stack): " << &arr << endl;
	cout << "*arr (1st value): " << *arr << endl;
	
	
	for(int i= 0 ; i<n ; i++)
	{
		cout<<"(arr+i) : "<<(arr+i) <<" *(arr+i) "<<*(arr+i)
		<< " &(arr+i) "<<&arr[i]<<endl;
	}
	
	delete[] arr;
	
	for(int i= 0 ; i<n ; i++)
	{
		cout<<"(arr+i) : "<<(arr+i) <<" *(arr+i) "<<*(arr+i)
		<< " &(arr+i) "<<&arr[i]<<endl;
	}
	
}

