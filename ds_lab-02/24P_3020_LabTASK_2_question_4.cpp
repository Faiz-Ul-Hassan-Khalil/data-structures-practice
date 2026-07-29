#include<iostream>
#include<cstdlib>
#include<ctime>
int top_selling(int*arr,int s){
	int index=0;
	for(int i=0;i<(s-1);i++){
		if(*(arr+i)<*(arr+index)){
			index=i;
		}//if ends
	}//loop ends
	return index;
}
int second_selling(int* arr,int s,int top){
	int index=-1;
	int max=*(arr+top);
	for(int i=0;i<s;i++){
		if(i==top){
			continue;
		}//if ends
		if(index==-1 || *(arr+i)<max){
			max=*(arr+i);
			index=i;
		}//if ends
	}//loop ends
	return index;
}
void sorting_inventory(int*arr,int s){
	int temp;
	for(int i=0;i<s-1;i++){
		for(int j=i+1;j<s;j++){
			if(*(arr+j)<*(arr+i)){
				temp=*(arr+i);
				*(arr+i)=*(arr+j);
				*(arr+j)=temp;
			}//if ends
		}//inner loop ends
	}//outer loop ends
}
using namespace std;
int main(){
	cout<<"[ Name : Faiz Ul Hassan | Roll num: 24p-3065 ]"<<endl;
	int size;
	cout<<"Enter size of Array (inventory) :";
	cin>>size;
	srand(time(0));
	int* inventory=new int[size];
	for(int i=0;i<size;i++){
		*(inventory+i)=rand()%100;
	}//loop ends
	
	int sum=0;
	for(int i=0;i<size;i++){
		sum=sum+*(inventory+i);
	}//loop ends
	double average=(double)sum/size;
	cout<<" Inventory : "<<endl;
	for(int i=0;i<size;i++){
		cout<<*(inventory+i)<<" ";
	}//loop ends
	
	cout<<"\nAverage Stock Level : "<<average;
	int critical_count=0;
	cout<<"\nCritical Products Along with Index and Stock : "<<endl;
	for(int i=0;i<size;i++){
		if(*(inventory+i)<average){
			cout<<"Product "<<i+1<<" : "<<*(inventory+i)<<endl;
			critical_count++;
		}//if ends
	}//loop ends
	cout<<"\nTotal Critical Products : "<<critical_count<<endl;
	
	int top=top_selling(inventory,size);
	cout<<"\nTopselling Product  "<<top+1<<" with stock count : "<<*(inventory+top)<<endl;
	
	int second=second_selling(inventory,size,top);
	cout<<"\nSecond Top Selling Product  "<<second+1<<" with stock count : "<<*(inventory+second)<<endl;
	
	sorting_inventory(inventory,size);
	cout<<"\nSorted Inventory : "<<endl;
	for(int i=0;i<size;i++){
		cout<<*(inventory+i)<<" ";
	}//loop ends
	delete[] inventory;
	return 0;
}