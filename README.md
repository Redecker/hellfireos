# HellfireOS Realtime Operating System

---
### Instructions:

optional: 
- Download GNU cross (MIPS) toolchain (4.6 series, pre-built)
  - [32 bits](https://dl.dropboxusercontent.com/u/7936618/gcc-4.6.1_x86.tar.gz)
  - [64 bits](https://dl.dropboxusercontent.com/u/7936618/gcc-4.6.1.tar.gz)
```sh
export PATH=$PATH:<PATH_TO_TOOLCHAIN>/bin/ (see 1)
```
 - Execute 
```sh
git clone git@github.com/sjohan81/hellfireos.git
cd hellfireos
gcc /usr/sim/hf_risc_sim/hf_risc_sim.c -o /usr/sim/hf_risc_sim/hf_risc_sim
cd platform/single_core
make image
cd ../../
./usr/sim/hf_risc_sim/hf_risc_sim platform/single_core/image.bin 
```
1- You can use "./export.sh" to export the PATH

---

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