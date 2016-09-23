#include <hellfire.h>

void task(void){
	for(;;){
		printf("task %d \n", hf_selfid());		
		delay_ms(200);
	}
}
void app_main(void){
	hf_spawn(task, 12, 1, 12, "task 1", 1024);
	hf_spawn(task, 10, 3, 10, "task 2", 1024);
	hf_spawn(task, 15, 1, 15, "task 3", 1024);
	hf_spawn(task, 17, 2, 17, "task 4", 1024);
	hf_spawn(task, 30, 5, 30, "task 5", 1024);
	hf_spawn(task, 24, 4, 24, "task 6", 1024);
}

