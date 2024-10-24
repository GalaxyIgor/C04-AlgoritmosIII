#include<iostream>
#include<list>
#include<string>
using namespace std;

#define INT_MAX 99999

struct Upgrade{
	int orig;
	int dest;
	int custo;
};

struct Habilidade {
	string nome;
	int codigo;
	float poder; 
	list<Upgrade> upgrades;
};

void bfs_poder_acumulado(Habilidade adj[], int vertices, int start, float poder_acumulado[]){
	
	bool visited[vertices];
	list<int> to_visit_queue;
	
	for(int i=0;i<vertices;i++){
		visited[i] = false;
	}
	
	visited[start] = true;
	to_visit_queue.push_back(start);
	
	while(!to_visit_queue.empty()){
		int curr = to_visit_queue.front();
		to_visit_queue.pop_front();
		list<Upgrade>::iterator p;
		for(p=adj[curr].upgrades.begin();p!=adj[curr].upgrades.end();p++){
			int dest = p->dest;
			if(!visited[dest]){
				visited[dest] = true;
				to_visit_queue.push_back(dest);
				poder_acumulado[dest] += poder_acumulado[curr];
			}				
		}
			
	}
	return ;	
}


int shortest_path_dijkstra(Habilidade adj[], float poder_acumulado[], int vertices, int start){
	bool intree[vertices];
	int distance[vertices], parent[vertices];
	
	for(int u = 0; u < vertices; u++){
        intree[u] = false;
        distance[u] = INT_MAX;
        parent[u] = -1;
	}
    distance[start] = 0;
    int v = start;
    while(intree[v] == false){
        intree[v] = true;
		list<Upgrade>::iterator p;
    	for(p = adj[v].upgrades.begin(); p != adj[v].upgrades.end(); p++){
            int dest = p->dest;
            int weight = p->custo;
            if(distance[dest] > distance[v]+weight){
                distance[dest] = distance[v]+weight;
                parent[dest] = v;
			}
		}
        v = 0;
        int dist = INT_MAX, poder = 0;
        for(int u = 0; u < vertices; u++){
            if(intree[u]==false && distance[u]<dist){
                dist = distance[u];
                v = u;
			}
		}
	}
	int dist = INT_MAX;
	for(int u = 0; u < vertices; u++){
        if(intree[u]==true && distance[u] < dist){
            dist = distance[u];
		}
	}
	return dist;
}

int main(){
    
    //Use as fun��es e as structs fornecidas para resolver a atividade.
    // N�o esque�a de fazer os ajustes necess�rios nas fun��es para que elas retornem o resultado esperado.
    
    // Tome cuidado com a passagem de par�metros. 
    // Verifique cada um deles e tente enteder o que cada um deles traz de informa��o para resolver o problema.
    
    // Voc� tamb�m pode implementar a sua pr�pria solu��o.
    
    int H;
    cin >> H;
    
    Upgrade upgrades[H];
    Habilidade habilidades[H];
    
    for(int i = 0; i < H; i++){
        habilidades[i].codigo = i;
    }
    
	
	
}
/*
10
Land 0
Dash 1
Thief 3
Hunter 3
Assassin 4
BeastMaster 5
Berserker 7
WildMagic 2
Vengeance 4
Life 5
9
0 1 1
1 2 2
1 3 2
3 4 3
3 5 3
3 6 4
0 7 2
7 8 3
7 9 3
7

5
---------


Poles est� desenvolvendo uma �rvore de habilidades para o seu jogo de RPG. Ele quer que os personagens possam escolher, partindo de uma habilidade principal, algumas ramifica��es poss�veis. 
Para cada upgrade de habilidade, o personagem deve gastar alguns pontos de experi�ncia e pode adquirir alguma pontua��o de poder.
<imagem>
Ele quer saber, dada um determinada �rvore de habilidadades, qual � o custo m�nimo de experi�ncia para ter um determinado valor de poder.

Entrada
A entrada come�a com um n�mero inteiro indicando a quantidade H de habilidades. As H linhas seguintes cont�m o nome (palavra) e o poder (n�mero real) de cada habilidade (cada habilidade tem um c�digo autom�tico de 0 a H de acordo com a entrada de dados).
Em seguida � informado um valor inteiro indicando a quantidade U de upgrades poss�veis. As U linhas seguintes cont�m tr�s inteiros indicando o c�digo da habilidade origem, o c�digo da habilidade destino e o custo de cada upgrade.
Por fim, � informado um n�mero real que � o valor de poder desejado.

Sa�da
A sa�da � um n�mero inteiro indicando o custo m�nimo para se conseguir o n�vel de poder desejado. 

*/