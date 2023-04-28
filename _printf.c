#include "main.h"
#include <stdarg.h>
<<<<<<< HEAD
void print_buffer(char buffer[], int *buff_ind);
=======


>>>>>>> 16917705d18a07fec3547aa52a0718349dcc02db
/**
 * _printf - ...
 * @format: ...
 * Return: ...
 */
int _printf(const char *format, ...)
{
<<<<<<< HEAD
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - ...
 * @buffer: ...
 * @buff_ind: ...
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

*buff_ind = 0;
=======
	va_list args;
	int i, count = 0;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			switch (format[++i])
			{
				case 'c':
					_putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					count += puts(va_arg(args, char *));
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
>>>>>>> 16917705d18a07fec3547aa52a0718349dcc02db
}
