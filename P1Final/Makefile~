a.out: lex.yy.c y.tab.c
	gcc y.tab.c lex.yy.c

lex.yy.c: SmallC.l
	flex SmallC.l

y.tab.c: SmallC.y 
	yacc -d SmallC.y

clean:
	rm a.out lex.yy.c y.tab.c y.tab.h

