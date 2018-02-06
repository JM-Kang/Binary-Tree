# **************************************************************************** #
#                                                                              #
#                                                                              #
#    makefile                                                                  #
#                                                                              #
#    By: JianMing <jason.kang1106@gmail.com>                                   #
#                                                                              #
#    Created: 2017/11/18 21:09:15 by JianMing                                  #
#    Updated: 2017/11/18 21:14:57 by JianMing                                  #
#                                                                              #
# **************************************************************************** #

NAME = a.out
OBJS = *.o
SRCS = *.cc
HEADER = *.h

all: $(NAME)
	g++ $(OBJS) -o $(NAME)

$(NAME): $(SRCS) $(HEADER)
	g++ -Wall -c $(SRCS)

clean:
	rm -rf $(OBJS)
	rm -rf statement.txt

fclean: clean
	rm -rf $(NAME)

re: fclean all
