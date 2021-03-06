# HellfireOS Realtime Operating System

---
### Instructions:

optional: 
- Download GNU cross (MIPS) toolchain (4.6 series, pre-built)
  - [32 bits](https://dl.dropboxusercontent.com/u/7936618/gcc-4.6.1_x86.tar.gz)
  - [64 bits](https://dl.dropboxusercontent.com/u/7936618/gcc-4.6.1.tar.gz)
```sh
export PATH=$PATH:<CURRENT-DIRECTORY>/gcc-4.6.1/bin
```
 - Execute 
```sh
git clone git@github.com/sjohan81/hellfireos.git
cd hellfireos
gcc usr/sim/hf_risc_sim/hf_risc_sim.c -o usr/sim/hf_risc_sim/hf_risc_sim
cd platform/single_core
make image
cd ../../
./usr/sim/hf_risc_sim/hf_risc_sim platform/single_core/image.bin 
```

- T1
```
cd platform/single_core/
nano makefile
make clean
make image
cd ../../
./usr/sim/hf_risc_sim/hf_risc_sim platform/single_core/image.bin log.txt
java -jar usr/kprofiler/Kprofiler.jar 
```

- Exercicio
```
cd platform/noc_3x2/
make clean
nano makefile
make images
cp *.bin ~/Documents/hellfireos/usr/sim/mpsoc_sim/objects/ -f
cd ../../
cd usr/sim/mpsoc_sim/
make noc_3x2	
./mpsoc_sim 3 s
```

- T2
```
//compile the app
cd platform/noc_3x2/
make clean
make images
cp *.bin ~/Documents/hellfireos/usr/sim/mpsoc_sim/objects/ -f
cd ../../
//simulates the mpsoc
cd usr/sim/mpsoc_sim/
./mpsoc_sim 20 s
//see the image
subl host/filter_image.h
subl reports/out0.txt
<copy image>
cd ../../../
cd host/
gcc create_bmp.c -o create_bmp
./create_bmp
xnview output.bmp &
```
---

