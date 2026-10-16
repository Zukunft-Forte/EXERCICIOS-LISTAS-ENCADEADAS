#include <iostream>
#include <string>
using namespace std;
/* 1 Questão listas encadeadas.  Lembrando o que a questão solicitou para que 
não precise abrir o pdf o tempo todo:
Como solicitado pelo prof alex na questão, devo usar o new
para criar 3 nós com os valores 10, 20 e 30, respectivamente*/
struct No {
    int valor;
    No* prox; //aqui estou declarando o valor e o nó.
};

void exibir(No* inicio) {
    if (inicio == nullptr) {
        cout << "Lista vazia" << endl;
        return; //aqui criei uma função para verificar a condição da lista, vendo se ela está vazia
    } //com o return encerrando a função imediatamente, evitando que o usuário acesse um nó que não existe.

    No* atual = inicio;

    while (atual != nullptr) {
        cout << atual->valor << " ";
        atual = atual->prox;
    }

    cout << endl;
}

int main() {
    No* inicio = nullptr; //incializando a lista vazia.

    cout << "Teste drive com lista atualmente vazia: ";
    exibir(inicio);

    No* primeiro = new No;
    No* segundo = new No;
    No* terceiro = new No;

    primeiro->valor = 10;
    segundo->valor = 20;
    terceiro->valor = 30;

    primeiro->prox = segundo;
    segundo->prox = terceiro;
    terceiro->prox = nullptr;

    inicio = primeiro;

    cout << "Lista atualmente criada: ";
    exibir(inicio);

    delete terceiro;
    delete segundo;
    delete primeiro;
    inicio = nullptr;

    return 0;
}
