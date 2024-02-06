# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souchane <souchane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 17:43:56 by souchane          #+#    #+#              #
#    Updated: 2024/02/05 12:50:00 by souchane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		    = minitalk
F			    = -Wall -Wextra -Werror
CC			    = cc
RM			    = rm -f
HEADER		    = minitalk.h
FSERVER_BONUS	= server_bonus.c util.c
FCLIENT_BONUS	= client_bonus.c util.c
FSERVER         = server.c util.c
FCLIENT         = client.c util.c


OSERVER_BONUS	= $(FSERVER_BONUS:.c=.o)
OCLIENT_BONUS	= $(FCLIENT_BONUS:.c=.o)
OSERVER			= $(FSERVER:.c=.o)
OCLIENT			= $(FCLIENT:.c=.o)


all : $(NAME) 

$(NAME): $(OSERVER) $(OCLIENT)
	@ $(CC) $(F) $(OSERVER)  -o server
	@ $(CC) $(F) $(OCLIENT)  -o client


%.o: %.c $(HEADER)
	$(CC) $(F) -o $@ -c $<


bonus : $(OSERVER_BONUS) $(OCLIENT_BONUS)
	@ $(CC) $(F) $(OSERVER_BONUS) -o server_bonus
	@ $(CC) $(F) $(OCLIENT_BONUS) -o client_bonus

clean :
	@ $(RM) $(OSERVER) $(OCLIENT) $(OSERVER_BONUS) $(OCLIENT_BONUS)

fclean : clean
	@$(RM) server client client_bonus server_bonus

re : fclean all 
