#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


//func to find the index of the top seling product

int top_sell(int *arr, int size)
{
    int index = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > arr[index])
        {
            index = i;
        }

    }

    return index;


}

//function to find the index of the second top selling product
int second_sell(int *arr, int size, int topIndex)
{

    int index = -1;
    for (int i = 0; i < size; i++)

    {
        if (i == topIndex)

        {
            continue; //skip the top selling product

        }

        if (index == -1 || arr[i] > arr[index])

        {
            index = i;
        }
    }


    return index;
}

//simple sorting function in ascending order
void sort_inventory(int *arr, int size)

{
    for (int i = 0; i < size - 1; i++)

    {
        for (int j = i + 1; j < size; j++)
        {

            if (arr[j] < arr[i])
            {
                int temp = arr[i];

                arr[i] = arr[j];
                arr[j] = temp;


            }
        }


    }
}

int main()
{
    cout<<"[ Name : Faiz Ul Hassan | Roll num: 24p-3065 ]"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"[ <<<< Inventory Management System >>>> ]"<<endl;
    cout<<"-----------------------------------------"<<endl;


    //rndm seed for genrating numbrs

    srand(time(0)); 
    
    int size;
    cout<<"Enter size of inventory (array): ";
    cin >> size;

    int *inventory = new int[size]; 

    //fill inventory with random stock values

    for (int i = 0; i < size; i++)
    {

        inventory[i] = rand() % 100; //stock between 0 and 99
    }

    //display original inventory
    
    cout<<"\nOriginal Inventory: ";
    for (int i = 0; i < size; i++)
    {
        cout<<inventory[i]<<" ";
    }
    cout<<endl;

    //Calculate sum and average
    int sum = 0;
    for (int i = 0; i < size; i++)
    {

        sum += inventory[i];
    }
    float average = (float)sum / size;

    cout<<"Average stock level: "<<average<<endl;

    //find and display critical products whic are below average

    int count = 0;

    cout<<"\nCritical products (below average): "<<endl;

    for (int i = 0; i < size; i++)
    {
        if (inventory[i] < average)

        {
            cout<<"Product "<<i + 1<<" with stock "<<inventory[i]<<endl;


            count++;

        }


    }
    cout<<"Total critical products: "<<count<<endl;


    //find top and second top selling

    int top = top_sell(inventory, size);

    cout<<"\nTop seling product: Product "<<top + 1 

        <<" with stock "<<inventory[top]<<endl;

    int second = second_sell(inventory, size, top);

    cout<<"Second top selling product: Product "<<second + 1 

        <<" with stock "<<inventory[second]<<endl;

    //sort inventory
    sort_inventory(inventory, size);
    cout<<"\nSorted Inventory: ";
    for (int i = 0; i < size; i++)
    {
        cout<<inventory[i]<<" ";
    }
    cout<<endl;
    cout<<""<<endl;

    delete[] inventory; 


    return 0;


}
