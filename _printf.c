#include <stdio.h>
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
char c;
char *s;

va_start(args, format);
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
switch (format[++i])
{
case 'c':
c = (char) va_arg(args, int);
putchar(c);
count++;
break;
case 's':
s = va_arg(args, char *);
while (*s)
{
putchar(*s);
s++;
count++; }
break;
case '%':
putchar('%');
count++;
break;
default:
putchar('%');
putchar(format[i]);
count += 2;
break; }}
else
{
putchar(format[i]);
count++; }}
va_end(args);
return (count); }
