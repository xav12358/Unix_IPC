#include "header.h"

struct my_proc2_msg1 {
  long int msg_id;
  char msg_txt[BUFSIZ];
};

struct my_proc2_msg2 {
  long int msg_id;
  int payload0;
  int payload1;
};

int main() {
  struct my_proc2_msg1 some_data1;
  struct my_proc2_msg2 some_data2;
  char buffer[MAX_TEXT];

  key_t key1 = ftok(".", 0);
  int msgid1 = msgget(key1, IPC_CREAT | 0666);
  if (msgid1 == -1) {
    exit(-1);
  }

  int count = 0;
  some_data2.payload0 = 0;
  some_data2.payload1 = 2555;
  some_data1.msg_id = 1;
  some_data2.msg_id = 2;

  while (1) {
    some_data2.payload0++;
    some_data2.payload1--;
    memcpy(some_data1.msg_txt, &some_data2, sizeof(some_data2));
    if (msgsnd(msgid1, (void *)&some_data1, sizeof(some_data2), 0) == -1) {
      fprintf(stderr, "msgsnd failed\n");
      exit(-1);
    } else {
      printf("sended data %d %d\n", some_data2.payload0, some_data2.payload1);
    }
    sleep(1);
  }
  exit(0);
}
