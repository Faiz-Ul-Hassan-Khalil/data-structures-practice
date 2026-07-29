#include <iostream>
using namespace std;
int main()
{
    cout<<"[ Name: Faiz Ul Hassan  |  Roll number: 24p_3065 ]\n"<<endl;

    
    int roll_num;
    //taking roll num input

    cout<<"Enter the roll number of student: ";
    cin>>roll_num;


    //single pointer as teacher knows roll number directly

    int *teacher;
    teacher = &roll_num;


    //double pointer as class incharge gets roll numberr  through teacher)

    int **class_incharge;

    class_incharge = &teacher;

    //a triple pointer principal gets roll number from class inchgre
    int ***principal;
    principal = &class_incharge;


//print the roll number in four different ways

    cout<<"\nRoll number accesed directly: "<<roll_num<<endl;
    cout<<"Roll Number accesed by teacher (single pointer): "<<*teacher<<endl;
    cout<<"Roll Number accesed by class incharge (double pointer): "<<**class_incharge<<endl;
    cout<<"Roll Number accesed by principal (triple pointer): "<<***principal<<endl;

    cout<<"\n\n";



    return 0;


}
