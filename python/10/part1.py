file = []
start_pos = None

with open("input.txt", "r") as F:
    for n, line in enumerate(F.readlines()):
        file.append(line.strip())

        if start_pos is None and "S" in line:
            start_pos = [n, line.index("S")]

current_pos = None

# Above
if file[start_pos[0]-1][start_pos[1]] in ["|", "7", "F"]:
    current_pos = [start_pos[0]-1, start_pos[1]]
# Right
elif file[start_pos[0]][start_pos[1]+1] in ["-", "J", "7"]:
    current_pos = [start_pos[0], start_pos[1]+1]
# Bottom
elif file[start_pos[0]+1][start_pos[1]] in ["|", "L", "J"]:
    current_pos = [start_pos[0]+1, start_pos[1]]
# Left
elif file[start_pos[0]][start_pos[1]-1] in ["-", "J", "7"]:
    current_pos = [start_pos[0], start_pos[1]-1]

last_pos = list(start_pos)

steps = 2

while current_pos != start_pos:
    y_mod = 0
    x_mod = 0

    if file[current_pos[0]][current_pos[1]] == "|":
        # From north
        if current_pos[0] - last_pos[0] == 1:
            y_mod = 1
        # From south
        else:
            y_mod = -1
    elif file[current_pos[0]][current_pos[1]] == "-":
        # From west
        if current_pos[1] - last_pos[1] == 1:
            x_mod = 1
        # From east
        else:
            x_mod = -1
    elif file[current_pos[0]][current_pos[1]] == "L":
        # From north
        if current_pos[0] - last_pos[0] == 1:
            x_mod = 1
        # From east
        else:
            y_mod = -1
    elif file[current_pos[0]][current_pos[1]] == "J":
        # From north
        if current_pos[0] - last_pos[0] == 1:
            x_mod = -1
        # From west
        else:
            y_mod = -1
    elif file[current_pos[0]][current_pos[1]] == "7":
        # From west
        if current_pos[1] - last_pos[1] == 1:
            y_mod = 1
        # From south
        else:
            x_mod = -1
    elif file[current_pos[0]][current_pos[1]] == "F":
        # From east
        if current_pos[1] - last_pos[1] == -1:
            y_mod = 1
         # From south
        else:
            x_mod = 1

    last_pos = list(current_pos)
    current_pos = [current_pos[0]+y_mod, current_pos[1]+x_mod]
    
    steps += 1

print(steps//2)

