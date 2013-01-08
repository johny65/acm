t = int(input())
for tt in range(t):
	w, h, s = input().split(' ', 2)
	w, h = map(int, [w, h])
	palabras = s.split()
	l = list(map(len, palabras))
	m = max(l)
	p = w//m
	
	while True:
		b = True
		lineas = 1
		suma = 0
		alto = 0
		for i in l:
			suma += p*i
			if suma > w:
				lineas += 1
				suma = p*i
				alto = lineas*p
				if alto > h:
					b = False
					break
			suma += p #el espacio de la otra palabra
		if not b:
			p -= 1
			if p == 0:
				print("Case #{}: {}".format(tt+1, 0))
				break
		else:
			print("Case #{}: {}".format(tt+1, p))
			break
