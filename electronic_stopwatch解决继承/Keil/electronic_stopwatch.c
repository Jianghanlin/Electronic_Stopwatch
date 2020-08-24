#include<reg52.h>
void my_info();
void T0_initial();
void INT_initial();
void key_check();
void display_num(char num,char spot);
void seg_enable(char i);
void display_time();
void delay();

sbit a=P2^0;
sbit b=P2^1;
sbit c=P2^2;
sbit d=P2^3;
sbit e=P2^4;
sbit f=P2^5;
sbit g=P2^6;
sbit h=P2^7;
sbit key3=P1^0;//清零
sbit s1=P1^1;//控制数码管1显示
sbit s2=P1^2;//控制数码管2显示
sbit s3=P1^3;//控制数码管3显示
sbit s4=P1^4;//控制数码管4显示
sbit PWM=P1^5;
unsigned int count=0;
unsigned char flag=0;

int main()
{
    PWM=0;
    my_info();
    T0_initial();
    INT_initial();
    while(1)
    {   
        key_check();//按键检测用来控制T0的中断使能
        display_time();             
    }
}

void timer0() interrupt 1
{    
    count++;//中断函数执行累加计数
    TH0=0xD8;
    TL0=0xF0;//每次进入中断赋初值55536
}

void key_1() interrupt 0
{
    ET0=1;
    flag=1;   
}

void key_2() interrupt 2
{
    ET0=0;
    flag=2;   
}

void T0_initial()
{
    TMOD=0x01;//无需配置C/(T的反)，因为单片机默认上电是低电平
    TH0=0xD8;
    TL0=0xF0;//给定时器赋初值55536
    ET0=0;//先不允许T0中断
    TR0=1;//启动T0计数器
    EA=1;//打开总中断
}

void INT_initial()
{
    EA=0;
    IT0=1;
    EX0=1;
    IT1=1;
    EX1=1;
    EA=1;
}


void key_check() 
{
    static unsigned char now=1;
    unsigned char past;
    past=now;
    if(key3==0)    {flag=3;now=0;}
    else    now=1;

    if(flag==0)     ET0=0;
    else if((past==1)&&(now==0)) {ET0=0;count=0;}     
}

void display_time()
{
    if(count>9999)//计满显示
    {   
        seg_enable(0);
        display_num(9,0);
        seg_enable(1);        

        delay();

        seg_enable(0);
        display_num(9,1);
        seg_enable(2);        

        delay();

        seg_enable(0);
        display_num(9,0);
        seg_enable(3);

        delay();

        seg_enable(4);
        delay();
    }
    else if(count>999)//1000~9999的显示
    {
        seg_enable(0);
        display_num(count/1000,0);
        seg_enable(1);

        delay();

        seg_enable(0);
        display_num((count/100)%10,1);
        seg_enable(2);


        delay();

        seg_enable(0);
        display_num((count/10)%10,0);
        seg_enable(3);

        
        delay();

        seg_enable(0);
        display_num(count%10,0);
        seg_enable(4);

        delay();                
    }
    else if(count>99)//100~999的显示
    {
        seg_enable(0);
        display_num(count/100,1);
        seg_enable(2);
       
        delay();

        seg_enable(0);
        display_num((count/10)%10,0);
        seg_enable(3);
        
        delay();

        seg_enable(0);
        display_num(count%10,0);
        seg_enable(4);
        
        delay();                  
    }
    else if(count>9)//10~99的显示
    {
        seg_enable(0);
        display_num(0,1);
        seg_enable(2);
        
        delay();

        seg_enable(0);
        display_num(count/10,0);        
        seg_enable(3);
        
        delay();

        seg_enable(0);
        display_num(count%10,0);        
        seg_enable(4); 

        delay();               
    }
    else
    {
        seg_enable(0);
        display_num(0,1);
        seg_enable(2);
        
        delay();
        
        seg_enable(0);
        display_num(0,0);       
        seg_enable(3);
        
        delay();
        
        seg_enable(0);
        display_num(count,0);        
        seg_enable(4);

        delay();                
    }   
}

void delay()
{
    unsigned char i,j;
    for(i=19;i>0;i--)
        for(j=100;j>0;j--);//4ms延时
    // for(i=111;i>0;i--)
    //     for(j=12;j>0;j--);		 //3ms延时
    PWM=~PWM;    
}


void display_num(char num,char spot)
{
    switch(num)
    {
        case 0:
            if(spot==1)     {a=0;b=0;c=0;d=0;e=0;f=0;g=1;h=0;}//显示0带点
            else            {a=0;b=0;c=0;d=0;e=0;f=0;g=1;h=1;}//显示0不带点
            break;
        case 1:
            if(spot==1)     {a=1;b=0;c=0;d=1;e=1;f=1;g=1;h=0;}//显示1带点
            else            {a=1;b=0;c=0;d=1;e=1;f=1;g=1;h=1;}//显示1不带点
            break;
        case 2:
            if(spot==1)     {a=0;b=0;c=1;d=0;e=0;f=1;g=0;h=0;}//显示2带点
            else            {a=0;b=0;c=1;d=0;e=0;f=1;g=0;h=1;}//显示2不带点
            break;
        case 3:
            if(spot==1)     {a=0;b=0;c=0;d=0;e=1;f=1;g=0;h=0;}//显示3带点
            else            {a=0;b=0;c=0;d=0;e=1;f=1;g=0;h=1;}//显示3不带点
            break;
        case 4:
            if(spot==1)     {a=1;b=0;c=0;d=1;e=1;f=0;g=0;h=0;}//显示4带点
            else            {a=1;b=0;c=0;d=1;e=1;f=0;g=0;h=1;}//显示4不带点
            break;       
        case 5:
            if(spot==1)     {a=0;b=1;c=0;d=0;e=1;f=0;g=0;h=0;}//显示5带点
            else            {a=0;b=1;c=0;d=0;e=1;f=0;g=0;h=1;}//显示5不带点
            break;
        case 6:
            if(spot==1)     {a=0;b=1;c=0;d=0;e=0;f=0;g=0;h=0;}//显示6带点
            else            {a=0;b=1;c=0;d=0;e=0;f=0;g=0;h=1;}//显示6不带点
            break;
        case 7:
            if(spot==1)     {a=0;b=0;c=0;d=1;e=1;f=1;g=1;h=0;}//显示7带点
            else            {a=0;b=0;c=0;d=1;e=1;f=1;g=1;h=1;}//显示7不带点
            break;
        case 8:
            if(spot==1)     {a=0;b=0;c=0;d=0;e=0;f=0;g=0;h=0;}//显示8带点
            else            {a=0;b=0;c=0;d=0;e=0;f=0;g=0;h=1;}//显示8不带点
            break;
        case 9:
            if(spot==1)     {a=0;b=0;c=0;d=0;e=1;f=0;g=0;h=0;}//显示9带点
            else            {a=0;b=0;c=0;d=0;e=1;f=0;g=0;h=1;}//显示9不带点
    }
}

void my_info()
{
    unsigned char i,j;
    for(i=100;i>0;i--)
    {
        seg_enable(2);
        a=1;b=0;c=0;d=0;e=0;f=1;g=1;h=1;  
        delay();
        seg_enable(3);
        a=1;b=0;c=0;d=1;e=0;f=0;g=0;h=1; 
        delay();
        seg_enable(4);
        a=1;b=1;c=1;d=0;e=0;f=0;g=1;h=1;
        delay();
    }
    for(j=100;j>0;j--)
    {
        seg_enable(1);
        display_num(0,0); 
        delay();
        seg_enable(2);
        display_num(1,0); 
        delay();
        seg_enable(3);
        display_num(0,0); 
        delay();
        seg_enable(4);
        display_num(7,0);
        delay();
    }
}

void seg_enable(char i)
{
    switch(i)
    {
        case 0:     s1=1;s2=1;s3=1;s4=1;    break;
        case 1:     s1=0;s2=1;s3=1;s4=1;    break;             
        case 2:     s1=1;s2=0;s3=1;s4=1;    break;              
        case 3:     s1=1;s2=1;s3=0;s4=1;    break;
        case 4:     s1=1;s2=1;s3=1;s4=0;
    }
}

