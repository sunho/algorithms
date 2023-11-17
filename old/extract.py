words = []
with open("wikinames.dat") as f:
  lines = f.readlines()
  for line in lines:
    for word in line.split():
      if all(c.isalpha() and c.isascii() for c in word):
        words.append(word)

words = list(set(words))
words.sort()
N = 20
fin = []
ans = [0] * N
for k in range(N):
  for word in words:
    if len(word) <= k:
      ans[k] += 1

for i in range(N):
  print(ans[i])

fin = []
for word in words:
  if len(word) <= 4:
    fin.append(word)

fin = fin[:50010]

with open('dict.txt', 'w') as f:
  f.write('\n'.join(fin))
