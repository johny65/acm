#para pruebas:

t = int(input())
for tt in range(t):
	(n, p1, w1, m, k, a, b, c, d) = map(int, input().split())
	ps = [p1]
	ws = [w1]
	for i in range(1, n):
		pi = ((a*ps[i-1] + b) % m) +1
		ps.append(pi)
		wi = ((c*ws[i-1] + d) % k) +1
		ws.append(wi)
	print(ps)
	print(ws)