#include <bits/stdc++.h>
using namespace std;
int n;
int a[100][100];
int d[100]; 
int pre[100];
//5
//99 1 99 99 3
//99 99 3 3 8
//99 99 99 1 -5
//99 99 2 99 99
//99 99 99 4 99
void print_every_round(){
	for(int v = 1; v <= n; v++){
		cout << "(" << d[v] << ", " << pre[v] << ") ";
	}
	cout << endl;
}
Bellman_Ford(int s){
	//Init
	for(int v = 1; v <= n; v++){
		d[v] = a[s][v];
		pre[v] = s;
	}
	d[s] = 0;
	cout << "Init: "; print_every_round();
	//Loop
	for(int k = 1; k <= n - 1; k++){
		for(int v = 1; v <= n; v++){
			if(v != s){
				for(int u = 1; u <= n; u++){
					if(d[v] > d[u] + a[u][v]){
						d[v] = d[u] + a[u][v];
						pre[v] = u;
					}
				}
			}
		}
		cout << "k = " << k << ": ";
		print_every_round();
	}
}
 
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	Bellman_Ford(1);
}
