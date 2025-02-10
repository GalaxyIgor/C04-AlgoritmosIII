#include<iostream> 
#include<list>
using namespace std;

struct node {
    int info;
    node *left, *right;    
};

// Fun��o para inserir um n�mero na �rvore bin�ria
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

// Fun��o para percorrer a �rvore em n�vel
void in_level(node *curr) {
    list<node *> visit_queue;  // Fila para percorrer em n�vel
    if(curr != NULL) {
        visit_queue.push_back(curr);  // Adiciona o n� raiz � fila
        while(!visit_queue.empty()) {
            node *aux = visit_queue.front();  // Obt�m o n� da frente da fila
            visit_queue.pop_front();  // Remove o n� da fila
            
            // Exibe o valor do n�
            cout << aux->info << " ";
            
            // Adiciona os filhos � fila
            if(aux->left != NULL)
                visit_queue.push_back(aux->left);
            if(aux->right != NULL)
                visit_queue.push_back(aux->right);
        }
    }
}

// Fun��o para liberar a mem�ria da �rvore
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

    // Leitura dos n�meros e inser��o na �rvore at� ler o -1
    while (cin >> num && num != -1) {
        insert(root, num);
    }

    // Mostra o percurso em n�vel
    in_level(root);
    cout << endl;

    // Libera a mem�ria utilizada pela �rvore
    destruct(root);

    return 0;
}
