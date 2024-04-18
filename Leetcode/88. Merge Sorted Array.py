class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        akt_idx = n+m-1
        akt_m = m-1
        akt_n = n-1
        if n == 0: return
        for i in range(m+n):
            if (nums1[akt_m] > nums2[akt_n] or akt_n<0) and akt_m>=0:
                nums1[akt_idx],nums1[akt_m] = nums1[akt_m],nums1[akt_idx]
                akt_m -= 1 
            else:
                nums1[akt_idx],nums2[akt_n] = nums2[akt_n],nums1[akt_idx]
                akt_n -= 1
            akt_idx-=1
        