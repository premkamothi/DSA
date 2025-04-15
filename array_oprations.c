#include<stdio.h>

void display(int arr[],int n)
{
    for(int i=0; i<n; i++){
        printf("%d\n",arr[i]);
    }
}

int insertionAtIndex(int arr[], int element, int capacity, int size, int index)
{
    if(size>capacity){
        return -1;
    }
    for(int i=size-1 ; i>=index ; i-- ){
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;
}

void deleteAtIndex(int arr[], int size, int index)
{

    for(int i=index; i<size-1; i++){
        arr[i]=arr[i+1];

    }

}

int main()
{
    int arr[100]={1,2,3,4};
    int element, capacity, size=5, index;

    display(arr,4);
    printf("\n");
    insertionAtIndex(arr,23, 100, size, 2);

    display(arr,5);
    printf("\n");
    deleteAtIndex(arr,size,2);
    size-=1;
    display(arr,size);
    return 0;

}
