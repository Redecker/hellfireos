#include <hellfire.h>

void task(void){
	//just to skip time
	for(;;){
		printf("task %d \n", hf_selfid());		
		delay_ms(500);
	}

}

void app_main(void){
	hf_spawn(task, 6, 1, 6, "task a", 1024);
	hf_spawn(task, 9, 1, 9, "task b", 1024);
	hf_spawn(task, 5, 1, 5, "task c", 1024);
	hf_spawn(task, 7, 1, 7, "task d", 1024);
	hf_spawn(task, 6, 1, 6, "task e", 1024);
}

