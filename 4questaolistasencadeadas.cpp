#include <iostream>
#include <string>
using namespace std;
/* 4 questão listas encadeadas.
Essa questão está me solicitando a criar uma função No*buscar(No*inicio, int alvo)
que retorne o endereço da primeira ocorrência de um valor, ou nullptr, caso ainda não exista.
Devo colocar os valores 3,6 e 9, e depois verificar se ele encontra na lista 3, 9 e 7.*/
struct No {
    int valor;
    No* prox;
};

void inserirFim(No*& inicio, int valor) {
    No* novo = new No;

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

No* buscar(No* inicio, int alvo) {
    No* atual = inicio;

    while (atual != nullptr) {
        if (atual->valor == alvo) {
            return atual;
        }

        atual = atual->prox;
    }

    return nullptr;
}

void exibir(No* inicio) {
    if (inicio == nullptr) {
        cout << "Lista vazia" << endl;
        return;
    }

    No* atual = inicio;

    while (atual != nullptr) {
        cout << atual->valor << " ";
        atual = atual->prox;
    }

    cout << endl;
}

int main() {
    No* inicio = nullptr;

    inserirFim(inicio, 3);
    inserirFim(inicio, 6);
    inserirFim(inicio, 3);
    inserirFim(inicio, 9);

    cout << "Lista atual: ";
    exibir(inicio);

    int valores[] = {3, 9, 7};

    for (int i = 0; i < 3; i++) {
        No* resultado = buscar(inicio, valores[i]);

        if (resultado != nullptr) {
            cout << valores[i] << " , valor encontrado." << endl;

            if (valores[i] == 3) {
                if (resultado == inicio) {
                    cout << "O ponteiro corresponde ao primeiro nó de valor 3."
                         << endl;
                }
            }
        } else {
            cout << valores[i] << " , valor não encontrado." << endl;
        }
    }

    No* vazia = nullptr;
    No* resultado = buscar(vazia, 3);

    if (resultado == nullptr) {
        cout << "Busca na lista atualmente vazia: valor não encontrado." << endl;
    }

    while (inicio != nullptr) {
        No* proximo = inicio->prox;
        delete inicio;
        inicio = proximo;
    }

    return 0;
}
