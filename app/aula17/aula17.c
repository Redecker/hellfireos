#include <hellfire.h>
#include <noc.h>

void t1(void){

	int8_t buft7[1280];
	int8_t buft2[256];
	int8_t buft3_4_5[64];
	uint16_t result;
	
	if (hf_comm_create(hf_selfid(), 1000, 0))
		panic(0xff);
	
	sprintf(buft7, "hello from cpu %d thread %d\n", hf_cpuid(), hf_selfid());
	result = hf_sendack(0, 7000, buft7, sizeof(buft7), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);

	sprintf(buft2, "hello from cpu %d thread %d\n", hf_cpuid(), hf_selfid());
	result = hf_sendack(1, 2000, buft2, sizeof(buft2), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);	

	sprintf(buft3_4_5, "hello from cpu %d thread %d\n", hf_cpuid(), hf_selfid());
	result = hf_sendack(2, 3000, buft3_4_5, sizeof(buft3_4_5), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);

	sprintf(buft3_4_5, "hello from cpu %d thread %d\n", hf_cpuid(), hf_selfid());
	result = hf_sendack(3, 4000, buft3_4_5, sizeof(buft3_4_5), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);

	sprintf(buft3_4_5, "hello from cpu %d thread %d\n", hf_cpuid(), hf_selfid());
	result = hf_sendack(4, 5000, buft3_4_5, sizeof(buft3_4_5), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);
}

void t2(void){
	//recebe
	int8_t buft1[256];
	//envia
	int8_t buft6[64];
	int8_t buft7[320];
	int8_t buft8[320];
	
	uint16_t result;
	
	if (hf_comm_create(hf_selfid(), 2000, 0))
		panic(0xff);

	//recebendo
	uint16_t cpu, task, size;	
	result = hf_recvack(&cpu, &task, buft1, &size, 0);
	if (result)	printf("error %d\n", result);
	else printf("%s", buft1);
	
	//enviando	
	sprintf(buft6, "hello from cpu %d thread %d\n", hf_cpuid(), hf_selfid());
	result = hf_sendack(5, 6000, buft6, sizeof(buft6), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);

	sprintf(buft7, "hello from cpu %d thread %d\n", hf_cpuid(), hf_selfid());
	result = hf_sendack(0, 7000, buft7, sizeof(buft7), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);	

	sprintf(buft8, "hello from cpu %d thread %d\n", hf_cpuid(), hf_selfid());
	result = hf_sendack(1, 8000, buft8, sizeof(buft8), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);
}

void t3(void){
	//recebe
	int8_t buft1[64];
	//envia
	int8_t buft7[320];
	int8_t buft8[64];
	
	uint16_t result;
	
	if (hf_comm_create(hf_selfid(), 3000, 0))
		panic(0xff);

	//recebendo
	uint16_t cpu, task, size;	
	result = hf_recvack(&cpu, &task, buft1, &size, 0);
	if (result)	printf("error %d\n", result);
	else printf("%s", buft1);
	
	//enviando	
	sprintf(buft7, "hello from cpu %d thread %d\n", hf_cpuid(), hf_selfid());
	result = hf_sendack(0, 7000, buft7, sizeof(buft7), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);	

	sprintf(buft8, "hello from cpu %d thread %d\n", hf_cpuid(), hf_selfid());
	result = hf_sendack(1, 8000, buft8, sizeof(buft8), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);
}

void t4(void){
	//recebe
	int8_t buft1[64];
	//envia
	int8_t buft8[64];
	
	uint16_t result;
	
	if (hf_comm_create(hf_selfid(), 4000, 0))
		panic(0xff);

	//recebendo
	uint16_t cpu, task, size;	
	result = hf_recvack(&cpu, &task, buft1, &size, 0);
	if (result)	printf("error %d\n", result);
	else printf("%s", buft1);
	
	//enviando	
	sprintf(buft8, "hello from cpu %d thread %d\n", hf_cpuid(), hf_selfid());
	result = hf_sendack(1, 8000, buft8, sizeof(buft8), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);
}

void t5(void){
	//recebe
	int8_t buft1[64];
	//envia
	int8_t buft7[320];
	int8_t buft8[64];
	
	uint16_t result;
	
	if (hf_comm_create(hf_selfid(), 5000, 0))
		panic(0xff);

	//recebendo
	uint16_t cpu, task, size;	
	result = hf_recvack(&cpu, &task, buft1, &size, 0);
	if (result)	printf("error %d\n", result);
	else printf("%s", buft1);
	
	//enviando	
	sprintf(buft7, "hello from cpu %d thread %d\n", hf_cpuid(), hf_selfid());
	result = hf_sendack(0, 7000, buft7, sizeof(buft7), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);	

	sprintf(buft8, "hello from cpu %d thread %d\n", hf_cpuid(), hf_selfid());
	result = hf_sendack(1, 8000, buft8, sizeof(buft8), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);
}

void t6(void){
	//recebe
	int8_t buft2[64];
	//envia
	int8_t buft9[640];
	
	uint16_t result;
	
	if (hf_comm_create(hf_selfid(), 6000, 0))
		panic(0xff);

	//recebendo
	uint16_t cpu, task, size;	
	result = hf_recvack(&cpu, &task, buft2, &size, 0);
	if (result)	printf("error %d\n", result);
	else printf("%s", buft2);
	
	//enviando	
	sprintf(buft9, "hello from cpu %d thread %d\n", hf_cpuid(), hf_selfid());
	result = hf_sendack(0, 9000, buft9, sizeof(buft9), 0, 500);
	if (result) printf("sender, hf_sendack(): error %d\n", result);	
}

void t7(void){
    //recebe
    int8_t buft1[1280];
    int8_t buft2[320];
    int8_t buft3[320];
    //envia
    int8_t buft9[640];
    
    uint16_t result;
    
    if (hf_comm_create(hf_selfid(), 7000, 0))
        panic(0xff);

    //recebendo
    uint16_t cpu, task, size;   
    result = hf_recvack(&cpu, &task, buft1, &size, 0);
    if (result) printf("error %d\n", result);
    else printf("%s", buft1);

    result = hf_recvack(&cpu, &task, buft2, &size, 0);
    if (result) printf("error %d\n", result);
    else printf("%s", buft2);

    result = hf_recvack(&cpu, &task, buft3, &size, 0);
    if (result) printf("error %d\n", result);
    else printf("%s", buft3);

    //enviando  
    sprintf(buft9, "hello from cpu %d thread %d\n", hf_cpuid(), hf_selfid());
    result = hf_sendack(2, 9000, buft9, sizeof(buft9), 0, 500);
    if (result) printf("sender, hf_sendack(): error %d\n", result);
}

void t8(void){
    //recebe
    int8_t buft2[320];
    int8_t buft3[64];
    int8_t buft4[64];
    int8_t buft5[640];
    //envia
    int8_t buft9[640];
    
    uint16_t result;
    
    if (hf_comm_create(hf_selfid(), 8000, 0))
        panic(0xff);

    //recebendo
    uint16_t cpu, task, size;   
    result = hf_recvack(&cpu, &task, buft2, &size, 0);
    if (result) printf("error %d\n", result);
    else printf("%s", buft2);

    result = hf_recvack(&cpu, &task, buft3, &size, 0);
    if (result) printf("error %d\n", result);
    else printf("%s", buft3);

    result = hf_recvack(&cpu, &task, buft4, &size, 0);
    if (result) printf("error %d\n", result);
    else printf("%s", buft4);

    result = hf_recvack(&cpu, &task, buft5, &size, 0);
    if (result) printf("error %d\n", result);
    else printf("%s", buft5);
    
    //enviando  
    sprintf(buft9, "hello from cpu %d thread %d\n", hf_cpuid(), hf_selfid());
    result = hf_sendack(2, 9000, buft9, sizeof(buft9), 0, 500);
    if (result) printf("sender, hf_sendack(): error %d\n", result);
}

void t9(void){
    
    //recebe
    int8_t buft6[640];
    int8_t buft7[640];
    int8_t buft8[640];
    
    uint16_t result;
    
    if (hf_comm_create(hf_selfid(), 9000, 0))
        panic(0xff);

    //recebendo
    uint16_t cpu, task, size;   
    result = hf_recvack(&cpu, &task, buft6, &size, 0);
    if (result) printf("error %d\n", result);
    else printf("%s", buft6);

    result = hf_recvack(&cpu, &task, buft7, &size, 0);
    if (result) printf("error %d\n", result);
    else printf("%s", buft7);

    result = hf_recvack(&cpu, &task, buft8, &size, 0);
    if (result) printf("error %d\n", result);
    else printf("%s", buft8);
}


void app_main(void)
{	
	if (hf_cpuid() == 0){
		hf_spawn(t1, 0, 0, 0, "T1", 4096);
		hf_spawn(t7, 0, 0, 0, "T7", 4096);
	}else if(hf_cpuid() == 1){
		hf_spawn(t2, 0, 0, 0, "T2", 4096);
		hf_spawn(t8, 0, 0, 0, "T8", 4096);
	}else if (hf_cpuid() == 2){
		hf_spawn(t3, 0, 0, 0, "T3", 4096);
		hf_spawn(t9, 0, 0, 0, "T9", 4096);
	}else if(hf_cpuid() == 3){
		hf_spawn(t4, 0, 0, 0, "T4", 4096);
	}else if(hf_cpuid() == 4){
		hf_spawn(t5, 0, 0, 0, "T5", 4096);
	}else if(hf_cpuid() == 5){
		hf_spawn(t6, 0, 0, 0, "T6", 4096);
	}
}
