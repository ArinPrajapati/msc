class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = {}

        slow = 0
        fast = 0
        maxCount = 0

        while(fast < len(s)):
            if s[fast] in seen:
                del seen[s[slow]]
                slow+=1
            else:
                seen[s[fast]] = True
                maxCount = max(maxCount,fast - slow + 1)
                fast+=1

        return maxCount



            
