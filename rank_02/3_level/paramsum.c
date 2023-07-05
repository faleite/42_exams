#include <unistd.h>

int main(int ac, char **av) {

(void)av;
write(1, &"0123456789"[--ac], 1);
  return 0;
}
