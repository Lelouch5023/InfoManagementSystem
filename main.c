#include"information.h"

Node_tch* head=NULL;


int main()
{
	SetConsoleTitle(TITLE);

	int shuzi=CreatList(&head);
	printf("creatlist��ɶ�%d \n",shuzi);
	SaveSysData(head);//����
	int out;
	do{
		//��ʼ��
		static int choice_main;
		choice_main = menu_start(welcome, Nwelcome);
		out = 0;


		//ѡ����ڽ��뺯��
		switch (choice_main)
		{
			case 1:
				out = shujuweihu(choice_main);		//����ά��
				SaveSysData(head);
				puts("�����ѱ���");
				break;
			case 2:
				out = shujuchaxun(choice_main);		//���ݱ�����ѯ
				SaveSysData(head);
				puts("�����ѱ���");
				break;
			case 3:
				out = shujutongji(choice_main);		//����ͳ��
				SaveSysData(head);
				puts("�����ѱ���");
				break;
			case 4:
				out = shujusousuo(choice_main);		//��������
				SaveSysData(head);
				puts("�����ѱ���");
				break;
			default:
				out = 1;
		}

	}while(out==0);


	SaveSysData(head);
	puts("�����ѱ���");
	return 0;
}

////////////////////////////////////////////�˵����溯��//////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////�˵����溯��/////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * ��������: menu_start
 * ��������: �����ʾ�ַ���������һ����Χ�ڵ������淶�����ֺ󷵻�
 * �������: �����ַ����������
 * �������: int ����
 * �� �� ֵ: BOOL���ͣ�����ΪTRUE
 *
 * ����˵��:
 */

int  menu_start(const char s[][NUMOFCH], int n)
{
	int choice;
	int i;
	//����
	system("pause");
	system("cls");
	//����
	puts(s[0]);
	for (i=1; i<n; i++)
		printf("%d.%s\n",i,s[i]);
		//���������
		/*	puts("��ӭ�����ʦ��ѧ��Ϣ����ϵͳ,����������ѡ�����:");	*/
		/*	puts("1.����ά��");		*/
		/*	puts("2.���ݲ�ѯ");		*/
		/*	puts("3.����ͳ��");		*/
		/*	puts("4.��ʾȫ������");	*/

	//���뼰�������
	while(1)
	{
		if (scanf("%d", &choice)!=1)
			continue;
		if (choice>=1 && choice<=n-1)
			break;
		else
			printf("��������%d����1-%d�����֣�������һ��", choice, n-1);
	}
	return choice;
}



//1.	����ά������
int shujuweihu(int choice)
{
	int option=0;
	option = menu_start(maintain, Nmaintain);
	if (option==Nmaintain)
		return 1;	//�˳�

	switch (option){
		case 1:		//1.1����¼��
			shujuluru();
			break;
		case 2:		//1.2�����޸�
			shujuxiugai();
			break;
		case 3:		//1.3����ɾ��
			shujushanchu();
			break;
	}


    SaveSysData(head);
	return 0;	//����ѭ��������
}

//1.1	����¼��
void shujuluru(void)
{
	int luru;
	luru = menu_start(insert, Ninsert);
	switch (luru)
	{
		case 1:		//1.1.1��ʦ��Ϣ¼��
			jiaoshiluru();
			break;
		case 2:		//1.1.2������Ϣ¼��
			ketangluru();
			break;
		case 3:		//1.1.3������Ϣ¼��
			dudaoluru();
			break;
	}

}

//1.1.1<¼��>��ʦ¼��
void jiaoshiluru(void)
{
	Node_tch* ptchtmp=(Node_tch*)malloc(sizeof(Node_tch));

	puts("���빤��");
	scanf(" %s", ptchtmp->gonghao);
	if (SeekTchNode(head, ptchtmp->gonghao)!=NULL)
    {
        printf("�ù����Ѵ��ڣ�\n");
        return ;
    }
	puts("��������");
	scanf(" %s", ptchtmp->xingming);
	puts("����ְ��:'1'����'2'������'3'��ʦ'4'����");
	scanf("%d", &ptchtmp->zhicheng);

	if (InsertTchNode( ptchtmp)==TRUE)			/*����������*/
	{
		printf("¼��ɹ�!\r");
		Sleep(1500);
		printf("         \n");
	}
	else
	{
		printf("�Ҳ����ý�ʦ�Ŀ��ã�%d\n",__LINE__);
	}

}
//1.1.2<¼��>����¼��
void ketangluru(void)
{
	Node_tch* pTch ;
	Node_cls* pclstmp = (Node_cls*)calloc(1, sizeof(Node_cls));

	//������Ϣ
	puts("�����ον�ʦ����");
	scanf("%s",pclstmp->gonghao);
	if ((pTch=SeekTchNode(head, pclstmp->gonghao))==NULL)
    {
        printf("�ù��Ų����ڣ�\n");
        return ;
    }
	puts("�������ѧ��");
	scanf(" %s", pclstmp->xueqi);
	puts("�����������");
	scanf(" %s", pclstmp->mingcheng);

	puts("�������ѧ��");
	scanf("%lf", &pclstmp->xuefen);
	puts("�������ѧʱ");
	scanf("%d", &pclstmp->xueshi);
	puts("������ð༶");
	scanf(" %s", pclstmp->ketang);
	puts("�������������");
	scanf("%d", &pclstmp->renshu);
	puts("������þ���");
	scanf("%lf", &pclstmp->junfen);
	int i;
	for (i=4; i>=1; i--)
	{
		printf("���������%d0�����ϵ���", i+5);
		scanf("%d", &pclstmp->GPA[i]);
	}	printf("�����벻���������");
		scanf("%d", &pclstmp->GPA[i]);

	//����ڵ�
	if(InsertClsNode(head, pclstmp)==TRUE)
	{
		printf("¼��ɹ�!\r");
		Sleep(1500);
		printf("         \n");
	}
	else
	{
		printf("�Ҳ����ý�ʦ�Ŀ��ã�%d",__LINE__);

	}
}
//1.1.3<¼��>����¼��
void dudaoluru(void)
{
	Node_spv* pspvtmp = (Node_spv*)malloc(sizeof(Node_spv));
	//������Ϣ
	puts("�����ʦ����");
	scanf("%s", pspvtmp->gonghao);
    if (SeekTchNode(head, pspvtmp->gonghao)==NULL)
    {
        printf("�ù��Ų����ڣ�\n");
        return ;
    }
	puts("����γ�����");
	scanf("%s", pspvtmp->mingcheng);
	puts("���붽���γ�ѧ��");
	scanf("%s", pspvtmp->xueqi);
	if (SeekClsNode(head, pspvtmp->xueqi, pspvtmp->gonghao, pspvtmp->mingcheng)==NULL)
    {
        printf("�ÿγ̲����ڣ�\n");
        return ;
    }
	puts("���붽������");
	scanf("%s", pspvtmp->riqi);
	puts("���붽����ʦ���� (%c)  A.׼ʱ B.�ٵ�");
	scanf(" %c", &pspvtmp->kaoqin);
	pspvtmp->kaoqin = toupper(pspvtmp->kaoqin);
	puts("���붽����������");
	scanf("%d", &pspvtmp->daoke);
	puts("���붽������Ч��(%c)   E.���� G.���� M.�е� B.�ϲ�");
	scanf(" %c", &pspvtmp->xiaoguo);
	pspvtmp->xiaoguo = toupper(pspvtmp->xiaoguo);
	puts("���붽��ѧ�����۷���");
	scanf("%d", &pspvtmp->pingjia);
	puts("���붽����ʦ����(dudaogonghao)");
	scanf("%s", pspvtmp->dudaogonghao);
	//����ڵ�
	if(InsertSpvNode(head , pspvtmp)==TRUE)
	{
		printf("¼��ɹ�!\r");
		Sleep(1500);
		printf("         \n");
	}
	else
	{
		printf("�Ҳ����ö�����%d",__LINE__);
	}

}

//1.2�����޸�
void shujuxiugai(void)
{
	int xiugai;
	xiugai = menu_start(modified, Nmodified);
	switch (xiugai)
	{
		case 1:		//1.1.1��ʦ��Ϣ�޸�
			jiaoshixiugai();
			break;
		case 2:		//1.1.2������Ϣ�޸�
			ketangxiugai();
			break;
		case 3:		//1.1.3������Ϣ�޸�
			dudaoxiugai();
			break;
	}

}

//1.2.1<�޸�>��ʦ�޸�
void jiaoshixiugai(void)
{
	Node_tch* pTch;
	Node_tch* pTchtmp = (Node_tch*)calloc(1, sizeof(Node_tch));

	char gh[12];

	puts("������Ҫ�޸ĵĽ�ʦ����");
	scanf("%s", gh);
	pTch = SeekTchNode(head, gh);

	if (pTch!=NULL)
	{
		system("cls");
		puts("����ǰ��Ϣ��");
		printf("��ʦ���ţ�%s\n", pTch->gonghao);
		printf("��ʦ������%s\n", pTch->xingming);
		printf("��ʦְ�ƣ�%s\n", Job[pTch->zhicheng-1]);
	}
	else
	{
		printf("�Ҳ����ý�ʦ��line:%d\n",__LINE__);
		return ;
	}
	puts("���µ���Ϣ��");
	*pTchtmp = *pTch;							//����

	puts("�������µĽ�ʦ����");
	scanf(" %s", pTchtmp->xingming);
	puts("�������µĽ�ʦְ�� (%c) 1.����  2.������  3.��ʦ  4.����");
	scanf(" %d", &pTchtmp->zhicheng);
    printf("ABOVE:%c  %d\n",pTchtmp->zhicheng,pTchtmp->zhicheng);

	*pTch = *pTchtmp;
}

//1.2.2<�޸�>�����޸�
void ketangxiugai(void)
{
	Node_cls Clstmp;
	Node_cls* pCls;

	char xq[10];
	char gh[12];
	char mc[30];

	puts("�������ʦ����");
	scanf("%s", gh);
	puts("�������������");
	scanf("%s", mc);
	puts("������γ�ѧ��");
	scanf("%s", xq);

	pCls = SeekClsNode(head, xq, gh, mc);

	if (pCls!=NULL)
	{
		system("cls");					//��ʾ�ɵ���Ϣ
		printf("����ǰ��Ϣ��\n");
		printf("�γ����ƣ�%s\n",pCls->mingcheng);
		printf("�γ�ѧ�ڣ�%s\n",pCls->xueqi);
		printf("�γ�ѧ�֣�%.1lf\n",pCls->xuefen);
		printf("�γ�ѧʱ��%d\n",pCls->xueshi);
		printf("�γ̿��ã�%s\n",pCls->ketang);
		printf("�γ�������%d\n",pCls->renshu);
		puts("�γ�ѧ�����������");
		int i;
		for	(i=4; i>=1; i--){
			printf("�γ�%d������������%d\n",i*10+50,pCls->GPA[i]);
		}
		printf("�γ̲�����������%d\n",pCls->GPA[i]);
		printf("�γ̾��֣�%.1lf\n\n",pCls->junfen);

		printf("���µ���Ϣ��\n");		//�����µ���Ϣ
		Clstmp = *pCls;
		puts("�������µĿγ�����");
		scanf("%s", Clstmp.mingcheng);
		puts("�������µĿγ�ѧ��");
		scanf("%s", Clstmp.xueqi);
		puts("�������µĿγ�ѧ��");
		scanf("%lf", &Clstmp.xuefen);
		puts("�������µĿγ�ѧʱ");
		scanf("%d", &Clstmp.xueshi);
		puts("�������µĿγ̿���");
		scanf("%s", Clstmp.ketang);
		puts("�������µĿγ̿γ�����");
		scanf("%d", &Clstmp.renshu);
		for	(i=4; i>=1; i--){
			printf("������γ�%d������������\n",i*10+50);
			scanf("%d", &Clstmp.GPA[i]);
		}
		printf("������γ̲�����������\n");
		scanf("%d", &Clstmp.GPA[i]);
        printf("�������µĿγ̾���\n");
        scanf("%lf", &Clstmp.junfen);

		if ((ModifyClsNode(head, xq, gh, mc, &Clstmp))==TRUE)
		{
			printf("������Ϣ�޸ĳɹ���\n");
			/**��ʱ����Ҫ�޸����ӽڵ����Ϣ*/
			Node_spv* pSpv;
			for (pSpv=pCls->spv; pSpv!=NULL; pSpv=pSpv->next)
            {
                strcpy(pSpv->mingcheng, Clstmp.mingcheng);
                strcpy(pSpv->xueqi, Clstmp.xueqi);
            }
            printf("�����µĶ�����Ϣ�޸ĳɹ���\n");

		}
		else
		{
			printf("�޸�ʧ�ܣ� line:%d \n",__LINE__);
		}
	}
	else
	{
		printf("�Ҳ����ÿ��ã�  line:%d\n",__LINE__);
	}


}
//1.2.3<�޸�>�����޸�
void dudaoxiugai(void)
{
	Node_spv Spvtmp;
	Node_spv* pSpv;

	char gh[12];
	char xq[10];
	char mc[30];
	char rq[10];

	puts("�������ʦ����");
	scanf("%s", gh);
	puts("������γ�ѧ��");
	scanf("%s", xq);
	puts("������γ�����");
	scanf("%s", mc);
	puts("�����붽������");
	scanf("%s", rq);

	pSpv = SeekSpvNode(head, gh, xq, mc, rq);
	if (pSpv!=NULL)
	{
		system("cls");				//��ʾ�ɵ���Ϣ
		printf("����ǰ��Ϣ��\n");
		printf("�������ڣ�%s\n", pSpv->riqi);
		printf("��ʦ���ڣ�%s\n", kaoq[pSpv->kaoqin-'A']);
		printf("ѧ������������%d\n", pSpv->daoke);
		printf("����Ч����%s\n", pSpv->xiaoguo=='E'?"��":pSpv->xiaoguo=='G'?"��":pSpv->xiaoguo=='M'?"��":"��");
		printf("ѧ�����ۣ�%d\n", pSpv->pingjia);
		printf("������ʦ���ţ�%s\n", pSpv->dudaogonghao);

		printf("���µ���Ϣ��\n");		//�����µ���Ϣ
		Spvtmp = *pSpv;
		puts("���붽������");
		scanf("%s", Spvtmp.riqi);
		puts("���붽����ʦ���� (%c)  A.׼ʱ B.�ٵ�");
		scanf(" %c", &Spvtmp.kaoqin);
		Spvtmp.kaoqin = toupper(Spvtmp.kaoqin);
		puts("���붽����������");
		scanf("%d",&Spvtmp.daoke);
		puts("���붽������Ч��(%c)   E.���� G.���� M.�е� B.�ϲ�");
		scanf(" %c",&Spvtmp.xiaoguo);
		Spvtmp.xiaoguo = toupper(Spvtmp.xiaoguo);
		puts("���붽��ѧ�����۷���");
		scanf("%d", &Spvtmp.pingjia);
		puts("���붽����ʦ����(dudaogonghao)");
		scanf("%s", Spvtmp.dudaogonghao);

		if (ModifySpvNode(head, gh, xq, mc, rq, &Spvtmp)==TRUE)		//��ʼ�޸�
		{
			printf("�޸ĳɹ��� \n");
		}
		else
		{
			printf("�޸�ʧ�ܣ� line:%d \n",__LINE__);
		}

	}
	else
	{
		printf("�Ҳ����ö�����Ϣ��  line:%d \n",__LINE__);
	}

}


//1.3	����ɾ��
void shujushanchu(void)
{
	int shanchu;
	shanchu = menu_start(deleted, Ndeleted);
	switch (shanchu)
	{
		case 1:		//1.1.1��ʦ��Ϣɾ��
			jiaoshishanchu();
			break;
		case 2:		//1.1.2������Ϣɾ��
			ketangshanchu();
			break;
		case 3:		//1.1.3������Ϣɾ��
			dudaoshanchu();
			break;
	}
	SaveSysData(head);

}

//1.3.1<ɾ��>��ʦɾ��
void jiaoshishanchu(void)
{
	char gh[12];

	puts("������Ҫɾ���Ľ�ʦ����");
	scanf("%s", gh);

	if (DelTchNode(head, gh)==TRUE)
	{
		printf("ɾ���ɹ���\n");
	}
	else
	{
		printf("ɾ��ʧ�ܣ�line:%d\n",__LINE__);
	}
}
//1.3.2<ɾ��>����ɾ��
void ketangshanchu(void)
{
	char gh[12];
	char xq[12];
	char mc[30];

	puts("�������ον�ʦ����");
	scanf("%s", gh);
	puts("������γ�����");
	scanf("%s", mc);
	puts("������γ�ѧ��");
	scanf("%s", xq);

	if (DelClsNode(head, xq, gh, mc)==TRUE)
	{
		printf("ɾ���ɹ���\n");
	}
	else
	{
		printf("ɾ��ʧ�ܣ�line:%d\n",__LINE__);
	}

}
//1.3.3<ɾ��>����ɾ��
void dudaoshanchu(void)
{
	char gh[12];
	char xq[12];
	char mc[30];
	char rq[10];

	puts("�������ον�ʦ����");
	scanf("%s", gh);
	puts("������γ�����");
	scanf("%s", mc);
	puts("������γ�ѧ��");
	scanf("%s", xq);
	puts("�����붽������");
	scanf("%s", rq);

	if (DelSpvNode(head, gh, xq, mc, rq)==TRUE)
	{
		printf("ɾ���ɹ���\n");
	}
	else
	{
		printf("ɾ��ʧ�ܣ�line:%d\n",__LINE__);
	}
}


//2.���ݱ�����ѯ����
int shujuchaxun(int choice)
{
	int option=0;
	option = menu_start(refer, Nrefer);
	if (option==Nrefer)
		return 1;	//�˳�

	switch(option){
		case 1:
			jiaoshichaxun();		// ��ʦ������ѯ
			break;
		case 2:
			ketangchaxun();			//	���ñ�����ѯ
			break;
		case 3:
			dudaochaxun();			//	����������ѯ
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




//3����ͳ�ƽ���
int shujutongji(int choice)
{
    int option=0;
	option = menu_start(statqq, Nstatqq);
	if (option==Nstatqq)
		return 1;	//�˳�

	switch(option){
		case 1:
			jiaoshitongji();	//��ʦͳ��
			break;
		case 2:
			ketangtongji();		//����ͳ��
			break;
		case 3:
			dudaotongji();		//����ͳ��
			break;
        case 4:
            pingjiatongji();	//����ͳ��
            break;
		default:
			return 0;
	}

	return 0;
}
//<ͳ��>��ʦͳ��
void jiaoshitongji(void)
{
    STATISTIC1* hdp;

    hdp = StatTchNode(head);
    system("cls");
    printf("\t��ʦ����\tѧʱ��\t\t�γ���\t\tѧ����\t\tѧ������\n");
    while(hdp)
    {
        printf("\t%s\t\t%d\t\t%d\t\t%.4lf\t\t%d\n", hdp->jiaoshixingming, hdp->xueshishu, hdp->kechengshu,
                                            hdp->xuefenshu, hdp->zongrenshu);
        hdp = hdp->next;
    }

}
//<ͳ��>����ͳ��
void ketangtongji(void)
{
    STATISTIC2* hdp;

    hdp = StatClsNode(head);
    system("cls");
    printf("�γ�����\t������\t����\t90-100\t80-89\t70-79\t60-69\t0-59\n");
    while (hdp)
    {
        printf("%s\t%d\t%.1lf\t%d\t%d\t%d\t%d\t%d\n", hdp->kechengmingcheng, hdp->ketangshu, hdp->junfen,
                        hdp->sGPA[4], hdp->sGPA[3], hdp->sGPA[2], hdp->sGPA[1], hdp->sGPA[0]);
       hdp = hdp->next;
    }

}
//<ͳ��>����ͳ��
void dudaotongji(void)
{
    STATISTIC3* hdp;

    hdp = StatSpvNode(head);
    system("cls");
    printf("ѧ��\t������\t����\t������\t��ʦ\t�ٵ���\n");
    while (hdp)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", hdp->xueqi, hdp->ketangshu, hdp->zhiwei[0], hdp->zhiwei[1], hdp->zhiwei[2],hdp->chidaoshu);
        hdp = hdp->next;
    }

}
//<ͳ��>����ͳ��
void pingjiatongji(void)
{
    STATISTIC4* hdp;

    int year;

    puts("����������ͳ�Ƶ����");
    scanf("%d", &year);

    hdp = StatPjNode(head, year);

    system("cls");
    printf("\t��ʦ\t\tѧ���ۺ����۷�ֵ\n");
    while(hdp)
    {
        printf("\t%s\t\t%.1lf\n", hdp->jiaoshixingming, hdp->zonghepingjia);
        hdp = hdp->next;
    }
}



//4������������
int shujusousuo(int choice)
{
	int option=0;
	option = menu_start(seekinfo, Nseekinfo);
	if (option==Nseekinfo)
		return 1;	//�˳�

	switch (option){
		case 1:		//������ʦ�ڵ�
			souTch1();
			break;
		case 2:		//������ʦ�ڵ�
			souTch2();
			break;
		case 3:		//�������ýڵ�
			souCls1();
			break;
		case 4:		//�������ýڵ�
			souCls2();
			break;
		case 5:		//���������ڵ�
			souSpv1();
			break;
		case 6:		//���������ڵ�
			souSpv2();
			break;
	}


	return 0;
}

//<����>��ʦ�ڵ�1
void souTch1(void)
{
	Node_tch* pTch;

	char gh[12];

	puts("������Ҫ��ѯ�Ľ�ʦ����");
	scanf("%s",gh);
	pTch = SeekTchNode(head, gh);

	if (pTch!=NULL)
	{
		system("cls");
		printf("��ʦ������%s\n",pTch->xingming);
		printf("��ʦְ�ƣ�%s\n",Job[pTch->zhicheng-1]);
	}
	else
	{
		printf("�Ҳ����ý�ʦ��line:%d\n",__LINE__);
	}

}

//<����>��ʦ�ڵ�2
void souTch2(void)
{
	Node_tch* pTch;

	char* xs = (char*)calloc(6, sizeof(char));
	char zc;

	puts("�������ʦ������");
	scanf(" %s", xs);

	puts("�������ʦ��ְ��(%d)��1.����  2.������  3.��ʦ  4.����");
	scanf("%d", &zc);

	pTch = SeekTchNode2(head, xs, zc);
	if (pTch!=NULL)
	{
		system("cls");
		printf("��ʦ������%s\n",pTch->xingming);
		printf("��ʦ���ţ�%s\n",pTch->gonghao);
		printf("��ʦְ�ƣ�%s\n",Job[pTch->zhicheng-1]);
		putchar('\n');
	}
	else
	{
		printf("�Ҳ����ý�ʦ��line:%d\n",__LINE__);
	}
	free(xs);
}

//<����>���ýڵ�1
void souCls1(void)
{
	Node_cls* pCls;
	char gh[12];
	char xq[10];
	char mc[30];

	puts("�������ʦ����");
	scanf("%s", gh);
	puts("�������������");
	scanf("%s", mc);
	puts("���������ѧ��");
	scanf("%s", xq);


	pCls = SeekClsNode(head, xq, gh, mc);
	if (pCls!=NULL)
	{
		system("cls");
		printf("���������ơ���%s\n", pCls->mingcheng);
		printf("�ον�ʦ���ţ�%s\n", pCls->gonghao);
		printf("ѧ�ڣ�%s\n", pCls->xueqi);
		printf("ѧ�֣�%.2lf\n", pCls->xuefen);
		printf("ѧʱ��%d\n", pCls->xueshi);
		printf("���ã�%s\n", pCls->ketang);
		printf("������%d\n", pCls->renshu);
		puts("�γ�ѧ�����������");
		int i;
		for	(i=4; i>=1; i--){
			printf("�γ�%d������������%d\n",i*10+50,pCls->GPA[i]);
		}
		printf("�γ̲�����������%d\n",pCls->GPA[i]);
		printf("�γ̾��֣�%.1lf\n\n",pCls->junfen);
	}
	else
	{
		printf("�Ҳ����ÿ��ã�line:%d\n",__LINE__);
	}

}

//<����>���ýڵ�2
void souCls2(void)
{
	Node_cls* pCls;

	char xq[10];
	int i;
	int inf;
	int sup;

	puts("������ѧ�ڣ�");
	scanf("%s", xq);

	puts("������ѧʱ���Ͻ�");
	scanf("%d", &sup);
	puts("������ѧʱ���½�");
	scanf("%d", &inf);

	pCls = SeekClsNode2R(head, xq, sup, inf);
	if (pCls!=NULL)
	{
	    system("cls");
		for (; pCls!=NULL; pCls=pCls->next)
        {

            printf("���������ơ���%s\n", pCls->mingcheng);
            printf("�ον�ʦ���ţ�%s\n", pCls->gonghao);
            printf("ѧ�ڣ�%s\n", pCls->xueqi);
            printf("ѧ�֣�%.2lf\n", pCls->xuefen);
            printf("ѧʱ��%d\n", pCls->xueshi);
            printf("���ã�%s\n", pCls->ketang);
            printf("������%d\n", pCls->renshu);
            puts("�γ�ѧ�����������");
            int i;
            for	(i=4; i>=1; i--)
            {
                printf("�γ�%d������������%d\n",i*10+50, pCls->GPA[i]);
            }
            printf("�γ̲�����������%d\n", pCls->GPA[i]);
            printf("�γ̾��֣�%.1lf\n\n", pCls->junfen);
        }
	}
	else
	{
		printf("�Ҳ����ÿ��ã�line:%d\n",__LINE__);
	}
}

//<����>���ýڵ�2
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

//<����>�����ڵ�1
void souSpv1(void)
{
	Node_spv* pSpv;

	char gh[12];
	char xq[10];
	char mc[30];
	char rq[10];

	puts("�������ʦ����");
	scanf("%s", gh);
	puts("������γ�����");
	scanf("%s", mc);
	puts("������ѧ��");
	scanf("%s", xq);
	puts("����������");
	scanf("%s", rq);

	pSpv = SeekSpvNode(head, gh, xq, mc, rq);
	if (pSpv !=NULL)
	{
		printf("��ʦ���ڣ�%s\n",kaoq[pSpv->kaoqin-'A']);
		printf("ѧ������������%d\n",pSpv->daoke);
		printf("����Ч����%s\n",pSpv->xiaoguo=='E'?"��":pSpv->xiaoguo=='G'?"��":pSpv->xiaoguo=='M'?"��":"��");
		printf("ѧ�����ۣ�%d\n",pSpv->pingjia);
		printf("������ʦ���ţ�%s\n",pSpv->dudaogonghao);
	}
	else
	{
		printf("�Ҳ����ö�����Ϣ��line:%d\n",__LINE__);
	}

}

//<����>�����ڵ�2
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
		puts("�������ʦ����");
		scanf("%s", gh);
		pTch = SeekTchNode(head, gh);
		if (pTch!=NULL)
			break;
		else
			puts("���Ų����ڣ��������룡");
	}

	pCls = pTch->cls;
	if (pCls!=NULL)
	{

	puts("������ѧ�����۵��Ͻ�");
	scanf("%d", &sup);
	puts("������ѧ�����۵��½�");
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
	    printf("���������ڡ�%s\n", pSpvc->riqi);
		printf("��ʦ���ڣ�%s\n",kaoq[pSpvc->kaoqin-'A']);
		printf("ѧ������������%d\n",pSpvc->daoke);
		printf("����Ч����%s\n",pSpvc->xiaoguo=='E'?"��":pSpvc->xiaoguo=='G'?"��":pSpvc->xiaoguo=='M'?"��":"��");
		printf("ѧ�����ۣ�%d\n",pSpvc->pingjia);
		printf("������ʦ���ţ�%s\n\n",pSpvc->dudaogonghao);

		pSpvc = pSpvc->next;
	}


}

//<����>�����ʦ��Ϣ�ڵ�
void SearchTch(Node_tch* pTch)
{
	int i;

	if (pTch!=NULL)
	{
		for (i=0; pTch!=NULL; pTch = pTch->next)
		{
			printf("����%d����Ϣ��\n",++i);
			printf("��ʦ����:%s\n",pTch->gonghao);
			printf("��ʦ����:%s\n",pTch->xingming);
			printf("��ʦְ��:%s\n",Job[pTch->zhicheng-1]);
		}
	}
	else
		printf("û������\t%s",__func__);


}

//<����>���������Ϣ�ڵ�
void SearchCls(Node_tch* hd)
{
	Node_tch* pTch;
	Node_cls* pCls;
	char gh[12];
	int i = 0;
	puts("�����ѯ��λ��ʦ��ȫ��������Ϣ���������乤��:");
	scanf("%s",gh);
	pTch = SeekTchNode(hd, gh);
	if (pTch!=NULL && pTch->cls!=NULL)
	{
		pCls = pTch->cls;
		while (pCls!=NULL)
		{
			puts("");
			printf("����%d����Ϣ��\n",++i);
			printf("�γ����ƣ�%s\n",pCls->mingcheng);
			printf("�γ�ѧ�ڣ�%s\n",pCls->xueqi);
			printf("�γ�ѧ�֣�%.1lf\n",pCls->xuefen);
			printf("�γ�ѧʱ��%d\n",pCls->xueshi);
			printf("�γ̿��ã�%s\n",pCls->ketang);
			printf("�γ�������%d\n",pCls->renshu);
			puts("�γ�ѧ�����������");
			int i;
			for	(i=4; i>=1; i--){
				printf("�γ�%d������������%d\n",i*10+50,pCls->GPA[i]);
			}
			printf("�γ̲�����������%d\n",pCls->GPA[i]);
			printf("�γ̾��֣�%.1lf\n\n",pCls->junfen);
			pCls = pCls->next;
		}
	}
	else
		printf("�Ҳ�����û������%d\t%s",__LINE__,__func__);

}

//<����>���������Ϣ�ڵ�
void SearchSpv(Node_tch* hd)
{
	Node_cls* pCls;
	Node_spv* pSpv;
	puts("�����ѯ�ĸ����õ�ȫ��������Ϣ��");
	char* xueqi_tmp = (char*)calloc(10, sizeof(char));
	char* gonghao_tmp = (char*)calloc(12, sizeof(char));
	char* mingcheng_tmp = (char*)calloc(30, sizeof(char));

	puts("�������ʦ����");
	scanf(" %s",gonghao_tmp);
	puts("������γ�ѧ��");
	scanf(" %s",xueqi_tmp);
	puts("������γ�����");
	scanf(" %s",mingcheng_tmp);

	pCls = SeekClsNode(hd, xueqi_tmp, gonghao_tmp, mingcheng_tmp);
	if (pCls!=NULL && pCls->spv!=NULL)
	{
		pSpv = pCls->spv;
		while (pSpv!=NULL)
		{
			puts("");
			printf("���������ڡ���%s\n", pSpv->riqi);
			printf("��ʦ���ڣ�%s\n", kaoq[pSpv->kaoqin-'A']);
			printf("ѧ������������%d\n", pSpv->daoke);
			printf("����Ч����%s\n", pSpv->xiaoguo=='E'?"��":pSpv->xiaoguo=='G'?"��":pSpv->xiaoguo=='M'?"��":"��");
			printf("ѧ�����ۣ�%d\n", pSpv->pingjia);
			printf("������ʦ���ţ�%s\n", pSpv->dudaogonghao);

			pSpv = pSpv->next;
		}

	}
	else
		printf("�Ҳ���\tline:%s  %d\n",__func__,__LINE__);

	free(xueqi_tmp);
	free(gonghao_tmp);
	free(mingcheng_tmp);
}
////////////////////////////////////////////�����ǲ˵����溯��//////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////�����ǲ˵����溯��///////////////////////////////////////////////////////////////////////////////////











////////////////////////////////////////////�����ǹ��ܺ���//////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////�����ǹ��ܺ���///////////////////////////////////////////////////////////////////////////////////



/**
 * ��������: CreateList
 * ��������: �������ļ���ȡ��������, ����ŵ���������ʮ��������.
 * �������: ��
 * �������: phead ����ͷָ��ĵ�ַ, ����������������ʮ����.
 * �� �� ֵ: int����ֵ, ��ʾ�����������.
 *           0  ����, ������
 *           4  �Ѽ�������¥��Ϣ���ݣ���ѧ��������Ϣ�ͽɷ���Ϣ����
 *      4+8==12 �Ѽ�������¥��Ϣ��ѧ��������Ϣ���ݣ��޽ɷ���Ϣ����
 *   4+8+16==28 ����������ݶ��Ѽ���
 *
 * ����˵��:

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
    int ret = 0;		/*��ʼ��ɶ�*/

    while ((pFile1 = fopen(info_tch, "rb")) == NULL)
    {
        printf("��ʦ��Ϣ�����ļ���ʧ��!�������´���...\n");
        if ((pFile1 = fopen(info_tch, "wb+"))==NULL){
			printf("��ʦ��Ϣ�����ļ�����ʧ��!\n");
        	exit(1);
        }
        printf("�����ɹ�!\n");
        fclose(pFile1);
    }
    printf("��ʦ��Ϣ�����ļ��򿪳ɹ�!\n");

    while ((pFile2 = fopen(info_cls, "rb")) == NULL)
    {
        printf("������Ϣ�����ļ���ʧ��!�������´���...\n");
        if ((pFile2 = fopen(info_cls, "wb+"))==NULL){
			printf("������Ϣ�����ļ�����ʧ��!\n");
        	exit(1);
        }
        printf("�����ɹ�!\n");
        fclose(pFile2);
    }
    printf("������Ϣ�����ļ��򿪳ɹ�!\n");

	while ((pFile3 = fopen(info_spv, "rb")) == NULL)
    {
        printf("������Ϣ�����ļ���ʧ��!�������´���...\n");
        if ((pFile3 = fopen(info_spv, "wb+"))==NULL){
			printf("������Ϣ�����ļ�����ʧ��!\n");
        	exit(1);
        }
        printf("�����ɹ�!\n");
        fclose(pFile3);
    }
    printf("������Ϣ�����ļ��򿪳ɹ�!\n");

    /*�������ļ��ж�����¥��Ϣ���ݣ������Ժ���ȳ���ʽ������������*/
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
    printf("��ʦ��Ϣ�����ļ����سɹ�!\n");
    *phead = hd;		/*���������ֵ*/
    ret += 4;  /**/


    /*�������ļ��ж�ȡ��ʦ������Ϣ���ݣ�����������Ӧ����ѧ��������Ϣ֧����*/
    while (!feof(pFile2))
    {
        /*������㣬��Ŵ������ļ��ж����Ľ�ʦ������Ϣ*/
        pCls = (Node_cls *)calloc(1, sizeof(Node_cls));
        fread(pCls, sizeof(Node_cls), 1, pFile2);
        pCls->spv = NULL;

        /*�������ϲ��Ҹý�ʦ�����ڿ��ö�Ӧ���������*/
        pTch = hd;
        while (pTch != NULL
               && strcmp(pTch->gonghao, pCls->gonghao) != 0)
        {
            pTch = pTch->next;
        }
        if (pTch != NULL) /*����ҵ����򽫽���Ժ���ȳ���ʽ�����ʦ��Ϣ֧��*/
        {
            pCls->next = pTch->cls;
            pTch->cls = pCls;
        }
        else  /*���δ�ҵ������ͷ������������ڴ�ռ�*/
        {
            free(pCls);
        }
    }
    fclose(pFile2);
	ret += 8;   /**/
	printf("������Ϣ�����ļ����سɹ�!\n");

    /*�������ļ��ж�ȡѧ���ɷ���Ϣ���ݣ������ʦ������Ϣ֧����Ӧ���Ľɷ�֧����*/
    while (!feof(pFile3))
    {
        /*������㣬��Ŵ������ļ��ж���������Ϣ*/
        pSpv = (Node_spv *)calloc(1, sizeof(Node_spv));
		fread(pSpv, sizeof(Node_spv), 1, pFile3);

        /*���ҽ�ʦ��Ϣ֧���϶�Ӧ�������*/
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
        if (find)  /*����ҵ����򽫽���Ժ���ȳ���ʽ���������Ϣ֧����*/
        {
            pSpv->next = pCls->spv;
            pCls->spv = pSpv;
        }
        else /*���δ�ҵ������ͷ������������ڴ�ռ�*/
        {
            free(pSpv);
        }
    }
    fclose(pFile3);
	ret += 16;   /**/
	printf("������Ϣ�����ļ����سɹ�!\n");

    return ret;
}




/**
 * ��������: SaveSysData
 * ��������: ��������ʮ���������������
 * �������: hd����ͷ���
 * �������: ��
 * �� �� ֵ: BOOL���ͣ�����ΪTRUE
 *
 * ����˵��:
 */

BOOL SaveSysData(Node_tch* hd)
{
	FILE* pfile1 ;
	FILE* pfile2 ;
	FILE* pfile3 ;
	Node_tch* pTch ;
	Node_cls* pCls ;
	Node_spv* pSpv ;

	/******hd==NULL��ʱ����˵��*******/
	if (hd==NULL){
		printf("BUG! hd==NULL when saving data! %d\n",__LINE__);
		exit(3);
	}

	if ((pfile1 = fopen(info_tch,"wb+"))==NULL)
		printf("�򿪲���ʧ�ܣ�\t%s\t%d\n",__func__,__LINE__);

	if ((pfile2 = fopen(info_cls,"wb+"))==NULL)
		printf("�򿪲���ʧ�ܣ�\t%s\t%d\n",__func__,__LINE__);

	if ((pfile3 = fopen(info_spv,"wb+"))==NULL)
		printf("�򿪲���ʧ�ܣ�\t%s\t%d\n",__func__,__LINE__);


	//��ʦ�ڵ�д����
	for (pTch=hd; pTch!=NULL; pTch=pTch->next)
	{
		//дһ���ڵ�
		fwrite(pTch, sizeof(Node_tch), 1, pfile1);

		//���ýڵ�д����
		for (pCls=pTch->cls; pCls!=NULL; pCls=pCls->next)
		{
			//д�����ڵ�
			fwrite(pCls, sizeof(Node_cls), 1, pfile2);

			//�����ڵ�д����:
			for(pSpv=pCls->spv; pSpv!=NULL; pSpv=pSpv->next)
			{
				//д�����ڵ�
				fwrite(pSpv, sizeof(Node_spv), 1, pfile3);
			}

		}


	}

	//д��һ���ڵ�ر�
	if (fclose(pfile1)==EOF)
		printf("�ر�д����ʧ�ܣ�line:%s\t%d\n",__func__,__LINE__);
	//д������ڵ�ر�
	if ((fclose(pfile2))==EOF)
		printf("�ر�д����ʧ�ܣ�line:%s\t%d\n",__func__,__LINE__);
	//д�������ڵ�ر�
	if ((fclose(pfile3))==EOF)
		printf("�ر�д����ʧ�ܣ�line:%s\t%d\n",__func__,__LINE__);


	return TRUE;
}



////1¼���޸�ɾ������


//(��ʦ)

/**
 * ��������: InsertTchNode
 * ��������: �����ʦ�ڵ�
 * �������: ��д�Ľ�ʦ�ڵ�
 * �������: ��
 * �� �� ֵ: BOOL���ͣ��ɹ�����ΪTRUE��ʧ��ΪFALSE
 *
 * ����˵��:
 */

BOOL InsertTchNode(Node_tch* pTch_written)
{
	if (pTch_written!=NULL)
	{
		pTch_written->next = head;
		head = pTch_written;
		head->cls = NULL;		//���ԣ���
		printf("¼��ɹ���%s\t%d",__func__,__LINE__);
		return TRUE;
	}
	printf("¼��ʧ�ܣ�%s\t%d",__func__,__LINE__);
	return FALSE;
}


/**
 * ��������: DelTchNode
 * ��������: ɾ����ʦ�ڵ�
 * �������: ��ʦ�ڵ�Ŀ�ͷ�� Ҫɾ����ʦ�Ĺ���
 * �������: ��
 * �� �� ֵ: BOOL���ͣ��ɹ�ɾ��ΪTRUE��ʧ��ΪFALSE
 *
 * ����˵��:
*/

BOOL DelTchNode(Node_tch* headp, char* Gonghao)
{
	BOOL bRet = FALSE;
	Node_tch* pTch_current = headp;
	Node_tch* pTch_prior = NULL;
	int find=0;
	while (pTch_current!=NULL)	//�ҵ���������Ӧ�Ľ�ʦ�ڵ�
	{
		if (strcmp(pTch_current->gonghao, Gonghao)==0)
		{
			find=1;
			break;
		}

		pTch_prior=pTch_current;
		pTch_current=pTch_current->next;
	}

	if (pTch_prior!=NULL)		//���Ҫɾ���Ľڵ��ǲ���һ���ڵ㣬��ǰһ���ڵ�ָ��ǰ�ڵ�ĺ�һ���ڵ�
		pTch_prior->next = pTch_current->next;
	else						//���Ҫɾ���Ľڵ��ǵ�һ���ڵ㣬��ͷָ��ָ��ǰ�ڵ�ĺ�һ���ڵ�
		headp = pTch_current->next;

	free(pTch_current);

	if (find==1)
		bRet=TRUE;
	return bRet;
}

/**
 * ��������: ModifyTchNode
 * ��������: �޸Ľ�ʦ�ڵ�
 * �������: ��ʦ�ڵ�Ŀ�ͷ�� Ҫ�޸Ľ�ʦ�Ĺ��� ����д���޸Ľ�ʦ�ڵ�
 * �������: ��
 * �� �� ֵ: BOOL���ͣ��ɹ��޸�ΪTRUE��ʧ��ΪFALSE
 *
 * ����˵��:
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

//�����ã�
/**
 * ��������: InsertClsNode
 * ��������: ������ýڵ�
 * �������: ��ʦͷ��㣬��д�Ŀ��ýڵ�
 * �������: ��
 * �� �� ֵ: BOOL���ͣ��ɹ�����ΪTRUE��ʧ��ΪFALSE
 *
 * ����˵��:
*/

BOOL InsertClsNode(Node_tch* hd, Node_cls* pCls_written)
{
	int find = 0;
	BOOL bRet = FALSE;
	hd = SeekTchNode(hd, pCls_written->gonghao);	//���ҵ���Ӧ�Ľ�ʦ�ڵ�
	//����ȳ��Ĳ���
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
 * ��������: DelClsNode
 * ��������: ɾ�����ýڵ�
 * �������: ��ʦ�ڵ�Ŀ�ͷ�� ����ѧ�ڣ�Ҫɾ�����ö�Ӧ��ʦ�Ĺ��� ����������
 * �������: ��
 * �� �� ֵ: BOOL���ͣ��ɹ�ɾ��ΪTRUE��ʧ��ΪFALSE
 *
 * ����˵��:
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
 * ��������: ModifyClsNode
 * ��������: �޸Ŀ��ýڵ�
 * �������: ��ʦ�ڵ�Ŀ�ͷ������ѧ�ڣ�Ҫ�޸Ľ�ʦ�Ĺ��� ���������ƣ���д���޸Ŀ��ýڵ�
 * �������: ��
 * �� �� ֵ: BOOL���ͣ��ɹ��޸�ΪTRUE��ʧ��ΪFALSE
 *
 * ����˵��:
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

//(����)

/**
 * ��������: InsertSpvNode
 * ��������: ���붽���ڵ�
 * �������: ��ʦͷ��㣬��д�Ķ����ڵ�
 * �������: ��
 * �� �� ֵ: BOOL���ͣ��ɹ�����ΪTRUE��ʧ��ΪFALSE
 *
 * ����˵��:
*/

BOOL InsertSpvNode(Node_tch* hd, Node_spv* pSpv_written)
{
	Node_cls* pCls;
	pCls = SeekClsNode(hd, pSpv_written->xueqi, pSpv_written->gonghao, pSpv_written->mingcheng);
	//����ȳ�����ڵ�
	if (pCls!=NULL)
	{
		pSpv_written->next = pCls->spv;
		pCls->spv = pSpv_written;
		return TRUE;
	}
	return FALSE;
}

/**
 * ��������: DelSpvNode
 * ��������: ɾ�������ڵ�
 * �������: ��ʦ�ڵ�Ŀ�ͷ��Ҫɾ�����ö�Ӧ��ʦ�Ĺ��� ������ѧ�ڣ��������ƣ���������
 * �������: ��
 * �� �� ֵ: BOOL���ͣ��ɹ�ɾ��ΪTRUE��ʧ��ΪFALSE
 *
 * ����˵��:
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
		if (pSpv_prior==NULL)//����ö����ڵ��ǿ��õ�һ���ڵ�
			pCls->spv=pSpv_current->next;//���ý��Ϻ�һ�������ڵ�
		else
			pSpv_prior->next=pSpv_current->next;//����ö����ڵ㲻�ǿ��õ�һ���ڵ㣬������һ�������ڵ������һ�������ڵ�

		bRet = TRUE;
		free(pSpv_current);
	}
	return bRet;
}

/**
 * ��������: ModifySpvNode
 * ��������: �޸Ķ����ڵ�
 * �������: ��ʦ�ڵ�Ŀ�ͷ��Ҫ�޸Ľ�ʦ�Ĺ��� ������ѧ�ڣ��������ƣ��������ڣ���д���޸Ķ����ڵ�
 * �������: ��
 * �� �� ֵ: BOOL���ͣ��ɹ��޸�ΪTRUE��ʧ��ΪFALSE
 *
 * ����˵��:
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



////2��ѯ����

/**
 * ��������: SeekTchNode
 * ��������: ��ʮ���������ҵ��͹�����ͬ�Ľ�ʦ��Ϣ�ڵ�ָ�벢����
 * �������: ͷ���ָ��headp, ��ʦ����Gonghao
 * �������: ��
 * �� �� ֵ: ����ҵ��ڵ㣬�򷵻�ָ��ýڵ��ָ�룬���򷵻�NULL

 *
 * ����˵��: �Թ��Ų�ѯ
 */


//(��ʦ)
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
 * ��������: SeekTchNode2
 * ��������: ��ʮ���������ҵ����������Ľ�ʦ��Ϣ�ڵ�ָ�벢����
 * �������: ͷ���ָ��headp, ��ʦ���ϣ� ��ʦְ��
 * �������: ��
 * �� �� ֵ: ����ҵ��ڵ㣬�򷵻�ָ��ýڵ��ָ�룬���򷵻�NULL

 *
 * ����˵��:�Խ�ʦ���Ϻ�ְ��ģ����ѯ
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


//�����ã�

/**
 * ��������: SeekClsNode
 * ��������: ��ʮ���������ҵ��͹��ţ�ѧ�ڣ�����������ͬ�Ŀ�����Ϣ�ڵ�ָ�벢����
 * �������: ͷ���ָ��headp, ���ţ�ѧ�ڣ���������
 * �������: ��
 * �� �� ֵ: ����ҵ��ڵ㣬�򷵻�ָ��ýڵ��ָ�룬���򷵻�NULL

 *
 * ����˵��: �Թ��ţ�ѧ�ڣ��������Ʋ�ѯ
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
 * ��������: SeekClsNode2
 * ��������: ��ʮ���������ҵ����������Ŀ�����Ϣ�ڵ�ָ�벢����
 * �������: ͷ���ָ��headp, ����ѧ��
 * �������: ��
 * �� �� ֵ: ����ҵ��ڵ㣬�򷵻�ָ��ýڵ��ָ�룬���򷵻�NULL

 *
 * ����˵��:ģ����ѯ
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



//��������
/**
 * ��������: SeekSpvNode
 * ��������: ��ʮ���������ҵ����������Ķ�����Ϣ�ڵ�ָ�벢����
 * �������: ͷ���ָ��headp, ��ʦ����, ����ѧ��, �������ƣ���������
 * �������: ��
 * �� �� ֵ: ����ҵ��ڵ㣬�򷵻�ָ��ýڵ��ָ�룬���򷵻�NULL

 *
 * ����˵��: �Խ�ʦ����, ����ѧ��, �������ƣ��������ڲ�ѯ
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
 * ��������: SeekSpvNode
 * ��������: ��ʮ���������ҵ����������Ķ�����Ϣ�ڵ�ָ�벢����
 * �������: ͷ���ָ��headp, ��ʦ����, ����ѧ��, ѧʱ����
 * �������: ��
 * �� �� ֵ: ����ҵ��ڵ㣬�򷵻�ָ��ýڵ��ָ�룬���򷵻�NULL

 *
 * ����˵��: �Խ�ʦ����, ����ѧ��, ѧʱ���� ��ѯ
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

//<ͳ��1>


/**
 * ��������: StatTchNode
 * ��������: ͳ��
 * �������: ͷ���ָ��headp
 * �������: ��
 * �� �� ֵ: ������ͳ����Ϣ������Ϣ������������ָ��ͷ�ڵ��ָ�룬���򷵻�NULL

 *
 * ����˵��:  ͳ�ƽ�ʦ������ѧʱ�����γ�����ѧ������ѧ������
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

    puts("������Ҫͳ�Ƶ�ѧ��");
    scanf(" %s", xq);

    for (pTch=headp; pTch!=NULL; pTch=pTch->next)
    {
        //�µĽڵ㣬���ݳ�ʼ��
        kcs = 0;
        xfs = 0;
        xss = 0;
        zrs = 0;
        //һ���������μ���
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
        //������������
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
                /********�����������������������***********/
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

//<ͳ��2>

/**
 * ��������: StatClsNode
 * ��������: ͳ��
 * �������: ͷ���ָ��headp
 * �������: ��
 * �� �� ֵ: ������ͳ����Ϣ������Ϣ������������ָ��ͷ�ڵ��ָ�룬���򷵻�NULL

 *
 * ����˵��:  ѧ�ڣ�����������������������������ʦ�����ٵ���
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

    puts("������Ҫͳ�Ƶ�ѧ��");
    scanf(" %s", xq);

    for (pTch=headp; pTch!=NULL; pTch=pTch->next)
    {
        for (pCls=pTch->cls; pCls!=NULL; pCls=pCls->next)
        {
            if (strcmp(pCls->xueqi, xq)!=0)
                continue;
            Clstmp = *pCls;
            if ((ptmp = searchstat(pnodec, Clstmp.mingcheng))!=NULL)    /**�����pnodec���������ҵ�ͬ���Ŀγ�*/
            {
                /**������������Ӧ�Ľڵ�����������*/
                ptmp->ketangshu += 1;
                ptmp->junfen =(ptmp->junfen*(ptmp->ketangshu - 1) + Clstmp.junfen)/(ptmp->ketangshu);
                for (i=0; i<5; i++)
                {
                    ptmp->sGPA[i] += Clstmp.GPA[i];
                }
            }
            else        /**�����pnodec�������Ҳ���ͬ���Ŀγ�*/
            {
                /**����������*/
                pnodec = (STATISTIC2*)calloc(1, sizeof(STATISTIC2));
                pnodec->next = pnoder;
                pnoder = pnodec;
                /**Ȼ�����ݸ���ֵ*/
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
                /********�����������������������***********/
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



//<ͳ��3>

/**
 * ��������: StatSpvNode
 * ��������: ͳ��
 * �������: ͷ���ָ��headp
 * �������: ��
 * �� �� ֵ: ������ͳ����Ϣ������Ϣ������������ָ��ͷ�ڵ��ָ�룬���򷵻�NULL

 *
 * ����˵��:  ͳ��ѧ�ڣ�����������������������������ʦ�����ٵ���
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
    puts("������Ҫͳ�ƵĿγ�����");
    scanf(" %s", mc);

    for (pTch=headp; pTch!=NULL; pTch=pTch->next)
    {
        for (pCls=pTch->cls; pCls!=NULL; pCls=pCls->next)
        {
            if (strcmp(pCls->mingcheng, mc)!=0)
                continue;
            if ((ptemp = searchstatspv(pnodec, pCls->xueqi))==NULL)     /**���û�ҵ����ѧ�ڣ��ʹ���һ���µĽڵ㲢����ֵ*/
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
            else        /**�����������ڵ��ϲ�������*/
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

//<ͳ��4>

/**
 * ��������: StatPjNode
 * ��������: ͳ��
 * �������: ͷ���ָ��headp
 * �������: ��
 * �� �� ֵ: ������ͳ����Ϣ������Ϣ������������ָ��ͷ�ڵ��ָ�룬���򷵻�NULL

 *
 * ����˵��:  ��ʦ��ѧ���ۺ����۷�ֵ
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
            if (year!=atoi(pCls->xueqi+1))         /**����Ȳ�ƥ��ʱ����**/
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
            /********�����������������������***********/
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





