#include <bits/stdc++.h>
using namespace std;
int n; // number of vertices
int a[100][100]; // adjacency matrix
int Queue[100];
int head = 0;
int tail = -1;
bool unTraverse[100];
void push(int u){
	++tail;
	Queue[tail] = u;
}
int pop(){
	int front = Queue[head];
	++head;
	return front;
}
bool isEmpty(){
	if(head > tail) 
		return true;
	return false;
}
void Reinit(){
	for(int i = 1; i <= n; i++) 
		unTraverse[i] = true;
}
void BFS(int u){
	Reinit();
		
	push(u);
	unTraverse[u] = false;
	while(!isEmpty()){
		int s = pop();
//		cout << s << " ";
		for(int t = 1; t <= n; t++){
			if(a[s][t] == 1 && unTraverse[t]){
				push(t);
				unTraverse[t] = false;
			}
		}
	} 
}
void conComp(){
	Reinit();
	int count = 0;
	for(int u = 1; u <= n; u++){
		if(unTraverse[u]){
			++count;
			BFS(u);
		}
	}
	cout << "The number of connected components: " << count << endl;
} 
int previous[100];
void findPath(int s){
	Reinit();
	push(s);
	unTraverse[s] = false;
	
	while(!isEmpty()){
		int s = pop();
		for(int t = 1; t <= n; t++){
			if(a[s][t] == 1 && unTraverse[t]){
				push(t);
				unTraverse[t] = false;
				previous[t] = s;
			}
		}
	}
}
void pathRestore(int start, int end){
	findPath(start);
	cout << "The path from " << start << " -> " << end << ": ";
	while(end != start){
		cout << end << " <- ";
		end = previous[end];
	}
	cout << start << endl;
	// you should use a Stack to print back the result
}
void findingCutVertices(){
	Reinit();
//	previous[100]= {0};
	cout << "The cut vertices have found: ";
	for(int u = 1; u <= n; u++){
		unTraverse[u] = false;
		int s = 1;
		if(u == 1) s = 2;
		BFS(s);
		for(int i = 1; i <= n; i++){
			if(unTraverse[i]){
				cout << u << " ";
				break;
			}
		}
	}
	cout << endl;
}
void findingBridges(){  
	Reinit();	
	cout << "The bridges have found: ";
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] == 1){
				a[i][j] = 0;
				BFS(1);
				for(int t = 1; t <= n; t++){
					if(unTraverse[t]){
						cout << i <<"-"<< j << " ";
						break;
					}
				// return edge e to to the graph
				a[i][j] = 1;
				}
			}
		}
	}
	cout << endl;
}
void strongly_Connected(){
	cout << "Strongly_Connected if BFS(u) = V: ";
	bool flag = 1;
	for(int u = 1; u <= n; u++){
		BFS(u);
		for(int i = 1; i <= n; i++){
			if(unTraverse[i] == true){
				flag = 0;
				break;
			}
		}
	}
	if(flag) cout << "Strongly Connected";
	else cout << "NOT Strongly Connected";
}
int main(){
	cin >> n;
	for(int i = 1;  i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
//	BFS(1);
	conComp();
	pathRestore(1, 7);
	findingCutVertices();
	findingBridges();
	strongly_Connected(); 
} 
//8
//0 0 1 0 0 0 0 0
//1 0 0 1 0 0 0 0
//0 1 0 1 0 0 0 0
//0 0 0 0 1 0 0 1
//0 1 0 0 0 0 0 0
//0 0 0 0 1 0 0 0
//0 0 0 1 0 1 0 0
//0 0 0 0 0 0 1 0

//BFS(1) = 1 3 2 4 5 8 7 6
