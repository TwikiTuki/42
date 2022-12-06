MAIN_DIR="/Users/jrenau-v/Documents/cursus/42/"
PRJ_DIR=$(MAIN_DIR)"pushswap/"
TST_DIR=$(MAIN_DIR)"tst_pushswap/stuff/"


prnt:
	@echo MAIN_DIR $(MAIN_DIR)
	@echo PRJ_DIR $(PRJ_DIR)
	@echo TST_DIR $(TST_DIR)

test%: $(TST_DIR)test%.o
	make -C $(PRJ_DIR) $@

$(TST_DIR)test%.o: test%.c
	mkdir -p $(TST_DIR)
	$(CC) -Wall -Werror -Wextra -c $^ -o $@

clean:
	make -C $(PRJ_DIR) clean
	rm -rf ./stuff/*.o

fclean:
	make -C $(PRJ_DIR) fclean
	rm -rf ./stuff

.PHONY: fclean clean re
.PRECIOUS: $(TST_DIR)test%.o
