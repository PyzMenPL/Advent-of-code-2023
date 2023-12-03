suma = 0

with open("input.txt", "r") as F:
    for i, line in enumerate(F, start=1):
        line = line[line.index(":")+2:]

        values = {
            "green": 0,
            "red": 0,
            "blue": 0
        }

        for game in line.split(";"):
       
            for ball_set in game.split(","):
                ball_set = ball_set.strip()
                num, color = ball_set.split(" ")
                num = int(num)

                if num > values[color]:
                    values[color] = num


        suma += values["green"] * values["red"] * values["blue"]

print(suma)
