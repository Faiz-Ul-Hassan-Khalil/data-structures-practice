#include <iostream>
using namespace std;

//finding length of array

int getLength(char arr[]) 
{
    int length = 0;

    while (arr[length] != '\0') 
    {
        length++;

    }

    return length;

}

//reversing part of sentece

void reverse(char arr[], int start, int end) 
{

    while (start < end) 
    {
        char temp = arr[start];

        arr[start] = arr[end];

        arr[end] = temp;

        start++;

        end--;


    
    }
}

//reverse the entire sentence

void reverseSentence(char arr[]) 
{

    int n = getLength(arr);
    reverse(arr, 0, n - 1);
}

//reverse each worrd

void reverseWords(char arr[])
{
    int n = getLength(arr);

    int start = 0;

    for (int i = 0; i <= n; i++)
    {
        if (arr[i] == ' ' || arr[i] == '\0') 
        {
            //reverse current word 
            reverse(arr, start, i - 1);
            
            //move to nextt word
            start = i + 1;
       
        }
}

}

//convet vovles to uper case and consonet into lowercase

void convertCase(char arr[]){

    int n = getLength(arr);

    for (int i = 0; i < n; i++)
    {
        char ch = arr[i];

        //check vowel
        if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
            ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U') 
            {

            //make vowel uppercase
            if (ch >= 'a' && ch <= 'z'){

                //ascii conversion
                arr[i] = ch - 32; 

            }

        } else if (ch != ' '){

//consonant to lowercase

            if (ch >= 'A' && ch <= 'Z'){

//ascii conversion
                arr[i] = ch + 32; 

            }
        }


}
}

//remove spaces from the array
void removeSpaces(char arr[]){

    int n = getLength(arr);
    int j = 0;

    for (int i = 0; i < n; i++){
        
        if (arr[i] != ' '){

        //copy only non-space chars
            arr[j] = arr[i]; 

            j++;
        }
    }

    arr[j] = '\0';
}

//Display the final array
void displayArray(char arr[]){

    int n = getLength(arr);

    for (int i = 0; i < n; i++){
        cout<< arr[i];

    }
    cout<< endl;
    cout<<"\n\n";

}

int main(){

    cout<< "[ Name: Faiz Ul Hassan  |  Roll number: 24p_3065 ]\n" << endl;


    //taking input sentencxe

    char arr[100];
    cout<< "Enter a sentence: ";

    cin.getline(arr, 100);

//reverse the entire sentence

    reverseSentence(arr);

//reverse each word individually
    reverseWords(arr);


//convert vowels to uppercase, consonants to lowercase
    convertCase(arr);

    //remove spaces
    removeSpaces(arr);

    //display final compressed array
    cout<< "\nFinal compressed array: ";

    displayArray(arr);

    return 0;
}
