double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int i = 0;
    int j = 0;
    int c = 0;
    double median;
    int num = m + n;
    int *C = (int *)malloc(sizeof(int)*num);
    while((i < m) && (j < n))
    {
        if(A[i] <= B[j])
        {
            C[c] = A[i];
            i++;
        }
        else
        {
            C[c] = B[j];
            j++;
        }
        c++;
    }
    while(i < m)
    {
        C[c] = A[i];
        i++;
        c++;
    }
    while(j < n)
    {
        C[c] = B[j];
        j++;
        c++;
    }
    if(0 != num%2)
    {
        median = C[(m+n)/2];
    }
    else
    {
        median = (C[(m+n)/2] + C[(m+n)/2-1])/2.0;
    }
    return median;
}