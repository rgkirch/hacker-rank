from collections import Counter

def hash(string):
    return int(str(sum([pow("abcdefghijklmnopqrstuvwxyz".index(char), 2) for char in string])) + str(len(string)))

# takes one string and returns a list of all substrings
def superString(string):
    if not string:
        return []
    else:
        return [string[x:] for x in range(len(string))] + list(superString(string[:-1]))

def case(string):
    return sum([x *(x-1)/2 for x in Counter(map(hash,superString(string))).values()])

for testCase in range(int(input())):
    print(case(input()))
