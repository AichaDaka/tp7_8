# Makefile à completer pour vos besoins
EXE 		= bin/executable

# Compilateur et editeur de lien
COMP		= @gcc
LINK		= @gcc

# Options de compilation et editions de liens
CPPFLAGS	= -Wall -ansi -ggdb -std=c99
EDLFLAGS	=

#Dossiers
SRC_DIR		= src
OBJ_DIR		= obj

#Fichiers
INTERFACES_FILES		= AVL.h Collection.h Element.h																# Mettre les .h ici
INT 					= $(addprefix $(SRC_DIR)/, $(INTERFACES_FILES))					# construit le chemin des sources 
OBJ						= $(addprefix $(OBJ_DIR)/, $(INTERFACES_FILES:.h=.o))			# Génération du nom des fichiers obj
MAIN_OBJ 				= $(OBJ_DIR)/main.o												# .o du fichier ou se trouve le main


#Autres commandes et message
ECHO		= @echo
RM			= @rm
MESSAGE		= "Compilation réussie"

$(EXE): $(OBJ) $(MAIN_OBJ)
	$(LINK) -o $(EXE) $^ $(EDLFLAGS)
	$(ECHO) $(MESSAGE)

#Mettre les dependances particulieres ici
$(MAIN_OBJ): $(INT)

#Generation des fichiers obj
$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(ECHO) "Compilation de $< (generation de $@)"
	$(COMP) -o $@ -c $< $(CPPFLAGS)  

clean:
	$(RM) -fv $(OBJ_DIR)/*.o $(EXE)
