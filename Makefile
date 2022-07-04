# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tliot <tliot@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 21:22:24 by tliot             #+#    #+#              #
#    Updated: 2022/07/04 15:27:55 by tliot            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR =       mandatory
SRC_DIRBONUS =       bonus

SRCS	=	mandatory/ft_childs.c\
			mandatory/ft_find.c\
			mandatory/ft_free.c\
			mandatory/ft_lst.c\
			mandatory/ft_put.c\
			mandatory/ft_split.c\
			mandatory/ft_strjoin_path.c\
			mandatory/ft_strncmp.c\
			mandatory/pipex.c


SRCSBONUS = bonus/ft_childs_bonus1.c\
			bonus/ft_find_bonus.c\
			bonus/ft_free_bonus.c\
			bonus/ft_lst_bonus.c\
			bonus/ft_put_bonus.c\
			bonus/ft_split_bonus.c\
			bonus/ft_strjoin_path_bonus.c\
			bonus/ft_strncmp_bonus.c\
			bonus/pipex_bonus.c

OBJS			=	$(SRCS:%.c=%.o)
OBJSBONUS		=	$(SRCSBONUS:%.c=%.o)
NAME			=	pipex
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g3


RM				=	rm -f

all:		${NAME}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
		
$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

bonus: $(NAME)_bonus 

$(NAME)_bonus:	$(OBJSBONUS)
		$(CC) $(CFLAGS) $(OBJSBONUS) -o $(NAME)_bonus

clean:
	${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
		${RM} ${NAME} ${NAME}_bonus

re:			fclean all

.PHONY: 	all clean fclean re
