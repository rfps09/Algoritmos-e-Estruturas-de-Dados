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
void merge(RandomAccessIterator primeiro, RandomAccessIterator ultimo) {
    int len = ultimo - primeiro;
    int mid = len/2;
    int vetor[len], count=0;

    for(int k=0; k<len; k++)
    vetor[k] = primeiro[k];

    int i=0, j = mid;
    while(i < mid && j < len) {
        if(vetor[i] < vetor[j]) {
            troca(vetor[i], primeiro[count]);
            i++;
        }
        else {
            troca(vetor[j],primeiro[count]);
            j++;
        }
        count++;
    }

    while(count < len) {
        if(i < mid) {
            troca(vetor[i], primeiro[count]);
            i++;
        }
        else {
            troca(vetor[j],primeiro[count]);
            j++;
        }
        count++;
    }
}

template <class RandomAccessIterator>
void mergeSort(RandomAccessIterator primeiro, RandomAccessIterator ultimo) {
    int len = ultimo - primeiro;
    int mid = len/2;
    if(len > 1) {
        mergeSort(primeiro,primeiro+mid);
        mergeSort(primeiro+mid,ultimo);
        merge(primeiro,ultimo);
    }
}


//Comparer ----------------------------------------------------------------------------------------------
//Comparer ----------------------------------------------------------------------------------------------
//Comparer ----------------------------------------------------------------------------------------------
//Comparer ----------------------------------------------------------------------------------------------


template <class RandomAccessIterator, class Compare>
void merge(RandomAccessIterator primeiro, RandomAccessIterator ultimo, Compare Comparer) {
    int len = ultimo - primeiro;
    int mid = len/2;
    int vetor[len], count=0;

    for(int k=0; k<len; k++)
    vetor[k] = primeiro[k];

    int i=0, j = mid;
    while(i < mid && j < len) {
        if(Comparer(vetor[i],vetor[j])) {
            troca(vetor[i], primeiro[count]);
            i++;
        }
        else {
            troca(vetor[j],primeiro[count]);
            j++;
        }
        count++;
    }

    while(count < len) {
        if(i < mid) {
            troca(vetor[i], primeiro[count]);
            i++;
        }
        else {
            troca(vetor[j],primeiro[count]);
            j++;
        }
        count++;
    }
}

template <class RandomAccessIterator, class Compare>
void mergeSort(RandomAccessIterator primeiro, RandomAccessIterator ultimo, Compare Comparer) {
    int len = ultimo - primeiro;
    int mid = len/2;
    if(len > 1) {
        mergeSort(primeiro,primeiro+mid,Comparer);
        mergeSort(primeiro+mid,ultimo,Comparer);
        merge(primeiro,ultimo,Comparer);
    }
}

int maior(int &a, int &b) {
    return a > b;
}

int main() {
    int vetorTeste[MAXN] = {9,7,3,8,6,2,5,1,4,0};

    mergeSort(vetorTeste, vetorTeste+MAXN);

    for(int i=0; i<MAXN; i++)
        cout << vetorTeste[i] << " ";
    
    cout << "\n";

    return 0;
}