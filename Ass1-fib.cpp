#include<iostream>
#include<vector>
using namespace std;

int recFib(int n){
    if(n<=1){
        return n;
    }

    return recFib(n-1)+recFib(n-2);
}

int recStep(int n){
    if(n<=1){
        return n;
    }

    return 1+recStep(n-1)+recStep(n-2);
}

int iterativeFib(int n, vector<int>&v){
    for(int i=2;i<=n;i++){
        v[i] = v[i-1]+v[i-2];
    }
    return v[n];

}

int iterativeStep(int n){
    // if(n<=0) return 0;
    // else if(n==1) return 1;
    if(n<=1) return n;

    vector<int> steps(n+1,0);
    steps[1]=1;

    for(int i=2; i <= n; i++){
        steps[i] = 1+ steps[i-1]+steps[i-2];
    }

    return steps[n];
}
int main(){
    int n;
    cin>>n;

    vector<int> v(n+1,0);
    v[1]=1;

    cout<<"The number using recursion is: "<<recFib(n)<<endl;

    cout<<"Steps using recursion is: "<< recStep(n)<<endl;

    cout<<"The number using iterative method is: "<< iterativeFib(n,v)<<endl;

    cout<<"Steps using Iterative method is: "<< iterativeStep(n)<<endl;

    for(int i=0;i<=n;i++){
        cout<<v[i]<<" ";
    }
}