#include <iostream>
using namespace std;

//func to find second largest element using pointers
int findSecondLargest(int *arr, int n) 
{
    int *p= arr;

    int largest= *p;
    int second= -999999; //assume very small number

    //find the largest element first
    for (int i= 1; i< n; i++) 
    {
        if (*(p + i) > largest) 
        {

            largest= *(p + i);
        }

    }

    //now find the second largest

    for (int i= 0; i< n; i++) 
    {
        if (*(p + i) != largest && *(p + i) > second) 
        {
            
            second= *(p + i);
        }
    }

    return second;
    
}

//function to count even and odd numbers using pointers
void countEvenOdd(int *arr, int n, int *evenCount, int *oddCount) 
{
    *evenCount= 0;
    *oddCount= 0;
    for (int i= 0; i< n; i++) 
    {
        if (*(arr + i) % 2== 0) 
        {
            (*evenCount)++;
        } else 
        {
            (*oddCount)++;
        }
    }
}

//function to rotate array k positions left using pointers
void rotateArray(int *arr, int n, int k) 
{

   //handle if k is greater than n
    k= k % n; 

    int temp[100];  
    for (int i= 0; i< k; i++) 
    {
        temp[i]= *(arr + i);
    }


    for (int i= 0; i< n - k; i++) 
    {
        *(arr + i)= *(arr + i + k);
    }


    for (int i= 0; i< k; i++) 
    {
        *(arr + (n - k) + i)= temp[i];
    }


}

//helper function to check if a number is prime
bool isPrime(int x) 
{

    if (x< 2) return false;
    for (int i= 2; i * i <= x; i++) 
    {
        if (x % i== 0) return false;
    }

    return true;

}

//function to return sum of all prime numbers using pointers
int sumOfPrimes(int *arr, int n) 
{
    int sum= 0;
    for (int i= 0; i< n; i++) 
    {
        if (isPrime(*(arr + i))) 
        {
            sum += *(arr + i);
        }
    }


    return sum;
}




int main() 
{
    cout<<"[ Name: Faiz Ul Hassan  |  Roll number: 24p_3065 ]\n"<<endl;

    int n;
    cout<<"enter size of array: ";
    cin >> n;

    int arr[100];
    cout<<"enter "<<n<<" elements: ";
    for (int i= 0; i< n; i++) 
    {
        cin >> *(arr + i);  
    }

    //display original array
    cout<<"\noriginal array: [";
    for (int i= 0; i< n; i++) 
    {
        cout<<*(arr + i);
        if (i != n - 1) cout<<", ";
    }
    cout<<"]\n";

    int secondLargest= findSecondLargest(arr, n);
    cout<<"\nsecond largest element: "<<secondLargest<<endl;

    int evenCount, oddCount;
    countEvenOdd(arr, n, &evenCount, &oddCount);
    cout<<"even count: "<<evenCount<<", odd count: "<<oddCount<<endl;

    int k;
    cout<<"\nenter positions to rotate left: ";
    cin >> k;
    rotateArray(arr, n, k);

    cout<<"array after rotating "<<k<<" positions left: [";
    for (int i= 0; i< n; i++) 
    {
        cout<<*(arr + i);
        if (i != n - 1) cout<<", ";
    }
    cout<<"]\n";

    int primeSum= sumOfPrimes(arr, n);
    cout<<"sum of all prime numbers: "<<primeSum<<endl;

    cout<<"\n\n";

    return 0;
}
