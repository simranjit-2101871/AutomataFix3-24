//The next result is sum of preceding two digits
//incorrect code
#include<iostream>
using namespace std;
int fib(int n) {
        if(n<=1) return n;
        int prev2 = 0, prev1 = 1, cur;
        for(int i=2;i<=n;i++){
          //write your code here.  
        }
        return cur;
    }

//correct one
#include<iostream>
using namespace std;
int fib(int n) {
        if(n<=1) return n;
        int prev2 = 0, prev1 = 1, cur;
        for(int i=2;i<=n;i++){
            cur = prev1+prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return cur;
    }
