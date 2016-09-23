#include <hellfire.h>

void task(void){
	for(;;){
		printf("task %d \n", hf_selfid());		
		delay_ms(500);
	}
}
void app_main(void){
	hf_spawn(task, 10, 2, 10, "task 1", 1024);
	hf_spawn(task, 30, 5, 30, "task 2", 1024);
	hf_spawn(task, 50, 10, 50, "task 3", 1024);
	hf_spawn(task, 30, 6, 30, "task 4", 1024);
	hf_spawn(task, 30, 1, 30, "task 5", 1024);
	hf_spawn(task, 40, 8, 40, "task 6", 1024);
}

