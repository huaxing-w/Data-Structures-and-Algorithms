#include <stdio.h>

#define MAX_LEN 1000

//build the tree->fill out the tree array
void build_tree(int arr[], int tree[], int node, int start, int end){
    //start index and end index are the same
    //this is the exit condition
    //which is also the leaf node
    if (start==end){
        tree[node]=arr[start];
        return;
    }
    //find current node's left child and right child
    int left_node=node*2+1;
    int right_node=node*2+2;
    int mid=(start+end)/2;
    //fill out the tree array first, and then find the sum of the two child node
    build_tree(arr,tree,left_node,start,mid);
    build_tree(arr,tree,right_node,mid+1,end);
    //at this moment, the tree array has been filled out, you just have to find the sum of both child node
    tree[node]=tree[left_node]+tree[right_node];
}

void update_tree(int arr[], int tree[], int node, int start, int end, int idx, int val){
    if(start==end){
        arr[idx]=val;
        tree[node]=val;
        return;
    }
    int mid=(start+end)/2;
    int left_node=2*node+1;
    int right_node=2*node+2;
    if(idx<=mid){
        update_tree(arr,tree,left_node,start,mid,idx,val);
    }
    else{
        update_tree(arr,tree,right_node,mid+1,end,idx,val);
    }
    tree[node]=tree[left_node]+tree[right_node];
}



int query_tree(int arr[], int tree[], int node, int start, int end, int l, int r){
    if(r<start || l>end){
        return 0;
    }
    if(start==end){
        return tree[node];
    }
    if(start>=l && end<=r){
        return tree[node];
    }
    int mid=(start+end)/2;
    int left_node=node*2+1;
    int right_node=node*2+2;
    int sum_left = query_tree(arr,tree,left_node,start,mid,l,r);
    int sum_right = query_tree(arr,tree,right_node,mid+1,end, l,r);
    return sum_left+sum_right;

}


int main(){

    int arr[]={1,3,5,7,9,11};
    int size=6;

    int tree[MAX_LEN]={0};

    build_tree(arr,tree,0,0,size-1);
    int i;
    for (int i = 0; i < 15; ++i) {
        printf("tree[%d] = %d\n",i,tree[i]);

    }

    printf("\n");

    update_tree(arr,tree,0,0,size-1,4,6);
    for (int i = 0; i < 15; ++i) {
        printf("tree[%d] = %d\n",i,tree[i]);

    }
    printf("\n");

    int s= query_tree(arr,tree,0,0,size-1,2,5);
    printf("%d\n",s);

    return 0;
}
