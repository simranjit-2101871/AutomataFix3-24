//Multipicative product of two maximum number out of three in a list

#include<iostream>
using namespace std;
int multiply(int num1,int num2, int num3){
    int result,max,min,mid;
    max=(num1>num2)?((num1>num3)? num1:num3):((num2>num3)?num2:num3);
    min=(num1<num2)?((num1<num3)? num1:num3):((num2<num3)?num2:num3); 
    mid=(num1+num2+num3)-(min+max);
    result=(max*mid); 
    return result;  
}
int main(){
    int num1=2;
    int num2=4;
    int num3=3;
    int product=multiply(num1,num2,num3);
    cout<<"The resultant is as follows="<<product<<endl;
    return 0;
}
/*
max = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);

This line uses the ternary conditional operator to find the maximum value among num1, num2, and num3.
It checks if num1 is greater than num2. If true, it then checks if num1 is greater than num3. If both conditions are true, num1 is the maximum.
If num1 is not greater than num2, it checks if num2 is greater than num3. If true, num2 is the maximum. Otherwise, num3 is the maximum.
Finding the Minimum Value:


min = (num1 < num2) ? ((num1 < num3) ? num1 : num3) : ((num2 < num3) ? num2 : num3);

This line uses a similar ternary conditional operator structure to find the minimum value among num1, num2, and num3.
It checks if num1 is less than num2. If true, it then checks if num1 is less than num3. If both conditions are true, num1 is the minimum.
If num1 is not less than num2, it checks if num2 is less than num3. If true, num2 is the minimum. Otherwise, num3 is the minimum.*/