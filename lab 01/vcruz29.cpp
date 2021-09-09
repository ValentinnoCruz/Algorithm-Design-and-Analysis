#include<bits/stdc++.h>
using namespace std;

int main(){
    //get input from file
    string line;
    ifstream myfile ("input.txt"); //input stream
    if (myfile.is_open()){
        getline(myfile,line); //get first line
        int n = atoi(line.c_str()); //size of array
        int a[n]; //array to store elements
        int x = 0;
        while ( getline (myfile,line) ){
            a[x++] = atoi(line.c_str());
        }
        myfile.close();

        //Insertion sort
        for (int i=1;i<n;i++) {
            int key = a[i];
            int j = i - 1;
            while (j>=0 && a[j]>key) {
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = key;
            for(j=0;j<=i;j++){
                cout << a[j] << ";";
            }
            cout << endl;
        }

    }
    else {
        cout << "Unable to open file";
    }
}