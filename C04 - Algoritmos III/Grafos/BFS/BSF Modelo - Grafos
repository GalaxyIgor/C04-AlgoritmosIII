#include<iostream>
#include<list>

#define MAX_VERTICES 10

using namespace std;

struct Aresta {
	int origem, destino, peso;
};

//void bfs(bool grafo[MAX_VERTICES][MAX_VERTICES], int vertices, int origem){
void bfs(list<Aresta> grafo[], int vertices, int origem){
	bool visitado[vertices];
	list<int> fila_visitacao;
	list<Aresta>::iterator it;
	
	for(int i=0; i<vertices; i++)
		visitado[i] = false;

	cout<<origem<<endl;
	visitado[origem] = true;
	fila_visitacao.push_back(origem);
	
	while(!fila_visitacao.empty()){
		int atual = fila_visitacao.front();
		// for(int i=0; i<vertices; i++){
        for(it = grafo[atual].begin(); it != grafo[atual].end(); it++){
		// 	if(grafo[atual][i] && !visitado[i]){
        int i = it->destino;//(*it).destino;
        if(!visitado[i]){
				cout<<i<<endl;
				visitado[i] = true;
				fila_visitacao.push_back(i);
			}
		}
		fila_visitacao.pop_front();
	}
	bool disconexo = false;
	for(int i=0; i<vertices; i++){
		if(!visitado[i]){
			cout<<"Grafo disconexo"<<endl;
			disconexo = true;
			break;
		}
	}
	if(!disconexo)
		cout<<"Grafo conexo"<<endl;
}


int main(){
	int vertices, arestas, origem, destino;
	cin >> vertices >> arestas;
	
	//bool grafo[vertices][vertices];
	list<Aresta> grafo[vertices];
	list<Aresta>::iterator it;
	
	// for(int i=0;i<vertices;i++)
	// 	for(int j=0;j<vertices;j++)
	// 		grafo[i][j] = false;
		
    for(int i=0; i< arestas; i++){
		cin >> origem >> destino;
		// grafo[origem][destino] = true;
		// grafo[destino][origem] = true;
		grafo[origem].push_back({origem, destino, 0});
		grafo[destino].push_back({destino, origem, 0});
    }
    
    for(int i=0;i<vertices;i++){
		// for(int j=0;j<vertices;j++)
		// 	cout << grafo[i][j] << " ";
		cout<<i<<": ";
		for(it = grafo[i].begin(); it != grafo[i].end(); it++)
			//cout << (*it).destino << "; "
			cout << it->destino << "; ";
		cout<<endl;
	}
	
	bfs(grafo, vertices, 5);
    
	return 0;
}