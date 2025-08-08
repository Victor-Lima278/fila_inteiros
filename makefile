# Nome do executável
EXEC = fila

# Fontes
SRC = main.c

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)

clean:
	rm -f $(EXEC)

run: $(EXEC)
	./$(EXEC)
