from typing import List

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:

        c = n + m - 1

        while(m < 0 and n < 0):
            if(nums1[n] > nums2[m]):
                nums1[c] = nums1[n]
                nums1[n] = 0
                c -= 1
                n -= 1
            else:
                nums1[c] = nums2[m]
                c -= 1
                m-= 1

        if(m > 0):
            while(m > 0):
                nums1[c] = nums2[m]
                m-=1

        if(n > 0):
            while(n > 0):
                nums1[c] = nums1[n]
                n-=1




