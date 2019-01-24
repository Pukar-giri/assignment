/*
*Author:-Pukar Giri
*Created On:-24Th January 2019 at 14:18
*File Name:-main.cpp
*Project Name:-lab2
*Licence:- MIT
*Email:-crazzy.lx75@gmail.com
*/
#include <iostream>
#include <cstring>
using namespace std;
class intvector
    {
        int *data= new int [2];
        long long size=2;
        long length=0;
    public:
        void add_element(int a);
        void del_element(int num);
        void print_all();
        long getsize();
    };



void intvector::add_element(int a)
    {
        if (length>=size)
        {
            cout<<"increasing the size of the intvector"<<endl;
            size*=2;
            int *temp=new int [size];
            temp=(int *) memcpy(temp,data,length*sizeof(int));
            delete data;
            data=temp;
        }
        data[length]=a;
        length++;
    }

void intvector::del_element(int num)
    {
        int lastindex=length-1;
        int temp;
        int count=0;
        for(int i=0;i<lastindex;i++)
        {
            if (data[i] == num)
            {
                count++;
                temp = data[i];
                data[i]         = data[lastindex];
                data[lastindex] = temp;
                lastindex--;
            }
        }
        if (count>0)
        {
            length=length-count;
        }
        else
        {
            cout<<"Not There"<<endl;
        }
        if (length<=size/2)
        {
            cout<<"decreasing the size of the intvector"<<endl;
            size/=2;
            int *temp=new int [size];
            temp=(int *) memcpy(temp,data,length*sizeof(int));
            delete data;
            data=temp;
        }
    }



void intvector::print_all()
    {
        if (length>0)
        {
            for (int i=0;i<length;i++)
            {
                cout<<i<<" th element in the array is "<<data[i]<<endl;
            }
        }
        else
        {
            cout<<"Nothing to print"<<endl;
        }
    }



long intvector::getsize()
    {
        return size;
    }


int main()
    {
        char selection='0' ;
        int num;
        intvector v;
        while(selection!='x')
        {
            cout<<"\n\n===================================="<<endl;
            cout<<"(a) add element"<<endl;
            cout<<"(d) delete element"<<endl;
            cout<<"(p) print elements"<<endl;
            cout <<"(s) print size"<<endl;
            cout<< "(x) exit"<<endl;
            cout<<"===================================="<<endl;
            cin>>selection;
            system("clear");
            switch(selection)
            {
                case 'a':
                    cout<<"Enter the number to add"<<endl;
                    cin>>num;
                    v.add_element(num);
                    break;
                case 'p':
                    v.print_all();
                    break;
                case 's':
                    cout<<"size of array is "<<v.getsize()<<endl;
                    break;
                case 'd':
                    cout<<"Enter the number to delete"<<endl;
                    cin>>num;
                    v.del_element(num);
                    break;
            }

        }
    }
