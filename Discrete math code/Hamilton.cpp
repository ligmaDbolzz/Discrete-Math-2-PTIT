#include <bits/stdc++.h>
using namespace std;
int n;
int a[100][100];
int X[100];
bool unChecked[100];
void init(){
	for(int i = 1; i <= n; i++){
		unChecked[i] = true;
	}
}
void Hamilton(int k){
	for(int y = 1; y <= n; y++){
		//a[X[k-1]][y] = 1 -> y is in the adjacency vertex X[k-1]
		if(a[X[k-1]][y] == 1){
			if(k == n + 1 && y == X[1]){ //stop condition  
				for(int i = 1; i <= n; i++){
					cout << X[i] << " ";
				}
				cout << X[1] << endl;;
			}
			else if(unChecked[y]){
				X[k] = y;
				unChecked[y] = false;
				Hamilton(k + 1);
				unChecked[y] = true;
			}
		}
	}
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	
	//Listing all Hamiltonian Circuits
	init();
	//X[1] = 1 -> start from 1 (v0)
	X[1] = 1; unChecked[1] = false;
	cout << "List of all Hamiltonian circuits starting form vertex X[1]:" << endl;
	Hamilton(2);
}
//5
//0 1 0 1 0
//1 0 1 0 1
//0 1 0 1 1
//1 0 1 0 1
//0 1 1 1 0
//List of all Hamiltonian circuits starting form vertex X[1]:
//1 2 3 5 4 1
//1 2 5 3 4 1
//1 4 3 5 2 1
//1 4 5 3 2 1
