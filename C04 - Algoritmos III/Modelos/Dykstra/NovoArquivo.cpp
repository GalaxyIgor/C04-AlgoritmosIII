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
    
    //Use as funções e as structs fornecidas para resolver a atividade.
    // Não esqueça de fazer os ajustes necessários nas funções para que elas retornem o resultado esperado.
    
    // Tome cuidado com a passagem de parâmetros. 
    // Verifique cada um deles e tente enteder o que cada um deles traz de informação para resolver o problema.
    
    // Você também pode implementar a sua própria solução.
    
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


Poles está desenvolvendo uma árvore de habilidades para o seu jogo de RPG. Ele quer que os personagens possam escolher, partindo de uma habilidade principal, algumas ramificações possíveis. 
Para cada upgrade de habilidade, o personagem deve gastar alguns pontos de experiência e pode adquirir alguma pontuação de poder.
<imagem>
Ele quer saber, dada um determinada árvore de habilidadades, qual é o custo mínimo de experiência para ter um determinado valor de poder.

Entrada
A entrada começa com um número inteiro indicando a quantidade H de habilidades. As H linhas seguintes contêm o nome (palavra) e o poder (número real) de cada habilidade (cada habilidade tem um código automático de 0 a H de acordo com a entrada de dados).
Em seguida é informado um valor inteiro indicando a quantidade U de upgrades possíveis. As U linhas seguintes contêm três inteiros indicando o código da habilidade origem, o código da habilidade destino e o custo de cada upgrade.
Por fim, é informado um número real que é o valor de poder desejado.

Saída
A saída é um número inteiro indicando o custo mínimo para se conseguir o nível de poder desejado. 

*/