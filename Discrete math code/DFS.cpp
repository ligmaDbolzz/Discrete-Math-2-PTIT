#include <bits/stdc++.h>
using namespace std;
int n;
int a[100][100];
int Stack[100];
int head = 0;
bool unTraverse[100];
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
	return (head == -1);
}
void DFS(int u){
	for(int i = 1; i <= n; i++)
		unTraverse[i] = true;
	
	push(u);
	unTraverse[u] = false;
	cout << u << " ";
	while(!isEmpty()){
		int s = pop();
		for(int t = 1; t <= n; t++){
			if(a[s][t] == 1 && unTraverse[t]){
				push(s);
				push(t);
				unTraverse[t] = false;
				cout << t << " ";
				break;
			}
		}
	}
}
void strongly_Connected(){
	for(int u = 1; u <= n; u++){
		DFS(u);
		cout << endl;
//		for(int i = 1; i <= n; i++)
//			if(unTraverse[i]) 
//				return false;
	}
//	return true;
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
//	DFS(1);
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
