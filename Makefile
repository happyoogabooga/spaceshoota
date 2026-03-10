CC = C:/msys64/ucrt64/bin/gcc.exe

# Compiler flags
CFLAGS = -fdiagnostics-color=always -g \
	-I C:/msys64/ucrt64/include/SDL2 \
	-I ./headers

# Linker flags
LDFLAGS = -L C:/msys64/mingw64/lib \
	-lmingw32 -lSDL2main -lSDL2 -lSDL2_image

# Target
TARGET = main.exe
SRC = shoota.c headers/saucer.c headers/structure.c headers/trianglecoli.c headers/projectiles.c
DYNARR_SRC = dynamicarray/dynarr.c
OBJS = $(SRC:.c=.o) $(DYNARR_SRC:.c=.o)

# Build rule
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f *.o dynamicarray/*.o main.exe
	rm -f headers/*.o
# Run rule
run: $(TARGET)
	./$(TARGET)