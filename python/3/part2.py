class Solve:
    def __init__(self):
        with open("input.txt", "r") as F:
            self.file = [line.strip() for line in F.readlines()]

        self.output = 0

        self.run()
        print(self.output)

    def get_number_from(self, i: int, j: int) -> int:
        """Returns number, which was at `i` and `j` coordinates"""
        number = self.file[i][j]
        
        # go_left = 0 -> We are looking for numbers on the right side
        # go_left = 1 -> We are looking for numbers on the left side
        for go_left in range(0, 2):
            shift = -1 if go_left else 1
            
            if j + shift < 0 or j + shift >= len(self.file[i]):
                continue

            while self.file[i][j+shift].isdigit():
                if go_left:
                    number = self.file[i][j+shift] + number

                else:
                    number += self.file[i][j+shift]

                shift += -1 if go_left else 1

                if j + shift < 0 or j + shift >= len(self.file[i]):
                    break
        
        return int(number)

    def find_numbers_around(self, i: int, j: int) -> None:
        """Check if there are numbers around given point, if so - get them using get_number_from()"""
        digits_found = set()

        # For line above, on the same level and below
        for height in range(-1, 2):
            # If we are in the first or last row -> skip
            if i <= 0 or i+height >= len(self.file):
                continue

            # Check if there are numbers in current row
            for shift in range(j if j == 0 else j-1, j+2): # j+2 because the last number is not used
                for letter in self.file[i+height][shift]:
                    if letter.isdigit():
                        digits_found.add(self.get_number_from(i+height, shift))

        # If there are exactly 2 numbers around `*` multiply them and add them to sum
        if len(digits_found) == 2:
            out = 1

            for n in digits_found:
                out *= n

            self.output += out
                
    def run(self):
        """Main running method"""
        # For row
        for i in range(0, len(self.file)):
            # For collumn
            for j in range(0, len(self.file[i])):
                if self.file[i][j] == "*":
                    self.find_numbers_around(i, j)


if __name__ == "__main__":
    Solve()

