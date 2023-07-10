#include<bits/stdc++.h>
#defind MAX 100
int n, m; // n-> num of vertices, m->num of edges
struct Edge{
	int start;
	int end;
	int weight;
};
Edge G[MAX], T[MAX];
//G - graph (set of edges)
//T - spanning tree (set of edges)
sort_by_weight(){ 
	for(int i = 1; i <= m; i++){
		for(int j = i + 1; j <= m; j++){
			if(G[i].weight > G[j].weight)
				swap(G[i], G[j]);
		}
	}
}
void Prim(s){
	sort_by_weight();
	bool unUsed[m+1]; 
	for(int i = 1; i <= m; i++) unUsed[i] = true;
	int vH[0] = s;
	int v[s] = 0; int v = 1;
	int cnt = 0;
	for(int i = 1; i <= m; i++){
		if(unUsed[i] && cond()){
			Edge e = G[i];
			T[cnt] = e;
			d = d + e.weight;
			vH[v] = e.start;
			v++;
			v[e.start] = 0;
		}
	} 
	
}
int main(){
	for(int i = 1;
} 
