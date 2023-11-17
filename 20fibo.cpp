#include <iostream>
#include <vector>
using namespace std;



// vector<int>fibo1(int n){
//     vector<int>ans;
//     if(n>=1) ans.push_back(0);
//     if(n>=2) ans.push_back(1);
//     for(int i=2;i<n;i++){
//         int next=ans[i-1]+ans[i-2];
//         ans.push_back(next);
//     }
//     return ans;
// }

// void fibo2(int n,vector<int>&v){
//     if(n<=0) return;
//     fibo2(n-1,v);
//     int next = (n==1)?0:(n==2)?1:v[n-2]+v[n-3];
//     v.push_back(next);
// }






































vector<int> fibonacciNonRecursive(int n)
{
    vector<int> fibArray;

    if (n >= 1)
    {
        fibArray.push_back(0);
    }
    if (n >= 2)
    {
        fibArray.push_back(1);
    }

    for (int i = 2; i < n; ++i)
    {
        int nextFib = fibArray[i - 1] + fibArray[i - 2];
        fibArray.push_back(nextFib);
    }

    return fibArray;
}

void fibonacciRecursive(int n, vector<int> &fibArray)
{
    if (n <= 0)
    {
        return;
    }

    fibonacciRecursive(n - 1, fibArray);

    int nextFib = (n == 1) ? 0 : (n == 2) ? 1
                                          : fibArray[n - 2] + fibArray[n - 3];
    fibArray.push_back(nextFib);
}
int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> fibArray1 = fibonacciNonRecursive(n);
    cout << "Fibonacci Numbers (non recursive): ";
    for (int fib : fibArray1)
    {
        cout << fib << " ";
    }
    cout << endl;

    vector<int> fibArray2;
    fibonacciRecursive(n, fibArray2);
    cout << "Fibonacci Numbers (recursive): ";
    for (int fib : fibArray2)
    {
        cout << fib << " ";
    }
    cout << endl;

    return 0;
}
