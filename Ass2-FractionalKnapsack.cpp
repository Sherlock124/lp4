#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Item{
    int profit;
    int weight;

    public:
        Item(int profit, int weight){
            this -> profit = profit;
            this -> weight = weight;
        }

        int getProfit(){
            return profit;
        }

        int getWeight(){
            return weight;
        }
};

bool cmp(Item& a, Item& b){
    double r1 = (double)a.getProfit()/a.getWeight();
    double r2 = (double)b.getProfit()/b.getWeight();
    return r1 > r2;
}

double fractknapsack(int W, vector<Item>& arr){
    sort(arr.begin(),arr.end(),cmp);

    double finalvalue = 0.0;

    for(Item& item: arr){
        if(item.getWeight() <= W){
            W = W - item.getWeight();
            finalvalue = finalvalue + item.getProfit();
        }
        else{
            finalvalue += item.getProfit() *(W / (double)item.getWeight());
        }
    }

    return finalvalue;
}

int main(){
    int n,W;
    cout<<"Enter the no. of items: ";
    cin>>n;

    vector<Item> arr;
    cout<<"Enter the profits and weights for each item: "<<endl;

    for(int i=0; i< n;i++){
        int profit,weight;

        cout<<"Item "<<i+1<<"- Profit: ";
        cin>>profit;
        cout<<"Item "<<i+1<<"- Weight: ";
        cin>>weight;

        arr.push_back(Item(profit,weight));
    }

    cout<<"Enter the maximum weight capacity: ";
    cin>>W;

    cout<<"Maximum Profit: "<<fractknapsack(W,arr)<<endl;

    return 0;
}