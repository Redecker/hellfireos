#include <hellfire.h>
#include <noc.h>

void t1(void){

	printf("T1 começou\n");

	int8_t buft7[1280];
	int8_t buft2[256];
	int8_t buft3[64];
	int8_t buft4[64];
	int8_t buft5[64];
	uint16_t result;
	
	if (hf_comm_create(hf_selfid(), 10, 0))
		panic(0xff);
	
	delay_ms(40);
	
	printf("T1 enviando para T7, da CPU %d e thread %d \n", hf_cpuid(), hf_selfid());
	sprintf(buft7, "Recebi de T1 \n");
	result = hf_sendack(3, 70, buft7, sizeof(buft7), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);

	printf("T1 enviando para T2, da CPU %d e thread %d\n", hf_cpuid(), hf_selfid());
	sprintf(buft2, "Recebi de T1 \n");
	result = hf_sendack(1, 20, buft2, sizeof(buft2), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);	

	printf("T1 enviando para T3, da CPU %d e thread %d\n", hf_cpuid(), hf_selfid());
	sprintf(buft3, "Recebi de T1 \n");
	result = hf_sendack(2, 30, buft3, sizeof(buft3), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);

	printf("T1 enviando para T4, da CPU %d e thread %d\n", hf_cpuid(), hf_selfid());
	sprintf(buft4, "Recebi de T1 \n");
	result = hf_sendack(3, 40, buft4, sizeof(buft4), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);

	printf("T1 enviando para T5, da CPU %d e thread %d\n", hf_cpuid(), hf_selfid());
	sprintf(buft5, "Recebi de T1 \n");
	result = hf_sendack(1, 50, buft5, sizeof(buft5), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);

	printf("T1 acabou\n");
	while(1){}
}

void t2(void){

	printf("T2 começou\n");

	//recebe
	int8_t buft1[256];
	//envia
	int8_t buft6[64];
	int8_t buft7[320];
	int8_t buft8[320];
	
	uint16_t result;
	
	if (hf_comm_create(hf_selfid(), 20, 0))
		panic(0xff);

	delay_ms(30);

	//recebendo
	uint16_t cpu, task, size;	
	result = hf_recvack(&cpu, &task, buft1, &size, 0);
	if (result)	printf("error %d\n", result);
	else printf("Sou T2 e %s", buft1);
	
	//enviando		
	printf("T2 enviando para T6, da CPU %d e thread %d\n", hf_cpuid(), hf_selfid());
	sprintf(buft6, "Recebi de T2 \n");
	result = hf_sendack(5, 60, buft6, sizeof(buft6), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);

	printf("T2 enviando para T7, da CPU %d e thread %d\n", hf_cpuid(), hf_selfid());
	sprintf(buft7, "Recebi de T2 \n");
	result = hf_sendack(3, 70, buft7, sizeof(buft7), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);	

	printf("T2 enviando para T8, da CPU %d e thread %d\n", hf_cpuid(), hf_selfid());
	sprintf(buft8, "Recebi de T2 \n");
	result = hf_sendack(4, 80, buft8, sizeof(buft8), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);

	printf("T2 acabou\n");
	while(1){}
}

void t3(void){

	printf("T3 começou\n");

	//recebe
	int8_t buft1[64];
	//envia
	int8_t buft7[320];
	int8_t buft8[64];
	
	uint16_t result;
	
	if (hf_comm_create(hf_selfid(), 30, 0))
		panic(0xff);

	delay_ms(30);

	//recebendo
	uint16_t cpu, task, size;	
	result = hf_recvack(&cpu, &task, buft1, &size, 0);
	if (result)	printf("error %d\n", result);
	else printf("Sou T3 e %s", buft1);
	
	//enviando	
	printf("T3 enviando para T7, da CPU %d e thread %d\n", hf_cpuid(), hf_selfid());
	sprintf(buft7, "Recebi de T3 \n");
	result = hf_sendack(3, 70, buft7, sizeof(buft7), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);	

	printf("T3 enviando para T8, da CPU %d e thread %d\n", hf_cpuid(), hf_selfid());
	sprintf(buft8, "Recebi de T3 \n");
	result = hf_sendack(4, 80, buft8, sizeof(buft8), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);

	printf("T3 acabou\n");
	while(1){}
}

void t4(void){

	printf("T4 começou\n");

	//recebe
	int8_t buft1[64];
	//envia
	int8_t buft8[64];
	
	uint16_t result;
	
	if (hf_comm_create(hf_selfid(), 40, 0))
		panic(0xff);
	
	delay_ms(30);

	//recebendo
	uint16_t cpu, task, size;	
	result = hf_recvack(&cpu, &task, buft1, &size, 0);
	if (result)	printf("error %d\n", result);
	else printf("Sou T4 e %s", buft1);
	
	//enviando	
	printf("T4 enviando para T8, da CPU %d e thread %d\n", hf_cpuid(), hf_selfid());
	sprintf(buft8, "Recebi de T4 \n");
	result = hf_sendack(4, 80, buft8, sizeof(buft8), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);

	printf("T4 acabou\n");
	while(1){}
}

void t5(void){

	printf("T5 começou\n");

	//recebe
	int8_t buft1[64];
	//envia
	int8_t buft8[64];
	
	uint16_t result;
	
	if (hf_comm_create(hf_selfid(), 50, 0))
		panic(0xff);

	delay_ms(30);

	//recebendo
	uint16_t cpu, task, size;	
	result = hf_recvack(&cpu, &task, buft1, &size, 0);
	if (result)	printf("error %d\n", result);
	else printf("Sou T5 e %s", buft1);
	
	//enviando	
	printf("T5 enviando para T8, da CPU %d e thread %d\n", hf_cpuid(), hf_selfid());
	sprintf(buft8, "Recebi de T5 \n");
	result = hf_sendack(4, 80, buft8, sizeof(buft8), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);

	printf("T5 acabou\n");
	while(1){}
}

void t6(void){

	printf("T6 começou\n");

	//recebe
	int8_t buft2[64];
	//envia
	int8_t buft9[640];
	
	uint16_t result;
	
	if (hf_comm_create(hf_selfid(), 60, 0))
		panic(0xff);

	delay_ms(20);

	//recebendo
	uint16_t cpu, task, size;	
	result = hf_recvack(&cpu, &task, buft2, &size, 0);
	if (result)	printf("error %d\n", result);
	else printf("Sou T6 e %s", buft2);
	
	//enviando		
	printf("T6 enviando para T9, da CPU %d e thread %d\n", hf_cpuid(), hf_selfid());
	sprintf(buft9, "Recebi de T6 \n");
	result = hf_sendack(0, 90, buft9, sizeof(buft9), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);	

	printf("T6 acabou\n");
	while(1){}
}

void t7(void){

	printf("T7 começou\n");

    //recebe
    int8_t buft1[1280];
    int8_t buft2[320];
    int8_t buft3[320];
    //envia
    int8_t buft9[640];
    
    uint16_t result;
    
    if (hf_comm_create(hf_selfid(), 70, 0))
        panic(0xff);

    delay_ms(20);

    //recebendo
    uint16_t cpu, task, size;   
    uint16_t cpu1, task1, size1;   
    uint16_t cpu2, task2, size2;   
    result = hf_recvack(&cpu, &task, buft1, &size, 0);
    if (result) printf("error %d\n", result);
    else printf("Sou T7 e %s", buft1);

    result = hf_recvack(&cpu1, &task1, buft2, &size1, 0);
    if (result) printf("error %d\n", result);
    else printf("Sou T7 e %s", buft2);

    result = hf_recvack(&cpu2, &task2, buft3, &size2, 0);
    if (result) printf("error %d\n", result);
    else printf("Sou T7 e %s", buft3);

    //enviando      
	printf("T7 enviando para T9, da CPU %d e thread %d\n", hf_cpuid(), hf_selfid());
	sprintf(buft9, "Recebi de T7 \n");
    result = hf_sendack(0, 90, buft9, sizeof(buft9), 0, 500);
    if (result) printf("sender, hf_sendack(): error %d\n", result);

    printf("T7 acabou\n");
    while(1){}
}

void t8(void){

	printf("T8 começou\n");

    //recebe
    int8_t buft2[320];
    int8_t buft3[64];
    int8_t buft4[64];
    int8_t buft5[640];
    //envia
    int8_t buft9[640];
    
    uint16_t result;
    
    if (hf_comm_create(hf_selfid(), 80, 0))
        panic(0xff);

    delay_ms(20);

    //recebendo
    uint16_t cpu, task, size;   
    uint16_t cpu1, task1, size1;   
    uint16_t cpu2, task2, size2;   
    uint16_t cpu3, task3, size3;   
    result = hf_recvack(&cpu, &task, buft2, &size, 0);
    if (result) printf("error %d\n", result);
    else printf("Sou T8 e %s", buft2);

    result = hf_recvack(&cpu1, &task1, buft3, &size1, 0);
    if (result) printf("error %d\n", result);
    else printf("Sou T8 e %s", buft3);

    result = hf_recvack(&cpu2, &task2, buft4, &size2, 0);
    if (result) printf("error %d\n", result);
    else printf("Sou T8 e %s", buft4);

    result = hf_recvack(&cpu3, &task3, buft5, &size3, 0);
    if (result) printf("error %d\n", result);
    else printf("Sou T8 e %s", buft5);
    
    //enviando      
	printf("T8 enviando para T9, da CPU %d e thread %d\n", hf_cpuid(), hf_selfid());
	sprintf(buft9, "Recebi de T8 \n");
    result = hf_sendack(0, 90, buft9, sizeof(buft9), 0, 500);
    if (result) printf("sender, hf_sendack(): error %d\n", result);

    printf("T8 acabou\n");
    while(1){}
}

void t9(void){

	printf("T9 começou\n");
    
    //recebe
    int8_t buft6[640];
    int8_t buft7[640];
    int8_t buft8[640];
    
    uint16_t result;
    
    if (hf_comm_create(hf_selfid(), 90, 0))
        panic(0xff);

    delay_ms(10);

    //recebendo
    uint16_t cpu, task, size;   
    uint16_t cpu1, task1, size1;   
    uint16_t cpu2, task2, size2;   
    result = hf_recvack(&cpu, &task, buft6, &size, 0);
    if (result) printf("error %d\n", result);
    else printf("Sou T9 e %s", buft6);

    result = hf_recvack(&cpu1, &task1, buft7, &size1, 0);
    if (result) printf("error %d\n", result);
    else printf("Sou T9 e %s", buft7);

    result = hf_recvack(&cpu2, &task2, buft8, &size2, 0);
    if (result) printf("error %d\n", result);
    else printf("Sou T9 e %s", buft8);

    printf("T9 acabou\n");
    while(1){}
}


void app_main(void)
{	
	if (hf_cpuid() == 0){
		hf_spawn(t9, 0, 0, 0, "T9", 4096);
		hf_spawn(t1, 0, 0, 0, "T1", 4096);
	}else if(hf_cpuid() == 1){
		hf_spawn(t5, 0, 0, 0, "T5", 4096);
		hf_spawn(t2, 0, 0, 0, "T2", 4096);
	}else if (hf_cpuid() == 2){
		hf_spawn(t3, 0, 0, 0, "T3", 4096);
	}else if(hf_cpuid() == 3){
		hf_spawn(t7, 0, 0, 0, "T7", 4096);
		hf_spawn(t4, 0, 0, 0, "T4", 4096);
	}else if(hf_cpuid() == 4){
		hf_spawn(t8, 0, 0, 0, "T8", 4096);
	}else if(hf_cpuid() == 5){
		hf_spawn(t6, 0, 0, 0, "T6", 4096);
	}
}
