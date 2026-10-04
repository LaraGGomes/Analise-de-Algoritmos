#include <iostream>
#include <vector>
#include <random>
#include <fstream>

using namespace std;

int main() {
    // Cria o arquivo de texto com os casos
    ofstream out("entradas.txt");
    
    // Escalas de 100 até 1.000.000 (5 tamanhos)
    vector<int> tamanhos = {100, 1000, 10000, 100000, 1000000};
    int num_testes = tamanhos.size() * 4; // 20 testes
    
    out << num_testes << "\n\n";
    
    mt19937 rng(42); // Semente fixa para testes reproduzíveis
    
    // 1. Aleatório Uniforme (Testes 1 ao 5)
    for (int n : tamanhos) {
        out << n << "\n";
        uniform_int_distribution<int> dist(1, 1000000000);
        for(int i = 0; i < n; i++) out << dist(rng) << (i == n - 1 ? "" : " ");
        out << "\n\n";
    }
    
    // 2. Poucos Únicos (Testes 6 ao 10)
    for (int n : tamanhos) {
        out << n << "\n";
        uniform_int_distribution<int> dist5(1, 5);
        for(int i = 0; i < n; i++) out << dist5(rng) << (i == n - 1 ? "" : " ");
        out << "\n\n";
    }
    
    // 3. Ordenado (Testes 11 ao 15)
    for (int n : tamanhos) {
        out << n << "\n";
        for(int i = 1; i <= n; i++) out << i << (i == n ? "" : " ");
        out << "\n\n";
    }
    
    // 4. Inverso (Testes 16 ao 20)
    for (int n : tamanhos) {
        out << n << "\n";
        for(int i = n; i >= 1; i--) out << i << (i == 1 ? "" : " ");
        out << "\n\n";
    }
    
    out.close();
    cout << "Arquivo entradas.txt gerado com sucesso! (20 testes agrupados por tipo)\n";
    return 0;
}