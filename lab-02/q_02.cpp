#include <iostream>
using namespace std;

//function for find intrsection of two array

int* findIntersect(int *arr1, int size1, int *arr2, int size2, int *resultSize)
{
    int maxSize;

    //determin max possible size of intersection
    if (size1 < size2)
    {

        maxSize = size1;

    } 

    else{

        maxSize = size2;
    }

    //temp array to store intersection
    int *temp = new int[maxSize]; 

    int count = 0;

    //check comon elements
    for (int i = 0; i < size1; i++)
    {

        for (int j = 0; j < size2; j++)
        {
            if (*(arr1 + i)==*(arr2 + j))

            {
                bool exists = false;

                for (int k = 0; k < count; k++)
                {

                    if (*(temp + k)==*(arr1 + i))
                    {

                        exists = true;

                        break;


                    }

                }

                if (!exists)

                {
                    *(temp + count) = *(arr1 + i);
                    count++;
                }
            }
        }
    }

    //if no intersection
    if (count==0)
    {

        delete[] temp;

        *resultSize = 0;

        return NULL;

    }

    //create exact sized array

    int *result = new int[count];
    //copy elements
    for (int i = 0; i < count; i++)
    {

        *(result + i) = *(temp + i);

    }

    delete[] temp;

    *resultSize = count;


    return result;


}

int main()
{
    cout<<"[ Name : Faiz Ul Hassan | Roll num: 24p-3065 ]"<<endl;
    cout<<"-----------------------------------------"<<endl;



    int size1, size2;

    cout << "\nEnter Size of first array: ";
    cin >> size1;

    int *arr1 = new int[size1];

    cout << "Enter elements of first array:\n";

    for (int i = 0; i < size1; i++)
    {
        cout<<"Element ["<<i<<"]: ";
        cin >> *(arr1 + i);
    }

    cout << "Enter size of Second array: ";
    cin >> size2;

    int *arr2 = new int[size2];

    cout << "Enter elements of second array:\n";

    for (int i = 0; i < size2; i++)
    {

        cout<<"Element ["<<i<<"]: ";
        cin >> *(arr2 + i);
    }

    int resultSize;

    int *intersection = findIntersect(arr1, size1, arr2, size2, &resultSize);

    if (intersection==NULL)
    {

        cout << "\nNo intersection found ." << endl;

    } 
    else{

        cout << "\nIntersection elements: ";

        for (int i = 0; i < resultSize; i++)
        {
            cout << *(intersection + i) << " ";
        }
        cout << endl;
        cout<<"\n\n"<<endl;
        
        delete[] intersection;
    }

    
    delete[] arr1;
    delete[] arr2;






    return 0;
}
