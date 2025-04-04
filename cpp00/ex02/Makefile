NAME = account

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = tests.cpp Account.cpp

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