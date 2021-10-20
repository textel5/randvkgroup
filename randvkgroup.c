/*
    randvkgroup generates a html page of links to random vk groups
    Copyright (C) 2021 Sergey Tokarev
    
    randvkgroup is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VG_BUFF_SIZE 51
#define VG_GROUP_LIM_MAX 999999999

int vgHtmlOpen()
{
  return printf(
  "<!DOCTYPE html>\n"
  "<html>\n"
  "<head>\n"
  "<title>random vk groups list</title>\n"
  "</head>"
  "<body>\n");
}

int vgHtmlClose()
{
  return printf(
  "</body>\n"
  "</html>\n");
}

int vgCharToInt(char *str)
{
  int num, i;
  num = 0;
  for (i = 0; ; i++) {
    if (!str[i]) {
      break;
    }
    if (str[i] >= '0' && str[i] <= '9') {
      num *= 10;
      num += (str[i] - '0') % 10;
#ifdef DEBUG
      fprintf(stderr, "%d\n", num);
#endif
    } else {
      return 0;
    }
  }
  return num;
}

int main(int argc, char **argv)
{
  int i, count;
  if (argc < 2) {
    fprintf(stderr, "enter a quantity of groups\n");
    return 1;
  }
  vgHtmlOpen();
  srand(time(NULL));
  for (i = 0, count = vgCharToInt(argv[1]); i < count; i++) {
    unsigned int number;
    while ((number = rand()) > VG_GROUP_LIM_MAX)
      {}
    printf("<a href=\"http://vk.com/club%u\">%u</a>\n", number, number);
  }
  vgHtmlClose();
  return 0;
}