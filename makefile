cipher: cipher.o
	gcc cipher.o -o cipher
cipher.o: cipher.c
breaker: breaker.o
	gcc breaker.o -o breaker
breaker.o: breaker.c

test: test1 test2
test1:
	./cipher 1 5 astronomer.txt ast_enc.out
	./breaker ast_enc.out output1.txt
	diff -s astronomer.txt output1.txt
test2:
	./cipher 1 10 siddhartha.txt sid_enc.out
	./breaker sid_enc.out output2.txt
	diff -s siddhartha.txt output2.txt
