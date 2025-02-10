#include<iostream> 
#include<list>
using namespace std;

struct node {
    int info;
    node *left, *right;    
};

// Função para inserir um número na árvore binária
void insert(node *&curr, int new_info){
    if(curr == NULL){
        curr = new node;
        curr->info = new_info;
        curr->left = NULL;
        curr->right = NULL;
    } else {
        if(new_info < curr->info){
            insert(curr->left, new_info);
        } else {
            insert(curr->right, new_info);
        }
    }
}

// Função para percorrer a árvore em nível
void in_level(node *curr) {
    list<node *> visit_queue;  // Fila para percorrer em nível
    if(curr != NULL) {
        visit_queue.push_back(curr);  // Adiciona o nó raiz à fila
        while(!visit_queue.empty()) {
            node *aux = visit_queue.front();  // Obtém o nó da frente da fila
            visit_queue.pop_front();  // Remove o nó da fila
            
            // Exibe o valor do nó
            cout << aux->info << " ";
            
            // Adiciona os filhos à fila
            if(aux->left != NULL)
                visit_queue.push_back(aux->left);
            if(aux->right != NULL)
                visit_queue.push_back(aux->right);
        }
    }
}

// Função para liberar a memória da árvore
void destruct(node *&curr){
    if(curr != NULL){
        destruct(curr->left);
        destruct(curr->right);
        delete curr;
        curr = NULL;
    }
}

int main() {
    node *root = NULL;
    int num;

    // Leitura dos números e inserção na árvore até ler o -1
    while (cin >> num && num != -1) {
        insert(root, num);
    }

    // Mostra o percurso em nível
    in_level(root);
    cout << endl;

    // Libera a memória utilizada pela árvore
    destruct(root);

    return 0;
}
