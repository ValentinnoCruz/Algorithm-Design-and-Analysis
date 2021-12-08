#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

vector<vector<int>>s;
void Exp_Print_Optimal_Parens(vector<vector<int>>s,int i, int j){
if (i == j){
	cout<<"A"<<i-1;
	}
else {
	cout<<"(";
	Exp_Print_Optimal_Parens(s, i, s[i][j]);
	cout<<".";
	Exp_Print_Optimal_Parens(s,s[i][j]+1,j);
	cout<<")";
}
}

int Matrix_Chain_Order(int p[], int n){

//int n = deltasize-1;
int m[n+1][n];
//int s[n][n];
s.resize(n,vector<int>(n+1));
for (int i = 1; i <= n; i++){
	m[i][i] = 0;
	}
for(int l = 2; l <= n; l++){
	for(int i = 1; i <= n - l + 1; i++){
		int j = i+l-1;
		m[i][j] = INT_MAX;
		for(int k = i; k <= j-1; k++){
			int q = m[i][k]+ m[k+1][j]+p[i-1]*p[k]*p[j];
			if(q < m[i][j]){
				m[i][j]=q;
				s[i][j]=k;
				}
			}
		}
	}

int key = m[1][n];
cout<<key<<endl;
Exp_Print_Optimal_Parens(s,1,n);

return key;
}


int main(){

int first;
cin>>first;

int size = first+1;
int p[size];

for(int i = 0; i <=first; i++){
cin>>p[i];
}

int value = Matrix_Chain_Order(p,first);
//cout<<"value is "<<value;
cout<<endl;
return 0;
}
