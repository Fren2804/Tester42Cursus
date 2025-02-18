#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <bsd/string.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648

void ft_check_int(int num1, int num2, char *nombre_funcion, int prueba)
{
	if (num1 == num2)
	{
		printf("\U00002705 %-3d- ft_%-5s: %-30d		%-5s: %-30d \n", prueba, nombre_funcion, num1, nombre_funcion, num2);
	}
	else
	{
		printf("\U0000274C %-3d- ft_%-5s: %-30d		%-5s: %-30d \n", prueba, nombre_funcion, num1, nombre_funcion, num2);
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
	if (strlen(str1) == strlen(str2))
	{
		printf("\U00002705 %-3d- strlen-ft_%-10s: %-20ld		strlen-%-5s: %-20ld \n", prueba, nombre_funcion, strlen(str1), nombre_funcion, strlen(str2));
	}
	else
	{
		printf("\U0000274C %-3d- strlen-ft_%-10s: %-20ld		strlen-%-5s: %-20ld \n", prueba, nombre_funcion, strlen(str1), nombre_funcion, strlen(str2));
	}
}

void ft_check_buffer(void *buff1, void *buff2, int len, char *nombre_funcion, int prueba, int print)
{
	const unsigned char *buf1 = (const unsigned char *)buff1;
	const unsigned char *buf2 = (const unsigned char *)buff2;
	if (memcmp(buff1, buff2, len) == 0)
	{
		printf("\U00002705 %-3d- prueba buffer -\n", prueba);
		if (print)
		{
			for (size_t i = 0; i < len; i ++)
				printf("- posicion buffer: %-3ld Valor ft_%-5s: %02X - Valor %-5s: %02X \n", i, nombre_funcion, buf1[i], nombre_funcion, buf2[i]);
		}
	}
	else
	{
		printf("\U0000274C %-3d- prueba buffer -\n", prueba);
		if (print)
		{
			for (size_t i = 0; i < len; i ++)
				printf("- posicion buffer: %-3ld Valor ft_%-5s: %02X - Valor %-5s: %02X \n", i, nombre_funcion, buf1[i], nombre_funcion, buf2[i]);
		}
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
	return ((unsigned char)num);
}

unsigned char ft_generate_lower()
{
	int num;

	num = rand() % 26;
	num += 97;
	return ((unsigned char)num);
}

unsigned char ft_generate_digit()
{
	int num;

	num = rand() % 10;
	num += 48;
	return ((unsigned char)num);
}

unsigned char ft_generate_isspace()
{
	int random;

	random = rand() % 6;

	if (random == 0)
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
	else if (random <= 5)
		return (ft_generate_lower());
	else if (random <= 8)
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
		return;
	(*s)[len] = '\0';
	while (i < len)
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
		i++;
	}
}

void ft_generate_string_without_malloc(char **s, int len, int num_dis)
{
	int i = 0;
	int random;

	while (i < len)
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
		i++;
	}
	(*s)[i] = '\0';
}

void ft_generate_atoi(char **s, int len_max)
{
	int i = 0;
	int len;
	int random;
	int control;
	if (len_max != 0)
		len = rand() % len_max;
	else
		len = 0;
	*s = malloc(len + 1);
	if (!(*s))
		return;
	(*s)[len] = '\0';
	control = 0;
	while (i < len)
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
		i++;
	}
}

void ft_generate_bzero(char **s, int len)
{
	*s = malloc(len);
	if (!(*s))
		return;
}

int main(int argc, char *argv[])
{
	int i;
	char *str;
	char *str1;
	char *str2;
	char *str3;
	char *buff;
	char *buff1;
	int cantidad_pruebas;
	int random;
	int random1;
	int random2;
	int aux;
	int aux1;
	int *ptr;
	int *ptr1;
	clock_t start, end;
	double cpu_time_used_ft;
	double cpu_time_used;
	char *long_str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer posuere sapien sit amet rutrum mollis. Praesent non odio feugiat, placerat erat vel, ultrices metus. Curabitur eget ante vitae nisi vehicula accumsan. Ut eu dictum magna, sed ullamcorper metus. Quisque vehicula finibus dui, gravida tempus ante gravida eu. Etiam elementum turpis eget dui accumsan cursus. Aliquam sed cursus nulla. Duis suscipit nulla sed scelerisque commodo. Donec rutrum arcu dolor, in tempor odio ornare non. Ut finibus enim sit amet dictum rutrum. Aenean vitae placerat ex, non vehicula mauris. Quisque et faucibus dolor. Nunc lacus est, placerat sit amet nunc at, consectetur porta dui. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Nullam eget neque in arcu congue consectetur ac at diam. Proin porttitor sapien vel consequat efficitur. Morbi mauris mi, aliquet vitae porta sit amet, ultricies et urna. Sed porta, turpis dictum suscipit tincidunt, arcu massa vestibulum ante, ut ullamcorper justo nisi quis enim. Praesent tempor at lacus id molestie. Ut nec magna elit. Interdum et malesuada fames ac ante ipsum primis in faucibus. Ut lacinia vestibulum facilisis. Suspendisse quis sem ac diam iaculis lacinia in ut odio. Pellentesque tellus dolor, laoreet ut blandit venenatis, pulvinar sed turpis. Praesent et diam ut dui eleifend pulvinar. Ut eget nunc a orci aliquam eleifend. Donec fermentum vulputate metus eu ultrices. Nunc nec consectetur libero, non iaculis tortor. In feugiat rutrum laoreet. Duis in suscipit orci. Aliquam felis eros, porttitor tincidunt suscipit ac, commodo quis augue. Mauris aliquet mauris a nunc ullamcorper auctor at varius erat. Sed dapibus libero et arcu eleifend ornare nec quis magna. Aenean tincidunt felis efficitur, tincidunt risus quis, pharetra lacus. Pellentesque feugiat ornare lectus, accumsan scelerisque nisl accumsan in. Morbi felis nulla, volutpat sed pellentesque a, cursus ac quam. Sed dictum diam ut ligula dapibus, in scelerisque libero dignissim. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Interdum et malesuada fames ac ante ipsum primis in faucibus. Sed lacinia tortor ut tortor vestibulum aliquet. Quisque ipsum nunc, pretium sed porta in, semper ut dolor. Nullam tincidunt odio et vulputate convallis. Integer quis tincidunt nulla. Quisque at mauris vel augue convallis elementum pharetra vitae neque. Curabitur interdum turpis sed ex porta, id tincidunt neque varius. Interdum et malesuada fames ac ante ipsum primis in faucibus. Maecenas vel elit et dui convallis imperdiet. Pellentesque egestas ante magna, at ultrices quam aliquet sed. Donec vestibulum velit ac congue ultrices. Ut venenatis metus molestie consectetur elementum. Mauris vitae nibh eget felis tincidunt congue ut sed orci. Nunc tempor mollis quam id sodales. Mauris est nibh, ullamcorper ac condimentum a, gravida at augue. Maecenas lacinia odio porttitor est posuere porttitor. Vestibulum eu laoreet ante. Sed ut rhoncus diam. In hac habitasse platea dictumst. Mauris in tellus a nulla condimentum tristique. Cras venenatis consectetur nisl nec laoreet. Aenean quis orci facilisis, elementum leo nec, pulvinar enim. Nullam accumsan dui pulvinar turpis ultrices, iaculis porttitor sapien ornare. Mauris sem enim, finibus vitae rutrum ac, ullamcorper nec quam. Donec sed ipsum quis elit tempus dignissim. Sed eu dui magna. Donec ac blandit massa. Donec tempus consequat maximus. Sed lorem arcu, sollicitudin pulvinar auctor vel, eleifend quis mi. Lorem ipsum dolor sit amet, consectetur adipiscing elit. In sed lacus ligula. Nunc id mollis lorem. Aliquam erat volutpat. Nunc volutpat mauris non felis venenatis, at varius augue mollis. Etiam maximus magna mauris, id mollis eros semper ut. Cras maximus sem vitae venenatis sollicitudin. Nullam porttitor ac nisi sed molestie. Nulla aliquam nec magna eu convallis. Proin eget sapien vel erat pulvinar malesuada. Quisque laoreet mauris ipsum, fermentum porta nunc venenatis eu. Suspendisse potenti. Cras quis interdum diam. Integer eu lacus quis neque feugiat rhoncus. Vestibulum ac magna eleifend, fringilla ligula ac, tristique nibh. Mauris eros lorem, venenatis eu erat at, pulvinar consequat urna. Nulla sit amet enim tempus, fermentum justo non, lacinia arcu. Etiam at metus dapibus, vehicula neque eu, blandit odio. Duis odio augue, pharetra nec felis sed, blandit tincidunt metus. Nam eu ante nunc. Aenean mi diam, suscipit at ex quis, rhoncus ornare metus. Morbi dapibus vulputate enim nec tempus. Maecenas laoreet molestie risus sit amet gravida. In condimentum turpis augue, a scelerisque dolor aliquam nec. Sed eget ornare ante. Interdum et malesuada fames ac ante ipsum primis in faucibus. Vivamus eget blandit ipsum. Proin fringilla pharetra augue eget iaculis. Nullam pulvinar odio eget facilisis volutpat. Ut varius ullamcorper tristique. Nunc mattis leo quis elementum vehicula. Sed facilisis, magna vel dignissim pulvinar, purus nisi accumsan lacus, eu maximus massa nulla eget magna. Maecenas feugiat odio id massa mollis tristique. Nullam imperdiet mauris a magna vestibulum scelerisque. Fusce nisi mi, dictum at odio sed, ullamcorper volutpat lectus. Sed lobortis tincidunt dui, in cursus enim congue non. Ut euismod vel justo non dignissim. Mauris vitae ex vestibulum, lobortis nibh vitae, pellentesque urna. Phasellus gravida sagittis varius. Vivamus tempor ex eros, ac tincidunt nibh condimentum a. Vestibulum sed tortor ac orci semper dignissim in non velit. Praesent in fermentum leo. Nullam porttitor nisl augue, a euismod ante vulputate at. Maecenas quis felis massa. Nunc sagittis interdum turpis ut tempor. Praesent sed efficitur velit. Vestibulum gravida nulla lectus, pretium euismod turpis auctor ac. Vivamus nunc sem, blandit non enim sed, tristique sagittis urna. Cras sit amet nibh vitae ipsum luctus luctus. Cras consectetur dui nec sodales condimentum. Nam fringilla mi quis accumsan auctor. Integer ultricies euismod quam a accumsan. Praesent fermentum, magna sed ornare convallis, justo enim sollicitudin neque, in semper metus orci at nibh. Proin commodo fermentum eros, consectetur ornare velit ultrices porta. Mauris eu mattis arcu. Pellentesque eu orci rutrum, elementum eros non, vulputate lacus. Aenean sed vulputate lectus. Curabitur mollis aliquam ultrices. Proin sit amet nulla est. Etiam metus urna, gravida ac varius a, dapibus in purus. Donec iaculis diam id pellentesque vulputate. Sed tincidunt, sapien sed fermentum condimentum, justo mi sollicitudin neque, sit amet lacinia orci odio eget mi. Donec hendrerit convallis neque, at rutrum lectus elementum in. In hac habitasse platea dictumst. Nulla pretium enim sit amet faucibus convallis. Aliquam id luctus ex. Quisque quis auctor sem, vitae interdum elit. Nam blandit vehicula est nec interdum. Aenean id cursus mi. Nullam volutpat cursus neque, id commodo elit finibus non. Ut vitae sollicitudin nibh. Phasellus et mauris dapibus, venenatis odio ut, suscipit orci. Vestibulum tristique quam a tellus tempus consectetur. Morbi eu arcu dui. Morbi congue ligula in placerat pharetra. Duis gravida metus nec sagittis feugiat. Vestibulum pellentesque mattis metus, at eleifend leo hendrerit sed. Nam pretium leo dolor, vel facilisis leo mollis id. Cras eu laoreet ante. Pellentesque suscipit tortor a ex sodales, vitae posuere ligula tempor. Interdum et malesuada fames ac ante ipsum primis in faucibus. Duis at elit sit amet lectus feugiat finibus. Donec in arcu sit amet lacus imperdiet dapibus ut vehicula justo. Vestibulum at lectus lobortis, molestie nisl quis, hendrerit felis. Ut dapibus ornare ligula vel mattis. In id nulla nisl. Aenean tortor leo, sagittis sed ante in, varius vulputate est. Phasellus egestas nisi ut tortor vulputate mattis. Proin id nibh ultricies, vulputate ex sed, aliquet nibh. Praesent tincidunt massa et sapien vestibulum volutpat. Cras convallis ornare purus, ut accumsan tortor tincidunt eget. Curabitur hendrerit eros in turpis ultricies vestibulum. Aliquam dictum risus. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer posuere sapien sit amet rutrum mollis. Praesent non odio feugiat, placerat erat vel, ultrices metus. Curabitur eget ante vitae nisi vehicula accumsan. Ut eu dictum magna, sed ullamcorper metus. Quisque vehicula finibus dui, gravida tempus ante gravida eu. Etiam elementum turpis eget dui accumsan cursus. Aliquam sed cursus nulla. Duis suscipit nulla sed scelerisque commodo. Donec rutrum arcu dolor, in tempor odio ornare non. Ut finibus enim sit amet dictum rutrum. Aenean vitae placerat ex, non vehicula mauris. Quisque et faucibus dolor. Nunc lacus est, placerat sit amet nunc at, consectetur porta dui. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Nullam eget neque in arcu congue consectetur ac at diam. Proin porttitor sapien vel consequat efficitur. Morbi mauris mi, aliquet vitae porta sit amet, ultricies et urna. Sed porta, turpis dictum suscipit tincidunt, arcu massa vestibulum ante, ut ullamcorper justo nisi quis enim. Praesent tempor at lacus id molestie. Ut nec magna elit. Interdum et malesuada fames ac ante ipsum primis in faucibus. Ut lacinia vestibulum facilisis. Suspendisse quis sem ac diam iaculis lacinia in ut odio. Pellentesque tellus dolor, laoreet ut blandit venenatis, pulvinar sed turpis. Praesent et diam ut dui eleifend pulvinar. Ut eget nunc a orci aliquam eleifend. Donec fermentum vulputate metus eu ultrices. Nunc nec consectetur libero, non iaculis tortor. In feugiat rutrum laoreet. Duis in suscipit orci. Aliquam felis eros, porttitor tincidunt suscipit ac, commodo quis augue. Mauris aliquet mauris a nunc ullamcorper auctor at varius erat. Sed dapibus libero et arcu eleifend ornare nec quis magna. Aenean tincidunt felis efficitur, tincidunt risus quis, pharetra lacus. Pellentesque feugiat ornare lectus, accumsan scelerisque nisl accumsan in. Morbi felis nulla, volutpat sed pellentesque a, cursus ac quam. Sed dictum diam ut ligula dapibus, in scelerisque libero dignissim. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Interdum et malesuada fames ac ante ipsum primis in faucibus. Sed lacinia tortor ut tortor vestibulum aliquet. Quisque ipsum nunc, pretium sed porta in, semper ut dolor. Nullam tincidunt odio et vulputate convallis. Integer quis tincidunt nulla. Quisque at mauris vel augue convallis elementum pharetra vitae neque. Curabitur interdum turpis sed ex porta, id tincidunt neque varius. Interdum et malesuada fames ac ante ipsum primis in faucibus. Maecenas vel elit et dui convallis imperdiet. Pellentesque egestas ante magna, at ultrices quam aliquet sed. Donec vestibulum velit ac congue ultrices. Ut venenatis metus molestie consectetur elementum. Mauris vitae nibh eget felis tincidunt congue ut sed orci. Nunc tempor mollis quam id sodales. Mauris est nibh, ullamcorper ac condimentum a, gravida at augue. Maecenas lacinia odio porttitor est posuere porttitor. Vestibulum eu laoreet ante. Sed ut rhoncus diam. In hac habitasse platea dictumst. Mauris in tellus a nulla condimentum tristique. Cras venenatis consectetur nisl nec laoreet. Aenean quis orci facilisis, elementum leo nec, pulvinar enim. Nullam accumsan dui pulvinar turpis ultrices, iaculis porttitor sapien ornare. Mauris sem enim, finibus vitae rutrum ac, ullamcorper nec quam. Donec sed ipsum quis elit tempus dignissim. Sed eu dui magna. Donec ac blandit massa. Donec tempus consequat maximus. Sed lorem arcu, sollicitudin pulvinar auctor vel, eleifend quis mi. Lorem ipsum dolor sit amet, consectetur adipiscing elit. In sed lacus ligula. Nunc id mollis lorem. Aliquam erat volutpat. Nunc volutpat mauris non felis venenatis, at varius augue mollis. Etiam maximus magna mauris, id mollis eros semper ut. Cras maximus sem vitae venenatis sollicitudin. Nullam porttitor ac nisi sed molestie. Nulla aliquam nec magna eu convallis. Proin eget sapien vel erat pulvinar malesuada. Quisque laoreet mauris ipsum, fermentum porta nunc venenatis eu. Suspendisse potenti. Cras quis interdum diam. Integer eu lacus quis neque feugiat rhoncus. Vestibulum ac magna eleifend, fringilla ligula ac, tristique nibh. Mauris eros lorem, venenatis eu erat at, pulvinar consequat urna. Nulla sit amet enim tempus, fermentum justo non, lacinia arcu. Etiam at metus dapibus, vehicula neque eu, blandit odio. Duis odio augue, pharetra nec felis sed, blandit tincidunt metus. Nam eu ante nunc. Aenean mi diam, suscipit at ex quis, rhoncus ornare metus. Morbi dapibus vulputate enim nec tempus. Maecenas laoreet molestie risus sit amet gravida. In condimentum turpis augue, a scelerisque dolor aliquam nec. Sed eget ornare ante. Interdum et malesuada fames ac ante ipsum primis in faucibus. Vivamus eget blandit ipsum. Proin fringilla pharetra augue eget iaculis. Nullam pulvinar odio eget facilisis volutpat. Ut varius ullamcorper tristique. Nunc mattis leo quis elementum vehicula. Sed facilisis, magna vel dignissim pulvinar, purus nisi accumsan lacus, eu maximus massa nulla eget magna. Maecenas feugiat odio id massa mollis tristique. Nullam imperdiet mauris a magna vestibulum scelerisque. Fusce nisi mi, dictum at odio sed, ullamcorper volutpat lectus. Sed lobortis tincidunt dui, in cursus enim congue non. Ut euismod vel justo non dignissim. Mauris vitae ex vestibulum, lobortis nibh vitae, pellentesque urna. Phasellus gravida sagittis varius. Vivamus tempor ex eros, ac tincidunt nibh condimentum a. Vestibulum sed tortor ac orci semper dignissim in non velit. Praesent in fermentum leo. Nullam porttitor nisl augue, a euismod ante vulputate at. Maecenas quis felis massa. Nunc sagittis interdum turpis ut tempor. Praesent sed efficitur velit. Vestibulum gravida nulla lectus, pretium euismod turpis auctor ac. Vivamus nunc sem, blandit non enim sed, tristique sagittis urna. Cras sit amet nibh vitae ipsum luctus luctus. Cras consectetur dui nec sodales condimentum. Nam fringilla mi quis accumsan auctor. Integer ultricies euismod quam a accumsan. Praesent fermentum, magna sed ornare convallis, justo enim sollicitudin neque, in semper metus orci at nibh. Proin commodo fermentum eros, consectetur ornare velit ultrices porta. Mauris eu mattis arcu. Pellentesque eu orci rutrum, elementum eros non, vulputate lacus. Aenean sed vulputate lectus. Curabitur mollis aliquam ultrices. Proin sit amet nulla est. Etiam metus urna, gravida ac varius a, dapibus in purus. Donec iaculis diam id pellentesque vulputate. Sed tincidunt, sapien sed fermentum condimentum, justo mi sollicitudin neque, sit amet lacinia orci odio eget mi. Donec hendrerit convallis neque, at rutrum lectus elementum in. In hac habitasse platea dictumst. Nulla pretium enim sit amet faucibus convallis. Aliquam id luctus ex. Quisque quis auctor sem, vitae interdum elit. Nam blandit vehicula est nec interdum. Aenean id cursus mi. Nullam volutpat cursus neque, id commodo elit finibus non. Ut vitae sollicitudin nibh. Phasellus et mauris dapibus, venenatis odio ut, suscipit orci. Vestibulum tristique quam a tellus tempus consectetur. Morbi eu arcu dui. Morbi congue ligula in placerat pharetra. Duis gravida metus nec sagittis feugiat. Vestibulum pellentesque mattis metus, at eleifend leo hendrerit sed. Nam pretium leo dolor, vel facilisis leo mollis id. Cras eu laoreet ante. Pellentesque suscipit tortor a ex sodales, vitae posuere ligula tempor. Interdum et malesuada fames ac ante ipsum primis in faucibus. Duis at elit sit amet lectus feugiat finibus. Donec in arcu sit amet lacus imperdiet dapibus ut vehicula justo. Vestibulum at lectus lobortis, molestie nisl quis, hendrerit felis. Ut dapibus ornare ligula vel mattis. In id nulla nisl. Aenean tortor leo, sagittis sed ante in, varius vulputate est. Phasellus egestas nisi ut tortor vulputate mattis. Proin id nibh ultricies, vulputate ex sed, aliquet nibh. Praesent tincidunt massa et sapien vestibulum volutpat. Cras convallis ornare purus, ut accumsan tortor tincidunt eget. Curabitur hendrerit eros in turpis ultricies vestibulum. Aliquam dictum risus.";
	char *long_str1 = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum. Why do we use it? It is a long established fact that a reader will be distracted by the readable content of a page when looking at its layout. The point of using Lorem Ipsum is that it has a more-or-less normal distribution of letters, as opposed to using 'Content here, content here', making it look like readable English. Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites still in their infancy. Various versions have evolved over the years, sometimes by accident, sometimes on purpose (injected humour and the like). Where does it come from? Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 years old. Richard McClintock, a Latin professor at Hampden-Sydney College in Virginia, looked up one of the more obscure Latin words, consectetur, from a Lorem Ipsum passage, and going through the cites of the word in classical literature, discovered the undoubtable source. Lorem Ipsum comes from sections 1.10.32 and 1.10.33 of de Finibus Bonorum et Malorum (The Extremes of Good and Evil) by Cicero, written in 45 BC. This book is a treatise on the theory of ethics, very popular during the Renaissance. The first line of Lorem Ipsum, Lorem ipsum dolor sit amet.., comes from a line in section 1.10.32. The standard chunk of Lorem Ipsum used since the 1500s is reproduced below for those interested. Sections 1.10.32 and 1.10.33 from de Finibus Bonorum et Malorum by Cicero are also reproduced in their exact original form, accompanied by English versions from the 1914 translation by H. Rackham. Where can I get some? There are many variations of passages of Lorem Ipsum available, but the majority have suffered alteration in some form, by injected humour, or randomised words which don't look even slightly believable. If you are going to use a passage of Lorem Ipsum, you need to be sure there isn't anything embarrassing hidden in the middle of text. All the Lorem Ipsum generators on the Internet tend to repeat predefined chunks as necessary, making this the first true generator on the Internet. It uses a dictionary of over 200 Latin words, combined with a handful of model sentence structures, to generate Lorem Ipsum which looks reasonable. The generated Lorem Ipsum is therefore always free from repetition, injected humour, or non-characteristic words etc. Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum. Why do we use it? It is a long established fact that a reader will be distracted by the readable content of a page when looking at its layout. The point of using Lorem Ipsum is that it has a more-or-less normal distribution of letters, as opposed to using 'Content here, content here', making it look like readable English. Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites still in their infancy. Various versions have evolved over the years, sometimes by accident, sometimes on purpose (injected humour and the like). Where does it come from? Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 years old. Richard McClintock, a Latin professor at Hampden-Sydney College in Virginia, looked up one of the more obscure Latin words, consectetur, from a Lorem Ipsum passage, and going through the cites of the word in classical literature, discovered the undoubtable source. Lorem Ipsum comes from sections 1.10.32 and 1.10.33 of de Finibus Bonorum et Malorum (The Extremes of Good and Evil) by Cicero, written in 45 BC. This book is a treatise on the theory of ethics, very popular during the Renaissance. The first line of Lorem Ipsum, Lorem ipsum dolor sit amet.., comes from a line in section 1.10.32. The standard chunk of Lorem Ipsum used since the 1500s is reproduced below for those interested. Sections 1.10.32 and 1.10.33 from de Finibus Bonorum et Malorum by Cicero are also reproduced in their exact original form, accompanied by English versions from the 1914 translation by H. Rackham. Where can I get some? There are many variations of passages of Lorem Ipsum available, but the majority have suffered alteration in some form, by injected humour, or randomised words which don't look even slightly believable. If you are going to use a passage of Lorem Ipsum, you need to be sure there isn't anything embarrassing hidden in the middle of text. All the Lorem Ipsum generators on the Internet tend to repeat predefined chunks as necessary, making this the first true generator on the Internet. It uses a dictionary of over 200 Latin words, combined with a handful of model sentence structures, to generate Lorem Ipsum which looks reasonable. The generated Lorem Ipsum is therefore always free from repetition, injected humour, or non-characteristic words etc. Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum. Why do we use it? It is a long established fact that a reader will be distracted by the readable content of a page when looking at its layout. The point of using Lorem Ipsum is that it has a more-or-less normal distribution of letters, as opposed to using 'Content here, content here', making it look like readable English. Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites still in their infancy. Various versions have evolved over the years, sometimes by accident, sometimes on purpose (injected humour and the like). Where does it come from? Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 years old. Richard McClintock, a Latin professor at Hampden-Sydney College in Virginia, looked up one of the more obscure Latin words, consectetur, from a Lorem Ipsum passage, and going through the cites of the word in classical literature, discovered the undoubtable source. Lorem Ipsum comes from sections 1.10.32 and 1.10.33 of de Finibus Bonorum et Malorum (The Extremes of Good and Evil) by Cicero, written in 45 BC. This book is a treatise on the theory of ethics, very popular during the Renaissance. The first line of Lorem Ipsum, Lorem ipsum dolor sit amet.., comes from a line in section 1.10.32. The standard chunk of Lorem Ipsum used since the 1500s is reproduced below for those interested. Sections 1.10.32 and 1.10.33 from de Finibus Bonorum et Malorum by Cicero are also reproduced in their exact original form, accompanied by English versions from the 1914 translation by H. Rackham. Where can I get some? There are many variations of passages of Lorem Ipsum available, but the majority have suffered alteration in some form, by injected humour, or randomised words which don't look even slightly believable. If you are going to use a passage of Lorem Ipsum, you need to be sure there isn't anything embarrassing hidden in the middle of text. All the Lorem Ipsum generators on the Internet tend to repeat predefined chunks as necessary, making this the first true generator on the Internet. It uses a dictionary of over 200 Latin words, combined with a handful of model sentence structures, to generate Lorem Ipsum which looks reasonable. The generated Lorem Ipsum is therefore always free from repetition, injected humour, or non-characteristic words etc. Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum. Why do we use it? It is a long established fact that a reader will be distracted by the readable content of a page when looking at its layout. The point of using Lorem Ipsum is that it has a more-or-less normal distribution of letters, as opposed to using 'Content here, content here', making it look like readable English. Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites still in their infancy. Various versions have evolved over the years, sometimes by accident, sometimes on purpose (injected humour and the like). Where does it come from? Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 years old. Richard McClintock, a Latin professor at Hampden-Sydney College in Virginia, looked up one of the more obscure Latin words, consectetur, from a Lorem Ipsum passage, and going through the cites of the word in classical literature, discovered the undoubtable source. Lorem Ipsum comes from sections 1.10.32 and 1.10.33 of de Finibus Bonorum et Malorum (The Extremes of Good and Evil) by Cicero, written in 45 BC. This book is a treatise on the theory of ethics, very popular during the Renaissance. The first line of Lorem Ipsum, Lorem ipsum dolor sit amet.., comes from a line in section 1.10.32. The standard chunk of Lorem Ipsum used since the 1500s is reproduced below for those interested. Sections 1.10.32 and 1.10.33 from de Finibus Bonorum et Malorum by Cicero are also reproduced in their exact original form, accompanied by English versions from the 1914 translation by H. Rackham. Where can I get some? There are many variations of passages of Lorem Ipsum available, but the majority have suffered alteration in some form, by injected humour, or randomised words which don't look even slightly believable. If you are going to use a passage of Lorem Ipsum, you need to be sure there isn't anything embarrassing hidden in the middle of text. All the Lorem Ipsum generators on the Internet tend to repeat predefined chunks as necessary, making this the first true generator on the Internet. It uses a dictionary of over 200 Latin words, combined with a handful of model sentence structures, to generate Lorem Ipsum which looks reasonable. The generated Lorem Ipsum is therefore always free from repetition, injected humour, or non-characteristic words etc. Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum. Why do we use it? It is a long established fact that a reader will be distracted by the readable content of a page when looking at its layout. The point of using Lorem Ipsum is that it has a more-or-less normal distribution of letters, as opposed to using 'Content here, content here', making it look like readable English. Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites still in their infancy. Various versions have evolved over the years, sometimes by accident, sometimes on purpose (injected humour and the like). Where does it come from? Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 years old. Richard McClintock, a Latin professor at Hampden-Sydney College in Virginia, looked up one of the more obscure Latin words, consectetur, from a Lorem Ipsum passage, and going through the cites of the word in classical literature, discovered the undoubtable source. Lorem Ipsum comes from sections 1.10.32 and 1.10.33 of de Finibus Bonorum et Malorum (The Extremes of Good and Evil) by Cicero, written in 45 BC. This book is a treatise on the theory of ethics, very popular during the Renaissance. The first line of Lorem Ipsum, Lorem ipsum dolor sit amet.., comes from a line in section 1.10.32. The standard chunk of Lorem Ipsum used since the 1500s is reproduced below for those interested. Sections 1.10.32 and 1.10.33 from de Finibus Bonorum et Malorum by Cicero are also reproduced in their exact original form, accompanied by English versions from the 1914 translation by H. Rackham. Where can I get some? There are many variations of passages of Lorem Ipsum available, but the majority have suffered alteration in some form, by injected humour, or randomised words which don't look even slightly believable. If you are going to use a passage of Lorem Ipsum, you need to be sure there isn't anything embarrassing hidden in the middle of text. All the Lorem Ipsum generators on the Internet tend to repeat predefined chunks as necessary, making this the first true generator on the Internet. It uses a dictionary of over 200 Latin words, combined with a handful of model sentence structures, to generate Lorem Ipsum which looks reasonable. The generated Lorem Ipsum is therefore always free from repetition, injected humour, or non-characteristic words etc. Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum. Why do we use it? It is a long established fact that a reader will be distracted by the readable content of a page when looking at its layout. The point of using Lorem Ipsum is that it has a more-or-less normal distribution of letters, as opposed to using 'Content here, content here', making it look like readable English. Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites still in their infancy. Various versions have evolved over the years, sometimes by accident, sometimes on purpose (injected humour and the like). Where does it come from? Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 years old. Richard McClintock, a Latin professor at Hampden-Sydney College in Virginia, looked up one of the more obscure Latin words, consectetur, from a Lorem Ipsum passage, and going through the cites of the word in classical literature, discovered the undoubtable source. Lorem Ipsum comes from sections 1.10.32 and 1.10.33 of de Finibus Bonorum et Malorum (The Extremes of Good and Evil) by Cicero, written in 45 BC. This book is a treatise on the theory of ethics, very popular during the Renaissance. The first line of Lorem Ipsum, Lorem ipsum dolor sit amet.., comes from a line in section 1.10.32. The standard chunk of Lorem Ipsum used since the 1500s is reproduced below for those interested. Sections 1.10.32 and 1.10.33 from de Finibus Bonorum et Malorum by Cicero are also reproduced in their exact original form, accompanied by English versions from the 1914 translation by H. Rackham. Where can I get some? There are many variations of passages of Lorem Ipsum available, but the majority have suffered alteration in some form, by injected humour, or randomised words which don't look even slightly believable. If you are going to use a passage of Lorem Ipsum, you need to be sure there isn't anything embarrassing hidden in the middle of text. All the Lorem Ipsum generators on the Internet tend to repeat predefined chunks as necessary, making this the first true generator on the Internet. It uses a dictionary of over 200 Latin words, combined with a handful of model sentence structures, to generate Lorem Ipsum which looks reasonable. The generated Lorem Ipsum is therefore always free from repetition, injected humour, or non-characteristic words etc.";

	cantidad_pruebas = 100;
	srand(time(NULL));

	if (argc == 1 || !strcmp(argv[1], "1"))
	{
		printf("\n\U00002B50------Pruebas Atoi------\U00002B50\n");
		i = 0;
		while (i++ < cantidad_pruebas)
		{
			// 20 es la longitud maxima de str
			ft_generate_atoi(&str, 20);
			ft_check_int(ft_atoi(str), atoi(str), "atoi", i);
			free(str);
		}
		ft_check_int(ft_atoi("2147483647"), atoi("2147483647"), "atoi", i);
		i++;
		ft_check_int(ft_atoi("-2147483648"), atoi("-2147483648"), "atoi", i);
		i++;
		ft_check_int(ft_atoi("-2147483648323"), atoi("-2147483648323"), "atoi", i);
		i++;
		ft_check_int(ft_atoi("2147483648323"), atoi("2147483648323"), "atoi", i);
		i++;
		ft_check_int(ft_atoi("  -0"), atoi("  -0"), "atoi", i);
		i++;
		ft_check_int(ft_atoi(""), atoi(""), "atoi", i);
		i++;
		ft_check_int(ft_atoi("   "), atoi("   "), "atoi", i);
		i++;
		ft_check_int(ft_atoi("0000123"), atoi("0000123"), "atoi", i);
		i++;
		ft_check_int(ft_atoi("123\n456"), atoi("123\n456"), "atoi", i);

		// Prueba de rendimiento atoi
		i = 0;
		cpu_time_used_ft = 0;
		cpu_time_used = 0;
		while (i++ < 200000)
		{
			// 20 es la longitud maxima de str
			ft_generate_atoi(&str, 20);
			start = clock();
			ft_atoi(str);
			end = clock();
			cpu_time_used_ft += ((double)(end - start)) / CLOCKS_PER_SEC;
			start = clock();
			atoi(str);
			end = clock();
			cpu_time_used += ((double)(end - start)) / CLOCKS_PER_SEC;
			free(str);
		}
		printf("\n\U0001F3C1 Rendimiento 200000 operaciones ft_atoi:%fs 	original:%fs \U0001F3C1\n", cpu_time_used_ft, cpu_time_used);
	}

	if (argc == 1 || !strcmp(argv[1], "2"))
	{
		struct {
			int a;
			double b;
			char c[8];
		} my_struct = {1234, 56.78, "HELLO"};
		struct {
			int a;
			double b;
			char c[8];
		} my_struct1 = {1234, 56.78, "HELLO"};
		unsigned char buffer_special_1_1[] = {0xFF, 0xAA, 0x55, 0x00, 0x11};
		unsigned char buffer_special_1_2[] = {0xFF, 0xAA, 0x55, 0x00, 0x11};
		printf("\n\U00002B50------Pruebas Bzero------\U00002B50\n");
		i = 0;
		while (i++ < 5)
		{
			random = rand() % 10 + 1;
			// 20 es la longitud de str
			ft_generate_bzero(&str, 20);
			ft_generate_bzero(&str1, 20);
			ft_bzero(str, random);
			bzero(str1, random);
			ft_check_str(str, str1, "bzero", i);
			ft_check_size(str, str1, "bzero", i);
			ft_check_buffer(str, str1, random, "bzero", i, 1);
			free(str);
			free(str1);
		}
		buff = strdup("123456789");
		buff1 = strdup("123456789");
		ft_bzero(buff, 0);
		bzero(buff1, 0);
		ft_check_str(buff, buff1, "bzero", i);
		ft_check_size(buff, buff1, "bzero", i);
		ft_check_buffer(buff, buff1, 9, "bzero", i, 1);
		i ++;
		ft_bzero(buff, 6);
		bzero(buff1, 6);
		ft_check_str(buff, buff1, "bzero", i);
		ft_check_size(buff, buff1, "bzero", i);
		ft_check_buffer(buff, buff1, 9, "bzero", i, 1);
		i++;
		ft_bzero(buff, 9);
		bzero(buff1, 9);
		ft_check_str(buff, buff1, "bzero", i);
		ft_check_size(buff, buff1, "bzero", i);
		ft_check_buffer(buff, buff1, 9, "bzero", i, 1);
		free(buff);
		free(buff1);
		i ++;
		ft_bzero(buffer_special_1_1, sizeof(buffer_special_1_1));
		bzero(buffer_special_1_2, sizeof(buffer_special_1_2));
		ft_check_size(buffer_special_1_1, buffer_special_1_2, "bzero", i);
		ft_check_buffer(buffer_special_1_1, buffer_special_1_2, sizeof(buffer_special_1_2), "bzero", i, 1);
		i ++;
		ft_bzero(&my_struct, sizeof(my_struct));
		bzero(&my_struct1, sizeof(my_struct1));
		ft_check_size(&my_struct, &my_struct1, "bzero", i);
		ft_check_buffer(&my_struct, &my_struct1, sizeof(my_struct), "bzero", i, 1);

		
		// Prueba de rendimiento bzero
		i = 0;
		cpu_time_used_ft = 0;
		cpu_time_used = 0;
		while (i++ < 200000)
		{
			random = rand() % 10 + 1;
			// 20 es la longitud de str
			ft_generate_bzero(&str, 20);
			ft_generate_bzero(&str1, 20);
			start = clock();
			ft_bzero(str, random);
			end = clock();
			cpu_time_used_ft += ((double)(end - start)) / CLOCKS_PER_SEC;
			start = clock();
			bzero(str1, random);
			end = clock();
			cpu_time_used += ((double)(end - start)) / CLOCKS_PER_SEC;
			free(str);
			free(str1);
		}
		printf("\n\U0001F3C1 Rendimiento 200000 operaciones ft_bzero:%fs 	original:%fs \U0001F3C1\n", cpu_time_used_ft, cpu_time_used);
	}

	if (argc == 1 || !strcmp(argv[1], "3"))
	{
		printf("\n\U00002B50------Pruebas Calloc------\U00002B50\n");
		i = 0;
		while (i++ < 5)
		{
			random = rand() % 100 + 1;
			random1 = rand() % 100 + 1;
			str = (char *)ft_calloc(random, random1);
			str1 = (char *)calloc(random, random1);
			ft_check_str(str, str1, "calloc", i);
			ft_check_size(str, str1, "calloc", i);
			ft_check_buffer(str, str1, (random * random1), "calloc", i, 0);
			free(str);
			free(str1);
		}
		str = (char *)ft_calloc(2, 3);
		str1 = (char *)calloc(2, 3);
		ft_check_str(str, str1, "calloc", i);
		ft_check_size(str, str1, "calloc", i);
		ft_check_buffer(str, str1, (2 * 3), "calloc", i, 1);
		free(str);
		free(str1);
		i ++;
		ptr = ft_calloc(1, sizeof(int));
		ptr1 = calloc(1, sizeof(int));
		ft_check_int(*ptr, *ptr1, "calloc", i);
		ft_check_buffer(ptr, ptr1, 1, "calloc", i, 1);
		free(ptr);
		free(ptr1);
		i ++;
		ptr = ft_calloc(5, sizeof(int));
		ptr1 = calloc(5, sizeof(int));
		ft_check_buffer(ptr, ptr1, 5, "calloc", i, 1);
		free(ptr);
		free(ptr1);
		i ++;
		struct Data {
			int a;
			float b;
			unsigned char c;
		};
		struct Data *ptr_struct1 = calloc(3, sizeof(struct Data));
		ptr_struct1->c = 48;
		struct Data *ptr_struct2 = calloc(3, sizeof(struct Data));
		ptr_struct2->c = 48;
		ft_check_buffer(ptr_struct1, ptr_struct2, sizeof(ptr_struct2) + 1, "calloc", i, 1);


		// Prueba de rendimiento calloc
		i = 0;
		cpu_time_used_ft = 0;
		cpu_time_used = 0;
		while (i ++ < 200000)
		{
			random = rand () % 100;
			random1 = rand () % 100;
			start = clock();
			str = (char *)ft_calloc(random, random1);
			end = clock();
			cpu_time_used_ft += ((double)(end - start)) / CLOCKS_PER_SEC;
			start = clock();
			str1 = (char *)calloc(random, random1);
			end = clock();
			cpu_time_used += ((double)(end - start)) / CLOCKS_PER_SEC;
			free(str);
			free(str1);
		}
		printf ("\n\U0001F3C1 Rendimiento 200000 operaciones ft_calloc:%fs 	original:%fs \U0001F3C1\n", cpu_time_used_ft, cpu_time_used);
	}

	if (argc == 1 || !strcmp(argv[1], "4"))
	{
		printf("\n\U00002B50------Pruebas IsAlNum------\U00002B50\n");
		i = 0;
		while (i++ < cantidad_pruebas)
		{
			random = rand() % 128;
			ft_check_is(ft_isalnum(random), isalnum(random), "isalnum", i, random);
		}
		ft_check_is(ft_isalnum(-47), isalnum(-47), "isalnum", i, -47);
		i++;
		ft_check_is(ft_isalnum(47), isalnum(47), "isalnum", i, 47);
		i++;
		ft_check_is(ft_isalnum(48), isalnum(48), "isalnum", i, 48);
		i++;
		ft_check_is(ft_isalnum(57), isalnum(57), "isalnum", i, 57);
		i++;
		ft_check_is(ft_isalnum(58), isalnum(58), "isalnum", i, 58);
		i++;
		ft_check_is(ft_isalnum(64), isalnum(64), "isalnum", i, 64);
		i++;
		ft_check_is(ft_isalnum(65), isalnum(65), "isalnum", i, 65);
		i++;
		ft_check_is(ft_isalnum(90), isalnum(90), "isalnum", i, 90);
		i++;
		ft_check_is(ft_isalnum(91), isalnum(91), "isalnum", i, 91);
		i++;
		ft_check_is(ft_isalnum(96), isalnum(96), "isalnum", i, 96);
		i++;
		ft_check_is(ft_isalnum(97), isalnum(97), "isalnum", i, 97);
		i++;
		ft_check_is(ft_isalnum(122), isalnum(122), "isalnum", i, 122);
		i++;
		ft_check_is(ft_isalnum(123), isalnum(123), "isalnum", i, 123);
		i++;
		ft_check_is(ft_isalnum(0), isalnum(0), "isalnum", i, 0);
		i++;
		ft_check_is(ft_isalnum(127), isalnum(127), "isalnum", i, 127);
	
		// Prueba de rendimiento isalnum
		i = 0;
		cpu_time_used_ft = 0;
		cpu_time_used = 0;
		while (i++ < 200000)
		{
			random = rand() % 127;
			start = clock();
			aux = ft_isalnum(random);
			end = clock();
			cpu_time_used_ft += ((double)(end - start)) / CLOCKS_PER_SEC;
			start = clock();
			aux = isalnum(random);
			end = clock();
			cpu_time_used += ((double)(end - start)) / CLOCKS_PER_SEC;
		}
		printf("\n\U0001F3C1 Rendimiento 200000 operaciones ft_isalnum:%fs 	original:%fs \U0001F3C1\n", cpu_time_used_ft, cpu_time_used);
	}

	if (argc == 1 || !strcmp(argv[1], "5"))
	{
		printf("\n\U00002B50------Pruebas IsAlpha------\U00002B50\n");
		i = 0;
		while (i++ < cantidad_pruebas)
		{
			random = rand() % 128;
			ft_check_is(ft_isalpha(random), isalpha(random), "isalpha", i, random);
		}
		ft_check_is(ft_isalpha(-64), isalpha(-64), "isalpha", i, -64);
		i++;
		ft_check_is(ft_isalpha(64), isalpha(64), "isalpha", i, 64);
		i++;
		ft_check_is(ft_isalpha(65), isalpha(65), "isalpha", i, 65);
		i++;
		ft_check_is(ft_isalpha(90), isalpha(90), "isalpha", i, 90);
		i++;
		ft_check_is(ft_isalpha(91), isalpha(91), "isalpha", i, 91);
		i++;
		ft_check_is(ft_isalpha(96), isalpha(96), "isalpha", i, 96);
		i++;
		ft_check_is(ft_isalpha(97), isalpha(97), "isalpha", i, 97);
		i++;
		ft_check_is(ft_isalpha(122), isalpha(122), "isalpha", i, 122);
		i++;
		ft_check_is(ft_isalpha(123), isalpha(123), "isalpha", i, 123);
		i++;
		ft_check_is(ft_isalpha('!'), isalpha('!'), "isalpha", i, '!');
		i++;
		ft_check_is(ft_isalpha('\t'), isalpha('\t'), "isalpha", i, '\t');
	
		// Prueba de rendimiento isalpha
		i = 0;
		cpu_time_used_ft = 0;
		cpu_time_used = 0;
		while (i++ < 200000)
		{
			random = rand() % 127;
			start = clock();
			aux = ft_isalpha(random);
			end = clock();
			cpu_time_used_ft += ((double)(end - start)) / CLOCKS_PER_SEC;
			start = clock();
			aux = isalpha(random);
			end = clock();
			cpu_time_used += ((double)(end - start)) / CLOCKS_PER_SEC;
		}
		printf("\n\U0001F3C1 Rendimiento 200000 operaciones ft_isalpha:%fs 	original:%fs \U0001F3C1\n", cpu_time_used_ft, cpu_time_used);
	}
	
	if (argc == 1 || !strcmp(argv[1], "6"))
	{
		printf("\n\U00002B50------Pruebas IsAcii------\U00002B50\n");
		i = 0;
		while (i++ < cantidad_pruebas)
		{
			random = rand() % 256;
			ft_check_is(ft_isascii(random), __isascii(random), "isacii", i, random);
		}
		ft_check_is(ft_isascii(-10), __isascii(-10), "isacii", i, -10);
		i++;
		ft_check_is(ft_isascii(-1), __isascii(-1), "isacii", i, -1);
		i++;
		ft_check_is(ft_isascii(0), __isascii(0), "isacii", i, 0);
		i++;
		ft_check_is(ft_isascii(31), __isascii(31), "isacii", i, 31);
		i++;
		ft_check_is(ft_isascii(32), __isascii(32), "isacii", i, 32);
		i++;
		ft_check_is(ft_isascii(127), __isascii(127), "isacii", i, 127);
		i++;
		ft_check_is(ft_isascii(128), __isascii(128), "isacii", i, 128);
		i++;
	
		// Prueba de rendimiento isascii
		i = 0;
		cpu_time_used_ft = 0;
		cpu_time_used = 0;
		while (i++ < 200000)
		{
			random = rand() % 256;
			start = clock();
			aux = ft_isascii(random);
			end = clock();
			cpu_time_used_ft += ((double)(end - start)) / CLOCKS_PER_SEC;
			start = clock();
			aux = __isascii(random);
			end = clock();
			cpu_time_used += ((double)(end - start)) / CLOCKS_PER_SEC;
		}
		printf("\n\U0001F3C1 Rendimiento 200000 operaciones ft_isascii:%fs 	original:%fs \U0001F3C1\n", cpu_time_used_ft, cpu_time_used);
	}

	if (argc == 1 || !strcmp(argv[1], "7"))
	{
		printf("\n\U00002B50------Pruebas IsDigit-----\U00002B50\n");
		i = 0;
		while (i++ < cantidad_pruebas)
		{
			random = rand() % 128;
			ft_check_is(ft_isdigit(random), isdigit(random), "isdigit", i, random);
		}
		ft_check_is(ft_isdigit(-20), isdigit(-20), "isdigit", i, -20);
		i++;
		ft_check_is(ft_isdigit(47), isdigit(47), "isdigit", i, 47);
		i++;
		ft_check_is(ft_isdigit(48), isdigit(48), "isdigit", i, 48);
		i++;
		ft_check_is(ft_isdigit(57), isdigit(57), "isdigit", i, 57);
		i++;
		ft_check_is(ft_isdigit(58), isdigit(58), "isdigit", i, 58);
	
		// Prueba de rendimiento isdigit
		i = 0;
		cpu_time_used_ft = 0;
		cpu_time_used = 0;
		while (i++ < 200000)
		{
			random = rand() % 128;
			start = clock();
			aux = ft_isdigit(random);
			end = clock();
			cpu_time_used_ft += ((double)(end - start)) / CLOCKS_PER_SEC;
			start = clock();
			aux = isdigit(random);
			end = clock();
			cpu_time_used += ((double)(end - start)) / CLOCKS_PER_SEC;
		}
		printf("\n\U0001F3C1 Rendimiento 200000 operaciones ft_isdigit:%fs 	original:%fs \U0001F3C1\n", cpu_time_used_ft, cpu_time_used);
	}

	if (argc == 1 || !strcmp(argv[1], "8"))
	{
		printf("\n\U00002B50------Pruebas IsPrint-----\U00002B50\n");
		i = 0;
		while (i++ < cantidad_pruebas)
		{
			random = rand() % 256;
			ft_check_is(ft_isprint(random), isprint(random), "isprint", i, random);
		}
		ft_check_is(ft_isprint(-20), isprint(-20), "isprint", i, -20);
		i++;
		ft_check_is(ft_isprint(0), isprint(0), "isprint", i, 0);
		i++;
		ft_check_is(ft_isprint(31), isprint(31), "isprint", i, 31);
		i++;
		ft_check_is(ft_isprint(32), isprint(32), "isprint", i, 32);
		i++;
		ft_check_is(ft_isprint(126), isprint(126), "isprint", i, 126);
		i++;
		ft_check_is(ft_isprint(127), isprint(127), "isprint", i, 127);
	
		// Prueba de rendimiento isprint
		i = 0;
		cpu_time_used_ft = 0;
		cpu_time_used = 0;
		while (i++ < 200000)
		{
			random = rand() % 256;
			start = clock();
			aux = ft_isprint(random);
			end = clock();
			cpu_time_used_ft += ((double)(end - start)) / CLOCKS_PER_SEC;
			start = clock();
			aux = isprint(random);
			end = clock();
			cpu_time_used += ((double)(end - start)) / CLOCKS_PER_SEC;
		}
		printf("\n\U0001F3C1 Rendimiento 200000 operaciones ft_isprint:%fs 	original:%fs \U0001F3C1\n", cpu_time_used_ft, cpu_time_used);
	}

	if (argc == 1 || !strcmp(argv[1], "9"))
	{
		printf("\n\U00002B50------Pruebas Strlen-----\U00002B50\n");
		i = 0;
		while (i++ < cantidad_pruebas)
		{
			// 20 es la longitud maxima de str
			ft_generate_string(&str, 20, 1);
			ft_check_int(ft_strlen(str), strlen(str), "strlen", i);
			free(str);
		}
		ft_check_int(ft_strlen(""), strlen(""), "strlen", i);
		i++;
		ft_check_int(ft_strlen("Hola mundo"), strlen("Hola mundo"), "strlen", i);
		i++;
		ft_check_int(ft_strlen("Hola\nmundo"), strlen("Hola\nmundo"), "strlen", i);
		i++;
		ft_check_int(ft_strlen("¡¿Hola?!"), strlen("¡¿Hola?!"), "strlen", i);
		i++;
		ft_check_int(ft_strlen(long_str), strlen(long_str), "strlen", i);
	
		// Prueba de rendimiento strlen
		i = 0;
		cpu_time_used_ft = 0;
		cpu_time_used = 0;
		while (i++ < 200000)
		{
			ft_generate_string(&str, 20, 1);
			start = clock();
			aux = ft_strlen(str);
			end = clock();
			cpu_time_used_ft += ((double)(end - start)) / CLOCKS_PER_SEC;
			start = clock();
			aux = strlen(str);
			end = clock();
			cpu_time_used += ((double)(end - start)) / CLOCKS_PER_SEC;
			free(str);
		}
		start = clock();
		aux = ft_strlen(long_str);
		end = clock();
		cpu_time_used_ft += ((double)(end - start)) / CLOCKS_PER_SEC;
		start = clock();
		aux = strlen(long_str);
		end = clock();
		cpu_time_used += ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("\n\U0001F3C1 Rendimiento 200000 operaciones ft_strlen:%fs 	original:%fs \U0001F3C1\n", cpu_time_used_ft, cpu_time_used);
	}

	if (argc == 1 || !strcmp(argv[1], "10"))
	{
		struct {
			int a;
			double b;
			char c[8];
		} my_struct = {1234, 56.78, "HELLO"};
		struct {
			int a;
			double b;
			char c[8];
		} my_struct1 = {1234, 56.78, "HELLO"};
		unsigned char buffer_special_1_1[] = {0xFF, 0xAA, 0x55, 0x00, 0x11};
		unsigned char buffer_special_1_2[] = {0xFF, 0xAA, 0x55, 0x00, 0x11};
		printf("\n\U00002B50------Pruebas Memset-----\U00002B50\n");
		i = 0;
		while (i++ < cantidad_pruebas)
		{
			random = rand() % 94 + 32;
			random1 = rand() % 20;
	
			str = calloc(25, 1);
			if (!str)
				return (1);
			str1 = calloc(25, 1);
			if (!str1)
				return (1);
			ft_memset(str, random, random1);
			memset(str1, random, random1);
			ft_check_str((char *)str, (char *)str1, "memset", i);
			ft_check_buffer((char *)str, (char *)str1, random1, "memset", i, 0);
			free(str);
			free(str1);
		}
		str = calloc(25, 1);
		if (!str)
			return (1);
		str1 = calloc(25, 1);
		if (!str1)
			return (1);
		ft_memset(str, 48, 10);
		memset(str1, 48, 10);
		ft_check_str((char *)str, (char *)str1, "memset", i);
		ft_check_buffer((char *)str, (char *)str1, 20, "memset", i, 1);
		ft_memset(str, 0, 20);
		memset(str1, 0, 20);
		ft_check_str((char *)str, (char *)str1, "memset", i);
		ft_check_buffer((char *)str, (char *)str1, 20, "memset", i, 1);
		i++;
		ft_memset(str, 20, 5);
		memset(str1, 20, 5);
		ft_memset(str, 20, 0);
		memset(str1, 20, 0);
		ft_check_str((char *)str, (char *)str1, "memset", i);
		ft_check_buffer((char *)str, (char *)str1, 5, "memset", i, 1);
		free(str);
		free(str1);
		i++;
		ft_memset(&my_struct, 56, sizeof(my_struct));
		memset(&my_struct1, 56, sizeof(my_struct1));
		ft_check_buffer(&my_struct, &my_struct1, sizeof(my_struct1), "memset", i, 1);
		i ++;
		ft_memset(buffer_special_1_1, 9, sizeof(buffer_special_1_1));
		memset(buffer_special_1_2, 9, sizeof(buffer_special_1_2));
		ft_check_buffer(buffer_special_1_1, buffer_special_1_2, sizeof(buffer_special_1_2), "memset", i, 1);

	
		// Prueba de rendimiento memset
		i = 0;
		cpu_time_used_ft = 0;
		cpu_time_used = 0;
		str = calloc(22, 1);
		if (!str)
			return (1);
		str1 = calloc(22, 1);
		if (!str1)
			return (1);
		while (i++ < 200000)
		{
			random = rand() % 94 + 32;
			random1 = rand() % 20;
			start = clock();
			ft_memset(str, random, random1);
			end = clock();
			cpu_time_used_ft += ((double)(end - start)) / CLOCKS_PER_SEC;
			start = clock();
			memset(str1, random, random1);
			end = clock();
			cpu_time_used += ((double)(end - start)) / CLOCKS_PER_SEC;
		}
		free(str);
		free(str1);
		printf("\n\U0001F3C1 Rendimiento 200000 operaciones ft_memset:%fs 	original:%fs \U0001F3C1\n", cpu_time_used_ft, cpu_time_used);
	}

	if (argc == 1 || !strcmp(argv[1], "11"))
	{
		struct Data {
			int a;
			double b;
			char c;
		} my_struct = {42, 3.14, 'X'}, my_struct1, my_struct2;
		printf("\n\U00002B50------Pruebas Memcpy-----\U00002B50\n");
		i = 0;
		while (i++ < cantidad_pruebas)
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
			ft_check_str((char *)str1, (char *)str2, "memcpy", i);
			free(str);
			free(str1);
			free(str2);
		}
		str1 = calloc(30, 1);
		str2 = calloc(30, 1);
		if (!str1 || !str2)
			return (1);
		ft_check_str(ft_memcpy(str1, "Fran", 0), memcpy(str2, "Fran", 0), "memcpy", i);
		ft_check_buffer(str1, str2, 5, "memcpy", i, 1);
		i++;
		ft_check_str(ft_memcpy(str1, "Fran", 4), memcpy(str2, "Fran", 4), "memcpy", i);
		ft_check_buffer(str1, str2, 5, "memcpy", i, 1);
		i++;
		ft_check_str(ft_memcpy(str1, "Hola mundo", 6), memcpy(str2, "Hola mundo", 6), "memcpy", i);
		ft_check_buffer(str1, str2, 10, "memcpy", i, 1);
		i++;
		ft_check_str(ft_memcpy(str1 + 5, "Hola mundo", 6), memcpy(str2 + 5, "Hola mundo", 6), "memcpy", i);
		ft_check_buffer(str1, str2, 15, "memcpy", i, 1);
		i++;
		free(str1);
		free(str2);
		ft_memcpy(&my_struct1, &my_struct, sizeof(my_struct));
		memcpy(&my_struct2, &my_struct, sizeof(my_struct));
		ft_check_buffer(&my_struct1, &my_struct2, sizeof(my_struct), "memcpy", i, 1);
		
		// Prueba de rendimiento memcpy
		i = 0;
		cpu_time_used_ft = 0;
		cpu_time_used = 0;
		while (i++ < 200000)
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
			start = clock();
			ft_memcpy(str1, str, random1);
			end = clock();
			cpu_time_used_ft += ((double)(end - start)) / CLOCKS_PER_SEC;
			start = clock();
			memcpy(str2, str, random1);
			end = clock();
			cpu_time_used += ((double)(end - start)) / CLOCKS_PER_SEC;
			free(str);
			free(str1);
			free(str2);
		}
	
		printf("\n\U0001F3C1 Rendimiento 200000 operaciones ft_memcpy:%fs 	original:%fs \U0001F3C1\n", cpu_time_used_ft, cpu_time_used);
	}

	//Aqui casos especificicos.
	if (argc == 1 || !strcmp(argv[1], "12"))
	{
		int dest[] = {1, 2, 3, 4, 5, 6};
		int dest1[] = {1, 2, 3, 4, 5, 6};
		int src[] = {7, 8, 9};
		struct Data {
    		int a;
    		double b;
    		char c;
		} my_struct = {42, 3.14, 'X'}, my_struct1, my_struct2;
		printf("\n\U00002B50------Pruebas Memmove-----\U00002B50\n");
		i = 0;
		while (i++ < cantidad_pruebas)
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
			ft_memmove(str1, str, random1);
			memmove(str2, str, random1);
			ft_check_str((char *)str1, (char *)str2, "memmove", i);
			ft_check_buffer(str1, str2, strlen(str2), "memmove", i, 0);
			free(str);
			free(str1);
			free(str2);
		}
		str1 = calloc(30, 1);
		str2 = calloc(30, 1);
		if (!str1 || !str2)
			return (1);
		memset(str1, 'A', 5);
		memset(str2, 'A', 5);
		ft_check_str(ft_memmove(str1, "Fran", 0), memmove(str2, "Fran", 0), "memmove", i);
		ft_check_buffer(str1, str2, 30, "memmove", i, 1);
		i++;
		ft_check_str(ft_memmove(str1, "Francisco", 10), memmove(str2, "Francisco", 10), "memmove", i);
		ft_check_buffer(str1, str2, 30, "memmove", i, 1);
		i++;
		ft_check_str(ft_memmove(str1, "Hola", 5), memmove(str2, "Hola", 5), "memmove", i);
		ft_check_buffer(str1, str2, 30, "memmove", i, 1);
		i++;
		ft_check_buffer(ft_memmove(dest, src, 3), memmove(dest1, src, 3), 10, "memmove", i, 1);
		i++;
		ft_check_buffer(ft_memmove(&my_struct1, &my_struct, sizeof(my_struct)), memmove(&my_struct2, &my_struct, sizeof(my_struct)), sizeof(my_struct), "memmove", i, 1);
		free(str1);
		free(str2);
	
		// Prueba de rendimiento memmove
		i = 0;
		cpu_time_used_ft = 0;
		cpu_time_used = 0;
		while (i++ < 200000)
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
			start = clock();
			ft_memmove(str1, str, random1);
			end = clock();
			cpu_time_used_ft += ((double)(end - start)) / CLOCKS_PER_SEC;
			start = clock();
			memmove(str2, str, random1);
			end = clock();
			cpu_time_used += ((double)(end - start)) / CLOCKS_PER_SEC;
			free(str);
			free(str1);
			free(str2);
		}
	
		printf("\n\U0001F3C1 Rendimiento 200000 operaciones ft_memmove:%fs 	original:%fs \U0001F3C1\n", cpu_time_used_ft, cpu_time_used);
	}

	//Casos especificos

	if (argc == 1 || !strcmp(argv[1], "13"))
	{
		printf("\n\U00002B50------Pruebas Strlcpy-----\U00002B50\n");
		i = 0;
		while (i++ < cantidad_pruebas)
		{
			random = rand() % 40;
			random1 = rand() % 40;
			random2 = rand() % 40;
			str = calloc(80, 1);
			str2 = calloc(80, 1);
			if (!str || !str2)
				return (1);
			ft_generate_string_without_malloc(&str, random, 1);
			ft_generate_string(&str1, random1, 1);
			memcpy(str2, str1, strlen(str1));
			printf("\n");
			ft_check_int(ft_strlcpy(str1, str, random2), strlcpy(str2, str, random2), "strlcpy", i);
			ft_check_str((char *)str1, (char *)str2, "strlcpy", i);
			free(str);
			free(str1);
			free(str2);
		}


		// Prueba de rendimiento strlcpy
		i = 0;
		cpu_time_used_ft = 0;
		cpu_time_used = 0;
		while (i ++ < 200000)
		{
			random = rand() % 40;
			random1 = rand() % 40;
			random2 = rand() % 40;
			str = calloc(80, 1);
			str2 = calloc(80, 1);
			if (!str || !str2)
				return (1);
			ft_generate_string_without_malloc(&str, random, 1);
			ft_generate_string(&str1, random1, 1);
			memcpy(str2, str1, strlen(str1));		
			start = clock();
			ft_strlcpy(str1, str, random1);
			end = clock();
			cpu_time_used_ft += ((double)(end - start)) / CLOCKS_PER_SEC;
			start = clock();
			strlcpy(str2, str, random1);
			end = clock();
			cpu_time_used += ((double)(end - start)) / CLOCKS_PER_SEC;
			free(str);
			free(str1);
			free(str2);
		}
		printf ("\n\U0001F3C1 Rendimiento 200000 operaciones ft_strlcpy:%fs 	original:%fs \U0001F3C1\n", cpu_time_used_ft, cpu_time_used);
	}


	//Casos especificos
	if (argc == 1 || !strcmp(argv[1], "14"))
	{
		printf("\n\U00002B50------Pruebas Strlcat-----\U00002B50\n");
		i = 0;
		while (i++ < cantidad_pruebas)
		{
			random = rand() % 40;
			random1 = rand() % 40;
			random2 = rand() % 40;
			str1 = calloc(100, 1);
			str2 = calloc(100, 1);
			str = calloc (80, 1);
			if (!str1 || !str2 || !str)
				return (1);
			ft_generate_string_without_malloc(&str, random, 1);
			ft_generate_string_without_malloc(&str1, random2, 1);
			memcpy(str2, str1, strlen(str1));
			printf("\n");
			ft_check_int(ft_strlcat(str1, str, random1), strlcat(str2, str, random1), "strlcat", i);
			ft_check_str((char *)str1, (char *)str2, "strlcat", i);
			free(str);
			free(str1);
			free(str2);
		}


		// Prueba de rendimiento strlcat
		i = 0;
		cpu_time_used_ft = 0;
		cpu_time_used = 0;
		while (i ++ < 200000)
		{
			random = rand() % 40;
			random1 = rand() % 40;
			random2 = rand() % 40;
			str1 = calloc(100, 1);
			str2 = calloc(100, 1);
			str = calloc (80, 1);
			if (!str1 || !str2 || !str)
				return (1);
			ft_generate_string_without_malloc(&str, random, 1);
			ft_generate_string_without_malloc(&str1, random2, 1);
			memcpy(str2, str1, strlen(str1));		
			start = clock();
			ft_strlcat(str1, str, random1);
			end = clock();
			cpu_time_used_ft += ((double)(end - start)) / CLOCKS_PER_SEC;
			start = clock();
			strlcat(str2, str, random1);
			end = clock();
			cpu_time_used += ((double)(end - start)) / CLOCKS_PER_SEC;
			free(str);
			free(str1);
			free(str2);
		}
		printf ("\n\U0001F3C1 Rendimiento 200000 operaciones ft_strlcat:%fs 	original:%fs \U0001F3C1\n", cpu_time_used_ft, cpu_time_used);
	}
	/*if(!strcmp(argv[1], "errores"))
	{
		//Errores calloc 6 - 4
		str = (char *)ft_calloc(0, 0);
		str1 = (char *)calloc(0, 0);
		ft_check_str(str, str1, "calloc", i);
		i ++;
		free(str);
		free(str1);
		str = (char *)ft_calloc(2, 0);
		str1 = (char *)calloc(2, 0);
		ft_check_str(str, str1, "calloc", i);
		i ++;
		free(str);
		free(str1);
		str = (char *)ft_calloc(0, 4);
		str1 = (char *)calloc(0, 4);
		ft_check_str(str, str1, "calloc", i);
		i ++;
		free(str);
		free(str1);

	}*/



	

	/*while (i ++ < 100)
	{
		printf("%d \n", ft_generate_int());
	}*/

	/*if (strcmp(argv[1], "2") == 0)
		printf("--Bonus--\n");*/

	return (0);
}
