
#include <iostream>
using namespace std;


int SizeofHeap;
int length;
 
 
void sort_heap(int A[]);
void heap_b(int A[]);
void heapify(int A[],int i );
void arr_size(int size);
void heap(int size);
 
 
int main(){
    int size;

    cin>>size;
    heap(size);
    arr_size(size);
    int A[size];
//------------------------------------------
    for(int i=0; i<size; i++)
    {
        cin>>A[i];
    }
    sort_heap(A);
//------------------------------------------ 
    for(int i=0; i<size; i++)
    {
        cout<<A[i]<<";";
    }
}

//------------------------------------------
    void heap(int size)
    {
        SizeofHeap = size;
    }
 //------------------------------------------   
    void arr_size(int size)
    {
        length=size-1;
    }


void heapify(int A[],int i )
{
    int biggest;
    int le = 2*i;
    int ri = 2*i+1;
  
    if (le<SizeofHeap&&A[le]>A[i])
    {
        biggest= le;
    }
 
    else
    {
       biggest =i;
    }

    if(ri<SizeofHeap&&A[ri]>A[biggest])
    {
        biggest=ri;
    }

    if(biggest!=i)
    {
        swap(A[i],A[biggest]);
        heapify(A,biggest);
    }
}

//------------------------------------------
void heap_b(int A[])
{
    for(int i=length/2;i>=0;i--)
    {   
        heapify(A,i);
    }
}
//------------------------------------------
void sort_heap(int A[])
{
    heap_b(A);
    
    for(int i=length;i>=1;i--) 
    {   
        swap(A[0],A[i]);
        SizeofHeap--;
        heapify(A,0);   
    }
}
