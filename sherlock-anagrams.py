from collections import Counter

def hash(string):
    return sum(["abcdefghijklmnopqrstuvwxyz".index(char) for char in string])

# takes one string and returns a list of all substrings
def superString(string):
    for length in range(len(string))[1:]:
        for start in range(len(string) - length - 1):
            yield string[start : start + length]

def case(string):
    return sum([x *(x-1)/2 for x in Counter(map(hash,superString(string))).values()])
            
for testCase in range(int(input())):
    print(list(superString(input())))
