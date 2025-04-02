NAME = phonebook

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Contact.cpp Phonebook.cpp main.cpp

OBJS = ${SRCS:%.cpp=%.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CPP} ${FLAGS} ${OBJS} -o $@

clean:
	rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}