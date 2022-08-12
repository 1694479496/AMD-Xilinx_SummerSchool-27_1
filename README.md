# AMD-Xilinx_SummerSchool
DFT算法的HLS求解与PYNQ实验  
基于xc7z020clg484-1
用于远程实验  
solution3和solution6为不同DFTcpp算法的同类型HLS求解

注：
![image](https://user-images.githubusercontent.com/36146459/184332099-8f235a14-d230-400f-a042-ba57bb47d33b.png)
直接执行全部代码时，会出现下板执行前后，输出buffer中结果均为零，分析应该是全部执行时，Zynq输出的结果还未全部读入PC缓存中，就直接输出了，导致输出异常，此时重新执行输出语句就可以看到计算结果；此外，逐步执行（上一条执行完毕再执行下一条），一般不会出现此问题~~~
