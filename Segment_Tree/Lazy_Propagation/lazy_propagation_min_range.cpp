#include<bits/stdc++.h>
using namespace std;

/*
Perform the following 2 queries on an array:
1) 1LRX --> add X to all the elements from L to R
2) 2LR --> return min of all elements from L to R
*/

vector<int> segTree, lazy;

int merge(int a, int b){
    return min(a,b);
}

//TC : O(n)
void build(vector<int>& arr, int start, int end, int index){
    if(start == end){
        segTree[index] = arr[start];
        return;
    }

    int mid = (start + end)/2;
    int left = 2*index;
    int right = 2*index + 1;

    build(arr,start,mid,2*index);
    build(arr,mid+1,end,2*index + 1);
    segTree[index] = merge(segTree[2*index],segTree[2*index + 1]);

}

void propagate(int start, int end, int index){
    if(start == end){
        lazy[index] = 0;
        return;
    }
    lazy[2*index] += lazy[index];
    lazy[2*index + 1] += lazy[index];
    lazy[index] = 0;
}

//TC : O(logn)
void updateRange(int start, int end, int index, int l, int r, int value){

    //check for pending updates in the lazy segment tree
    if(lazy[index] != 0){
        //1) add the update value from the lazy seg tree to original seg tree
        segTree[index] += lazy[index];
        //2) propagate the update values downwards and update the lazy array's current index node to 0
        propagate(start,end,index);
    }
    
    //in case of complete overlap
    if(l <= start && end <=  r){
        //1) update the value of the current index
        segTree[index] += value;

        //2) propagate the update values downwards in the lazy seg tree {propagate function makes the lazy[index] = 0 and propagate the updates downwards}
        lazy[index] = value;
        propagate(start,end,index);
        return;
    }

    //no overlap (disjoint)
    if(r < start || end < l){
        return;
    }
    
    //partial overlap
    int mid = (start + end)/2;
    updateRange(start, mid, 2*index,l,r,value);
    updateRange(mid+1,end,2*index + 1,l,r,value);
    segTree[index] = merge(segTree[2*index],segTree[2*index+1]);
}

//TC : O(logn)
int query(int start, int end, int index, int l, int r){

    //check for pending updates in the lazy segment tree
    if(lazy[index] != 0){
        //1) add the update value from the lazy seg tree to original seg tree
        segTree[index] += lazy[index];
        //2) propagate the update values downwards and update the lazy array's current index node to 0
        propagate(start,end,index);
    }

    //complete overlap
    if(l <= start && end <=  r){
        return segTree[index];
    }

    //disjoint
    if(r < start || end < l){
        return INT_MAX;
    }

    int mid = (start + end)/2;
    int leftAnswer = query(start, mid, 2*index,l,r);
    int rightAnswer = query(mid+1,end,2*index + 1,l,r);
    return merge(leftAnswer,rightAnswer);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    segTree.resize(4*n,-1);
    lazy.resize(4*n,0);

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    build(arr,0,n-1,1);

    for(auto & it : arr){
        cout<<it<<" ";
    }
    cout<<"\n";

    for(auto & it : segTree){
        cout<<it<<" ";
    }
    cout<<"\n";

    for(auto & it : lazy){
        cout<<it<<" ";
    }
    cout<<"\n";

    cout<<query(0,n-1,1,0,2)<<"\n";
    updateRange(0,n-1,1,0,0,500);
    cout<<query(0,n-1,1,0,2)<<"\n";


    return 0;
}