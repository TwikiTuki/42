SOURCES=../get_next_line/

test_%: tst_%.c $(SOURCES)get_next_line_utils.c $(SOURCES)get_next_line.c 
	echo fk
	gcc -g -Wall -Werror -Wextra -o $@ $^ 
	./$@

test_%_bonus: tst_%.c $(SOURCES)get_next_line_utils_bonus.c $(SOURCES)get_next_line_bonus.c 
	echo fk
	gcc -D BUFFER_SIZE=10000000 -g -Wall -Werror -Wextra -o $@ $^ 
	./$@
#-D BUFFER_SIZE=100 
#	valgrind --tool=memcheck  ./$@
#--show-leak-kinds=all
#--leak-check=full 
