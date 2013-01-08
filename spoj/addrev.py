#accepted
#http://www.spoj.pl/problems/ADDREV/
#0.47	3.8M

n = int(raw_input())
for i in range(n):
	[s1, s2] = raw_input().split(' ')
	s1 = s1[::-1]
	s2 = s2[::-1]
	suma = int(s1) + int(s2)
	rev = int(str(suma)[::-1])
	print rev
