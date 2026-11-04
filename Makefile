# Variables
CC = gcc
CFLAGS = -Wextra -Werror -O2 -Iinclude
LDFLAGS = -Llib
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
INCLUDE_DIR = include

LIBS = -lmyhashmap -lm


# Liste des fichiers source
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))


# Fichiers source
LIB_SRC = $(SRC_DIR)/hashmap.c
MAIN_SRC = $(SRC_DIR)/indexe_texte.c

# Fichiers objets
LIB_OBJ = $(OBJ_DIR)/hashmap.o
MAIN_OBJ = $(OBJ_DIR)/indexe_texte.o




# Noms des bibliothèques et exécutable
SHARED_LIB = $(LIB_DIR)/libmyhashmap.so
EXECUTABLE = indexe_texte

# Cibles par défaut
all: $(SHARED_LIB) $(EXECUTABLE)

# Compilation des fichiers objets pour la bibliothèque dynamique
$(LIB_OBJ): $(LIB_SRC)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# Création de la bibliothèque dynamique
$(SHARED_LIB): $(LIB_OBJ)
	@mkdir -p $(LIB_DIR)
	$(CC) -shared -o $@ $^

# Compilation du fichier main
$(MAIN_OBJ): $(MAIN_SRC)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Lien du programme avec la bibliothèque dynamique
$(EXECUTABLE): $(MAIN_OBJ) $(SHARED_LIB)
	$(CC) $(MAIN_OBJ) -o $@ -L$(LIB_DIR) $(LIBS)

# Nettoyage des fichiers objets et exécutables
clean:
	rm -rf $(OBJ_DIR) $(EXECUTABLE)

# Nettoyage complet (avec les bibliothèques)
distclean: clean
	rm -rf $(LIB_DIR)

# Afficher l'aide
help:
	@echo "Cibles disponibles :"
	@echo "  all        - Compiler la bibliothèque dynamique et le programme"
	@echo "  clean      - Supprimer les fichiers objets et exécutables"
	@echo "  distclean  - Supprimer tous les fichiers compilés"
	@echo "  help       - Afficher ce message d'aide"

.PHONY: all clean distclean help
