# Reflection

## 2022-01-05
```C
void build_tree(int arr[], int tree[], int node, int start, int end){

    if (start==end){
        tree[node]=arr[start];
        return;
    }
    int left_node=node*2+1;
    int right_node=node*2+2;
    int mid=(start+end)/2;

    build_tree(arr,tree,left_node,start,mid);
    build_tree(arr,tree,right_node,mid+1,end);

    tree[node]=tree[left_node]+tree[right_node];
}
```
This is a special type of recursion, not same as add-type or true/ false - type, it returns nothing like the standard type of recursion, but it is not the same.

we want to fill in the array to build the tree, so to remember the purpose of this recursion is to build the tree (arr->tree, arr is tree-type arr, tree is the segment tree we are looking for)
> void build_tree

the value of given node is calculated by its children
> tree[node]=tree[left_node]+tree[right_node];

but in order to find the `tree[left_node]` and `tree[right_node]`, we have to build the lower level tree first (recursion, top down)

exit condition is when the range is 1
```c
if (start==end){
        tree[node]=arr[start];
        return;
    }
```

so the recursion block is 
```c
void build_tree(arr,tree,curNode,left,right){
    //block 1
    //exit condition
    //find tree[curNode]
    if(left==right){
        tree[curNode]=arr[left];
        return;
    }

    //block 2
    //to find tree[curNode], we need to find 
    //tree[curNode_leftChild] and tree[curNode_rightChild]
    //but at this moment we dont know the tree[curNode_leftChild] or tree[curNode_rightChild]
    //top down find them first
    curNode_leftChild
    curNode_rightChild
    //binary
    mid
    build_tree(arr,tree,curNode_leftChild,left,mid)
    build_tree(arr,tree,curNode_rightChild,mid+1,right)

    //block 3
    //finish up the task we have in block 2
    //because at this moment we know the children value
    tree[curNode]=tree[curNode_leftChild]+tree[curNode_rightChild];

}


```
---
