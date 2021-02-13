
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <array>
#include <stack>
#define infinity 9999

using namespace std;

bool visit[infinity];
int j=1;

void DFS(int n, list<int>adj[], int arr[], int num);
void hashsearch(list<int>T[], int k,int num,bool found[]);
void dfs2(int n, list<int>t[], list<int>Final[], int in);
void insert(int vericies, int edge, list<int>adj[]);
void printtable(int num, list<int>adj[]);
void trans(list<int>T[],list<int>adj[],int num );
void Scc(list<int>T[],int nums, int arr[],list<int>Final[]);
void order(int arr[], int num, int order[]);


int main(int argc, const char * argv[]) {
    int loop=0;
    int num;
    cin>>num;
    int arr[num];
    int S[num];
    list<int>adj[num];
    list<int>t[num];
    list<int>Final[num];
    cin>>loop;
    int verticies;
    int edges;
    for(int l=0; l<loop;l++){
    cin>> verticies>>edges;
        insert(edges, verticies, adj);
    }
    trans(t,adj,num);

        DFS(0,adj,arr,num);

    for (int v=0;v<num;v++){
        if(!visit[v]){
            arr[v]=j+2;
        }
       // cout<<arr[v];
        visit[v]=NULL;
    }
      order(arr,num,S);
    Scc(t, num, S, Final);
  
    for (int v=0;v<num;v++){
        if(!visit[v]){
            Final[v].push_back(v);

        }
    }
 // printtable(num, Final);
    bool foud[num];
   for(int p=0;p<num;p++){
       
   hashsearch(Final, p, num,foud);
   }
}
void DFS(int n, list<int>adj[], int arr[], int num){
    j++;
    list<int>::iterator it;
    for(it = adj[n].begin();it!=adj[n].end();it++){
if (!visit[*it]){
    visit[*it]=true;
    DFS(*it,adj,arr,num);

}
        if(visit[*it]){
            j++;
        }
      
    }
      arr[n]=j;
}
void hashsearch(list<int>T[], int k,int num,bool found[]){
    list <int> :: iterator it;
    for(int p =0; p<num;p++){
    for(it = T[p].begin(); it != T[p].end(); ++it){
        if(*it==k){
            cout<<p<<endl;
            found[k]=true;
            break;
        }
       
    }
     
    }
    if(!found[k]){
        cout<<k<<endl;
    }
}

void dfs2(int n, list<int>t[], list<int>Final[], int in)
{
    list<int>::iterator it;
    for(it = t[n].begin();it!=t[n].end();it++){
        if (!visit[*it]){
        Final[in].push_back(n);
            visit[*it]=true;
            dfs2(*it,t,Final,in);
        }
      
    }
}
void insert(int vericies, int edge, list<int>adj[]){
    adj[edge].push_back(vericies);
}
void printtable(int num, list<int>adj[]){
    list <int> :: iterator it;
    for(int i = 0; i<num;i++){
        cout<<i<<":";
        for(it = adj[i].begin(); it != adj[i].end(); ++it){
            cout<<*it<<"->";
}
        cout<<";"<<endl;
    }
}
void trans(list<int>T[],list<int>adj[],int num ){
    list <int> :: iterator it;
    for(int i = 0; i<num;i++){
        for(it = adj[i].begin(); it != adj[i].end(); ++it){
             T[*it].push_back(i);
        }
    }
}
void Scc(list<int>T[],int nums, int arr[],list<int>Final[]){
    for(int i =0; i<nums;i++){
        //Final[i].push_back(i);
        if(!visit[i]){
          //

    dfs2(arr[i], T, Final,arr[i]);
        }
    }
    
}

void order(int arr[], int num, int order[]){
    int o =0;
    for (int i =0; i <num;i++){
        o =distance(arr, max_element(arr, arr + num));
        order[i]=o;
        arr[o]=0;
    }
    
}