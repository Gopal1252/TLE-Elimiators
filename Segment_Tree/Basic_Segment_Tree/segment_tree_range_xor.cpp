#include<bits/stdc++.h>
using namespace std;

/*
rangel queries of 2 types:
1) update --> point updates at pos -> gcd(current value, new value)
2) query --> given a range, provide xor of all element of that range
 */

vector<int> segTree;

void build(vector<int> arr, int start, int end, int index){
    //leaf node
    if(start == end){
        segTree[index] = arr[start];
        return;
    }

    int mid = (start + end)/2;

    build(arr,start,mid,2*index);
    build(arr,mid+1,end,2*index + 1);
    segTree[index] = segTree[2*index] ^ segTree[2*index + 1];
}

void update(vector<int> arr, int start, int end, int index, int pos, int value){
    if(start == end){
        arr[pos] = __gcd(arr[pos],value); //in the question above, its given to add the value 
        segTree[index] = arr[pos];
        return;
    }

    int mid = (start + end)/2;

    if(pos <= mid){
        update(arr,start,mid,2*index,pos,value);
    }
    else{
        update(arr,mid+1,end,2*index + 1,pos,value);
    }
    segTree[index] = segTree[2*index] ^ segTree[2*index + 1];

}

//l,r -->query
//start, end --> segment tree nodes
int query(int start, int end, int index, int l, int r){
    //complete overlap
    if(l <= start && end <= r){
        return segTree[index];
    }
    
    //disjoint (no overlap)
    if(end < l || r < start){
        return 0;
    }

    //partial overlap
    int mid = (start + end)/2;

    int leftAnswer = query(start,mid,2*index,l,r);
    int rightAnswer = query(mid+1, end,2*index + 1,l,r);
    return leftAnswer ^ rightAnswer ;
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    segTree.resize(4*n,-1);

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    build(arr,0,n-1,1);

    cout<<query(0,n-1,1,0,2)<<"\n";

    update(arr,0,n-1,1,1,3);

    cout<<query(0,n-1,1,0,2)<<"\n";


    return 0;
}