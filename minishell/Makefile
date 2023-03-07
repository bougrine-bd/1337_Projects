NAME= minishell

src= Executor/main.c Executor/convert.c \
builtins/cd.c builtins/echo.c builtins/env.c builtins/exit_msh.c builtins/export.c builtins/pwd.c builtins/unset.c \
Executor/tab_handling.c  Executor/utils.c Executor/data_handling.c Executor/utils2.c Executor/execute_heredocs.c \
Executor/piped_commands.c Executor/tmpfiles.c \
Executor/parse_command.c Executor/variables.c Executor/quotes.c Executor/heredoc_utils.c Executor/extract_filename.c\
Executor/commands_handling.c Executor/launch_commands.c Executor/redirections.c Parser/change_exit_stat.c \
Parser/change_vars.c Parser/change_vars_utils.c Parser/extra_funcs.c Parser/is_var.c Parser/parse_errors.c \
Parser/parsing_cmd.c Parser/parse_errors_utils.c Parser/split_args.c \
Parser/split_cmds.c

obj= main.o convert.o cd.o echo.o env.o exit_msh.o export.o pwd.o unset.o tab_handling.o \
utils.o data_handling.o utils2.o parse_command.o variables.o quotes.o heredoc_utils.o \
extract_filename.o commands_handling.o launch_commands.o redirections.o \
change_exit_stat.o change_vars.o change_vars_utils.o extra_funcs.o is_var.o parse_errors.o \
parsing_cmd.o parse_errors_utils.o split_args.o split_cmds.o tmpfiles.o piped_commands.o execute_heredocs.o

all: $(NAME)

$(NAME): $(src)
		@gcc -Wall -Wextra -Werror -c $(src)
		@gcc -Wall -Wextra -Werror -lreadline -o $(NAME) $(obj)

clean :
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME)

re : fclean all
