/*

Algoritmo de Ordenação Merge Sort
Autora: Lara Gomes Gonçalves
Data: 03/10/26

Descrição do algoritmo:
    A parte recursiva se resume a separar o vetor em duas partes iguais (ou quase) repetidamente até 
    ter os elementos únicos e voltar na pilha recursiva juntando esses elementos de forma ordenada.

    No Merge, as duas partes separadas são iteradas por ponteiros, de forma que o menor pro maior de elemento
    de ambas são inseridos ordenadamente no vetor original.

*/

#include <bits/stdc++.h>
#include <windows.h>

typedef long long ll;
using namespace std;

const int INF = 10e6 + 100;

void Merge(vector<int> &vec, int p, int q, int r) {
    vector<int> L(vec.begin() + p, vec.begin() + q+1);
    vector<int> R(vec.begin() + q+1, vec.begin() + r+1);
    
    L.push_back(INF);
    R.push_back(INF);

    int i = 0, j = 0;

    for(int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        }
        else {
            vec[k] = R[j];
            j++;
        }
    }
}

void MergeSort(vector<int> &vec, int p, int r)  {
    if (p < r) {
        int q = floor(p+(r-p)/2);
        MergeSort(vec, p, q);
        MergeSort(vec, q+1, r);
        Merge(vec, p, q, r);
    }
}

int main() {
    ios_base::sync_with_stdio(0);   // otimização que será utilizado em todos os algoritmos
    cin.tie(0);                     // saída é impressa de uma vez só ao final

    SetConsoleOutputCP(CP_UTF8);    // só pra imprimir acentuação

    // Leitura das entradas
    int t;      // quantidade de testes
    cin >> t;

    chrono::duration<double, milli> tempoTotal(0);
    cout << fixed << setprecision(2);

    for(int i = 1; i <= t; i++) {
        int n;  // tamanho da entrada
        cin >> n;
        
        vector<int> vec(n);     // alocação da entrada num vetor
        for(int j = 0; j < n; j++) cin >> vec[j];

        cout << "\nTeste #" << i << endl;

        /* Impressão do vetor original para testes

        cout << "\tVetor Original: ";
        for(int x : vec) cout << x << ' ';
        cout << endl;
        */
        
        auto inicio = chrono::high_resolution_clock::now();

        MergeSort(vec, 0, n-1);

        auto fim = chrono::high_resolution_clock::now();

        /* Impressão do vetor resultante para testes
        
        cout << "\tVetor Ordenado: ";
        for (auto x : vec) cout << x << ' ';
        cout << endl;
        */

        chrono::duration<double, milli> tempoDeExec = fim - inicio;

        cout << "\tTempo de execução: " << tempoDeExec.count() << " ms" << endl;

        tempoTotal += tempoDeExec;
    }

    cout << "\nTempo de execução total: " << tempoTotal.count() << " ms" << endl;

    return 0;
}