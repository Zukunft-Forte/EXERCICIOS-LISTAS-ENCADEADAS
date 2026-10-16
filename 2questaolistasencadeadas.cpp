#include <iostream>
#include <string>
using namespace std;
/* 2 questão listas encadeadas. Opa, prof Alex. Estou colocando comentários nessas questões
para que não tenha que ficar alternando o tempo todo entre o meu código e o pdf com as questões.
A 2ª questão está pedindo: criar uma função inserirInicio que adicione um novo nó antes do primeiro
elemento da lista.*/
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

void inserirInicio(No*& inicio, int valor) { //função principal da questão
    No* novo = new No;

    novo->valor = valor;
    novo->prox = inicio;

    inicio = novo;
}

int main() {
    No* inicio = nullptr;

    inserirInicio(inicio, 20);
    cout << "Após inserirmos o valor 20: ";
    exibir(inicio);

    inserirInicio(inicio, 10);
    cout << "Após inserirmos o valor 10: ";
    exibir(inicio);

    inserirInicio(inicio, 5);
    cout << "Após inserirmos o valor 5: ";
    exibir(inicio);

    while (inicio != nullptr) {
        No* proximo = inicio->prox;
        delete inicio;
        inicio = proximo;
    }

    return 0;
    
    /*OBS: A QUESTÃO SOLICITA PARA QUE SEJA EXPLICADO EM UMA FRASE POR QUE INÍCIO É PASSADO
    POR REFERÊNCIA. Estou respondendo ela nesse comentário(vou informar no readme e na descrição
    de envio da atividade do sava também). 
    RESPOSTA: Porque a função precisa modificar o ponteiro original inicio para 
    que ele passe a apontar para o novo primeiro nó, e No*& permite que essa alteração seja refletida 
    fora da função.*/
}
