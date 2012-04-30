
#include <stdio.h>

main() {
  puts("hello there");
  puts("what is your name?");
  pause();
  puts("It is nice to meet you");
}

pause() {
  int move_on;
  printf("press enter to continue");
  move_on = getchar();
  return(0);
}