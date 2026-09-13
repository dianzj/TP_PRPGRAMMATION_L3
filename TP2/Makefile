CC = clang

# chemin d'acces aux fichiers .h (interfaces)
INCDIR = include

# chemin d'acces aux fichiers .c (implementations)
SRCDIR = src

# chemin d'acces aux fichiers de test
TESTDIR = test

# chemin d'acces aux librairies (binaires)
LIBDIR = .

# options pour l'edition des liens
LDOPTS = -L$(LIBDIR) -lm

# options pour la recherche des fichiers .h
INCLUDEOPTS = -I$(INCDIR)

# options de compilation
COMPILOPTS = -g -Wall $(INCLUDEOPTS)

# liste des executables
EXECUTABLES = tp2


#############################################################################
# definition des regles
#############################################################################

########################################################
# la regle par defaut
all : $(EXECUTABLES)

########################################################
# regle generique de compilation des modules de src/
$(SRCDIR)/%.o : $(SRCDIR)/%.c $(INCDIR)/%.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module "$*
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $< -o $@

########################################################
# regle generique de compilation des fichiers de test/
$(TESTDIR)/%.o : $(TESTDIR)/%.c $(INCDIR)/%.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du test "$*
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $< -o $@

########################################################
# regle de compilation de main.c
main.o : main.c $(INCDIR)/fct.h $(INCDIR)/test_fct.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation de main"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $< -o $@

########################################################
# regles explicites de creation des executables

tp2: main.o $(SRCDIR)/fct.o $(TESTDIR)/test_fct.o
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) -o $@ $^ $(LDOPTS)

########################################################
# regle pour "nettoyer" le repertoire
clean:
	rm -fR $(EXECUTABLES) main.o $(SRCDIR)/*.o $(TESTDIR)/*.o

.PHONY: all clean