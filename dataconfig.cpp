#include "dataconfig.h"
#include <QDebug>

dataConfig::dataConfig(QObject *parent) : QObject(parent)
{
    int array1[9][9] = {{1,4,7,2,5,3,9,6,8},
                        {2,3,8,4,6,9,1,7,5},
                        {6,9,5,7,8,1,2,3,4},
                        {4,5,6,1,3,8,7,2,9},
                        {3,7,9,6,2,4,5,8,1},
                        {8,1,2,5,9,7,3,4,6},
                        {9,2,3,8,1,6,4,5,7},
                        {5,6,4,9,7,2,8,1,3},
                        {7,8,1,3,4,5,6,9,2}};
    QVector<QVector<int>> v;
    for(int i=0;i<9;i++){
        QVector<int> v1;
        for(int j=0;j<9;j++){
            v1.push_back(array1[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(0,v);


    int array2[9][9] = {{6,1,5,2,3,4,7,9,8},
                        {4,3,2,8,7,9,6,1,5},
                        {8,7,9,1,5,6,2,4,3},
                        {2,9,7,4,8,1,3,5,6},
                        {1,8,3,6,2,5,9,7,4},
                        {5,4,6,3,9,7,8,2,1},
                        {7,2,8,5,1,3,4,6,9},
                        {9,5,4,7,6,8,1,3,2},
                        {3,6,1,9,4,2,5,8,7}};
    v.clear();
    for(int i=0;i<9;i++){
        QVector<int> v1;
        for(int j=0;j<9;j++){
            v1.push_back(array2[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(1,v);

    int array3[9][9] = {{1,4,7,2,5,3,9,6,8},
                        {2,3,8,4,6,9,1,7,5},
                        {6,9,5,7,8,1,2,3,4},
                        {4,5,6,1,3,8,7,2,9},
                        {3,7,9,6,2,4,5,8,1},
                        {8,1,2,5,9,7,3,4,6},
                        {9,2,3,8,1,6,4,5,7},
                        {5,6,4,9,7,2,8,1,3},
                        {7,8,1,3,4,5,6,9,2}};
    v.clear();
    for(int i=0;i<9;i++){
        QVector<int> v1;
        for(int j=0;j<9;j++){
            v1.push_back(array3[i][j]);
        }
        v.push_back(v1);
    }
    mData.insert(2,v);



}
