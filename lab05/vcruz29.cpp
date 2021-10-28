


#include <iostream>
#include<deque>
using namespace std;
static int size;



void radixsort(deque<int> A[], deque<int> B[]);
void cnt_sort(deque<int> A[], deque<int> B[],int pos);

int main(int argc, const char * argv[])
{
    int k;
    cin>>size;
    
    deque<int>A[size];
    deque<int>B[size];
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<10;j++)
        {
            cin>>k;
            A[i].push_back(k);
            
        }
    }
    radixsort(A,B);
    for(int i=0; i<size; i++)
    {
         for(int j=0; j<10;j++)
        {
            cout<<B[i][j]<<";";
        }
        cout<<endl;
    }
 
}


void cnt_sort(deque<int> A[], deque<int> B[],int pos)
{
    //largest # of k possible is 3, so we need a size of 4
    int C[4];
    
    for (int i=0; i < 4; i++)
    {
        C[i]=0;
    }
    
    for (int j=0; j< size; j++)
    {
        C[A[j][pos]]=C[A[j][pos]]+1;
    }
    
    for (int i=1; i < 4; i++)
    {
        C[i]=C[i]+C[i-1];
    }
    
    for (int j = size-1; j>=0; j--)
    {
        B[C[A[j][pos]] - 1] = A[j];
        C[A[j][pos]]=C[A[j][pos]]-1;
    }
}

void radixsort(deque<int> A[], deque<int> B[])
{
    for(int pos = 9; pos>=0;pos--)
    {
        cnt_sort(A, B ,pos);

        for(int i=0;i<size;i++)
        {
            A[i]=B[i];
        }
    }
}
