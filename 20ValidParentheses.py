class Solution:
    def isValid(self, s: str) -> bool:
        #define the pairs
        map = {"(":")", "[":"]", "{":"}"}
        stack = []
        for item in s:
            if item in map.keys():
                stack.append(item)
            elif item in map.values() and len(stack) != 0:
                left_pair = list(map.keys())[list(map.values()).index(item)]
                if stack[-1] == left_pair:
                    stack.pop()
                else:
                    return False
            elif item in map.values() and len(stack) == 0:
                return False
        if len(stack) == 0:
            return True
        else:
            return False
