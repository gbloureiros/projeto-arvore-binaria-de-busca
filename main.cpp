#include <iostream>
using namespace std;

struct No {
    int dado;
    No* esquerda;
    No* direita;

    No(int valor) {
        dado = valor;
        esquerda = NULL;
        direita = NULL;
    }
};

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return new No(valor);
    }
    if (valor < raiz->dado) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->dado) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

bool buscar(No* raiz, int valor) {
    if (raiz == NULL) {
        return false;
    }
    if (raiz->dado == valor) {
        return true;
    }
    if (valor < raiz->dado) {
        return buscar(raiz->esquerda, valor);
    }
    return buscar(raiz->direita, valor);
}

void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        cout << raiz->dado << " ";
        emOrdem(raiz->direita);
    }
}

void preOrdem(No* raiz) {
    if (raiz != NULL) {
        cout << raiz->dado << " ";
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        cout << raiz->dado << " ";
    }
}

int main() {
    No* raiz = NULL;
    int escolha, valor;

    do {
        cout << "\nMenu:\n";
        cout << "1. Inserir valor\n";
        cout << "2. Buscar valor\n";
        cout << "3. Exibir arvore em ordem\n";
        cout << "4. Exibir arvore em pre-ordem\n";
        cout << "5. Exibir arvore em pos-ordem\n";
        cout << "0. Sair\n";
        cout << "Escolha: ";
        cin >> escolha;

        switch (escolha) {
            case 1:
            	system("cls");
                cout << "Digite o valor a ser inserido: ";
                cin >> valor;
                raiz = inserir(raiz, valor);
                cout << "Valor " << valor << " inserido com sucesso.\n";
                break;
            case 2:
            	system("cls");
                cout << "Digite o valor a ser buscado: ";
                cin >> valor;
                if (buscar(raiz, valor)) {
                    cout << "Valor " << valor << " encontrado na arvore.\n";
                } else {
                    cout << "Valor " << valor << " nao encontrado na arvore.\n";
                }
                break;
            case 3:
            	system("cls");
                cout << "Arvore em ordem: ";
                emOrdem(raiz);
                cout << endl;
                break;
            case 4:
            	system("cls");
                cout << "Arvore em pre-ordem: ";
                preOrdem(raiz);
                cout << endl;
                break;
            case 5:
            	system("cls");
                cout << "Arvore em pos-ordem: ";
                posOrdem(raiz);
                cout << endl;
                break;
            case 0:
                cout << "\nSaindo...\n";
                break;
            default:
                cout << "Erro! Tente novamente.\n";
                system("pause");
        }
    } while (escolha != 0);

    return 0;
}

