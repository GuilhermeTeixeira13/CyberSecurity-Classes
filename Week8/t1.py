

for e in range(2, 667):
	for d in range(2, 667):
		if ( e * d % 616 == 1):
			print((e, d));
