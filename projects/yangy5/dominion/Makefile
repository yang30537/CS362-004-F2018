CFLAGS = -Wall -fprofile-arcs -ftest-coverage -lm -std=c99


rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/


testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)


testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)



cardtest1:
	gcc -g dominion.c cardtest1.c rngs.c -o cardtest1 $(CFLAGS)

cardtest2:
	gcc -g dominion.c cardtest1.c rngs.c -o cardtest2 $(CFLAGS)

cardtest3:
	gcc -g dominion.c cardtest1.c rngs.c -o cardtest3 $(CFLAGS)

cardtest4:
	gcc -g dominion.c cardtest1.c rngs.c -o cardtest4 $(CFLAGS)

unittest1:
	gcc -g dominion.c unittest1.c rngs.c -o unittest1 $(CFLAGS)

unittest2:
	gcc -g dominion.c unittest1.c rngs.c -o unittest1 $(CFLAGS)

unittest3:
	gcc -g dominion.c unittest1.c rngs.c -o unittest1 $(CFLAGS)

unittest4:
	gcc -g dominion.c unittest1.c rngs.c -o unittest1 $(CFLAGS)

myTestResult:
	./cardtest1 &> unittestresult.out
	./cardtest2 >> unittestresult.out
	./cardtest3 >> unittestresult.out
	./cardtest4 >> unittestresult.out
	./unittest1 >> unittestresult.out
	./unittest2 >> unittestresult.out
	./unittest3 >> unittestresult.out
	./unittest4 >> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)



runtests:
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe cardtest1 cardtest1.exe cardtest2 cardtest2.exe cardtest3 cardtest3.exe cardtest4 cardtest4.exe


