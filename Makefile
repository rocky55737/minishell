NAME 								:=	minishell

SRC_DIR							:=	./src/
INCLUDE							:=	-I./inc/

CC 							:=	cc
CFLAGS 						:=	-Wall -Wextra -Werror

LIB_NAME					:=	ft
LIB_DIR						:=	./libft/
LIB							:=	$(LIB_DIR)lib$(LIB_NAME).a
LIB_FLAGS					:=	-L $(LIB_DIR) -l$(LIB_NAME) -I$(LIB_DIR)


##### Sources #######
SRC_PARSING_DIR				:=	parsing/
SRC_EXECUTING_DIR			:=	executing/
SRC_BUILTIN_DIR				:=	builtin/

SRC_PARSING					:=	expand_env.c here_doc.c init.c parse_utils1.c \
parse_utils2.c parse_line.c remove_quote.c signal1.c signal2.c split_word.c \
syntax_check.c tokenize_utils.c tokenize.c tree_parsing.c free_list.c \
heredoc_utils.c expand_env_utils.c shell_level.c main_utils.c

SRC_EXECUTING				:=	cmd_exec_child.c do_builtin_1.c do_builtin_2.c \
env_list_to_str_ptr.c find_cmd_path.c free_str_ptr.c in_file_open.c malloc_null_guard.c \
ms_command_search_and_execution.c ms_exec_cmd.c ms_exec_cmd_init.c ms_free_data.c \
ms_set_back.c ms_simple_command_expansion.c ms_simple_command_expansion2.c ms_wait_all.c

SRC_BUILTIN					:=	can_be_name.c find_env_by_name_in_list.c ft_atol.c \
ms_cd.c ms_echo.c ms_env.c ms_exit.c ms_export.c ms_export2.c ms_pwd.c ms_unset.c str_is_long_long.c str_ptr_len.c

SRC_FILES					:=	main.c \
								$(addprefix $(SRC_PARSING_DIR), $(SRC_PARSING)) \
								$(addprefix $(SRC_BUILTIN_DIR), $(SRC_BUILTIN)) \
								$(addprefix $(SRC_EXECUTING_DIR), $(SRC_EXECUTING))

SRCS						:=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS						:=	$(SRCS:%.c=%.o)


### Cluster
 READLINE_LIB 	= -lreadline -L${HOME}/.brew/opt/readline/lib
 READLINE_INC	= -I${HOME}/.brew/opt/readline/include

### Home
#READLINE_LIB 	= -lreadline -L/opt/homebrew/opt/readline/lib
#READLINE_INC	= -I/opt/homebrew/opt/readline/include

ifdef DEBUG_MODE
	CFLAGS					:=	$(CFLAGS) -g
endif

ifdef D_SANI
	CFLAGS					:=	$(CFLAGS) -g -fsanitize=address
endif

.PHONY : all
all : $(NAME)

.PHONY : clean
clean :
	@rm -f $(OBJS)
	@make clean -C libft
	@echo "$(NAME) object files removed"

.PHONY : fclean
fclean : clean
	@rm -f $(NAME)
	@$(RM) libft.a
	@$(RM) libft/libft.a
	@echo "$(NAME) executable removed"

.PHONY : re
re : fclean all

debug : fclean
	make DEBUG_MODE=1 all

dsani : fclean
	make D_SANI=1 all

$(NAME) : $(OBJS)
	@$(MAKE) bonus -C $(LIB_DIR)
	@$(CC) $(CFLAGS) -o $@ $^ $(READLINE_LIB) $(LIB_FLAGS)
	@echo "$(NAME) made"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE) -I$(LIB_DIR) $(READLINE_INC)