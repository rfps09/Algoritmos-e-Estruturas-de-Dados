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
    
int main() {
    int x=11,y=7;
    
    cin >> x >> y;
    
    cout << somar(x,y) << endl;
    
    return 0;
}