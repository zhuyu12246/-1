#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
struct all{
    char category[20];
    char number[20];
    char bookname[20];
    int out;
    int noout;

    char penumber[20];
    char name[20];
    int peout;
    int maxout;
    char outbooks[30];
    struct all *next;
};
void freed(struct all *pfirst);//�ͷ�ָ���ڴ�
void input();
void xiugai();
void delet();
void chazhao();
void xianshi();
void quanshan();

void jieyue();
void jieyuechaozuo();
void guihuan();
void guihuanchaozuo();
void shanchuguihuan(char str[20]);
void wodexingxi();
void shuchu();
/*void zuce();
int yanzhen(char str[20]);
 */


int main() {
    int num, ex;
    printf("��ӭ����ͼ�����ϵͳ����1�������Աϵͳ����2�����û�ϵͳ");
    scanf("%d", &num);
    if (num == 1) {
        while (1) {
            printf("===============ͼ��ά��ϵͳ===============\n");
            printf("1.����ͼ��\n");
            printf("2.����ͼ����Ϣ\n");
            printf("3.ɾ��ͼ��\n");
            printf("4.����ͼ��\n");
            printf("5.��ʾ����ͼ����Ϣ\n");
            printf("6.ȫɾ��ǰ����\n");
            printf("0.�˳�\n");
            printf("=================��ѡ��===================\n");
            scanf("%d", &ex);
            if (ex == 1) {
                input();
                printf("�����������....");
                getch();
            } else if (ex == 2) {
                xiugai();
                printf("�����������....");
                getch();
            } else if (ex == 3) {
                delet();
                printf("�����������....");
                getch();
            } else if (ex == 4) {
                chazhao();
                printf("�����������....");
                getch();
            } else if (ex == 5) {
                xianshi();
                printf("�����������....");
                getch();
            } else if (ex == 6) {
                quanshan();
                printf("=============�Ѿ�ȫɾ===========\n");
                printf("�����������....");
                getch();
            } else if (ex == 0) {
                break;
            }
        }
    }
    else if (num == 2) {
        char str[20];
        printf("�û�������ѧ�ŵ�¼:");
        scanf("%s",str);
        while (1){
            printf("===============ͼ��ά��ϵͳ===============\n");
            printf("1.����ͼ��\n");
            printf("2.�黹ͼ��\n");
            printf("3.�鿴����ͼ��\n");
            printf("4.����ͼ��\n");
            printf("5.��ʾ�ҵ���Ϣ\n");
            printf("0.�˳�\n");
            printf("=================��ѡ��===================\n");
            scanf("%d", &ex);
            if(ex == 1){
                jieyue();
                printf("======================================\n");
                printf("�����������....");
                getch();
            }
            else if(ex == 2){
                guihuan();
                printf("======================================\n");
                printf("�����������....");
                getch();
            }
            else if(ex == 3){
                xianshi();
                printf("�����������....");
                getch();
            }
            else if(ex == 4){
                chazhao();
                printf("�����������....");
                getch();
            }
            else if(ex == 5){
                wodexingxi();
                printf("�����������....");
                getch();
            }
            else if(ex == 0){
                break;
            }
        }
    }
}
void freed(struct all *pfirst) {
    struct all *p = pfirst;
    while (p) {
        pfirst = pfirst->next;
        free(p);
        p = pfirst;
    }
}
void input() {
    FILE *fp;
    struct all *bh;
    if ((fp = fopen("quanbu.txt", "a+")) == NULL) {
        printf("can not open file!");
        exit(1);
    }
    bh = (struct all *) malloc(sizeof(struct all));
    printf("������ͼ����Ϣ��������:\n");
    printf("%s\t%s\t%s\t%s\t%s\n", "ͼ�����", "���", "����", "�ѽ������", "δ�������");
    scanf("%s %s %s %d %d", bh->category, bh->number, bh->bookname, &bh->out, &bh->noout);
    fprintf(fp, "%s\t%s\t%s\t%d\t%d\n", bh->category, bh->number, bh->bookname, bh->out, bh->noout);
    free(bh);
    fclose(fp);
}
void xiugai() {
    struct all *phead;
    phead = (struct all *) malloc(sizeof(struct all));
    phead->next = NULL;
    FILE *fp;
    int i = 0;
    char n[50];
    struct all *p;
    p = (struct all *) malloc(sizeof(struct all));
    if ((fp = fopen("quanbu.txt", "r+")) == NULL) {
        printf("can not open file!");
        exit(1);
    }
    while (fscanf(fp, "%s %s %s %d %d\n", p->category, p->number, p->bookname, &p->out, &p->noout) != EOF) {
        p = (struct all *) malloc(sizeof(struct all));
        p->next = phead->next;
        phead->next = p;
    }
    printf("������Ҫ�޸ĵ����:");
    scanf("%s", n);
    rewind(fp);
    while (fscanf(fp, "%s %s %s %d %d\n", p->category, p->number, p->bookname, &p->out, &p->noout) != EOF &&
           p != NULL) {
        if (strcmp(n, p->number) == 0) {
            printf("%s\t%s\t%s\t%s\t%s\n", "ͼ�����", "���", "����", "�ѽ������", "δ�������");
            printf("%s\t%s\t%s\t%d\t%d\n", p->category, p->number, p->bookname, p->out, p->noout);
            printf("������ĺ����Ϣ");
            printf("%s\t%s\t%s\t%s\t%s\n", "ͼ�����", "���", "����", "�ѽ������", "δ�������");
            scanf("%s %s %s %d %d", p->category, p->number, p->bookname, &p->out, &p->noout);
            printf("=================�޸����===============\n");
            i++;
            break;
        }
        p = p->next;
    }
    if (i == 0) {
        printf("�޷����ҵ��������\n");
        return;
    } else {
        phead = phead->next;
        rewind(fp);
        while (phead) {
            fprintf(fp, "%s\t%s\t%s\t%d\t%d\n", phead->category, phead->number, phead->bookname, phead->out,
                    phead->noout);
            phead = phead->next;
        }
    }
    fclose(fp);
    freed(p);


}
void delet() {
    struct all *phead;
    phead = (struct all *) malloc(sizeof(struct all));
    phead->next = NULL;
    struct all *p;
    FILE *fp;
    int i = 0;
    char a[20];
    if ((fp = fopen("quanbu.txt", "r+")) == NULL) {
        printf("can not open file!");
        exit(1);
    }
    rewind(fp);
    p = (struct all *) malloc(sizeof(struct all));
    while (fscanf(fp, "%s %s %s %d %d\n", p->category, p->number, p->bookname, &p->out, &p->noout) != EOF) {
        p = (struct all *) malloc(sizeof(struct all));
        p->next = phead->next;
        phead->next = p;
    }
    printf("������Ҫɾ�������:");
    scanf("%s", a);
    rewind(fp);
    FILE *fp1;
    if ((fp1 = fopen("linshi.txt", "w+")) == NULL) {
        printf("can not open file!");
        exit(1);
    }
    while (fscanf(fp, "%s %s %s %d %d\n", p->category, p->number, p->bookname, &p->out, &p->noout) != EOF &&
           p != NULL) {
        if (strcmp(a, p->number) == 0) {
            printf("%s\t%s\t%s\t%s\t%s\n", "ͼ�����", "���", "����", "�ѽ������", "δ�������");
            printf("%s\t%s\t%s\t%d\t%d\n", p->category, p->number, p->bookname, p->out, p->noout);
            printf("=================ɾ�����===============\n");
            i = 1;
        } else if (strcmp(a, p->number) != 0) {
            fprintf(fp1, "%s\t%s\t%s\t%d\t%d\n", p->category, p->number, p->bookname, p->out, p->noout);
        }
        p = p->next;
    }
    freed(p);
    fclose(fp);
    fclose(fp1);
    remove("quanbu.txt");
    rename("linshi.txt", "quanbu.txt");
    if (i == 0)
        printf("δ���ҵ���������\n");
}
void chazhao() {
    struct all *phead;
    phead = (struct all *) malloc(sizeof(struct all));
    phead->next = NULL;
    FILE *fp;
    int n, i = 0;
    char a[20], b[20], c[20];
    struct all *p;
    p = (struct all *) malloc(sizeof(struct all));
    if ((fp = fopen("quanbu.txt", "r+")) == NULL) {
        printf("can not open file!");
        exit(1);
    }
    while (fscanf(fp, "%s %s %s %d %d\n", p->category, p->number, p->bookname, &p->out, &p->noout) != EOF) {
        p = (struct all *) malloc(sizeof(struct all));
        p->next = phead->next;
        phead->next = p;
    }
    printf("ѡ����ҷ�ʽ���������Ұ�1�������Ұ�2����Ų��Ұ�3:");
    scanf("%d", &n);
    if (n == 1) {
        printf("��������Ҫ���ҵ�����:");
        scanf("%s", a);
        rewind(fp);
        while (fscanf(fp, "%s %s %s %d %d\n", p->category, p->number, p->bookname, &p->out, &p->noout) != EOF &&
               p != NULL) {
            if (strcmp(a, p->bookname) == 0) {
                printf("%s\t%s\t%s\t%s\t%s\n", "ͼ�����", "���", "����", "�ѽ������", "δ�������");
                printf("%s\t%s\t%s\t%d\t%d\n", p->category, p->number, p->bookname, p->out, p->noout);
                i++;
                break;
            }
            p = p->next;
        }
        fclose(fp);
        freed(p);
        if (i == 0)
            printf("�޷����ҵ���������\n");
    } else if (n == 2) {
        printf("��������Ҫ���ҵ����:");
        scanf("%s", b);
        rewind(fp);
        while (fscanf(fp, "%s %s %s %d %d\n", p->category, p->number, p->bookname, &p->out, &p->noout) != EOF &&
               p != NULL) {
            if (strcmp(b, p->category) == 0) {
                printf("%s\t%s\t%s\t%s\t%s\n", "ͼ�����", "���", "����", "�ѽ������", "δ�������");
                printf("%s\t%s\t%s\t%d\t%d\n", p->category, p->number, p->bookname, p->out, p->noout);
                i++;
                break;
            }
            p = p->next;
        }
        fclose(fp);
        freed(p);
        if (i == 0)
            printf("�޷����ҵ��������\n");
    } else if (n == 3) {
        printf("��������Ҫ���ҵ����:");
        scanf("%s", c);
        rewind(fp);
        while (fscanf(fp, "%s %s %s %d %d\n", p->category, p->number, p->bookname, &p->out, &p->noout) != EOF &&
               p != NULL) {
            if (strcmp(c, p->number) == 0) {
                printf("%s\t%s\t%s\t%s\t%s\n", "ͼ�����", "���", "����", "�ѽ������", "δ�������");
                printf("%s\t%s\t%s\t%d\t%d\n", p->category, p->number, p->bookname, p->out, p->noout);
                i++;
                break;
            }
            p = p->next;
        }
        fclose(fp);
        freed(p);
        if (i == 0)
            printf("�޷����ҵ��������\n");
    }
}
void xianshi() {
    struct all *phead;
    phead = (struct all *) malloc(sizeof(struct all));
    phead->next = NULL;
    FILE *fp;
    struct all *p;
    p = (struct all *) malloc(sizeof(struct all));
    if ((fp = fopen("quanbu.txt", "r+")) == NULL) {
        printf("can not open file!");
        exit(1);
    }
    rewind(fp);
    while (fscanf(fp, "%s %s %s %d %d\n", p->category, p->number, p->bookname, &p->out, &p->noout) != EOF) {
        p->next = phead->next;
        phead->next = p;
        p = (struct all *) malloc(sizeof(struct all));
    }
    phead = phead->next;
    printf("%s\t%s\t%s\t%s\t%s\n", "ͼ�����", "���", "����", "�ѽ������", "δ�������");
    while (phead) {
        printf("%s\t%s\t%s\t%d\t%d\n", phead->category, phead->number, phead->bookname, phead->out, phead->noout);
        phead = phead->next;
    }
    fclose(fp);
    freed(phead);
}
void quanshan() {
    remove("quanbu.txt");
}

void jieyue() {
    char aw[30];
    struct all *phead;
    phead = (struct all *) malloc(sizeof(struct all));
    phead->next = NULL;
    FILE *fp;
    FILE *fp1;
    struct all *p;
    char str[20];
    int i = 0;
    printf("====================ͼ�����ϵͳ======================\n");
    printf("����������Ҫ���ĵ����:");
    scanf("%s", str);
    p = (struct all *) malloc(sizeof(struct all));
    if ((fp = fopen("quanbu.txt", "r+")) == NULL) {
        printf("can not open file!");
        exit(1);
    }
    while (fscanf(fp, "%s %s %s %d %d\n", p->category, p->number, p->bookname, &p->out, &p->noout) != EOF) {
        p = (struct all *) malloc(sizeof(struct all));
        p->next = phead->next;
        phead->next = p;
    }
    rewind(fp);
    while (fscanf(fp, "%s %s %s %d %d\n", p->category, p->number, p->bookname, &p->out, &p->noout) != EOF &&
           p != NULL) {
        if (strcmp(str, p->number) == 0) {
            jieyuechaozuo();
            p->out = p->out + 1;
            p->noout = p->noout - 1;
            printf("���ĳɹ�!\n");
            if ((fp1 = fopen("jieshuxiangmu.txt", "a+")) == NULL) {
                printf("can not open file!");
                exit(1);
            }
            fprintf(fp1, "%s\t",str);
            fclose(fp1);
            i = 1;
            break;
        }
        p = p->next;

    }
    if(i == 0) {
        printf("δ���ҵ�����Ҫ���ĵ����\n");
        return;
    }
    else{
        phead = phead->next;
        rewind(fp);
        while (phead) {
            fprintf(fp, "%s\t%s\t%s\t%d\t%d\n", phead->category, phead->number, phead->bookname, phead->out,
                    phead->noout);
            phead = phead->next;
        }
    }
    fclose(fp);
    freed(p);
}
void jieyuechaozuo(){
    struct all *phead;
    phead = (struct all *) malloc(sizeof(struct all));
    phead->next = NULL;
    FILE *fp3;
    struct all *p;
    p = (struct all *) malloc(sizeof(struct all));
    if ((fp3 = fopen("yonghu.txt", "r+")) == NULL) {
        printf("can not open file!");
        exit(1);
    }
 fscanf(fp3, "%s %s %d %d \n", p->penumber,p->name,&p->peout,&p->maxout);
    p->peout = p ->peout + 1;
    rewind(fp3);
        fprintf(fp3, "%s\t%s\t%d\t%d\n", p->penumber,p->name,p->peout,p->maxout);

    fclose(fp3);
    free(p);
}
void guihuan(){
    char aw[30];
    struct all *phead;
    phead = (struct all *) malloc(sizeof(struct all));
    phead->next = NULL;
    FILE *fp;
    FILE *fp1;
    struct all *p;
    char str[20];
    int i = 0;
    printf("====================ͼ�����ϵͳ======================\n");
    printf("����������Ҫ�黹�����:");
    scanf("%s", str);
    p = (struct all *) malloc(sizeof(struct all));
    if ((fp = fopen("quanbu.txt", "r+")) == NULL) {
        printf("can not open file!");
        exit(1);
    }
    while (fscanf(fp, "%s %s %s %d %d\n", p->category, p->number, p->bookname, &p->out, &p->noout) != EOF) {
        p = (struct all *) malloc(sizeof(struct all));
        p->next = phead->next;
        phead->next = p;
    }
    rewind(fp);
    while (fscanf(fp, "%s %s %s %d %d\n", p->category, p->number, p->bookname, &p->out, &p->noout) != EOF &&
           p != NULL) {
        if (strcmp(str, p->number) == 0) {
            guihuanchaozuo();
            p->out = p->out - 1;
            p->noout = p->noout + 1;
            printf("�黹�ɹ�!\n");
            shanchuguihuan(str);
            i = 1;
            break;
        }
        p = p->next;

    }
    if(i == 0) {
        printf("δ���ҵ�����Ҫ�黹�����\n");
        return;
    }
    else{
        phead = phead->next;
        rewind(fp);
        while (phead) {
            fprintf(fp, "%s\t%s\t%s\t%d\t%d\n", phead->category, phead->number, phead->bookname, phead->out,
                    phead->noout);
            phead = phead->next;
        }
    }
    fclose(fp);
    freed(p);
}
void guihuanchaozuo(){
    struct all *phead;
    phead = (struct all *) malloc(sizeof(struct all));
    phead->next = NULL;
    FILE *fp3;
    struct all *p;
    p = (struct all *) malloc(sizeof(struct all));
    if ((fp3 = fopen("yonghu.txt", "r+")) == NULL) {
        printf("can not open file!");
        exit(1);
    }
    fscanf(fp3, "%s %s %d %d \n", p->penumber,p->name,&p->peout,&p->maxout);
    p->peout = p ->peout - 1;
    rewind(fp3);
    fprintf(fp3, "%s\t%s\t%d\t%d\n", p->penumber,p->name,p->peout,p->maxout);

    fclose(fp3);
    free(p);
}
void shanchuguihuan(char str[20]){
    struct all *phead;
    phead = (struct all *) malloc(sizeof(struct all));
    phead->next = NULL;
    struct all *p;
    FILE *fp1;
    FILE *fp;
    if ((fp1 = fopen("jieshuxiangmu.txt", "r+")) == NULL) {
        printf("can not open file!");
        exit(1);
    }
    rewind(fp1);
    p = (struct all *) malloc(sizeof(struct all));
    while (fscanf(fp1, "%s",p->outbooks) != EOF) {
        p = (struct all *) malloc(sizeof(struct all));
        p->next = phead->next;
        phead->next = p;
    }
    if ((fp = fopen("linshi.txt", "w+")) == NULL) {
        printf("can not open file!");
        exit(1);
    }
    rewind(fp1);
    while (fscanf(fp1, "%s", p->outbooks) != EOF &&
           p != NULL) {
            if (strcmp(str, p->outbooks) != 0) {
            fprintf(fp, "%s\t", p->outbooks);
        }
        p = p->next;
    }
    freed(p);
    fclose(fp);
    fclose(fp1);
    remove("jieshuxiangmu.txt");
    rename("linshi.txt", "jieshuxiangmu.txt");

}
void wodexingxi(){
    struct all *phead;
    phead = (struct all *) malloc(sizeof(struct all));
    phead->next = NULL;
    struct all *p;
    FILE *fp;
    p = (struct all *) malloc(sizeof(struct all));
    if ((fp = fopen("yonghu.txt", "r+")) == NULL) {
        printf("can not open file!");
        exit(1);
    }
    fscanf(fp,"%s %s %d %d",p->penumber,p->name,&p->peout,&p->maxout);
    printf("%s\t%s\t%s\t%s\n","ѧ��","����","�ѽ������","��������");
    printf("%s\t%s\t%d\t%d\n",p->penumber,p->name,p->peout,p->maxout);
    printf("������Ŀ\n");
    shuchu();
    fclose(fp);
    free(p);

}
void shuchu(){
    char ch[200];
    FILE *fp;
    if ((fp = fopen("jieshuxiangmu.txt", "r+")) == NULL) {
        printf("can not open file!");
        exit(1);
    }
    fgets(ch,200,fp);
    printf("%s\n",ch);
    fclose(fp);

}

/*void zuce(){
    int a = 0,b = 5;
    FILE *fp;
    struct all *bh;
    if((fp = fopen("yonghu.txt","a+")) == NULL){
        printf("can not open file!");
        exit(1);
    }
    bh = (struct all*)malloc(sizeof (struct all));
    printf("��������ע���ѧ�ź�����:\n");
    scanf("%s %s",bh->penumber,bh->name);
    fprintf(fp,"%s\t%s\t%d\t%d\n",bh->penumber,bh->name,a,b);
    free(bh);
    fclose(fp);
}
int yanzhen(char str[20]){
    struct all *k;
    FILE *yh;
    if((yh = fopen("yonghu.txt","r+")) == NULL){
        printf("can not open file!");
        exit(1);
    }
    while(fscanf(yh,"%s %s %d %d\n",k->penumber,k->name,k->peout,k->maxout) != EOF){
        k = (struct all*)malloc(sizeof (struct all));
        k->next = phead ->next;
        phead ->next = k;
    }
    while(k != NULL){
        if(strcmp(str,k->penumber) == 0){
            return 1;
        }
        k = k->next;
    }

    return 0;

}*/
