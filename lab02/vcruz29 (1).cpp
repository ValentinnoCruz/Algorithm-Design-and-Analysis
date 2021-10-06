#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <vector>

#define RAN_MAX 327

using namespace std;

//functions

void mergeSort(int *v, int p, int q, int r);
void merge(int *v, int p, int r);
int MAX_VAL = 65536;


void merge(int *v, int p, int q, int r) {

    int j, i;
    int k = 0;
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1+1], R[n2+1];

    for (i = 0; i < n1; i++)
        L[i] = v[p + i];
    for (j = 0; j < n2; j++)
        R[j] = v[q +1 + j];
    i = j = 0;
    k = p;

    while (i < n1 && j < n2){
        if ((L[i] <= R[j])){
            v[k] = L[i];
            i++;
        }

        else{
            v[k] = R[j];
            j++;
        }
        k++;

    }

    while (i < n1){

        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        v[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *v, int p, int r) {
    int q;//middle
    
        if (p < r) {
            q = (p + r) / 2;
            mergeSort(v, p, q);
            mergeSort(v, q + 1, r);
            merge(v, p, q, r);
        }

}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++)
        cout<< arr[i]<<";";
}





int main()
{

    int n;
    cin>>n;

    int *a = new int[n];

        for(int i=0;i<n;++i)
        cin>>a[i];
        mergeSort(a,0,n-1);
        printArray(a, n);

}