NAME = diamondtrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wno-shadow

SRCDIR = .
OBJDIR = obj

SOURCES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re