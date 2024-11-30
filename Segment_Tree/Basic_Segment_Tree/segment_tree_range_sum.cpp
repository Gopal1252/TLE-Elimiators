#include<bits/stdc++.h>
using namespace std;

/*
2 type of queries
update --> point updates of the values of the array {change to the new value}
range sum --> given a range, provide its sum
*/

//TC: O(n)
vector<int> segTree;
void build(vector<int>& arr, int start, int end, int index){ // build the segment tree 
    //leaf node
    if(start == end){
        segTree[index] = arr[start];
        return;
    }

    //internal node
    int mid = (start + end)/2;
    int left = 2*index;
    int right = 2*index + 1;

    build(arr,start,mid,left);
    build(arr,mid+1,end,right);
    segTree[index] = segTree[left] + segTree[right];
}

//TC: O(log(n))
void update(vector<int>& arr, int start, int end, int index, int pos, int value){ // update at a given point (pos) to the value in segment tree
    if(start == end){
        arr[pos] = value;
        segTree[index] = arr[pos];
        return;
    }

    int mid = (start + end)/2;
    int left = 2*index;
    int right = 2*index + 1;

    if(pos <= mid){
        update(arr, start, mid, left, pos, value);
    }
    else{
        update(arr, mid+1, end, right, pos, value);
    }
    segTree[index] = segTree[left] + segTree[right];
}

//l,r --> indexes of the query
//start, end --> indexes of the nodes of segment tree
//TC: O(log(n))
int query(int start, int end, int index, int l, int r){ // give sum from L to R
    //complete overlap
    if(l <= start && end <= r){
        return segTree[index];
    }

    //disjoint
    if(l>end || r<start){
        return 0;
    }

    //partial overlatp
    int mid = (start + end)/2;
    int left = 2*index;
    int right = 2*index + 1;

    int leftAnswer = query(start, mid, left, l, r);
    int rightAnswer = query(mid+1,end,right, l,r);
    return leftAnswer + rightAnswer;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    segTree.resize(4*n,-1);

    vector<int> arr(n);
    for(auto & it : arr){
        cin>>it;
    }

    build(arr,0,n-1,1);

    for(auto & it : segTree){
        cout<<it<<" ";
    }
    cout<<"\n";

    for(auto & it : arr){
        cout<<it<<" ";
    }
    cout<<"\n";

    cout<<query(0,n-1,1,0,2)<<"\n";

    update(arr,0,n-1,1,1,3);


    for(auto & it : segTree){
        cout<<it<<" ";
    }
    cout<<"\n";

    for(auto & it : arr){
        cout<<it<<" ";
    }
    cout<<"\n";

    cout<<query(0,n-1,1,0,2)<<"\n";


    return 0;
}