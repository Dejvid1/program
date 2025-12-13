#include <iostream>
#include <vector>
using namespace std;
void fiboInTab(int numer);
void fiboInLoop(int numer);
long long fibo(int numer);
int main()
{
    int numer = 0;
    cout << "podaj numer ciagu" << endl; cin >> numer;
    //fiboInTab(numer);
    //fiboInLoop(numer);
    //cout<<fibo(numer);
    return 0;
}
void fiboInTab(int numer) {
    if (numer == 0) { cout << 0; return;}
    vector<long long> tab(numer + 1);
    tab[0] = 0;
    tab[1] = 1;

    for (int i = 2; i <= numer; i++) {
        tab[i] = tab[i - 1] + tab[i - 2];
    }
    cout << tab[numer];
}
void fiboInLoop(int numer) {
    if (numer == 0) { cout << 0; return; }
    if (numer == 1) { cout << 1; return; }
    long long val = 0;
    long long val1 = 1;
    long long temp = 0;
    for (int i = 2; i <= numer; i++) {
        temp = val + val1;
        val = val1;
        val1 = temp;
    }
    cout << temp;
}
long long fibo(int numer) {
    if (numer == 0) return 0;
    if (numer == 1) return 1;
    return fibo(numer - 1) + fibo(numer - 2);
}