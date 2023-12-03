colors = {"red": 12, "green": 13, "blue": 14}

suma = 0

with open("input.txt", "r") as F:
    for i, line in enumerate(F, start=1):
        increment = True
        line = line[line.index(":")+2:]
        for game in line.split(";"):
            for ball_set in game.split(","):
                ball_set = ball_set.strip()
                num, color = ball_set.split(" ")
                if int(num) > colors[color]:
                    increment = False
                    break
            if not increment:
                break

        if increment:
            suma += i

print(suma)
