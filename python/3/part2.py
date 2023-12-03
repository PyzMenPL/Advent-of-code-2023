class Solve:
    def __init__(self):
        with open("input.txt", "r") as F:
            self.file = [line.strip() for line in F.readlines()]

        self.suma = 0

        self.run()
        print(self.suma)

    def get_number_from(self, i: int, j: int) -> int:
        """Pozyskuje liczbę, która zawiera w sobie punkt o współrzędnych i oraz j"""
        number = self.file[i][j]

        # Warunek, mówiący w jakim kierunku odkrywamy liczbę
        for go_left in range(0, 2):
            shift = -1 if go_left else 1
            
            # Zabezpieczenie przed wyjściem poza zakres
            if j + shift < 0 or j + shift >= len(self.file[i]):
                continue

            while self.file[i][j+shift].isdigit():
                if go_left:
                    number = self.file[i][j+shift] + number

                else:
                    number += self.file[i][j+shift]

                shift += -1 if go_left else 1

                # Zabezpieczenie przed wyjściem poza zakres
                if j + shift < 0 or j + shift >= len(self.file[i]):
                    break
        
        return int(number)

    def find_numbers_around(self, i: int, j: int) -> None:
        """Sprawdź czy wokół punktu znajdują się liczby, jeżeli tak - pozyskaj je"""
        digits_found = set()

        # Dla linijki ponad, na tym samym poziomie i poniżej
        for height in range(-1, 2):
            # Jeżeli jesteśmy w pierwszym wierszu, albo w ostatnim to skip
            if i <= 0 or i+height >= len(self.file):
                continue


            # Sprawdź czy w obecnie oprzeszukiwanej linijce znajdują się liczby
            for shift in range(j if j == 0 else j-1, j+2): # j+2 ponieważ range() to zbiór lewostronnie domknięty
                for letter in self.file[i+height][shift]:
                    if letter.isdigit():
                        digits_found.add(self.get_number_from(i+height, shift))

        # Jeżeli znaleziono dwie liczby wokół `*` to je przemnóż i dodaj do sumy
        if len(digits_found) == 2:
            out = 1

            for n in digits_found:
                out *= n

            self.suma += out
                
    def run(self):
        """Główna funkcja biegająca"""
        # Dla rzędu
        for i in range(0, len(self.file)):
            # Dla kolumny
            for j in range(0, len(self.file[i])):
                if self.file[i][j] == "*":
                    self.find_numbers_around(i, j)


if __name__ == "__main__":
    Solve()

