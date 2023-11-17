import zlib
import base64

import sys
sys.setrecursionlimit(int(1e5))
def make_trie(words):
  root = dict()
  for word in words:
    current_dict = root
    for letter in word:
      current_dict = current_dict.setdefault(letter, {})
    current_dict['@'] = {}
  return root

with open("dict.txt") as f:
  lines = list(f.readlines())
  lines = [s[:-1] for s in lines]
  root = make_trie(lines)
  res = ''
  def dfs(entry):
    global res
    for k,v in entry.items():
      res += k
      dfs(v)
      res += '<'
  dfs(root)
  cursor = 0
  fin = ''
  while cursor < len(res):
    if res[cursor] == '<':
      c = cursor
      while c < len(res) and res[c] == '<':
        c+=1
      fin += str(c-cursor)
      cursor = c
    else:
      fin += res[cursor]
      cursor+=1
  a = zlib.compress(fin.encode('ascii'))
  fin2 = base64.b85encode(a).decode('ascii')
  print(len(fin2))
  with open('res.txt', 'w') as f2:
    f2.write(fin2)
