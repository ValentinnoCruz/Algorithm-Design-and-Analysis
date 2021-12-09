//I used the textbook and lecture notes to finish the lab


#include <iostream>

using namespace std;



int hashFunction(int k,int i){
int j = (((k % 13) + i*(1 + k % 11)) % 13);
return j;

}


int insert(int T[], int k){
int i = 0;
int j;
while (i < 13){
	j = hashFunction(k,i);
	if (T[j]==999){
		T[j] = k;
		return j;
		}
	else {
		i++;
	}
	}
//cout<<"ERROR HASH TABLE OVERFLOW"<<endl;
return 0;

}

int search(int T[], int k){
int i = 0;
int j;
int yeet = 0;
while(i < 13){
	j = hashFunction(k,i);
	if (T[j]==k){
		cout<<j<<endl;
		yeet = 1;
		}
	i=i+1;
	if(T[j]==999){
	cout<<"NOT_FOUND"<<endl;
	break;
	}
	}
if (yeet != 1){
cout<<"NOT_FOUND"<<endl;
}
return 0;


}

int deletion(int T[], int k){
int i = 0;
int j;
while(i < 13){
	j = hashFunction(k,i);
	if (T[j]==k){
		T[j] = 998;
		}
	i=i+1;
	if(T[j]==999){
	//cout<<"NOT_FOUND"<<endl;
	break;
	}
	}
//cout<<"NOT_FOUND"<<endl;
return 0;


}

void output(int T[]){

for (int i = 0; i < 13; i++){
if (T[i] == 998 || T[i] == 999) {
cout<<endl;
}
if (T[i] != 998 || T[i] == 999){
cout<<T[i]<<endl;
}
}
}

int main(){

int full=0;
int send= 200;
int checks=0;
int sentinal = 999;
int T[13];
for(int i = 0; i < 13; i++){
T[i] = sentinal;
}


while(full<send){
int key;
cin>>key;
while(key != -1){
	insert(T,key);
	break;
	}
if (key == -1){
	output(T);
	full = 200;
}
}
while(full==send){
int look;
cin>>look;
while(look != -2){
	search(T, look);
	break;
	}
if(look == -2){
	full = 201;
	}
}
while(checks < send){
int remove;
cin>>remove;
while(remove != -3){
	deletion(T, remove);
	break;
	}
if(remove == -3){
	output(T);
	checks = 201;
	}
}

return 0;
}














