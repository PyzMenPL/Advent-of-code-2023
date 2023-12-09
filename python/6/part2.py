file = []

with open("input.txt", "r") as F:
    file = F.readlines()

# Get time and distance
time = int("".join([n.strip() for n in file[0].split(": ")[1].split(" ")]))
dst = int("".join([n.strip() for n in file[1].split(": ")[1].split(" ")]))

# Calculate ammount of possible outcomes
out = 0

for i in range(1, time):
    if i * (time - i) > dst:
        out += 1

print(out)
