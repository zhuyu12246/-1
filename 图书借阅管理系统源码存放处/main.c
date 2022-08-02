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
void freed(struct all *pfirst);//释放指针内存
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
    printf("欢迎进入图书管理系统，按1进入管理员系统，按2进入用户系统");
    scanf("%d", &num);
    if (num == 1) {
        while (1) {
            printf("===============图书维护系统===============\n");
            printf("1.新增图书\n");
            printf("2.更改图书信息\n");
            printf("3.删除图书\n");
            printf("4.查找图书\n");
            printf("5.显示所有图书信息\n");
            printf("6.全删当前数据\n");
            printf("0.退出\n");
            printf("=================请选择===================\n");
            scanf("%d", &ex);
            if (ex == 1) {
                input();
                printf("按任意键继续....");
                getch();
            } else if (ex == 2) {
                xiugai();
                printf("按任意键继续....");
                getch();
            } else if (ex == 3) {
                delet();
                printf("按任意键继续....");
                getch();
            } else if (ex == 4) {
                chazhao();
                printf("按任意键继续....");
                getch();
            } else if (ex == 5) {
                xianshi();
                printf("按任意键继续....");
                getch();
            } else if (ex == 6) {
                quanshan();
                printf("=============已经全删===========\n");
                printf("按任意键继续....");
                getch();
            } else if (ex == 0) {
                break;
            }
        }
    }
    else if (num == 2) {
        char str[20];
        printf("用户请输入学号登录:");
        scanf("%s",str);
        while (1){
            printf("===============图书维护系统===============\n");
            printf("1.借阅图书\n");
            printf("2.归还图书\n");
            printf("3.查看所有图书\n");
            printf("4.查找图书\n");
            printf("5.显示我的信息\n");
            printf("0.退出\n");
            printf("=================请选择===================\n");
            scanf("%d", &ex);
            if(ex == 1){
                jieyue();
                printf("======================================\n");
                printf("按任意键继续....");
                getch();
            }
            else if(ex == 2){
                guihuan();
                printf("======================================\n");
                printf("按任意键继续....");
                getch();
            }
            else if(ex == 3){
                xianshi();
                printf("按任意键继续....");
                getch();
            }
            else if(ex == 4){
                chazhao();
                printf("按任意键继续....");
                getch();
            }
            else if(ex == 5){
                wodexingxi();
                printf("按任意键继续....");
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
    printf("新增加图书信息，请输入:\n");
    printf("%s\t%s\t%s\t%s\t%s\n", "图书类别", "书号", "书名", "已借出数量", "未借出数量");
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
    printf("输入你要修改的书号:");
    scanf("%s", n);
    rewind(fp);
    while (fscanf(fp, "%s %s %s %d %d\n", p->category, p->number, p->bookname, &p->out, &p->noout) != EOF &&
           p != NULL) {
        if (strcmp(n, p->number) == 0) {
            printf("%s\t%s\t%s\t%s\t%s\n", "图书类别", "书号", "书名", "已借出数量", "未借出数量");
            printf("%s\t%s\t%s\t%d\t%d\n", p->category, p->number, p->bookname, p->out, p->noout);
            printf("输入更改后的信息");
            printf("%s\t%s\t%s\t%s\t%s\n", "图书类别", "书号", "书名", "已借出数量", "未借出数量");
            scanf("%s %s %s %d %d", p->category, p->number, p->bookname, &p->out, &p->noout);
            printf("=================修改完毕===============\n");
            i++;
            break;
        }
        p = p->next;
    }
    if (i == 0) {
        printf("无法查找到输入书号\n");
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
    printf("输入你要删除的书号:");
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
            printf("%s\t%s\t%s\t%s\t%s\n", "图书类别", "书号", "书名", "已借出数量", "未借出数量");
            printf("%s\t%s\t%s\t%d\t%d\n", p->category, p->number, p->bookname, p->out, p->noout);
            printf("=================删除完毕===============\n");
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
        printf("未查找到输入的书号\n");
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
    printf("选择查找方式：书名查找按1，类别查找按2，书号查找按3:");
    scanf("%d", &n);
    if (n == 1) {
        printf("请输入你要查找的书名:");
        scanf("%s", a);
        rewind(fp);
        while (fscanf(fp, "%s %s %s %d %d\n", p->category, p->number, p->bookname, &p->out, &p->noout) != EOF &&
               p != NULL) {
            if (strcmp(a, p->bookname) == 0) {
                printf("%s\t%s\t%s\t%s\t%s\n", "图书类别", "书号", "书名", "已借出数量", "未借出数量");
                printf("%s\t%s\t%s\t%d\t%d\n", p->category, p->number, p->bookname, p->out, p->noout);
                i++;
                break;
            }
            p = p->next;
        }
        fclose(fp);
        freed(p);
        if (i == 0)
            printf("无法查找到输入书名\n");
    } else if (n == 2) {
        printf("请输入你要查找的类别:");
        scanf("%s", b);
        rewind(fp);
        while (fscanf(fp, "%s %s %s %d %d\n", p->category, p->number, p->bookname, &p->out, &p->noout) != EOF &&
               p != NULL) {
            if (strcmp(b, p->category) == 0) {
                printf("%s\t%s\t%s\t%s\t%s\n", "图书类别", "书号", "书名", "已借出数量", "未借出数量");
                printf("%s\t%s\t%s\t%d\t%d\n", p->category, p->number, p->bookname, p->out, p->noout);
                i++;
                break;
            }
            p = p->next;
        }
        fclose(fp);
        freed(p);
        if (i == 0)
            printf("无法查找到输入类别\n");
    } else if (n == 3) {
        printf("请输入你要查找的书号:");
        scanf("%s", c);
        rewind(fp);
        while (fscanf(fp, "%s %s %s %d %d\n", p->category, p->number, p->bookname, &p->out, &p->noout) != EOF &&
               p != NULL) {
            if (strcmp(c, p->number) == 0) {
                printf("%s\t%s\t%s\t%s\t%s\n", "图书类别", "书号", "书名", "已借出数量", "未借出数量");
                printf("%s\t%s\t%s\t%d\t%d\n", p->category, p->number, p->bookname, p->out, p->noout);
                i++;
                break;
            }
            p = p->next;
        }
        fclose(fp);
        freed(p);
        if (i == 0)
            printf("无法查找到输入书号\n");
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
    printf("%s\t%s\t%s\t%s\t%s\n", "图书类别", "书号", "书名", "已借出数量", "未借出数量");
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
    printf("====================图书借阅系统======================\n");
    printf("请输入你想要借阅的书号:");
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
            printf("借阅成功!\n");
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
        printf("未查找到你想要借阅的书号\n");
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
    printf("====================图书借阅系统======================\n");
    printf("请输入你想要归还的书号:");
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
            printf("归还成功!\n");
            shanchuguihuan(str);
            i = 1;
            break;
        }
        p = p->next;

    }
    if(i == 0) {
        printf("未查找到你想要归还的书号\n");
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
    printf("%s\t%s\t%s\t%s\n","学号","姓名","已借出数量","最大借书量");
    printf("%s\t%s\t%d\t%d\n",p->penumber,p->name,p->peout,p->maxout);
    printf("借书项目\n");
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
    printf("请输入你注册的学号和姓名:\n");
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
