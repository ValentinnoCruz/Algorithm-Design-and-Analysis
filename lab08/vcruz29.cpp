

//coped and pasted pseudocode from textbook at bottom 

#include <iostream>
using namespace std;
int q;


int botupwardcutrod(int p[],int n){
    int r[n+1];
    int s[n+1];
    int x=n;
    r[0]=0;
    for(int j=1;j<=n;j++ ){
        q=0;
        for(int i =1;i<=j;i++){
            if(q<p[i]+r[j-i]){
                q=p[i]+r[j-i];
                s[j]=i;
            }
        }
           r[j]=q;
    }
    cout<<r[n]<<endl;
    while (x>0){
        cout<<s[x]<<" ";
        x= x-s[x];
    }
      return -1;

}

int main(int argc, const char * argv[]) {
    int length;
    cin>>length;
    int p[length+1];
    p[0]=0;
    for(int i=1; i<length+1;i++){
        cin>>p[i];
    }
    
  cout<<botupwardcutrod(p, length)<<endl;
    return 0;
}
