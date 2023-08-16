#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < n; i++){
        int v = arr[i];
        int j = i-1;

        while( j>=0 && arr[j]>v){
            arr[j+1] = arr[j];
            j = j-1;
        }

        arr[j+1] = v;
    }

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
    
}