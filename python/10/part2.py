# 36 - wrong

file = []
border_points = []

with open("test2.txt", "r") as F:
    for n, line in enumerate(F.readlines()):
        file.append(line.strip())

        if len(border_points) == 0 and "S" in line:
            border_points.append([n, line.index("S")])


# Above
if file[border_points[0][0]-1][border_points[0][1]] in ["|", "7", "F"]:
    border_points.append([border_points[0][0]-1, border_points[0][1]])
# Right
elif file[border_points[0][0]][border_points[0][1]+1] in ["-", "J", "7"]:
    border_points.append([border_points[0][0], border_points[0][1]+1])
# Bottom
elif file[border_points[0][0]+1][border_points[0][1]] in ["|", "L", "J"]:
    border_points.append([border_points[0][0]+1, border_points[0][1]])
# Left
elif file[border_points[0][0]][border_points[0][1]-1] in ["-", "J", "7"]:
    border_points.append([border_points[0][0], border_points[0][1]-1])

while border_points[-1] != border_points[0]:
    y_mod = 0
    x_mod = 0

    if file[border_points[-1][0]][border_points[-1][1]] == "|":
        # From north
        if border_points[-1][0] - border_points[-2][0] == 1:
            y_mod = 1
        # From south
        else:
            y_mod = -1
    elif file[border_points[-1][0]][border_points[-1][1]] == "-":
        # From west
        if border_points[-1][1] - border_points[-2][1] == 1:
            x_mod = 1
        # From east
        else:
            x_mod = -1
    elif file[border_points[-1][0]][border_points[-1][1]] == "L":
        # From north
        if border_points[-1][0] - border_points[-2][0] == 1:
            x_mod = 1
        # From east
        else:
            y_mod = -1
    elif file[border_points[-1][0]][border_points[-1][1]] == "J":
        # From north
        if border_points[-1][0] - border_points[-2][0] == 1:
            x_mod = -1
        # From west
        else:
            y_mod = -1
    elif file[border_points[-1][0]][border_points[-1][1]] == "7":
        # From west
        if border_points[-1][1] - border_points[-2][1] == 1:
            y_mod = 1
        # From south
        else:
            x_mod = -1
    elif file[border_points[-1][0]][border_points[-1][1]] == "F":
        # From east
        if border_points[-1][1] - border_points[-2][1] == -1:
            y_mod = 1
         # From south
        else:
            x_mod = 1

    border_points.append([border_points[-1][0]+y_mod, border_points[-1][1]+x_mod])
    
points_inside = 0

# Sprawdź każdy punkt w pliku, który nie znajduje się w border_points
for i in range(0, len(file)):
    for j in range(0, len(file[i])):
        if [i, j] not in border_points:
            # Sporządź 4 listy, każda zawierająca punkty z border_points, które znajdują się w pojedynczym kierunku geograficznym względem sprawdzanego punktu
            north = []
            east = []
            south = []
            west = []

            for point in border_points:
                # Horizontally
                # Listom, które zawierają punkty w pionie, usuń '|'
                if j == point[1] and file[point[0]][point[1]] != "|":
                    if point[0] < i:
                        north.append(point)
                    else:
                        south.append(point)
                # Vertically
                # Listom, które zawierają punkty w poziomie, usuń wszystkie '-'
                elif i == point[0] and file[point[0]][point[1]] != "-":
                    if point[1] > j:
                        east.append(point)
                    else:
                        west.append(point)

            print(f"Point: {i}, {j}")
            print(f"\t{len(north)}: {str(north)}")
            print(f"\t{len(east)}: {str(east)}")
            print(f"\t{len(south)}: {str(south)}")
            print(f"\t{len(west)}: {str(west)}")

            # Jeżeli wszystkie listy mają nieparzystą liczbę punktów wewnątrz -> dany punkt na 100% znajduje się wewnątrz figury
            if len(north) % 2 == 1 and len(east) % 2 == 1 and len(south) % 2 == 1 and len(west) % 2 == 1:
                points_inside += 1
                print("PASS")
            else:
                print("NOT")

            print()

print(points_inside)
