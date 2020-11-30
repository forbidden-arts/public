# Requires databases and sequences provided by CS50 (not included)

from sys import argv, exit
import re
import csv

# Global variables are suboptimal, but easy.
strs = []
match = []
seq = []


def main():
    # Load CSV
    db = load_csv(argv[1])
    dna = load_txt(argv[2])

    # Get DNA strs
    for i in range(1, len(db[0])):
        strs.append(db[0][i])

    # Searchin' time!
    tempseq = []

    # Because we want repeated sequences, the RegEx matches on 2 or more.
    for i in strs:
        tempseq = (re.findall(rf"((?:{i})+(?={i}))", dna))
        if len(tempseq) > 1:
            for j in range(len(tempseq) - 1):
                if len(tempseq[j]) < len(tempseq[j + 1]):
                    del tempseq[j]

        # Check and see if the list is nested.
        try:
            seq.append(tempseq[0])
        except:
            seq.append(tempseq)

    # Post processing. Adds +1 to sequence to account for final match.
    for i in range(len(seq)):
        match.append(str(int((len(seq[i]) / len(strs[i])) + 1)))

    # Compare list(match) to known values in CSV. Print name if true.
    for n in range(len(db)):
        if db[n][1:] == match:
            print(db[n][0])
            break
    else:
        print("No match")


def load_csv(file):
    with open(file) as f:
        db = list(csv.reader(f, delimiter=','))
    return db


def load_txt(file):
    with open(file, 'r') as f:
        dna_seq = f.read()
    return dna_seq


if len(argv) != 3:
    print("Usage: python dna.py database sequence")
    exit()

main()
