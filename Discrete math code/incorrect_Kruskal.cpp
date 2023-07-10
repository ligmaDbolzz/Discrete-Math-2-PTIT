#include <bits/stdc++.h>
using namespace std;
//infinity = 99
//99 2 1 3 99 99 99 99 99 99 99 99 99
//2 99 2 99 99 5 5 99 99 99 99 99 99
//1 2 99 4 99 5 99 99 99 99 99 99 99
//3 99 4 99 5 5 99 99 99 99 99 99 99
//99 99 99 5 99 6 99 99 99 6 99 99 99
//99 5 5 5 6 99 6 6 6 6 99 99 99
//99 599 99 99 99 6 99 6 99 99 99 99 99
//99 99 99 99 99 6 99 7 99 99 7 7
//99 99 99 99 99 6 99 7 99 7 7 99 99 
//99 99 99 99 6 6 99 99 7 99 7 7 99
//99 99 99 99 99 99 99 99 7 7 99 8 99
//99 99 99 99 99 99 99 7 99 7 8 99 8
//99 99 99 99 99 99 99 7 99 99 99 8 99


int n;
int a[100][100];
struct Edge{
	int start;
	int end;
	int weight;
};
Edge E[100], T[100];
int E_cnt;
int T_cnt;
void sort(){
	for(int i = 1; i <= E_cnt; i++){
		
	} 
}
bool cmpLength(Edge e1, Edge e2){
	return (e1.weight < e2.weight);
}
bool isNotCircuit(Edge T[]){
	int vertex[] = {0};
	int vertex_num = 0;
	for(int i = 0; i <= n; i++){
		if(vertex[T[i].start] == 0) vertex[T[i].start] = 1; ++vertex_num; 
		if(vertex[T[i].end] == 0) vertex[T[i].end] = 1; ++vertex_num;
	}
	return (vertex_num == T_cnt-1);
}
void Kruskal(){
//	step 1(init)
	T_cnt = 0;
	int d = 0;
//	step 2(sort)
	sort(E, E + E_cnt, cmpLength);
	
//	step 3
	int i = 0;
	while(T_cnt < n - 1 && i < E_cnt){
//		E[i]- minimum length edge
		if(isNotCircuit(T)){
			T[T_cnt] = E[i];
			++T_cnt;
			d = d + T[T_cnt].weight;
		}
		++i; 
	}
	for(int t = 0; t < T_cnt; t++){
		cout << T[t].start << " " << T[t].end << " " << T[t].weight;
	}
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	//because the graph is undirected -> only need to run one-half diagonal side 
	E_cnt = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(a[i][j] != 99){
				E[E_cnt].start = i;
				E[E_cnt].end = j;
				E[E_cnt].weight = a[i][j];
				++E_cnt;
			}
		}
	}
	
}

