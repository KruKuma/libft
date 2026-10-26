*This project has been created as part of the 42 curriculum by nfurst.*

# Libft

## Description

**Libft** is a C static library (`libft.a`) that reimplements useful functions from the C standard library and adds utilities for strings, output, and singly linked lists. It is intended to provide reusable building blocks for later 42 projects while practicing memory management, pointers, compilation, and basic data structures.

The project includes **43 functions** in three parts:

### Part 1 — Libc functions (23)

- **Character checks and conversions:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`.
- **Memory handling:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`.
- **String operations:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`.
- **Conversion:** `ft_atoi`.

### Part 2 — Additional functions (11)

- **Creating and transforming strings:** `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`.
- **Writing to a file descriptor:** `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`.

Functions returning dynamically allocated strings or arrays transfer ownership to the caller. In particular, free each string returned by `ft_split`, then free the array itself.

### Part 3 — Linked lists (9)

The library uses this singly linked-list type:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

- **Create and add nodes:** `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`.
- **Inspect lists:** `ft_lstsize`, `ft_lstlast`.
- **Delete or clear:** `ft_lstdelone`, `ft_lstclear`.
- **Iterate or transform:** `ft_lstiter`, `ft_lstmap`.

Each node stores a generic `void *content` pointer and a pointer to the next node. Functions that delete content accept a callback so callers can control how their data is freed. `ft_lstmap` creates a new list; it does not modify the original list.

## Instructions

### Requirements

- A C compiler (`cc`), `make`, and the `ar` archiver.
- The repository root contains `Makefile`, `libft.h`, and all `ft_*.c` source files.

### Compilation

From the repository root, run:

```sh
make        # compile the objects and create libft.a
make clean  # remove object files
make fclean # remove object files and libft.a
make re     # rebuild from scratch
```

Compilation uses `-Wall -Wextra -Werror -std=c99`. The Makefile creates the static library with `ar`.

### Using the library

Include `libft.h` and link `libft.a` into your program. For example, from the repository root, given a separate `main.c`:

```sh
cc -Wall -Wextra -Werror -std=c99 main.c -L. -lft -o my_program
./my_program
```

Example `main.c`:

```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    printf("Length: %zu\n", ft_strlen("Hello, Libft!"));
    return (0);
}
```

### Important notes

- The functions are implemented without calling their standard-library equivalents.
- Character-testing functions return `1` for a match and `0` otherwise.
- Some functions allocate memory; the caller must free returned memory when it is no longer needed.
- Check allocation results before using pointers.
- File-descriptor output functions use `write` and do not append a newline unless their description specifies one.

## Resources

- [42 Libft subject](https://github.com/42School) — refer to the official subject supplied by your campus for the exact rules and required behavior.
- [C reference — cppreference](https://en.cppreference.com/w/c) — C language and standard-library reference.
- [Linux man-pages project](https://man7.org/linux/man-pages/) — manual pages for `malloc`, `free`, `write`, and libc functions.
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html) — Makefile syntax and build rules.
