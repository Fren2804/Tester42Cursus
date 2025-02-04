#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h> 
#define INT_MAX 2147483647
#define INT_MIN -2147483648

void ft_check_int(int num1, int num2, char *nombre_funcion, int prueba)
{
    if (num1 == num2)
    {
        printf("\U00002705 %-3d- ft_%-5s: %-15d		%-5s: %-15d \n", prueba, nombre_funcion, num1, nombre_funcion, num2);
    }
    else
    {
        printf("\U0000274C %-3d- ft_%-5s: %-15d		%-5s: %-15d \n", prueba, nombre_funcion, num1, nombre_funcion, num2);
    }
}

void ft_check_str(char *str1, char *str2, char *nombre_funcion, int prueba)
{
	if (strcmp(str1, str2) == 0)
    {
        printf("\U00002705 %-3d- ft_%-5s: %-30s		%-5s: %-30s \n", prueba, nombre_funcion, str1, nombre_funcion, str2);
    }
    else
    {
        printf("\U0000274C %-3d- ft_%-5s: %-30s		%-5s: %-30s \n", prueba, nombre_funcion, str1, nombre_funcion, str2);
    }
}

void ft_check_size(void *str1, void *str2, char *nombre_funcion, int prueba)
{
	if (sizeof(*str1) == sizeof(*str2))
    {
        printf("\U00002705 %-3d- sizeof-ft_%-10s: %-20ld		sizeof-%-5s: %-20ld \n", prueba, nombre_funcion, sizeof(*str1), nombre_funcion, sizeof(*str2));
    }
    else
    {
        printf("\U0000274C %-3d- sizeof-ft_%-10s: %-20ld		sizeof-%-5s: %-20ld \n", prueba, nombre_funcion, sizeof(*str1), nombre_funcion, sizeof(*str2));
    }
}

void ft_check_is(int num1, int num2, char *nombre_funcion, int prueba, int value)
{
    if ((num1 != num2 && (num1 != 0 && num2 != 0)) || (num1 == num2 && num1 == 1))
    {
        printf("\U00002705 %-3d- ft_%-5s: %-15d		%-5s: %-15d value: %3d\n", prueba, nombre_funcion, num1, nombre_funcion, num2, value);
    }
    else if (num1 == num2 && (num1 == 0 && num2 == 0))
    {
        printf("\U00002705 %-3d- ft_%-5s: %-15d		%-5s: %-15d value: %3d\n", prueba, nombre_funcion, num1, nombre_funcion, num2, value);
    }
	else
	{
		printf("\U0000274C %-3d- ft_%-5s: %-15d		%-5s: %-15d value: %3d\n", prueba, nombre_funcion, num1, nombre_funcion, num2, value);
	}
}

unsigned char ft_generate_upper()
{
	int num;

	num = rand() % 26;
	num += 65;
	return ((unsigned char) num);
}

unsigned char ft_generate_lower()
{
	int num;

	num = rand() % 26;
	num += 97;
	return ((unsigned char) num);
}

unsigned char ft_generate_digit()
{
	int num;

	num = rand() % 10;
	num += 48;
	return ((unsigned char) num);
}

unsigned char ft_generate_isspace()
{
	int random;

	random = rand() % 6;

	if(random == 0)
		return (32);
	else if (random == 1)
        return (9);            
    else if (random == 2)
        return (10);           
    else if (random == 3)
        return (11);           
    else if (random == 4)
        return (12);           
    else
        return (13); 
}

int ft_generate_int()
{
	int num;
	int num1;

	num = rand() % INT_MAX + 1;
	num1 = rand() % INT_MAX + 1;
	num -= num1;
	return (num);
}

unsigned char ft_generate_ulde()
{
	int random;

	random = rand() % 10;
	if (random <= 2)
		return (ft_generate_upper());
	else if(random <= 5)
		return (ft_generate_lower());
	else if(random <= 8)
		return (ft_generate_digit());
	else
		return (32);
}

void ft_generate_string(char **s, int len_max, int num_dis)
{
	int i = 0;
	int len;
	int random;

	if (len_max != 0)
		len = rand() % len_max;
	else
		len = 0;		
	*s = malloc(len + 1);
	if (!(*s))
		return ;
	(*s)[len] = '\0';
	while(i < len)
	{
		random = rand() % 20;
		if (random == 0)
			(*s)[i] = '\0';
		else if (random <= 4)
			(*s)[i] = 32;
		else if (random == 5 && num_dis)
			(*s)[i] = ft_generate_digit();
		else if (random <= 11)
			(*s)[i] = ft_generate_upper();
		else
			(*s)[i] = ft_generate_lower();
		i ++;
	}
}

void ft_generate_atoi(char **s, int len_max)
{
	int i = 0;
	int len;
	int random;
	int control;
	len = rand() % len_max;
	*s = malloc(len + 1);
	if (!(*s))
		return ;
	(*s)[len] = '\0';
	control = 0;
	while(i < len)
	{
		if (control == 0)
		{
			random = rand() % 2;
			if (random == 0)
				control = 1;
			else
				(*s)[i] = ft_generate_isspace();
		}
		if (control == 1)
		{
			random = rand() % 9;
			if (random <= 4)
				control = 2;
			else if (random <= 6)
				(*s)[i] = 45;
			else
				(*s)[i] = 43;
		}
		if (control == 2)
		{
			random = rand() % 9;
			if (random == 0)
				control = 3;
			else
				(*s)[i] = ft_generate_digit();
		}
		if (control == 3)
		{
			random = rand() % 9;
			if (random == 0)
				(*s)[i] = 0;
			else if (random <= 2)
				(*s)[i] = ft_generate_lower();
			else if (random <= 4)
				(*s)[i] = ft_generate_upper();
			else if (random <= 6)
				(*s)[i] = ft_generate_isspace();
			else
				(*s)[i] = ft_generate_digit();
		}
		i ++;
	}
}

void ft_generate_bzero(char **s, int len)
{
	*s = malloc(len + 1);
	if (!(*s))
		return ;
}


int main(void)
{
	int		i;
	char	*str;
	char	*str1;
	char	*str2;
	char	*str3;
	int		cantidad_pruebas;
	int		random;
	int		random1;
	int		random2;
	int		aux;
	int		aux1;
	clock_t start, end;
    double cpu_time_used_ft;
	double cpu_time_used;

	cantidad_pruebas = 100;
	srand(time(NULL));

	printf ("\n\U00002B50------Pruebas Memcpy-----\U00002B50\n");
	i = 0;
	while (i ++ < cantidad_pruebas)
	{
		random = rand() % 20;
		random1 = rand() % 20;
		ft_generate_string(&str, random, 1);
		str1 = calloc(30, 1);
		str2 = calloc(30, 1);
		if (!str1 || !str2)
			return (1);
		if (strlen(str) < random1)
			random1 = strlen(str);
		ft_memcpy(str1, str, random1);
		memcpy(str2, str, random1);	
		ft_check_str((char *)str1,(char *)str2, "memcpy", i);
		free(str);
		free(str1);
		free(str2);
	}

	return (0);
}