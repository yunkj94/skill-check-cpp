SRCS=q004.cc list_manager.cc
PROGRAM=$(basename $(firstword $(SRCS)))

CC=g++
CFLAGS=-g -Wall
LDFLAGS=
LIBS=
INCULDES=
OBJDIR=../build/$(PROGRAM)
OBJS=$(addprefix $(OBJDIR)/, $(SRCS:.cc=.o))
TARGET=$(OBJDIR)/$(PROGRAM)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

$(OBJDIR)/%.o: ./%.cc
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CC) $(INCLUDES) $(CFLAGS) -o $@ -c $<

run: $(TARGET)
	$(TARGET)

debug: $(TARGET)
	gdb $(TARGET)

all: clean $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
