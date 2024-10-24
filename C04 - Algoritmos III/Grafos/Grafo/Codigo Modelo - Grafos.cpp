#include <iostream>
using namespace std;

int main(){
	//vertices para o grafo
	int vertice, arestas, origem, destino;
	//entrada das vertices
	cin >> vertice >> arestas;
	//grafo
	bool grafo[vertice][vertice];
	
	//inicializando a matriz
	for(int i=0; i<vertice; i++)
		for(int j=0; j<vertice; j++)
			grafo[i][j] = false;
		
	for(int i=0; i<arestas; i++){
	    cin >> origem >> destino;
	    //se for direcional apenas esse
 	    grafo[origem][destino] = true;
		//se for bi-direcional ambas
		grafo[destino][origem] = true;
    }
    
	//finalização
	for(int i=0; i<vertice; i++){
		for(int j=0; j<vertice; j++)
			cout << grafo[i][j] << " ";
		cout << endl;
	}
	return 0;
}