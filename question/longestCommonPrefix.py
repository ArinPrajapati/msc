from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not str:
            return ""
        sm_str = min(strs, key=len)

        for i in strs:
            while not i.startswith(sm_str):
                sm_str = sm_str[:-1]
                if not sm_str:
                    return ""

        return sm_str
