CC = clang
CFLAGS = -Wall -Wextra -Werror

# Sources
COLLEEN_SRC = Colleen.c
GRACE_SRC = Grace.c
SULLY_SRC = Sully.c

# Binaries
COLLEEN = Colleen
GRACE = Grace
SULLY = Sully

# Objects
OBJS_O = Sully*.o Grace.o Colleen.o

all: colleen grace sully

colleen: $(COLLEEN)
	$(CC) $(CFLAGS) -o $(COLLEEN) $(COLLEEN_SRC)
	./Colleen > tmp_Colleen
	diff Colleen.c tmp_Colleen

$(COLLEEN): $(COLLEEN_SRC)
	$(CC) $(CFLAGS) -o $@ -c $<

grace: $(GRACE)
	$(CC) $(CFLAGS) -o $(GRACE) $(GRACE_SRC)
	./Grace
	diff Grace.c Grace_kid.c

$(GRACE): $(GRACE_SRC)
	$(CC) $(CFLAGS) -o $@ -c $<

sully:
	$(CC) $(CFLAGS) -o $(SULLY) $(SULLY_SRC)
	./Sully

$(SULLY): $(SULLY_SRC)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS_O)

fclean: clean
	rm -rf $(COLLEEN) tmp_Colleen $(GRACE) Grace_kid.c $(SULLY) $(SULLY)_*

.PHONY: Colleen Grace clean fclean re
