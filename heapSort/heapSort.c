#include<stdio.h>



void swap(int arr[], int i, int j ){
     int temp = arr[i];
     arr[i]=arr[j];
     arr[j]=temp;	

}


//use array to represent tree
//n means how many nodes are there in the tree
//i means we are doing i node
void heapify(int tree[], int n, int i){
    if(i>=n){
    return;
    }

    int c1 = 2*i+1;
    int c2 =2*i +2;
    int max = i;
    if(c1<n && tree[c1]>tree[max]){
        max = c1;
    }
    if(c2<n && tree[c2]>tree[max]){
        max = c2;
    }
    if(max!=i){
        swap(tree,max,i);
        heapify(tree,n,max);
    }

}

void build_heap(int tree[],int n){
    int last_node=n-1;
    int parent = (last_node-1)/2;

    int i;
    for(i=parent; i>=0;i--){
	heapify(tree,n,i);
    }

}



void heap_sort(int tree[],int n){
    build_heap(tree,n);
    int i;
    for(i=n-1; i>=0;i--){
	swap(tree,i,0);
	heapify(tree,i,0);
    }
}


int main(){
    int tree[]={4,10,3,5,1,2};
    int n=6;
    heapify(tree,n,0);
    
    int i;
    for(i=0;i<n;i++){
	printf("%d\n",tree[i]);
    }

    printf("================\n");
    int tree1[]={2,5,3,1,10,4};
    build_heap(tree1,6);
    int j;
    for( j=0;j<6;j++){
	printf("%d\n",tree1[j]);
    }

    printf("================\n");
    int tree2[]={3,124,23,534,25,32,523,14,231};
    heap_sort(tree2,9);
    int k;
    for(k=0;k<9;k++){
	printf("%d\n",tree2[k]);
    }






		    

    return 0;
}
