#include "levenshtein.h"


Levenshtein::Levenshtein(QVector <QString> inputs, QObject *parent) : QObject(parent)
{
    //Matrix
    int l1, l2;
    l1 = inputs[0].length();
    l2 = inputs[1].length();
    //Distance
    int r;
    r = edit_dist(inputs[0],l1,inputs[1],l2);
    distance = QString::number(r);
}

int Levenshtein::edit_dist(QString s1,int a,QString s2,int b)
{
    //Prints matrix and returns distance
    a++;
    b++;
    int* ptr=new int[a*b];

    memset(ptr,0,sizeof(int)*static_cast<unsigned int>(a)*static_cast<unsigned int>(b));

    for (int i=1,x=0; i<b;++i,++x)
    {
        for (int j=1,y=0;j<a;++j,++y)
        {
        if(s1[y]==s2[x])
        {
            ptr[(i*a)+j]=ptr[((i-1)*a)+(j-1)];
        }
        else
        {
            ptr[(i*a)+j]=qMin( ptr[(i-1)*a+j]+1, qMin(ptr[i*a+(j-1)]+1, ptr[(i-1)*a+(j-1)]+1) );
        }
        }
    }

    for(int i=0;i<b;++i)
    {
        for(int j=0;j<a;++j)
        {
            matrix += QString::number(ptr[(i*a)+j]);
            matrix += " ";
        }
        matrix += "\n";
    }

    int out= ptr[a*b-1];
    delete [] ptr;
    return out;
}
