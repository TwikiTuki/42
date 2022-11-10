SOURCES=../get_next_line/

yep:
	echo yep
test_%: tst_%.c $(SOURCES)utils.c $(SOURCES)get_next_line.c
	echo fk
	gcc -Wall -Werror -Wextra -o $@ $^ 
	./$@
