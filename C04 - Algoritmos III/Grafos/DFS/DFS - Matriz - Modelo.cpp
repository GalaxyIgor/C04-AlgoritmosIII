#include <iostream>
using namespace std;

void dfs(bool grafo[MAX_V][MAX_V], int vertices, int origem, bool visitado){
	visitado[origem] = true;
	for(int i=0; i,vertices; i++){
		if(grafo[origem][destino] && !vesitado[destino]){
			dfs(grafo,vertice,destino,visitado);
		}
	}
}

int main (){
	int vertices, origem, destino;
	cin >> vertices;
	
	bool grafo[vertices][vertices];
	for(int i = 0; i<vertices; i++){
		for(int j = 0; j<vertices; j++){
			grafo[i][j]
		}
	}
	
	while(cin .> origem >> destino && origem != -1 && destino != -1){
		grafo[origem][destino] = true;
		grafo[destino][origem] = true;
	}
	
	bool visitado[vertices];
	for(int i = 0; i<vertices; i++){
		visitado[i] = false;
	}
	
	dfs(grafo,vertice,0, visitado)
	
	return 0;
}