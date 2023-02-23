#--------------------------------- VARIABLES ---------------------------------#

# Executable (Can be changed).

NAME			= test

# Color codes (Can be changed).

RESET			= \033[0m
GREEN			= \033[32m
YELLOW			= \033[33m

#--------------------------------- DIRECTORIES  -------------------------------#

# Project (Can be changed).

SRCS_DIR		= src
OBJS_DIR		= obj

# Location of all header files used in the project to avoid
# writing the full path upon include (Can be changed).

INCS_DIR		= include

# All the subdirectories used in the project
# to organise include files (Can be changed).

INCS_SUBDIRS	:= algorithm
INCS_SUBDIRS	+= container
INCS_SUBDIRS	+= functional
INCS_SUBDIRS	+= iterator
INCS_SUBDIRS	+= type_traits
INCS_SUBDIRS	+= utility

#------------------------------------ FILES -----------------------------------#

# Used header at each compilation to check file integrity (Can be changed).

INCS			:= algorithm/algorithm.hpp
INCS			+= container/map.hpp
INCS			+= container/set.hpp
INCS			+= container/stack.hpp
INCS			+= container/vector.hpp
INCS			+= functional/functional.hpp
INCS			+= iterator/iterator.hpp
INCS			+= type_traits/type_traits.hpp
INCS			+= utility/utility.hpp

# Source files (Can be changed)

SRCS_MANDA		:= main.cpp
SRCS_BONUS		:= main_bonus.cpp

#-------------------------------- MISCELANEOUS --------------------------------#

# Some tricks in order to get the makefile doing his job (Can't be changed).

D_SRCS			= $(addsuffix /, $(SRCS_DIR))
D_OBJS			= $(addsuffix /, $(OBJS_DIR))
D_INCS			= $(addsuffix /, $(INCS_DIR))
C_OBJS_MANDA	= $(addprefix $(D_OBJS), $(OBJS_MANDA))
C_OBJS_BONUS	= $(addprefix $(D_OBJS), $(OBJS_BONUS))
C_INCS			= $(addprefix $(D_INCS), $(INCS))
C_INCS_SUBDIRS	= $(foreach dir, $(INCS_SUBDIRS), -I$(D_INCS)$(dir))

ifeq ($(BONUS_FLAG),1)
	C_OBJS		= $(C_OBJS_BONUS)
else
	C_OBJS		= $(C_OBJS_MANDA)
endif

#--------------------------------- COMPILATION --------------------------------#

# How files should be compiled (Can't be changed).

CXX				= c++
OBJS_MANDA		= $(SRCS_MANDA:.cpp=.o)
OBJS_BONUS		= $(SRCS_BONUS:.cpp=.o)

# Compilation flags (Can be changed).

CXXFLAGS		= $(C_INCS_SUBDIRS) -Wall -Wextra -Werror -std=c++98

#------------------------------------ RULES -----------------------------------#

# Redefinition of the implicit compilation rule
# to prompt some informations (Can't be changed).

$(D_OBJS)%.o: $(D_SRCS)%.cpp $(C_INCS)
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Implicit make rule simply using dependancies
# to compile our project (Can't be canged).

all: $(OBJS_DIR) $(NAME)

bonus:
	@make BONUS_FLAG=1

$(NAME): $(C_OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(C_OBJS)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

# Rules used to create folders if they aren't already existing (Can be changed).

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# Deleting all .o files. (Can't be changed).

clean:
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) -r $(OBJS_DIR)

# Deleting all executables after cleaning up
# all .o files (Can't be changed).

fclean:
	@make clean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@$(RM) $(NAME)

# Re-compile everything (Can't be changed).

re:
	@make fclean
	@make all

# Avoid unexpected behaviour when regular files
# get the same name as the following variables (Can be changed).

.PHONY: all clean fclean re bonus
