SOURCES=../get_next_line/

test_%: tst_%.c $(SOURCES)get_next_line_utils.c $(SOURCES)get_next_line.c 
	echo fk
	gcc -D BUFFER_SIZE=42 -g -Wall -Werror -Wextra -o $@ $^ 
	./$@
//	valgrind --tool=memcheck  ./$@
#--show-leak-kinds=all
#--leak-check=full 
