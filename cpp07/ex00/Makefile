NAME = template

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS = main.cpp

OBJS = ${SRCS:%.cpp=%.o}

all: ${NAME}

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

${NAME}: ${OBJS}
	${CPP} ${FLAGS} ${OBJS} -o $@

clean:
	rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}

re: fclean all

.PHONY: all fclean clean re