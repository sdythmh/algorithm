#include <stdio.h>
#include <stdlib.h>
int **board;
int tile = 1;       //当前使用的三格板

void tileBoard(int topRow, int topCol, int defectRow, int defectCol, int size){
    if(size == 1){return;}
    int tileToUse = tile++;
    int quadrantSize = size/2;
    //覆盖左上角
    if(defectRow < topRow + quadrantSize && defectCol < topCol + quadrantSize){		//残缺方格属于这个象限
        tileBoard(topRow, topCol, defectRow, defectCol, quadrantSize);
    }else{																			//残缺方格不属于这个象限
        //在右下角放一个三格板
        board[topRow + quadrantSize -1][topCol + quadrantSize -1] = tileToUse;
        tileBoard(topRow, topCol, topRow + quadrantSize -1, topCol + quadrantSize-1, quadrantSize);
    }
    //覆盖左下角
    if(topRow + quadrantSize < defectRow < topRow + quadrantSize*2 && defectCol < topCol + quadrantSize){		//残缺方格属于这个象限
        tileBoard(topRow, topCol, defectRow, defectCol, quadrantSize);
    }else{																				//残缺方格不属于这个象限
        //在右上角放一个三格板
        board[topRow + (quadrantSize-1)*2][topCol + quadrantSize -1] = tileToUse;
        tileBoard(topRow, topCol, topRow + (quadrantSize-1)*2, topCol + quadrantSize-1, quadrantSize);
    }
    //覆盖右上角
    if(defectRow < topRow + quadrantSize && topCol + quadrantSize < defectCol < topCol + quadrantSize*2){		//残缺方格属于这个象限
        tileBoard(topRow, topCol, defectRow, defectCol, quadrantSize);
    }else{																				//残缺方格不属于这个象限
        //在左下角放一个三格板
        board[topRow + quadrantSize -1][topCol + (quadrantSize-1)*2] = tileToUse;
        tileBoard(topRow, topCol, topRow + quadrantSize -1, topCol + (quadrantSize-1)*2, quadrantSize);
    }
    //覆盖右下角
    if(topRow + quadrantSize < defectRow < topRow + quadrantSize*2 && topCol + quadrantSize < defectCol < topCol + quadrantSize*2){		//残缺方格属于这个象限
        tileBoard(topRow, topCol, defectRow, defectCol, quadrantSize);
    }else{																				//残缺方格不属于这个象限
        //在左上角放一个三格板
        board[topRow + (quadrantSize-1)*2][topCol + (quadrantSize-1)*2] = tileToUse;
        tileBoard(topRow, topCol, topRow + (quadrantSize-1)*2, topCol + (quadrantSize-1)*2, quadrantSize);
    }
}