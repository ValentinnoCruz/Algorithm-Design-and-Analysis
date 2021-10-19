
#include <iostream>
using namespace std;



int part(int arr[], int p, int r);

int rand_partition(int arr[],int p,int r);

void q_sort(int arr[], int p, int r);



int main() 
{
    int size;

    cin >> size;
    int arr[size];
    
    for(int i = 0; i<size;i++)
    {
        cin >> arr[i];
    }
    q_sort(arr, 0, size-1);
    
    for(int i = 0;i<size;i++)
    {
        cout << arr[i]<<";";
    }
    return 0;
}

/* ====================================================== */

int part(int arr[], int p, int r)
{

    int x = arr[r];
    int i = (p - 1);

    for(int j = p;j <= r-1;j++)
    {
        if(arr[j] <= x)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);

    return (i+1);
}

/* ====================================================== */

// used cplusplus library for help on rand function
int rand_partition(int arr[],int p,int r)
{
    int  random = p + rand() % (r - p);
   
    swap(arr[r],arr[random]);
    
    return part(arr,p,r);
}

/* ====================================================== */

void q_sort(int arr[], int p, int r)
{
    if ( p < r)
    {
      int q = rand_partition(arr,p,r);
        q_sort(arr,p,q-1);
        q_sort(arr,q+1,r);
    }
}