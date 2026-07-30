#include <iostream>
using namespace std;


class WaitingArea
{
private:
    int capacity;

    int *array;     
    int count; 

public:

    //constructor
    WaitingArea(int size = 6) 
    {
        capacity = size;
        array = new int[capacity];
        count = 0;
    }
    
    ~WaitingArea() {
        delete[] array;
    }

    
void addPatient(int patientID) {
    if (count == capacity) {
        cout<<"Waiting area full\n";

        return;  
    }
        array[count]=patientID;
        count++;
        cout<<"Patient "<<patientID<<" added.\n";
    }

void callpatient()
{
    if (count==0){
        cout<<"No Patient is Waiting"<<endl;

        return;
    }    

    int patient = array[0];
       for(int i=0; i<count-1; i++){
        array[i]=array[i+1];
       }
        count--;
        cout<<"Doctor calls patient "<<patient+1<<endl;

}
void findPatient(int patientID){
    if(count==0){
        cout<<"No Patienyt is waiting"<<endl;
        return ;

    }

    for (int i=0; i<count; i++){
        if(array[i]==patientID){

            cout<<"Patient "<<patientID<<" fount"<<endl;

            return;


        }

    }
    cout<<"Patient "<<patientID<<" not found"<<endl;

}


};
int main(){

    cout<<"[Faiz Ul Hassan | 24p-3065]\n"<<endl;


    WaitingArea A1(6);
    
    int choice, patientID;

    //an extra code to show user a menue

    do{
        cout<<"\n"<<endl;
        cout<<"<<< Hospital Waiting Area >>>\n"<<endl;

        cout<<"1. Add Patient"<<endl;
        cout<<"2. Call next patient"<<endl;
        cout<<"3. Find Patient"<<endl;

        cout<<"0. Exit"<<endl;
        cout<<"\n"<<endl;
        
        cout<<"Enter Your Choice: ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter Patient ID: ";
            cin>>patientID;
            A1.addPatient(patientID);

            break;

        case 2:
        cout<<"Call next patient"<<endl;
            A1.callpatient();
            break;
        case 3:
            cout<<"Enter Patient ID to find: ";
            cin>>patientID;

            A1.findPatient(patientID);
            break;
        case 0:
            cout<<"Exiting..."<<endl;
            break;
        
        default:

            cout<<"Invalid Choice, try again"<<endl;
            
        }

    }
    while (choice!=0);
    


}

   