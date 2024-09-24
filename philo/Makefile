# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmansuri <mmansuri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/29 14:49:24 by mmansuri          #+#    #+#              #
#    Updated: 2024/09/24 14:55:54 by mmansuri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 				= philo
SRCS 				= main.c  utils1valid.c utils2start.c utils3thread.c utils4time.c utils5status.c utils5status2.c utils6phroutin.c utils6phroutin2.c
CFLAGS	 			= -Wall -Werror -Wextra	-g
OBJS        		= $(SRCS:.c=.o)
CC = cc

all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lpthread

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<


clean:
	rm -rf $(OBJS)
	
fclean: clean
	rm -rf $(NAME)


re: fclean all

.PHONY: all clean fclean re
