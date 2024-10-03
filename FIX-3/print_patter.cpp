
/*same NUMBERS
1 1
1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
*/

//The key point here is that the orinting on every row is equivalent to that ith row and it is iterating with row only so will print the value of i//
#include<iostream>
using namespace std;
int main(){
    int rows=5;
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=2*i;j++){
            cout<<1<<" ";
        }
        cout<<endl;
    }
    return 0;
}