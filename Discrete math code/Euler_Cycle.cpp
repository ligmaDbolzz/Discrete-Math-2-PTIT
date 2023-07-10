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
void euler_Cycle(int u){
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
					a[s][t] = a[t][s] = 0;
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
	cout <<"The Eulerian Cuicirt: ";
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
	euler_Cycle(1);
}
//13
//0 1 0 0 0 1 0 0 0 0 0 0 0
//1 0 1 0 1 1 0 0 0 0 0 0 0
//0 1 0 1 1 0 0 0 0 0 1 0 0
//0 0 1 0 0 0 1 1 0 0 1 0 0
//0 1 1 0 0 1 1 0 0 0 0 0 0
//1 1 0 0 1 0 1 0 0 0 0 0 0
//0 0 0 1 1 1 0 1 0 0 0 0 0
//0 0 0 1 0 0 1 0 1 1 0 0 0
//0 0 0 0 0 0 0 1 0 1 0 1 1
//0 0 0 0 0 0 0 1 1 0 1 1 0
//0 0 1 1 0 0 0 0 0 1 0 1 0
//0 0 0 0 0 0 0 0 1 1 1 0 1
//0 0 0 0 0 0 0 0 1 0 0 1 0
//The Eulerian Cuicirt: 1 2 3 4 7 5 2 6 5 3 11 4 8 9 10 11 12 9 13 12 10 8 7 6 1
// (slide 12/27 - chap 4) 
