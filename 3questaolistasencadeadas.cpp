#include <iostream>
#include <string>
using namespace std;
/* 3 questão da lista de exercícios sobre listas encadeadas. 
ela está solicitando que: implementar inserirFim(No*& inicio, int valor), 
percorrendo a lista até o último nó e adicionando um novo elemento ao final.
Até que um pouco parecida com a anterior, porém a posição da inserção é o diferencial,
já que nessa, os valores devem permanecer na ordem que foram devidamente inseridos
pelo usuário.*/
struct No {
    int valor;
    No* prox;
};

void exibir(No* inicio) {
    if (inicio == nullptr) {
        cout << "Lista atualmente vazia" << endl;
        return;
    }

    No* atual = inicio;

    while (atual != nullptr) {
        cout << atual->valor << " ";
        atual = atual->prox;
    }

    cout << endl;
}

void inserirFim(No*& inicio, int valor) { //aqui, o nó recebe o valor solicitado e o seu campo próximo
    No* novo = new No;                   //será inicializado com nullptr. Fiz isso pois ele deve ser o último nó da lista.

    novo->valor = valor;
    novo->prox = nullptr;

    if (inicio == nullptr) {
        inicio = novo;
        return;
    }

    No* atual = inicio;

    while (atual->prox != nullptr) {
        atual = atual->prox;
    }

    atual->prox = novo;
}

int main() { 
    No* inicio = nullptr;

    inserirFim(inicio, 8);
    cout << "Após inserirmos o valor 8: ";
    exibir(inicio);

    inserirFim(inicio, 12);
    cout << "Apóss inserirmos o valor 12: ";
    exibir(inicio);

    inserirFim(inicio, 16);
    cout << "Após inserirmos o valor 16: ";
    exibir(inicio);

    while (inicio != nullptr) {
        No* proximo = inicio->prox;
        delete inicio;
        inicio = proximo;
    }
//inserindo no fim, estamos buscando o último nó e fazendo seu campo prox apontar para um novo nó.
    return 0;
}
