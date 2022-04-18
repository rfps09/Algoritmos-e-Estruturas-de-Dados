#include <iostream>
    
using namespace std;
    
int somar(int a, int b){
    int sum = a^b;
    int carry = (a&b)<<1;
    
    while(carry){
        a=sum;
        b=carry;
        sum = a^b;
        carry = (a&b)<<1;
    }
    
    return sum;
}
    
int subtrair(int a, int b){
    b = somar(b,-1)^-1;
    return somar(a,b);
}
    
int main() {
    int x=11,y=7;
    
    cin >> x >> y;
    
    cout << subtrair(x,y) << endl;
    
    return 0;
}