def is_number(n: str) -> bool:
    return n.isdigit()

file = []

with open("input.txt", "r") as F:
    file = [line.strip() for line in F.readlines()]

cards = {}

out = 0

for n, line in enumerate(file, start=1):
    if not cards.get(n):
        cards[n] = 1

    line = line.split(": ")[1]
    left, right = line.split(" | ")
    left, right = set(left.split(" ")), set(right.split(" "))
    left, right = set(filter(is_number, left)), set(filter(is_number, right))
    
    new_cards = len(left.intersection(right))

    for _ in range(0, cards[n]):
        for i in range(n+1, n+1 + new_cards):
            if cards.get(i):
                cards[i] += 1 
            else:
                cards[i] = 2

    out += cards[n]

print(out)
    
