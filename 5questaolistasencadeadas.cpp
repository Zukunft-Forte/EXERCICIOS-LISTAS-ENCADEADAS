#include <iostream>
#include <string>
using namespace std;
/* 5 e última questão das listas encadeadas! Essa questão solicita que a gente percorra a lista,
alterar os ponteiros, remover nós e liberar memória. É o boss final do pdf, realmente. Reúne tudo dele.*/
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

bool remover(No*& inicio, int alvo) {
    No* atual = inicio;
    No* anterior = nullptr;

    while (atual != nullptr) {
        if (atual->valor == alvo) {
            if (anterior == nullptr) {
                inicio = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

            delete atual;
            return true;
        }

        anterior = atual;
        atual = atual->prox;
    }

    return false;
}

void liberarLista(No*& inicio) {
    No* atual = inicio;

    while (atual != nullptr) {
        No* proximo = atual->prox;

        delete atual;

        atual = proximo;
    }

    inicio = nullptr;
}

int main() {
    No* inicio = nullptr;

    inserirFim(inicio, 4);
    inserirFim(inicio, 7);
    inserirFim(inicio, 4);
    inserirFim(inicio, 9);

    cout << "1ª Lista: ";
    exibir(inicio);

    int alvos[] = {4, 4, 9, 99};

    for (int i = 0; i < 4; i++) {
        bool resultado = remover(inicio, alvos[i]);

        cout << "\nRemover " << alvos[i] << ": ";

        if (resultado) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }

        cout << "Lista atualmente: ";
        exibir(inicio);
    }

    cout << "\n=====TESTE: APENAS UM NÓ =======" << endl;

    No* unica = nullptr;
    inserirFim(unica, 50);

    cout << "Antes: ";
    exibir(unica);

    cout << "Remover 50: "
         << (remover(unica, 50) ? "true" : "false") << endl;

    cout << "Depois: ";
    exibir(unica);

    cout << "\n======TESTE: AGORA ESTANDO LISTA VAZIA========" << endl;

    cout << "Remover 10: "
         << (remover(unica, 10) ? "true" : "false") << endl;

    cout << "Lista: ";
    exibir(unica);

    cout << "\n======FIM: LIBERANDO LISTAS ======" << endl;

    liberarLista(inicio);
    liberarLista(unica);

    if (inicio == nullptr && unica == nullptr) {
        cout << "As listas foram liberadas com sucesso. Ponteiros estão atualmente iguais a nullptr."
             << endl;
    }

    return 0;
    
/*Ok, a questão pede para que eu diga decisões de implementações, testes, etc. Irei responder
nesse comentário, ao final do código. Vamos lá.

Decisões de implementação:

utilizei a estrutura No, com os campos valor e prox 
o ponteiro inicio foi com nullptr, para que eu conseguisse representar uma lista vazia 
a função exibir está utilizando um ponteiro auxiliar, para que que consiga percorrer a lista sem que alteremos o início
As funções de inserção e remoção recebem inicio por referência (No*&),
pois elas podem modificar o primeiro nó da lista.
A busca retorna o endereço do primeiro nó que contém o valor procurado ou nullptr 
quando o valor não existe.
A remoção atualiza as ligações antes de liberar o nó com delete.
A função liberarLista guarda o endereço do próximo nó antes de liberar o nó atual.

Resultado dos testes para cada questão: 

1ª Questão: a lista vazia foi corretamente identificada, e a lista com 3 nós exibiu os valores solicitados(10, 20 e 30)
2ª Questão: As inserções presentes no início produziram as listas 20, depois 10 --> 20 e, por fim, 5 --> 10 --> 20
3ª Questão: as inserções no fim produziram 8, depois 8 --> 12. Finalizando o programa, ficomos com: 8 -- > 12 --> 16, nessa ordem.
4ª Questão: as buscas por 3 e 9 deram certo, enquanto a busca por 7 retornou nullptr. A busca em uma lista vazia também retornou nullptr.
5ª Questão: as remoções dos valores 4, 4 e 9 deu bem demais, só sucesso. A remoção de 99 não encontrou correspondência. 
Também testei a remoção do único nó e a tentativa de remoção em uma lista vazia.

Dificuldades:

No geral, senti mais dificuldade em como atualizar os ponteiros sem perder o acesso aos nós restantes.
Também apanhei bastante na diferenciação entre remoção de um nó e da liberação da lista toda.
No geral, consegui desenrolar e resolver todas essas broncas. A atividade me ajudou a compreender mais 
a implementação do uso de No* quando o início de uma lista precisa ser alterado, além da verificação de nullptr 
antes de acessar um nó, e por fim a necessidade de liberar memória dinâmicamente.
*/
}
