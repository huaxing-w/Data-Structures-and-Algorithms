#include <stdio.h>

//swap element in the arr
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//use array to represent tree
//n means how many nodes are there in the tree
//i means we are doing i node
void heapify(int tree[], int n, int i)
{
    //exit condition
    //if the current node index is bigger than n-1
    if (i >= n)
    {
        return;
    }

    //find the left child c1 and right child c2 in the array format tree
    int c1 = 2 * i + 1;
    int c2 = 2 * i + 2;
    //initial the max value index to i as starter
    int max = i;
    //compare with the left child and right child to update the max index
    if (c1 < n && tree[c1] > tree[max])
    {
        max = c1;
    }
    if (c2 < n && tree[c2] > tree[max])
    {
        max = c2;
    }
    //swap the bigger one to the father location
    if (max != i)
    {
        swap(tree, max, i);
        //recursively call the function
        //here we changed the smaller value to one of ith children
        //this may break the 'heap' balance, we need to continue run the function
        heapify(tree, n, max);
    }
}

//given an array
//build a start heap from this array
void build_heap(int tree[], int n)
{
    int last_node = n - 1;
    //starting from the parent of the last node
    int parent = (last_node - 1) / 2;

    int i;
    //run the heapify backwards to build the heap
    for (i = parent; i >= 0; i--)
    {
        heapify(tree, n, i);
    }
}

void heap_sort(int tree[], int n)
{
    //start with building a heap
    build_heap(tree, n);
    int i;
    //run the loop backwards
    //at each time, the first element tree[0] is the biggest one
    //so we swap the value between the first node and the last node
    //the total number of node -=1 after the swap
    //after the swap, the tree[0] is relative smaller one
    //so we need to run another heapify to find the biggest one one the top
    for (i = n - 1; i >= 0; i--)
    {
        swap(tree, i, 0);
        heapify(tree, i, 0);
    }
}


int main()
{
    int tree[] = {4, 10, 3, 5, 1, 2};
    int n = 6;
    heapify(tree, n, 0);

    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\n", tree[i]);
    }

    printf("================\n");
    int tree1[] = {2, 5, 3, 1, 10, 4};
    build_heap(tree1, 6);
    int j;
    for (j = 0; j < 6; j++)
    {
        printf("%d\n", tree1[j]);
    }

    printf("================\n");
    int tree2[] = {3, 124, 23, 534, 25, 32, 523, 14, 231};
    heap_sort(tree2, 9);
    int k;
    for (k = 0; k < 9; k++)
    {
        printf("%d\n", tree2[k]);
    }

    return 0;
}
