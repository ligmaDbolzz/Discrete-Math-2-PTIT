#include <bits/stdc++.h> 
//Dijksta Algorithm 
//find the shortest paths from vertex s to other ones
//graphs with "non-negative weights" -> solution by using Dijkstra
using namespace std;
int n, s = 1; 
int a[100][100];
int d[100];
int pre[100];
bool T[100];
//13
//99 2 8 99 99 99 99 99 99 99 99 99 99
//99 99 2 99 99 99 9 99 99 99 99 99 99
//99 99 99 6 99 8 1 99 99 99 99 99 99
//7 99 99 99 99 99 99 99 99 99 99 99 99
//99 99 1 7 99 99 99 99 99 99 99 99 99
//99 99 99 99 1 99 99 9 8 99 99 99 99
//99 99 99 99 99 2 99 2 99 99 99 99 99
//99 99 99 99 99 99 99 99 9 99 99 2 99
//99 99 99 99 99 99 99 99 99 6 99 9 8
//99 99 99 99 7 6 99 99 99 99 99 99 99
//99 99 99 99 99 99 99 99 6 7 99 99 99
//99 99 99 99 99 99 99 99 99 99 99 99 2
//99 99 99 99 99 99 99 99 99 99 7 99 99

//6
//99 1 99 99 99 99
//99 99 5 2 99 7
//99 99 99 99 99 1
//2 99 1 99 4 99
//99 99 99 3 99 99
//99 99 99 99 1 99
bool isEmpty(){
	for(int i = 1; i <= n; i++){
		if(T[i]) return false;
	}
	return true;
}
void print_every_round(){
	for(int i = 1; i <= n; i++){
		if(T[i]) cout << "("<< d[i] << "," << pre[i] << ") ";
		else cout << "(-, -) ";
	}	
	cout << endl;
}
void Dijkstra(int s){
	//step1: Init
	d[s] = 0;
	for(int i = 1; i <= n; i++){
		T[i] = true;
	}
	T[s] = false; //fix s
	pre[s] = s;
	  
	for(int v = 1; v <= n; v++){
		if(T[v]){
			d[v] = a[s][v];
			pre[v] = s;
		}
	}
	cout << endl;
	//Step2: Loop
	while(!isEmpty()){
		print_every_round();
		//find the vertex u such that d[u] min
		int min = INT_MAX;
		int u;
		for(int z = 1; z <= n; z++){
			if(T[z]){
				if(min > d[z]){
					u = z;
					min = d[z];
				}
			}
		}
		
		T[u] = false; // fix the u
		for(int v = 1; v <= n; v++){
			if(T[v]){
				if(d[v] > d[u] + a[u][v]){
					d[v] = d[u] + a[u][v];
					pre[v] = u;
				}
			}
		}	
	}
}

void Result(){
	cout << "RESULT(distance(s, v), path): " << endl;
	for(int v = 1; v <= n; v++){
		cout << "d(" << s << ", " << v << ")= "  << d[v] <<"; " ;
		cout << "path:";
		int i = v;
		while(i != s){
			cout << i << " <- ";
			i = pre[i];
		}
		cout << s << endl;
	}
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	Dijkstra(s);
	Result();
//	int i = 6;
//	while(i != s){
//		cout << i;
//		i = pre[i];
//	}
}
