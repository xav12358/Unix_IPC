#include "header.h"

struct my_proc1_msg1 {
  long int msg_id;
  char msg_txt[BUFSIZ];
};

struct my_proc1_msg2 {
  long int msg_id;
  int payload0;
  int payload1;
};

int main(int argc, char *argv[]) {

  int running = 1;
  struct my_proc1_msg1 msg_data1;
  struct my_proc1_msg2 msg_data2;
  long int msg_to_receive1 = 0;
  key_t key1 = ftok(".", 0);
  int msgid1 = msgget(key1, 0666 | IPC_CREAT);

  while (running) {
    if (msgrcv(msgid1, (void *)&msg_data1, sizeof(msg_data1) - sizeof(long),
               msg_to_receive1, IPC_NOWAIT) > 0) {
      memcpy(&msg_data2, msg_data1.msg_txt, sizeof(msg_data2));
      // printf("data2 %d \n ", msg_data2.kk);
      printf("received  data %d %d \n ", msg_data2.payload0,
             msg_data2.payload1);
    }
    usleep(100000);
  }

  exit(0);
}
