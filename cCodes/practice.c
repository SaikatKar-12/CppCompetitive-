#include<stdio.h>
#define size 100

void swap(int *a,int *b){
    int temp= *a;
    *a=*b;
    *b=temp;
}

// void merge(int arr[],int si,int mid,int ei){
//     int i=si;
//     int j=mid+1;
//     int k=si;
//     int temp[size];
//     while(i<=mid && j<=ei){
//         if(arr[i]<=arr[j]){
//             temp[k]=arr[i];
//             i++;
//             k++;
//         }else{
//             temp[k]=arr[j];
//             j++;
//             k++;
//         }
//     }
//     while(i<=mid){
//         temp[k]=arr[i];
//             i++;
//             k++;
//     }
//     while(j<=ei){
//         temp[k]=arr[j];
//             j++;
//             k++;
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

// int partition(int arr[],int si,int ei){
//     int pivotEle=arr[si];
//     int count=0;
//     for(int i=si+1;i<=ei;i++){
//         if(arr[i]<=pivotEle) count++;
//     }
//     int pi=si+count;
//     swap(&arr[pi],&arr[si]);
//     int i=si;
//     int j=ei;
//     while(i<pi && j>pi){
//         if(arr[i]<=pivotEle) i++;
//         else if(arr[j]>pivotEle) j--;
//         else{
//             swap(&arr[i],&arr[j]);
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
        int lc=2*pi+1;
        int rc=2*pi+2;
        if(lc>=n) break;
        int maxidx=pi;
        if(arr[lc]>arr[maxidx]) maxidx=lc;
        if(rc<n && arr[rc]>arr[maxidx]) maxidx=rc;
        if(maxidx!=pi){
            swap(&arr[pi],&arr[maxidx]);
            pi=maxidx;
        }else break;
    }
}

void heapsort(int arr[],int n){
    for(int i=n/2;i>=0;i--){
        downheapify(arr,i,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        downheapify(arr,0,i-1);
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