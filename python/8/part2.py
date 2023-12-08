def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def calculate_lcm(numbers):
    if len(numbers) < 2:
        return "Not enough numbers!"

    result = numbers[0]
    for num in numbers[1:]:
        result = lcm(result, num)

    return result

directions = ""
nodes = {}
start_nodes = []

with open("input.txt", "r") as F:
    for line in F.readlines():
        line = line.strip()

        # First line is saved as directions
        if not directions and "=" not in line:
            directions = line
        
        # Rest lines
        elif "=" in line:
            name, values = line.split(" = ")
            l, r = values.split(", ")

            nodes[name] = (l[1:], r[:-1])

            if name.endswith("A"):
                start_nodes.append(name)

# Get how many steps it gets to achieve 'Z' in each node at the end
numbers = []

for node in start_nodes:
    moves = 0
    while True:
        for side in directions:
            moves += 1
            node = nodes[node][0 if side == "L" else 1]

            if node.endswith("Z"):
                break

        if node.endswith("Z"):
            break

    numbers.append(moves)

# Calculate lcm based on 'numbers'
print(calculate_lcm(numbers))

