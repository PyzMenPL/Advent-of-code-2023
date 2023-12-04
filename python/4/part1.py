def is_number(n: str) -> bool:
    return n.isdigit()

def get_value(n: int) -> int:
    if n == 0:
        return 0
    
    return 2 ** (n-1)

plik = ["Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53",
"Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19",
"Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1",
"Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83",
"Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36",
"Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11"]

suma = 0

for line in plik:
    line = line.split(": ")[1]
    left, right = line.split(" | ")
    left, right = set(left.split(" ")), set(right.split(" "))
    left, right = set(filter(is_number, left)), set(filter(is_number, right))
    
    print(f"Left: {left}\tRight: {right}\tIntersection: {len(left.intersection(right))}\tValue: {get_value(len(left.intersection(right)))}")
    
    suma += get_value(len(left.intersection(right)))
    
print(suma)
    
