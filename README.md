# 【51单片机】基于STC89C52RC的电子秒表

随着电子技术的发展，电子技术在各个领域的运用也越来越广泛，人们对它的认识也 逐步加深。电子秒表功能设计不断完善，时间设计上不断精确。电子秒表适用于对时间测 量精度要求较高的场合此次课程设计利用型号为STC89C52RC 的单片机、8段共阳LED数码管等电子元器 件来实现简易不带存储功能的电子秒表。<br />**目录**

- **设计题目**
- **设计目的**
- **设计内容及要求**
- **设计过程**
- **总体设计**
> 关键元件选取具体电路设计，基于Altium Designer 20程序设计

- **仿真过程，Proteus 8 与 Keil 联动**
- **制作与实现**
> 元件的购买与焊接系统调试

- **遇到的问题与解决方法**
- **心得体会**

---

<a name="ChwGC"></a>
### 1 设计题目

- 设计一个电子秒表
<a name="33XqR"></a>
### 2 设计目的

- 巩固模拟和数字电子技术基础知识，学习51单片机，并用其设计电子产品。
- 掌握熟悉产品开发的调试方法，增强工程实践能力和综合分析问题的能力。
<a name="Nw7GW"></a>
### 3 设计内容及要求

- 学习51单片机内部资源，要求熟练掌握单片机I/O口，定时器和中断系统的使用。其主要学习以下内容：
> 中央处理器存储器组织片内并行接口8051的芯片引脚中断定时器/计数器（T/C）

- 设计电子秒表，用51单片机STC89C52设计控制电路，用4位数码管显示，能从00.00秒计时到99.99秒。
> 秒表计数器元器件选型秒表计数器单片机控制电路设计软件流程框图绘制、应用程序编制，仿真调试电路原理图绘制电路板设计与制作焊接下载程序调试
<a name="Lc5Kl"></a>
### 4 设计过程

- 总体设计
> 此次电子秒表设计包括： 单片机为STC89C52RC，晶振电路由12MHz晶振和电容构成，复位电路由按键、电容限流电阻构成，按键电路由按键、上拉电阻构成，数码管显示电路由8段共阳数码管构成。其电路总设计框图如下：
![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610972443890-f5040919-408f-41b4-944d-5ddbaf2c723b.jpeg#align=left&display=inline&height=313&margin=%5Bobject%20Object%5D&originHeight=450&originWidth=720&size=0&status=done&style=none&width=500)<br />

- 关键元件选取
> STC89C52RC是STC公司生产的一种低功耗、高性能CMOS8位微控制器，具有8K字节系统可编程Flash存储器。STC89C52使用经典的MCS-51内核，但是做了很多的改进使得芯片具有传统的51单片机不具备的功能。在单芯片上，拥有灵巧的8 位CPU 和在系统可编程Flash，使得STC89C52为众多嵌入式控制应用系统提供高灵活、超有效的解决方案。32 位I/O 口线，看门狗定时器，内置4KB EEPROM，MAX810复位电路，3个16 位定时器/计数器，4个外部中断，一个7向量4级中断结构（兼容传统51的5向量2级中断结构），全双工串行口。另外STC89C52 可降至0Hz 静态逻辑操作，支持2种软件可选择节电模式。空闲模式下，CPU 停止工作，允许RAM、定时器/计数器、串口、中断继续工作 1、数据存储器（RAM）：片内为128B（52子系列为256B），片外最多可扩64KB。片内128B的RAM以高速RAM的形式集成，可加快单片机运行的速度和降低功耗 2、程序存储器（Flash ROM）：片内集成有8KB的Flash存储器，如片内容量不够，片外可外扩至64KB 3、中断系统：具有6个中断源，2级中断优先权 4、定时器/计数器：2个16位定时器/计数器（52子系列有3个），4种工作方式 5、看门狗定时器WDT：当CPU由于干扰使程序陷入死循环或跑飞时，WDT可使程序恢复正常运行 关键引脚 RESET：复位信号输入，在引脚加上持续时间大于2个机器周期的高电平，可使单片机复位。正常工作，此脚电平应 ≤ 0.5V。当看门狗定时器溢出输出时，该脚将输出长达96个时钟振荡周期的高电平 (EA) ̅：1，读取内部存储器。0，读取外部存储器 ALE：为CPU访问外部程序存储器或外部数据存储器提供地址锁存信号，将低8位地址锁存在片外的地址锁存器中
![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610972443833-8a91738f-1922-4788-95cc-31f71c811102.jpeg#align=left&display=inline&height=294&margin=%5Bobject%20Object%5D&originHeight=555&originWidth=483&size=0&status=done&style=none&width=256)![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610972443876-c9f9f096-c682-40ec-8d23-85722eece765.jpeg#align=left&display=inline&height=288&margin=%5Bobject%20Object%5D&originHeight=414&originWidth=720&size=0&status=done&style=none&width=500)![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610972443894-b836dd0f-1d01-4f54-8b02-b58ed474ea0f.jpeg#align=left&display=inline&height=271&margin=%5Bobject%20Object%5D&originHeight=300&originWidth=501&size=0&status=done&style=none&width=453)<br />

> **PNP型三极管**> 三极管，全称应为半导体三极管，也称双极型晶体管、晶体三极管，是一种电流控制电流的半导体器件，其作用是把微弱信号放大成幅度值较大的电信号，也用作无触点开关。晶体三极管，是半导体基本元器件之一，具有电流放大作用，是电子电路的核心元件。三极管是在一块半导体基片上制作两个相距很近的PN结，两个PN结把整块半导体分成三部分，中间部分是基区，两侧部分是发射区和集电区，排列方式有PNP和NPN两种。PNP型三极管，是由2块P型半导体中间夹着1块N型半导体所组成的三极管，所以称为PNP型三极管 E端高电压的时候，当B端也是高电压，那么E和C之间是断开的；当B端是低电压，那么E和C直接导通，实现开关的作用
![](https://cdn.nlark.com/yuque/0/2021/jpg/1593351/1610972443889-40c5ffe2-9697-4c06-9bf3-e8bd7e9f77a6.jpg#align=left&display=inline&height=272&margin=%5Bobject%20Object%5D&originHeight=355&originWidth=279&size=0&status=done&style=none&width=214)
> **8段共阳数码管**> 共阳数码管是指将所有发光二极管的阳极接到一起形成公共阳极(COM)的数码管。共阳数码管在应用时应将公共极COM接到+5V，3、8脚在内部是短路的，只需选其一即可。当某一字段发光二极管的阴极为低电平时，相应字段就点亮，当某一字段的阴极为高电平时，相应字段就不亮
![](https://cdn.nlark.com/yuque/0/2021/png/1593351/1610972443896-68987917-9b2b-4ff3-8bfa-8527e49f6c48.png#align=left&display=inline&height=181&margin=%5Bobject%20Object%5D&originHeight=181&originWidth=144&size=0&status=done&style=none&width=144)![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610972443894-8e209ccd-735a-4a7e-b1bc-3d62b124b51a.jpeg#align=left&display=inline&height=166&margin=%5Bobject%20Object%5D&originHeight=232&originWidth=217&size=0&status=done&style=none&width=155)![](https://cdn.nlark.com/yuque/0/2021/jpg/1593351/1610972443861-d83ef840-5713-484b-9795-a36b6d708dc4.jpg#align=left&display=inline&height=194&margin=%5Bobject%20Object%5D&originHeight=222&originWidth=300&size=0&status=done&style=none&width=262)<br />

- 具体电路设计，基于Altium Designer 20
> **晶振模块**> 晶振与单片机的脚XTAL0和脚XTAL1构成的振荡电路中会产生谐波（也就是不希望存在的其他频率的波）这个波对电路的影响不大，但会降低电路的时钟振荡器的稳定性，为了电路的稳定性起见 ATMEL公司只是建议在晶振的两引脚处接入两个10pf-50pf的瓷片电容接地来削减谐波对电路的稳定性的影响，所以晶振所配的电容在10pf-50pf之间都可以的
![](https://cdn.nlark.com/yuque/0/2021/jpg/1593351/1610972443997-a5e777ad-7188-4630-a0d2-9668fdd58e4a.jpg#align=left&display=inline&height=323&margin=%5Bobject%20Object%5D&originHeight=390&originWidth=604&size=0&status=done&style=none&width=500)
> **单片机复位模块**> 复位电路工作原理如上所示，VCC上电时，使极性电容C充电，在200欧电阻上出现高电位电压，使得单片机复位；几个毫秒后，C充满，200欧电阻上电流降为0，电压也为0，使得单片机进入工作状态。工作期间，按下S1，C放电，放电结束后，又充电，在200电阻上出现高电压，使得单片机进入复位状态，直到S1松手，C又充电完毕，随后，单片机进入工作状态
![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610972443891-8a0d8053-6cfe-41f4-b4ba-36575938c9b5.jpeg#align=left&display=inline&height=208&margin=%5Bobject%20Object%5D&originHeight=299&originWidth=720&size=0&status=done&style=none&width=500)
> **三极管开关放大模块**> 如上图，PNP型三极管作为电子开关，当基级b为低电平，三极管集电极c和发射极e打通，集电极c为高电平，使数码管使能；当基级b为高电平，三极管集电极c和发射极e断开，集电极c为低电平，使数码管消隐。三极管处于放大区时，I_c=βI_b，将单片机IO口的微弱电流放大，驱动数码管
![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610972443865-877f4add-e266-4f50-860c-caa1e6caac72.jpeg#align=left&display=inline&height=324&margin=%5Bobject%20Object%5D&originHeight=466&originWidth=720&size=0&status=done&style=none&width=500)
> **数码管电路**> STC89C52RC的P2口作为驱动8段数码管的引脚，分别控制段码a,b,c,d,e,f,g,h。当IO为低电平，则对应段码亮起；当IO为高电平，则对应段码熄灭
![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610972443875-782408d1-8cd5-4c29-b19c-fb09ff5c5755.jpeg#align=left&display=inline&height=366&margin=%5Bobject%20Object%5D&originHeight=434&originWidth=720&size=0&status=done&style=none&width=607)
> **按键模块**> 按键模块如上图所示，上拉电阻在上电时默认将按键右端置为高电平。一旦按键按下，电阻下方为低电平并传给STC89C52对应引脚
![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610972443925-316382bb-7ce8-4785-ba3e-8c6f74a07a51.jpeg#align=left&display=inline&height=491&margin=%5Bobject%20Object%5D&originHeight=707&originWidth=720&size=0&status=done&style=none&width=500)

- 程序设计
> 此次的程序设计由C语言实现。定义了8个自定义函数，2个全局变量，它们分别为：1、my_info() 启动时用来显示自己的个人信息函数2、T0_initial() 定时器0初始化函数3、INT_initial() 外部中断初始化函数4、key_check() 按键检测函数5、display_num(char num,char spot) 显示函数6、seg_enable(char i) 控制数码管的使能函数7、display_time() 数码管显示函数8、delay() 4ms延时函数9、count 控制计数，初始化010、flag 检测按键，按键的标志位，初始化0以下是本次程序设计的流程图，分为主函数执行流程图和中断函数执行流程图：
![](https://cdn.nlark.com/yuque/0/2021/jpg/1593351/1610972443887-c7c0ecea-074c-422a-96b0-a19f63f0687a.jpg#align=left&display=inline&height=319&margin=%5Bobject%20Object%5D&originHeight=319&originWidth=220&size=0&status=done&style=none&width=220)![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610972443888-98bc113d-521d-4f4d-8517-672bd9e30e84.jpeg#align=left&display=inline&height=313&margin=%5Bobject%20Object%5D&originHeight=313&originWidth=216&size=0&status=done&style=none&width=216)![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610972443892-1926194a-614c-4958-b395-99fd63281096.jpeg#align=left&display=inline&height=311&margin=%5Bobject%20Object%5D&originHeight=311&originWidth=214&size=0&status=done&style=none&width=214)<br />定时器0中断流程图                 外部中断INT0中断流程图          外部中断INT1中断流程图<br />![](https://cdn.nlark.com/yuque/0/2021/jpg/1593351/1610972443901-c7c8d83d-f47a-41bf-a099-b74fc372e87b.jpg#align=left&display=inline&height=696&margin=%5Bobject%20Object%5D&originHeight=696&originWidth=480&size=0&status=done&style=none&width=480)<br />主函数执行流程图
> 此次设计的时99.99秒表，精度为0.01s=10ms，所以需让定时器0每0.01s进入一次中断，执行count++并且重新给计数器赋初值。根据51单片机外部12MHz晶振自定义进入中断的时间公式 (2^16-X)*10^(-6)=自定义进入中断时间，计算可得X=55536，转换成16进制为(55536)_D=(D8F0)_H，将D8赋值给高八位TH0，将F0赋值给低八位TL0。
<a name="b1GXf"></a>
### 5 仿真过程，Proteus 8 与 Keil 联动
![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610972443876-7911ca85-0f5f-4282-bea0-c88ce9ecac76.jpeg#align=left&display=inline&height=392&margin=%5Bobject%20Object%5D&originHeight=486&originWidth=720&size=0&status=done&style=none&width=580)<br />启用Enable Remote<br />![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610972443899-f348f79b-6d3c-4516-a65c-18e666364f98.jpeg#align=left&display=inline&height=309&margin=%5Bobject%20Object%5D&originHeight=309&originWidth=554&size=0&status=done&style=none&width=554)<br />激活uVersion4中的Proteus选项<br />![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610972443900-60a9137d-09da-4887-92b0-7bec14e7fcd2.jpeg#align=left&display=inline&height=103&margin=%5Bobject%20Object%5D&originHeight=103&originWidth=554&size=0&status=done&style=none&width=554)<br />编译工程<br />![](https://cdn.nlark.com/yuque/0/2021/jpg/1593351/1610972443911-a04fa39c-bdf8-409c-b3f0-e3e3273adbcb.jpg#align=left&display=inline&height=121&margin=%5Bobject%20Object%5D&originHeight=121&originWidth=554&size=0&status=done&style=none&width=554)<br />启动调试<br />![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610972443884-4f950dc7-fac0-4196-82a6-46386924cc87.jpeg#align=left&display=inline&height=275&margin=%5Bobject%20Object%5D&originHeight=263&originWidth=554&size=0&status=done&style=none&width=580)<br />全速运行<br />![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610972443905-635c7a2e-d170-49e1-af10-5cfbec58d169.jpeg#align=left&display=inline&height=325&margin=%5Bobject%20Object%5D&originHeight=404&originWidth=720&size=0&status=done&style=none&width=580)<br />

<a name="jJG0g"></a>
### 6 制作与实现

- 元件的购买与焊接
> 元件的取材与焊接以下是此次温度测量放大电路焊接所需要元器件
![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610972443921-4708c702-b380-4cab-b860-5141111ce32b.jpeg#align=left&display=inline&height=449&margin=%5Bobject%20Object%5D&originHeight=504&originWidth=720&size=0&status=done&style=none&width=641)<br />元件采购清单

- 系统调试
> 此次课程设计利用的是人眼的滞留效应，又由于STC89C52的IO口有限，需将每个数码管依次延时5ms。由于我对汇编语言的理解不是很深，不清楚延时语句delay到底执行的时间，我想到在delay语句中写入引脚电平取反，这样一来一定会生成周期固定的PWM波。系统上电，借助示波器观察引脚的波形，发现是周期为8ms，占空比为50%的PWM波，即延时程序延时了4ms，符合要求。其他示数一切正常。
![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610972443928-2972d825-a1f2-4a88-bdcc-e8b36ea1ce71.jpeg#align=left&display=inline&height=321&margin=%5Bobject%20Object%5D&originHeight=398&originWidth=720&size=0&status=done&style=none&width=580)<br />![](https://cdn.nlark.com/yuque/0/2021/jpeg/1593351/1610972443899-53433cc0-e354-4d93-aceb-57a10235ee67.jpeg#align=left&display=inline&height=319&margin=%5Bobject%20Object%5D&originHeight=396&originWidth=720&size=0&status=done&style=none&width=580)
<a name="34rEm"></a>
### 7 遇到的问题与解决方法

- 单片机复位电路未接Vcc
> 由于复位电路没有接Vcc，系统启动时Reset引脚始终为低电平，在运行过程中按下按键没有反应。之后接上VCC后，复位电路模块正常工作，系统能够正常复位
