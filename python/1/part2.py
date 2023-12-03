numbers = {"one": "1", "two": "2", "three": "3", "four": "4", "five": "5", "six": "6", "seven": "7", "eight": "8", "nine": "9"}

def get_numbers(line, reverse=False):    
    for i in range(0, len(line)-2):
        for key, value in numbers.items():
            if reverse:
                key = key[::-1]

            if line[i:i+len(key)] == key:
                line = line[:i] + value + line[i+len(value):]

    return line

def get_first_number(line):
    for letter in line:
        if letter.isdigit():
            return letter

    return "0"

out = 0

with open("input.txt", "r") as F:
    for line in F:
        line = line.strip()
        l = int(get_first_number(get_numbers(line)) + get_first_number(get_numbers(line[::-1], reverse=True)))
        out += l

print(out)

