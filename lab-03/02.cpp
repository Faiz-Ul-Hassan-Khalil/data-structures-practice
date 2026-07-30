#include<iostream>
using namespace std;
//super market with 50 products
//maxx products 50 IDS AT a time
//insert a product
//insert a product at a specific position
//DELETE a product
//sort the product
//reverse the cart
//display all products


class SuperMarket{
    private:
    int capacity;
    int *array;
    int count;

    public:
    SuperMarket(int size=50){
        capacity=size;
        array=new int[capacity];
        count=0;
    }
    ~SuperMarket(){
        delete[] array;
    }
    void insertProduct(int productID){
        if(count==capacity){
            cout<<"Cart is full"<<endl;
            return;
        }
        array[count]=productID;
        count++;
        cout<<"Product "<<productID<<" added to cart"<<endl;
    }
    void insertAtPosition(int productID, int position){
        if(count==capacity){
            cout<<"Cart is full"<<endl;
            return;
        }
        if(position<0 || position>count){
            cout<<"Invalid position"<<endl;
            return;
        }
        for(int i=count; i>position; i--){
            array[i]=array[i-1];
        }
        array[position]=productID;
        count++;
        cout<<"Product "<<productID<<" added at position "<<position<<endl;
    }
    void deleteProduct(int productID){
        if(count==0){
            cout<<"Cart is empty"<<endl;
            return;
        }
        int index=-1;
        for(int i=0; i<count; i++){
            if(array[i]==productID){
                index=i;
                break;
            }
        }
        if(index==-1){
            cout<<"Product not found"<<endl;
            return;
        }
        for(int i=index; i<count-1; i++){
            array[i]=array[i+1];
        }
        count--;
        cout<<"Product "<<productID<<" deleted from cart"<<endl;
    };

    //maimn function
    int main(){
        SuperMarket cart;
        cart.insertProduct(101);
        cart.insertProduct(102);
        cart.insertAtPosition(103,1);
        cart.deleteProduct(102);
        return 0;
    }