def get_extrapolated_value(numbers: list) -> int:
    if len(set(numbers)) == 1 and numbers[0] == 0:
        return numbers[-1]
    else:
        diff = []

        for i in range(0, len(numbers)-1):
            diff.append(numbers[i+1] - numbers[i])

        return get_extrapolated_value(diff) + numbers[-1] 


file = []

with open("input.txt", "r") as F:
    file = F.readlines()

out = 0

for line in file:
    numbers = list(map(lambda x: int(x), line.split(" ")))
    out += get_extrapolated_value(numbers)

print(out)
