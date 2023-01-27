//Apache AGE Internship Program
//candidate : Renzo Prats
#include <stdio.h>
#include <stdlib.h>
/*
This problem is a recurrence, so it will generate a tree of recurrence that calculates each subproblem.
So here we have two different approaches that is do this by a recursive function that calculates each subproblem every time
and a dp approach that stores the subproblems and we don't need to calculate it every time
*/


//recursive function
//advantages: Easy to think, easy implementation
//disadvantages: If n is not little it becomes slow because it has exponential complexity time and can overflow the stack if n is big
long long function1(int n){
    //if are some of the base cases we return the value
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    //if is not the base case we calculate the subproblem
    return function1(n-3) + function1(n-2);
}

//dp top-down approach function
//here we use dp a techique that stores in an array the subproblems so we don't need to calculate it every time
//advantages: Faster than recursive function, works with big n
//disadvantages: Needs extra space like an array, if n is too big can overflow the stack because it is also an recursive function but with memoization, it is more hard to think and to implement
long long dp[1000001];
long long function2(int n){
    //if are some of the base cases we return the value
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    //if we already calculated the subproblem we just return it
    if(dp[n]){
        return dp[n];
    }
    //we store the subproblems in array dp
    dp[n] = function2(n-3) + function2(n-2);
    //we return dp[n] that is the value of function2(n)
    return dp[n];
}

//dp bottom-up approach function
//advantages: Faster than recursive function, works with big n, does not have the problem of overflow the stack
//disadvantages: Needs extra space like an array, hard to think and to implement
long long function3(int n, long long dp2[]){
    //we store the subproblems in the array
    dp2[0] = 0;
    dp2[1] = 1;
    dp2[2] = 2;
    //we store the possibilities of recurrence that is (n-2) and (n-3)
    int possibilities[2] = {3,2};

    /*get n = 5 as example, so first we calculate n-3 = 2 and n-2 = 3 and we get other two subproblems n=3 and n=2
    for n=2 we know that it has the value of 2 and for n=3 we can calculate other two subproblens n=1 and n=0
    for n=1 we know that it has the value of 1 and n=0 value of 0, so n[5] = n[2] + n[1] + n[0] = 2 + 1 + 0
    that is what the two for do
    */
     
    for(int i = 0; i <= n; i++){
        for(int y = 1; y <= 2; y++){
            if(i - possibilities[y - 1] >= 0){
                dp2[i] += dp2[i - possibilities[y-1]];
            }
        }
    }
    //we return dp[n] that is the value of function3(n)
    return dp2[n];
}

int main(){
    int n = 5;

    printf("%lld\n", function1(n));
    
    printf("%lld\n", function2(n));

    long long dp2[1000001];
    printf("%lld\n", function3(n, dp2));

    return 0;
}