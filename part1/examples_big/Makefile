CC = gcc
CFLAGS = -DINT_X#-Wall
#LD_FLAGS = -lm

DIR = .

TARG = $(DIR)/exec_name

DEP0 = $(DIR)/utils.o
DEP1 = $(DIR)/program.o

SRC0 = $(DIR)/utils.c
SRC1 = $(DIR)/program.c

ALL_DEPS = $(DEP0) $(DEP1)

#MANDATORY: use tab for indentation!
$(TARG): $(DEP1) $(DEP0)
	$(CC) -o $(TARG) $(ALL_DEPS)

$(DEP1): $(SRC1)
	$(CC) $(CFLAGS) -c $(SRC1) -o $(DEP1)

$(DEP0): $(SRC0)
	$(CC) $(CFLAGS) -c $(SRC0) -o $(DEP0)

#'test' target
test: $(TARG)
	$(TARG) -f list_ints_huge.txt -s bubble

#removing objects and target
.PHONY: clean
clean:
	$(RM) $(ALL_DEPS) $(TARG)
