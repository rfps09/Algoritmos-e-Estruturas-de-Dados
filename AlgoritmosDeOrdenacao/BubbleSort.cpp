#include <iostream>

using namespace std;

const int MAXN = 10;

template <class Random>
void troca(Random &a, Random &b) {
    Random aux = a;
    a = b;
    b = aux;
}

template <class RandomAccessIterator>
void bubbleSort(RandomAccessIterator primeiro, RandomAccessIterator ultimo) {
    int len = ultimo - primeiro;
    for(int i=1; i<=len; i++)
    for(int j=0; j < len-i; j++)
    if(primeiro[j] > primeiro[j+1])
    troca(primeiro[j],primeiro[j+1]);
}

int main() {
    int vetorTeste[MAXN] = {9,7,3,8,6,2,5,1,4,0};

    bubbleSort(vetorTeste, vetorTeste+MAXN);

    for(int i=0; i<MAXN; i++)
        cout << vetorTeste[i] << " ";
    
    cout << "\n";

    return 0;
}