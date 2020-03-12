#include <stdio.h>
#include <stdlib.h>

void ArrayFilling(int **a,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0){
                a[i][j]=j+1;
            }
            else{
                if(j==0){
                    a[i][j]=a[i-1][n-1];
                }
                else {
                    a[i][j]=a[i-1][j-1];
                }
            }
        }
    }
}


void ArrayOutput(int **a,int n ){
    printf("Latin square:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==0){
                printf("|");
            }
            printf("%02d|",a[i][j]);
        }
        printf("\n");
    }
}




int main()
{
    int size;
    printf("Enter array dimension\n");
    if(!scanf("%d",&size)){
        printf("Error, invalid input\n");
        return 1;
    }
    if(size<=0){
        printf("Error, invalid argument\n");
        return 1;
    }
    int ** array = (int**) malloc(size * sizeof(int*));
    if(array==NULL) {
        printf( "Can't allocate memory\n" );
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; i++){
        array[i] = (int*) malloc(size * sizeof(int));
        if(array[i]==NULL) {
            printf( "Can't allocate memory\n" );
            exit(EXIT_FAILURE);
        }
    }
    ArrayFilling(array,size);
    ArrayOutput(array,size);
    for (int i =0 ; i < size; i++){
        free(array[i]);
    }
    free(array);
    return 0;
}
