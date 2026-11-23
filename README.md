# Ft_printf Interactive Tester

Utilidad de consola interactiva desarrollada en C++ para probar y comparar tu implementación personalizada de `ft_printf` frente al `printf` estándar del sistema.

---

## 📋 Características del Menú

El programa cuenta con un menú interactivo en bucle con las siguientes opciones de prueba:
1. **Normal:** Mensaje clásico de Hola mundo.
2. **Char:** Impresión de caracteres individuales (`%c`).
3. **Cadena:** Impresión de strings utilizando `std::string::c_str()`.
4. **Entero:** Pruebas con números enteros (`%i`).
5. **Entero sin signo:** Pruebas con valores numéricos sin signo (`%u`).
6. **Hexadecimal:** Conversión de decimal a hexadecimal en mayúsculas y minúsculas (`%x` / `%X`).
7. **Dirección de memoria:** Comprobación de punteros (`%p`).
8. **Salir:** Cierra la ejecución del programa.

---

## ⚙️ Configuración del Header (`libprintf.h`)

Para permitir que un archivo escrito en C++ (`.cpp`) pueda incluir y llamar correctamente a funciones escritas en C sin problemas de *name-mangling*, tu archivo de cabecera debe incluir las guardas condicionales para `__cplusplus` y el bloque `extern "C"`:

```c
#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# ifdef __cplusplus
extern "C" {
# endif

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr(int nb);
int	ft_putnbr_base(ssize_t nbr, const char *base);

# ifdef __cplusplus
}
# endif

#endif // LIBPRINTF_H
```

---

# Compilación

Para compilar este tester interactivo (`main.cpp`) junto con el proyecto de `ft_printf` directamente mediante la terminal sin utilizar ningún Makefile, debes pasarle al compilador `g++` tu archivo principal junto con los archivos fuente en C de la librería.

Ejecuta el siguiente comando en la raíz de tu proyecto:

```bash
g++ -Wall -Wextra -Werror main.cpp ft_printf.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr.c ft_putnbr_base.c -o tester
```
