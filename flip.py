s = input()
t = list(s)
for char in range(0, len(t)):
    if(t[char] == "0"):
        t[char] == "1"
        continue
    if(t[char] == "1"):
        t[char] == "0"
        continue

print(''.join(t))