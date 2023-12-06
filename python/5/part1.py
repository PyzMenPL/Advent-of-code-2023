# 2987557382 - too high

plik = """seeds: 79 14 55 13

seed-to-soil map:
50 98 2
52 50 48

soil-to-fertilizer map:
0 15 37
37 52 2
39 0 15

fertilizer-to-water map:
49 53 8
0 11 42
42 0 7
57 7 4

water-to-light map:
88 18 7
18 25 70

light-to-temperature map:
45 77 23
81 45 19
68 64 13

temperature-to-humidity map:
0 69 1
1 0 69

humidity-to-location map:
60 56 37
56 93 4""".split("\n")

class RangeObj:
    def __init__(self, line: list):
        self.scope = int(line[2])
        self.dst_range_start = int(line[0])
        #self.dst_range_end = self.dst_range_start + self.scope
        
        self.src_range_start = int(line[1])
        self.src_range_end = self.src_range_start + self.scope
        
    def get_next_value(self, n):
        #if self.dst_range_start <= n < self.dst_range_end:
        #    return n + self.scope
            
        if self.src_range_start <= n < self.src_range_end:
            return self.dst_range_start + (n - self.src_range_start)
        
        return n

seeds = [int(n) for n in plik[0].split(": ")[1].split(" ")]

ranges = []

for i in range(0, len(plik[1:])):
    if ":" in plik[i]:
        ranges = []
        continue
    
    elif len(plik[i].split(" ")) == 3:
        ranges.append(RangeObj(plik[i].split(" ")))
    
    elif plik[i] == "":
        for i in range(0, len(seeds)):
            for r in ranges:
                start_val = int(seeds[i])
                seeds[i] = r.get_next_value(seeds[i])
                
                if start_val != seeds[i]:
                    break
            

print(min(seeds))
