#Accepted!
#https://www.spoj.pl/problems/TOANDFRO/
#0.03 	3.7M

import sys

def reverse(s):
	#equivalente: s = s[::-1]
	s2 = ""
	for i in range(len(s)-1, -1, -1):
		s2 += s[i]
	return s2

n = input()
while n != 0:
	s = raw_input()
	i = 0;
	l = []
	bien = True
	while i < len(s):
		aux = s[i:i+n]
		if not bien:
			aux = reverse(aux)
		l += [aux]
		bien = not bien
		i += n
	for c in range(n):
		for f in range(len(l)):
			sys.stdout.write(l[f][c])
	print
	n = input()
