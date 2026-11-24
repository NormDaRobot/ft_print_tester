#include <iostream>
#include <string>
#include <limits.h>

extern "C" {
	#include "ft_printf.h"
}

int main()
{
	int num, real_len, my_len, op;
	std::string str;
	const char *args[] = {"./programa", NULL};
	unsigned int unum;
	char a, u;

	do
	{
		system("clear");
		std::cout << "--MENU--" << std::endl;
		std::cout << "1. Normal (un hola mundo)." << std::endl;
		std::cout << "2. Con un char." << std::endl;
		std::cout << "3. Con cadena." << std::endl;
		std::cout << "4. Con entero." << std::endl;
		std::cout << "5. Entero sin signo." << std::endl;
		std::cout << "6. Hexadecimal" << std::endl;
		std::cout << "7. Direccion de memoria de una variable." << std::endl;
		std::cout << "8. Exit." << std::endl;
		std::cout << "9. Actualizar." << std::endl;
		std::cout << "Selecciona opcion: " << std::flush;
		std::cin >> op;

		switch(op)
		{
			case 1:
				do
				{
					real_len = printf("Hola mundo! desde printf\n");
					my_len = ft_printf("Hola mundo! desde ft_printf\n");
					if ((real_len + 3) == my_len)
						std::cout << "Longitud OK" << std::endl;
					else
						std::cout << "Longitud KO" << std::endl;
					std::cout << "Continue? (y/n) " << std::flush;
					std::cin >> a;
				} while (a != 'n');
				break;

			case 2:
				do
				{
					std::cout << "Char a imprimir: " << std::flush;
					std::cin >> u;
					real_len = printf("Vamos a imprimir el char desde printf: %c\n", u);
					my_len = printf("Vamos a imprimir el char desde ft_printf: %c\n", u);
					if ((real_len + 3) == my_len)
						std::cout << "Longitud OK" << std::endl;
					else
						std::cout << "Longitud KO" << std::endl;
					std::cout << "Continue? (y/n) " << std::flush;
					std::cin.ignore(10000, '\n');
					std::cin >> a;
				} while (a != 'n');
				break; 

			case 3:
				do
				{
					std::cin.ignore(10000, '\n');
					std::cout << "Cadena a imprimir: " << std::flush;
					getline(std::cin, str);
					my_len = ft_printf("El resultado desde ft_printf es: %s\n", str.cstr());
					real_len = printf("El resultado desde printf es: %s\n", str.cstr());

					if (real_len + 3 == my_len)
						std::cout << "Longitud OK" << std::endl;
					else
						std::cout << "Longitud KO" << std::endl;
					std::cout << "Continue? (y/n) " << std::flush;
					std::cin >> a;
				} while (a != 'n');
				break; 

			case 4:
				do
				{
					std::cout << "Resultado que quiere imprimir(int): " << std::flush;
					std::cin >> num;
					std::cin.ignore(10000, '\n');
					real_len = printf("El resultado es: %i\n", num);
					my_len = ft_printf("El resultado es: %i\n", num);
					if (real_len == my_len)
						std::cout << "Longitud OK" << std::endl;
					else
						std::cout << "Longitud KO" << std::endl;
					std::cout << "Continue? (y/n) " << std::flush;
					std::cin >> a;
				} while (a != 'n');
				break; 

			case 5:
				do
				{
					std::cout << "Que numerin quiere usted imprimiiiiir? " << std::endl;
					std::cin >> unum;
					real_len = printf("El resultado de printf es: %x\n", unum);
					my_len = ft_printf("El resultado de ft_printf es: %u\n", unum);
					if (real_len + 3 == my_len)
						std::cout << "Longitud OK" << std::endl;
					else
						std::cout << "Longitud KO" << std::endl;
					std::cout << "Continue? (y/n) " << std::flush;
					std::cin >> a;
				} while (a != 'n');
				break; 

			case 6:
				do
				{
					std::cout << "5. Convertir numeros de base decimal a base hexadecimal:\n";
					std::cout << "Numero para convertir: " << std::flush;
					std::cin >> num;
					real_len = printf("Con mayusculas en printf: %X\n", num);
					my_len = ft_printf("Con mayusculas en ft_printf: %X\n", num);

					if (real_len + 3 == my_len)
						std::cout << "Longitud OK" << std::endl;
					else
						std::cout << "Longitud KO" << std::endl;

					real_len = printf("Con minusculas en printf: %x\n", num);
					my_len = ft_printf("Con minusculas en ft_printf: %x\n", num);

					if (real_len + 3 == my_len)
						std::cout << "Longitud OK" << std::endl;
					else
						std::cout << "Longitud KO" << std::endl;
					std::cout << "Continue? (y/n) " << std::flush;
					std::cin >> a;
				} while (a != 'n');
				break; 

			case 7:
				do
				{
					std::cout << "4. Vamos a imprimir la direccion de memoria de el string anterior" << std::endl;
					printf("La ubicacion de memoria de la var str desde el printf es: %p\n", &str);
					ft_printf("La ubicacion de memoria de la var str desde el ft_printf es: %p\n", &str);
					if (real_len + 3 == my_len)
						std::cout << "Longitud OK" << std::endl;
					else
						std::cout << "Longitud KO" << std::endl;
					std::cout << "Continue? (y/n) " << std::flush;
					std::cin >> a;
				} while (a != 'n');
				break;

			case 8:
				std::cout << "Saliendo.." << std::endl;
				exit(0);
				break; 

			case 9:
				if (system("g++ main.cpp ft_printf.c fts_put.c -o programa") != 0)
				{
					std::cout << "Error de compilacion o demasiados intentos.\nSaliendo del programa ..." << std::endl;
					std::cin.ignore(10000, '\n');
					std::cin.get();
					return 1;
				}
				std::cout << "Recompilacio exitosa. Su programa ha sido actualizado" << std::endl;
				execvp(args[0], (char *const *)args);
				perror("Error critico de execvp\n");
				break;

			default:
				std::cout << "Opcion no valida, vuelva a intentar." << std::endl;
				break;
		}
		fflush(stdout);
		system ("read -p 'Presiona enter para continuar ...' var");
	} while (op != 8);
	return 0;
}
