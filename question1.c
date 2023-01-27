//Apache AGE Internship Program
//candidate : Renzo Prats
#include <stdio.h>
#include <stdlib.h>

//creating the struct Node
typedef struct{
    int val;
} Node;


//creating the function addition that add two numbers and return a Node
Node* addition(int v1, int v2){
    //heap memory alocation
    Node *n = (Node*) malloc(sizeof(Node));
    //add v1 and v2
    n->val = v1 + v2;
    return n;
}

//creating the function multiplication that multiplies two numbers and return a Node
Node* multiplication(int v1, int v2){
    //heap memory alocation
    Node *n = (Node*) malloc(sizeof(Node));
    //multiply v1 and v2
    n->val = v1 * v2;
    return n;
}

//creating the function subtraction that subtract two numbers and return a Node
Node* subtraction(int v1, int v2){
    //heap memory alocation
    Node *n = (Node*) malloc(sizeof(Node));
    //subtract v2 and v1
    n->val = v2 - v1;
    return n;
}

//creating the function fib that calculates a fibonacci sequence of some number and return a Node
Node* fibo(int n){
    //heap memory alocation
    Node *v = (Node*) malloc(sizeof(Node));

    //if n is negative we need to convert it to positive because does not exists fibonacci of negative numbers
    if(n < 0){
        n *= -1;
    }

    //heap memory alocation of the array that will be used to store data of fib dp
    int *f = (int*) malloc((n+1) * sizeof(int));

    //store the base case of dp in the array
    f[0] = 0;
    f[1] = 1;

    //using a top down approach to solve fib using dp, basically we store in f[i] the value of f[i-1] + f[i-2] that is the rule of fib sequence
    for(int i = 2; i <= n; i++){
        f[i] = f[i-1]+f[i-2];
    }

    v->val = f[n-1];
    return v;
}

//prints the value in the Node struct
void calc(Node *n){
    printf("%d\n", n->val);
}

int main(){
    Node *add = addition(10,6);
    Node *mul = multiplication(5,4);
    Node *sub = subtraction(mul->val,add->val);
    Node *fib = fibo(sub->val);

    calc(add);
    calc(mul);
    calc(sub);
    calc(fib);
    return 0;
}