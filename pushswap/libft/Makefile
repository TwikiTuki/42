all:
	cd ft_printf && make
	cp ./ft_printf/libftprintf.a ./libft.a 

celan:
	make -C ft_printf clean
	
fclean: celan
	@-rm -f libft.a
	make -C ft_printf fclean

re: fcelan all

.PHONY: all clean fclean re
