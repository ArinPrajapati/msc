
from typing import List

class Solution:
    def encode(self, strs: List[str]) -> str:
        encode = ""

        for s in strs:
            encode += str(len(s)) + "#" + s

        return encode

    def decode(self, s: str) -> List[str]:
        
        decode = []

        i = 0
        while(i < len(s)):
            j = i
            while(s[j] != '#'):
                j += 1
            length = int(s[i:j])
            i = j + 1
            decode.append(s[i:i + length])
            i += length

        return decode


