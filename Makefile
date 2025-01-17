NAME = Abstractvm

stat = Development
log_path = Logs

CC = c++ -std=c++23
CURRENTDIR=$(shell pwd)
INC = -I$(CURRENTDIR)/src/Includes -I$(CURRENTDIR)/src/Dignoses/Includes

RED = \033[0;31m
R_3 = \033[0;34m
GREEN = \033[0;32m
NO_COLOR = \033[0m
EOL= \033[0K

CFLAGS = -Wall -Wextra -Werror -Wno-error -fsanitize=address # TODO: no error just for diagnose files

Headers= $(shell find . -type f -name "*.hpp")
SRC_FILES = $(shell find . -type f -name "*.cpp")

OUTDIR = build/outfiles
$(shell mkdir -p $(OUTDIR))
OBJ_FILES = $(patsubst %.cpp,$(OUTDIR)/%.o,$(notdir $(SRC_FILES)))

vpath %.cpp $(sort $(dir $(SRC_FILES)))

$(OUTDIR)/%.o:%.cpp  $(Headers)
	@printf "\r$(GREEN)Compiling $< ...$(NO_COLOR)$(EOL)"
	@${CC} ${CFLAGS} $(INC)  -o $@ -c $< -D $(stat)



all: CFLAGS += -DDIAGNOSING -DLOG_PATH=\"$(log_path)\" #TODO: diagno
all: $(NAME)

diagno: $(NAME)

$(NAME): $(OBJ_FILES)
	@mkdir -p ${log_path}
	@$(CC) ${CFLAGS} $(INC) $(OBJ_FILES) -o build/${NAME}
	@printf "\r$(GREEN)Compilation done$(NO_COLOR)$(EOL)\n"

clean:
	@rm -f $(OBJ_FILES)
	@echo "$(RED)Object files removed$(NO_COLOR)$(EOL)"

fclean: clean
	@rm -rif $(log_path)
	@echo "$(RED)Logs removed$(NO_COLOR)$(EOL)"
	@rm -f $(NAME)
	@echo "$(RED)Executable removed$(NO_COLOR)$(EOL)"

run: ${NAME}
	@./build/${NAME}; \
	EXIT_CODE=$$?; \
	if [ $$EXIT_CODE -eq 0 ]; then \
		echo "$(GREEN)Good By!$(NO_COLOR)"; \
	else \
		echo "$(RED)fail ($$EXIT_CODE)$(NO_COLOR)"; \
	fi

re: fclean all

.PHONY: re fclean clean all
