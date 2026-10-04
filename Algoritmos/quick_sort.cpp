/*

Algoritmo de Ordenação Quick Sort
Autora: Lara Gomes Gonçalves
Data: 03/10/26

Os dois algortimos tem básicamente a mesma estrutura de recursão, separando o
vetor original dois a partir de um pivô, o que muda é o método de partição em si.
Ao final da partoção, ambos retornam o índice da sepação das partes do vetor.

Descrição do algoritmo de Hoare:
    Dois ponteiros são posicionados no inicio e fim do array, que vão convergindo até encontrarem a posição de partição.
    O pivõ tomado é o primeiro elemento, o ponteiro da esquerda só anda em elementos menores que o pivô, enquanto o da direita
    só move em elementos maiores. Quando os dois param, a troca acontece e o algoritmo se repete.

Descrição do algoritmo de Lomuto:
    Dessa vez, os dois ponteiros se iniciam do começo do array e o pivô escolhido é o último elemento. Enquanto um ponteiro 
    varre o array por completo, o outro para em elementos maiores e então os troca com o que está no outro ponteiro.
    O processo se repete até que todos os elementos maiores que o pivô tenham sido "arrastados" pra direita.
*/

#include <bits/stdc++.h>
#include <windows.h>

typedef long long ll;
using namespace std;

int PartitionHoare(vector<int> &vec, int inic, int fim) {
    int pivo = vec[inic];

    int i = inic - 1;
    int j = fim + 1;
    
    while (1) {
        do { i++; } while(vec[i] < pivo);

        do { j--; } while(vec[j] > pivo);

        if( i >= j) return j;

        swap(vec[i], vec[j]);
    }
}

int PartitionLomuto(vector<int> &vec, int inic, int fim) {
    int pivo = vec[fim];

    int i = inic - 1;

    for(int j = inic; j <= fim - 1; j++) {
        if(vec[j] <= pivo) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    
    swap(vec[i+1], vec[fim]);

    return i+1;
}

void QuickSortHoare(vector<int> &vec, int l, int r) {
    if (l < r) {
        int q = PartitionHoare(vec, l, r);
        QuickSortHoare(vec, l, q);
        QuickSortHoare(vec, q+1, r);
    }
}

void QuickSortLomuto(vector<int> &vec, int l, int r) {
    if (l < r) {
        int q = PartitionLomuto(vec, l, r);
        QuickSortLomuto(vec, l, q-1);
        QuickSortLomuto(vec, q+1, r);
    }
}

int main() {
    ios_base::sync_with_stdio(0);   // otimização que será utilizado em todos os algoritmos
    cin.tie(0);                     // saída é impressa de uma vez só ao final

    SetConsoleOutputCP(CP_UTF8);    // só pra imprimir acentuação

    // Leitura das entradas
    int t;      // quantidade de testes
    cin >> t;
    
    chrono::duration<double, milli> tempoTotalH(0);
    chrono::duration<double, milli> tempoTotalL(0);
    cout << fixed << setprecision(2);

    for(int i = 1; i <= t; i++) {
        int n;  // tamanho da entrada
        cin >> n;
        
        vector<int> vec(n);     // alocação da entrada num vetor
        vector<int> vec2(n);
        for(int j = 0; j < n; j++) {
            cin >> vec[j];
            vec2[j] = vec[j];
        }

        cout << "\nTeste #" << i << endl;

        /* Impressão do vetor original para testes

        cout << "\tVetor Original: ";
        for(int x : vec) cout << x << ' ';
        cout << endl;
        */

        cout << "\n\tParticionamento de Hoare:\n";
        auto inicioH = chrono::high_resolution_clock::now();
        
        QuickSortHoare(vec, 0, n-1);
        
        auto fimH = chrono::high_resolution_clock::now();
        
        /* Impressão do vetor resultante para testes
        
        cout << "\tVetor Ordenado: ";
        for (auto x : vec) cout << x << ' ';
        cout << endl;
        */
        
        chrono::duration<double, milli> tempoDeExecH = fimH - inicioH;
        
        cout << "\tTempo de execução: " << tempoDeExecH.count() << " ms" << endl;
        
        tempoTotalH += tempoDeExecH;
        
        cout << "\n\tParticionamento de Lomuto:\n";
        auto inicioL = chrono::high_resolution_clock::now();
        
        QuickSortLomuto(vec2, 0, n-1);

        auto fimL = chrono::high_resolution_clock::now();

        /* Impressão do vetor resultante para testes
        
        cout << "\tVetor Ordenado: ";
        for (auto x : vec) cout << x << ' ';
        cout << endl;
        */
        
        chrono::duration<double, milli> tempoDeExecL = fimL - inicioL;

        cout << "\tTempo de execução: " << tempoDeExecL.count() << " ms" << endl;
        
        tempoTotalL += tempoDeExecL;

    }

    cout << "\nTempo de execução total Hoare: " << tempoTotalH.count() << " ms" << endl;
    cout << "\nTempo de execução total Lomuto: " << tempoTotalL.count() << " ms" << endl;

    return 0;
}