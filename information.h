#ifndef _INFORMATION_H
#define _INFORMATION_H


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <windows.h>
#include <wincon.h>
#include <conio.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <ctype.h>
#include <time.h>

/*************************************************以下是统计节点*********************************************************/
typedef struct statistic1{
    char* jiaoshixingming;
    int kechengshu;
    double xuefenshu;
    int xueshishu;          //降序排列 
    int zongrenshu;

    struct statistic1* next;
}STATISTIC1, *PSTATISTIC1;

typedef struct statistic2{
    char* kechengmingcheng[30];
    int ketangshu;			
    int sGPA[5];			
    double junfen;

    struct statistic2* next;
}STATISTIC2, *PSTATISTIC2;

typedef struct statistic3{
    char xueqi[12];
    int ketangshu;
    int zhiwei[4];
    int chidaoshu;

    struct statistic3* next;
}STATISTIC3, *PSTATISTIC3;

typedef struct statistic4{
    char* jiaoshixingming;
    double zonghepingjia;   //降序

    struct statistic4* next;
}STATISTIC4, *PSTATISTIC4;

/*************************************************以上是统计节点*********************************************************/

/******************督导信息节点*****************/
typedef struct list3{
	//num
	int num;
	//data
	char xueqi[10];			/* 学期*/
	char gonghao[12];		/* 任课教师工号*/
	char mingcheng[30];		/* 课程名称*/
	char riqi[10];			/* 查课日期*/
	char kaoqin;			/* 教师考勤*/
	int daoke;				/* 到课学生数*/
	char xiaoguo;			/* 课堂效果*/
	int pingjia;			/* 学生评价*/
	char dudaogonghao[12];	/* 督导教师工号*/
	//pointer
	struct list3* next;
}Node_spv;


/*****************课堂信息节点******************/
typedef struct list2{
	//num
	int num;
	//data
	char xueqi[10];				/*学期*/
	char gonghao[12];			/*教师工号*/
	char mingcheng[30];			/*(课程)名称*/
	double xuefen;				/*学分*/
	int xueshi;					/*学时*/
	char ketang[20];			/*课堂    比如CS1307-10*/
	int renshu;					/*人数*/
	int GPA[5];					/*得分人数 0->59,1->60,2->70,3->80,4->90 */
	double junfen;				/*均分*/
	//pointer
	struct list3* spv;
	struct list2* next;
}Node_cls;


/*****************教师信息节点******************/
typedef struct list{
	//num
	int num;
	//data
	char gonghao[12];		/*教师工号*/
	char xingming[20];		/*教师姓名*/
	char zhicheng;			/*教师职称*/
	//pointer
	struct list2* cls;
	struct list* next;
}Node_tch;


const char* TITLE = "教师督导信息管理系统";



/**********************************************界面字符串****************************************************/
#define NUMOFCH 60
const char welcome[][NUMOFCH]={
"欢迎来到教师信息管理系统！请输入数字选择服务",//0
"数据维护",     //1
"数据遍历",     //2
"数据统计",     //3
"数据搜索",     //4
"退出",
};
#define Nwelcome (sizeof(welcome)/sizeof(*welcome))

const char maintain[][NUMOFCH]={
"要选择下列选项，请输入数字选择服务",
"数据录入",			//1.1
"数据修改",			//1.2
"数据删除",			//1.3
"返回上一级菜单",
};
#define Nmaintain (sizeof(maintain)/sizeof(*maintain))

	const char insert[][NUMOFCH]={
	"要选择下列选项，请输入数字选择服务",
	"教师数据录入",		//1.1.1
	"课堂信息录入",		//1.1.2
	"督导信息录入",		//1.1.3
	"返回上一级菜单",
	};
	#define Ninsert (sizeof(insert)/sizeof(*insert))

	const char modified[][NUMOFCH]={
	"要选择下列选项，请输入数字选择服务",
	"教师数据修改",		//1.2.1
	"课堂信息修改",		//1.2.2
	"督导信息修改", 	//1.2.3
	"返回上一级菜单",
	};
	#define Nmodified (sizeof(modified)/sizeof(*modified))


	const char deleted[][NUMOFCH]={
	"要选择下列选项，请输入数字选择服务",
	"教师数据删除",		//1.3.1
	"课堂信息删除",		//1.3.2
	"督导信息删除", 	//1.3.3
	"返回上一级菜单",
	};
	#define Ndeleted (sizeof(deleted)/sizeof(*deleted))


const char refer[][NUMOFCH]={
"要选择下列选项，请输入数字选择服务",
"教师数据遍历查询",		//2.1
"课堂信息遍历查询",		//2.2
"督导信息遍历查询", 	//2.3
"返回上一级菜单",
};
#define Nrefer (sizeof(refer)/sizeof(*refer))


const char seekinfo[][NUMOFCH]={
"要选择下列选项，请输入数字选择服务",
"【查询教师基本信息】根据教师工号  ",
"【查询教师基本信息】根据根据教师姓名的一部分和教师职称",
"【查询课堂基本信息】根据学期，教师工号和课堂名称",
"【查询课堂基本信息】根据学期和学时数",
"【查询督导基本信息】根据教师工号，学期，课程名称和学生评价",
"【查询督导基本信息】根据督导教师工号，学期和学生评价",
"返回上一级菜单",
};
#define Nseekinfo (sizeof(seekinfo)/sizeof(*seekinfo))

const char statqq[][NUMOFCH]={
"要选择下列选项，请输入数字选择服务",
"统计任课教师的课程数,学分数,学时数,课程总人数",
"统计某学期每门课程开设的课堂数及考试情况",
"统计某门课程每个学期开设的课堂数,教师职称,考勤",
"统计某年度每个教师讲授的所有课程的学生评价综合分值",
"返回上一级菜单",
};
#define Nstatqq (sizeof(statqq)/sizeof(*statqq))


const char* Job[]={
"教授",
"副教授",
"讲师",
"助教",
};

const char* kaoq[]={
"准时",
"迟到",
};

/**********************************************以上是界面字符串****************************************************/


const char bug = 'U';

const char* info_tch="Teachers.dat";
const char* info_cls="Classes.dat";
const char* info_spv="Supervisors.dat";



/**********界面函数***********/
int  menu_start(const char s[][NUMOFCH], int n);
void SearchTch(Node_tch* hd);
//1数据维护
int shujuweihu(int choice);
//1.1数据录入 
void shujuluru(void);			/*1.1*/
void jiaoshiluru(void);
void ketangluru(void);
void dudaoluru(void);
//1.2数据修改 
void shujuxiugai(void);			/*1.2*/
void jiaoshixiugai(void);
void ketangxiugai(void);
void dudaoxiugai(void);
//1.3删除 
void shujushanchu(void);		/*1.3*/
void jiaoshishanchu(void);
void ketangshanchu(void);
void dudaoshanchu(void);


//2数据查询
int shujuchaxun(int choice);

void jiaoshichaxun(void);
void ketangchaxun(void);
void dudaochaxun(void);

void SearchTch(Node_tch* hd);
void SearchCls(Node_tch* hd);
void SearchSpv(Node_tch* hd);
//3数据统计
int shujutongji(int choice);

void jiaoshitongji(void);
void ketangtongji(void);
void dudaotongji(void);
void pingjiatongji(void);

//4数据搜索
int shujusousuo(int choice);

void souTch1(void);
void souTch2(void);
void souCls1(void);
void souCls2(void);
void souSpv1(void);
void souSpv2(void);
/********************************/

int CreatList(Node_tch **phead);		/*创建链表*/
BOOL SaveSysData(Node_tch* hd);			/*保存数据*/


/**********功能函数***********/
//1维护函数

//1.1录入函数 
BOOL InsertTchNode(Node_tch* pTch_written);
BOOL InsertClsNode(Node_tch* hd, Node_cls* pCls_written);
BOOL InsertSpvNode(Node_tch* hd, Node_spv* pSpv_written);
//1.2删除函数 
BOOL DelTchNode(Node_tch* headp, char* Gonghao);
BOOL DelClsNode(Node_tch* headp, char* Xueqi, char* Gonghao, char* Mingcheng);
BOOL DelSpvNode(Node_tch* headp, char* Gonghao, char* Xueqi, char* Mingcheng, char* Riqi);
//1.3修改函数 
BOOL ModifyTchNode(Node_tch* headp, char* Gonghao, Node_tch* pTch_written);
BOOL ModifyClsNode(Node_tch* headp, char* Xueqi, char* Gonghao, char* Mingcheng, Node_cls* pCls_written);
BOOL ModifySpvNode(Node_tch* headp, char* Gonghao, char* Xueqi, char* Mingcheng,
 					char* Riqi, Node_spv* pSpv_written);


//2查询函数
//<教师>
Node_tch* SeekTchNode(Node_tch* headp, char* Gonghao); 		/*【精确查询】以教师工号查询1教师信息节点*/
Node_tch* SeekTchNode2(Node_tch* headp, char* Xingshi, char Zhicheng);	/*【模糊查询】以学期和学时数查询1教师信息节点*/
//<课堂>
Node_cls* SeekClsNode(Node_tch* headp, char* Xueqi, char* Gonghao, char* Mingcheng);	/*【精确查询】以工号和课程名和学期查询2课堂信息节点*/
Node_cls* SeekClsNode2(Node_tch* hd, char* Xueqi, int cond_num,...);			
Node_cls* SeekClsNode2R(Node_tch* headp, char* xq, int sup, int inf);					/*【模糊查询】以学期和学时数查询2课堂信息节点*/
BOOL JudgeClsNodeItem(Node_cls* pcls_node, char* pcondition);
//<督导>
Node_spv* SeekSpvNode(Node_tch* headp, char* Gonghao, char* Xueqi, char* Mingcheng, char* Riqi);	/*【精确查询】以工号和课程名和学期和督导日期查询3督导信息节点*/
Node_spv* SeekSpvNode2(Node_tch* headp, char* Gonghao, char* Xueqi, int cond_num,...);		/*【模糊查询】以学期和学生评价查询2课堂信息节点*/
BOOL JudgeSpv2NodeItem(Node_spv* pspv_node, char* pcondition);
//3统计函数

//<教师>
STATISTIC1* StatTchNode(Node_tch* headp);	/*统计任课教师的课程数,学分数,学时数,课程总人数*/ 
void SortTchNode(STATISTIC1* hd);	
//<课堂>
STATISTIC2* StatClsNode(Node_tch* headp);	/*统计某学期每门课程开设的课堂数及考试情况*/
STATISTIC2* searchstat(STATISTIC2* hd, char* Mingcheng);
void SortClsNode(STATISTIC2* hd);

//<督导> 
STATISTIC3* StatSpvNode(Node_tch* headp);	/*统计某门课程每个学期开设的课堂数,教师职称,考勤*/
int nodecmp(STATISTIC3* h1, STATISTIC3* h2);
void SortSpvNode(STATISTIC3* hd);
STATISTIC3* searchstatspv(STATISTIC3* hd, char* Xueqi);
//<评价> 
STATISTIC4* StatPjNode(Node_tch* headp, int year);	/*统计某年度每个教师讲授的所有课程的学生评价综合分值*/
void SortPjNode(STATISTIC4* hd);




#endif
