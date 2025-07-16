class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        if len(s) == 1:
            return False


        for i in range(len(s)):
            if s[i] == '(' or s[i] == '{' or s[i] == '[':
                stack.append(s[i])
            else:
                if not stack:
                    return False
                top = stack.pop()
                if (s[i] == ')' and top != '(') or \
                   (s[i] == '}' and top != '{') or \
                   (s[i] == ']' and top != '['):
                    return False
        return len(stack) == 0
            

        
