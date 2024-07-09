# Compilador
CC = gcc

# Archivo ejecutable
TARGET = ordenamiento

# Flags de compilación
CFLAGS = -Wall -Wextra

# Archivo fuente
SRCS = main.c

# Archivo objeto, generado a partir de archivo fuente
OBJS = $(SRCS:.c=.o)

# Regla para compilar el ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regla para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Limpia archivos generados
clean:
	rm -f $(OBJS) $(TARGET)

distclean: clean
	rm -f Makefile