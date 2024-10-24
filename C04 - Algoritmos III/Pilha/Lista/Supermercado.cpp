#include <iostream>
#include <list>

using namespace std;

void gerenciar_listas(list<pair<int, int>>& operacoes) {
    list<int> estoque;
    list<int> venda;

    for (auto& operacao : operacoes) {
        if (operacao.first == 1) {
            // Adiciona ao estoque
            estoque.push_back(operacao.second);
        } else if (operacao.first == 2 && !estoque.empty()) {
            // Move para venda
            venda.push_front(estoque.front());
            estoque.pop_front();
        }
    }

    // Exibe o estoque
    cout << "Estoque: ";
    for (int produto : estoque) {
        cout << produto << " ";
    }
    cout << endl;

    // Exibe a venda
    cout << "Venda: ";
    for (int produto : venda) {
        cout << produto << " ";
    }
    cout << endl;
}

int main() {
    list<pair<int, int>> operacoes = {
        {1, 10},
        {1, 20},
        {2, 0},
        {1, 30},
        {1, 40},
        {2, 0},
        {2, 0}
    };

    gerenciar_listas(operacoes);

    return 0;
}
/*Um gerente de supermercado possui duas listas, sendo a primeira com os códigos de produtos que estão no estoque, e a segunda com os códigos dos produtos que já estão disponíveis para venda. 
Sempre que um produto novo chega, primeiro ele é adicionado no estoque, e depois é movido para venda, à medida em que os produtos vão sendo vendidos. 

Ele precisa de alguém para gerenciar essas listas e contratou você para o serviço.

Entrada
A primeira linha contém um único inteiro N, que corresponde ao número de operações.
Depois seguem-se N linhas, sendo que cada linha corresponde a uma operação.
Se o primeiro número da linha  for 1, você deverá ler o código do produto e colocá-lo no estoque;
Se for 2, você deverá pegar um elemento do estoque e colocá-lo para venda.
Saída
A saída deverá mostrar quais elementos estão no estoque e quais estão disponíveis para venda.

Exemplo de entrada   
Exemplo de saída
5
1 15
1 19
2
1 33
2
Estoque: 33
Venda: 19 15



*/