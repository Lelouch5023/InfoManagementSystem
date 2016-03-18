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

/*************************************************������ͳ�ƽڵ�*********************************************************/
typedef struct statistic1{
    char* jiaoshixingming;
    int kechengshu;
    double xuefenshu;
    int xueshishu;          //�������� 
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
    double zonghepingjia;   //����

    struct statistic4* next;
}STATISTIC4, *PSTATISTIC4;

/*************************************************������ͳ�ƽڵ�*********************************************************/

/******************������Ϣ�ڵ�*****************/
typedef struct list3{
	//num
	int num;
	//data
	char xueqi[10];			/* ѧ��*/
	char gonghao[12];		/* �ον�ʦ����*/
	char mingcheng[30];		/* �γ�����*/
	char riqi[10];			/* �������*/
	char kaoqin;			/* ��ʦ����*/
	int daoke;				/* ����ѧ����*/
	char xiaoguo;			/* ����Ч��*/
	int pingjia;			/* ѧ������*/
	char dudaogonghao[12];	/* ������ʦ����*/
	//pointer
	struct list3* next;
}Node_spv;


/*****************������Ϣ�ڵ�******************/
typedef struct list2{
	//num
	int num;
	//data
	char xueqi[10];				/*ѧ��*/
	char gonghao[12];			/*��ʦ����*/
	char mingcheng[30];			/*(�γ�)����*/
	double xuefen;				/*ѧ��*/
	int xueshi;					/*ѧʱ*/
	char ketang[20];			/*����    ����CS1307-10*/
	int renshu;					/*����*/
	int GPA[5];					/*�÷����� 0->59,1->60,2->70,3->80,4->90 */
	double junfen;				/*����*/
	//pointer
	struct list3* spv;
	struct list2* next;
}Node_cls;


/*****************��ʦ��Ϣ�ڵ�******************/
typedef struct list{
	//num
	int num;
	//data
	char gonghao[12];		/*��ʦ����*/
	char xingming[20];		/*��ʦ����*/
	char zhicheng;			/*��ʦְ��*/
	//pointer
	struct list2* cls;
	struct list* next;
}Node_tch;


const char* TITLE = "��ʦ������Ϣ����ϵͳ";



/**********************************************�����ַ���****************************************************/
#define NUMOFCH 60
const char welcome[][NUMOFCH]={
"��ӭ������ʦ��Ϣ����ϵͳ������������ѡ�����",//0
"����ά��",     //1
"���ݱ���",     //2
"����ͳ��",     //3
"��������",     //4
"�˳�",
};
#define Nwelcome (sizeof(welcome)/sizeof(*welcome))

const char maintain[][NUMOFCH]={
"Ҫѡ������ѡ�����������ѡ�����",
"����¼��",			//1.1
"�����޸�",			//1.2
"����ɾ��",			//1.3
"������һ���˵�",
};
#define Nmaintain (sizeof(maintain)/sizeof(*maintain))

	const char insert[][NUMOFCH]={
	"Ҫѡ������ѡ�����������ѡ�����",
	"��ʦ����¼��",		//1.1.1
	"������Ϣ¼��",		//1.1.2
	"������Ϣ¼��",		//1.1.3
	"������һ���˵�",
	};
	#define Ninsert (sizeof(insert)/sizeof(*insert))

	const char modified[][NUMOFCH]={
	"Ҫѡ������ѡ�����������ѡ�����",
	"��ʦ�����޸�",		//1.2.1
	"������Ϣ�޸�",		//1.2.2
	"������Ϣ�޸�", 	//1.2.3
	"������һ���˵�",
	};
	#define Nmodified (sizeof(modified)/sizeof(*modified))


	const char deleted[][NUMOFCH]={
	"Ҫѡ������ѡ�����������ѡ�����",
	"��ʦ����ɾ��",		//1.3.1
	"������Ϣɾ��",		//1.3.2
	"������Ϣɾ��", 	//1.3.3
	"������һ���˵�",
	};
	#define Ndeleted (sizeof(deleted)/sizeof(*deleted))


const char refer[][NUMOFCH]={
"Ҫѡ������ѡ�����������ѡ�����",
"��ʦ���ݱ�����ѯ",		//2.1
"������Ϣ������ѯ",		//2.2
"������Ϣ������ѯ", 	//2.3
"������һ���˵�",
};
#define Nrefer (sizeof(refer)/sizeof(*refer))


const char seekinfo[][NUMOFCH]={
"Ҫѡ������ѡ�����������ѡ�����",
"����ѯ��ʦ������Ϣ�����ݽ�ʦ����  ",
"����ѯ��ʦ������Ϣ�����ݸ��ݽ�ʦ������һ���ֺͽ�ʦְ��",
"����ѯ���û�����Ϣ������ѧ�ڣ���ʦ���źͿ�������",
"����ѯ���û�����Ϣ������ѧ�ں�ѧʱ��",
"����ѯ����������Ϣ�����ݽ�ʦ���ţ�ѧ�ڣ��γ����ƺ�ѧ������",
"����ѯ����������Ϣ�����ݶ�����ʦ���ţ�ѧ�ں�ѧ������",
"������һ���˵�",
};
#define Nseekinfo (sizeof(seekinfo)/sizeof(*seekinfo))

const char statqq[][NUMOFCH]={
"Ҫѡ������ѡ�����������ѡ�����",
"ͳ���ον�ʦ�Ŀγ���,ѧ����,ѧʱ��,�γ�������",
"ͳ��ĳѧ��ÿ�ſγ̿���Ŀ��������������",
"ͳ��ĳ�ſγ�ÿ��ѧ�ڿ���Ŀ�����,��ʦְ��,����",
"ͳ��ĳ���ÿ����ʦ���ڵ����пγ̵�ѧ�������ۺϷ�ֵ",
"������һ���˵�",
};
#define Nstatqq (sizeof(statqq)/sizeof(*statqq))


const char* Job[]={
"����",
"������",
"��ʦ",
"����",
};

const char* kaoq[]={
"׼ʱ",
"�ٵ�",
};

/**********************************************�����ǽ����ַ���****************************************************/


const char bug = 'U';

const char* info_tch="Teachers.dat";
const char* info_cls="Classes.dat";
const char* info_spv="Supervisors.dat";



/**********���溯��***********/
int  menu_start(const char s[][NUMOFCH], int n);
void SearchTch(Node_tch* hd);
//1����ά��
int shujuweihu(int choice);
//1.1����¼�� 
void shujuluru(void);			/*1.1*/
void jiaoshiluru(void);
void ketangluru(void);
void dudaoluru(void);
//1.2�����޸� 
void shujuxiugai(void);			/*1.2*/
void jiaoshixiugai(void);
void ketangxiugai(void);
void dudaoxiugai(void);
//1.3ɾ�� 
void shujushanchu(void);		/*1.3*/
void jiaoshishanchu(void);
void ketangshanchu(void);
void dudaoshanchu(void);


//2���ݲ�ѯ
int shujuchaxun(int choice);

void jiaoshichaxun(void);
void ketangchaxun(void);
void dudaochaxun(void);

void SearchTch(Node_tch* hd);
void SearchCls(Node_tch* hd);
void SearchSpv(Node_tch* hd);
//3����ͳ��
int shujutongji(int choice);

void jiaoshitongji(void);
void ketangtongji(void);
void dudaotongji(void);
void pingjiatongji(void);

//4��������
int shujusousuo(int choice);

void souTch1(void);
void souTch2(void);
void souCls1(void);
void souCls2(void);
void souSpv1(void);
void souSpv2(void);
/********************************/

int CreatList(Node_tch **phead);		/*��������*/
BOOL SaveSysData(Node_tch* hd);			/*��������*/


/**********���ܺ���***********/
//1ά������

//1.1¼�뺯�� 
BOOL InsertTchNode(Node_tch* pTch_written);
BOOL InsertClsNode(Node_tch* hd, Node_cls* pCls_written);
BOOL InsertSpvNode(Node_tch* hd, Node_spv* pSpv_written);
//1.2ɾ������ 
BOOL DelTchNode(Node_tch* headp, char* Gonghao);
BOOL DelClsNode(Node_tch* headp, char* Xueqi, char* Gonghao, char* Mingcheng);
BOOL DelSpvNode(Node_tch* headp, char* Gonghao, char* Xueqi, char* Mingcheng, char* Riqi);
//1.3�޸ĺ��� 
BOOL ModifyTchNode(Node_tch* headp, char* Gonghao, Node_tch* pTch_written);
BOOL ModifyClsNode(Node_tch* headp, char* Xueqi, char* Gonghao, char* Mingcheng, Node_cls* pCls_written);
BOOL ModifySpvNode(Node_tch* headp, char* Gonghao, char* Xueqi, char* Mingcheng,
 					char* Riqi, Node_spv* pSpv_written);


//2��ѯ����
//<��ʦ>
Node_tch* SeekTchNode(Node_tch* headp, char* Gonghao); 		/*����ȷ��ѯ���Խ�ʦ���Ų�ѯ1��ʦ��Ϣ�ڵ�*/
Node_tch* SeekTchNode2(Node_tch* headp, char* Xingshi, char Zhicheng);	/*��ģ����ѯ����ѧ�ں�ѧʱ����ѯ1��ʦ��Ϣ�ڵ�*/
//<����>
Node_cls* SeekClsNode(Node_tch* headp, char* Xueqi, char* Gonghao, char* Mingcheng);	/*����ȷ��ѯ���Թ��źͿγ�����ѧ�ڲ�ѯ2������Ϣ�ڵ�*/
Node_cls* SeekClsNode2(Node_tch* hd, char* Xueqi, int cond_num,...);			
Node_cls* SeekClsNode2R(Node_tch* headp, char* xq, int sup, int inf);					/*��ģ����ѯ����ѧ�ں�ѧʱ����ѯ2������Ϣ�ڵ�*/
BOOL JudgeClsNodeItem(Node_cls* pcls_node, char* pcondition);
//<����>
Node_spv* SeekSpvNode(Node_tch* headp, char* Gonghao, char* Xueqi, char* Mingcheng, char* Riqi);	/*����ȷ��ѯ���Թ��źͿγ�����ѧ�ںͶ������ڲ�ѯ3������Ϣ�ڵ�*/
Node_spv* SeekSpvNode2(Node_tch* headp, char* Gonghao, char* Xueqi, int cond_num,...);		/*��ģ����ѯ����ѧ�ں�ѧ�����۲�ѯ2������Ϣ�ڵ�*/
BOOL JudgeSpv2NodeItem(Node_spv* pspv_node, char* pcondition);
//3ͳ�ƺ���

//<��ʦ>
STATISTIC1* StatTchNode(Node_tch* headp);	/*ͳ���ον�ʦ�Ŀγ���,ѧ����,ѧʱ��,�γ�������*/ 
void SortTchNode(STATISTIC1* hd);	
//<����>
STATISTIC2* StatClsNode(Node_tch* headp);	/*ͳ��ĳѧ��ÿ�ſγ̿���Ŀ��������������*/
STATISTIC2* searchstat(STATISTIC2* hd, char* Mingcheng);
void SortClsNode(STATISTIC2* hd);

//<����> 
STATISTIC3* StatSpvNode(Node_tch* headp);	/*ͳ��ĳ�ſγ�ÿ��ѧ�ڿ���Ŀ�����,��ʦְ��,����*/
int nodecmp(STATISTIC3* h1, STATISTIC3* h2);
void SortSpvNode(STATISTIC3* hd);
STATISTIC3* searchstatspv(STATISTIC3* hd, char* Xueqi);
//<����> 
STATISTIC4* StatPjNode(Node_tch* headp, int year);	/*ͳ��ĳ���ÿ����ʦ���ڵ����пγ̵�ѧ�������ۺϷ�ֵ*/
void SortPjNode(STATISTIC4* hd);




#endif
