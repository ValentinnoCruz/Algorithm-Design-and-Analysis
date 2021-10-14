#include <limits.h> 
#include <iostream>

using namespace std;


int MaxCrosSubA(int arr[], int low, int mid, int high) ;
int MaxSubArr(int arr[], int low, int high);

int main() 
{ 
    int size;
    cin >> size;
        
    int arr[size];
        
        for (int i = 0; i < size; i++) 
        {
        	cin >> arr[i];
        }
           int max_sum = MaxSubArr(arr, 0, size-1); 
           cout<< max_sum; 
           return max_sum; 
}

int MaxCrosSubA(int arr[], int low, int mid, int high) 
{ 
    int sum = 0; 
    int L_sum = INT_MIN; 
    for (int i = mid; i >= low; i--) 
    { 
        sum = sum + arr[i]; 
        if (sum > L_sum) 
          L_sum = sum; 
    } 
  
    sum = 0; 
    int R_sum = INT_MIN; 
    for (int i = mid+1; i <= high; i++) 
    { 
        sum = sum + arr[i]; 
        if (sum > R_sum) 
          R_sum = sum; 
    } 
  
    return L_sum + R_sum; 
} 
  

int MaxSubArr(int arr[], int low, int high) 
{ 

   if (low == high)
    {
     return arr[low]; 
    }

   int mid = (low + high)/2; 
   if (MaxSubArr(arr, low, mid) >= MaxSubArr(arr, mid+1, high) && 
       MaxSubArr(arr, low, mid) >= MaxCrosSubA(arr, low, mid, high))
    {
       return MaxSubArr(arr, low, mid);
    }
    
   if (MaxSubArr(arr, low, mid) <= MaxSubArr(arr, mid+1, high) && 
       MaxSubArr(arr, mid+1, high) >= MaxCrosSubA(arr, low, mid, high))
    {
       return MaxSubArr(arr, mid+1, high);
    }
    
   if (MaxCrosSubA(arr, low, mid, high) >= MaxSubArr(arr, mid+1, high) && 
       MaxSubArr(arr, low, mid) <= MaxCrosSubA(arr, low, mid, high))
    {
       return MaxCrosSubA(arr, low, mid, high);
    }
return 0;
}
