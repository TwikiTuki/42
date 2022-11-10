SOURCES=../get_next_line/

yep:
	echo yep
test_%: tst_%.c $(SOURCES)utils.c $(SOURCES)get_next_line.c 
	echo fk
	gcc -g -Wall -Werror -Wextra -o $@ $^ 
	valgrind --tool=memcheck  ./$@
#--show-leak-kinds=all
#--leak-check=full 
