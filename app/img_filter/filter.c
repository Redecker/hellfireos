#include <hellfire.h>
#include <noc.h>
#include "image.h"

struct matrixPacket {
  uint32_t x;
  uint32_t y;
  uint8_t* data;
} matrixPacket;

uint8_t gausian(uint8_t buffer[5][5]){
	int32_t sum = 0, mpixel;
	uint8_t i, j;

	int16_t kernel[5][5] =	{	{2, 4, 5, 4, 2},
					{4, 9, 12, 9, 4},
					{5, 12, 15, 12, 5},
					{4, 9, 12, 9, 4},
					{2, 4, 5, 4, 2}
				};
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			sum += ((int32_t)buffer[i][j] * (int32_t)kernel[i][j]);
	mpixel = (int32_t)(sum / 159);

	return (uint8_t)mpixel;
}

uint32_t isqrt(uint32_t a){
	uint32_t i, rem = 0, root = 0, divisor = 0;

	for (i = 0; i < 16; i++){
		root <<= 1;
		rem = ((rem << 2) + (a >> 30));
		a <<= 2;
		divisor = (root << 1) + 1;
		if (divisor <= rem){
			rem -= divisor;
			root++;
		}
	}
	return root;
}

uint8_t sobel(uint8_t buffer[3][3]){
	int32_t sum = 0, gx = 0, gy = 0;
	uint8_t i, j;

	int16_t kernelx[3][3] =	{	{-1, 0, 1},
					{-2, 0, 2},
					{-1, 0, 1},
				};
	int16_t kernely[3][3] =	{	{-1, -2, -1},
					{0, 0, 0},
					{1, 2, 1},
				};
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			gx += ((int32_t)buffer[i][j] * (int32_t)kernelx[i][j]);
			gy += ((int32_t)buffer[i][j] * (int32_t)kernely[i][j]);
		}
	}
	
	sum = isqrt(gy * gy + gx * gx);

	if (sum > 255) sum = 255;
	if (sum < 0) sum = 0;

	return (uint8_t)sum;
}

uint8_t* do_gausian(uint8_t *chunk, int32_t width, int32_t height){
    int32_t i, j, k, l;
    uint8_t image_buf[5][5];
    
    uint8_t *outImg = (uint8_t *) malloc(width*height);

    for(i = 0; i < height; i++){
        if (i > 1 || i < height-1){
            for(j = 0; j < width; j++){
                if (j > 1 || j < width-1){
                    for (k = 0; k < 5;k++)
                        for(l = 0; l < 5; l++)
                            image_buf[k][l] = chunk[(((i + l-2) * width) + (j + k-2))];

                    outImg[((i * width) + j)] = gausian(image_buf);
                }else{
                    outImg[((i * width) + j)] = chunk[((i * width) + j)];
                }
            }
        }
    }

    return outImg;
}

uint8_t* do_sobel(uint8_t *chunk, int32_t width, int32_t height){
    int32_t i, j, k, l;
    uint8_t image_buf[3][3];
    uint8_t *outImg = (uint8_t *) malloc(width*height);

    for(i = 0; i < height; i++){
        if (i > 0 || i < height){
            for(j = 0; j < width; j++){
                if (j > 0 || j < width){
                    for (k = 0; k < 3;k++)
                        for(l = 0; l < 3; l++)
                            image_buf[k][l] = chunk[(((i + l-1) * width) + (j + k-1))];

                    outImg[((i * width) + j)] = sobel(image_buf);
                }else{
                    outImg[((i * width) + j)] = chunk[((i * width) + j)];
                }
            }
        }
    }
    return outImg;
}


uint32_t convertPosToIndex(uint32_t x, uint32_t y, uint32_t aWidth)
{	
	//printf("(%d+%d*%d)", x, width, y);
    return (x + aWidth * y);
}


void task(void){
    uint32_t i, j, k = 0;
    uint8_t* img;
    uint32_t time;
    
    while(1) {
        img = (uint8_t *) malloc(height * width);
        if (img == NULL){
            printf("\nmalloc() failed!\n");
            for(;;);
        }

        printf("\n\nstart of processing!\n\n");

        time = _readcounter();

        //começa aqui
        uint8_t* chunk = (uint8_t*) malloc(1024);

        uint32_t x,y = 0;
        
        //Como tem 16 slaves, da pra fazer 2 for
        uint8_t maxX = width/32;
        uint8_t maxY = height/32;

        for(i=0; i<maxY; i++)
        {
            for(j=0; j<maxX; j++)
            {
                //printf("Bloco %d \n", i+j);
                for(y=0; y<32; y++)
                {   
                    for(x=0; x<32; x++)
                    {   
                        uint32_t posarray = convertPosToIndex(x + j*32, y + i*32, width);
                        chunk[convertPosToIndex(x,y, 32)] = image[posarray];

                        //printf("0x%02x ", chunk[convertPosToIndex(x,y, 32)]);
                    }
                    //printf("\n");
                }
                   
                
                struct matrixPacket mp;
                mp.x = j;
                mp.y = i;
                mp.data = chunk;


                //Manda a struct pro filhao
                
                //Filhao faz as coisas
                mp.data = do_gausian(mp.data, 32, 32);        
                mp.data = do_sobel(mp.data, 32, 32);     


                //Filaho manda de volta
                
                //Auxiliar do filhao junta

                for(y=0; y<32; y++)
                {   
                    for(x=0; x<32; x++)
                    {   
                        img[convertPosToIndex(mp.x*32 + x, mp.y*32 + y, width)] = mp.data[convertPosToIndex(x,y,32)];
                    }
                }
            }
        }
		time = _readcounter() - time;

		printf("done in %d clock cycles.\n\n", time);

		printf("\n\nint32_t width = %d, height = %d;\n", width, height);
		printf("uint8_t image[] = {\n");
		for (i = 0; i < height; i++){
			for (j = 0; j < width; j++){
				printf("0x%x", img[i * width + j]);
				if ((i < height-1) || (j < width-1)) printf(", ");
				if ((++k % 16) == 0) printf("\n");
			}
		}
		printf("};\n");

		free(img);

		printf("\n\nend of processing!\n");
		panic(0);
	}
		
}

void app_main(void) {
	if (hf_cpuid() == 0){
		hf_spawn(task, 0, 0, 0, "filter", 2048);
	}
}
