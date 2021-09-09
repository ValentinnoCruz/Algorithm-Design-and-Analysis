//#include<iostream>
//#include<string>
//
//using namespace std;
//
////function for the insertion sort
//void sort_integer(int array[],int n){
//    int i,key,j;
//    for(i-1; i<n;i++){
//        key=array[i];
//        j=i-1;
//        while(j>=0 && array[j]>key){
//            array[j+1]=array[j];
//            j=j-1;
//        }
//        array[j+1]=key;
//        
//        //print out each step
//        if (i>1){
//            for(int k=0;k<i;k++){
//                cout <<array[k]<<",";
//            }
//            cout<<endl;
//        }
//    }
//}
//    
//    int main(){
//        int array[100],j,n;
//        
//        //input none of the element
//        cout <<"Enter numbber of ints: "<<endl;
//        cin>>n;
//        
//        //input element in the array itself
//        cout <<"enter ints: "<<endl;
//        for(j=0;j<n;j++){
//            cin>>array[j];
//        }
//        cout <<"sorted ints are:" <<endl;
//        sort_integer(array,n);
//    }


#include<iostream>

#include<string>

using namespace std;

//function for insertion sort

void sort_integer(int array[],int n){

int i,key,j;

for(i=1;i<n;i++){

key=array[i];

j=i-1;

while(j>=0 && array[j]>key){

array[j+1]=array[j];

j=j-1;

}

array[j+1]=key;

//printing step by step

if(i>1){

for(int k=0;k<i;k++){

cout<<array[k]<<",";

}

cout<<endl;

}

}

}

int main(){

int array[100],j,n;

//input no of element

cout<<"Enter Number of Integer: "<<endl;

cin>>n;

//input element in array

cout<<"Enter Integer: "<<endl;

for(j=0;j<n;j++){

cin>>array[j];

}

cout<<"Sorted Integer Is:"<<endl;

sort_integer(array,n);

}