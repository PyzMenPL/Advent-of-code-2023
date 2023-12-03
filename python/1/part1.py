def get_first_number(line):
    for letter in line:
        if letter.isdigit():
            return letter

    return "0"

out = 0

with open("input.txt", "r") as F:
    for line in F:
        line = line.strip()

        out += int(get_first_number(line) + get_first_number(line[::-1]))


print(out)

