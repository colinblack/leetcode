//
// Created by cp on 2019/2/2.
//

#include <iostream>
#include <cstdio>
#include <cstring>

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int *array = new int[m + n]{0};
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (A[i] < B[j])
            {
                array[k] = A[i];
                ++i;
            }
            else
            {
                array[k] = B[j];
                ++j;
            }
            ++k;
        }

        if (i >=m && j < n)
        {
            memcpy(array + k, &B[j], sizeof(int)*(n - j));
        }
        else if (j >= n && i < m)
        {
            memcpy(array + k, &A[i], sizeof(int)*(m - i));
        }

        double media = 0.0;
        if ((m + n) % 2)
        {
            media = array[(m + n) / 2];
        }
        else
        {
            media = (array[(m + n) / 2] + array[(m + n) / 2 - 1]) / 2.0;
        }

        delete[] array;
        return media;
    }

};


int main()
{


    return 0;
}