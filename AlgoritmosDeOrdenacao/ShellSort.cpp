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
void shellSort(RandomAccessIterator primeiro, RandomAccessIterator ultimo) {
    int len = ultimo - primeiro;
    int jump = len/2;

    while(jump) {
        for(int i=jump; i<len; i++) {
            int j=i;
            while(j-jump >= 0 && primeiro[j] < primeiro[j-jump]) {
                troca(primeiro[j],primeiro[j-jump]);
                j-=jump;
            }
        }
        jump/=2;
    }
}

template <class RandomAccessIterator, class Compare>
void shellSort(RandomAccessIterator primeiro, RandomAccessIterator ultimo, Compare Comparer) {
    int len = ultimo-primeiro;
    int jump = len/2;

    while(jump) {
        for(int i = jump; i<len; i++) {
            int j = i;
            while(j-jump >= 0 && Comparer(primeiro[j],primeiro[j-jump])) {
                troca(primeiro[j],primeiro[j-jump]);
                j-=jump;
            }
        }
        jump/=2;
    }
}

int maior(int &a, int &b) {
    return a > b;
}

int main() {
    int vetorTeste[MAXN] = {9,7,3,8,6,2,5,1,4,0};

    shellSort(vetorTeste, vetorTeste+MAXN, maior);

    for(int i=0; i<MAXN; i++)
        cout << vetorTeste[i] << " ";
    
    cout << "\n";

    return 0;
}