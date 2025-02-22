#include<iostream>
#include<fstream>
#include <stdlib.h>
#include<ctime>
#include<windows.h>
using namespace std;
int main()
{   
    std::string a[23767];
    int number=0;
    std::cout<<"欢迎使用学生提问系统(请原谅我不会Qt)\n\n顺带说一句，此程序的选择是真随机而不是伪随机\n我首先需要确认你是否需要重新输入学生姓名和班级人数。若你初次使用,或者刚分过班,或者班级里新增学生,则需要(重新)输入班级人数和学生姓名\n是否需要录入或者重新录入学生姓名?\n";
    std::cout<<"\t\t1. 是,需要(重新)录入\t\t\t0.否, 不需要(重新)录入\n";
    bool answer=1;
    std::cin>>answer;
    if(answer==true)
    {
        std::ofstream fout;
        fout.open("name.txt");
        if(!fout.is_open()){
        std::cout<<"录入失败，请检查此程序(文件)是否有存储/修改文件的权限\n";
        }
        else
        {
        std::cout<<"输入学生人数\n";
        std::cin>>number;
        fout<<number<<'\n';
        for(int i=0;i<number;i++)
        {
        std::cout<<"请输入第"<<i+1<<"个学生的名字 \n";
        std::cin>>a[i];
        std::cout<<'\n';
        fout<<a[i]<<'\n';
        }
    	std::cout<<"录入成功\n";
        fout.close();
        }
        std::cout<<"请关闭程序并重新打开\n";
        system("pause");
        
    }
    else if(answer==false)
    {   
        std::ifstream fin;
        fin.open("name.txt",ios::in);
        fin>>number;
        std::cout<<"上次输入的人数是"<<number<<'\n';
        std::cout<<"由于存储的\" 人数\"数据类型和需要的此数据类型不匹配，请输入学生人数\n";
        std::cin>>number;
        for(int j=0;j<number;j++)
        {
            fin>>a[j];
        }
        bool answer_2=1;
        while (answer_2==true)
        {
            srand(time(0));
            int another_int=0;
            another_int=rand()%number;
            std::cout<<"此次要回答问题的是"<<a[another_int]<<'\n'<<"是否要重新选择?\n";
            std::cout<<"\n1, 重新选择                                              0, 不重新选择并关闭程序"<<std::endl;
            std::cin>>answer_2;
            system("cls");
        }
    }

    return 0;
}
