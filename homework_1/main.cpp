
/***************************
    first Qt homework
    written 15/9/2018
    Author  Joseph_Zhou
 ***************************/



#include <QCoreApplication>
#include <QDebug>
#include<cstdio>
#include<climits>
#include<windef.h>
#include<QList>
using namespace std;

#define  MAX(x, y)  ( ((x) > (y)) ? (x) : (y) )
#define  MIN(x, y)  ( ((x) < (y)) ? (x) : (y) )

#define  QuadraWORD_LLO(xxx)  ((qint8) ((qint32)(xxx)     ))
#define  QuadraWORD_HLO(xxx)  ((qint8) ((qint32)(xxx) >> 8))
#define  QuadraWORD_LHI(xxx)  ((qint8) ((qint32)(xxx) >>16))
#define  QuadraWORD_HHI(xxx)  ((qint8) ((qint32)(xxx) >>24))
//#define  W_PTR( var )  ( (word *) ((void *) &(var)) )

//typedef  unsigned long int  uint32;      /* Unsigned 32 bit value */
//typedef  unsigned short     uint16;      /* Unsigned 16 bit value */
//typedef  unsigned char      uint8;       /* Unsigned 8  bit value */

int main(int argc,char *argv[])
{
    qint32 u=0x12345678;
    qint8 hhi,lhi,hlo,llo;
    llo=QuadraWORD_LLO(u);
    hlo=QuadraWORD_HLO(u);
    lhi=QuadraWORD_LHI(u);
    hhi=QuadraWORD_HHI(u);
    QList<quint8> values;
    values.append({hhi,lhi,hlo,llo});

    //for (int x : values )

    //输出原始数和各字节数
    qDebug().nospace()<<"原始值:"<<"0x"<<hex<<u<<"=="<<dec<<u<<'\n';
    qDebug().nospace()<<"0x"<<hex<<hhi<<"=="<<dec<<hhi<<" 0x"<<hex<<lhi<<"=="<<dec<<lhi<<" 0x"<<hex<<hlo<<"=="<<dec<<hlo<<" 0x"<<hex<<llo<<"=="<<dec<<llo;

//    qDebug().nospace()<<"0x"<<hex<<lhi<<"=="<<dec<<lhi;
//    qDebug().nospace()<<"0x"<<hex<<hlo<<"=="<<dec<<hlo;
//    qDebug().nospace()<<"0x"<<hex<<llo<<"=="<<dec<<llo;

    qDebug().nospace()<<"最高和次高8位最大值:"<<"0x"<<hex<<MAX(hhi, lhi)<<'<'<<dec<<MAX(hhi, lhi)<<'>';
    //qDebug()<<"0x"<<hex<<hhi<<lhi<<hlo<<llo;
    //qDebug()<<W_PTR(values);
    //qDebug()<<hex<<values[3];
}
