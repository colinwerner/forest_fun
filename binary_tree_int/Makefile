CC=gcc
CFLAGS=-g -O2 -Wall -Wextra -Isrc -DNDEBUG $(OPTFLAGS)

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(SOURCES:.c=.o)

TEST_EXEC=check
TEST_SRC=$(wildcard tests/check_*.c)
TEST_OBJ=$(TEST_SRC:.c=.o)

TARGET=build/binary_tree_int.a
SO_TARGET=$(TARGET:.a=.so)

# The Target Build
all: build $(TARGET) $(SO_TARGET) $(TEST_EXEC)

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

build:
	@mkdir -p build
	@mkdir -p bin

# The Unit Tests
.PHONY: $(TEST_EXEC)
INCPATH=src
$(TEST_EXEC): CFLAGS += $(TARGET)
$(TEST_EXEC):
	$(CC) $(CFLAGS) -o $@ -I$(INCPATH) $(TEST_SRC) -lcheck

# The Cleaner
clean:
	rm -rf build $(OBJECTS) $(TEST_OBJ) $(TEST_EXEC) *.dSYM