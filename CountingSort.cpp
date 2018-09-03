/**
 * Learning Algorithms - From MIT courses
 * 
 * Counting Sort operates by counting the number of objects that have 
 * each distinct key value, and using arithmetic on those counts to 
 * determine the positions of each key value in the output sequence.(from wiki)
 *
 * Counting Sort runs in linear time and is not a comparison sorts method!
 * the Complexity is O(n + k).
 * Useful for small numbers(integers) especially when k=O(n), 
 * large numbers may cause lots of time because k is large.
 **/

int* CountingSort(int *A){

    int large=0;
    int i,j;
    int *B=new int[N];

    //first finds the largest number in A[]
    for(i=0;i<N;i++){
        if(A[i]>large)
        large=A[i];
    }

    // build the aux storage
    int C[large];

    //initial C[]
    for(i=0;i<large;i++){
        C[i]=0;
    }

    // find the occurs time of numbers in A[]
    for(j=0;j<N;j++)
        C[A[j]-1]++; // A[j]-1 because the array starts from 0 ~ N-1

    // get the number of elements <= i
    for(i=1;i<large;i++){
        C[i]+=C[i-1];
    }

    //make the distribution
    for(j=N-1;j>=0;j--){
        B[C[A[j]-1]-1]=A[j]; // -1 denotes that the array starts from 0 ~ N-1
        C[A[j]-1]--;
    }
    return B;
}