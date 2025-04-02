NAME = megaphone

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = megaphone.cpp

OBJS = ${SRCS:%.cpp=%.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CPP} ${FLAGS} ${OBJS} -o $@

clean:
	rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}