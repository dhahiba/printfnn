#include "main.h"
#include <stdarg.h>


/**
 * _printf - ...
 * @format: ...
 * Return: ...
 */
int _printf(const char *format, ...)
{
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
					_putchar(va_arg(args, char));
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
}
