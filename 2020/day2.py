# --- Day 2: Password Philosophy ---

def part1(): 
    with open("aoc.txt", "r") as file:
        lines = file.readlines()

    valid = 0

    for line in lines:
        policy_passw = line.split(":")
        passw = policy_passw[1]

        policy = policy_passw[0].split(" ")
        ranges = policy[0].split("-")
        l_range, r_range = int(ranges[0]), int(ranges[1])
        letter = policy[1]

        count = 0
        for l in passw:
            if l == letter:
                count += 1
        
        if count >= l_range and count <= r_range:
            valid += 1

    print(f"Part 1: {valid}")

def part2():
    with open("aoc.txt", "r") as file:
        lines = file.readlines()

    valid = 0

    for line in lines:
        policy_passw = line.split(":")
        passw = policy_passw[1].strip()

        policy = policy_passw[0].split(" ")
        ranges = policy[0].split("-")
        pos1, pos2 = int(ranges[0]), int(ranges[1])
        letter = policy[1]

        # one pos but not the other
        if passw[pos1 - 1] == letter and passw[pos2 - 1] != letter:
            valid += 1
        elif passw[pos2 - 1] == letter and passw[pos1 - 1] != letter:
            valid += 1
    
    print(f"Part 2: {valid}")

part2()
