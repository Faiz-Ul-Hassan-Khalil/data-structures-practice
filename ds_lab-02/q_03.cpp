#include<iostream>
using namespace std;

void resize_array(int **&arr, int &r, int &c)
{

    int row_up= *(*(arr));
    int row_down= *(*(arr+0)+(c-1));

    int right_col= *(*(arr+(r-1))+0); 

    //creating new 2D array of new size

    int row_num=r+row_up+row_down; // total number of rows for array 2
    int col_num=c+right_col; //totall numbr of colmns for new array 2

    int **arr2= new int*[row_num];

    for(int i=0; i<row_num; i++)
    {

        *(arr2+i)=new int[col_num];

    }
    int i;
    for ( i = 0; i < row_up; i++)  
    
    {
        for(int j=0;j<col_num;j++)
        
        {
            *(*(arr2+i)+j) = 0;
        }
    } 

    for(i;i<row_up+r;i++)
    
    {
        for(int j=0;j<col_num;j++)
        
        {
            if(j<c)
            
            {
                *(*(arr2+i)+j) = *(*(arr+(i-row_up))+(j));
            }
            else 
            
            {
                *(*(arr2+i)+j) = 0;
            }
        }
    } 

    for(i;i<row_num;i++)
    
    {
        for(int j=0;j<col_num;j++)
        
        {
            *(*(arr2+i)+j) = 0;
        }
    } 

    for(int k=0;k<r;k++)
    
    {
        delete[] *(arr+k);
    }
    delete[] arr;

    arr = arr2;
    r = row_num;
    c = col_num;


}
void display(int **&arr, int r, int c)
{

    for (int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {

            cout<<*(*(arr+i)+j)<<" ";
        }
        cout<<endl;
    }

}
int main()
{

    cout<<"[ Name : Faiz Ul Hassan | Roll num: 24p-3065 ]"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"[ <<<< 2D Array Resizing >>>> ]"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cout<<"\n";

    int rows, col;

    cout<<"enter rows: ";
    cin>>rows;

    cout<<"enter colmns: ";
    cin>>col;

    int **arr = new int*[rows];


    for (int i=0; i<rows; i++)
    {
        arr[i] = new int[col];
    }

    cout<<"\n<< Enter array elements >> \n "<<endl;
    for (int i=0; i<rows; i++)
    {
        for(int j=0; j<col; j++)
        {

            cout<<"Element ["<<i<<"]["<<j<<"] :";
            cin>>*(*(arr+i)+j);


        }

    }
    cout<<endl;


    cout<<"Orignal Array: "<<endl;


    display(arr, rows, col);
    resize_array(arr, rows, col);

    cout<<"\nNew Array: \n"<<endl;
    display(arr,rows, col);


    cout<<"\n\n";


    return 0;

}