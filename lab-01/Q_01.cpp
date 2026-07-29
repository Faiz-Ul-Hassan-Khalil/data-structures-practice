#include <iostream>
using namespace std;

//functtion to remove duplicates 
int remove_duplicates(int arr[], int n) {
    for(int i = 0; i < n; i++) {

        for(int j = i + 1; j < n;) {

            if(arr[i] == arr[j]) {

            //shift elements left to overwrite duplicate
                for(int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }

                --n; //size decreases as one elment is removed
            } else {

            //only move to next if no duplicate removed
                j++; 
           
            }
        }

    }

    return n; 
    //n is updated sixe

}
//fucntion to count occurance of each elemnt

void count_freq(const int arr[], int n, int uniqueVals[], int freq[], int &uCount) 
{
    uCount = 0; //number of unique elements whic are found so far
    for (int i = 0; i < n; i++) {
        bool found = false;
        int pos = -1;

        // check if arr[i] already exists in uniqueVals
        for (int j = 0; j < uCount; j++) {
            if (uniqueVals[j] == arr[i]) {
                found = true;
                pos = j;
                break;
            }
        }

        if (found) {
            freq[pos]++; // increase frequency of existing element
        } else {
            uniqueVals[uCount] = arr[i]; // add new unique value
            freq[uCount] = 1;           // first occurrence
            uCount++;                   // increase unique count
        }
    }
}

//function to sort according to freqncy
void sort(int uniqueVals[], int freq[], int uCount) 
{
    for (int i = 0; i < uCount - 1; i++)
    {
        int now = i; 
        //assume current index is "now"

        for (int j = i + 1; j < uCount; j++) 
        {
            //check for higher freqency
            if (freq[j] > freq[now]){

                now = j;

            }


            //if same frequency, choose smaller number

            else if (freq[j] == freq[now] && uniqueVals[j] < uniqueVals[now]) 
            {

                now = j;

            }
        }

        
        // swap values and frequencies
        if (now != i) 
        {
            int tempFreq = freq[i];

            freq[i] = freq[now];

            freq[now] = tempFreq;


            int tempVal = uniqueVals[i];

            uniqueVals[i] = uniqueVals[now];
            uniqueVals[now] = tempVal;
    }
}
}

//display rearranged and its frequncy

void display(const int uniqueVals[], const int freq[], int uCount) 
{

    cout<< "Rearranged Array: [";

    for (int i = 0; i < uCount; i++) {
        cout<< uniqueVals[i];
        if (i != uCount - 1) cout<< ", ";
    }

    cout<< "]"<< endl;

    cout<< "Frequencies:" << endl;

    for (int i = 0; i < uCount; i++) 
    {

        cout<< uniqueVals[i] << " -> " << freq[i] << endl;
    }
}


//main function

int main() {
    cout<< "[ Name: Faiz Ul Hassan  |  Roll number: 24p_3065 ]\n" << endl;

//take array size from user

    int size;

    cout<< "Enter Size of Array: ";
    cin>> size;
    cout<< endl;

//taking array elemnts from user

    int arr[50];

    cout<< "Enter array elements" << endl;
    for (int i = 0; i < size; i++) {
        cout<< "[" << i << "] =";

        cin>> arr[i]; 

    };


//Display original array

    cout<< "Original array is: [";

    for (int i = 0; i < size; i++) 
    {

        cout<< arr[i];

        if (i != size - 1) cout<< ", ";


    }

    cout<< "]" << endl;
    

//remove duplicates (on a copy so original stays safe)

    int arrCopy[50];

    for (int i = 0; i < size; i++) arrCopy[i] = arr[i];

    int dedupSize = remove_duplicates(arrCopy, size);

//disply array after duplicates removed

    cout<< "Array after removing duplicates: [";

    for (int i = 0; i < dedupSize; i++) 
    {
        cout<< arrCopy[i];

        if (i != dedupSize - 1) cout<< ", ";

    }
    cout<< "]" << endl;


//count frequencies from rignal array

    int uniqueVals[50], freq[50], uCount = 0;

    count_freq(arr, size, uniqueVals, freq, uCount);
    

//display rearranged array with frequencies

    display(uniqueVals, freq, uCount);

    return 0;
}
