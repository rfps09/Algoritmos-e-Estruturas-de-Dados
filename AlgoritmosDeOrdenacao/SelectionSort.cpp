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
void selectionSort(RandomAccessIterator primeiro, RandomAccessIterator ultimo) {
    int len = ultimo-primeiro;
    for(int i=0;i<len;i++) {
        int menor = i;
        for(int j=i; j<len; j++) 
        if(primeiro[menor] > primeiro[j]) menor = j;
        troca(primeiro[i],primeiro[menor]);
    }
}

template <class RandomAccessIterator, class Compare>
void selectionSort(RandomAccessIterator primeiro, RandomAccessIterator ultimo, Compare Comparer) {
    int len = ultimo-primeiro;
    for(int i=0;i<len;i++) {
        int menor = i;
        for(int j=i; j<len; j++) 
        if(Comparer(primeiro[j],primeiro[menor])) menor = j;
        troca(primeiro[i],primeiro[menor]);
    }
}

int maior(int &a, int &b) {
    return a < b;
}

int main() {
    int vetorTeste[MAXN] = {9,7,3,8,6,2,5,1,4,0};

    selectionSort(vetorTeste, vetorTeste+MAXN, maior);

    for(int i=0; i<MAXN; i++)
        cout << vetorTeste[i] << " ";
    
    cout << "\n";

    return 0;
}