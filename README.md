# Análise de Algoritmos de Ordenação
_Atividade Prática Supervisionada 2 de APA_

## Visão Geral
Cada arquivo contento a implementação do algoritmo de ordenação possui a descrição do respectivo algoritmo. 
Todos os arquivos possuem a mesma estrutura geral e da main (mostrada a seguir), contendo a medição do tempo de execução.

```
#include <bits/stdc++.h>
#include <windows.h>

typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);   // otimização que será utilizado em todos os algoritmos
    cin.tie(0);                     // saída é impressa de uma vez só ao final

    SetConsoleOutputCP(CP_UTF8);    // só pra imprimir acentuação

    // Leitura das entradas
    int t;      // quantidade de testes
    cin >> t;

    chrono::duration<double, milli> tempoTotal(0);

    for(int i = 1; i <= t; i++) {
        int n;  // tamanho da entrada
        cin >> n;
        
        vector<int> vec(n);     // alocação da entrada num vetor
        for(int j = 0; j < n; j++) cin >> vec[j];

        cout << "\nTeste #" << i << endl;

        cout << "\tVetor Original: ";
        for(int x : vec) cout << x << ' ';
        cout << endl;
        
        auto inicio = chrono::high_resolution_clock::now();

        // { Chamada de função do algoritmo de ordenação }

        cout << "\tVetor Ordenado: ";
        for (auto x : vec) cout << x << ' ';
        cout << endl;

        auto fim = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> tempoDeExec = fim - inicio;

        cout << fixed << setprecision(2);
        cout << "\tTempo de execução: " << tempoDeExec.count() << " ms" << endl;

        tempoTotal += tempoDeExec;
    }

    cout << "\nTempo de execução total: " << tempoTotal.count() << " ms" << endl;

    return 0;
}
```

A impressão do vetor original e do ordenado foi feita apenas quando eu estava testando os algoritmos.

## Casos Teste
Os casos testes foram agrupados nos quatro tipos diferentes de array solicitados.

Além disso, foram criados testes pequenos para visualização da main disponíveis no arquivo testes.txt e testes grandes (com arrays de tamanho entre 100 e 10e7) para testar o tempo de execução. 

Esse segundo tipo foi gerado pelo arquivo gerador.cpp (criado por IA) e armazenado no arquivo entradas.txt. 
Das entradas grandes: 
- Tamanho 100: Entradas #1, #6, #11, #16
- Tamanho 1000: Entradas #2, #7, #12, #17
- Tamanho 10000: Entradas #3, #8, #13, #18
- Tamanho 100000: Entradas #4, #9, #14, #19
- Tamanho 1000000: Entradas #5, #10, #15, #20

### Valores aleatórios com distribuição uniforme
Nas entradas teste, temos as seguintes entradas:
- Aleatorio 1:
    - Tamanho 8
    - [42 17 99 3 56 81 22 14]

- Aleatorio 2
    - Tamanho 10
    - [512 12 873 44 91 1024 333 7 65 88]

- Aleatorio 3
    - Tamanho 12
    - [100 45 9 21 67 89 32 11 5 78 93 2]

- Aleatorio 4
    - Tamanho 15
    - [3 8 12 1 99 45 23 76 54 88 11 29 67 34 90]

Nas entradas grandes, elas representam os testes #1 - #5.

### Arrays com poucos valores únicos
Nas entradas teste, temos as seguintes entradas:
- Poucos Unicos 1:
    - Tamanho 10
    - [1 2 1 1 3 2 1 3 2 1]

- Poucos Unicos 2
    - Tamanho 12
    - [5 5 5 8 5 8 8 5 5 8 8 5]

- Poucos Unicos 3
    - Tamanho 12
    - [4 4 4 4 4 4 4 4 4 4 4 4]

- Poucos Unicos 4
    - Tamanho 15
    - [7 9 7 7 7 9 9 7 7 7 9 7 7 9 7]

Nas entradas grandes, elas representam os testes #6 - #10.

### Arrays já ordenados 
Nas entradas teste, temos as seguintes entradas:
- Ordenado 1:
    - Tamanho 8
    - [1 2 3 4 5 6 7 8]

- Ordenado 2
    - Tamanho 10
    - [10 20 30 40 50 60 70 80 90 100]

- Ordenado 3
    - Tamanho 12
    - [-5 -2 0 3 7 11 15 18 22 25 30 42]

- Ordenado 4
    - Tamanho 13
    - [2 4 6 8 10 12 14 16 18 20 22 24 26]

Nas entradas grandes, elas representam os testes #11 - #15.

### Arrays ordenados em ordem inversa 
Nas entradas teste, temos as seguintes entradas:
- Inverso 1:
    - Tamanho 8
    - [8 7 6 5 4 3 2 1]

- Inverso 2
    - Tamanho 10
    - [100 90 80 70 60 50 40 30 20 10]

- Inverso 3
    - Tamanho 12
    - [42 30 25 22 18 15 11 7 3 0 -2 -5]

- Inverso 4
    - Tamanho 13
    - [26 24 22 20 18 16 14 12 10 8 6 4 2]

Nas entradas grandes, elas representam os testes #16 - #20. 

> **Cada um deles foi aplicado a todos os algoritmos implementados.**

## Metodologia dos Testes
Depois de testar se todos os algoritmos estavam funcionais com os testes acima, mudei a main geral para que não fossem mais impressos o array completo antes e depois da ordenação, para não lotar o terminal e apenas serem visíveis os tempos de execução para os testes grandes.

Caso queira testar, basta compilar o algoritmo desejado:
```
g++ algoritmo.cpp -o algoritmo -O3
```
E no cmd:
```
algoritmo.exe < entradas.txt
```

Ou no Powershell:
```
cmd /c "algoritmo.exe < entradas.txt"
```

## Resultados Obtidos
As colunas representam cada tipo de algoritmo de ordenação, enquanto as linhas são cada caso teste, do #1 até #20.

|       | Insertion | Selection | Quick (Hoare) | Quick (Lomuto) | Merge    | Tamanho da entrada(N) | Tipo da entrada |
|-------|-----------|-----------|---------------|----------------|----------|-----------------------|-----------------|
| #1    | 0.00 ms   | 0.01 ms   | 0.00 ms       | 0.00 ms        | 0.12 ms  |          100          |    Aleatório    |
| #2    | 0.07 ms   | 0.54 ms   | 0.04 ms       | 0.03 ms        | 0.48 ms  |          1000         |        \|       |
| #3    | 6.37 ms   | 57.67 ms  | 0.50 ms       | 0.43 ms        | 2.87 ms  |         10000         |        \|       |
| #4    | 0.66 s    | 9.15 s    | 6.15 ms       | 5.04 ms        | 40.85 ms |         100000        |        \|       |
| #5    | 64.46 s   | 16.7 min  | 75.81 ms      | 56.87 ms       | 287.3 ms |        1000000        |        \|       |
| #6    | 0.00 ms   | 0.01 ms   | 0.00 ms       | 0.00 ms        | 0.22 ms  |          100          |      Únicos     |
| #7    | 0.06 ms   | 0.61 ms   | 0.02 ms       | 0.08 ms        | 0.33 ms  |          1000         |        \|       |
| #8    | 5.19 ms   | 27.85 ms  | 0.16 ms       | 5.05 ms        | 2.86 ms  |         10000         |        \|       |
| #9    | 0.53 s    | 108.9 s   | 2.73 ms       | 541.38 ms      | 62.53 ms |         100000        |        \|       |
| #10   | 51.99 s   | 3.33 min  | 18.26 ms      | Não rodou :(   | 0.326 s  |        1000000        |        \|       |
| #11   | 0.0 ms    | 3.06 min  | 0.00 ms       | 0.01 ms        | 0.13 m   |          100          |     Ordenado    |
| #12   | 0.00 ms   | 3.04 min  | 0.13 ms       | 0.25 ms        | 1.09 ms  |          1000         |        \|       |
| #13   | 0.01 ms   | 2.90 min  | 21.58 ms      | 35.62 ms       | 9.28 ms  |         10000         |        \|       |
| #14   | 0.10 ms   | 2.92 min  | 1.47 s        | 2.82 s         | 47.76 ms |         100000        |        \|       |
| #15   | 0.85 ms   | 2.98 min  | 2.9 min       | Não rodou :(   | 0.30 s   |        1000000        |        \|       |
| #16   | 0.00 ms   | 3.15 min  | 0.01 ms       | 0.00 ms        | 0.15 ms  |          100          |    Invertidos   |
| #17   | 0.16 ms   | 3.30 min  | 0.23 ms       | 0.27 ms        | 0.5 ms   |          1000         |        \|       |
| #18   | 22.03 ms  | 3.81 min  | 25.00 ms      | 26.87 ms       | 3.05 ms  |         10000         |        \|       |
| #19   | 1.29 s    | 3.60 min  | 2.30 s        | 2.70 s         | 39.36 ms |         100000        |        \|       |
| #20   | 2.1 min   | 2.87 min  | Não rodou :(  | Não rodou :(   | 0.36 s   |        1000000        |        \|       |
|       |           |           |               |                |          |                       |                 |
| Total | 246.61 s  | 53.7 min  | 177.91 s      | ???            | 1.49 s   |                       |                 |


_Usei o site [Tables Generator](https://www.tablesgenerator.com/markdown_tables#) pra criação das tabelas. Também deixei os resultados disponíveis no formato csv no arquivo **Resultados.csv**_

Vale comentar que para a compilação de **todos** os algoritmos, eu utilizei a flag de otimização *-O3*, para que não demorassem tanto. Para ter noção da diferença de tempo de execução geral, abaixo estão asss comparações entre o tempo de execução dos Insertion e Selection Sorts, com e sem a flag.

|     | Insertion s/flag | Insertion c/flag | Selection s/flag | Selection c/flag | Tamanho da entrada | Tipo da entrada |
|-----|------------------|------------------|------------------|------------------|--------------------|-----------------|
| #1  | 0.01 ms          | 0.0 ms           | 0.12 ms          | 0.01 ms          |         100        |    Aleatório    |
| #2  | 1.04 ms          | 0.07 ms          | 6.54 ms          | 0.54 ms          |        1000        |        \|       |
| #3  | 0.11 s           | 0.006 s          | 0.77 s           | 0.57 s           |        10000       |        \|       |
| #4  | 10.95 s          | 0.66 s           | 83.74 s          | 9.15 s           |       100000       |        \|       |
| #5  | 18.5 min         | 64.46 s          | **2.13 horas**   | 16.7 min         |       1000000      |        \|       |
| #6  | 0.01 ms          | 0.00 ms          | 0.04 ms          | 0.01 ms          |         100        |      Únicos     |
| #7  | 0.88 ms          | 0.06 ms          | 2.80 ms          | 0.61 ms          |        1000        |        \|       |
| #8  | 0.89 s           | 0.005 s          | 0.60 s           | 0.02 s           |        10000       |        \|       |
| #9  | 9.12 s           | 0.53 s           | 37.93 min        | 108.9 s          |       100000       |        \|       |
| #10 | 15.5 min         | 51.99 s          | 20.48 min        | 3.33 min         |       1000000      |        \|       |

De 2 horas pra 16 minutos no caso teste #5... Foi ai que eu decidi usar a flag para todos os algoritmos.

## Observações e Comparações entre os Algoritmos
Os resultados foram bem curiosos e mais variados do que eu esperava.

### Sobre o Quick Sort
Primeiro que o Quick Sort com partição de Lomuto não rodou em quase todos os testes com 10e6 elementos, o que provalvemente pode ser explicado pela grande quantidade de swaps que ele faz (como discutido em aula) e principalmente pelo algoritmo ter caido no **pior caso**, particionando o array em unidades, o que faz com que a complexidade seja ***O(n^2)***, mesmo motivo pelo qual o Quick Sort com partição de Hoare não funcionou para a entrada #20. Por isso que coloquei o tempo total do Quick Sort Lomuto como '???', visto que não temos uma comparação justa com os outros algoritmos por vários testes não terem funcionado.

Ainda sobre o Quick Sort, o método com partição de Hoare apenas falhou no #20, mesmo que ele também tenha caído no pior caso no testes com array originalmente ordenado. Minha teoria é que isso se dá pelo fato do algoritmo escolher o primeiro elemento como pivô, talvez isso seja o motivo pelo qual o algoritmo teve pior desempenho com arrays invertidos.

### Sobre o Insertion Sort
O Insertion Sort refletiu perfeitamente o comportamento esperado. Teve um crescimento de tempo de execução praticamente proporcional ao tamanho da entrada, e o pior tempo foi justamente o array invertido com maior n dos testes, que era o pior caso desse algoritmo. Inclusive, ele teve um ótimo desempenho em arrays ordenados, como vimos que é o melhor caso dele, sendo de todos o mais rápido nesse tipo de entrada. De longe, esse foi o algoritmo com comportamento mais previsível de todos.

### Sobre o Selection Sort
Também como esperado, o Selection Sort foi definitivamente o pior algoritmo em desempenho. Mas algo de estranho aconteceu, que não sei se foi erro na implementação ou um comportamento inesperado do algoritmo em si, mas nos testes ordenados e invertidos, praticamente todos os tempos se mantiveram numa mesma média de minutos, mesmo com os tamanhos das entradas aumentando. Acho que tem relação com o jeito que as trocas acontecem, porque como vimos em sala, arrays invertidos não são o pior caso desse algoritmo, dado que ao trocar de lugar o primeiro com o último, metade do array já está sendo ordenado. 

Além disso, para não falar só mal do algoritmo, note que ele não falhou nenhuma vez! Mesmo nas entradas em que o Quick Sort não foi capaz de rodar. Ele demorou (mais que duas horas dependendo do caso) mas acabou!

### Sobre o Merge Sort
Honestamente me surpreendeu.

Eu sabia que o algoritmo era constantemente ***O(nlog(n))***, mas ainda tinha a percepção que o Quick Sort seria no geral melhor que ele, justamente por causa das cópias feitas dentro do merge. Eu estava errada!!! (Não sobre as cópias, mas sobre o desempenho)

A consistência é justamente o que fez dele um algoritmo muito bom pra maioria dos casos. Em entradas com número de elementos (n) menor, ele realmente não foi muito bom em comparação aos outros. Mas praticamente em todas as entradas grandes dos tipos Únicos, Ordenados e Invertidos, ele foi disparado o melhor, e não passou de **1 segundo** em **nenhum** dos testes! Virei fã.

## Conclusões
Foi muito interessante ver o funcionamento de cada algoritmo mais detalhadamente. Como falei, fui surpreendida com alguns resultados, mas todos eles tem bastante relação com o que vimos na análise assintótica deles.

No geral é isso, me diverti e se passaram mais de 5 horas e o Selection Sort sem flag de otimização ainda não terminou de rodar!