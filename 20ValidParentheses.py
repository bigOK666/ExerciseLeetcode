class Solution:
    def isValid(self, s: str) -> bool:
        #define the pairs
        map = {"(":")", "[":"]", "{":"}"}
        stack = []
        for item in str:
            if map.has_key(item):
                stack.append(item)
            else if 
