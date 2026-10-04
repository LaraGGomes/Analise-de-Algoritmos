/*

Algoritmo de Ordenação Insertion Sort
Autora: Lara Gomes Gonçalves
Data: 03/10/26

Descrição do algoritmo:
    Inserção dos elementos é feita um elemento por vez, de forma que os elementos anteriores 
    a uma nova inserção já estejam ordenados. 
    O novo elemento é comparado ao seu imediato vizinho e, caso seja menor, movido para
    a esquerda até ser posicionado corretamente.

*/

#include <bits/stdc++.h>
#include <windows.h>

typedef long long ll;
using namespace std;

void InsertionSort(vector<int> &vec, int n) {
    int pivo;

    for(int i = 1; i < n; i++) {
        pivo = vec[i];
        int j = i - 1;

        while(j >= 0 && vec[j] > pivo) {
            vec[j+1] = vec[j];
            j--;
        }

        vec[j+1] = pivo;
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

        InsertionSort(vec, n);

        auto fim = chrono::high_resolution_clock::now();

        /* Impressão do vetor ressultante para testes
        
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