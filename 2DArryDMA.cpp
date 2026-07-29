#include <iostream>
using namespace std;

int main() {
    int arr[2][2] = {{1,2},{2,3}};
    
    int* start = &arr[0][0];
 
    int* end   = &arr[1][1];
    
    for(int* p = start; p <= end; p++) {
        cout << *p << endl;
    }
}

