#include <stdio.h>                   //stdio.h标准输入输出库，用于键盘输入屏幕输出等。
#include <stdlib.h>                  //stdlib.h标准库共含有五种类型，有文件打开读写、宏等命令。
#include <string.h>                  //字符串处理库，有字符串比较、复制等待命令。
#define true 1                       //#define是宏定义的意思，把true的值定义为1


/*
声明一个结构体。struct是声明结构体类型命令，student就是结构体的名字。结构体，通俗讲就像是打包封装，把一些有联系的变量封装在内部，通过一定方法访问修改内部变量。
*/
struct shangpin
{
    char id[30];
    char name[30];
    char prize[30];
    char changjia[30];
    char riqi[30];
    char xiancun[30];
};


/*
程序中所有函数的声明
*/
int dq(struct shangpin sp[]);         //声明函数  建立名字为dq的返回值为int整型的函数，这个函数的参数（形参）是一个名字叫sp的结构体类型的数组。
void xianshi();                      //显示菜单功能函数的声明  建立名字为xianshi的返回值为空的函数。
void bc(struct shangpin sp[]);        //保存功能函数的声明  建立名字为bc的返回值为空的函数，这个函数的参数（形参）是一个是一个名字叫sp的结构体类型的数组。
void add();                          //添加信息功能函数的声明  建立名字为add的返回值为空的函数。
void select();                       //查看信息功能函数声明  建立名字为select的返回值为空的函数。
void zz();                           //提示已保存功能函数声明  建立名字为zz的返回值为空的函数。
void chazhao();                      //查找菜单功能函数声明  建立名字为chazhao的返回值为空的函数。
void xg();                           //修改菜单功能函数声明  建立名字为xg的返回值为空的函数。
void fh();                           //提示返回菜单功能函数声明    建立名字为fh的返回值为空的函数。
struct shangpin sp[300];              //建立一个结构体变量数组sp,它的结构体名称是shangpin sp，它的数组容量是300，也就是说在录入信息时最大容量是300，超出会出错。300是最大信息数目，调整它的值可以修改这个程序的最大有效保存信息的数目。
int Number=0;                        //建立int整型变量Number,并且直接把它的值赋0。


/*
主函数，一是显示创立学生信息界面并创立保存文件，二是显示主菜单并根据用户不同选择调用对应函数。
*/
void main()//主函数 用于调用各个功能函数
{
    int choose=0;                    //建立int整型变量choose,并把它的值赋0。
    FILE *fp=NULL;                   //打开输入文件 建立一个FILE文件操作型的指针变量,变量名字叫fp,*表示后面这个变量是指针变量。把这个文件操作的指针变量的值赋0，就是把它初始化。
    char yesorno;                    //建立字符型变量yesorno

    if((fp=fopen("shangpin.dat","rb"))==NULL)//如果打开文件等于空，就执行下面花括号中的程序。
                                     //fopen("shangpin.dat","rb")，fopen是打开文件，文件的名字是shangpin.dat，打开的方式是rb是以二进制的形式读。文件的名字上没有路径，所以默认从程序所在的当前目录来打开这个文件。打开成功会返回该文件打开后的文件指针，打开失败返回空值NULL。
                                     //fp=返回指针==NULL，由于==等于符号的优先级大于赋值符号=，所以此处先计算返回指针==NULL，再计算fp=返回指针，也就是说如果返回的是空值和NULL相等，就把空值赋值给fp，并执行下面花括号中的操作，进行创建工作。如果返回的不是空值，就把它赋值给fp，执行下面花括号后面else以后的操作。
    {
        printf("\n=========>提示：现在没有学生信息，是否要创建一个?(y/n)\n");//输出创建提示信息
        scanf("%c",&yesorno);        //%是格式化输出符号，后面接输出格式 c 表示输出字符。&是连接到的意思，&yesorno，就是把字符保存到字符变量yesorno中。整句含义是把键盘上输入的字条在屏幕上显示，同时把它保存到yesorno变量中。创建后的文件操作指针赋值给fp。
        if(yesorno=='y'||yesorno=='Y')//如果yesorno这个变量是y或者Y(只要是y,大小写都一样)，就执行下面花括号中的语句。||是或者的意思。
        {
            fp=fopen("shangpin.dat","wb");//为读写建立一个新的二进制文件，wg新建一个二进制文件shangpin.dat，已存在的文件将被删除，只允许写。
            fclose(fp);              //关闭fp   fclose是一个函数名，功能是关闭一个流。注意：使用fclose()函数就可以把缓冲区内最后剩余的数据输出到内核缓冲区，并释放文件指针和有关的缓冲区。
        }
        else                         //如果输入的不是大写或小写的y,就执行以下操作语句。
            exit(0);                 //函数exit功能是关闭所有文件，终止正在执行的进程，它的参数是0表示正常退出，非0表示异常退出。
    }
    else                             //如果fp不为空（读入文件名字成功）
    {
        Number=dq(sp);               //dq(sp)说把读入文件的数据的数组数取回；再把这个数字赋值给Number。通过这句，原有信息被保存到sp数组中，而且知道了原有数据有多少条，这个数字被保存在Number中。
    }

    system("cls");                   //system是执行系统命令，它的参数有很多种。cls是dos命令清屏的意思。这里把前面输出的界面清空为显示主菜单做准备。

    while(true)                      //while如果true的值非0，就执行下面花括号中的操作，由于true在开头的宏定义中已经定义为1，所以下面花括号中的语句正常进行中。
    {
        xianshi();                   //调用显示主菜单函数xianshi，来显示主菜单。
        printf("                    请选择：");//显示主菜单下面的显示文字。
        scanf("%d",&choose);         //scanf接收键盘输入的字符，%d一方面以十进制来显示在屏幕上，&choose另一方面把接收到的数值保存在choose变量中。
        system("cls");               //system是执行系统命令，它的参数有很多种。cls是dos命令清屏的意思。
        switch(choose)               //用switch 实现功能函数的调用
                                     //switch是多分支选择语句。计算它后面括号（choost,也就是上面用户所输入数字）的值，根据值的不同来选择不同的分支语句，并一直执行下去。
        {
            case 6: exit(0);fh();break;//case 6：choose是6的话，就执行exit(0)关闭程序语句，再执行fh()返回主菜单语句，其实这是完全多余的，程序都关闭了，你还返回什么主菜单？break终止这层的循环。这在这里也没用。
            case 1: add();fh();break;//case 1：choose是1的话，就执行add添加信息函数，再执行fh返回主菜单语句，再执行break语句来结束循环，
            case 2: select();fh();break;//choose是2就执行select输出全部信息函数。
            case 3: chazhao();fh();break;//choose是3就执行chazhao查找函数。
            case 4: xg();fh();break; //choose是4就执行xg修改函数。
            case 5:zz();fh();break;  //choose是5就执行zz保存函数。
            default:break;           //default如果用户什么选择也没有，就执行break语句结束本次语句，也就是说什么也不做。
        }
        fflush(stdin);               //fflush(stdin)，简单说就是清内存的。含义是清空输入缓冲区（多为键盘输入的信息），通常是为了确保不影响后面的数据读取。
        getchar();                   //getchar()是在输入缓冲区顺序读入一个字符
        system("cls");               //cls 清屏.
    }
}



void zz()//功能函数 用来实现提示 已保存
{
    printf("\t=====程序在运行时已自动保存.....\n");
}

void fh()//功能函数 用来实现 提示 按enter 键返回主菜单
{
    printf("\t===>按Enter键返回主菜单\n");
}

void xg() //功能函数 用来实现调出 修改菜单

{
    FILE *fp=NULL;                   //文件操作指针fp为空
    char id[30];                      //定义字符型变量id长度为30字节
    int i=0;                         //建立整型变量i,changgindex,index并为它们赋0值。
    int changeIndex=0;
    int index=0;
    printf("请输入要修改的商品号：");//输出修改提示
    scanf("%s",id);                  //接收输入的文字，保存在变量id中。
    system("cls");                   //清屏。
    for(i=0;i<Number;i++)            //通过循环语句找出信息
    {
        if (strcmp(id,sp[i].id)==0)  //strcmp是比较字符串的值，就是用一个减去另一个，并返回相减的值。若值为0说明两个相等，否则不相等。
                                     //如果接收的学号信息id和数组sp[i]的值相等，那么它们相减得到的值为0，就说明找到了目标的位置就是i。那么就执行下面花括号中内容，把找到的信息都显示出来。
        {
            changeIndex=i;           //用changeIndex来保存我们找到的学号位置i
                printf("%-20s%-20s%-20s%-20s%-20s%-20s\n\n","商品号","商品名称","商品价格","商品厂家","生产日期","现存量");
            printf("%-20s%-20s%-20s%-20s%-20s%-20s\n",sp[i].id,sp[i].name,sp[i].prize,sp[i].changjia,sp[i].riqi,sp[i].xiancun);//把目标学号的，姓名、学号、成绩分别显示到屏幕上。\t%s是说用一个制表符的长度8个字节来显示字符型的数据。如果你要显示的数据超过了一个制表符那么就会显示不全而出错。
                                     //上面这行的意思是把你要修改的信息先在屏幕上显示，供你修改它时做参考。
        printf("请重新输入该商品信息");  //输出提示信息
        printf("商品号：");
        scanf("%s",sp[changeIndex].id);
        getchar();
        printf("商品名称：");
        scanf("%s",sp[changeIndex].name);
        getchar();
        printf("商品价格：");
        scanf("%s",sp[changeIndex].prize);
        getchar();
        printf("商品厂家：");
        scanf("%s",sp[changeIndex].changjia);
        getchar();
        printf("商品日期：");
        scanf("%s",sp[changeIndex].riqi);
        getchar();
        printf("现存量：");
        scanf("%s",sp[changeIndex].xiancun);
        getchar();


        fp=fopen("shangpin.dat","wb");   //wb以二进制方式打开shangpin.dat，打开后文件操作指针用fp保存，接着马上修改硬盘文件。
        for (i=0;i<Number;i++)           //如果i小于整个数组的个数Number,那么就进行循环，每次循环后i都自加1，来移动文件读写位置。
        {
            fwrite(&sp[i],sizeof(struct shangpin),1,fp);//fwrite是向文件写入一个数据块。把sp数组的所有数据，按一次写入一个结构体struct shangpin的长度的数据。把所有数据依次写入shangpin.dat
        }
        fclose(fp);                      //关闭fp，把打开的文件关闭
        printf("\t=======>修改成功\n");  //输出提示信息
        printf("即将返回主菜单！\n");
        getchar();
        }
    }
            if (changeIndex>Number||changeIndex==0)
        {
        printf("未找到商品数据，即将返回主菜单！\n");
        getchar();
        }



}


void chazhao()                       //功能函数 用来实现 调出查找菜单
{
    int j=0;
    int m;
    do
    {
    system("cls");
    printf("查询方式:");
    printf("\t\t\t1.按商品名称查询\n\n");
    printf("\t\t\t\t2.按商品厂家查询\n\n");
    printf("请选择查询方式：");
    scanf("%d",&m);
    switch(m)
    {
    case 1: mingchaxun();break;
    case 2: changchaxun();break;
    default:{printf("输入错误，请重新载入\n");getch();}
    }
    printf("\n是否查询下一商品信息?(y/n)");
    m=getchar();
    }while(m=='y');
}
void mingchaxun()     //按照商品的名称查询。
{
    int a=0;
    char name[30],b;
    printf("请输入商品名称:\n");
    fflush(stdin);
    gets(name);
    for(a=0;a<Number;a++)
    {
        if(strcmp(name,sp[a].name)==0)
        {
            printf("\n\t 该商品在第%d个位置找到了。\n\n",a+1);
            break;
        }
    }
    if(a==Number)
        printf("\n\t没有找到商品数据。\n");
    else
    {
        printf("%-20s%-20s%-20s%-20s%-20s%-20s\n\n","商品号","商品名称","商品价格","商品厂家","生产日期","现存量");
        printf("%-20s%-20s%-20s%-20s%-20s%-20s\n\n",sp[a].id,sp[a].name,sp[a].prize,sp[a].changjia,sp[a].riqi,sp[a].xiancun);
    }
}
void changchaxun()       //按照商品的厂家查询。
{
    int a=0;
    char changjia[30],b;
    printf("请输入商品厂家\n");
    fflush(stdin);
    gets(changjia);
    for(a=0;a<Number;a++)
    {
        if(strcmp(changjia,sp[a].changjia)==0)
        {
            printf("\n\t 该商品在第%d个位置找到了。\n\n",a+1);
            break;
        }
    }
    if(a==Number)
        printf("\n\t没有找到商品数据。\n");
    else
    {
        printf("%-20s%-20s%-20s%-20s%-20s%-20s\n\n","商品号","商品名称","商品价格","商品厂家","生产日期","现存量");
        printf("%-20s%-20s%-20s%-20s%-20s%-20s\n\n",sp[a].id,sp[a].name,sp[a].prize,sp[a].changjia,sp[a].riqi,sp[a].xiancun);
    }
}

void select()//功能函数 用于实现输出学生信息
{
    int i=0;                         //建立整型变量i,并为它们赋0值
    printf("以下是全部商品的信息\n");//输出提示信息
    printf("%-20s%-20s%-20s%-20s%-20s%-20s\n\n","商品号","商品名称","商品价格","商品厂家","生产日期","现存量");
    for(i=0;i<Number;i++)            //通过FOR循环 输出 如果当前组数i小于最大组数就接着循环。
    {
        printf("%-20s%-20s%-20s%-20s%-20s%-20s\n",sp[i].id,sp[i].name,sp[i].prize,sp[i].changjia,sp[i].riqi,sp[i].xiancun);//那么就把找到的信息都显示出来。
    }
}


void add()                           //功能函数 用于实现添加学生信息
{
    int numberTemp=0;                //建立整型变量numberTemp,并为它们赋0值
    int i=0;                         //建立整型变量i,并为它们赋0值
    struct shangpin temp;             //建立struct shangpin类型的变量temp
    printf("请输入要增加商品个数：");
    scanf("%d",&numberTemp);         //接收输入的文字，保存在变量numberTemp中。
    for(i=0;i<numberTemp;i++)        //通过FOR循环 依次将学生信息输入
    {
        printf("输入第%d个商品信息\n",i+1);//输出提示信息
        printf("商品号：");
        scanf("%s",temp.id);
        printf("商品名称：");
        scanf("%s",temp.name);
        printf("商品价格：");
        scanf("%s",temp.prize);
        printf("商品厂家：");
        scanf("%s",temp.changjia);
        printf("商品日期：");
        scanf("%s",temp.riqi);
        printf("现存量：");
        scanf("%s",temp.xiancun);
		while(getchar() != '\n');

        sp[Number++]=temp;           //把sp[Number]中的Number自加1,再把刚才的struct shangpin类型的变量temp赋值给它，也就是给sp[Number++]
        bc(&temp);//保存             //调用bc函数，把变量temp写到目标文件中。
    }
    printf("添加成功\n");            //输出提示信息
}
void bc(struct shangpin *sp)          //保存函数
{
    FILE *fp=NULL;                   //打开输入文件，文件读写指针fp为空值。
    fp=fopen("shangpin.dat","ab+");  //将文件保存到指定位置shangpin.dat中。ab+是向二进制文本的末尾写入数据，这种打开方式也可以读数据。
    fwrite(sp,sizeof(struct shangpin),1,fp);//把sp的数据写入文件操作指针fp的位置上去。
    fclose(fp);                      //关闭fp
}

/*
dq是读取数据并保存到st数组中，最后返回st的数组成员数，就是返回所读数据共有多少组。
*/
int dq(struct shangpin sp[])
{
    FILE *fp=NULL;                   //打开输入文件,设置文件型指针fp，它的初值为空。
    int i=0;                         //设置整型变量i,并且赋初值为0.
    fp=fopen("shangpin.dat","rb");   //foren打开shangpin.dat这个文件，用rb（二进制读）方式打开，文件打开后返回的数据开始位置用fp这个文件指针来保存。
    while(fread(&sp[i],sizeof(struct shangpin),1,fp))//当存入数据后将i自加 （新的存储位置）   fread是一个函数(参数：buffer  用于接收数据的内存地址  size要读的每个数据项的字节数，单位是字节  count要读数据项的个数，每个数据项size个字节.  stream输入流的指针)。从一个文件流中读数据，最多读取count个元素，每个元素size字节，如果调用成功返回实际读取到的元素个数，如果不成功或读到文件末尾返回 0。sizeof是计算对象所占的字节数，通常用来查看变量、数组或结构体等所占的字节个数。
                                     //先用sizeof取得结构体struct shangpin的长度。
                                     //再用fread来读取文件fp处的数据，一次读一个长度为得到长度的数据，再把读出的数据放到st数组的对应的位置。读取成功fp的值就是操作的位置非0，读取失败就是说fp的值取到了0值或者说空值。
    i++;                             //while是说如果这种读取数据返回的文件指针fp的值非0，就说没到数据结尾，就把i自加1，就是i=i+1,通过这个手段，来移动文件指针fp,使它向前移动了一位，达到连续读取数据的目的。
    fclose(fp);                      //关闭fp 如果读取的结果是空值，就结束这次读取数据的过程。
    return i;                        //把数据的读取次数i返回给调用者。
}


void xianshi()                       //功能函数 用来实现 菜单主菜单效果
{
    printf("\t*****************************************************************\n");
    printf("\t*                                                               *\n");
    printf("\t*                      商品管理系统                             *\n");
    printf("\t*                                                               *\n");
    printf("\t*        [1] 添加商品信息          [2] 查看商品信息             *\n");
    printf("\t*        [3] 查找商品信息          [4] 修改商品信息             *\n");
    printf("\t*        [5] 保存数据              [6] 退出系统                 *\n");
    printf("\t*                                                               *\n");
    printf("\t*****************************************************************\n");
}
