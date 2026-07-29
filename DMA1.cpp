#include<iostream>
using namespace std;
int main()
{
//	int* ptr = NULL;
//	ptr = new int;
//
//	int* ptr = new int ;
//	
//	
//	*ptr = 2;

	int* ptr = new int(2);
	cout<<ptr << " " <<&ptr << " * ptr : "<<*ptr<<endl; 


	float* f_ptr = new float(20.5);
	cout<<f_ptr << " " <<&f_ptr << " * ptr : "<<*f_ptr<<endl; 
	
	
	struct fast{
		int s_id;
		fast(int id)
		{
			s_id = id;
		}
		
	};
	
	
	fast* s_ptr = new fast(7821);
	cout<<s_ptr << " " <<&s_ptr->s_id << "  s_ptr->s_id : "<<s_ptr->s_id<<endl;
}

