from collections import Counter

values = "23456789TJQKA"

class Hand:
    def __init__(self, line: str) -> None:
        tmp = line.split(" ")
        self.cards = [letter for letter in tmp[0]]
        self.type = self._get_type()
        self.bid = int(tmp[1])

    def _get_type(self) -> int:
        card_counter = Counter(self.cards).most_common(5)

        if len(card_counter) == 1:
            return 8
        elif card_counter[0][1] == 4:
            return 7
        elif len(card_counter) == 2:
            return 6
        elif card_counter[0][1] == 3:
            return 5
        elif len(card_counter) in (2, 3):
            if card_counter[0][1] == 2 and card_counter[1][1] == 2:
                return 4
        elif card_counter[0][1] == 2:
            return 3
        elif "".join(self.cards) in values or "".join(reversed(self.cards)) in values:
            return 2

        return 1

    def batter_than(self, hand) -> bool:
        if self.type != hand.type:
            return self.type > hand.type

        else:
            for i in range(len(self.cards)):
                if values.index(self.cards[i]) != values.index(hand.cards[i]):
                    return values.index(self.cards[i]) > values.index(hand.cards[i])

            return False


# Getting hands
hands = []

with open("input.txt", "r") as F:
    hands = [Hand(line.strip()) for line in F.readlines()]

# Bubble sort :)
changed = True

while changed:
    changed = False

    for i in range(0, len(hands)-1):
        if hands[i].batter_than(hands[i+1]):
            hands[i], hands[i+1] = hands[i+1], hands[i]
            changed = True

# Output
out = 0

for n, hand in enumerate(hands, start=1):
    out += n * hand.bid

print(out)
