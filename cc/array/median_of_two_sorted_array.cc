//
// Created by cp on 2019/2/4.
//
#include <iostream>
#include <algorithm>



class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int k = m+n;
        if(k & 0x01)
            return kOfSortedArrays(A, m, B, n, k/2+1);
        else
            return (kOfSortedArrays(A, m, B, n, k/2) + kOfSortedArrays(A, m, B, n, k/2+1))/2;

    }

    double kOfSortedArrays(int A[], int m, int B[], int n, int k)
    {
       if(m > n)
           return kOfSortedArrays(B, n, A, m, k);
       if(m == 0)
           return B[k-1];
       if(k == 1)
           return std::min(A[0], B[0]);

       int pa = std::min(k/2, m);
       int pb = k - pa;

       if(A[pa-1] < B[pb-1])
           return kOfSortedArrays(A+pa, m-pa, B, n, k-pa);
       else if(A[pa-1] > B[pb-1])
            return kOfSortedArrays(A, m, B+pb, n-pb, k-pb);
       else
            return B[pb-1];
    }
};



