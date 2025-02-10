#include<iostream>
#include<list>
using namespace std;

struct node {
	   int info;
	   node * left, * right;	
};

void insert(node * & curr, int new_info){
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

node * search(node * curr, int searched_info){
	if(curr == NULL)
		return NULL;
	if(curr->info == searched_info)
		return curr;
	if(searched_info < curr->info){
		return search(curr->left, searched_info);
	} else {
		return search(curr->right, searched_info);
	}	
}


int main(){
	int N;
	cin >> N;
	
	node* root = NULL;
	
	for(int i=0; i<N; i++){
		int x;
		char op;
		cin >> op >> x;
		
		if (op == 'i') {
			insert(root, x);
		}
		else if(op == 'b') {
			node* resultado = search(root, x);
			
			if(resultado != NULL){
				cout << "Sim" << endl;
			}
			else{
				cout << "Não" << endl;
			}
		}
	}

	return 0;
}