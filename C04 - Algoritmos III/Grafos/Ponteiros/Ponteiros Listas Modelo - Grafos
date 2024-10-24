#include <iostream>
#include <list>
using namespace std;

int main(){
	
	int a;
	a = 25;
	cout<< a << endl; // apresentando o conteúdo de a
	cout<< &a << endl; // apresentando o endereço de a
	
	int * p;
	p = &a;
	cout << p << endl; // apresentando o conteúdo de p
	// perceba que é o endereço de a
	cout << *p << endl; // apresentando o conteúdo do endereço apontado por p
	// perceba que é o conteúdo de a
	
	*p = 26; // mundando o conteúdo do endereço apontado por p
	cout << a << endl; // perceba que o conteúdo de a mudou
	
	
	int vetor[10];
	cout << vetor << endl; 
	//perceba que ao mostrar o conteúdo de um vetor sem indicar a posição é mostrado um endereço
	cout<< &vetor[0] << endl; 
	// o conteúdo de vetor é o endereço da sua primeira posição
	
	vetor[0] = 10;
	cout << vetor[0] << endl;
	cout << (*vetor) << endl;
	
	*vetor = 25
	cout << vetor[0] << endl;
	//usando a mesma lógica de ponteiros podemos manipular suas posições
	
	*(vetor+2) = 36;
	cout << vetor[2] << endl;
	// tanto a primeira como qualquer outra posição
	
	//----------------------------------------------
	
	
	
	list<int> a; // criando uma lista de inteiros
	
	a.push_back(25);
	a.push_back(10);
	a.push_back(13); // adicionando elementos (lófica de fila / FIFO)
	
	list<int>::iterator p;
	for(p = a.begin(); p != a.end(); p++){
		cout << *(p) << endl; // aprensetando os elementos
	}
	
	
	a.push_front(25);
	a.push_front(10);
	a.push_front(13); // adicionando mais elementos na lógica de pilha / LIFO
	
	for(p = a.begin(); p != a.end(); p++){
		cout << *(p) << endl; // aprensetando os elementos
	}
	return 0;
}