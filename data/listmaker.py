from asyncore import write
import random

randomlist = []

for i in range (0, 100):
    n = random.randint(1, 30)
    randomlist.append(n)

with open('randomlist.txt', 'w') as f:
    for n in randomlist:
        f.write(str(n))
        f.write(' ')