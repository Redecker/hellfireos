#include <hellfire.h>

void task(void){
	for(;;){
		printf("task %d \n", hf_selfid());		
		delay_ms(200);
	}
}
void app_main(void){
	hf_spawn(task, 15, 2, 15, "task 1", 1024);
	hf_spawn(task, 30, 1, 30, "task 2", 1024);
	hf_spawn(task, 20, 2, 20, "task 3", 1024);
	hf_spawn(task, 24, 4, 24, "task 4", 1024);
	hf_spawn(task, 100, 9, 100, "task 5", 1024);
	hf_spawn(task, 40, 5, 40, "task 6", 1024);
}

