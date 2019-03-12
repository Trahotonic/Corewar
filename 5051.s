.name "5051"
.comment "5051 1337"

fork:	fork %:live
		st r1, 6
live:	live %1
		ld %0, r2
		st r1, 6
		live %1
		zjmp %:live
