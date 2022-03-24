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
void insertionSort(RandomAccessIterator primeiro, RandomAccessIterator ultimo) {
    int len = ultimo-primeiro;
    for(int i=1;i<len;i++) {
        int j=i;
        while(j && primeiro[j-1] > primeiro[j] ){
            troca(primeiro[j-1],primeiro[j]);
            j--;
        }
    }
}

template <class RandomAccessIterator, class Compare>
void insertionSort(RandomAccessIterator primeiro, RandomAccessIterator ultimo, Compare Comparer) {
    int len = ultimo-primeiro;
    for(int i=1;i<len;i++) {
        int j=i;
        while(j && Comparer(primeiro[j],primeiro[j-1])){
            troca(primeiro[j-1],primeiro[j]);
            j--;
        }
    }
}

int maior(int &a, int &b) {
    return a > b;
}

int main() {
    int vetorTeste[MAXN] = {9,7,3,8,6,2,5,1,4,0};

    insertionSort(vetorTeste, vetorTeste+MAXN,maior);

    for(int i=0; i<MAXN; i++)
        cout << vetorTeste[i] << " ";
    
    cout << "\n";

    return 0;
}