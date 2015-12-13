# Makefile à completer pour vos besoins
EXE 		= bin/executable

# Compilateur et editeur de lien
COMP		= @gcc
LINK		= @gcc

# Choix de l'implementation
IMPLEMENATION = AVL
#IMPLEMENATION = ARN

# Options de compilation et editions de liens
CPPFLAGS	= -Wall -ansi -ggdb -std=c99 -D$(IMPLEMENATION)
EDLFLAGS	=

#Dossiers
SRC_DIR		= src
OBJ_DIR		= obj

#Fichiers
INTERFACES_FILES		= Avl.h Collection.h Element.h Utils.h Ascii.h Arn.h														# Mettre les .h ici
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

$(OBJ_DIR)/Collection.o : $(SRC_DIR)/Collection.h

$(OBJ_DIR)/Avl.o : $(SRC_DIR)/Avl.h $(SRC_DIR)/Element.h $(SRC_DIR)/Utils.h

$(OBJ_DIR)/Element.o : $(SRC_DIR)/Element.h

#Generation des fichiers obj
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(ECHO) "Compilation de $< (generation de $@)"
	$(COMP) -o $@ -c $< $(CPPFLAGS)  

clean:
	$(RM) -fv $(OBJ_DIR)/*.o $(EXE)
