#include <hellfire.h>

void task(void){
	//just to skip time
	for(;;){
		printf("task %d \n", hf_selfid());		
		delay_ms(500);
	}

}
void app_main(void){
	hf_spawn(task, 10, 1, 10, "task 1", 1024);
	hf_spawn(task, 20, 1, 20, "task 2", 1024);
	hf_spawn(task, 15, 1, 15, "task 3", 1024);
	hf_spawn(task, 5, 1, 5, "task 4", 1024);
	hf_spawn(task, 15, 1, 15, "task 5", 1024);
	hf_spawn(task, 10, 1, 10, "task 6", 1024);
	hf_spawn(task, 5, 1, 5, "task 7", 1024);
}

