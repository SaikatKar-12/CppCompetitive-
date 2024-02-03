#include<stdio.h>
#define size 100

// void merge(int arr[],int si,int mid,int ei){
//     int i=si;
//     int j=mid+1;
//     int k=si;
//     int temp[size];
//     while(i<=mid && j<=ei){
//         if(arr[i]<=arr[j]){
//             temp[k]=arr[i];
//             k++;
//             i++;
//         }else if(arr[i]>arr[j]){
//             temp[k]=arr[j];
//             k++;
//             j++;
//         }
//     }
//     while(i<=mid){
//         temp[k]=arr[i];
//         k++;
//         i++;
//     }
//     while(j<=ei){
//         temp[k]=arr[j];
//         k++;
//         j++;
//     }
//     for(int x=si;x<k;x++){
//         arr[x]=temp[x];
//     }
// }

// void mergesort(int arr[],int si,int ei){
//     if(si>=ei) return;
//     int mid=(si+ei)/2;
//     mergesort(arr,si,mid);
//     mergesort(arr,mid+1,ei);

//     merge(arr,si,mid,ei);
// }

void swap(int *a,int *b){
    int temp= *a;
    *a=*b;
    *b=temp;
}

// int partition(int arr[],int si,int ei){
//     int pivotEle=arr[si];
//     int count=0;
//     for(int i=si+1;i<=ei;i++){
//         if(arr[i]<=pivotEle){
//             count++;
//         }
//     }
//     int pi=si+count;
//     //printf("%d ",arr[pi]);
//     swap(&arr[si],&arr[pi]);
//     int i=si;
//     int j=ei;
//     while(i<pi && j>pi){
//         if(arr[i]<=pivotEle) i++;
//         if(arr[j]>pivotEle) j--;
//         if(arr[i]>pivotEle && arr[j]<=pivotEle) {
//             swap(&arr[i],&arr[j]);
//             //printf("%d %d",arr[i],arr[j]);
//             i++;
//             j--;
//         }
//     }

//     return pi;
// }

// void quicksort(int arr[],int si,int ei){
//     if(si>=ei) return;

//     int pi=partition(arr,si,ei);

//     quicksort(arr,si,pi-1);
//     quicksort(arr,pi+1,ei);

// }
void downheapify(int arr[],int pi,int n){
    while(pi<n){
        int left=2*pi+1;
        int right=2*pi+2;
        int maxidx=pi;
        if(left>=n) break;
        if(arr[left]>arr[maxidx]) maxidx=left;
        if(right<n && arr[right]>arr[maxidx]) maxidx=right;
        if(maxidx!=pi){
            swap(&arr[maxidx],&arr[pi]);
            pi=maxidx;
        }else break;
    }
    
}
void heapsort(int arr[],int n){
    //heapify
    for(int i=n/2;i>=0;i--){
        downheapify(arr,i,n);
    }
    //sort
    for(int i=n-1;i>=0;i--){
        swap(&arr[i],&arr[0]);
        downheapify(arr,0,i);
    }
}

int main(){
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int arr[size];
    printf("input data:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    heapsort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}