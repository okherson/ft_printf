NAME	=	libftprintf.a

SRC_F		=	ft_printf.c check_format.c check_type.c	type_des.c put_t_c.c\
			put_t_s.c put_t_p.c ft_itoa_base.c use_flags_w.c check_b.c\
			add_str_to_b.c put_t_x.c put_t_o.c put_t_u.c put_t_d.c ft_atoi.c\
			ft_bzero.c ft_memcpy.c ft_putchar.c ft_putnbr.c ft_putstr.c\
			ft_strcat.c ft_strcpy.c ft_strdup.c ft_strlen.c ft_minus_zero.c\
			ft_strnew.c ft_strjoin.c ft_itoa.c add_w_x.c nan_inf.c\
			put_t_prosent.c add_w_d.c add_a_d.c ft_strdel.c use_flags_a.c\
			ft_memalloc.c put_t_f.c add_w_f.c ftoa_atof.c ft_round_f.c

OBJ_F 	=	ft_printf.o check_format.o check_type.o type_des.o put_t_c.o\
			put_t_s.o put_t_p.o ft_itoa_base.o use_flags_w.o check_b.o\
			add_str_to_b.o put_t_x.o put_t_o.o put_t_u.o put_t_d.o ft_atoi.o\
			ft_bzero.o ft_memcpy.o ft_putchar.o ft_putnbr.o ft_putstr.o\
			ft_strcat.o  ft_strcpy.o ft_strdup.o ft_strlen.o ft_minus_zero.o\
			ft_strnew.o ft_strjoin.o ft_itoa.o add_w_x.o nan_inf.o\
			put_t_prosent.o add_a_d.o add_w_d.o ft_strdel.o use_flags_a.o\
			ft_memalloc.o put_t_f.o add_w_f.o ftoa_atof.o ft_round_f.o

OBJ_DIR = ./obj/
SRC = $(addprefix ./src/, $(SRC_F))
OBJ = $(addprefix ./obj/, $(OBJ_F))
HEADER = ./ft_printf.h
FLAGS = -Wall -Wextra -Werror -g
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER)
		@ar rc $(NAME) $(OBJ)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(addprefix ./obj/, %.o): $(addprefix ./src/, %.c)
		@clang -g -o $@ -c $< $(FLAGS)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
