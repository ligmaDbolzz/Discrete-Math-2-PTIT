#include <bits/stdc++.h>
using namespace std;
//The graph is Eulerian graph -> finding Eulerian Circuit
int n;
int a[100][100], b[100][100];
int Stack[100];
int head = 0; 
void push(int u){
	++head;
	Stack[head] = u;
} 
int pop(){
	int top = Stack[head];
	--head;
	return top;
}
bool isEmpty(){
	return(head == -1);
}
void eulerCycle(int u){
	int dCE = 0;
	int CE[100]; //CE[] array store the reversed Eulerian Cycle 
	push(u);
	while(!isEmpty()){
		int s = Stack[head];
		for(int t = 1; t <= n; t++){
			if(a[s][t] == 1){
				push(t);
				a[s][t] = a[t][s] = 0;
				break;
			}
			else if(t == n){
				int v = pop(); 
				++dCE;
				CE[dCE] = v; 
			}
		}
	}
	cout <<"The Eulerian Cuicirt: ";
	for(int i = dCE - 1; i > 0; i--){
		cout << CE[i] << " ";
	}
}
bool Adj(int s){
	for(int i = 1; i <= n; i++){
		if(a[s][i]) return true;
	}
	return false;
} 
void euler_Path(int u){
	int dCE = 0;
	int CE[100]; //CE[] array store the reversed Eulerian Cycle 
	push(u);
	while(!isEmpty()){
		int s = Stack[head];
		if(Adj(s)){
			for(int t = 1; t <= n; t++){
				//t -> the 1st vertex in a[s][t]
				if(a[s][t] == 1){
					push(t);
					a[s][t] = 0;
					break;
				}
			}	
		}
		else{
			int v = pop();
			++dCE;
			CE[dCE] = v;
		}
	}
	cout << "UNDIRECTED Graph: starting from odd deg vertex" << endl;
	cout << "DIRECTED Graph: starting from vertex u (deg+(u) - deg-(u) = 1) to vertex v (deg-(v) - deg+(v) = 1)" << endl;
	cout <<"An Eulerian Path: ";
	for(int i = dCE - 1; i > 0; i--){
		cout << CE[i] << " ";
	}
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
//	eulerCycle(1);
	euler_Path(3);
}
//10
//0 1 0 0 1 0 0 0 0 0
//0 0 1 1 0 0 0 1 0 0
//0 1 0 0 0 1 0 0 0 0
//0 0 0 0 0 1 0 0 0 0
//0 0 0 0 0 0 0 1 1 0
//0 0 0 0 1 0 0 0 0 0
//0 0 0 0 0 0 0 0 0 1
//1 0 0 0 0 0 1 0 0 0
//0 1 0 0 0 0 0 0 0 0
//1 0 0 0 0 0 0 0 0 0
//UNDIRECTED Graph: starting from odd deg vertex
//DIRECTED Graph: starting from vertex u (deg+(u) - deg-(u) = 1) to vertex v (deg-(v) - deg+(v) = 1)
//An Eulerian Path: 3 2 3 6 5 8 1 2 8 7 10 1 5 9 2 4 6
