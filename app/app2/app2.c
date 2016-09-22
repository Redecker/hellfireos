#include <hellfire.h>

void task(void){
	//just to skip time
	for(;;){
		printf("task %d \n", hf_selfid());		
		delay_ms(500);
	}

}

//essa aplicacao buga porque os deadlines sempre sao os primeiros!!!!
void app_main(void){
	hf_spawn(task, 2, 1, 2, "task 1", 1024);
	hf_spawn(task, 3, 1, 3, "task 2", 1024);
	hf_spawn(task, 4, 1, 4, "task 3", 1024);
	hf_spawn(task, 5, 1, 5, "task 4", 1024);
}

