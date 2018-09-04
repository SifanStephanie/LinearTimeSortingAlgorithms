/**
 * Learning Algorithms - From MIT courses
 *
 * Radix Sort radix sort is a non-comparative integer (not limited to integers)
 * sorting algorithm that sorts data with integer keys by grouping keys by the
 * individual digits which share the same significant position and value.
 * (from wiki)
 * Also Radix Sort uses the method of Counting sort in each sorting process.
 *
 * Radix Sort runs in linear time and is not a comparison sorts method!
 * Given n b-bit numbers and any positive integer r<=b, RADIX-SORT correctly
 * sorts these numbers in O((b/r)(n+2^r))time if the stable sort it uses
 * takes O(n+k) time for inputs in the range 0 to k (Counting Sort could do).
 **/

/*
 * bit - returns n'th digit in num
 * for example: (1234,2) returns 3
 */
static inline int bit(int num, int n){
    return num%(int)pow(10,n)/(int)pow(10,n-1);
}

static inline int random(int a, int b){
    return (rand() % (b-a))+ a;
}


/*
 * RadixSort - returns the sorting array of A[] using Radix Sort
 * length is the length of array A[]
 *
 */
int* RadixSort(int *A,int length){
    //initial the bucket to store 0-9
    int bucket[10];
    int *result=new int[length];
    int large=A[0];
    int i;
    int cnt = 1;
    int index;

    // first find the largest number in A[]
    for(i=1;i<length;i++){
        if(A[i]>large)
            large=A[i];
    }

    //sort for all the digits
    while((large/(cnt*10))>0){
        //set the bucket and result to 0
        memset(bucket,0, sizeof(int)*10);
        memset(result,0, sizeof(int)*length);

        //find the corresponding digit and store in bucket
        for(i=0;i<length;i++){
            index=bit(A[i],cnt);
            bucket[index]++;
        }

        //get the number of elements <= i
        for(i=1;i<10;i++)
            bucket[i]+=bucket[i-1];

        //make the distribution and store in result
        for(i=length-1;i>=0;i--){
            index=bit(A[i],cnt);
            result[bucket[index]-1]=A[i];
            bucket[index]--;
        }

        // put the result into A to prepare for next sorting
        for(i=0;i<length;i++){
            A[i]=result[i];
        }

        //increase the digit count
        cnt++;

    }
    return A;
}