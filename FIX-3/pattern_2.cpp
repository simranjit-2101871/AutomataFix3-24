/*DIFFERENT NUMBERS
1
1 1
1 1 1
1 1 1 1
1 1 1 1 1
*/

//The key point here in this code is value always changing so means we should iterate j or we should take some other varible and increment it//
#include<iostream>
using namespace std;
int main(){
    int rows=6;
    int c=1;
    for(int i=1;i<=rows;i++){
        for(int j=1;j<i;j++){
            //well if we use j and increment it then after every ith iteration the value of j will be reset//
             cout<<c<<" ";
            
        }
        cout<<endl;
    }
    return 0;

}