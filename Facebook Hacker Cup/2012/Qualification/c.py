import sys
import math

t = int(input())
for f in range(t):
	s = sys.stdin.readline()
	h = a = c = k = e = r = u = p = 0
	for i in s:
		if i == 'H':
			h += 1
		elif i == 'A':
			a += 1
		elif i == 'C':
			c += 1
		elif i == 'E':
			e += 1
		elif i == 'R':
			r += 1
		elif i == 'K':
			k += 1
		elif i == 'U':
			u += 1
		elif i == 'P':
			p += 1
	l = (h, a, c, k, e, r, u, p)
	m = min(l)
	if c >= 2*m:
		total = m
	else:
		c2 = c//2
		if c2 <= m:
			total = c2
		else:
			total = 0
		
	print('Case #{}: {}'.format(f+1, total))
