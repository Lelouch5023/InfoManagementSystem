#include"information.h"

Node_tch* head=NULL;


int main()
{
	SetConsoleTitle(TITLE);

	int shuzi=CreatList(&head);
	printf("creatlist完成度%d \n",shuzi);
	SaveSysData(head);//调试
	int out;
	do{
		//初始化
		static int choice_main;
		choice_main = menu_start(welcome, Nwelcome);
		out = 0;


		//选择入口进入函数
		switch (choice_main)
		{
			case 1:
				out = shujuweihu(choice_main);		//数据维护
				SaveSysData(head);
				puts("数据已保存");
				break;
			case 2:
				out = shujuchaxun(choice_main);		//数据遍历查询
				SaveSysData(head);
				puts("数据已保存");
				break;
			case 3:
				out = shujutongji(choice_main);		//数据统计
				SaveSysData(head);
				puts("数据已保存");
				break;
			case 4:
				out = shujusousuo(choice_main);		//数据搜索
				SaveSysData(head);
				puts("数据已保存");
				break;
			default:
				out = 1;
		}

	}while(out==0);


	SaveSysData(head);
	puts("数据已保存");
	return 0;
}

////////////////////////////////////////////菜单界面函数//////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////菜单界面函数/////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * 函数名称: menu_start
 * 函数功能: 输出提示字符串并输入一个范围内的数，规范化数字后返回
 * 输入参数: 界面字符串及其个数
 * 输出参数: int 类型
 * 返 回 值: BOOL类型，总是为TRUE
 *
 * 调用说明:
 */

int  menu_start(const char s[][NUMOFCH], int n)
{
	int choice;
	int i;
	//清屏
	system("pause");
	system("cls");
	//界面
	puts(s[0]);
	for (i=1; i<n; i++)
		printf("%d.%s\n",i,s[i]);
		//输出样例：
		/*	puts("欢迎进入教师教学信息管理系统,请输入数字选择服务:");	*/
		/*	puts("1.数据维护");		*/
		/*	puts("2.数据查询");		*/
		/*	puts("3.数据统计");		*/
		/*	puts("4.显示全部数据");	*/

	//输入及检查输入
	while(1)
	{
		if (scanf("%d", &choice)!=1)
			continue;
		if (choice>=1 && choice<=n-1)
			break;
		else
			printf("输入有误！%d不是1-%d的数字，请再来一遍", choice, n-1);
	}
	return choice;
}



//1.	数据维护界面
int shujuweihu(int choice)
{
	int option=0;
	option = menu_start(maintain, Nmaintain);
	if (option==Nmaintain)
		return 1;	//退出

	switch (option){
		case 1:		//1.1数据录入
			shujuluru();
			break;
		case 2:		//1.2数据修改
			shujuxiugai();
			break;
		case 3:		//1.3数据删除
			shujushanchu();
			break;
	}


    SaveSysData(head);
	return 0;	//不从循环里跳出
}

//1.1	数据录入
void shujuluru(void)
{
	int luru;
	luru = menu_start(insert, Ninsert);
	switch (luru)
	{
		case 1:		//1.1.1教师信息录入
			jiaoshiluru();
			break;
		case 2:		//1.1.2课堂信息录入
			ketangluru();
			break;
		case 3:		//1.1.3督导信息录入
			dudaoluru();
			break;
	}

}

//1.1.1<录入>教师录入
void jiaoshiluru(void)
{
	Node_tch* ptchtmp=(Node_tch*)malloc(sizeof(Node_tch));

	puts("输入工号");
	scanf(" %s", ptchtmp->gonghao);
	if (SeekTchNode(head, ptchtmp->gonghao)!=NULL)
    {
        printf("该工号已存在！\n");
        return ;
    }
	puts("输入姓名");
	scanf(" %s", ptchtmp->xingming);
	puts("输入职称:'1'教授'2'副教授'3'讲师'4'助教");
	scanf("%d", &ptchtmp->zhicheng);

	if (InsertTchNode( ptchtmp)==TRUE)			/*这里必须调试*/
	{
		printf("录入成功!\r");
		Sleep(1500);
		printf("         \n");
	}
	else
	{
		printf("找不到该教师的课堂！%d\n",__LINE__);
	}

}
//1.1.2<录入>课堂录入
void ketangluru(void)
{
	Node_tch* pTch ;
	Node_cls* pclstmp = (Node_cls*)calloc(1, sizeof(Node_cls));

	//输入信息
	puts("输入任课教师工号");
	scanf("%s",pclstmp->gonghao);
	if ((pTch=SeekTchNode(head, pclstmp->gonghao))==NULL)
    {
        printf("该工号不存在！\n");
        return ;
    }
	puts("输入课堂学期");
	scanf(" %s", pclstmp->xueqi);
	puts("输入课堂名称");
	scanf(" %s", pclstmp->mingcheng);

	puts("输入课堂学分");
	scanf("%lf", &pclstmp->xuefen);
	puts("输入课堂学时");
	scanf("%d", &pclstmp->xueshi);
	puts("输入课堂班级");
	scanf(" %s", pclstmp->ketang);
	puts("输入课堂总人数");
	scanf("%d", &pclstmp->renshu);
	puts("输入课堂均分");
	scanf("%lf", &pclstmp->junfen);
	int i;
	for (i=4; i>=1; i--)
	{
		printf("请输入分数%d0分以上的人", i+5);
		scanf("%d", &pclstmp->GPA[i]);
	}	printf("请输入不及格的人数");
		scanf("%d", &pclstmp->GPA[i]);

	//插入节点
	if(InsertClsNode(head, pclstmp)==TRUE)
	{
		printf("录入成功!\r");
		Sleep(1500);
		printf("         \n");
	}
	else
	{
		printf("找不到该教师的课堂！%d",__LINE__);

	}
}
//1.1.3<录入>督导录入
void dudaoluru(void)
{
	Node_spv* pspvtmp = (Node_spv*)malloc(sizeof(Node_spv));
	//输入信息
	puts("输入教师工号");
	scanf("%s", pspvtmp->gonghao);
    if (SeekTchNode(head, pspvtmp->gonghao)==NULL)
    {
        printf("该工号不存在！\n");
        return ;
    }
	puts("输入课程名称");
	scanf("%s", pspvtmp->mingcheng);
	puts("输入督导课程学期");
	scanf("%s", pspvtmp->xueqi);
	if (SeekClsNode(head, pspvtmp->xueqi, pspvtmp->gonghao, pspvtmp->mingcheng)==NULL)
    {
        printf("该课程不存在！\n");
        return ;
    }
	puts("输入督导日期");
	scanf("%s", pspvtmp->riqi);
	puts("输入督导教师考勤 (%c)  A.准时 B.迟到");
	scanf(" %c", &pspvtmp->kaoqin);
	pspvtmp->kaoqin = toupper(pspvtmp->kaoqin);
	puts("输入督导到课人数");
	scanf("%d", &pspvtmp->daoke);
	puts("输入督导课堂效果(%c)   E.优秀 G.良好 M.中等 B.较差");
	scanf(" %c", &pspvtmp->xiaoguo);
	pspvtmp->xiaoguo = toupper(pspvtmp->xiaoguo);
	puts("输入督导学生评价分数");
	scanf("%d", &pspvtmp->pingjia);
	puts("输入督导教师工号(dudaogonghao)");
	scanf("%s", pspvtmp->dudaogonghao);
	//插入节点
	if(InsertSpvNode(head , pspvtmp)==TRUE)
	{
		printf("录入成功!\r");
		Sleep(1500);
		printf("         \n");
	}
	else
	{
		printf("找不到该督导！%d",__LINE__);
	}

}

//1.2数据修改
void shujuxiugai(void)
{
	int xiugai;
	xiugai = menu_start(modified, Nmodified);
	switch (xiugai)
	{
		case 1:		//1.1.1教师信息修改
			jiaoshixiugai();
			break;
		case 2:		//1.1.2课堂信息修改
			ketangxiugai();
			break;
		case 3:		//1.1.3督导信息修改
			dudaoxiugai();
			break;
	}

}

//1.2.1<修改>教师修改
void jiaoshixiugai(void)
{
	Node_tch* pTch;
	Node_tch* pTchtmp = (Node_tch*)calloc(1, sizeof(Node_tch));

	char gh[12];

	puts("请输入要修改的教师工号");
	scanf("%s", gh);
	pTch = SeekTchNode(head, gh);

	if (pTch!=NULL)
	{
		system("cls");
		puts("【当前信息】");
		printf("教师工号：%s\n", pTch->gonghao);
		printf("教师姓名：%s\n", pTch->xingming);
		printf("教师职称：%s\n", Job[pTch->zhicheng-1]);
	}
	else
	{
		printf("找不到该教师！line:%d\n",__LINE__);
		return ;
	}
	puts("【新的信息】");
	*pTchtmp = *pTch;							//调试

	puts("请输入新的教师姓名");
	scanf(" %s", pTchtmp->xingming);
	puts("请输入新的教师职称 (%c) 1.教授  2.副教授  3.讲师  4.助教");
	scanf(" %d", &pTchtmp->zhicheng);
    printf("ABOVE:%c  %d\n",pTchtmp->zhicheng,pTchtmp->zhicheng);

	*pTch = *pTchtmp;
}

//1.2.2<修改>课堂修改
void ketangxiugai(void)
{
	Node_cls Clstmp;
	Node_cls* pCls;

	char xq[10];
	char gh[12];
	char mc[30];

	puts("请输入教师工号");
	scanf("%s", gh);
	puts("请输入课堂名称");
	scanf("%s", mc);
	puts("请输入课程学期");
	scanf("%s", xq);

	pCls = SeekClsNode(head, xq, gh, mc);

	if (pCls!=NULL)
	{
		system("cls");					//提示旧的信息
		printf("【当前信息】\n");
		printf("课程名称：%s\n",pCls->mingcheng);
		printf("课程学期：%s\n",pCls->xueqi);
		printf("课程学分：%.1lf\n",pCls->xuefen);
		printf("课程学时：%d\n",pCls->xueshi);
		printf("课程课堂：%s\n",pCls->ketang);
		printf("课程人数：%d\n",pCls->renshu);
		puts("课程学生考试情况：");
		int i;
		for	(i=4; i>=1; i--){
			printf("课程%d分以上人数：%d\n",i*10+50,pCls->GPA[i]);
		}
		printf("课程不及格人数：%d\n",pCls->GPA[i]);
		printf("课程均分：%.1lf\n\n",pCls->junfen);

		printf("【新的信息】\n");		//输入新的信息
		Clstmp = *pCls;
		puts("请输入新的课程名称");
		scanf("%s", Clstmp.mingcheng);
		puts("请输入新的课程学期");
		scanf("%s", Clstmp.xueqi);
		puts("请输入新的课程学分");
		scanf("%lf", &Clstmp.xuefen);
		puts("请输入新的课程学时");
		scanf("%d", &Clstmp.xueshi);
		puts("请输入新的课程课堂");
		scanf("%s", Clstmp.ketang);
		puts("请输入新的课程课程人数");
		scanf("%d", &Clstmp.renshu);
		for	(i=4; i>=1; i--){
			printf("请输入课程%d分以上人数：\n",i*10+50);
			scanf("%d", &Clstmp.GPA[i]);
		}
		printf("请输入课程不及格人数：\n");
		scanf("%d", &Clstmp.GPA[i]);
        printf("请输入新的课程均分\n");
        scanf("%lf", &Clstmp.junfen);

		if ((ModifyClsNode(head, xq, gh, mc, &Clstmp))==TRUE)
		{
			printf("课堂信息修改成功！\n");
			/**此时还需要修改其子节点的信息*/
			Node_spv* pSpv;
			for (pSpv=pCls->spv; pSpv!=NULL; pSpv=pSpv->next)
            {
                strcpy(pSpv->mingcheng, Clstmp.mingcheng);
                strcpy(pSpv->xueqi, Clstmp.xueqi);
            }
            printf("课堂下的督导信息修改成功！\n");

		}
		else
		{
			printf("修改失败！ line:%d \n",__LINE__);
		}
	}
	else
	{
		printf("找不到该课堂！  line:%d\n",__LINE__);
	}


}
//1.2.3<修改>督导修改
void dudaoxiugai(void)
{
	Node_spv Spvtmp;
	Node_spv* pSpv;

	char gh[12];
	char xq[10];
	char mc[30];
	char rq[10];

	puts("请输入教师工号");
	scanf("%s", gh);
	puts("请输入课程学期");
	scanf("%s", xq);
	puts("请输入课程名称");
	scanf("%s", mc);
	puts("请输入督导日期");
	scanf("%s", rq);

	pSpv = SeekSpvNode(head, gh, xq, mc, rq);
	if (pSpv!=NULL)
	{
		system("cls");				//提示旧的信息
		printf("【当前信息】\n");
		printf("督导日期：%s\n", pSpv->riqi);
		printf("教师考勤：%s\n", kaoq[pSpv->kaoqin-'A']);
		printf("学生到课人数：%d\n", pSpv->daoke);
		printf("课堂效果：%s\n", pSpv->xiaoguo=='E'?"优":pSpv->xiaoguo=='G'?"良":pSpv->xiaoguo=='M'?"中":"差");
		printf("学生评价：%d\n", pSpv->pingjia);
		printf("督导教师工号：%s\n", pSpv->dudaogonghao);

		printf("【新的信息】\n");		//输入新的信息
		Spvtmp = *pSpv;
		puts("输入督导日期");
		scanf("%s", Spvtmp.riqi);
		puts("输入督导教师考勤 (%c)  A.准时 B.迟到");
		scanf(" %c", &Spvtmp.kaoqin);
		Spvtmp.kaoqin = toupper(Spvtmp.kaoqin);
		puts("输入督导到课人数");
		scanf("%d",&Spvtmp.daoke);
		puts("输入督导课堂效果(%c)   E.优秀 G.良好 M.中等 B.较差");
		scanf(" %c",&Spvtmp.xiaoguo);
		Spvtmp.xiaoguo = toupper(Spvtmp.xiaoguo);
		puts("输入督导学生评价分数");
		scanf("%d", &Spvtmp.pingjia);
		puts("输入督导教师工号(dudaogonghao)");
		scanf("%s", Spvtmp.dudaogonghao);

		if (ModifySpvNode(head, gh, xq, mc, rq, &Spvtmp)==TRUE)		//开始修改
		{
			printf("修改成功！ \n");
		}
		else
		{
			printf("修改失败！ line:%d \n",__LINE__);
		}

	}
	else
	{
		printf("找不到该督导信息！  line:%d \n",__LINE__);
	}

}


//1.3	数据删除
void shujushanchu(void)
{
	int shanchu;
	shanchu = menu_start(deleted, Ndeleted);
	switch (shanchu)
	{
		case 1:		//1.1.1教师信息删除
			jiaoshishanchu();
			break;
		case 2:		//1.1.2课堂信息删除
			ketangshanchu();
			break;
		case 3:		//1.1.3督导信息删除
			dudaoshanchu();
			break;
	}
	SaveSysData(head);

}

//1.3.1<删除>教师删除
void jiaoshishanchu(void)
{
	char gh[12];

	puts("请输入要删除的教师工号");
	scanf("%s", gh);

	if (DelTchNode(head, gh)==TRUE)
	{
		printf("删除成功！\n");
	}
	else
	{
		printf("删除失败！line:%d\n",__LINE__);
	}
}
//1.3.2<删除>课堂删除
void ketangshanchu(void)
{
	char gh[12];
	char xq[12];
	char mc[30];

	puts("请输入任课教师工号");
	scanf("%s", gh);
	puts("请输入课程名称");
	scanf("%s", mc);
	puts("请输入课程学期");
	scanf("%s", xq);

	if (DelClsNode(head, xq, gh, mc)==TRUE)
	{
		printf("删除成功！\n");
	}
	else
	{
		printf("删除失败！line:%d\n",__LINE__);
	}

}
//1.3.3<删除>督导删除
void dudaoshanchu(void)
{
	char gh[12];
	char xq[12];
	char mc[30];
	char rq[10];

	puts("请输入任课教师工号");
	scanf("%s", gh);
	puts("请输入课程名称");
	scanf("%s", mc);
	puts("请输入课程学期");
	scanf("%s", xq);
	puts("请输入督导日期");
	scanf("%s", rq);

	if (DelSpvNode(head, gh, xq, mc, rq)==TRUE)
	{
		printf("删除成功！\n");
	}
	else
	{
		printf("删除失败！line:%d\n",__LINE__);
	}
}


//2.数据遍历查询界面
int shujuchaxun(int choice)
{
	int option=0;
	option = menu_start(refer, Nrefer);
	if (option==Nrefer)
		return 1;	//退出

	switch(option){
		case 1:
			jiaoshichaxun();		// 教师遍历查询
			break;
		case 2:
			ketangchaxun();			//	课堂遍历查询
			break;
		case 3:
			dudaochaxun();			//	督导遍历查询
			break;
	}


	return 0;
}

//2.1
void jiaoshichaxun(void)
{
	Node_tch* p = head;
	SearchTch(p);
	system("pause");
}

//2.2
void ketangchaxun(void)
{
	Node_tch* p = head;
	SearchCls(p);
	system("pause");
}

//2.3
void dudaochaxun(void)
{
	Node_tch* p = head;
	SearchSpv(p);
	system("pause");
}




//3数据统计界面
int shujutongji(int choice)
{
    int option=0;
	option = menu_start(statqq, Nstatqq);
	if (option==Nstatqq)
		return 1;	//退出

	switch(option){
		case 1:
			jiaoshitongji();	//教师统计
			break;
		case 2:
			ketangtongji();		//课堂统计
			break;
		case 3:
			dudaotongji();		//督导统计
			break;
        case 4:
            pingjiatongji();	//评价统计
            break;
		default:
			return 0;
	}

	return 0;
}
//<统计>教师统计
void jiaoshitongji(void)
{
    STATISTIC1* hdp;

    hdp = StatTchNode(head);
    system("cls");
    printf("\t教师姓名\t学时数\t\t课程数\t\t学分数\t\t学生总数\n");
    while(hdp)
    {
        printf("\t%s\t\t%d\t\t%d\t\t%.4lf\t\t%d\n", hdp->jiaoshixingming, hdp->xueshishu, hdp->kechengshu,
                                            hdp->xuefenshu, hdp->zongrenshu);
        hdp = hdp->next;
    }

}
//<统计>课堂统计
void ketangtongji(void)
{
    STATISTIC2* hdp;

    hdp = StatClsNode(head);
    system("cls");
    printf("课程名称\t课堂数\t均分\t90-100\t80-89\t70-79\t60-69\t0-59\n");
    while (hdp)
    {
        printf("%s\t%d\t%.1lf\t%d\t%d\t%d\t%d\t%d\n", hdp->kechengmingcheng, hdp->ketangshu, hdp->junfen,
                        hdp->sGPA[4], hdp->sGPA[3], hdp->sGPA[2], hdp->sGPA[1], hdp->sGPA[0]);
       hdp = hdp->next;
    }

}
//<统计>督导统计
void dudaotongji(void)
{
    STATISTIC3* hdp;

    hdp = StatSpvNode(head);
    system("cls");
    printf("学期\t课堂数\t教授\t副教授\t讲师\t迟到数\n");
    while (hdp)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", hdp->xueqi, hdp->ketangshu, hdp->zhiwei[0], hdp->zhiwei[1], hdp->zhiwei[2],hdp->chidaoshu);
        hdp = hdp->next;
    }

}
//<统计>评价统计
void pingjiatongji(void)
{
    STATISTIC4* hdp;

    int year;

    puts("请输入你想统计的年度");
    scanf("%d", &year);

    hdp = StatPjNode(head, year);

    system("cls");
    printf("\t教师\t\t学生综合评价分值\n");
    while(hdp)
    {
        printf("\t%s\t\t%.1lf\n", hdp->jiaoshixingming, hdp->zonghepingjia);
        hdp = hdp->next;
    }
}



//4数据搜索界面
int shujusousuo(int choice)
{
	int option=0;
	option = menu_start(seekinfo, Nseekinfo);
	if (option==Nseekinfo)
		return 1;	//退出

	switch (option){
		case 1:		//搜索教师节点
			souTch1();
			break;
		case 2:		//搜索教师节点
			souTch2();
			break;
		case 3:		//搜索课堂节点
			souCls1();
			break;
		case 4:		//搜索课堂节点
			souCls2();
			break;
		case 5:		//搜索督导节点
			souSpv1();
			break;
		case 6:		//搜索督导节点
			souSpv2();
			break;
	}


	return 0;
}

//<搜索>教师节点1
void souTch1(void)
{
	Node_tch* pTch;

	char gh[12];

	puts("请输入要查询的教师工号");
	scanf("%s",gh);
	pTch = SeekTchNode(head, gh);

	if (pTch!=NULL)
	{
		system("cls");
		printf("教师姓名：%s\n",pTch->xingming);
		printf("教师职称：%s\n",Job[pTch->zhicheng-1]);
	}
	else
	{
		printf("找不到该教师！line:%d\n",__LINE__);
	}

}

//<搜索>教师节点2
void souTch2(void)
{
	Node_tch* pTch;

	char* xs = (char*)calloc(6, sizeof(char));
	char zc;

	puts("请输入教师的姓氏");
	scanf(" %s", xs);

	puts("请输入教师的职称(%d)：1.教授  2.副教授  3.讲师  4.助教");
	scanf("%d", &zc);

	pTch = SeekTchNode2(head, xs, zc);
	if (pTch!=NULL)
	{
		system("cls");
		printf("教师姓名：%s\n",pTch->xingming);
		printf("教师工号：%s\n",pTch->gonghao);
		printf("教师职称：%s\n",Job[pTch->zhicheng-1]);
		putchar('\n');
	}
	else
	{
		printf("找不到该教师！line:%d\n",__LINE__);
	}
	free(xs);
}

//<搜索>课堂节点1
void souCls1(void)
{
	Node_cls* pCls;
	char gh[12];
	char xq[10];
	char mc[30];

	puts("请输入教师工号");
	scanf("%s", gh);
	puts("请输入课堂名称");
	scanf("%s", mc);
	puts("请输入课堂学期");
	scanf("%s", xq);


	pCls = SeekClsNode(head, xq, gh, mc);
	if (pCls!=NULL)
	{
		system("cls");
		printf("【课堂名称】：%s\n", pCls->mingcheng);
		printf("任课教师工号：%s\n", pCls->gonghao);
		printf("学期：%s\n", pCls->xueqi);
		printf("学分：%.2lf\n", pCls->xuefen);
		printf("学时：%d\n", pCls->xueshi);
		printf("课堂：%s\n", pCls->ketang);
		printf("人数：%d\n", pCls->renshu);
		puts("课程学生考试情况：");
		int i;
		for	(i=4; i>=1; i--){
			printf("课程%d分以上人数：%d\n",i*10+50,pCls->GPA[i]);
		}
		printf("课程不及格人数：%d\n",pCls->GPA[i]);
		printf("课程均分：%.1lf\n\n",pCls->junfen);
	}
	else
	{
		printf("找不到该课堂！line:%d\n",__LINE__);
	}

}

//<搜索>课堂节点2
void souCls2(void)
{
	Node_cls* pCls;

	char xq[10];
	int i;
	int inf;
	int sup;

	puts("请输入学期：");
	scanf("%s", xq);

	puts("请输入学时的上界");
	scanf("%d", &sup);
	puts("请输入学时的下界");
	scanf("%d", &inf);

	pCls = SeekClsNode2R(head, xq, sup, inf);
	if (pCls!=NULL)
	{
	    system("cls");
		for (; pCls!=NULL; pCls=pCls->next)
        {

            printf("【课堂名称】：%s\n", pCls->mingcheng);
            printf("任课教师工号：%s\n", pCls->gonghao);
            printf("学期：%s\n", pCls->xueqi);
            printf("学分：%.2lf\n", pCls->xuefen);
            printf("学时：%d\n", pCls->xueshi);
            printf("课堂：%s\n", pCls->ketang);
            printf("人数：%d\n", pCls->renshu);
            puts("课程学生考试情况：");
            int i;
            for	(i=4; i>=1; i--)
            {
                printf("课程%d分以上人数：%d\n",i*10+50, pCls->GPA[i]);
            }
            printf("课程不及格人数：%d\n", pCls->GPA[i]);
            printf("课程均分：%.1lf\n\n", pCls->junfen);
        }
	}
	else
	{
		printf("找不到该课堂！line:%d\n",__LINE__);
	}
}

//<搜索>课堂节点2
Node_cls* SeekClsNode2R(Node_tch* headp, char* xq, int sup, int inf)
{
	Node_tch* pTch;
	Node_cls* pCls;
	Node_cls* pClsr = NULL;
	Node_cls* pClsc = NULL;

	for (pTch=headp; pTch!=NULL; pTch=pTch->next)
	{
		for (pCls=pTch->cls; pCls!=NULL; pCls=pCls->next)
		{
			if (strcmp(pCls->xueqi, xq)!=0)
				continue;
			if (pCls->xueshi<=sup && pCls->xueshi>=inf)
			{
				pClsc = (Node_cls*)calloc(1, sizeof(Node_cls));
				*pClsc = *pCls;
				pClsc->next = pClsr;
				pClsr = pClsc;
			}

		}

	}

	return pClsc;
}

//<搜索>督导节点1
void souSpv1(void)
{
	Node_spv* pSpv;

	char gh[12];
	char xq[10];
	char mc[30];
	char rq[10];

	puts("请输入教师工号");
	scanf("%s", gh);
	puts("请输入课程名称");
	scanf("%s", mc);
	puts("请输入学期");
	scanf("%s", xq);
	puts("请输入日期");
	scanf("%s", rq);

	pSpv = SeekSpvNode(head, gh, xq, mc, rq);
	if (pSpv !=NULL)
	{
		printf("教师考勤：%s\n",kaoq[pSpv->kaoqin-'A']);
		printf("学生到课人数：%d\n",pSpv->daoke);
		printf("课堂效果：%s\n",pSpv->xiaoguo=='E'?"优":pSpv->xiaoguo=='G'?"良":pSpv->xiaoguo=='M'?"中":"差");
		printf("学生评价：%d\n",pSpv->pingjia);
		printf("督导教师工号：%s\n",pSpv->dudaogonghao);
	}
	else
	{
		printf("找不到该督导信息！line:%d\n",__LINE__);
	}

}

//<搜索>督导节点2
void souSpv2(void)
{
	Node_tch* pTch;
	Node_cls* pCls;
	Node_spv* pSpv;
	Node_spv* pSpvc = NULL;
	Node_spv* pSpvr = NULL;
	char gh[12];
	char xq[12];
	int inf;
	int sup;

	while (TRUE)
	{
		puts("请输入教师工号");
		scanf("%s", gh);
		pTch = SeekTchNode(head, gh);
		if (pTch!=NULL)
			break;
		else
			puts("工号不存在！重新输入！");
	}

	pCls = pTch->cls;
	if (pCls!=NULL)
	{

	puts("请输入学生评价的上界");
	scanf("%d", &sup);
	puts("请输入学生评价的下界");
	scanf("%d", &inf);

	for (;pCls!=NULL;pCls=pCls->next)
	{
		for (pSpv=pCls->spv ;pSpv!=NULL ;pSpv=pSpv->next)
		{
			if (pSpv->pingjia<=sup && pSpv->pingjia>=inf)
			{
				pSpvc = (Node_spv*)calloc(1, sizeof(Node_spv));
				*pSpvc = *pSpv;
				pSpvc->next = pSpvr;
				pSpvr = pSpvc;
			}
		}
	}

	}
	while(pSpvc)
	{
	    printf("【督导日期】%s\n", pSpvc->riqi);
		printf("教师考勤：%s\n",kaoq[pSpvc->kaoqin-'A']);
		printf("学生到课人数：%d\n",pSpvc->daoke);
		printf("课堂效果：%s\n",pSpvc->xiaoguo=='E'?"优":pSpvc->xiaoguo=='G'?"良":pSpvc->xiaoguo=='M'?"中":"差");
		printf("学生评价：%d\n",pSpvc->pingjia);
		printf("督导教师工号：%s\n\n",pSpvc->dudaogonghao);

		pSpvc = pSpvc->next;
	}


}

//<遍历>输出教师信息节点
void SearchTch(Node_tch* pTch)
{
	int i;

	if (pTch!=NULL)
	{
		for (i=0; pTch!=NULL; pTch = pTch->next)
		{
			printf("【第%d个信息】\n",++i);
			printf("教师工号:%s\n",pTch->gonghao);
			printf("教师姓名:%s\n",pTch->xingming);
			printf("教师职称:%s\n",Job[pTch->zhicheng-1]);
		}
	}
	else
		printf("没有数据\t%s",__func__);


}

//<遍历>输出课堂信息节点
void SearchCls(Node_tch* hd)
{
	Node_tch* pTch;
	Node_cls* pCls;
	char gh[12];
	int i = 0;
	puts("你想查询哪位教师的全部课堂信息？请输入其工号:");
	scanf("%s",gh);
	pTch = SeekTchNode(hd, gh);
	if (pTch!=NULL && pTch->cls!=NULL)
	{
		pCls = pTch->cls;
		while (pCls!=NULL)
		{
			puts("");
			printf("【第%d个信息】\n",++i);
			printf("课程名称：%s\n",pCls->mingcheng);
			printf("课程学期：%s\n",pCls->xueqi);
			printf("课程学分：%.1lf\n",pCls->xuefen);
			printf("课程学时：%d\n",pCls->xueshi);
			printf("课程课堂：%s\n",pCls->ketang);
			printf("课程人数：%d\n",pCls->renshu);
			puts("课程学生考试情况：");
			int i;
			for	(i=4; i>=1; i--){
				printf("课程%d分以上人数：%d\n",i*10+50,pCls->GPA[i]);
			}
			printf("课程不及格人数：%d\n",pCls->GPA[i]);
			printf("课程均分：%.1lf\n\n",pCls->junfen);
			pCls = pCls->next;
		}
	}
	else
		printf("找不到或没有数据%d\t%s",__LINE__,__func__);

}

//<遍历>输出督导信息节点
void SearchSpv(Node_tch* hd)
{
	Node_cls* pCls;
	Node_spv* pSpv;
	puts("你想查询哪个课堂的全部督导信息？");
	char* xueqi_tmp = (char*)calloc(10, sizeof(char));
	char* gonghao_tmp = (char*)calloc(12, sizeof(char));
	char* mingcheng_tmp = (char*)calloc(30, sizeof(char));

	puts("请输入教师工号");
	scanf(" %s",gonghao_tmp);
	puts("请输入课程学期");
	scanf(" %s",xueqi_tmp);
	puts("请输入课程名称");
	scanf(" %s",mingcheng_tmp);

	pCls = SeekClsNode(hd, xueqi_tmp, gonghao_tmp, mingcheng_tmp);
	if (pCls!=NULL && pCls->spv!=NULL)
	{
		pSpv = pCls->spv;
		while (pSpv!=NULL)
		{
			puts("");
			printf("【督导日期】：%s\n", pSpv->riqi);
			printf("教师考勤：%s\n", kaoq[pSpv->kaoqin-'A']);
			printf("学生到课人数：%d\n", pSpv->daoke);
			printf("课堂效果：%s\n", pSpv->xiaoguo=='E'?"优":pSpv->xiaoguo=='G'?"良":pSpv->xiaoguo=='M'?"中":"差");
			printf("学生评价：%d\n", pSpv->pingjia);
			printf("督导教师工号：%s\n", pSpv->dudaogonghao);

			pSpv = pSpv->next;
		}

	}
	else
		printf("找不到\tline:%s  %d\n",__func__,__LINE__);

	free(xueqi_tmp);
	free(gonghao_tmp);
	free(mingcheng_tmp);
}
////////////////////////////////////////////以上是菜单界面函数//////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////以上是菜单界面函数///////////////////////////////////////////////////////////////////////////////////











////////////////////////////////////////////以下是功能函数//////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////以下是功能函数///////////////////////////////////////////////////////////////////////////////////



/**
 * 函数名称: CreateList
 * 函数功能: 从数据文件读取基础数据, 并存放到所创建的十字链表中.
 * 输入参数: 无
 * 输出参数: phead 主链头指针的地址, 用来返回所创建的十字链.
 * 返 回 值: int型数值, 表示链表创建的情况.
 *           0  空链, 无数据
 *           4  已加载宿舍楼信息数据，无学生基本信息和缴费信息数据
 *      4+8==12 已加载宿舍楼信息和学生基本信息数据，无缴费信息数据
 *   4+8+16==28 三类基础数据都已加载
 *
 * 调用说明:

 */


int CreatList(Node_tch **phead)
{
    Node_tch *hd = NULL, *pTch;
    Node_cls *pCls;
    Node_spv *pSpv;
    FILE *pFile1;
    FILE *pFile2;
    FILE *pFile3;

    int find = 0;
    int ret = 0;		/*初始完成度*/

    while ((pFile1 = fopen(info_tch, "rb")) == NULL)
    {
        printf("教师信息数据文件打开失败!正在重新创建...\n");
        if ((pFile1 = fopen(info_tch, "wb+"))==NULL){
			printf("教师信息数据文件创建失败!\n");
        	exit(1);
        }
        printf("创建成功!\n");
        fclose(pFile1);
    }
    printf("教师信息数据文件打开成功!\n");

    while ((pFile2 = fopen(info_cls, "rb")) == NULL)
    {
        printf("课堂信息数据文件打开失败!正在重新创建...\n");
        if ((pFile2 = fopen(info_cls, "wb+"))==NULL){
			printf("课堂信息数据文件创建失败!\n");
        	exit(1);
        }
        printf("创建成功!\n");
        fclose(pFile2);
    }
    printf("课堂信息数据文件打开成功!\n");

	while ((pFile3 = fopen(info_spv, "rb")) == NULL)
    {
        printf("督导信息数据文件打开失败!正在重新创建...\n");
        if ((pFile3 = fopen(info_spv, "wb+"))==NULL){
			printf("督导信息数据文件创建失败!\n");
        	exit(1);
        }
        printf("创建成功!\n");
        fclose(pFile3);
    }
    printf("督导信息数据文件打开成功!\n");

    /*从数据文件中读宿舍楼信息数据，存入以后进先出方式建立的主链中*/
    while (!feof(pFile1))
    {
        pTch = (Node_tch *)calloc(1, sizeof(Node_tch));
        fread(pTch, sizeof(Node_tch), 1, pFile1);
        if (*pTch->gonghao == bug)
        {
        	free(pTch);
        	continue;
        }
        pTch->cls = NULL;
        pTch->next = hd;
        hd = pTch;
    }
    fclose(pFile1);
    if (hd == NULL)
    {
		hd=(Node_tch*)calloc(1, sizeof(Node_tch));
		hd->cls=(Node_cls*)calloc(1, sizeof(Node_cls));
		hd->cls->spv=(Node_spv*)calloc(1, sizeof(Node_spv));
		hd->next=NULL;
		hd->cls->next=NULL;
		hd->cls->spv->next=NULL;
    }
    printf("教师信息数据文件加载成功!\n");
    *phead = hd;		/*输出参数赋值*/
    ret += 4;  /**/


    /*从数据文件中读取教师基本信息数据，存入主链对应结点的学生基本信息支链中*/
    while (!feof(pFile2))
    {
        /*创建结点，存放从数据文件中读出的教师基本信息*/
        pCls = (Node_cls *)calloc(1, sizeof(Node_cls));
        fread(pCls, sizeof(Node_cls), 1, pFile2);
        pCls->spv = NULL;

        /*在主链上查找该教师所教授课堂对应的主链结点*/
        pTch = hd;
        while (pTch != NULL
               && strcmp(pTch->gonghao, pCls->gonghao) != 0)
        {
            pTch = pTch->next;
        }
        if (pTch != NULL) /*如果找到，则将结点以后进先出方式插入教师信息支链*/
        {
            pCls->next = pTch->cls;
            pTch->cls = pCls;
        }
        else  /*如果未找到，则释放所创建结点的内存空间*/
        {
            free(pCls);
        }
    }
    fclose(pFile2);
	ret += 8;   /**/
	printf("课堂信息数据文件加载成功!\n");

    /*从数据文件中读取学生缴费信息数据，存入教师基本信息支链对应结点的缴费支链中*/
    while (!feof(pFile3))
    {
        /*创建结点，存放从数据文件中读出督导信息*/
        pSpv = (Node_spv *)calloc(1, sizeof(Node_spv));
		fread(pSpv, sizeof(Node_spv), 1, pFile3);

        /*查找教师信息支链上对应督导结点*/
        pTch = hd;
        find = 0;
        for (;pTch != NULL && find == 0; pTch = pTch->next)
        {
            for (pCls = pTch->cls; pCls != NULL && find == 0; pCls = pCls->next)
            {
                if (strcmp(pCls->gonghao, pSpv->gonghao) == 0 && strcmp(pCls->mingcheng, pSpv->mingcheng)==0
                    && strcmp(pCls->xueqi, pSpv->xueqi)==0)
                {
                    find = 1;
                    break;
                }
            }
        }
        if (find)  /*如果找到，则将结点以后进先出方式插入课堂信息支链中*/
        {
            pSpv->next = pCls->spv;
            pCls->spv = pSpv;
        }
        else /*如果未找到，则释放所创建结点的内存空间*/
        {
            free(pSpv);
        }
    }
    fclose(pFile3);
	ret += 16;   /**/
	printf("督导信息数据文件加载成功!\n");

    return ret;
}




/**
 * 函数名称: SaveSysData
 * 函数功能: 保存三向十字链表的三类数据
 * 输入参数: hd主链头结点
 * 输出参数: 无
 * 返 回 值: BOOL类型，总是为TRUE
 *
 * 调用说明:
 */

BOOL SaveSysData(Node_tch* hd)
{
	FILE* pfile1 ;
	FILE* pfile2 ;
	FILE* pfile3 ;
	Node_tch* pTch ;
	Node_cls* pCls ;
	Node_spv* pSpv ;

	/******hd==NULL的时候作说明*******/
	if (hd==NULL){
		printf("BUG! hd==NULL when saving data! %d\n",__LINE__);
		exit(3);
	}

	if ((pfile1 = fopen(info_tch,"wb+"))==NULL)
		printf("打开操作失败！\t%s\t%d\n",__func__,__LINE__);

	if ((pfile2 = fopen(info_cls,"wb+"))==NULL)
		printf("打开操作失败！\t%s\t%d\n",__func__,__LINE__);

	if ((pfile3 = fopen(info_spv,"wb+"))==NULL)
		printf("打开操作失败！\t%s\t%d\n",__func__,__LINE__);


	//教师节点写操作
	for (pTch=hd; pTch!=NULL; pTch=pTch->next)
	{
		//写一级节点
		fwrite(pTch, sizeof(Node_tch), 1, pfile1);

		//课堂节点写操作
		for (pCls=pTch->cls; pCls!=NULL; pCls=pCls->next)
		{
			//写二级节点
			fwrite(pCls, sizeof(Node_cls), 1, pfile2);

			//督导节点写操作:
			for(pSpv=pCls->spv; pSpv!=NULL; pSpv=pSpv->next)
			{
				//写三级节点
				fwrite(pSpv, sizeof(Node_spv), 1, pfile3);
			}

		}


	}

	//写完一级节点关闭
	if (fclose(pfile1)==EOF)
		printf("关闭写操作失败！line:%s\t%d\n",__func__,__LINE__);
	//写完二级节点关闭
	if ((fclose(pfile2))==EOF)
		printf("关闭写操作失败！line:%s\t%d\n",__func__,__LINE__);
	//写完三级节点关闭
	if ((fclose(pfile3))==EOF)
		printf("关闭写操作失败！line:%s\t%d\n",__func__,__LINE__);


	return TRUE;
}



////1录入修改删除函数


//(教师)

/**
 * 函数名称: InsertTchNode
 * 函数功能: 插入教师节点
 * 输入参数: 已写的教师节点
 * 输出参数: 无
 * 返 回 值: BOOL类型，成功插入为TRUE，失败为FALSE
 *
 * 调用说明:
 */

BOOL InsertTchNode(Node_tch* pTch_written)
{
	if (pTch_written!=NULL)
	{
		pTch_written->next = head;
		head = pTch_written;
		head->cls = NULL;		//调试！！
		printf("录入成功！%s\t%d",__func__,__LINE__);
		return TRUE;
	}
	printf("录入失败！%s\t%d",__func__,__LINE__);
	return FALSE;
}


/**
 * 函数名称: DelTchNode
 * 函数功能: 删除教师节点
 * 输入参数: 教师节点的开头， 要删除教师的工号
 * 输出参数: 无
 * 返 回 值: BOOL类型，成功删除为TRUE，失败为FALSE
 *
 * 调用说明:
*/

BOOL DelTchNode(Node_tch* headp, char* Gonghao)
{
	BOOL bRet = FALSE;
	Node_tch* pTch_current = headp;
	Node_tch* pTch_prior = NULL;
	int find=0;
	while (pTch_current!=NULL)	//找到工号所对应的教师节点
	{
		if (strcmp(pTch_current->gonghao, Gonghao)==0)
		{
			find=1;
			break;
		}

		pTch_prior=pTch_current;
		pTch_current=pTch_current->next;
	}

	if (pTch_prior!=NULL)		//如果要删除的节点是不第一个节点，让前一个节点指向当前节点的后一个节点
		pTch_prior->next = pTch_current->next;
	else						//如果要删除的节点是第一个节点，让头指针指向当前节点的后一个节点
		headp = pTch_current->next;

	free(pTch_current);

	if (find==1)
		bRet=TRUE;
	return bRet;
}

/**
 * 函数名称: ModifyTchNode
 * 函数功能: 修改教师节点
 * 输入参数: 教师节点的开头， 要修改教师的工号 ，已写的修改教师节点
 * 输出参数: 无
 * 返 回 值: BOOL类型，成功修改为TRUE，失败为FALSE
 *
 * 调用说明:
 */

BOOL ModifyTchNode(Node_tch* headp, char* Gonghao, Node_tch* pTch_written)
{
	Node_tch* pTch;
	pTch = SeekTchNode(headp, Gonghao);
	if (pTch!=NULL)
	{
		pTch_written->next = pTch->next;
		*pTch = *pTch_written;
		return TRUE;
	}

	return FALSE;
}

//（课堂）
/**
 * 函数名称: InsertClsNode
 * 函数功能: 插入课堂节点
 * 输入参数: 教师头结点，已写的课堂节点
 * 输出参数: 无
 * 返 回 值: BOOL类型，成功插入为TRUE，失败为FALSE
 *
 * 调用说明:
*/

BOOL InsertClsNode(Node_tch* hd, Node_cls* pCls_written)
{
	int find = 0;
	BOOL bRet = FALSE;
	hd = SeekTchNode(hd, pCls_written->gonghao);	//先找到对应的教师节点
	//后进先出的插入
	pCls_written->next = hd->cls;
	pCls_written->spv = NULL;
	hd->cls = pCls_written;
	if (hd!=NULL && hd->cls!=NULL)
		find = 1;
	if (find==1)
		bRet=TRUE;
	return bRet;
}

/**
 * 函数名称: DelClsNode
 * 函数功能: 删除课堂节点
 * 输入参数: 教师节点的开头， 课堂学期，要删除课堂对应教师的工号 ，课堂名称
 * 输出参数: 无
 * 返 回 值: BOOL类型，成功删除为TRUE，失败为FALSE
 *
 * 调用说明:
*/

BOOL DelClsNode(Node_tch* headp, char* Xueqi, char* Gonghao, char* Mingcheng)
{
	int find=0;
	BOOL bRet=FALSE;
	Node_tch* pTch;
	Node_cls* pCls_current;
	Node_cls* pCls_prior;

	pTch=SeekTchNode(headp, Gonghao);
	pCls_current=pTch->cls;
	pCls_prior=NULL;
	while (pCls_current!=NULL)
	{
		if (strcmp(pCls_current->xueqi, Xueqi)==0
		&& strcmp(pCls_current->mingcheng, Mingcheng)==0)
		{
			find=1;
			break;
		}
		pCls_prior=pCls_current;
		pCls_current=pCls_current->next;
	}
	if (find==1)
	{
		if (pCls_prior==NULL)
			pTch->cls=pCls_current->next;
		else
			pCls_prior->next=pCls_current->next;

		bRet=TRUE;
		free(pCls_current);
	}

	return bRet;
}

/**
 * 函数名称: ModifyClsNode
 * 函数功能: 修改课堂节点
 * 输入参数: 教师节点的开头，课堂学期，要修改教师的工号 ，课堂名称，已写的修改课堂节点
 * 输出参数: 无
 * 返 回 值: BOOL类型，成功修改为TRUE，失败为FALSE
 *
 * 调用说明:
 */

BOOL ModifyClsNode(Node_tch* headp, char* Xueqi, char* Gonghao, char* Mingcheng, Node_cls* pCls_written)
{
	Node_cls* pCls;
	pCls = SeekClsNode(headp, Xueqi, Gonghao, Mingcheng);
	if (pCls!=NULL)
	{
		pCls_written->next = pCls->next;
		*pCls = *pCls_written;
		return TRUE;
	}
	return FALSE;
}

//(督导)

/**
 * 函数名称: InsertSpvNode
 * 函数功能: 插入督导节点
 * 输入参数: 教师头结点，已写的督导节点
 * 输出参数: 无
 * 返 回 值: BOOL类型，成功插入为TRUE，失败为FALSE
 *
 * 调用说明:
*/

BOOL InsertSpvNode(Node_tch* hd, Node_spv* pSpv_written)
{
	Node_cls* pCls;
	pCls = SeekClsNode(hd, pSpv_written->xueqi, pSpv_written->gonghao, pSpv_written->mingcheng);
	//后进先出插入节点
	if (pCls!=NULL)
	{
		pSpv_written->next = pCls->spv;
		pCls->spv = pSpv_written;
		return TRUE;
	}
	return FALSE;
}

/**
 * 函数名称: DelSpvNode
 * 函数功能: 删除督导节点
 * 输入参数: 教师节点的开头，要删除课堂对应教师的工号 ，课堂学期，课堂名称，督导日期
 * 输出参数: 无
 * 返 回 值: BOOL类型，成功删除为TRUE，失败为FALSE
 *
 * 调用说明:
*/
BOOL DelSpvNode(Node_tch* headp, char* Gonghao, char* Xueqi, char* Mingcheng, char* Riqi)
{
	int find=0;
	Node_cls* pCls;
	Node_spv* pSpv_prior;
	Node_spv* pSpv_current;
	BOOL bRet=FALSE;

	//
	pCls=SeekClsNode(headp, Xueqi, Gonghao, Mingcheng);
	//
	pSpv_current=pCls->spv;
	pSpv_prior=NULL;
	while (pSpv_current!=NULL ){
		if (strcmp(pSpv_current->riqi, Riqi)==0)
		{
			find=1;
			break;
		}
		pSpv_prior = pSpv_current;
		pSpv_current = pSpv_current->next;
	}

	if (find==1)
	{
		if (pSpv_prior==NULL)//如果该督导节点是课堂第一个节点
			pCls->spv=pSpv_current->next;//课堂接上后一个督导节点
		else
			pSpv_prior->next=pSpv_current->next;//如果该督导节点不是课堂第一个节点，就让上一个督导节点接上下一个督导节点

		bRet = TRUE;
		free(pSpv_current);
	}
	return bRet;
}

/**
 * 函数名称: ModifySpvNode
 * 函数功能: 修改督导节点
 * 输入参数: 教师节点的开头，要修改教师的工号 ，课堂学期，课堂名称，督导日期，已写的修改督导节点
 * 输出参数: 无
 * 返 回 值: BOOL类型，成功修改为TRUE，失败为FALSE
 *
 * 调用说明:
 */

BOOL ModifySpvNode(Node_tch* headp, char* Gonghao, char* Xueqi, char* Mingcheng, char* Riqi, Node_spv* pSpv_written)
{
	Node_spv* pSpv;
	pSpv = SeekSpvNode(headp, Gonghao, Xueqi, Mingcheng, Riqi);
	if (pSpv!=NULL)
	{
		pSpv_written->next = pSpv->next;
		*pSpv = *pSpv_written;
		return TRUE;
	}
		return FALSE;
}



////2查询函数

/**
 * 函数名称: SeekTchNode
 * 函数功能: 从十字链表中找到和工号相同的教师信息节点指针并返回
 * 输入参数: 头结点指针headp, 教师工号Gonghao
 * 输出参数: 无
 * 返 回 值: 如果找到节点，则返回指向该节点的指针，否则返回NULL

 *
 * 调用说明: 以工号查询
 */


//(教师)
Node_tch* SeekTchNode(Node_tch* headp, char* Gonghao)
{
	int find=0;
	while (headp != NULL)
	{
		if (strcmp(headp->gonghao, Gonghao)==0)
		{
			find=1;
			break;
		}
		headp=headp->next;
	}

	if (find==0)
		return NULL;
	return headp;
}



/**
 * 函数名称: SeekTchNode2
 * 函数功能: 从十字链表中找到满足条件的教师信息节点指针并返回
 * 输入参数: 头结点指针headp, 教师姓氏， 教师职称
 * 输出参数: 无
 * 返 回 值: 如果找到节点，则返回指向该节点的指针，否则返回NULL

 *
 * 调用说明:以教师姓氏和职称模糊查询
 */

Node_tch* SeekTchNode2(Node_tch* headp, char* Xingshi, char Zhicheng)
{
	int find=0;
	for ( ; headp!=NULL; headp=headp->next)
	{
		if (strstr(headp->xingming, Xingshi)!=NULL && headp->zhicheng==Zhicheng)
		{
				find=1;
				break;
		}

	}

	if (find==0)
		return NULL;
	return headp;
}


//（课堂）

/**
 * 函数名称: SeekClsNode
 * 函数功能: 从十字链表中找到和工号，学期，课堂名称相同的课堂信息节点指针并返回
 * 输入参数: 头结点指针headp, 工号，学期，课堂名称
 * 输出参数: 无
 * 返 回 值: 如果找到节点，则返回指向该节点的指针，否则返回NULL

 *
 * 调用说明: 以工号，学期，课堂名称查询
 */

Node_cls* SeekClsNode(Node_tch* headp, char* Xueqi, char* Gonghao, char* Mingcheng)
{
	int find=0;
	Node_tch* pTch = SeekTchNode(headp, Gonghao);
	Node_cls* pCls = pTch->cls;

	while (pCls!=NULL)
	{
		if (strcmp(pCls->mingcheng, Mingcheng)==0 && strcmp(pCls->xueqi, Xueqi)==0)
		{
			find=1;
			break;
		}
		pCls = pCls->next;
	}

	if (find==0){
		printf("find==0, line:%d \n",__LINE__);
		return NULL;
	}
	return pCls;
}

/**
 * 函数名称: SeekClsNode2
 * 函数功能: 从十字链表中找到满足条件的课堂信息节点指针并返回
 * 输入参数: 头结点指针headp, 课堂学期
 * 输出参数: 无
 * 返 回 值: 如果找到节点，则返回指向该节点的指针，否则返回NULL

 *
 * 调用说明:模糊查询
 */

Node_cls* SeekClsNode2(Node_tch* hd, char* Xueqi, int cond_num, ...)
{
	Node_tch* pTch;
	Node_cls* pCls;
	Node_cls* pCls_ret = NULL;
	Node_cls* pCls_tmp = NULL;
	char* pcTemp;
	char* condition[cond_num];
	int i;
	int find=0;
	va_list ap;
	va_start(ap, cond_num);
	for (i=0; i<cond_num; i++)
	{
		pcTemp = va_arg(ap, char*);
		condition[i] = (char*)calloc(1, strlen(pcTemp)+1);
		strcpy(condition[i], pcTemp);
	}
	va_end(ap);

	for (pTch=hd; pTch!=NULL; pTch=pTch->next)
	{
		for (pCls=pTch->cls; pCls!=NULL; pCls=pCls->next)
        {
        	if (strcmp(pCls->xueqi, Xueqi)!=0)
        		continue;
            for (i=0; i<cond_num; i++)
            {
                if (JudgeClsNodeItem(pCls, condition[i])==FALSE)
                    break;
            }

            if (i==cond_num)
            {
                find=1;		//
                pCls_tmp = (Node_cls *)calloc(1, sizeof(Node_cls));
                *pCls_tmp = *pCls;
                pCls_tmp->next = pCls_ret;
                pCls_ret = pCls_tmp;
            }

        }
	}

	if (find==0)
		return NULL;
	return pCls_ret;
}

BOOL JudgeClsNodeItem(Node_cls* pcls_node, char* pcondition)
{
	int item_num = *pcondition;
	BOOL bRet = FALSE;
	switch (item_num)
	{
		case '!':
			bRet = (atoi(pcondition+1)!=pcls_node->xueshi);
			break;
		case '=':
			bRet = (atoi(pcondition+1)==pcls_node->xueshi);
			break;
		case '>':
			bRet = (atoi(pcondition+1)>=pcls_node->xueshi);
			break;
		case '<':
			bRet = (atoi(pcondition+1)<=pcls_node->xueshi);
			break;
	}

	return bRet;
}



//（督导）
/**
 * 函数名称: SeekSpvNode
 * 函数功能: 从十字链表中找到满足条件的督导信息节点指针并返回
 * 输入参数: 头结点指针headp, 教师工号, 课堂学期, 课堂名称，督导日期
 * 输出参数: 无
 * 返 回 值: 如果找到节点，则返回指向该节点的指针，否则返回NULL

 *
 * 调用说明: 以教师工号, 课堂学期, 课堂名称，督导日期查询
 */

Node_spv* SeekSpvNode(Node_tch* headp, char* Gonghao, char* Xueqi, char* Mingcheng, char* Riqi)
{
	int find=0;
	Node_spv* pSpv;
	Node_cls* pCls = SeekClsNode(headp, Xueqi, Gonghao, Mingcheng);
	if (pCls!=NULL){
		pSpv = pCls->spv;
		while (pSpv!=NULL)
		{
			if (strcmp(pSpv->riqi, Riqi)==0)
			{
				find=1;
				break;
			}
			pSpv = pSpv->next;
		}
	}

	if (find==0)
		return NULL;
	return pSpv;
}


/**
 * 函数名称: SeekSpvNode
 * 函数功能: 从十字链表中找到满足条件的督导信息节点指针并返回
 * 输入参数: 头结点指针headp, 教师工号, 课堂学期, 学时条件
 * 输出参数: 无
 * 返 回 值: 如果找到节点，则返回指向该节点的指针，否则返回NULL

 *
 * 调用说明: 以教师工号, 课堂学期, 学时条件 查询
 */

Node_spv* SeekSpvNode2(Node_tch* headp, char* Gonghao, char* Xueqi,int cond_num,...)
{
	int find=0;
	char* pcTemp;
	char* condition[cond_num];
	int i;
	Node_spv* pSpv;
	Node_spv* pSpv_tmp;
	Node_spv* pSpv_ret;
	Node_cls* pCls;

	va_list ap;
	va_start(ap, cond_num);
	for (i=0; i<cond_num; i++)
	{
		pcTemp = va_arg(ap, char*);
		condition[i] = (char*)calloc(1, strlen(pcTemp)+1);
		strcpy(condition[i], pcTemp);
	}
	va_end(ap);

	//
	Node_tch* pTch = SeekTchNode(headp, Gonghao);
	//
	if (pTch!=NULL)
		pCls = pTch->cls;

	while (pCls!=NULL)
	{
		if (strcmp(pCls->xueqi, Xueqi)==0)
			break;
		pCls=pCls->next;
	}
	//
	if (pCls!=NULL)
        pSpv = pCls->spv;
	while (pSpv!=NULL)
	{
		////
		for (i=0; i<cond_num; i++)
		{
			if (JudgeSpv2NodeItem(pSpv, condition[i])==FALSE)
					break;
		}
		////
		if (i==cond_num)
		{
			find=1;
			pSpv_tmp = (Node_spv *)malloc(sizeof(Node_spv));
			*pSpv_tmp = *pSpv;
			pSpv_tmp->next = pSpv_ret;
			pSpv_ret = pSpv_tmp;
			break;
		}
		////
		pSpv=pSpv->next;
	}

	if (find==0)
		return NULL;
	return pSpv_ret;
}

BOOL JudgeSpv2NodeItem(Node_spv* pspv_node, char* pcondition)
{
	int item_num = *pcondition;
	BOOL bRet = FALSE;
	switch (item_num)
	{
		case '!':
			bRet = (atoi(pcondition+1)!=pspv_node->pingjia);
			break;
		case '=':
			bRet = (atoi(pcondition+1)==pspv_node->pingjia);
			break;
		case '>':
			bRet = (atoi(pcondition+1)>=pspv_node->pingjia);
			break;
		case '<':
			bRet = (atoi(pcondition+1)<=pspv_node->pingjia);
			break;
		default:
			printf("BUG!  line:%d\n",__LINE__);
	}

	return bRet;
}

//<统计1>


/**
 * 函数名称: StatTchNode
 * 函数功能: 统计
 * 输入参数: 头结点指针headp
 * 输出参数: 无
 * 返 回 值: 如果完成统计信息，则将信息做成链表并返回指向头节点的指针，否则返回NULL

 *
 * 调用说明:  统计教师姓名，学时数，课程数，学分数，学生总数
*/

STATISTIC1* StatTchNode(Node_tch* headp)
{
    Node_tch* pTch;
    Node_cls* pCls;

    STATISTIC1* pnodec = NULL;
    STATISTIC1* pnoder = NULL;

    int kcs;
    double xfs;
    int xss;
    int zrs;
    char xq[12];

    puts("请输入要统计的学期");
    scanf(" %s", xq);

    for (pTch=headp; pTch!=NULL; pTch=pTch->next)
    {
        //新的节点，数据初始化
        kcs = 0;
        xfs = 0;
        xss = 0;
        zrs = 0;
        //一级链表依次计算
        pnodec = (STATISTIC1*)calloc(1, sizeof(STATISTIC1));
        pnodec->next = pnoder;
        pnoder = pnodec;
        pnodec->jiaoshixingming = pTch->xingming;
        for (pCls=pTch->cls; pCls!=NULL; pCls=pCls->next)
        {
            if (strcmp(pCls->xueqi, xq)!=0)
                continue;
            kcs++;
            xfs += pCls->xuefen;
            xss += pCls->xueshi;
            zrs += pCls->renshu;
        }
        //计算完输入结果
        pnodec->kechengshu = kcs;
        pnodec->xuefenshu = xfs;
        pnodec->xueshishu = xss;
        pnodec->zongrenshu = zrs;
    }


    SortTchNode(pnodec);
    return pnodec;
}

void SortTchNode(STATISTIC1* hd)
{
    STATISTIC1* pnode1;
    STATISTIC1* pnode2;
    STATISTIC1* ptmp = NULL;

    for (pnode1=hd; pnode1!=NULL; pnode1=pnode1->next)
    {
        for (pnode2=pnode1->next; pnode2!=NULL; pnode2=pnode2->next)
        {
            if (pnode1->xueshishu < pnode2->xueshishu)
            {
                /********如果满足条件，交换数据域***********/
                ptmp = (STATISTIC1*)calloc(1, sizeof(STATISTIC1));
                *ptmp = *pnode1;
                //
                pnode1->kechengshu = pnode2->kechengshu;
                pnode1->xuefenshu = pnode2->xuefenshu;
                pnode1->xueshishu = pnode2->xueshishu;
                pnode1->zongrenshu = pnode2->zongrenshu;
                pnode1->jiaoshixingming = pnode2->jiaoshixingming;
                //
                pnode2->kechengshu = ptmp->kechengshu;
                pnode2->xuefenshu = ptmp->xuefenshu;
                pnode2->xueshishu = ptmp->xueshishu;
                pnode2->zongrenshu = ptmp->zongrenshu;
                pnode2->jiaoshixingming = ptmp->jiaoshixingming;
            }
        }

    }

}

//<统计2>

/**
 * 函数名称: StatClsNode
 * 函数功能: 统计
 * 输入参数: 头结点指针headp
 * 输出参数: 无
 * 返 回 值: 如果完成统计信息，则将信息做成链表并返回指向头节点的指针，否则返回NULL

 *
 * 调用说明:  学期，课堂数，教授数，副教授数，讲师数，迟到数
*/

STATISTIC2* StatClsNode(Node_tch* headp)
{
    Node_tch* pTch;
    Node_cls* pCls;
    Node_cls Clstmp;

    STATISTIC2* pnodec = NULL;
    STATISTIC2* pnoder = NULL;
    STATISTIC2* ptmp = NULL;

    int i=0;
    int num=0;
    char xq[12];

    puts("请输入要统计的学期");
    scanf(" %s", xq);

    for (pTch=headp; pTch!=NULL; pTch=pTch->next)
    {
        for (pCls=pTch->cls; pCls!=NULL; pCls=pCls->next)
        {
            if (strcmp(pCls->xueqi, xq)!=0)
                continue;
            Clstmp = *pCls;
            if ((ptmp = searchstat(pnodec, Clstmp.mingcheng))!=NULL)    /**如果在pnodec链表中能找到同名的课程*/
            {
                /**就在这个链表对应的节点上增加数据*/
                ptmp->ketangshu += 1;
                ptmp->junfen =(ptmp->junfen*(ptmp->ketangshu - 1) + Clstmp.junfen)/(ptmp->ketangshu);
                for (i=0; i<5; i++)
                {
                    ptmp->sGPA[i] += Clstmp.GPA[i];
                }
            }
            else        /**如果在pnodec链表中找不到同名的课程*/
            {
                /**先链表增长*/
                pnodec = (STATISTIC2*)calloc(1, sizeof(STATISTIC2));
                pnodec->next = pnoder;
                pnoder = pnodec;
                /**然后数据赋初值*/
                strcpy(pnodec->kechengmingcheng, Clstmp.mingcheng);
                pnodec->junfen = Clstmp.junfen;
                pnodec->ketangshu = 1;
                for (i=0; i<5; i++)
                {
                    pnodec->sGPA[i] = Clstmp.GPA[i];
                }
            }
        }
    }


    SortClsNode(pnodec);
    return pnodec;
}

STATISTIC2* searchstat(STATISTIC2* hd, char* Mingcheng)
{
    while(hd)
    {
        if (strcmp(hd->kechengmingcheng, Mingcheng)==0)
        {
            break;
        }
        hd = hd->next;
    }

    return hd;
}


void SortClsNode(STATISTIC2* hd)
{
    STATISTIC2* pnode1 = NULL;
    STATISTIC2* pnode2 = NULL;
    STATISTIC2* ptmp = NULL;

    int i;

    for (pnode1=hd; pnode1!=NULL; pnode1=pnode1->next)
    {
        for (pnode2=pnode1->next; pnode2!=NULL; pnode2=pnode2->next)
        {
            if (pnode1->junfen < pnode2->junfen)
            {
                /********如果满足条件，交换数据域***********/
                ptmp = (STATISTIC2*)calloc(1, sizeof(STATISTIC2));
                *ptmp = *pnode1;
                //
                strcpy(pnode1->kechengmingcheng, pnode2->kechengmingcheng);
                pnode1->junfen = pnode2->junfen;
                pnode1->ketangshu = pnode2->ketangshu;
                for (i=0; i<5; i++)
                {
                    pnode1->sGPA[i] = pnode2->sGPA[i];
                }
                //
                strcpy(pnode2->kechengmingcheng, ptmp->kechengmingcheng);
                pnode2->junfen = ptmp->junfen;
                pnode2->ketangshu = ptmp->ketangshu;
                for (i=0; i<5; i++)
                {
                    pnode2->sGPA[i] = ptmp->sGPA[i];
                }
            }
        }

    }

}



//<统计3>

/**
 * 函数名称: StatSpvNode
 * 函数功能: 统计
 * 输入参数: 头结点指针headp
 * 输出参数: 无
 * 返 回 值: 如果完成统计信息，则将信息做成链表并返回指向头节点的指针，否则返回NULL

 *
 * 调用说明:  统计学期，课堂数，教授数，副教授数，讲师数，迟到数
*/

STATISTIC3* StatSpvNode(Node_tch* headp)
{
    Node_tch* pTch;
    Node_cls* pCls;
    Node_spv* pSpv;
    STATISTIC3* pnodec = NULL;
    STATISTIC3* pnoder = NULL;
    STATISTIC3* ptemp = NULL;

    int i;
    char mc[30];
    puts("请输入要统计的课程名称");
    scanf(" %s", mc);

    for (pTch=headp; pTch!=NULL; pTch=pTch->next)
    {
        for (pCls=pTch->cls; pCls!=NULL; pCls=pCls->next)
        {
            if (strcmp(pCls->mingcheng, mc)!=0)
                continue;
            if ((ptemp = searchstatspv(pnodec, pCls->xueqi))==NULL)     /**如果没找到这个学期，就创建一个新的节点并赋初值*/
            {
                pnodec = (STATISTIC3*)calloc(1, sizeof(STATISTIC3));
                pnodec->next = pnoder;
                pnoder = pnodec;

                strcpy(pnodec->xueqi, pCls->xueqi);
                pnodec->chidaoshu = 0;
                pnodec->ketangshu = 1;
                for (i=0; i<4; i++)
                {
                    pnodec->zhiwei[i] = 0;
                }
                pnodec->zhiwei[SeekTchNode(head, pCls->gonghao)->zhicheng-1] = 1;
            }
            else        /**否则就在这个节点上补充数据*/
            {
                pnodec->ketangshu += 1;
                pnodec->zhiwei[SeekTchNode(head, pCls->gonghao)->zhicheng-1] += 1;
                for (pSpv=pCls->spv; pSpv!=NULL; pSpv=pSpv->next)
                {
                    if (toupper(pSpv->kaoqin)=='B')
                        pnodec->chidaoshu += 1;
                }
            }
        }
    }

    SortSpvNode(pnodec);
    return pnodec;
}


STATISTIC3* searchstatspv(STATISTIC3* hd, char* Xueqi)
{
    while (hd)
    {
        if (strcmp(hd->xueqi, Xueqi)==0)
            break;
        hd = hd->next;
    }

    return hd;
}

void SortSpvNode(STATISTIC3* hd)
{
    STATISTIC3* pnode1 = NULL;
    STATISTIC3* pnode2 = NULL;
    STATISTIC3* ptmp = NULL;

    int i;

    for (pnode1=hd; pnode1!=NULL; pnode1=pnode1->next)
    {
        for (pnode2=pnode1->next; pnode2!=NULL; pnode2=pnode2->next)
        {
            if (nodecmp(pnode1, pnode2)>0)
            {
                ptmp = (STATISTIC3*)calloc(1, sizeof(STATISTIC3));
                *ptmp = *pnode1;
                //
                pnode1->chidaoshu = pnode2->chidaoshu;
                pnode1->ketangshu = pnode2->ketangshu;
                strcpy(pnode1->xueqi, pnode2->xueqi);
                for (i=0; i<4; i++)
                    pnode1->zhiwei[i] = pnode2->zhiwei[i];
                //
                pnode2->chidaoshu = ptmp->chidaoshu;
                pnode2->ketangshu = ptmp->ketangshu;
                strcpy(pnode2->xueqi, ptmp->xueqi);
                for (i=0; i<4; i++)
                    pnode2->zhiwei[i] = ptmp->zhiwei[i];
                free(ptmp);
            }
        }
    }

}

int nodecmp(STATISTIC3* h1, STATISTIC3* h2)
{
    if (atoi(h1->xueqi+1)!=atoi(h2->xueqi+1))
    {
        return atoi(h1->xueqi+1)-atoi(h2->xueqi+1);
    }
    else
    {
        return *h2->xueqi - *h1->xueqi;
    }
}

//<统计4>

/**
 * 函数名称: StatPjNode
 * 函数功能: 统计
 * 输入参数: 头结点指针headp
 * 输出参数: 无
 * 返 回 值: 如果完成统计信息，则将信息做成链表并返回指向头节点的指针，否则返回NULL

 *
 * 调用说明:  教师的学生综合评价分值
*/

STATISTIC4* StatPjNode(Node_tch* headp, int year)
{
    Node_tch* pTch;
    Node_cls* pCls;
    Node_spv* pSpv;
    STATISTIC4* pnodec = NULL;
    STATISTIC4* pnoder = NULL;

    double fenzhi;
    int num;

    for (pTch=headp; pTch!=NULL; pTch=pTch->next)
    {
        pnodec = (STATISTIC4*)calloc(1, sizeof(STATISTIC4));
        pnodec->next = pnoder;
        pnoder = pnodec;

        pnodec->jiaoshixingming = pTch->xingming;
        num = 0;
        fenzhi = 0.0;

        for (pCls=pTch->cls; pCls!=NULL; pCls=pCls->next)
        {
            if (year!=atoi(pCls->xueqi+1))         /**当年度不匹配时跳过**/
            {
                continue;
            }
            for (pSpv=pCls->spv; pSpv!=NULL; pSpv=pSpv->next)
            {
                fenzhi += pSpv->pingjia;
                num++;
            }

        }
        if (num!=0)
            pnodec->zonghepingjia = fenzhi/num;
        else
            pnodec->zonghepingjia = 0;
    }

    SortPjNode(pnodec);
    return pnodec;
}

void SortPjNode(STATISTIC4* hd)
{
    STATISTIC4* pnode1 = NULL;
    STATISTIC4* pnode2 = NULL;
    STATISTIC4* ptmp = NULL;

    for (pnode1=hd; pnode1!=NULL; pnode1=pnode1->next)
    {
        for (pnode2=pnode1->next; pnode2!=NULL; pnode2=pnode2->next)
        {
            /********如果满足条件，交换数据域***********/
            if (pnode1->zonghepingjia < pnode2->zonghepingjia)
            {
                ptmp = (STATISTIC4*)calloc(1, sizeof(STATISTIC4));
                *ptmp = *pnode1;
                //
                pnode1->jiaoshixingming = pnode2->jiaoshixingming;
                pnode1->zonghepingjia = pnode2->zonghepingjia;
                //
                pnode2->jiaoshixingming = ptmp->jiaoshixingming;
                pnode2->zonghepingjia = ptmp->zonghepingjia;
            }

        }

    }

}





