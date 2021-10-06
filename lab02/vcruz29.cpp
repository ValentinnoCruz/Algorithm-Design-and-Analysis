
#include <iostream>
using namespace std;

void merge_sort(int Array[],int low,int high);
void merge(int Array[], int low, int mid, int high);

int main() {
    int length;

    cin >> length;
    int Array[length];
   
    for (int i=0; i<length; i++)
    {
        cin>>Array[i];
    }
    merge_sort(Array,0,length-1);
    for(int i=0;i<length;i++)
    {
        cout << Array[i] << ";";

    }
    
}


void merge(int Array[], int low, int mid, int high)
{
    //a=n1
    int a = mid-low+1,i,j,k;
    int b = high-mid;
    int Left[a];
    int Right[b];

    for (int i=0; i<a; i++ )
    {
        //i = low;
        Left[i]=Array[low+i]; //moves first half of values to l[]
    }
    
    for (int j =0; j<b; j++ )
    {
        Right[j]=Array[mid+j+1]; //moves next half value into r[]
    }
    i = 0;j = 0;
    
    for (k = low; i < a && j < b; k++ )
    {
        if (Left[i] < Right[j])
        {
            Array[k] = Left[i++];
        }
            else
            {
                Array[k]=Right[j++];
            }
    }

    // left array will merge back
    while(i < a)
    {
        Array[k++] = Left[i++];
    }

    // right array will merge back
    while (j < b)
    {
        Array[k++] = Right[j++];
    }
}
    void merge_sort(int Array[],int low,int high)
    {
        int mid;
        
        if(low < high)
        {
            // Seeks out the middle index
            mid = (low + high)/2;
            
            // array breaks off to Left-Leftsub
            merge_sort(Array,low,mid);
            
            // array breaks off to right-rightsub
            merge_sort(Array,mid+1,high);
            
            // merge
            merge(Array,low,mid,high); 
        }

    }
