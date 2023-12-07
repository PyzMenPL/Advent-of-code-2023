from collections import Counter

values = "J23456789TQKA"

class Hand:
    def __init__(self, line: str) -> None:
        tmp = line.split(" ")
        self.bid = int(tmp[1])
        self.cards = [letter for letter in tmp[0]]
        
        # Dealing with J's
        js = []

        ## Finding indexes of every J
        for i in range(len(self.cards)):
            if self.cards[i] == "J":
                js.append(i)

        # If J is found generate every combination od a hand and find the best one
        if js:
            self.type = max([self._get_type(cards=hand) for hand in self._gen_cards(self.cards, js)])

        # Assign type
        else:
            self.type = self._get_type()


    def _gen_cards(self, cards, js) -> list:
        """Method which generates every combination of a hand of cards"""
        hands = []

        if js:
            for letter in values:
                tmp = cards.copy()

                tmp[js[0]] = letter

                hands += self._gen_cards(tmp, js[1:])

                hands.append(tmp)

        return hands

    def _get_type(self, cards=None) -> int:
        cards_to_check = cards if cards is not None else self.cards
        
        card_counter = Counter(cards_to_check).most_common(5)

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
        elif "".join(cards_to_check) in values or "".join(reversed(cards_to_check)) in values:
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
