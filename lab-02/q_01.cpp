#include <iostream>
using namespace std;
int main()
{
    cout<<"[ Name : Faiz Ul Hassan | Roll num: 24p-3065 ]"<<endl;
    cout<<"-----------------------------------------"<<endl;


    //taking input form user for rows and columns

    int rows, cols;

    cout<<"enter number Of rows: ";
    cin>>rows;

    cout<<"enter number of columns: ";

    cin>>cols;


    int **arr = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        *(arr + i) = new int[cols];
    }


    //taking array elemnts from user

    cout<<"\nEnter Elements of the array:\n";
    
    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < cols; j++)

        {
            cout<<"Element ["<<i<<"]["<<j<<"]: ";

            cin>>*(*(arr + i) + j);

        }
    }


    //finding sum of rows

    cout<<"\n<<< Sum of rows >>>\n";
    for (int i = 0; i < rows; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < cols; j++)
        {

            rowSum += *(*(arr + i) + j);
        }


        cout<<"Row "<<i + 1<<" sum = "<<rowSum<<endl;


    }

    //column sums
    cout<<"\n<<< Sum of columns >>>\n";
    for (int j = 0; j < cols; j++)
    {
        int colSum = 0;

        for (int i = 0; i < rows; i++)

        {
            colSum += *(*(arr + i) + j);
        }
        cout<<"Column "<<j + 1<<" sum = "<<colSum<<endl;


    }

    cout<<"\n\n";
    



    //deleting dynamically allocated memory

    for (int i = 0; i < rows; i++)
    {
        delete[] *(arr + i);
    }
    delete[] arr;





    return 0;
}
