# Finds primes up to a user defined number.

def primes(n):
    sieve = [True] * n
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
    return [2] + [i for i in range(3,n,2) if sieve[i]]

# Ask for upper bound
limit = int(input("Please enter a positive number:"))

plist = primes(limit)

#Give stats

print(f"\nThere are {len(plist)} primes between 2 and {limit}")
print(f"The last prime was {plist[-1]}")
print(f"The sum of all the primes is {sum(plist)}\n")
