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
    std::cout<<"��ӭʹ��ѧ������ϵͳ(��ԭ���Ҳ���Qt)\n\n˳��˵һ�䣬�˳����ѡ���������������α���\n��������Ҫȷ�����Ƿ���Ҫ��������ѧ�������Ͱ༶�������������ʹ��,���߸շֹ���,���߰༶������ѧ��,����Ҫ(����)����༶������ѧ������\n�Ƿ���Ҫ¼���������¼��ѧ������?\n";
    std::cout<<"\t\t1. ��,��Ҫ(����)¼��\t\t\t0.��, ����Ҫ(����)¼��\n";
    bool answer=1;
    std::cin>>answer;
    if(answer==true)
    {
        std::ofstream fout;
        fout.open("name.txt");
        if(!fout.is_open()){
        std::cout<<"¼��ʧ�ܣ�����˳���(�ļ�)�Ƿ��д洢/�޸��ļ���Ȩ��\n";
        }
        else
        {
        std::cout<<"����ѧ������\n";
        std::cin>>number;
        fout<<number<<'\n';
        for(int i=0;i<number;i++)
        {
        std::cout<<"�������"<<i+1<<"��ѧ�������� \n";
        std::cin>>a[i];
        std::cout<<'\n';
        fout<<a[i]<<'\n';
        }
    	std::cout<<"¼��ɹ�\n";
        fout.close();
        }
        std::cout<<"��رճ������´�\n";
        system("pause");
        
    }
    else if(answer==false)
    {   
        std::ifstream fin;
        fin.open("name.txt",ios::in);
        fin>>number;
        std::cout<<"�ϴ������������"<<number<<'\n';
        std::cout<<"���ڴ洢��\" ����\"�������ͺ���Ҫ�Ĵ��������Ͳ�ƥ�䣬������ѧ������\n";
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
            std::cout<<"�˴�Ҫ�ش��������"<<a[another_int]<<'\n'<<"�Ƿ�Ҫ����ѡ��?\n";
            std::cout<<"\n1, ����ѡ��                                              0, ������ѡ�񲢹رճ���"<<std::endl;
            std::cin>>answer_2;
            system("cls");
        }
    }

    return 0;
}
