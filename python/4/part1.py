def is_number(n: str) -> bool:
    return n.isdigit()

def get_value(n: int) -> int:
    if n == 0:
        return 0
    
    return 2 ** (n-1)

file = []

with open("input.txt", "r") as F:
    file = [line.strip() for line in F.readlines()]

out = 0

for line in file:
    line = line.split(": ")[1]
    left, right = line.split(" | ")
    left, right = set(left.split(" ")), set(right.split(" "))
    left, right = set(filter(is_number, left)), set(filter(is_number, right))
    
    out += get_value(len(left.intersection(right)))
    
print(out)
    
