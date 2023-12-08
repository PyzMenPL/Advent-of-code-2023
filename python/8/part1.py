directions = ""
nodes = {}

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

current_node = "AAA"
moves = 0

# Loop which iterates until it finds 'ZZZ'
while current_node != "ZZZ":
    for side in directions:
        moves += 1
        current_node = nodes[current_node][0 if side == "L" else 1]

        if current_node == "ZZZ":
            break

print(moves)

